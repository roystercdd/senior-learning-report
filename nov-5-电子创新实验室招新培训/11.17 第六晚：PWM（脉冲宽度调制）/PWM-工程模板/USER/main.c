#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//百科荣创 STM32F407开发板 实验0
//实验 -库函数版本
//技术支持：
//公司主页：http:www.r8c.com  
//百科荣创（北京）科技发展有限公司
//作者：810 
////////////////////////////////////////////////////////////////////////////////// 	 

int main(void)
{
	u16 pwmval; // 代表灯泡的亮度
	int dir=1; // dir:1 灯泡亮度(从暗到亮), dir:0 灯泡亮度(从亮到暗)
	
	LED_Init(); // LED初始化
	// Tout=(arr+1)×(psc+1)/TCLK (84MHz) → 84000 = 84 1000
	// 
	TIM14_PWM_Init(500-1,168-1); // 500×168/84×10^6=10-1s=100ms
	delay_init(168);
	
	while(1)
	{
		delay_ms(10);
		
		if(dir==1) pwmval++;
		else pwmval--;
		
		if(pwmval>300) dir=0;
		if(pwmval==0) dir=1;
		
		TIM_SetCompare1(TIM14,pwmval);
	}
}
 

