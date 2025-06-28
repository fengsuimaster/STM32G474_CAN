#ifndef __SYSTEM_H
#define __SYSTEM_H

//把main.c中包含的.h文件包含到这里
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include <stdio.h>
//#include "usart.h"
#include "fdcan.h"
//Expand
#include "CAN_Expand.h"
//SM
#include "Menu_Page/Menu_peripheral.h"


//系统函数，在main中调用
void System_Init(void);
void System_Run(void);

#endif  /*__SYSTEM_H*/
