/*
 * delay.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Shehab
 */


void	_delay_ms(unsigned long  int ticks)
{
	unsigned long  int i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}
