#include "interruption_templates.h"

void init_external_led(GPIO_InitTypeDef LEDS)
{
	//initialize external LED on F port pin 7
    __HAL_RCC_GPIOF_CLK_ENABLE();	//giving clock
	LEDS.Pin = GPIO_PIN_7;  		// setting up a pin
	//LEDS.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);	//first param: name of port, second param: name of structure
}
