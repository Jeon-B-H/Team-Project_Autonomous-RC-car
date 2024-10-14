/*
 * hw.c
 *
 *  Created on: Sep 13, 2024
 *      Author: OMG
 */

#include "hw.h"


// Delay Function
void delay(uint32_t ms) {
	HAL_Delay(ms);
}

// miliseond counter function
uint32_t millis(void) {
	return HAL_GetTick();
}
