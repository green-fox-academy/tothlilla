#include "interruption_templates.h"

void init_GPIO_extern_button()
{
	//init GPIO external button for general purpose
	__HAL_RCC_GPIOB_CLK_ENABLE(); //giving clock
	external_button_handle.Pin = GPIO_PIN_4;
	external_button_handle.Mode = GPIO_MODE_INPUT;
	external_button_handle.Pull = GPIO_NOPULL;
	external_button_handle.Speed = GPIO_SPEED_FAST;
}

void init_external_button(void)
{
	//init GPIO external button for interrupt handle
	__HAL_RCC_GPIOB_CLK_ENABLE(); //giving clock
	external_button_handle.Pin = GPIO_PIN_4;
	external_button_handle.Mode = GPIO_MODE_IT_RISING; // our mode is interrupt on falling edge
	//external_button_handle.Mode = GPIO_MODE_FALLING; // our mode is interrupt on falling edge
	//external_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	external_button_handle.Pull = GPIO_NOPULL;
	external_button_handle.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOB, &external_button_handle);
	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 1); //set external button interrupt priority
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);	//enable the interrupt to HAL
}
