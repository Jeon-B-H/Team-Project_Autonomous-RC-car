/*
 * led.h
 *
 *  Created on: Sep 13, 2024
 *      Author: OMG
 */

#ifndef HW_DRIVER_LED_H_
#define HW_DRIVER_LED_H_

#include "hw_def.h"

// Define user defined structure
typedef struct {
	GPIO_TypeDef*     gpio_port;
	uint16_t 	      pinNumber;
	GPIO_PinState     onState;
	GPIO_PinState     offState;
} LED_TABLE;


// Define function prototype
void led_init(void);
void led_on(uint8_t pin);
void led_off(uint8_t pin);
void led_toggle(uint8_t pin);


#endif /* HW_DRIVER_LED_H_ */
