/**
********************************************************
*
* @file      Hal_temp_hum.c
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
#include "Hal_temp_hum/Hal_temp_hum.h"

/***********************************************
函数名称:DHT11_Rst
功		能:Reset DHT11
参		数:无
返 回 值:无
***********************************************/
void DHT11_Rst(void){
    DHT11_IO_OUT(); 											//SET OUTPUT
    DHT11_DQ_OUT=0; 											//GPIOA.0=0
    Delay_ms(20);    											//Pull down Least 18ms
    DHT11_DQ_OUT=1; 											//GPIOA.0=1
    Delay_us(30);     										//Pull up 20~40us
}
/***********************************************
函数名称:DHT11_Check
功		能:检测
参		数:无
返 回 值:状态
***********************************************/
u8 DHT11_Check(void){
    u8 retry=0;
    DHT11_IO_IN();												//SET INPUT
    while (DHT11_DQ_IN&&retry<100){				//DHT11 Pull down 40~80us
        retry++;
        Delay_us(1);
    }

    if(retry>=100)
        return 1;
    else
        retry=0;

    while (!DHT11_DQ_IN&&retry<100){		  //DHT11 Pull up 40~80us
        retry++;
        Delay_us(1);
    }

    if(retry>=100)
        return 1;														//chack error

    return 0;
}
/***********************************************
函数名称:DHT11_Read_Bit
功		能:读DHT11一个数据位
参		数:无
返 回 值:一个数据位
***********************************************/
u8 DHT11_Read_Bit(void){
    u8 retry=0;
    while(DHT11_DQ_IN&&retry<100){				//wait become Low level
        retry++;
        Delay_us(1);
    }

    retry=0;
    while(!DHT11_DQ_IN&&retry<100){				//wait become High level
        retry++;
        Delay_us(1);
    }

    Delay_us(40);//wait 40us

    if(DHT11_DQ_IN)
        return 1;
    else
        return 0;
}
/***********************************************
函数名称:DHT11_Read_Byte
功		能:读DHT11一个字节
参		数:无
返 回 值:一个字节数据
***********************************************/
u8 DHT11_Read_Byte(void){
    u8 i,dat;
    dat=0;
    for (i=0; i<8; i++){
        dat<<=1;
        dat|=DHT11_Read_Bit();
    }

    return dat;
}
/***********************************************
函数名称:DHT11_Read_Data
功		能:读DHT11温湿度
参		数:u8 *temperature,u8 *humidity
返 回 值:数据读取是否成功
***********************************************/
u8 DHT11_Read_Data(u8 *temperature,u8 *humidity){
    u8 buf[5];
    u8 i;
    DHT11_Rst();
    if(DHT11_Check()==0){
        for(i=0; i<5; i++){
            buf[i]=DHT11_Read_Byte();
        }
        if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4]){
            *humidity=buf[0];
            *temperature=buf[2];
        }
    }
    else
        return 1;

    return 0;
}
/***********************************************
函数名称:DHT11_Init
功		能:DHT11初始化
参		数:无
返 回 值:初始化是否成功
***********************************************/
u8 DHT11_Init(void){
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			//使能DHT11时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;								  //选择DHT11
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					//通用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					//IO口速度
    GPIO_Init(GPIOB, &GPIO_InitStructure);										//初始化IO口
    GPIO_SetBits(GPIOB,GPIO_Pin_3);

    DHT11_Rst();
    return DHT11_Check();
}
