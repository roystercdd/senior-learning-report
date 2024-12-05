#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h" 

extern u8  TIM5CH1_CAPTURE_STA;		// 输入捕获状态		    				
extern u32	TIM5CH1_CAPTURE_VAL;	// 输入捕获值  
	
int main(void)
{ 
	long temp=0;  
	delay_init(168);  // 初始化延时函数
	uart_init(115200); // 初始化串口波特率为115200
	// arr=500, psc=84, 定时器周期Tout=arr×psc/Tclk=500*84/84×10^6=5×10-4s , Fpwm=1/Tout=2000Hz=2KHz
	// 也可以这样理解, Tclk=84MHz, 经过分频器后变为1MHz, 每计数一次花费1/1MHz=10-6s(1us,比较精确满足大部分任务), 计数500次为5×10-4s
 	TIM14_PWM_Init(500-1,84-1);
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); // 以1Mhz的频率计数, arr=0XFFFFFFFF 保证测量较长时间而不溢出, 这里的psc不影响, 输入捕获的频率和PWM波频率不相关
  while(1)
	{
 		delay_ms(10);
		TIM_SetCompare1(TIM14,TIM_GetCapture1(TIM14)+1); // 每次去提高CNT值, CNT值变大, CNT变大高电平持续时间变少
		// 每当CNT增大到300就让其调整为0, 之前讲PWM的时候到300会自动重装载为0, 但这次实验我们重装载值设置得太大了, 于是手动置0
		if(TIM_GetCapture1(TIM14)==300)TIM_SetCompare1(TIM14,0);			 
 		if(TIM5CH1_CAPTURE_STA&0X80) // 成功完成一次捕获
		{
			temp=TIM5CH1_CAPTURE_STA&0X3F; // 记录捕获过程中定时器的溢出次数(低6位), 计算溢出了多少次
			temp*=0XFFFFFFFF; // 每次溢出，计数器都要经过2^32次计数
			temp+=TIM5CH1_CAPTURE_VAL; // 加上最后一轮捕获时定时器的值
			printf("HIGH:%ld us\r\n",temp); // 打印总的高电平时间，即捕获到的定时器的值
			TIM5CH1_CAPTURE_STA=0;			     // 开启下一次捕获
		}
	}
}
