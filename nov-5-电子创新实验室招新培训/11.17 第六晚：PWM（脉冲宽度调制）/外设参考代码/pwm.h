#ifndef _PWM_H
#define _PWM_H
#include "sys.h"

// arr:�Զ���װ��ֵ
// psc:Ԥ��Ƶϵ��,0~65536
void TIM14_PWM_Init(u16 arr,u16 psc); // PWM��ʼ��,��ͨ�ö�ʱ��14����

#endif