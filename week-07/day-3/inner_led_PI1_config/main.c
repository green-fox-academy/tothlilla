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
			

#define USING_BSRR
//#define USING_ODR

int main(void)
{
    HAL_Init();

    /* GPIOI Periph clock enable */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

    /* configure PI1 in output mode */
    GPIOI->MODER |= (GPIO_MODER_MODER1_0);

    /* ensure push pull mode selected default */
    GPIOI->OTYPER &= ~(GPIO_OTYPER_OT_1);

    /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOI->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1);

    /* ensure all pull up pull down resistors are disabled */
    GPIOI->PUPDR &= ~(GPIO_PUPDR_PUPDR1);

    uint32_t green_led = (1 << 1);

    while (1) {
        /* using BSRR register */
#ifdef USING_BSRR
        GPIOI->BSRR = green_led;		/* set PI1 */
        HAL_Delay(1000);

        GPIOI->BSRR = green_led << 16;		/* reset PI1 */
        HAL_Delay(1000);
#endif

        /* or using ODR register */
#ifdef USING_ODR
        GPIOI->ODR = GPIOI->ODR ^ green_led;	/* set pi1 to 1, leave the others as they are */
        HAL_Delay(1000);

        GPIOI->ODR ^= green_led;		/* This will set PI1 to 0. Guess why! */
        HAL_Delay(1000);
#endif
    }
}
