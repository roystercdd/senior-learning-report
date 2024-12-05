#ifndef _PWM_H
#define _PWM_H
#include "sys.h"

// arr:自动重装载值
// psc:预分频系数,0~65536
void TIM14_PWM_Init(u16 arr,u16 psc); // PWM初始化,用通用定时器14来做

#endif