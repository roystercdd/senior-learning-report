#include "pwm.h"
#include "led.h"

// TIM14,PWM�����ʼ��
// arr���Զ���װֵ
// psc��ʱ��Ԥ��Ƶ��
void TIM14_PWM_Init(u16 arr,u16 psc) {		 					 
	GPIO_InitTypeDef GPIO_InitStructure; // GPIO�ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; // ��ʱ�����������ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure; // ����ȽϽṹ��
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE); // TIM14ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); // ʹ��GPIOFʱ��	
	
	// ��PF9���Ÿ���Ϊ��ʱ��14�ĸ��ù�������,ʹ���ܹ���ΪPWM���
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14); // GPIOF9����Ϊ��ʱ��14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // GPIOF9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; // ���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // �ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; // ����
	GPIO_Init(GPIOF,&GPIO_InitStructure); // ��ʼ��PF9
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc; // ��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; // ���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr; // �Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; // ���ó�1��Ƶ,��:����Ƶ 
	
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseStructure); // ��ʼ����ʱ��14
	
	// ��ʼ��TIM14 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	// ģʽ1��������˵��, ��CNT<CCRʱ,Ϊ�ߵ�ƽ; ��CNT>=CCRʱ,Ϊ�͵�ƽ
	// ģʽ2,��CNT>=CCR,Ϊ��Ч��ƽ; ��CNT<CCR,Ϊ��Ч��ƽ
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // �Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; // �������:�ߵ�ƽ��Ϊ��Ч��ƽ
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);  // ��ʼ��TIM14 Channell PWM

	TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable); // ʹ��TIM14������ȽϼĴ���
 
	TIM_ARRPreloadConfig(TIM14,ENABLE); // ʹ��TIM14���Զ���װ�ؼĴ���
	
	TIM_Cmd(TIM14, ENABLE);  // ʹ��TIM14									  
}  


