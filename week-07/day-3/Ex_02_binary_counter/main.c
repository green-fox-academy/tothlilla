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
			
GPIO_InitTypeDef LEDS;
int main(void)
{

    HAL_Init();

    /* we need to enable the GPIOA port's clock first */
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    LEDS.Pin = GPIO_PIN_0 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8;	/* setting up 4 pins at once with | operator */
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;		/* configure as output, in push-pull mode */
    LEDS.Pull = GPIO_NOPULL;			/* we don't need internal pull-up or -down resistor */
    LEDS.Speed = GPIO_SPEED_HIGH;		/* we need a high-speed output */

    HAL_GPIO_Init(GPIOF, &LEDS);		/* initialize the pin on GPIOF port */
    HAL_GPIO_Init(GPIOA, &LEDS);
	int counter = 0;

    while (1) {


    	if (counter % 16 > 7){
    		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
    	} else {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
    	}

    	if (counter % 8 > 3){
    		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    	} else {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
    	}

    	if (counter % 4 > 1){
    		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
    	} else {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    	}

    	if (counter % 2 > 0){
    		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    	} else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
            //HAL_Delay(1000);
    	}

    	HAL_Delay(1000);
        counter++;
    }
}
