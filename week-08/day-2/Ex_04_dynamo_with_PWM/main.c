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

GPIO_InitTypeDef user_button_handle; // the PI11 user button handle structure
GPIO_InitTypeDef LEDS;		//the external Led config structure
TIM_HandleTypeDef pwm_tim; // PWM timer (TIM) config structure
TIM_OC_InitTypeDef sConfig; // the output compare channel's config structure for PWM
volatile uint32_t pushing_speed = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); // enable the GPIOI clock
	user_button_handle.Pin = GPIO_PIN_11; // the pin is the PI11
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; // port speed to fast
	user_button_handle.Mode = GPIO_MODE_IT_RISING; // our mode is interrupt on rising edge
	HAL_GPIO_Init(GPIOI, &user_button_handle); // init PI11 user button
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);	//set blue PI11 user button interrupt priority
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //enable the interrupt to HAL
}

void init_external_led()
{
	//initialize external LED on B port pin 4 (PWM compatibility)
	__HAL_RCC_GPIOB_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_4;  		// setting up a pin
	LEDS.Mode = GPIO_MODE_AF_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	LEDS.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOB, &LEDS);
}

void init_PWM(void)
{
	//initialize TIM3 for PWM
	__HAL_RCC_TIM3_CLK_ENABLE();		 //giving clock
	// configuriation of the basic mode of the timer (which direction should it count, what is the maximum value, etc.)
	pwm_tim.Instance = TIM3;			 //register base address
	pwm_tim.Init.Prescaler = 108 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	pwm_tim.Init.Period = 100 - 1; /* 10000 x 0.1 ms = 1 second period */
	pwm_tim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm_tim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_tim);	 //configure the PWM timer
	sConfig.Pulse = 0;
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&pwm_tim, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&pwm_tim, TIM_CHANNEL_1);

}
int main(void)
{
	HAL_Init();				//making HAL configuration
	SystemClock_Config(); //for TIMERS - this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	init_external_led(); //init external Led on F port pin 7
	init_user_button();
	init_PWM();

	while (1) {
		__HAL_TIM_SET_COMPARE(&pwm_tim, TIM_CHANNEL_1, pushing_speed);
		if (pushing_speed >= 3) {
			pushing_speed -= 3;
		} else {
			pushing_speed = 0;
		}
		HAL_Delay(500);
	}
}

//user push button PI11 external interrupt handler
void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}
//user push button PI11 external interrupt week callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//if(GPIO_Pin == GPIO_PIN_11){
	if (GPIO_Pin == user_button_handle.Pin) {
		if (pushing_speed <= 50) {
			if (pushing_speed + 5 <= 50) {
				pushing_speed += 5;
			} else {
				pushing_speed = 50;
			}
		}

	}
}

//error handler
static void Error_Handler(void)
{
}
//system clock config to TIMERs
static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

