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

TIM_HandleTypeDef tim;
GPIO_InitTypeDef LEDS;
uint16_t tim_val = 0;
static void Error_Handler(void);
static void SystemClock_Config(void);
void timer_init(void);
void init_external_led();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    timer_init();
    init_external_led();
    HAL_TIM_Base_Start(&tim);

	while (1) {
        tim_val = __HAL_TIM_GET_COUNTER(&tim);
		//if(tim_val >= 0 && tim_val <= 4999) {
        if(tim_val == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		}
		//if(tim_val >= 5000 && tim_val <= 9999) {
        if(tim_val == 5000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		}
		//if(tim_val >= 10000 && tim_val <= 14999) {
        if(tim_val == 10000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		}
		//if(tim_val >= 15000 && tim_val <= 19999) {
        if(tim_val == 15000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		}
	}
}

void timer_init(void) //init TIM2
{
	__HAL_RCC_TIM2_CLK_ENABLE(); // we need to enable the TIM2
	tim.Instance = TIM2;
	tim.Init.Prescaler = 108000 - 1; /* 108000000/108000=1000 -> speed of 1 count-up: 1/1000 sec = 1 ms */
	tim.Init.Period = 20000 - 1; /* 20000 x 1 ms = 20 second period */
	tim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim); 	// configure the timer
	//HAL_TIM_Base_Start(&tim);	// starting the timer
}

void init_external_led()
{
	//initialize external LEDs on F port
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);	//first param: name of port, second param: name of structure
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

