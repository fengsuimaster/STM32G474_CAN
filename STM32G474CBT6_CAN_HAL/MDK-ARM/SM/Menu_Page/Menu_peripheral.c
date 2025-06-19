#include "Menu_Page/Menu_peripheral.h"


uint16_t ADC_IN[4] = {1,2,3,4};
uint16_t DAC_OUT1 = 123;
uint16_t DAC_OUT2 = 1323;
uint8_t onoff_test = 0;
float float_test = 12.34;

/************************************************************************ADC章************************************************************************/
/********************************************重映射外设项********************************************/
DECLARE_ITEM(float_test, float32_t, "float", menu_item_static_parameter_type, 4);
cMenu_item_struct_Typedef
item_onoff_test = {{&onoff_test  , puint8_type}, (cstring_t)"oftest",  menu_item_onoff_type , .intdigit=4},
item_adc1in1   =  {{&ADC_IN[0]   , puint16_type}, (cstring_t)"ADC1IN1",  menu_item_dynamic_parameter_type , .intdigit=3},
item_adc1in2   =  {{&ADC_IN[1]   , puint16_type}, (cstring_t)"ADC1IN2",  menu_item_dynamic_parameter_type , .intdigit=4},
item_adc1in3   =  {{&ADC_IN[2]   , puint16_type}, (cstring_t)"ADC1IN3",  menu_item_dynamic_parameter_type , .intdigit=4},
item_adc1in4   =  {{&ADC_IN[3]   , puint16_type}, (cstring_t)"ADC1IN4",  menu_item_dynamic_parameter_type , .intdigit=4};

/*********************************************打包为一页*********************************************/
cpcMenu_item_struct_Typedef items_adc[] = 
{
    &item_intopage_peripheral_interface,&item_onoff_test, &item_adc1in1, &item_adc1in2, &item_adc1in3, &item_adc1in4,
};
Menu_page_struct_Typedef page_adc = {.items=items_adc,.function=NULL,.items_number=GET_ITEMS_NUMBER(items_adc),.titledigit=7,.gap=1,.numberdigit=5};

/***********************************************页接口***********************************************/
void Menu_intopage_adc(int8_t order, pMenu_struct_Typedef Menu)
{
    Menu->pages = &page_adc;
}
cMenu_item_struct_Typedef  item_intopage_adc = {{Menu_intopage_adc, function_type}, (cstring_t)"ADC", menu_item_into_function_type, .intdigit=0};



/************************************************************************DAC章************************************************************************/
/********************************************重映射外设项********************************************/
cMenu_item_struct_Typedef
item_dac1   =  {{&DAC_OUT1   , puint16_type}, (cstring_t)"DAC1",  menu_item_static_parameter_type , .intdigit=4},
item_dac2   =  {{&DAC_OUT2   , puint16_type}, (cstring_t)"DAC2",  menu_item_static_parameter_type , .intdigit=4};

/***********************************************页函数**********************************************/
void Menu_page_dac_function(void)
{
//    UPDATE_DACOUT();  //更新DAC输出
}

/*********************************************打包为一页*********************************************/
pcMenu_item_struct_Typedef items_dac[] = 
{
    &item_intopage_peripheral_interface,&item_float_test, &item_dac1,&item_dac2,
};
Menu_page_struct_Typedef page_dac = {.items=items_dac,.function=Menu_page_dac_function,.items_number=GET_ITEMS_NUMBER(items_dac),.titledigit=6,.gap=1,.numberdigit=8};

/***********************************************页接口***********************************************/
void Menu_intopage_dac(int8_t order, pMenu_struct_Typedef Menu)
{
    Menu->pages = &page_dac;
}
cMenu_item_struct_Typedef  item_intopage_dac  =  {{Menu_intopage_dac   , function_type}, (cstring_t)"DAC", menu_item_into_function_type, .intdigit=0};



