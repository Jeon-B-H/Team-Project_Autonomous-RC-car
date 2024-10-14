#include "HC_SR04.h"

uint8_t distance [3];
static uint16_t IC_Value1 [3];  // Input Capture == Start Point of Echo when ehco starts High-Level
static uint16_t IC_Value2 [3];  // Input Capture == End Point of Echo when ehco ends High-Level
static uint16_t echoTime [3];
static uint8_t captureFlag [3];

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(captureFlag[0]  == 0)
		{
			IC_Value1[0] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
			captureFlag[0] = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(captureFlag[0] == 1)
		{
			IC_Value2[0] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
			__HAL_TIM_SET_COUNTER(&htim2, 0);

			if(IC_Value2[0] > IC_Value1[0])
			{
				echoTime[0] = IC_Value2[0] - IC_Value1[0];
			}
			else if(IC_Value1[0] > IC_Value2[0])
			{
				echoTime[0] = (0xFFFF - IC_Value1[0]) + IC_Value2[0];
			}

			distance[0] = echoTime[0] / 58;
			captureFlag[0] = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2, TIM_IT_CC1);
		}
	} else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if(captureFlag[1]  == 0)
		{
			IC_Value1[1] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);
			captureFlag[1] = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(captureFlag[1] == 1)
		{
			IC_Value2[1] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);
			__HAL_TIM_SET_COUNTER(&htim2, 0);

			if(IC_Value2[1] > IC_Value1[1])
			{
				echoTime[1] = IC_Value2[1] - IC_Value1[1];
			}
			else if(IC_Value1[1] > IC_Value2[1])
			{
				echoTime[1] = (0xFFFF - IC_Value1[1]) + IC_Value2[1];
			}

			distance[1] = echoTime[1] / 58;
			captureFlag[1] = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2, TIM_IT_CC2);
		}
	} else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if(captureFlag[2]  == 0)
		{
			IC_Value1[2] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_3);
			captureFlag[2] = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(captureFlag[2] == 1)
		{
			IC_Value2[2] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_3);
			__HAL_TIM_SET_COUNTER(&htim2, 0);

			if(IC_Value2[2] > IC_Value1[2])
			{
				echoTime[2] = IC_Value2[2] - IC_Value1[2];
			}
			else if(IC_Value1[2] > IC_Value2[2])
			{
				echoTime[2] = (0xFFFF - IC_Value1[2]) + IC_Value2[2];
			}

			distance[2] = echoTime[2] / 58;
			captureFlag[2] = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2, TIM_IT_CC3);
		}
	}
}

void Front_HCSR04 (void) {
	HAL_GPIO_WritePin(FRONT_TRIG_PORT, FRONT_TRIG_PIN, 0);
	delay_us(1);
	HAL_GPIO_WritePin(FRONT_TRIG_PORT, FRONT_TRIG_PIN, 1);
	delay_us(10);
	HAL_GPIO_WritePin(FRONT_TRIG_PORT, FRONT_TRIG_PIN, 0);

	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_CC1);
}

void Left_HCSR04 (void) {
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, 0);
	delay_us(1);
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, 1);
	delay_us(10);
	HAL_GPIO_WritePin(LEFT_TRIG_PORT, LEFT_TRIG_PIN, 0);

	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_CC2);
}

void Right_HCSR04 (void) {
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, 0);
	delay_us(1);
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, 1);
	delay_us(10);
	HAL_GPIO_WritePin(RIGHT_TRIG_PORT, RIGHT_TRIG_PIN, 0);

	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_CC3);
}
