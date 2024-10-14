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
      checkTheDistances();
      // 충분한 거리일 때 전진
      if(distance[0] >= 50 && distance[1] >= 10 && distance[2] >= 10) {
          control_motor(1, 90, 90); // 전방 주행
          HAL_Delay(80);
      }
      // 도로가 좁은 구간
      else if(distance[0] >= 50 && distance[1] <= 9 && distance[2] <= 9)
        {
          control_motor(1, 60, 60); // 전방 주행
          HAL_Delay(80);
        }
      // 전방이 가까울 때 좌회전
      else if(distance[1] - (distance[2]) >= 10) {
          control_motor(4, 55, 60); // 좌회전
          HAL_Delay(80); // 거리 갱신
      }
      // 전방이 가까울 때 우회전
      else{
          control_motor(3, 60, 55); // 우회전
          HAL_Delay(80); // 거리 갱신
      }
  }
}



uint8_t checkTheDistances() {
	if(distance[0] > 200 || distance[1] > 200 || distance[2] > 200) return 0;
	else if(distance[0] < 3 || distance[1] < 3 || distance[2] < 3) return 0;
	else return 1;
}

