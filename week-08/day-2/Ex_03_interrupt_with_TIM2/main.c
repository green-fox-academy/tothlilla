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
#include <string.h>
#define UART_PUTCHAR int __io_putchar(int ch) //to use printf() function

//global variables
GPIO_InitTypeDef LEDS;		//the external Led config structure
TIM_HandleTypeDef tim_handle;  //the timer's config structure

static void Error_Handler(void); //predefining of error handling function
static void SystemClock_Config(void); //predefining of system clock initializing function

void init_external_led()
{
	//initialize LED
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_7;  		// setting up a pin
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);
}
void init_timer(void)
{
    //initialize TIM2
	__HAL_RCC_TIM2_CLK_ENABLE();		//giving clock
	// configuriation of the basic mode of the timer (which direction should it count, what is the maximum value, etc.)
	HAL_TIM_Base_DeInit(&tim_handle);
	tim_handle.Instance = TIM2;			//register base address
	tim_handle.Init.Prescaler = 10800 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	tim_handle.Init.Period = 5000 - 1; 	// 5000 x 0.1 ms = 500 ms = 0.5 s period */
	tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_Base_Init(&tim_handle); 	 //configure the timer
	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0); //set TIM2 interrupt priority
	HAL_NVIC_EnableIRQ(TIM2_IRQn); //enable the interrupt to HAL
}
int main(void)
{

    HAL_Init(); 			//making HAL configuration
    SystemClock_Config(); 	//this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
    init_external_led();	//initialize LED
    init_timer();			//initialize TIM2

    //Starts the TIM Base generation in interrupt mode.
    HAL_TIM_Base_Start_IT(&tim_handle);

    while (1) {


    }
}

/*TIMER handler and callback*/


void TIM2_IRQHandler()
													// the name of the function must come from the startup/startup_stm32f746xx.s file
{
	HAL_TIM_IRQHandler(&tim_handle);
													// set timer_handle structure for the TIM2 handler
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == tim_handle.Instance) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
	}
}


static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    //Configure the main internal regulator output voltage
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


