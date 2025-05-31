#include "servo.h"

#include "stm32f4xx_hal.h"

uint16_t X_out;
uint16_t Y_out;

extern TIM_HandleTypeDef htim2; // 定义定时器句柄

void Set_servo_angle(uint16_t angle1,uint16_t angle2)
{
	X_out = (uint16_t)(1000.0f * (((float)angle1 + 4.5f) / 90.0f + 0.5f));
	Y_out = (uint16_t)(1000.0f * (((float)angle2 - 10.8f ) / 90.0f + 0.5f));
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, X_out);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, Y_out);
}

void LED_Toggle(void){
	HAL_GPIO_TogglePin (GPIOC,GPIO_PIN_13);


}