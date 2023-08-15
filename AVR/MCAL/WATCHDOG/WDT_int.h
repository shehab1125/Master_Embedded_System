/*
 * WDT_int.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Shehab
 */

#ifndef WATCHDOG_WDT_INT_H_
#define WATCHDOG_WDT_INT_H_

/*sleep options
 * 0 -> 16.3  ms
 * 1->  32.5  ms
 * 2->  65    ms
 * 3->  0.13  SEC
 * 4->  0.26  sec
 * 5->  0.52  sec
 * 6->  1     sec
 * 7->  2.1   sec
 * */




void WDT_vEnable();

void WDT_vDisable();

void WDT_vRefresh(void);

#endif /* WATCHDOG_WDT_INT_H_ */
