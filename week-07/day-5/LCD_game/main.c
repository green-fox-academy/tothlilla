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
			
/* necessary include files */
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

static void Error_Handler(void);
static void SystemClock_Config(void);
TS_StateTypeDef current_ts_status;
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    /* initializing LCD */
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_Clear(LCD_COLOR_WHITE);

    /* drawing a red circle */
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_FillCircle(50, 50, 30);


	/* initializing TS (Touch Screen) */
	BSP_TS_Init(480, 272);



	uint8_t text1_on_LCD[] = "Let's play a game! Are you ready?"; //Beginning text
	uint8_t text2_on_LCD[] = "Something else";

	//Beginning text parameters on LCD
	sFONT start_text_fonts_size = Font16; //Changing default font size
	BSP_LCD_SetFont(&start_text_fonts_size); //Using font size function
	BSP_LCD_Clear(LCD_COLOR_GREEN); //Green color LCD background
	BSP_LCD_SetBackColor(LCD_COLOR_GREEN); //Green color text background
	BSP_LCD_DisplayStringAt(0, 0, text1_on_LCD, CENTER_MODE);
	HAL_Delay(500);
	/* BSP_LCD_SetBackColor(LCD_COLOR_WHITE); //White color LCD background
	BSP_LCD_Clear(LCD_COLOR_WHITE); //White color text background
	BSP_LCD_DisplayStringAt(0, 0, text1_on_LCD, CENTER_MODE);
	HAL_Delay(500);
    */

    while (1) {


    	//Beginning status of TS
    	BSP_TS_GetState(&current_ts_status);
    	if (current_ts_status.touchX[0] != 0 && current_ts_status.touchY[0] != 0) {
    		BSP_LCD_Clear(LCD_COLOR_WHITE);
    		BSP_LCD_DisplayStringAt(0, 0, text2_on_LCD, CENTER_MODE);
    		current_ts_status.touchX[0];
    		current_ts_status.touchY[0];
    		HAL_Delay(500);
    	}
    }
}

static void Error_Handler(void)
{}

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

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){}
#endif
