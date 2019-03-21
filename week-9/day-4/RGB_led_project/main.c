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

typedef enum {
	NOPUSHING,
	PUSHING
}pushing_button_rising_falling_state_t;

typedef enum {
	RED,
	GREEN,
	BLUE
} choice_of_color_t;

volatile choice_of_color_t color;

volatile pushing_button_rising_falling_state_t state = NOPUSHING;
volatile uint32_t start_pushing;
volatile uint32_t finish_pushing;

GPIO_InitTypeDef PA15_RED; //PA 15 pin able to compare channel 1 with alternate function AF
GPIO_InitTypeDef PB4_GREEN;
GPIO_InitTypeDef PI0_BLUE;
TIM_HandleTypeDef pwm_tim2;
TIM_HandleTypeDef pwm_tim3;
TIM_HandleTypeDef pwm_tim5;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef user_button_handle;

uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 50;    // the debounce time in ms (increase if the output flickers)

volatile int push_counter = 0;

volatile uint32_t pulse_changer_red = 100;
volatile uint32_t pulse_changer_blue = 100;
volatile uint32_t pulse_changer_green = 100;
volatile int flag = 1;

static void Error_Handler(void);
static void SystemClock_Config(void);
void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); // enable the GPIOI clock
	user_button_handle.Pin = GPIO_PIN_11; // the pin is the PI11
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; // port speed to fast
	user_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	HAL_GPIO_Init(GPIOI, &user_button_handle); // init PI11 user button
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);	//set blue PI11 user button interrupt priority //a 11 a 10 és a 15 között van
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //enable the interrupt to HAL
}


void rgb_led_init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); //A port clock
	PA15_RED.Pin = GPIO_PIN_15; //PA 15 pin able to compare channel 1 with alternate function AF
	PA15_RED.Mode = GPIO_MODE_AF_OD; /* configure as output, in push-pull mode */
	PA15_RED.Pull = GPIO_NOPULL;
	PA15_RED.Speed = GPIO_SPEED_HIGH;
	PA15_RED.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_RED);

	__HAL_RCC_GPIOB_CLK_ENABLE(); //B port clock
	PB4_GREEN.Pin = GPIO_PIN_4; // PB port 4 pin
	PB4_GREEN.Mode = GPIO_MODE_AF_OD; //same as PA port 15 pin
	PB4_GREEN.Pull = GPIO_NOPULL; //same as PA port 15 pin
	PB4_GREEN.Speed = GPIO_SPEED_HIGH; //same as PA port 15 pin
	PB4_GREEN.Alternate = GPIO_AF2_TIM3; //alternate function to TIM3 channel 1 with PB4 led pin
	HAL_GPIO_Init(GPIOB, &PB4_GREEN); //init B port's led in pwm mode

	__HAL_RCC_GPIOI_CLK_ENABLE(); //B port clock
	PI0_BLUE.Pin = GPIO_PIN_0; // PB port 4 pin
	PI0_BLUE.Mode = GPIO_MODE_AF_OD; //same as PA port 15 pin
	PI0_BLUE.Pull = GPIO_NOPULL; //same as PA port 15 pin
	PI0_BLUE.Speed = GPIO_SPEED_HIGH; //same as PA port 15 pin
	PI0_BLUE.Alternate = GPIO_AF2_TIM5; //alternate function to TIM3 channel 1 with PB4 led pin
	HAL_GPIO_Init(GPIOI, &PI0_BLUE); //init B port's led in pwm mode
}

void pwm_init()
{
    __HAL_RCC_TIM2_CLK_ENABLE();
    pwm_tim2.Instance = TIM2;
    pwm_tim2.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    pwm_tim2.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    pwm_tim2.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    pwm_tim2.Init.CounterMode		= TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&pwm_tim2);

    __HAL_RCC_TIM3_CLK_ENABLE();
    pwm_tim3.Instance = TIM3;
    pwm_tim3.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    pwm_tim3.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    pwm_tim3.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    pwm_tim3.Init.CounterMode		= TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&pwm_tim3);

    __HAL_RCC_TIM5_CLK_ENABLE();
    pwm_tim5.Instance = TIM5;
    pwm_tim5.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    pwm_tim5.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    pwm_tim5.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    pwm_tim5.Init.CounterMode		= TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&pwm_tim5);


    sConfig.Pulse = 50;
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm_tim2, &sConfig, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&pwm_tim3, &sConfig, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&pwm_tim5, &sConfig, TIM_CHANNEL_4);
}
void case1() {
	if (flag) {
		if (pulse_changer_red + 10 < 100) {
			pulse_changer_red += 10;
		} else {
			pulse_changer_red = 100;
			flag = 0;
		}
	} else {
		if (pulse_changer_red - 10 > 0) {
			pulse_changer_red -= 10;
		} else {
			pulse_changer_red = 0;
			flag = 1;
		}
	}
}
void case2() {
	if (flag) {
		if (pulse_changer_green + 10 < 100) {
			pulse_changer_green += 10;
		} else {
			pulse_changer_green = 100;
			flag = 0;
		}
	} else {
		if (pulse_changer_green - 10 > 0) {
			pulse_changer_green -= 10;
		} else {
			pulse_changer_green = 0;
			flag = 1;
		}
	}
}
void case3() {
	if (flag) {
		if (pulse_changer_blue + 10 < 100) {
			pulse_changer_blue += 10;
		} else {
			pulse_changer_blue = 100;
			flag = 0;
		}
	} else {
		if (pulse_changer_blue - 10 > 0) {
			pulse_changer_blue -= 10;
		} else {
			pulse_changer_blue = 0;
			flag = 1;
		}
	}
}
int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_user_button();
	rgb_led_init();
	pwm_init();

    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_tim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&pwm_tim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&pwm_tim5, TIM_CHANNEL_4);

	while (1){
		 __HAL_TIM_SET_COMPARE(&pwm_tim2, TIM_CHANNEL_1, pulse_changer_red);
		 __HAL_TIM_SET_COMPARE(&pwm_tim3, TIM_CHANNEL_1, pulse_changer_green);
		 __HAL_TIM_SET_COMPARE(&pwm_tim5, TIM_CHANNEL_4, pulse_changer_blue);
	}
}

//---------- 1 USER BUTTON HANDLER  -------------------
//user push button PI11 external interrupt handler
void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}
//user push button PI11 external interrupt week callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	//if(GPIO_Pin == GPIO_PIN_11){
	if (GPIO_Pin == user_button_handle.Pin) {
		uint32_t current_time = HAL_GetTick();
		if (current_time < last_debounce_time + debounce_delay) {
			// Do nothing (this is not a real button press)
			return;
		} else if (state == NOPUSHING) {
			state = PUSHING;
			start_pushing = HAL_GetTick();
		} else if (state == PUSHING) {
			state = NOPUSHING;
			finish_pushing = HAL_GetTick();
			uint32_t length_of_pushing = finish_pushing - start_pushing;
			if (length_of_pushing <= 600) {
				if (push_counter == 0) {
					color = RED;
					push_counter++;
				} else if (push_counter == 1) {
					color = GREEN;
					push_counter++;
				} else if (push_counter == 2) {
					color = BLUE;
					push_counter = 0;
				}

			} else if (length_of_pushing > 600) {
				if (color == RED) {
					case1();
				} else if (color == GREEN) {
					case2();
				} else if (color == BLUE) {
					case3();
				}
			}
		}
		last_debounce_time = current_time;
	}
}


//error handler
static void Error_Handler(void)
{

}
//system clock config to TIMERs
static void SystemClock_Config(void) {
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
