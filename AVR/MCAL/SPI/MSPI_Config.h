/*
 * MSPI_Config.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MSPI_MSPI_CONFIG_H_
#define MCAL_MSPI_MSPI_CONFIG_H_

/*SPI Data Ordered Options:
 * 1- MSPI_DATA_ORDERED_LSB
 * 2- MSPI_DATA_ORDERED_MSB
 */
#define MSPI_SET_DATA_ORDERED     MSPI_DATA_ORDERED_LSB

/*SPI Clock Polarity Options:
 * 1- MSPI_CPOL_LEADING_RISING
 * 2- MSPI_CPOL_LEADING_FALLING
 */
#define MSPI_SET_CLOCK_POLARITY   MSPI_CPOL_LEADING_RISING

/*SPI Clock Polarity Options:
 * 1- MSPI_CPHA_LEADING_SAMPLE
 * 2- MSPI_CPHA_LEADING_SETUP
 */
#define MSPI_SET_CLOCK_PHASE      MSPI_CPHA_LEADING_SETUP

/*SPI Double Speed Clock Options:
 * 1- MSPI_NO_DOUBLE_SPEED
 * 2- MSPI_DOUBLE_SPEED
 */
#define MSPI_SET_DOUBLE_SPEED     MSPI_NO_DOUBLE_SPEED

/*MSPI CLOCK RATE OPIONS:
 * 1- MSPI_CLOCK_RATE_4
 * 2- MSPI_CLOCK_RATE_16
 * 3- MSPI_CLOCK_RATE_64
 * 4- MSPI_CLOCK_RATE_128
 */
#define  MSPI_SET_CLOCK_RATE      MSPI_CLOCK_RATE_4

/*SPI interrupt enable Options:
 * 1- MSPI_SPI_INTERRUPT_ENABLE
 * 2- MSPI_SPI_INTERRUPT_DISABLE
 */
#define MSPI_SET_SPI_INTERRUPT_ENABLE   MSPI_SPI_INTERRUPT_DISABLE

#endif /* MCAL_MSPI_MSPI_CONFIG_H_ */