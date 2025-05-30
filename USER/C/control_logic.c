#include "control_logic.h"
#include "control.h"
#include "uart.h"

extern TIM_HandleTypeDef htim1;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
//		if (Finded_flag == 1){
			control();
//			HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
			
			HAL_TIM_Base_Start_IT(&htim1);
		}
//    }
		
}












