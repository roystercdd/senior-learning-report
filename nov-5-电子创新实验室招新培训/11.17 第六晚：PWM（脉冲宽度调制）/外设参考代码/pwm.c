#include "pwm.h"
#include "led.h"

// TIM14,PWM输出初始化
// arr：自动重装值
// psc：时钟预分频数
void TIM14_PWM_Init(u16 arr,u16 psc) {		 					 
	GPIO_InitTypeDef GPIO_InitStructure; // GPIO结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; // 定时器基础参数结构体
	TIM_OCInitTypeDef TIM_OCInitStructure; // 输出比较结构体
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE); // TIM14时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); // 使能GPIOF时钟	
	
	// 将PF9引脚复用为定时器14的复用功能引脚,使其能够作为PWM输出
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14); // GPIOF9复用为定时器14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // GPIOF9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; // 复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // 速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // 推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; // 上拉
	GPIO_Init(GPIOF,&GPIO_InitStructure); // 初始化PF9
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc; // 定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; // 向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr; // 自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; // 设置成1分频,即:不分频 
	
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseStructure); // 初始化定时器14
	
	// 初始化TIM14 Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // 选择定时器模式:TIM脉冲宽度调制模式2
	// 模式1即是我们说的, 当CNT<CCR时,为高电平; 当CNT>=CCR时,为低电平
	// 模式2,当CNT>=CCR,为有效电平; 当CNT<CCR,为无效电平
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // 比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; // 输出极性:高电平作为有效电平
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);  // 初始化TIM14 Channell PWM

	TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable); // 使能TIM14的输出比较寄存器
 
	TIM_ARRPreloadConfig(TIM14,ENABLE); // 使能TIM14的自动重装载寄存器
	
	TIM_Cmd(TIM14, ENABLE);  // 使能TIM14									  
}  


