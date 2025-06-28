#include "CAN_Expand.h"



#if FDCAN_EN

FDCAN_TxHeaderTypeDef TxHeader;
FDCAN_RxHeaderTypeDef RxHeader;

void FDCAN_Filter_Init(FDCAN_HandleTypeDef *hfdcan)
{
    FDCAN_FilterTypeDef sFilterConfig;
    
    sFilterConfig.IdType       = FDCAN_STANDARD_ID       ;  //目标为标准或拓展ID
    sFilterConfig.FilterIndex  = 0                       ;  //标准ID为0-27，拓展ID为0-7
    sFilterConfig.FilterType   = FDCAN_FILTER_DUAL       ;  //过滤模式
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0 ;  //过滤器工作模式
    sFilterConfig.FilterID1    = 0                       ;  //标准ID范围为0-0x7FF(11)，拓展ID为0-0x1FFFFFFF(29)
    sFilterConfig.FilterID2    = 0                       ;  //
    
    HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig);
    
    TxHeader.Identifier           = 0                  ;  //标准ID范围为0-0x7FF(11)，拓展ID为0-0x1FFFFFFF(29)
    TxHeader.IdType               = FDCAN_STANDARD_ID  ;
    TxHeader.TxFrameType          = FDCAN_DATA_FRAME   ;  //数据帧或者遥控帧
    TxHeader.DataLength           = FDCAN_DLC_BYTES_8   ;  //数据长度DLC
//    TxHeader.ErrorStateIndicator  = ;  //发送节点的错误状态，主动或被动
    TxHeader.BitRateSwitch        = FDCAN_BRS_OFF      ;  //FDCAN的波特率切换使能
    TxHeader.FDFormat             = FDCAN_CLASSIC_CAN  ;  //FDCAN模式使能
    TxHeader.TxEventFifoControl   = FDCAN_NO_TX_EVENTS ;  //是否存储发送事件
    TxHeader.MessageMarker        = 0                  ;  //消息事件表示
}




void FDCAN_Transmit(FDCAN_HandleTypeDef *hfdcan, cpuint8_t pdat)
{
    HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &TxHeader, pdat);
    
    
}

void FDCAN_Receive(FDCAN_HandleTypeDef *hfdcan, puint8_t pdat)
{
    if (HAL_FDCAN_GetRxFifoFillLevel(hfdcan, FDCAN_RX_FIFO0))  //接收队列不为空
    {
        HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, pdat);
    }
}





#endif /* FDCAN_EN */

