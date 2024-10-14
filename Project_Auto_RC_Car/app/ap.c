#include "ap.h"
#include "led.h"
#include "cmsis_os.h"

// Global Variables
uint8_t receive_data[8];
uint8_t previous_receive_data;
uint8_t auto_manual;

// Initialization of app
void apInit() {
	// Start PWM
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3);


	// Initialization of UART
	HAL_UART_Receive_DMA(&huart1, receive_data, sizeof(receive_data));

	//
	HAL_TIM_Base_Start(&htim10);    // For Delay function
}


// New Main Functions
void apMain() {
	osKernelStart();
}
