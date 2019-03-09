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
			
int main(void)
{
    HAL_Init();

    /* setting PI1 as output */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
    GPIOI->MODER |= (GPIO_MODER_MODER1_0);
    GPIOI->OTYPER &= ~(GPIO_OTYPER_OT_1);
    GPIOI->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1);
    GPIOI->PUPDR &= ~(GPIO_PUPDR_PUPDR1);


    /* setting PI11 as input */
    GPIOI->MODER |= 0b0000100000000000;

    uint32_t green_led = (1 << 1);

    while (1) {
        /* when button is pushed LED turns on, when released, then LED turns off */
        if (GPIOI->IDR & (1 << 11)) {
            GPIOI->BSRR = green_led;
        } else {
            GPIOI->BSRR = green_led << 16;
        }
    }
}
