/* 
 * File:   mcal_std_types.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:43 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section : Includes */
#include "std_libraries.h"


/* Section: Data Type Declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

/* Section: Macro Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00

#define ZERO_INIT 0

/* Section: Macro Functions Declarations */
/* Section: Macro Functions Declarations */
#define BIT_MASK  (uint32)1

#define SET_BIT_h(REG, BIT_POSN)     (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT_h(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT_h(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT_h(REG, BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK)
#define GET_BIT_h(REG, BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK)

/* Section: Function Declarations */

#endif	/* MCAL_STD_TYPES_H */

