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

int main(void) {
	//HAL initialization
	HAL_Init();
	//Inner button (BUTTON_KEY) initialization
	//BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	//Inner led (LED1) initialization
	BSP_LED_Init(LED1);

	int delay_time_set = 500; //Starting delay time of the led set case
	int delay_time_reset = 250; //Constant delay time of the led set case
	int speed_status = 1; //Speed up/speed down status changer
	int counter = 1;	  //Counter of loops

	while (1) {

		if ((counter % 3) != 0) { //Cases of every first and second loops
			//Set/reset of the led with an actual delay time
			BSP_LED_On(LED1);
			HAL_Delay(delay_time_set);
			BSP_LED_Off(LED1);
			HAL_Delay(delay_time_reset);

			counter++;
		} else { 				 //Cases of every third loops
			//Set/reset of the led with an actual delay time
			BSP_LED_On(LED1);
			HAL_Delay(delay_time_set);
			BSP_LED_Off(LED1);
			HAL_Delay(delay_time_reset);

			//Change status when you reach the max or min delay time
			if (delay_time_set == 500) { //If we reach the minimum delay time
				speed_status = 1;
			} else if (delay_time_set == 4000) { //If we reach the maximum  delay time
				speed_status = 0;
			}

			//Change the delay time
			if (speed_status) {
				delay_time_set *= 2;
			} else {
				delay_time_set /= 2;
			}

			counter++;
		}

	}
}
