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
GPIO_InitTypeDef GPIOTxConfig; //the uart config for general purpose without BSP
GPIO_InitTypeDef GPIORxConfig; //the uart config for general purpose without BSP
TIM_HandleTypeDef tim;
uint16_t tim_val1; //variable to store the actual value of the timer's register (CNT)
uint32_t user_number = 0;
uint8_t time_as_string[5];
static void Error_Handler(void);
static void SystemClock_Config(void);
void init_GPIO_uart();
void timer_init(void);
time_as_string_2[6];
int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_GPIO_uart();

	//Ask for value

	//memset(time_as_string, '\0', 5);
	printf("Set the timer in this format: wx.yz\r\n");
	HAL_UART_Receive(&uart, (uint8_t*) time_as_string, 5, 0xFFFF);


	strcpy(time_as_string_2, time_as_string);
	printf("\r\n%s\r\n", time_as_string_2);
	//(uint32_t)???
	uint8_t * prt;
	user_number = strtol(time_as_string_2, &prt, 10) * 10000;
	uint8_t * temp = strtok(prt, ".");
	user_number += (strtol(temp, &prt, 10) *100);

	printf("user number %u divide by 5 means prescaler counts until %u\r\n", user_number, user_number/5);
	timer_init();
	HAL_TIM_Base_Start(&tim);	// starting the timer
	tim_val1 = __HAL_TIM_GET_COUNTER(&tim);
	printf("%d first get tim counter \r\n", tim_val1);
	while (1) {
		tim_val1 = __HAL_TIM_GET_COUNTER(&tim);
		//check tim_val_1
		if(tim_val1 == 5000){
			printf("tim val 5000\r\n");
		}
		if(tim_val1 == 2000){
			printf("tim val 2000\r\n");
		}
		if(tim_val1 == 5000){
			printf("tim val 5000\r\n");
		}
		/*if (tim_val1 == 0) {
			printf("%d counting from up to down \r\n", tim_val1);
		}*/
		if (tim_val1 == (user_number/5 - 1)) {
			printf("%s seconds elapsed \r\n", time_as_string_2);
			printf("%d mseconds elapsed \r\n", tim_val1);
			HAL_NVIC_SystemReset();
		}

		if(tim_val1 == 2000){
			printf("tim val 2000\r\n");
		}
	}
}

void timer_init(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	; // we need to enable the TIM2
	tim.Instance = TIM2;
	tim.Init.Prescaler = 54000 - 1; /* 108000000/54000=10000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	//tim.Init.Period = 10000- 1; /* 10000 XYza x 0.5 ms = XY.za 5 second period */
	tim.Init.Period =  user_number/5 - 1; /* 10000 * XYza x 0.5 ms = XY.za 5 second period */
	tim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim.Init.CounterMode = TIM_COUNTERMODE_DOWN;
	HAL_TIM_Base_Init(&tim); 	// configure the timer

}
void init_GPIO_uart() {
//init uart for GPIO purpose with HAL
	//PA9 port 9 pin with AF7 alternate function means USART1_TX - no visible/connecting pin
	//PB9 port 7 pint with AF7 alternate function means USART1_RX - no visible/connecting pin
	/* enable GPIO clock for A and B port*/
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	/* configure GPIO for UART transmit line */
	GPIOTxConfig.Pin = GPIO_PIN_9; //chose PA port 9 pin
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
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	/* defining the UART configuration structure */
	uart.Instance = USART1;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&uart);
}
static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

UART_PUTCHAR {
	HAL_UART_Transmit(&uart, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
