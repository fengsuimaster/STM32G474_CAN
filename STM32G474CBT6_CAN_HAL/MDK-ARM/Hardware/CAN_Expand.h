#ifndef __CAN_EXPAND_H
#define __CAN_EXPAND_H

#define FDCAN_EN 1

#if FDCAN_EN
#include "fdcan.h"
#include "Stdint_Expand/stdint_Expand.h"



extern FDCAN_TxHeaderTypeDef TxHeader;
extern FDCAN_RxHeaderTypeDef RxHeader;


void FDCAN_Filter_Init(FDCAN_HandleTypeDef *hfdcan);
void FDCAN_Transmit(FDCAN_HandleTypeDef *hfdcan, cpuint8_t pdat);
void FDCAN_Receive(FDCAN_HandleTypeDef *hfdcan, puint8_t pdat);





#endif /* FDCAN_EN */
#endif /* __CAN_EXPAND_H */
