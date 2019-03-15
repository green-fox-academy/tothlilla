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
#include <string.h>

#define UART_PUTCHAR int __io_putchar(int ch)
UART_HandleTypeDef uart;
GPIO_InitTypeDef LEDS;

void init_GPIO_BSP_uart();
void init_external_led();

int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED1);

	init_GPIO_BSP_uart();
	init_external_led();


	char buffer[4];
	memset(buffer, '\0', 4);
	char received_from_hercules[2] = "\0";

	while (1) {
		char received_from_hercules[4];
		memset(received_from_hercules, '\0', 4);
		HAL_UART_Receive(&uart, (uint8_t*) received_from_hercules, 3, 3000);

		if (strcmp(received_from_hercules, "ON") == 0) {
			BSP_LED_On(LED1);
			printf("OK ON");
		} else if (strcmp(received_from_hercules, "OFF") == 0) {
			BSP_LED_Off(LED1);
			printf("OK OFF");
		} else if (strcmp(received_from_hercules, "") == 0) {
			printf("waiting");
		} else {
			printf("not OK");
			for (int i = 0; i < 3; i++) {
				BSP_LED_Off(LED1);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
				HAL_Delay(500);
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
				HAL_Delay(500);
			}
		}
	}
}



void init_GPIO_BSP_uart()
{
//init uart for GPIO purpose with BSP
	/* enable GPIO clock for A and B port*/
	__HAL_RCC_USART1_CLK_ENABLE();
	/* defining the UART configuration structure */
	uart.Instance = USART1;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart);
}
void init_external_led()
{
	//initialize external LED on F port pin 7
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_7;  		// setting up a pin
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);	//first param: name of port, second param: name of structure
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
