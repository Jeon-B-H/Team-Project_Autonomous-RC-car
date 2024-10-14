/*
 * Control_RC_Car.c
 *
 *  Created on: Oct 3, 2024
 *      Author: OMG
 */
#include "Control_RC_Car.h"

uint16_t counter = 0;

void control_RC_Car() {
	while(auto_manual) {
		// Check Front HC-SR04
		if(checkTheDistances() == 1) {
			if(distance[0] >= 30 && distance[1] >= 20 && distance[2] >= 20) control_motor(1, 60, 60);
			else {
				if(distance[1] > distance[2]) {
					while(distance[0] < 30) {
						control_motor(3, 50, 50);
					}
				}else {
					while(distance[0] < 30) {
						control_motor(4, 50, 50);
					}
				}
			}
		}
	}
}

uint8_t checkTheDistances() {
	if(distance[0] > 200 || distance[1] > 200 || distance[2] > 200) return 0;
	else if(distance[0] < 3 || distance[1] < 3 || distance[2] < 3) return 0;
	else return 1;
}

