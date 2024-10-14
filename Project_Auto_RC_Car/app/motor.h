/*
 * motor.h
 *
 *  Created on: Oct 2, 2024
 *      Author: OMG
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "gpio.h"

// Define Constant
#define IN1_PIN     GPIO_PIN_5
#define IN2_PIN     GPIO_PIN_6
#define IN3_PIN	 	GPIO_PIN_7
#define IN4_PIN		GPIO_PIN_6

#define IN1_PORT 	GPIOA
#define IN2_PORT	GPIOA
#define IN3_PORT	GPIOA
#define IN4_PORT	GPIOB

// Declare Function Prototype
void apInit();
void apMain();
void control_motor(uint8_t direction, uint8_t left_duty, uint8_t right_duty);
void select_IN_values();
void enter_IN_values();
void enter_duty_of_motor(uint8_t left_duty, uint8_t right_duty);
void select_IN_values_For_Auto_mode (uint8_t direction);

// Global Variables
extern uint8_t receive_data[8];
extern uint8_t IN_values [4];
extern uint8_t auto_manual;

#endif /* MOTOR_H_ */
