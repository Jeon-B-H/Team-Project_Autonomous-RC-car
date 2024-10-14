#include "motor.h"

uint8_t IN_values[4];

// Control Motor
void control_motor(uint8_t direction, uint8_t left_duty, uint8_t right_duty) {
	// Select IN Values
	if(auto_manual == 0) select_IN_values();
	else if(auto_manual == 1) select_IN_values_For_Auto_mode (direction);

	// Enter IN Values to Motor driver
	enter_IN_values();

	// Entr duty of Motor.
	enter_duty_of_motor(left_duty, right_duty);
}

void select_IN_values_For_Auto_mode (uint8_t direction) {
	// 0 : Stop
	// 1 : Forward
	// 2 : BackWard
	// 3 : Left
	// 4 : Right
	switch (direction) {
		case 0 :
			IN_values[0] = 1;
			IN_values[1] = 1;
			IN_values[2] = 1;
			IN_values[3] = 1;
			break;

		case 1:
			IN_values[0] = 1;
			IN_values[1] = 0;
			IN_values[2] = 1;
			IN_values[3] = 0;
			break;

		case 2:
			IN_values[0] = 0;
			IN_values[1] = 1;
			IN_values[2] = 0;
			IN_values[3] = 1;
			break;

		case 3:
			IN_values[0] = 1;
			IN_values[1] = 0;
			IN_values[2] = 0;
			IN_values[3] = 1;
			break;

		case 4:
			IN_values[0] = 0;
			IN_values[1] = 1;
			IN_values[2] = 1;
			IN_values[3] = 0;
			break;
		}
}

// Select IN Values
void select_IN_values() {
	if(receive_data[5] == 0) {
		if(receive_data[6] == 0) {
			IN_values[0] = GPIO_PIN_SET;
			IN_values[1] = GPIO_PIN_SET;
			IN_values[2] = GPIO_PIN_SET;
			IN_values[3] = GPIO_PIN_SET;
		}else if(receive_data[6] == 1) {
			IN_values[0] = GPIO_PIN_SET;
			IN_values[1] = GPIO_PIN_RESET;
			IN_values[2] = GPIO_PIN_SET;
			IN_values[3] = GPIO_PIN_RESET;
		}else if(receive_data[6] == 2) {
			IN_values[0] = GPIO_PIN_RESET;
			IN_values[1] = GPIO_PIN_SET;
			IN_values[2] = GPIO_PIN_RESET;
			IN_values[3] = GPIO_PIN_SET;
		}else if(receive_data[6] == 4) {
			IN_values[0] = GPIO_PIN_RESET;
			IN_values[1] = GPIO_PIN_SET;
			IN_values[2] = GPIO_PIN_SET;
			IN_values[3] = GPIO_PIN_RESET;
		}else if(receive_data[6] == 8) {
			IN_values[0] = GPIO_PIN_SET;
			IN_values[1] = GPIO_PIN_RESET;
			IN_values[2] = GPIO_PIN_RESET;
			IN_values[3] = GPIO_PIN_SET;
		}
	}
}

// Enter IN Values
void enter_IN_values() {
	HAL_GPIO_WritePin(IN1_PORT, IN1_PIN, IN_values[0]);
	HAL_GPIO_WritePin(IN2_PORT, IN2_PIN, IN_values[1]);
	HAL_GPIO_WritePin(IN3_PORT, IN3_PIN, IN_values[2]);
	HAL_GPIO_WritePin(IN4_PORT, IN4_PIN, IN_values[3]);
}

// Enter Duty of Motor
void enter_duty_of_motor(uint8_t left_duty, uint8_t right_duty) {
	TIM1->CCR2 = left_duty;
	TIM3->CCR2 = right_duty;
}
