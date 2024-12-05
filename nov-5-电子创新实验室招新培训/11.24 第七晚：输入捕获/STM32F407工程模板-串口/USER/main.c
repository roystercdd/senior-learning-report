#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h" 

extern u8  TIM5CH1_CAPTURE_STA;		// ���벶��״̬		    				
extern u32	TIM5CH1_CAPTURE_VAL;	// ���벶��ֵ  
	
int main(void)
{ 
	long temp=0;  
	delay_init(168);  // ��ʼ����ʱ����
	uart_init(115200); // ��ʼ�����ڲ�����Ϊ115200
	// arr=500, psc=84, ��ʱ������Tout=arr��psc/Tclk=500*84/84��10^6=5��10-4s , Fpwm=1/Tout=2000Hz=2KHz
	// Ҳ�����������, Tclk=84MHz, ������Ƶ�����Ϊ1MHz, ÿ����һ�λ���1/1MHz=10-6s(1us,�ȽϾ�ȷ����󲿷�����), ����500��Ϊ5��10-4s
 	TIM14_PWM_Init(500-1,84-1);
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); // ��1Mhz��Ƶ�ʼ���, arr=0XFFFFFFFF ��֤�����ϳ�ʱ��������, �����psc��Ӱ��, ���벶���Ƶ�ʺ�PWM��Ƶ�ʲ����
  while(1)
	{
 		delay_ms(10);
		TIM_SetCompare1(TIM14,TIM_GetCapture1(TIM14)+1); // ÿ��ȥ���CNTֵ, CNTֵ���, CNT���ߵ�ƽ����ʱ�����
		// ÿ��CNT����300���������Ϊ0, ֮ǰ��PWM��ʱ��300���Զ���װ��Ϊ0, �����ʵ��������װ��ֵ���õ�̫����, �����ֶ���0
		if(TIM_GetCapture1(TIM14)==300)TIM_SetCompare1(TIM14,0);			 
 		if(TIM5CH1_CAPTURE_STA&0X80) // �ɹ����һ�β���
		{
			temp=TIM5CH1_CAPTURE_STA&0X3F; // ��¼��������ж�ʱ�����������(��6λ), ��������˶��ٴ�
			temp*=0XFFFFFFFF; // ÿ���������������Ҫ����2^32�μ���
			temp+=TIM5CH1_CAPTURE_VAL; // �������һ�ֲ���ʱ��ʱ����ֵ
			printf("HIGH:%ld us\r\n",temp); // ��ӡ�ܵĸߵ�ƽʱ�䣬�����񵽵Ķ�ʱ����ֵ
			TIM5CH1_CAPTURE_STA=0;			     // ������һ�β���
		}
	}
}
