/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			
I2C_HandleTypeDef I2C_handle;            // defining the I2C configuration structure

GPIO_InitTypeDef SCL_SDA_config;           // configure GPIOs for I2C data and clock lines

UART_HandleTypeDef uart; // UART config structure

TIM_HandleTypeDef tim_handle; // timer (TIM2) config handle structure

volatile int timer_flag = 0;

volatile uint8_t read_temp_reg = 0;
volatile uint8_t read_temp_val;

/* 7 bit address of an I2C sensor shifted to left 1 bit, leaving place for W/R bit,
 * which is inserted by the HAL_I2C_Master_Transmit and HAL_I2C_Master_Receive */
#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define UART_PUTCHAR int __io_putchar(int ch)

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_timer(void);
void init_uart(void);
void init_I2C(void);

void write_to_uart();

int main(void)
{
    HAL_Init();
    SystemClock_Config(); 	//for TIMERS
    init_uart();
    init_timer();
    init_I2C();

    HAL_TIM_Base_Start_IT(&tim_handle); //starting the timer - init_timer() won't work without it

    while (1) {
        //HAL_Delay(1000); //using TIM2 timer insterad of HAL_DELAY()
    	write_to_uart();
	}
}
void init_uart(void)
{
	__HAL_RCC_USART1_CLK_ENABLE(); 	//giving clock
	/* defining the UART configuration structure */
	uart.Instance = USART1;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX;
	BSP_COM_Init(COM1, &uart); //init USART

}
void init_timer(void)
{
    //initialize TIM2
	__HAL_RCC_TIM2_CLK_ENABLE();		 //giving clock
	HAL_TIM_Base_DeInit(&tim_handle);	 // de-initialize the TIM_Base, because of safety reasons
	// configuriation of the basic mode of the timer (which direction should it count, what is the maximum value, etc.)
	tim_handle.Instance = TIM2;			 //register base address
	tim_handle.Init.Prescaler = 10800 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	tim_handle.Init.Period = 10000 - 1; 	// 10000 x 0.1 ms = 1000 ms = 1 s period */
	tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_Base_Init(&tim_handle); 	 //configure the timer
	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0); //set TIM2 interrupt priority
	HAL_NVIC_EnableIRQ(TIM2_IRQn); //enable the interrupt to HAL
}
void init_I2C(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();       /* enable GPIO clock */

    SCL_SDA_config.Pin         = GPIO_PIN_8 | GPIO_PIN_9;  /* PB8: SCL, PB9: SDA */
    SCL_SDA_config.Pull        = GPIO_PULLUP;
    SCL_SDA_config.Mode        = GPIO_MODE_AF_OD;          /* configure in pen drain mode */
    SCL_SDA_config.Alternate   = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

    __HAL_RCC_I2C1_CLK_ENABLE();        /* enable the clock of the used peripheral */

    /* defining the UART configuration structure */
    I2C_handle.Instance             = I2C1;
    I2C_handle.Init.Timing          = 0x40912732;
    I2C_handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;

    HAL_I2C_Init(&I2C_handle);
}

void write_to_uart()
{
	if (timer_flag) {
		HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS,
				&read_temp_reg, sizeof(read_temp_reg), 100);
		HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS,
				&read_temp_val, sizeof(read_temp_val), 100);
		/* or using HAL_I2C_Mem_Read():
		 HAL_I2C_Mem_Read(&I2C_handle, TEMP_SENSOR_ADDRESS, read_temp_reg, I2C_MEMADD_SIZE_8BIT,
		 &read_temp_val, sizeof(read_temp_val), 100);
		 */
		timer_flag = 0;
		printf("Temperature: %d\r\n", read_temp_val);
	}
}

//---------- 4 TIM2 HANDLER  -------------------
//TIM2 external interrupt handler
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim_handle);
}
//declare week callback function
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//if (htim->Instance == TIM2)
	if (htim->Instance == tim_handle.Instance) {
		timer_flag = 1;

	}
}
//using printf()
UART_PUTCHAR
{
    HAL_UART_Transmit(&uart, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}

//error handler
static void Error_Handler(void)
{}
//system clock config to TIMERs
static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /**Activate the Over-Drive mode */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        Error_Handler();
    }

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}


