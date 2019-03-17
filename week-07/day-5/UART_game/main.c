#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

//I made it based on Bola00's solution

#define UART_PUTCHAR int __io_putchar(int ch)
GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;
RNG_HandleTypeDef rng_handle;
UART_HandleTypeDef uart;
GPIO_InitTypeDef leds;
GPIO_InitTypeDef external_button;

void init();
int active_waiting(int waiting);

int main(void)
{
	//Part1: initialize things
	HAL_Init();
	init(); //init everything in one round

	//Part2: starting stage of the game, which is destroyed by a button push
	printf("Let's play a game! Are you ready?\n");
	//mechanism: toggle LED until someone won't push the button
	while (1) {
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
		if (active_waiting(500)) //break, if active_waiting(500) function return true
			break;

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
		if (active_waiting(500)) //break, if active_waiting(500) function return true
			break;
	}
	printf("Start!\nReady!\n");
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);

	//Part3: the game
	int random_flash;
    while (1) {
    	 uint32_t random_number = HAL_RNG_GetRandomNumber(&rng_handle); //it gets a rng, not generate a rng
    	 random_flash = random_number % 10 + 1; //this is a number between 1 and 10
    	 HAL_Delay(random_flash * 1000);  //this is a number between 1000 msec and 10000 msec


       	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET); //light up a led as a sign of the starting
       	 int starting_time = HAL_GetTick(); //get a starting time

       	 //nothing will happen until someone won't push the button
    	 while(!HAL_GPIO_ReadPin(GPIOB, external_button.Pin)) {

    	 }

    	 int ending_time = HAL_GetTick(); //get an ending time after someone pushed the button
     	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET); //light down means, someone pushed the button

     	 //Part 4: printf() the result of the game
     	 printf("your time: %d\n", ending_time - starting_time);
     	 break;
    }
}
void init()
{
	/* enable GPIO clocks */
	__HAL_RCC_GPIOA_CLK_ENABLE(); //A9 TX
	__HAL_RCC_GPIOB_CLK_ENABLE(); //B7 RT,  B4 button
	__HAL_RCC_GPIOF_CLK_ENABLE(); //F7 Led,
	/* configure GPIO for UART transmit line */
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);
	/* configure GPIO for UART receive line */
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOB, &GPIORxConfig);
	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE();
	/* defining the UART configuration structure */
	uart.Instance = USART1;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart);
	/* defining a LED configuration structure */
	leds.Pin = GPIO_PIN_7; /* setting up 1 pins */
	leds.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	leds.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	leds.Speed = GPIO_SPEED_FAST; /* we need a high-speed output */
	HAL_GPIO_Init(GPIOF, &leds); /* initialize the pin on GPIOF port */
	/* defining the button configuration structure */
	external_button.Pin = GPIO_PIN_4;
	external_button.Mode = GPIO_MODE_INPUT;
	external_button.Pull = GPIO_NOPULL;
	external_button.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOB, &external_button);
	/* defining the RNG (random number generator) configuration structure */
	__HAL_RCC_RNG_CLK_ENABLE();
	rng_handle.Instance = RNG;
	HAL_RNG_Init(&rng_handle);
}
int active_waiting(int waiting){
	int tickstart = HAL_GetTick(); //take an instant time
	//printf("%d\n",tickstart); //checking the mechanism
	while (HAL_GetTick() - tickstart < waiting) { //function must wait 500 msec, wether someone touch the button, exp: (15365 - 15039) < 500
		if (HAL_GPIO_ReadPin(GPIOB, external_button.Pin))
			return 1;	//if someone push the button, it returns true
	}
	return 0;
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}



