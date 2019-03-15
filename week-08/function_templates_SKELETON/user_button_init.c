#include "interruption_templates.h"

//init user_button for interrupt handle
void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); // enable the GPIOI clock
	user_button_handle.Pin = GPIO_PIN_11; // the pin is the PI11
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; // port speed to fast
	user_button_handle.Mode = GPIO_MODE_IT_RISING; // our mode is interrupt on rising edge
	//user_button_handle.Mode = GPIO_MODE_IT_FALLING; // our mode is interrupt on falling edge
	//user_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	HAL_GPIO_Init(GPIOI, &user_button_handle); // init PI11 user button
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);	//set blue PI11 user button interrupt priority
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //enable the interrupt to HAL
}
