/*
 * Control_RC_Car.h
 *
 *  Created on: Oct 3, 2024
 *      Author: OMG
 */

#ifndef CONTROL_RC_CAR_H_
#define CONTROL_RC_CAR_H_

// Include Header File
#include "gpio.h"
#include "motor.h"
#include "delay_us.h"

// Global Variables
extern uint8_t distance [3];
extern uint8_t auto_manual;

// Function Prototype
void control_RC_Car();
void auto_control_motor(uint8_t direction, uint8_t para_auto_left_duty, uint8_t para_auto_right_duty);
uint8_t checkTheDistances();

#endif /* CONTROL_RC_CAR_H_ */
