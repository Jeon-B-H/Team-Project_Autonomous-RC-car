/*
 * led.c
 *
 *  Created on: Sep 13, 2024
 *      Author: OMG
 */

#include "led.h"

// Initialization of structure
LED_TABLE led_table [8] = {
		{GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET}
};

// Initialization of LED
void led_init(void) {

}

// Turn on LED
void led_on(uint8_t pin) {
	HAL_GPIO_WritePin(led_table[pin].gpio_port, led_table[pin].pinNumber, led_table[pin].onState);
}

// Turn off LED
void led_off(uint8_t pin) {
	HAL_GPIO_WritePin(led_table[pin].gpio_port, led_table[pin].pinNumber, led_table[pin].offState);
}

// Toggle LED
void led_toggle(uint8_t pin) {
	HAL_GPIO_TogglePin(led_table[pin].gpio_port, led_table[pin].pinNumber);
}

