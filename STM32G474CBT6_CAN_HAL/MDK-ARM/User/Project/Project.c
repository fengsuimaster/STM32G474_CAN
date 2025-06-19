//#include "Project.h"


//uint8_t sin_flag = 0;
//uint16_t sin_f = 0;
//uint16_t sin_count = 0;
//float tem = 0;
//float m = 0.5;
//float p = 50;
//uint8_t en = 0;
//uint8_t Hmod = 0;
//float vout = 0;
//uint8_t beep_flag = 0;
//uint8_t ven = 1;
//uint8_t tem_en = 0;
//uint8_t H_state = 0;

//POWER_MEAS_SINE_ANALYZER Power_structre;
//pPOWER_MEAS_SINE_ANALYZER pPower = &Power_structre;

///************************************************************************Project章************************************************************************/
///********************************************重映射外设项********************************************/
//cMenu_item_struct_Typedef
//item_tem     =  {{&tem   , pfloat32_type}, (cstring_t)"tempera",  menu_item_dynamic_parameter_type , .intdigit=2},
//item_m     =  {{&m   , pfloat32_type},     (cstring_t)"modulat",  menu_item_static_parameter_type , .intdigit=1},
//item_p     =  {{&p   , pfloat32_type},  (cstring_t)"basicf ",  menu_item_static_parameter_type , .intdigit=5},
//item_en   =  {{&en   , puint8_type},       (cstring_t)"enable ",  menu_item_onoff_type , .intdigit=3},
//item_vout   =  {{&vout , pfloat32_type},   (cstring_t)"Vout   ",  menu_item_static_parameter_type , .intdigit=3},
//item_beep   =  {{&beep_flag , puint8_type},(cstring_t)"Warring",  menu_item_onoff_type , .intdigit=3},
//item_ven   =  {{&ven , puint8_type},       (cstring_t)"ven    ",  menu_item_static_parameter_type , .intdigit=5},
//item_tem_en   =  {{&tem_en , puint8_type}, (cstring_t)"tem_en ",  menu_item_onoff_type , .intdigit=3},
//item_tem_hstate   =  {{&H_state , puint8_type}, (cstring_t)"Hup    ",  menu_item_onoff_type , .intdigit=3},
//item_mod  =  {{&Hmod   , puint8_type},     (cstring_t)"mod    ",  menu_item_onoff_type , .intdigit=3};

///***********************************************页函数**********************************************/
//void Menu_page_project_function(void)
//{

//}

///*********************************************打包为一页*********************************************/
//pcMenu_item_struct_Typedef items_project[] = 
//{
//    &item_intopage_peripheral_interface,
//    &item_beep,
//    &item_ven,
//    &item_m,     
//    &item_vout,
//    &item_p,
//    &item_tem_en,
//    &item_tem,
//    &item_mod,
//    &item_tem_hstate,
//    &item_en,
//};
//Menu_page_struct_Typedef page_project = {.items=items_project,.function=Menu_page_project_function,.items_number=GET_ITEMS_NUMBER(items_project),.titledigit=7,.gap=0,.numberdigit=7};

///***********************************************页接口***********************************************/
//void Menu_intopage_project(int8_t order, pMenu_struct_Typedef Menu)
//{
//    Menu->pages = &page_project;
//}
//cMenu_item_struct_Typedef  item_intopage_project  =  {{Menu_intopage_project   , function_type}, (cstring_t)"Project", menu_item_into_function_type, .intdigit=0};

