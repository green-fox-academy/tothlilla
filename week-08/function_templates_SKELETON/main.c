/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "interruption_templates.h"

int main(void)
{
	HAL_Init();

	//your possibilities:
	BSP_LED_Init(LED_GREEN); //init LED1/LED_GREEN by BSP
	init_external_led(LEDS); //init external Led on F port pin 7

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO); //init blue user button for general purpose
	init_user_button();		 //init blue user button for interrupt handler mode
	init_external_button();	 //init external button B port pin 4 for interrupt handler mode
	init_uart();			 //init USART for interrupt handler mode



	//others
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1); //in the case of USART we must do it once in the main before the callback - without this the first callback won't get signal
	for(;;);
}

//---------- 1 USER BUTTON HANDLER  -------------------
//user push button PI11 external interrupt handler
void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}
//user push button PI11 external interrupt week callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//if(GPIO_Pin == GPIO_PIN_11){
	if(GPIO_Pin == user_button_handle.Pin){

		BSP_LED_Toggle(LED_GREEN);

		printf("Button interrupt\n"); //need an UART for general purpose!!!
	}
}

//---------- 2 EXTERNAL BUTTON HANDLER  -------------------
//external push button B4 external interrupt handler
void EXTI4_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(external_button_handle.Pin);
}
//declare week callback function
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//if(GPIO_Pin == GPIO_PIN_4){
	if(GPIO_Pin == external_button_handle.Pin){

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

//---------- 3 USART HANDLER  -------------------
//USART external interrupt handler
void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}
//declare week callback function
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1) {
		BSP_LED_Toggle(LED_GREEN);

		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}
}
