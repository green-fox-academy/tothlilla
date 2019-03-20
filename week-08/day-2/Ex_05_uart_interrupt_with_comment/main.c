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
volatile char buffer[6]; //to USART (Receiver) interrupt handler
volatile char single_char; //this is the word's letters
volatile int buffer_index = 0; //the index of letters/single chars in the buffer
volatile int command_parameter = 3;
// size_t is lehetne a buffer_index típusa
UART_HandleTypeDef uart_handle; // UART config handle structure
GPIO_InitTypeDef LEDS;		//the external Led config structure
TIM_HandleTypeDef tim_handle; // timer (TIM2) config handle structure

static void Error_Handler(void);
static void SystemClock_Config(void);
void init_external_led();
void init_timer(void);
void init_uart(void);

int main(void) {
	HAL_Init();				//making HAL configuration
	SystemClock_Config();
	init_external_led();
	init_timer();
	init_uart();
	printf("starting\r\n");
	//printf("next\r\n");
	HAL_TIM_Base_Start_IT(&tim_handle); //starting the timer - init_timer() won't work without it
	//printf("starting2\r\n");
	HAL_UART_Receive_IT(&uart_handle, &single_char, 1); //in the case of USART we must do it once in the main before the callback
	//ez egyszerre csak egy karaktert vesz be!
	//printf("starting3\r\n");
	//if (!strcmp(buffer, "EEEEE")){
	//printf("%s\r\n", buffer);

	//}

	while (1) {
		if (command_parameter == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			//printf("%s 0 command\r\n", buffer);
			//HAL_Delay(500);
		} else if (command_parameter == 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
			//printf("%s 1 command\r\n", buffer);
			//HAL_Delay(500);
		//} else if (command_parameter == 2) {
			//printf("%s 2 command\r\n", buffer);
			//HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
			//HAL_Delay(500);
		}
	}
}

void init_external_led() {
	//initialize LED
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;	//giving clock
	LEDS.Pin = GPIO_PIN_7;  		// setting up a pin
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &LEDS);
}

void init_timer(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&tim_handle);
	tim_handle.Instance = TIM2;
	tim_handle.Init.Prescaler = 10800 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	tim_handle.Init.Period = 5000 - 1; // 5000 x 0.1 ms = 500 ms = 0.5 s period */
	tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle); 	// configure the timer
	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0); // assign the highest priority to our interrupt line
	HAL_NVIC_EnableIRQ(TIM2_IRQn); //	/* tell the interrupt handling unit to process our interrupts */
}

void init_uart(void) //init uart for interrupt handle with BSP
{
	__HAL_RCC_USART1_CLK_ENABLE()
	; 	//giving clock
	/* defining the UART configuration structure */
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle); //init USART
	HAL_NVIC_SetPriority(USART1_IRQn, 1, 0); //set USART interrupt priority
	HAL_NVIC_EnableIRQ(USART1_IRQn); //enable the interrupt to HAL
}
//error handler
static void Error_Handler(void) {

}
//system clock config to TIMERs
static void SystemClock_Config(void) {
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

//---------- 3 USART HANDLER  -------------------
//USART external interrupt handler
void USART1_IRQHandler() {
	HAL_UART_IRQHandler(&uart_handle);
}
//declare week callback function
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART1) {

		if (single_char == '\n' || single_char == '\r') {
			buffer[buffer_index] = '\0';
			buffer_index = 0;
			if (!strcmp(buffer, "on")) {
				command_parameter = 1;
			} else if (!strcmp(buffer, "off")) {
				command_parameter = 0;
			} else if (!strcmp(buffer, "flash")) {
				command_parameter = 2;
			}
		} else {
			buffer[buffer_index] = single_char;
			//printf("\r\n%c\r\n", single_char);
			//printf("%s\r\n", buffer);
			buffer_index++;
		}

		HAL_UART_Receive_IT(&uart_handle, &single_char, 1);
	}
}
//---------- 4 TIM2 HANDLER  -------------------
//TIM2 external interrupt handler
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim_handle);
}
//declare week callback function
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//if (htim->Instance == TIM2)
	if (htim->Instance == tim_handle.Instance) {
		if (command_parameter == 2){
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
		}

	}
}


UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
