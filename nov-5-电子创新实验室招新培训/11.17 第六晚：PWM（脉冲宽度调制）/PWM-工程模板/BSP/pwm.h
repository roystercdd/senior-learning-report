#ifndef _PWM_H
#define _PWM_H
#include "sys.h"

// arr: �Զ���װ��ϵ��
// psc: Ԥ��Ƶϵ��
// Tout= (arr+1)��(psc+1)/TCLK TCLK:84MHz
// 1~65535
// arr=8400-1, psc=200-1
// Tout=8400��200/84��10^6=50s
// u16 �� unsigned 16 �޷���ʮ��λ��
void TIM14_PWM_Init(u16 arr, u16 psc); 

#endif