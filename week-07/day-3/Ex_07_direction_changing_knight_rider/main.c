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
GPIO_InitTypeDef external_button;
void init_external_led()
{
	//initialize external LED on F port pin 7
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);	//first param: name of port, second param: name of structure
}
void init_GPIO_extern_button()
{
	//init GPIO external button for general purpose
	__HAL_RCC_GPIOB_CLK_ENABLE(); //giving clock
	external_button.Pin = GPIO_PIN_4;
	external_button.Mode = GPIO_MODE_INPUT;
	external_button.Pull = GPIO_NOPULL;
	external_button.Speed = GPIO_SPEED_FAST;
}


int main(void) {
	HAL_Init();
	init_external_led();
	init_GPIO_extern_button();
	int counter = 0;
	int prev_state = 0;
	int switcher = 0;
	while (1) {
		int curr_state = HAL_GPIO_ReadPin(GPIOB, external_button.Pin);
		if (prev_state == 0 && curr_state == 1) {
			if (switcher == 1) {
				switcher = 0;
			} else if (switcher == 0) {
				switcher = 1;
			}
		}

		if (switcher == 0) {
			for (int i = 0; i < 4; ++i) {
				if (counter % 4 == 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				}
				if (counter % 4 == 1) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				}
				if (counter % 4 == 2) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
				}
				if (counter % 4 == 3) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
				}
				counter++;
				HAL_Delay(200);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			}
			counter = 0;
		}
		if (switcher == 1) {
			for (int i = 0; i < 4; ++i) {
				if (counter % 4 == 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
				}
				if (counter % 4 == 1) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
				}
				if (counter % 4 == 2) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				}
				if (counter % 4 == 3) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				}
				counter++;
				HAL_Delay(200);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			}
			counter = 0;
		}
		prev_state = curr_state;
	}
}

