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
GPIO_InitTypeDef push_button;

int main(void) {



	HAL_Init();

	__HAL_RCC_GPIOF_CLK_ENABLE();

	LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8; /* setting up 4 pins at once with | operator */
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);

	__HAL_RCC_GPIOB_CLK_ENABLE();
	push_button.Pin = GPIO_PIN_4;
	push_button.Mode = GPIO_MODE_INPUT;
	push_button.Pull = GPIO_NOPULL;
	push_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOB, &push_button);

	int counter = 0;
	int button_previous_state = 0;

	while (1) {
		int button_current_state = HAL_GPIO_ReadPin(GPIOB, push_button.Pin);

		if (button_previous_state == 0 && button_current_state == 1) {

				if (counter % 16 > 7) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
				} else {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
				}

				if (counter % 8 > 3) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
				} else {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
				}

				if (counter % 4 > 1) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				} else {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				}

				if (counter % 2 > 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				} else {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				}

				HAL_Delay(500);
				counter++;
			}
		button_previous_state = button_current_state;
		}
}

