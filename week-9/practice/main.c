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
//vagy GPIO_InitTypeDef external_led;

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
	//timer rész
	pwm_led_init.Instance = TIM2;
	pwm_led_init.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	pwm_led_init.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
	pwm_led_init.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
	pwm_led_init.Init.CounterMode		= TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&pwm_led_init);
	//pwm output channel rész
    sConfig.Pulse = 50; //ezt lehet változik
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;
    HAL_TIM_PWM_ConfigChannel(&pwm_led_init, &sConfig, TIM_CHANNEL_1);
    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_led_init, TIM_CHANNEL_1); //talán itt marad

}


int main(void)
{

	for(;;);
}
