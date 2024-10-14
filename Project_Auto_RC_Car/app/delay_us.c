#include "delay_us.h"

void delay_us(uint16_t us) {
	// First Argument : Hander Counter
	// Second Argument : Initialization 0
	__HAL_TIM_SET_COUNTER(&htim10, 0);

	// Wait for us [usecond]
	while((__HAL_TIM_GET_COUNTER(&htim10)) < us);
}
