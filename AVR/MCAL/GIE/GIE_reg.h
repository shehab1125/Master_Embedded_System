/*
 * GIE_reg.h
 *
 *  Created on: 29 Aug 2022
 *      Author: Mohamed Osama
 */

#ifndef MCAL_GIE_GIE_REG_H_
#define MCAL_GIE_GIE_REG_H_

/*  Status Register Definition */

#define SREG *( (volatile u8 *) 0x5F)			// continous changing without I change it




#endif /* MCAL_GIE_GIE_REG_H_ */



/*
 * any register that I don't write it's contents by itself we have to write volatile before it
 * */
