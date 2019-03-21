#include "interruption_templates.h"

//task variables
//uint16_t tim_val = 0;		/* variable to store the actual value of the timer's register (CNT) */
//uint16_t seconds = 0;		/* variable to store the value of ellapsed seconds */
//tim_val = __HAL_TIM_GET_COUNTER(&tim);
//if (tim_val == 0) {}
//if (tim_val == 1000) {}


void timer_init(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE(); // we need to enable the TIM2
	tim.Instance = TIM2;
	tim.Init.Prescaler = 54000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	tim.Init.Period = 2000 - 1; /* 2000 x 0.5 ms = 1 second period */
	tim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim); 	// configure the timer
	HAL_TIM_Base_Start(&tim);	// starting the timer
}


void init_timer(void) {
	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&tim_handle);
	__HAL_TIM_SET_COUNTER(&tim_handle, 0);
	tim_handle.Instance = TIM2;
	tim_handle.Init.Prescaler = 54000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	tim_handle.Init.Period = 12000 - 1; /* 6000 x 0.5 ms = 6 second period */
	tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle); 	// configure the timer
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0); // assign the highest priority to our interrupt line
	HAL_NVIC_EnableIRQ(TIM2_IRQn); //	/* tell the interrupt handling unit to process our interrupts */
}
