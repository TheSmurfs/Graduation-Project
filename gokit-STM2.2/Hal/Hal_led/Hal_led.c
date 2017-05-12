/**
********************************************************
*
* @file      Hal_led.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     ������ ֻΪ����Ӳ������
*            Gizwits Smart Cloud  for Smart Products
*            ����|��ֵ|����|����|��ȫ|����|����|��̬
*            www.gizwits.com
*
*********************************************************/
#include "Hal_led/Hal_led.h"

/***********************************************
��������:LED_GPIO_Init
��		��:��ʼ��LED1��2��3��4�
��		��:��
�� �� ֵ:��
***********************************************/
void LED_GPIO_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(GPIO_LED1_CLK | GPIO_LED2_CLK | GPIO_LED3_CLK | GPIO_LED4_CLK, ENABLE);//ʹ��LED

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//����IO���ٶ�
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//����Ϊͨ���������ģʽ
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//��д��һ��
	
    GPIO_InitStructure.GPIO_Pin = GPIO_LED1_PIN;							//ѡ��LED1
    GPIO_Init(GPIO_LED1_PORT, &GPIO_InitStructure);						//��ʼ��LED1

    GPIO_InitStructure.GPIO_Pin = GPIO_LED2_PIN;							//ѡ��LED2
    GPIO_Init(GPIO_LED2_PORT, &GPIO_InitStructure);						//��ʼ��LED2

    GPIO_InitStructure.GPIO_Pin = GPIO_LED3_PIN;							//ѡ��LED3
    GPIO_Init(GPIO_LED3_PORT, &GPIO_InitStructure);						//��ʼ��LED3

    GPIO_InitStructure.GPIO_Pin = GPIO_LED4_PIN;							//ѡ��LED4
    GPIO_Init(GPIO_LED4_PORT, &GPIO_InitStructure);						//��ʼ��LED4

    LED_OFF(LED1);																						//�ر�LED1
    LED_OFF(LED2);																						//�ر�LED2
    LED_OFF(LED3);																						//�ر�LED3
    LED_OFF(LED4);																						//�ر�LED4
}
/***********************************************
��������:LED_ON
��		��:����LED
��		��:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
�� �� ֵ:��
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
��������:LED_OFF
��		��:Ϩ��LED
��		��:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
�� �� ֵ:��
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
