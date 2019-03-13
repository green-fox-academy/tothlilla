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

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void)
{
	HAL_Init();				//making HAL configuration
	SystemClock_Config(); 	//for TIMERS - this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */


	//your possibilities:
	BSP_LED_Init(LED_GREEN); //init LED1/LED_GREEN by BSP
	init_external_led(LEDS); //init external Led on F port pin 7

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO); //init blue user button for general purpose
	init_user_button();		 //init blue user button for interrupt handler mode
	init_external_button();	 //init external button B port pin 4 for interrupt handler mode
	init_uart();			 //init USART for interrupt handler mode
	init_timer();			 //init TIM2 for interrupt handler mode


	//others
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1); //in the case of USART we must do it once in the main before the callback - without this the first callback won't get signal
	HAL_TIM_Base_Start_IT(&tim_handle); //starting the timer - init_timer() won't work without it
	HAL_TIM_PWM_Start_IT(&pwm_tim_handle, TIM_CHANNEL_1);
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
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
	}
}

//---------- 5 PWM TIM3 HANDLER  -------------------
//TIM3 external interrupt handler
void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim_handle);
}

//declare week callback function
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	//if (htim->Instance == TIM3)
	if (htim->Instance == tim_handle.Instance) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
	}
}

//error handler
static void Error_Handler(void)
{}
//system clock config to TIMERs
static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

//using printf()
UART_PUTCHAR
{
    HAL_UART_Transmit(&UartHandle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
