#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"

int main(void)
{
	u16 pwmval=0; // ���ȵ�ֵ
	int dir=1; // direct,�൱��һ��flag,�������������Ǽ�С
	LED_Init(); // LED��ʼ��
	// ��һ��������arr,�ڶ���������psc
	TIM11_PWM_Init(500-1,84-1); // ע��,STM32F407��΢������Ĭ��ʱ��Ƶ����84MHz��,����72MHz
	// arr:500,psc:84, ��ʱ����ʱ��Ϊ��500*84/(84*1000000)=0.5ms
	// ����ÿ0.5ms ��ʱ���ļ������ͻ�����1,ֱ��arr����499ʱ,�ͻ���������´�0��ʼ����
	delay_init(168); // ��ʼ����ʱ����
	// �����������������Ϊ6s: 300*10ms*2=6s
	while(1)
	{
		delay_ms(10); // ��ʱ10ms
		if(dir)
			pwmval++;
		else
			pwmval--;
		if(pwmval>300) // �������300,�ͷ���
			dir=0;
		if(pwmval==0) // �������0,�ͷ���
			dir=1;
		
		TIM_SetCompare1(TIM14,pwmval); 
		// ��pwm����ΪTIM14��CCR,ARR��500,�ߵ�ƽռ��ʱ����ĳһʱ�����300/500=60%
		// ģ������ĵ�ѹҲΪоƬ�ڲ�����ѹ��60%
	}
}
 

