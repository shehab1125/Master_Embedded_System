#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"

#include "DIO_reg.h"
#include "DIO_inter.h"


void DIO_vSetPinDir(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Dir){
	switch (A_u8portId){
	case PORTA_ID:WRT_BIT(DDRA, A_u8PinId ,  A_u8Dir); break;
	case PORTB_ID:WRT_BIT(DDRB, A_u8PinId ,  A_u8Dir); break;
	case PORTC_ID:WRT_BIT(DDRC, A_u8PinId ,  A_u8Dir); break;
	case PORTD_ID:WRT_BIT(DDRD, A_u8PinId ,  A_u8Dir); break;
	}
}

void DIO_vSetPinVal(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Val){
	switch (A_u8portId){
		case PORTA_ID:WRT_BIT(PORTA, A_u8PinId ,  A_u8Val); break;
		case PORTB_ID:WRT_BIT(PORTB, A_u8PinId ,  A_u8Val); break;
		case PORTC_ID:WRT_BIT(PORTC, A_u8PinId ,  A_u8Val); break;
		case PORTD_ID:WRT_BIT(PORTD, A_u8PinId ,  A_u8Val); break;
		}
}

u8 DIO_u8GetPinVal(u8 A_u8PortId, u8 A_u8PinId){
	u8 L_u8PinVal = 0;
	switch (A_u8PortId){
		case PORTA_ID: L_u8PinVal = GET_BIT(PINA, A_u8PinId); break;
		case PORTB_ID: L_u8PinVal = GET_BIT(PINB, A_u8PinId); break;
		case PORTC_ID: L_u8PinVal = GET_BIT(PINC, A_u8PinId); break;
		case PORTD_ID: L_u8PinVal = GET_BIT(PIND, A_u8PinId); break;
	}
	return L_u8PinVal;
}

void DIO_vSetPortDir(u8 A_u8portId,u8 A_u8Dir){
	switch (A_u8portId){
			case PORTA_ID:  DDRA=A_u8Dir; break;
			case PORTB_ID:  DDRB=A_u8Dir; break;
			case PORTC_ID:  DDRC=A_u8Dir; break;
			case PORTD_ID:  DDRD=A_u8Dir; break;
			default: break;
		}
}

void DIO_vSetPortVal(u8 A_u8portId,u8 A_u8Val){
	switch (A_u8portId){
				case PORTA_ID:  PORTA=A_u8Val; break;
				case PORTB_ID:  PORTB=A_u8Val; break;
				case PORTC_ID:  PORTC=A_u8Val; break;
				case PORTD_ID:  PORTD=A_u8Val; break;
				default: break;
			}
}

void DIO_vTogglePinVal(u8 A_u8PortId,u8 A_u8PinId){
			A_u8PortId^=(1<<A_u8PinId);
}

