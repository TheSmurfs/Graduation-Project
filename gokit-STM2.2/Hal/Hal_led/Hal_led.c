/**
********************************************************
*
* @file      Hal_led.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     »úÖÇÔÆ Ö»ÎªÖÇÄÜÓ²¼þ¶øÉú
*            Gizwits Smart Cloud  for Smart Products
*            Á´½Ó|ÔöÖµ|¿ª·Å|ÖÐÁ¢|°²È«|×ÔÓÐ|×ÔÓÉ|ÉúÌ¬
*            www.gizwits.com
*
*********************************************************/
#include "Hal_led/Hal_led.h"

/***********************************************
º¯ÊýÃû³Æ:LED_GPIO_Init
¹¦		ÄÜ:³õÊ¼»¯LED1£¬2£¬3£¬4£
²Î		Êý:ÎÞ
·µ »Ø Öµ:ÎÞ
***********************************************/
void LED_GPIO_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(GPIO_LED1_CLK | GPIO_LED2_CLK | GPIO_LED3_CLK | GPIO_LED4_CLK, ENABLE);//Ê¹ÄÜLED

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//ÉèÖÃIO¿ÚËÙ¶È
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//ÉèÖÃÎªÍ¨ÓÃÍÆÍìÊä³öÄ£Ê½
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//¶àÐ´ÁËÒ»Ìõ
	
    GPIO_InitStructure.GPIO_Pin = GPIO_LED1_PIN;							//Ñ¡ÔñLED1
    GPIO_Init(GPIO_LED1_PORT, &GPIO_InitStructure);						//³õÊ¼»¯LED1

    GPIO_InitStructure.GPIO_Pin = GPIO_LED2_PIN;							//Ñ¡ÔñLED2
    GPIO_Init(GPIO_LED2_PORT, &GPIO_InitStructure);						//³õÊ¼»¯LED2

    GPIO_InitStructure.GPIO_Pin = GPIO_LED3_PIN;							//Ñ¡ÔñLED3
    GPIO_Init(GPIO_LED3_PORT, &GPIO_InitStructure);						//³õÊ¼»¯LED3

    GPIO_InitStructure.GPIO_Pin = GPIO_LED4_PIN;							//Ñ¡ÔñLED4
    GPIO_Init(GPIO_LED4_PORT, &GPIO_InitStructure);						//³õÊ¼»¯LED4

    LED_OFF(LED1);																						//¹Ø±ÕLED1
    LED_OFF(LED2);																						//¹Ø±ÕLED2
    LED_OFF(LED3);																						//¹Ø±ÕLED3
    LED_OFF(LED4);																						//¹Ø±ÕLED4
}
/***********************************************
º¯ÊýÃû³Æ:LED_ON
¹¦		ÄÜ:µãÁÁLED
²Î		Êý:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
·µ »Ø Öµ:ÎÞ
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
º¯ÊýÃû³Æ:LED_OFF
¹¦		ÄÜ:Ï¨ÃðLED
²Î		Êý:uint8_t LEDNUM 
				LED1             0X01
				LED2             0X02
				LED3             0X04
				LED4             0X08
·µ »Ø Öµ:ÎÞ
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
