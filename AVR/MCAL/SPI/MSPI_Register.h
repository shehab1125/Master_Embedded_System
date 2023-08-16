/*
 * MSPI_Register.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSPI_MSPI_REGISTER_H_
#define MSPI_MSPI_REGISTER_H_

/************************************************/
/*          Register Definition                 */
/************************************************/

#define SPCR     *((volatile u8*)0x2D)
#define SPSR     *((volatile u8*)0x2E)
#define SPDR     *((volatile u8*)0x2F)



#endif /* MSPI_MSPI_REGISTER_H_ */
