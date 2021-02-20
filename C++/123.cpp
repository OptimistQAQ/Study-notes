#include<reg52.h>

#define uint unsigned int

#define uchar unsigned char

sbit dula=P2^6;

sbit wela=P2^7;

sbit led1=P1^0;

sbit led2=P1^2;

sbit led3=P1^4;

sbit key1=P3^4;

sbit key2=P3^5;

sbit beep=P2^3;

uchar shi=2,ge=5,num,a,k;

uchar aa,flag,i;

uchar code table[]={0x3f,0x06,0x5b,0x4f,

			        0x66,0x6d,0x7d,0x07,

			        0x7f,0x6f,0x77,0x7c,

			        0x39,0x5e,0x79,0x71,};

void display();

void display1();

void display2();

void display3();

void delayms(uint x);

void main()

{

  TMOD=0x21;

  TH1=0xfd;

  TL1=0xfd;

  TR1=1;

  SM0=0;

  SM1=1;

  REN=1;

  ES=1;

  TH0=(65535-50000)/256;

  TL0=(65535-50000)%256;

  EA=1;

  ET0=1;

  TR0=1;

  led1=0;

  while(1)

  {

	if(flag==1)

	{

	    ES=0;

		shi=5;ge=9;

		flag=0;

	}

	TI=0;

	ES=1;

	if(flag==2)

	{

	    ES=0;

		shi=0;ge=6;

		flag=0;

	}

	TI=0;

	ES=1; 

	if(flag==3)

	{

	    ES=0;

		shi=5;ge=9;

		flag=3;

	}

	TI=0;

	ES=1; 

	display();

	if(key1==0){shi=5;ge=9;}

  }

}
