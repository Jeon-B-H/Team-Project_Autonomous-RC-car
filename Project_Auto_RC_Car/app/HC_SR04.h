/*
 * HC_SR04.h
 *
 *  Created on: Oct 2, 2024
 *      Author: OMG
 */

#ifndef HC_SR04_H_
#define HC_SR04_H_

// Include Header File
#include "gpio.h"
#include "main.h"
#include "tim.h"
#include "usart.h"

#include "delay_us.h"

// Global Variables

// Define Constant
#define FRONT_TRIG_PORT 	GPIOA
#define FRONT_TRIG_PIN      GPIO_PIN_1

#define LEFT_TRIG_PORT 		GPIOC
#define LEFT_TRIG_PIN       GPIO_PIN_8

#define RIGHT_TRIG_PORT 	GPIOC
#define RIGHT_TRIG_PIN      GPIO_PIN_6

// Function prototype
void Front_HCSR04 (void);
void Left_HCSR04 (void);
void Right_HCSR04 (void);

#endif /* HC_SR04_H_ */
