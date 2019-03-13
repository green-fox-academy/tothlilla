#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

//create global variable configuration structs
//---------- interrupt handle variables ------------------
GPIO_InitTypeDef user_button_handle; // the PI11 user button handle structure
GPIO_InitTypeDef external_button_handle; // the B4 external digital(?) button handle structure
UART_HandleTypeDef uart_handle; // UART config handle structure
//no interrupt handle variables
GPIO_InitTypeDef LEDS;		//the external Led config structure

//---------- task variables -------------------------------
//---------- 2 EXTERNAL BUTTON HANDLER  -------------------
uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 150;    // the debounce time in ms (increase if the output flickers)
volatile int push_counter = 0;

//---------- 3 USART HANDLER  -----------------------------
volatile char buffer; //to USART (Receiver) interrupt handler

//interrupt handler functions
void init_user_button(void); //init board user push button PI11 with external interrupt
void init_external_button(void); //init external push button B port 4 pin with external interrupt
void init_uart(void); //init USART with external interrupt

//general functions
void init_external_led(GPIO_InitTypeDef LEDS); //external led on F port 7 pin (8, 9 , 10)


