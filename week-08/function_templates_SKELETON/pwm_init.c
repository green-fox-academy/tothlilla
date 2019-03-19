#include "interruption_templates.h"

GPIO_InitTypeDef PA15_LED_config; //PA 15 pin able to compare channel 1 with alternate function AF
TIM_HandleTypeDef pwm_tim;
TIM_OC_InitTypeDef sConfig;

void pwm_init(){

    // GPIO led config //TIM3_CH1 PB4 pinnel és AF2 alternate functionnel is mûködik
    __HAL_RCC_GPIOA_CLK_ENABLE(); //A pont clock
    //__HAL_RCC_GPIOB_CLK_ENABLE(); //B port clock
    PA15_LED_config.Pin = GPIO_PIN_15; //PA 15 pin able to compare channel 1 with alternate function AF
    //LEDS.Pin = GPIO_PIN_4; // PB port 4 pin
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;	/* configure as output, in push-pull mode */
    //LEDS.Mode = GPIO_MODE_AF_PP; //same as PA port 15 pin
    PA15_LED_config.Pull = GPIO_NOPULL;
    //LEDS.Pull = GPIO_NOPULL; //same as PA port 15 pin
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    //LEDS.Speed = GPIO_SPEED_HIGH; //same as PA port 15 pin
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;	/* this alternate function we need to use TIM2 in output compare mode */
    //LEDS.Alternate = GPIO_AF2_TIM3; //alternate function to TIM3 channel 1 with PB4 led pin
    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
    //HAL_GPIO_Init(GPIOB, &LEDS); //init B port's led in pwm mode

    /* base timer config ***************************************************************************************************/
    /* we need to enable the TIM2 */
    __HAL_RCC_TIM2_CLK_ENABLE();
    /* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
    pwm_tim.Instance = TIM2;
    pwm_tim.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    pwm_tim.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    pwm_tim.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    pwm_tim.Init.CounterMode		= TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
    HAL_TIM_PWM_Init(&pwm_tim);

    /* output compare config ***********************************************************************************************/
    sConfig.Pulse = 50;
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm_tim, &sConfig, TIM_CHANNEL_1);

    /* starting PWM */
    HAL_TIM_PWM_Start(&pwm_tim, TIM_CHANNEL_1);

}
