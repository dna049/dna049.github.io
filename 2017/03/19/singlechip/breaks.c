#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit k3=P3^2;  	//定义按键K3
sbit led=P2^0;	//定义P20口是led

void Int0Init(){	//设置INT0
	IT0=1;//跳变沿出发方式（下降沿）
	EX0=1;//打开INT0的中断允许。	
	EA=1;//打开总中断	
}
void main(){	
	Int0Init();  //	设置外部中断0
	while(1);		
}
void Int0()	interrupt 0	{	//外部中断0的中断函数
	delay(1000);	 //延时消抖
	if(k3==0){
		led=~led;
	}
}

// 相应的所有 0改1用K4得到外部中断1 void Int1() interrupt 2