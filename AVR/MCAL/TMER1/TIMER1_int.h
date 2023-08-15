
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_




#define RISING_EDEG    0
#define FALLING_EDEG   1



void TIM1_vINT();

void TIM1_vSetOCR1AValue(u16 COPY_U16VALUE);

void TIM1_vSetICR1AValue(u16 COPY_U16ICR1VAL);

void TIM1_vInputCaptureUnintMode();

u16 TIM1_vReadICR1();

void TIM1_vchangetriggering(u8 Copy_u8Triggring);

void TIM1_vSetCallback(void(*fptr)(void));

void TIM1_vDisable_ICU_Inturrpt();

#endif /* MCAL_DIO_DIO_INT_H_ */
