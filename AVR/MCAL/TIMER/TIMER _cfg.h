/*
 * TIMER _cfg.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Shehab
 */

#ifndef TIMER_TIMER__CFG_H_
#define TIMER_TIMER__CFG_H_

/*timer0 prescaler otions
 * 1-timer_stop
 * 2-no_prescaler
 * 3-8prescaler
 * 4-64prescaler
 * 5-256prescaler
 * 6-1024prescaler
 * 7-external_clk_falling_edge
 * 8-external_clk_rising_edge
 * */

#define MTIM0_set_Prescaler  MTIME_64_prescaler

/*TMER0 MODE OPTIONS:
* MTIM0_OVERFLOW_MODE
* MTIM0_CTC_MODE
* MTIM0_PHASE_CORRECT_PWM_MODE
* MTIM0_Fast_PWM_MODE
*/
#define MTIM0_MODE   MTIM0_Fast_PWM_MODE

/*MTIM0 OC0 PIN OPTIONS at CTC(which generates wave):
 * 1-MTIM0_OC0_DISCONNECTED
 * 2-MTIM0_OC0_TOGGLE
 * 3-MTIM0_OC0_CLEAR
 * 4-MTIM0_OC0_SET
 * */
#define MTIM0_PIN_OC0_MODE    MTIM0_OC0_DISCONNECTED

/*MTIM0 PWM MODES :
 *MTIM0_PWM_NON_Inveting_Mode     _NON_Inveting_Mode (duity cycle direct prob to OCR)
 *MTIM0_PWM_Inveting_Mode          Inveting_Mode (duity cycle INVERSILY prob to OCR)
   */
#define MTIM0_PWM_SET_MODE   MTIM0_PWM_NON_Inveting_Mode

#endif /* TIMER_TIMER__CFG_H_ */
