#include "System/System.h"
//设置通用定时器频率，记得检查系统时钟频率
#define GENERAL_TIM_FREQUENCY_SET(TIM, frequency)  do{TIM->PSC = (uint16_t)(SystemCoreClock / 2000000 - 1);TIM->ARR = (uint16_t)(1000000 / (frequency) - 1);}while(0)


uint32_t i = 0;
uint32_t j = 0;
float  aa = 0;

//uint8_t (*font_ptr)[64] = (uint8_t (*)[64])(Ascii_font->font_data);

uint8_t ta[8] = {1,2,3,4,5,6,7,8};
uint8_t ra[8] = {0};

uint8_t ta2[8] = {11,22,33,44,55,66,77,88};
uint8_t ra2[8] = {0};

void System_Init(void)
{
    Menu_Struct_Init(pMenu_structure, &page_peripheral_interface);
    //TIM
    HAL_TIM_Base_Start_IT(&htim3);
    GENERAL_TIM_FREQUENCY_SET(TIM3, 100);
    //FDCAN
    FDCAN_Filter_Init(&hfdcan2);
    FDCAN_Filter_Init(&hfdcan3);
    HAL_FDCAN_Start(&hfdcan2);
    HAL_FDCAN_Start(&hfdcan3);
    
    FDCAN_Transmit(&hfdcan2, ta);
    
    
   // printf("ok\n");
    
}


void System_Run(void)
{
    //LED1
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    //Display_Init
    Menu_Display_Init(pMenu_structure);
    //Printf
    
    FDCAN_Receive(&hfdcan2, ra);
    FDCAN_Receive(&hfdcan3, ra2);
    
    Display_UnNumber(0,0,ta[0],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(0,2,ra[0],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(0,4,ta[7],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(0,6,ra[7],0,4,BLACK,SIZE8_16,-1);
    
    Display_UnNumber(60,0,ta2[0],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(60,2,ra2[0],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(60,4,ta2[7],0,4,BLACK,SIZE8_16,-1);
    Display_UnNumber(60,6,ra2[7],0,4,BLACK,SIZE8_16,-1);
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
//        Menu_Run(pMenu_structure);
    }
}


