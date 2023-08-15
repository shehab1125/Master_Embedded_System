/* * MBTN_prg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Shehab
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"
#include <avr/delay.h>
#include <stddef.h>

#include "../../MCAL/DIO/DIO_inter.h"

#include "../../HAL/KeyPad/KP_int.h"
#include "../../HAL/KeyPad/KP_pri.h"
#include "../../HAL/KeyPad/KP_cfg.h"

static const u8 KPD_RowsPins[4] = {KPD_ROW1_pin, KPD_ROW2_pin, KPD_ROW3_pin, KPD_ROW4_pin};
static const u8 KPD_ColsPins[4] = {KPD_COL1_pin, KPD_COL2_pin, KPD_COL3_pin, KPD_COL4_pin};

void KPD_vInit() {
    for (u8 L_u8RowCounter = 0; L_u8RowCounter < 4; L_u8RowCounter++) {
        DIO_vSetPinDir(ROW_PORT, KPD_RowsPins[L_u8RowCounter], DIR_OUTPUT);
        DIO_vSetPinVal(ROW_PORT, KPD_RowsPins[L_u8RowCounter], VAL_HIGH);
    }

    for (u8 L_u8ColCounter = 0; L_u8ColCounter < 4; L_u8ColCounter++) {
        DIO_vSetPinDir(COL_PORT, KPD_ColsPins[L_u8ColCounter], DIR_INPUT);
        DIO_vSetPinVal(COL_PORT, KPD_ColsPins[L_u8ColCounter], VAL_HIGH);
    }
}

u8 KPD_vGetPressedKey() {
    u8 L_u8thePressedKey = 0;
    u8 L_u8CheckVal;

    for (u8 L_u8RowCounter = 0; L_u8RowCounter < 4; L_u8RowCounter++) {
        DIO_vSetPinVal(ROW_PORT, KPD_RowsPins[L_u8RowCounter], VAL_LOW);
        _delay_us(10); // Add a small delay to stabilize the signals

        for (u8 L_u8ColCounter = 0; L_u8ColCounter < 4; L_u8ColCounter++) {
            L_u8CheckVal = DIO_u8GetPinVal(COL_PORT, KPD_ColsPins[L_u8ColCounter]);

            if (L_u8CheckVal == 0) {
                L_u8thePressedKey = KPD_au8SwitchVal[L_u8RowCounter][L_u8ColCounter];
                while (L_u8CheckVal == 0) {
                    L_u8CheckVal = DIO_u8GetPinVal(COL_PORT, KPD_ColsPins[L_u8ColCounter]);
                }
                _delay_ms(20); // Add a small delay to avoid multiple detections for the same key
            }
        }
        DIO_vSetPinVal(ROW_PORT, KPD_RowsPins[L_u8RowCounter], VAL_HIGH);
    }
    return L_u8thePressedKey;
}
