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
			
/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef sConfig;

/* pin config: we cannot use the green user LED, because it's not connected to an output compare channel so we use PA15*/
GPIO_InitTypeDef PA15_LED_config;

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    /* GPIO config *********************************************************************************************************/
    __HAL_RCC_GPIOA_CLK_ENABLE();
    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;	/* configure as output, in push-pull mode */
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;	/* this alternate function we need to use TIM2 in output compare mode */
    HAL_GPIO_Init(GPIOA, &PA15_LED_config);

    /* base timer config ***************************************************************************************************/
    /* we need to enable the TIM2 */
    __HAL_RCC_TIM2_CLK_ENABLE();
    /* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
    TimHandle.Instance = TIM2;
    TimHandle.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    TimHandle.Init.Period		= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    TimHandle.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode		= TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
    HAL_TIM_PWM_Init(&TimHandle);

    /* output compare config ***********************************************************************************************/
    sConfig.Pulse = 50;
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);

    /* starting PWM */
    HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);

    while (1) {
        /* we don't need to do here anything, the signal is always on the pin, after starting it once */

        /* a bit more spectacular example: increasing the compare value in every 250 ms
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 0);
        HAL_Delay(250);
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 25);
        HAL_Delay(250);
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 50);
        HAL_Delay(250);
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 75);
        HAL_Delay(250);
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 100);
        */
    }
}
