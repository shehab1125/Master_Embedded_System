/*
 * EXT_REG.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#ifndef EXT_EXT_REG_H_
#define EXT_EXT_REG_H_

typedef struct
{ volatile u32 IMR1;
  volatile u32 EMR1;
  volatile u32 RTSR1;
  volatile u32 FTSR1;
  volatile u32 SWIER1;
  volatile u32 PR1;
}EXTI;


#define EXTI                                   ((EXTI *)  (0x40010400))

#endif /* EXT_EXT_REG_H_ */
