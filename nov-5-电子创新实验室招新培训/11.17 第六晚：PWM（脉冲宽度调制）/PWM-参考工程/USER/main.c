#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"

int main(void)
{
	u16 pwmval=0; // 亮度的值
	int dir=1; // direct,相当于一个flag,控制亮度增大还是减小
	LED_Init(); // LED初始化
	// 第一个参数是arr,第二个参数是psc
	TIM11_PWM_Init(500-1,84-1); // 注意,STM32F407的微控制器默认时钟频率是84MHz哈,不是72MHz
	// arr:500,psc:84, 定时器的时间为：500*84/(84*1000000)=0.5ms
	// 所以每0.5ms 定时器的计数器就会增加1,直到arr增大到499时,就会溢出并重新从0开始计数
	delay_init(168); // 初始化延时函数
	// 从亮→灭→亮的周期为6s: 300*10ms*2=6s
	while(1)
	{
		delay_ms(10); // 延时10ms
		if(dir)
			pwmval++;
		else
			pwmval--;
		if(pwmval>300) // 如果超过300,就反向
			dir=0;
		if(pwmval==0) // 如果减到0,就反向
			dir=1;
		
		TIM_SetCompare1(TIM14,pwmval); 
		// 把pwm设置为TIM14的CCR,ARR是500,高电平占的时间在某一时刻最长是300/500=60%
		// 模拟输出的电压也为芯片内部最大电压乘60%
	}
}
 

