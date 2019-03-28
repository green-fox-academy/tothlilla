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
			
GPIO_InitTypeDef PA15_LED_config; //PA 15 pin able to compare channel 1 with alternate function AF
GPIO_InitTypeDef user_button_handle; //PI 11 pin

TIM_HandleTypeDef pwm_led_init;
TIM_OC_InitTypeDef sConfig;

void external_led_PA15_init(){
    __HAL_RCC_GPIOA_CLK_ENABLE(); //A port clock
    PA15_LED_config.Pin = GPIO_PIN_15; //PA 15 pin able to compare channel 1 with alternate function AF
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;	/* configure as output, in push-pull mode */
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;	/* this alternate function we need to use TIM2 in output compare mode */
    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}
void pwm_init(){
	//timer r�sz
	pwm_led_init.Instance = TIM2;
	pwm_led_init.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	pwm_led_init.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
	pwm_led_init.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
	pwm_led_init.Init.CounterMode		= TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_led_init);
	//pwm output channel r�sz
    sConfig.Pulse = 0; //ezt lehet v�ltozik
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;
    HAL_TIM_PWM_ConfigChannel(&pwm_led_init, &sConfig, TIM_CHANNEL_1);
    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_led_init, TIM_CHANNEL_1); //tal�n itt marad

}

void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); // enable the GPIOI clock
	user_button_handle.Pin = GPIO_PIN_11; // the pin is the PI11
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; // port speed to fast
	user_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING; // our mode is interrupt on rising edge
	HAL_GPIO_Init(GPIOI, &user_button_handle); // init PI11 user button

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);	//set blue PI11 user button interrupt priority //a 11 a 10 �s a 15 k�z�tt van
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //enable the interrupt to HAL
}


int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED1);
	while(1){

	}
}


void EXTI15_10_IRQHandler(void)
{
	//HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == user_button_handle.Pin){
		HAL_GPIO_TogglePin(LED1);//tesztel�s miatt!!
	}
}













