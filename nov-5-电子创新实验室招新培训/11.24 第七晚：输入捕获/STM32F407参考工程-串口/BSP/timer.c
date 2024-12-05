#include "timer.h"
#include "led.h"
#include "usart.h"

//TIM14 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM14_PWM_Init(u32 arr,u32 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);  	//TIM14ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); 	//ʹ��PORTFʱ��	
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14); //GPIOF9����λ��ʱ��14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //GPIOA9 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOF,&GPIO_InitStructure); //��ʼ��PF9
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; // ����Ƶ
	
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseStructure);
	
	// ��ʼ��TIM14 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_Pulse=0;
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2

	TIM_OC2PreloadConfig(TIM14, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
 
	TIM_ARRPreloadConfig(TIM14,ENABLE);
	
	TIM_Cmd(TIM14, ENABLE);  //ʹ��TIM14		

}  

// ����Ϊȫ�ֱ���
TIM_ICInitTypeDef  TIM5_ICInitStructure; // ���벶���ʼ���ṹ��

//��ʱ��5ͨ��1���벶������
//arr���Զ���װֵ(TIM2,TIM5��32λ��!!)
//psc��ʱ��Ԥ��Ƶ��
void TIM5_CH1_Cap_Init(u32 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; // GPIO��ʼ���ṹ�������PA0
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure; // ��ʱ��������ʼ���ṹ��
	NVIC_InitTypeDef NVIC_InitStructure; // Ƕ�������жϿ�������ʼ���ṹ��������ж����ȼ���
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // ����ϵͳ�ж����ȼ�����2

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	// TIM5ʱ��ʹ�� 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	// ʹ��PORTAʱ��	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // GPIOA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; // ���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	// �ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ���츴�����
	// ���������ź�����ʱ���ڵ͵�ƽ״̬����Ϊ�������Ȳ����������ٲ����½��أ�������Ʒ����߼�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; // ����
	GPIO_Init(GPIOA,&GPIO_InitStructure); // ��ʼ��PA0

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5); // PA0����λ��ʱ��5
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  // ��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; // ���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   // �Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; // ����Ƶ

	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);

	// ��ʼ��TIM5���벶�����
	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; // ʹ��TIM5_CH1
	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	// �����ز���
	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; // TI��Timer Input����ʾֱ��ӳ�䵽�����źŶ�
	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 // ���������Ƶ,����Ƶ 
	TIM5_ICInitStructure.TIM_ICFilter = 0x00; // IC1F=0000 ���������˲��� ���˲������벶���źſ����ص�Ÿ��Ż�����Ӱ�죩
	TIM_ICInit(TIM5, &TIM5_ICInitStructure);
		
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC1,ENABLE); // ��������ж� ,����CC1IE�����ж�	

	TIM_Cmd(TIM5,ENABLE ); 	//ʹ�ܶ�ʱ��5

	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2; // ��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		// �����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			// IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	// ����ָ���Ĳ�����ʼ��NVIC�Ĵ���
}
// ����״̬
// [7]:0, û�гɹ��Ĳ���;1,�ɹ�����һ����������
// [6]:0, ��û�����½���; 1,�Ѿ������½�����.
// [5:0]: ����͵�ƽ������Ĵ���
u8  TIM5CH1_CAPTURE_STA=0;	// ���벶��״̬��STA��ʾstatus����˼		    				
u32	TIM5CH1_CAPTURE_VAL;	// ���벶��ֵ(TIM2/TIM5��32λ)
// ��ʱ��5�жϷ������	 
// �жϷ�����������������½��룬����TIM_IT_Update�¼����������ʱ�䣩��TIM_IT_CC1�¼������벶���¼���
void TIM5_IRQHandler(void)
{ 		    
	// 0X80��1000 0000(���λ��1)�������㣬Ϊ1��ʾ���������ء�ת��ȥ�����½���
 	if((TIM5CH1_CAPTURE_STA&0X80)==0) // ��δ�ɹ�����	
	{
		// TIM_IT_Update���ж����ʱ�䣬==RESET δ�����==SET ���
		if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)//���
		{	     
			// 0X40��0100 0000�������㣬Ϊ1��ʾ�����½��أ�Ϊ0��ʾδ�����½���
			// �Ѿ������½���
			if(TIM5CH1_CAPTURE_STA&0X40)
			{
				// ���Ǽ�ʱ������ˣ�˵���ߵ�ƽ����ʱ��̫���ˣ���ʱ��������˻�û�����½��أ�...
				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)
				{
					// �����㣬�����λ��1����ʾ�ɹ�����һ��
					TIM5CH1_CAPTURE_STA|=0X80;	// ��ǳɹ�������һ�� 
					TIM5CH1_CAPTURE_VAL=0XFFFFFFFF; // ����β�����Ϊ�쳣���������0X3F���˻�û���񵽣�ֻ�ñ��Ϊ�쳣��
				}
				else TIM5CH1_CAPTURE_STA++; // ����STA++
			}	 
		}
		
		// TIM_IT_CC1��ͨ��1�������벶���¼�
		// RESET��δ������SET������
		// ��⵽�����ػ��½���ʱ�ᴥ�������¼�
		
		if(TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET) // ͨ��1���������¼�
		{	
			// һ��ʼ��else����Ϊ��ʼ����ʱ��Ĭ�ϲ�׽������
			if(TIM5CH1_CAPTURE_STA&0X40)	// �����½��ص�ʱ������������ʾ����һ����������	
			{	  			
				TIM5CH1_CAPTURE_STA|=0X80;	// ��ǳɹ�����һ�θߵ�ƽ����
			  TIM5CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5); // ��ȡ��ǰ�Ĳ���ֵ.
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising); // CC1P=0 ����Ϊ�����ز���
			}
			else 
			{
				// ��Ϊ��һ�����̵Ŀ�ʼ�����԰�STA��VAL��Ϊ0����ʾһ�����ڵĿ�ʼ
				TIM5CH1_CAPTURE_STA=0; 
				TIM5CH1_CAPTURE_VAL=0;
				// �������жϣ������Ǹ����¼���˵�������˲����¼� �� ����������
				TIM5CH1_CAPTURE_STA|=0X40; // �ѵ���λ���1����ʾ�����������ˣ�����ȥ�����½���
				TIM_Cmd(TIM5,DISABLE );  // �رն�ʱ��5
	 			TIM_SetCounter(TIM5,0); // TIM5��CNT��0�����������½��ص�ʱ�򣬰�CNT��0����������ǵ�ֵ
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);	 // ����Ϊ�½��ز���
				TIM_Cmd(TIM5,ENABLE ); 	// ʹ�ܶ�ʱ��5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC1|TIM_IT_Update); // ����жϱ�־λ�������Ϳ��Խ�����һ���ж�
}