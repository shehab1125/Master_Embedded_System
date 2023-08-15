/*
 * TIMER_pri.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Shehab
 */

#ifndef TIMER_TIMER_PRI_H_
#define TIMER_TIMER_PRI_H_

 #define timer_stop                           0
 #define no_prescaler                         1
 #define MTIME_8_prescaler                    2
 #define MTIME_64_prescaler                   3
 #define MTIME_256_prescaler                  4
 #define MTIME_1024_prescaler                 5
 #define external_clk_falling_edge            6
 #define external_clk_rising_edge             7


#define MTIM0_OVERFLOW_MODE                   0
#define MTIM0_CTC_MODE                        1
#define MTIM0_PHASE_CORRECT_PWM_MODE          2
#define MTIM0_Fast_PWM_MODE                   3

#define MTIM0_OC0_DISCONNECTED                0
#define MTIM0_OC0_TOGGLE                      1
#define MTIM0_OC0_CLEAR                       2
#define MTIM0_OC0_SET                         3


 #define MTIM0_PWM_NON_Inveting_Mode          0
 #define MTIM0_PWM_Inveting_Mode              1


#endif /* TIMER_TIMER_PRI_H_ */