/************************************************************************PWM章************************************************************************/
/********************************************重映射外设项********************************************/
//cMenu_item_struct_Typedef
//item_tim1frequency  =  {{&TIM1_PWM_structre.frequency    , puint32_type }, (cstring_t)"T1freq ",  menu_item_static_parameter_type , .intdigit=7},
//item_tim1duty1      =  {{&TIM1_PWM_structre.dutycycle1   , pfloat32_type}, (cstring_t)"T1Duty1",  menu_item_static_parameter_type , .intdigit=1},
//item_tim1duty2      =  {{&TIM1_PWM_structre.dutycycle2   , pfloat32_type}, (cstring_t)"T1Duty2",  menu_item_static_parameter_type , .intdigit=1},
//item_tim1duty3      =  {{&TIM1_PWM_structre.dutycycle3   , pfloat32_type}, (cstring_t)"T1Duty3",  menu_item_static_parameter_type , .intdigit=1},
//item_tim1duty4      =  {{&TIM1_PWM_structre.dutycycle4   , pfloat32_type}, (cstring_t)"T1Duty4",  menu_item_static_parameter_type , .intdigit=1},
//item_tim1deadtime_set   =  {{&TIM1_PWM_structre.dead_time_set    , puint8_type    }, (cstring_t)"T1Deadt",  menu_item_static_parameter_type  , .intdigit=3},
//item_tim1deadtime_real  =  {{&TIM1_PWM_structre.dead_time_real   , pfloat32_type  }, (cstring_t)"DTreal ",  menu_item_dynamic_parameter_type , .intdigit=6};

/***********************************************页函数**********************************************/
void Menu_page_pwm_function(void)
{
//    Advanced_TIM_PWM_Parameter_Set(pTIM1_PWM_structre);  //更新TIM1PWM输出
//    Dead_Time_Set(pTIM1_PWM_structre);      //更新死区长度
//    Dead_Time_Compute(pTIM1_PWM_structre);  //计算实际死区时间
}

/*********************************************打包为一页*********************************************/
pcMenu_item_struct_Typedef items_pwm[] = 
{
    &item_intopage_peripheral_interface,// &item_tim1frequency, &item_tim1duty1, &item_tim1duty2, &item_tim1duty3, &item_tim1duty4, &item_tim1deadtime_set, &item_tim1deadtime_real,
};
Menu_page_struct_Typedef page_pwm = {.items=items_pwm,.function=Menu_page_pwm_function,.items_number=GET_ITEMS_NUMBER(items_pwm),.titledigit=7,.gap=0,.numberdigit=9};

/***********************************************页接口***********************************************/
void Menu_intopage_pwm(int8_t order, pMenu_struct_Typedef Menu)
{
    Menu->pages = &page_pwm;
}
cMenu_item_struct_Typedef  item_intopage_pwm  =  {{Menu_intopage_pwm   , function_type}, (cstring_t)"TIM", menu_item_into_function_type, .intdigit=0};






/************************************************************************接口章************************************************************************/
//把接口放在最后就不用声明具体外设页了，只需要声明接口页
/***********************************************标题项***********************************************/
cMenu_item_struct_Typedef  item_title_peripheral_interface = {{Menu_init_display   , function_type}, (cstring_t)"Interface", menu_item_into_function_type, .intdigit=0};
/*********************************************打包为一页*********************************************/
pcMenu_item_struct_Typedef items_peripheral_interface[] = 
{
    &item_title_peripheral_interface, &item_intopage_adc, &item_intopage_dac, &item_intopage_pwm, //&item_intopage_project,
};
Menu_page_struct_Typedef page_peripheral_interface = {.items=items_peripheral_interface,.function=NULL,.items_number=GET_ITEMS_NUMBER(items_peripheral_interface),.titledigit=9,.gap=1,.numberdigit=0};
/***********************************************页接口***********************************************/
void Menu_intopage_peripheral_interface(int8_t order, pMenu_struct_Typedef Menu)
{
    Menu->pages = &page_peripheral_interface;
}
cMenu_item_struct_Typedef  item_intopage_peripheral_interface  =  {{Menu_intopage_peripheral_interface  , function_type}, (cstring_t)"Peripheral", menu_item_into_function_type, .intdigit=0};





























