#ifndef		EXTI0_PRIVATE_H
#define		EXTI0_PRIVATE_H

#define MCUCR   *( ( u8 *) 0x55)
#define MCUCSR  *( ( u8 *) 0x54)
#define GIFR	*( (volatile u8 *) 0x5A)
#define GICR 	*( ( u8 *) 0x5B)

void __vector_1(void) __attribute__((signal , used));

#endif