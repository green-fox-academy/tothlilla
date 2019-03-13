/*
 * interruption_templates.c
 *
 *  Created on: 2019. márc. 12.
 *      Author: Lilla
 */

#include "interruption_templates.h"

	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping function,
	 * because the grouping defaults to NVIC_PRIORITYGROUP_2:
	 * HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	 */

void init_external_button(void)
{
	//init GPIO external button
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

void init_uart(void)
{
	__HAL_RCC_USART1_CLK_ENABLE(); 	//giving clock

	/* defining the UART configuration structure */
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	//uart_handle.Init.Mode = UART_MODE_TX;
	//uart_handle.Init.Mode = UART_MODE_RX;
	BSP_COM_Init(COM1, &uart_handle); //init USART
	HAL_NVIC_SetPriority(USART1_IRQn, 3, 0); //set USART interrupt priority
	HAL_NVIC_EnableIRQ(USART1_IRQn); //enable the interrupt to HAL
}
void init_external_led(GPIO_InitTypeDef LEDS)
{
	//initialize external LED on F port pin 7
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_7;  		// setting up a pin
	//LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);
}
