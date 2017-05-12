#include<reg51.h>
#include<stdio.h>
//#define uchar unsigned char
//#define uint unsigned int
unsigned int t;
 //**传感器***/
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
sbit IN5 = P1^4;
sbit IN6 = P1^5;
sbit IN7 = P1^6;
sbit IN8 = P1^7;
sbit F1 = P0^0;
sbit F2 = P0^1;
sbit F3 = P0^2;
sbit X1 = P2^3;
sbit X2 = P2^4;
sbit X3 = P2^5;
sbit X4 = P2^6;
sbit Q1 = P2^0;
sbit Q2 = P0^7;
sbit BEEP = P2^2;
sbit XJ = P3^1;

//******************直行******************//
 void qianjin()
 {
   	  IN1=1;
      IN2=0;
      IN3=1;
      IN4=0;
	  IN5=1;
      IN6=0;
      IN7=1;
      IN8=0;

}
 //***************左转函数1***************//
 void turn_left()
 {
	  IN1=1;
      IN2=0;
      IN3=1;
      IN4=0;
	  IN5=0;
      IN6=0;
      IN7=0;
      IN8=1;  

 }

//  //***************右转函数***************//
 void turn_right()
 {
 	  IN1=0;
      IN2=1;
      IN3=0;
      IN4=1;
	  IN5=0;
      IN6=0;
      IN7=1;
      IN8=0;

 }
////***************t停车***************//
 void turn_stop()
 {
 	  IN1=0;
      IN2=0;
      IN3=0;
      IN4=0;
	  IN5=0;
      IN6=0;
      IN7=0;
      IN8=0;  

 }
 ////***************后退***************//
 void turn_down()
 {
 	  IN1=0;
      IN2=1;
      IN3=0;
      IN4=1;
	  IN5=0;
      IN6=1;
      IN7=0;
      IN8=1;  

 }
 //****************主程序****************//
 void main()
{

P1 =0x00;
P0 =0x00;
BEEP=0;
P2=0x78;


	while(1)
{ 		if(Q2==0)
			{BEEP=1;}
  		else BEEP =0;
		if(XJ == 0) 
    {
		if((F1 == 0)&&(F2 == 0)&&(F3 == 0))
		{
		turn_stop();

		}
    	if((F1 == 1)&&(F2 == 0)&&(F3 == 0))
		{
		qianjin();	

		}
		if((F1 == 0)&&(F2 == 1)&&(F3 == 0))
		{
		turn_left();

		}
		if((F1 == 1)&&(F2 == 1)&&(F3 == 0))
		{
		turn_right();

		}
		if((F1 == 0)&&(F2 == 0)&&(F3 == 1))
		{
		turn_down();

		}
	}
	 	if(XJ == 1)
	{	
//	 		qianjin();
		if((X2 == 1)&&(X3 == 1)||(X1 == 1)&&(X4 == 1))
		{
		qianjin();

		}
    	if((X2 == 1)&&(X3 == 0))
		{
		turn_left();	

		}
		if((X2 == 0)&&(X3 == 1))
		{
		turn_right();	

		}

	}

	

	
 }

}