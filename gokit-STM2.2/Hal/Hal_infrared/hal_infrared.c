/**
********************************************************
*
* @file      Hal_infrared.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     机智云 只为智能硬件而生
*            Gizwits Smart Cloud  for Smart Products
*            链接|增值|开放|中立|安全|自有|自由|生态
*            www.gizwits.com
*
*********************************************************/

#include <stm32f10x.h>
#include "Hal_infrared/Hal_infrared.h"
/***********************************************
函数名称:IR_Init
功		能:红外初始化
参		数:无
返 回 值:无
***********************************************/
void IR_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(Infrared_GPIO_CLK,ENABLE);					//使能PORTA,PORTE时钟
    GPIO_InitStructure.GPIO_Pin  = Infrared_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 						//设置成上拉输入
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_Init(Infrared_GPIO_PORT, &GPIO_InitStructure);
}
/***********************************************
函数名称:IR_Handle
功		能:红外对管状态
参		数:无
返 回 值:状态
***********************************************/
bool IR_Handle(void){
    if(GPIO_ReadInputDataBit(Infrared_GPIO_PORT, Infrared_GPIO_PIN)){
        return 0;
    }
    else{
        return 1;
    }
}
