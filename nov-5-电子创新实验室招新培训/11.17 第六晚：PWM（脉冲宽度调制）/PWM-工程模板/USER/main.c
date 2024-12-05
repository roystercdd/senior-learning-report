#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�ٿ��ٴ� STM32F407������ ʵ��0
//ʵ�� -�⺯���汾
//����֧�֣�
//��˾��ҳ��http:www.r8c.com  
//�ٿ��ٴ����������Ƽ���չ���޹�˾
//���ߣ�810 
////////////////////////////////////////////////////////////////////////////////// 	 

int main(void)
{
	u16 pwmval; // ������ݵ�����
	int dir=1; // dir:1 ��������(�Ӱ�����), dir:0 ��������(��������)
	
	LED_Init(); // LED��ʼ��
	// Tout=(arr+1)��(psc+1)/TCLK (84MHz) �� 84000 = 84 1000
	// 
	TIM14_PWM_Init(500-1,168-1); // 500��168/84��10^6=10-1s=100ms
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
 

