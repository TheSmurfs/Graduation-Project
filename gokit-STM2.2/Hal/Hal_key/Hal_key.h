#ifndef _HAL_KEY_H
#define _HAL_KEY_H

#include <stdio.h>
#include <stm32f10x.h>

#define GPIO_KEY1_CLK    RCC_APB2Periph_GPIOB
#define GPIO_KEY1_PORT   GPIOB
#define GPIO_KEY1_PIN    GPIO_Pin_10

#define GPIO_KEY2_CLK    RCC_APB2Periph_GPIOA
#define GPIO_KEY2_PORT   GPIOA
#define GPIO_KEY2_PIN    GPIO_Pin_8

#define GPIO_KEY3_CLK    RCC_APB2Periph_GPIOC
#define GPIO_KEY3_PORT   GPIOC
#define GPIO_KEY3_PIN    GPIO_Pin_13



#define PRESS_KEY1   0x01
#define PRESS_KEY2   0x02
#define PRESS_KEY3   0x04

#define NO_KEY       0x00
#define KEY_DOWN     0x10  	
#define KEY_UP    	 0x20   
#define KEY_LIAN     0x40   
#define KEY_LONG     0x80



#define KEY_CLICK_DELAY    10

#define KEY1_Long_Action      0x01         
#define KEY2_Long_Action      0x02

void KEY_GPIO_Init(void);												//按键初始化
uint8_t Read_KEY_State(void);										//没有函数体
uint8_t Get_Key(void);													//获得键值
void TIM3_Int_Init(u16 arr,u16 psc);						//定时器3初始化
void KEY_Handle(void);													//按键功能配置（在mian中有点蒙圈）
void KEY_LongHandle(uint8_t KeyAction);					//没有函数体
uint8_t ReadKeyValue(void);											//不明白><	

#endif /*_HAL_KEY_H*/

