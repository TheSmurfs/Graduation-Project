/**
********************************************************
*
* @file      Hal_led.c
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
#include "Hal_led/Hal_led.h"

/***********************************************
函数名称:LED_GPIO_Init
功		能:初始化LED1，2，3，4�
参		数:无
返 回 值:无
***********************************************/
void LED_GPIO_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(GPIO_LED1_CLK | GPIO_LED2_CLK | GPIO_LED3_CLK | GPIO_LED4_CLK, ENABLE);//使能LED

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//设置IO口速度
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//设置为通用推挽输出模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//多写了一条
	
    GPIO_InitStructure.GPIO_Pin = GPIO_LED1_PIN;							//选择LED1
    GPIO_Init(GPIO_LED1_PORT, &GPIO_InitStructure);						//初始化LED1

    GPIO_InitStructure.GPIO_Pin = GPIO_LED2_PIN;							//选择LED2
    GPIO_Init(GPIO_LED2_PORT, &GPIO_InitStructure);						//初始化LED2

    GPIO_InitStructure.GPIO_Pin = GPIO_LED3_PIN;							//选择LED3
    GPIO_Init(GPIO_LED3_PORT, &GPIO_InitStructure);						//初始化LED3

    GPIO_InitStructure.GPIO_Pin = GPIO_LED4_PIN;							//选择LED4
    GPIO_Init(GPIO_LED4_PORT, &GPIO_InitStructure);						//初始化LED4

    LED_OFF(LED1);																						//关闭LED1
    LED_OFF(LED2);																						//关闭LED2
    LED_OFF(LED3);																						//关闭LED3
    LED_OFF(LED4);																						//关闭LED4
}
/***********************************************
函数名称:LED_ON
功		能:点亮LED
参		数:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
返 回 值:无
***********************************************/
void LED_ON(uint8_t LEDNUM){
    switch (LEDNUM){
			
    case LED1:
        GPIO_SetBits(GPIO_LED1_PORT,GPIO_LED1_PIN);
        break;
		
    case LED2:
        GPIO_SetBits(GPIO_LED2_PORT,GPIO_LED2_PIN);
        break;
		
    case LED3:
        GPIO_SetBits(GPIO_LED3_PORT,GPIO_LED3_PIN);
        break;
		
    case LED4:
        GPIO_SetBits(GPIO_LED4_PORT,GPIO_LED4_PIN);
        break;
		
    default:
        break;
    }
}
/***********************************************
函数名称:LED_OFF
功		能:熄灭LED
参		数:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
返 回 值:无
***********************************************/
void LED_OFF(uint8_t LEDNUM){
    switch (LEDNUM){
			
    case LED1:
        GPIO_ResetBits(GPIO_LED1_PORT,GPIO_LED1_PIN);
        break;
		
    case LED2:
        GPIO_ResetBits(GPIO_LED2_PORT,GPIO_LED2_PIN);
        break;
		
    case LED3:
        GPIO_ResetBits(GPIO_LED3_PORT,GPIO_LED3_PIN);
        break;
		
    case LED4:
        GPIO_ResetBits(GPIO_LED4_PORT,GPIO_LED4_PIN);
        break;
		
    default:
        break;
    }
}
