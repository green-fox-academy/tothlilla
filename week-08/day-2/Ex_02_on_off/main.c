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

// Declare two global variables
uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 150;    // the debounce time in ms (increase if the output flickers)
GPIO_InitTypeDef external_button;
volatile int push_counter = 0;

void init_outside_button()
{
	//init GPIO external button
	__HAL_RCC_GPIOB_CLK_ENABLE();
	external_button.Pin = GPIO_PIN_4;
	external_button.Mode = GPIO_MODE_IT_RISING;
	external_button.Pull = GPIO_NOPULL;
	external_button.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOB, &external_button);

	//set external button interrupt priority
	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);

	//enable the interrupt to HAL
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED_GREEN);
	init_outside_button();



	for(;;);
}

//interrupt handler
void EXTI4_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(external_button.Pin);
}
//declare callback function
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if(GPIO_Pin == external_button.Pin){


	    uint32_t current_time = HAL_GetTick();
	    if (current_time < last_debounce_time + debounce_delay) {
	        // Do nothing (this is not a real button press)
	        return;
	    }
		push_counter++;
		if(push_counter % 10 == 5){
			BSP_LED_On(LED_GREEN);
		}
		if(push_counter % 10 == 0){
			BSP_LED_Off(LED_GREEN);
		}
		last_debounce_time = current_time;
	}

}







