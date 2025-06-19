#include "System/System.h"
//设置通用定时器频率，记得检查系统时钟频率
#define GENERAL_TIM_FREQUENCY_SET(TIM, frequency)  do{TIM->PSC = (uint16_t)(SystemCoreClock / 2000000 - 1);TIM->ARR = (uint16_t)(1000000 / (frequency) - 1);}while(0)


uint32_t i = 0;
uint32_t j = 0;
float  aa = 0;

//uint8_t (*font_ptr)[64] = (uint8_t (*)[64])(Ascii_font->font_data);


void System_Init(void)
{
    Menu_Struct_Init(pMenu_structure, &page_peripheral_interface);
    //TIM
    HAL_TIM_Base_Start_IT(&htim3);
    GENERAL_TIM_FREQUENCY_SET(TIM3, 100);
   // printf("ok\n");

    

}


void System_Run(void)
{
    //LED1
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    //Display_Init
    Menu_Display_Init(pMenu_structure);
    //Printf
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);

    /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
    */
    if (htim == &htim3)  //Menu中断100Hz
    {
        j++;
        //LED3
        HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
        Menu_Run(pMenu_structure);
    }
}


