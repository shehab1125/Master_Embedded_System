/*
 * LCD_prg.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Shehab
 */
#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"
#include <avr/delay.h>

#include "../../MCAL/DIO/DIO_inter.h"

#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/LCD/LCD_pri.h"
#include "../../HAL/LCD/LCD_cfg.h"




void LCD_Trigger(void){
	DIO_vSetPinVal(ENPort,ENPIN ,VAL_HIGH);
	_delay_ms(2);
	DIO_vSetPinVal(ENPort,ENPIN ,VAL_LOW);
	_delay_ms(2);

}


void LCD_SendCommand(u8 cmd){

	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW); // EN low
	DIO_vSetPinVal(PORTA_ID, PIN3_ID, VAL_LOW); // RS low for command mode

	DIO_vSetPinVal(PORTB_ID, DataPin1, GET_BIT(cmd, 4));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(cmd, 5));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(cmd, 6));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(cmd, 7));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

	DIO_vSetPinVal(PORTB_ID, DataPin1, GET_BIT(cmd, 0));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(cmd, 1));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(cmd, 2));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(cmd, 3));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

}



void LCD_vInit(){

	/*1- Dio Initialize*/
	DIO_vSetPinDir(PORTA_ID, PIN3_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTA_ID, PIN2_ID, DIR_OUTPUT);

	DIO_vSetPinDir(PORTB_ID, DataPin1, DIR_OUTPUT);
	DIO_vSetPinDir(PORTB_ID, PIN1_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTB_ID, PIN2_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTB_ID, PIN4_ID, DIR_OUTPUT);

	_delay_ms(35);
	//FIRST 4 BITS SENT (function set)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);

	//FIRST 4 BITS SENT (function set)
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_HIGH);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);



	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);

	//SECOND 4 BITS SENT (function set)
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_HIGH);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);

	//last 3 bits
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_HIGH);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);


	_delay_ms(35);
	// FIRST 4 BITS (display on/off control)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);


	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(1);

	// SECOND 4 BITS (display on/off control)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW); //B
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW); //C
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_HIGH); //D
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_HIGH);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(35);
	//FIRST 4 BITS (display clear)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(1);

	//SECOND  4 BITS (display clear)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_HIGH);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(35);

	//FIRST 4 BITS (entry mode set)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(1);

	//SECOND 4 BITS (entry mode set)
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	DIO_vSetPinVal(PORTA_ID,RSPIN ,VAL_LOW);
	_delay_ms(1);
	DIO_vSetPinVal(PORTB_ID,DataPin1,VAL_LOW);
	DIO_vSetPinVal(PORTB_ID,DataPin2,VAL_HIGH);
	DIO_vSetPinVal(PORTB_ID,DataPin3,VAL_HIGH);
	DIO_vSetPinVal(PORTB_ID,DataPin4,VAL_LOW);

	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_HIGH);
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID,ENPIN ,VAL_LOW);
	_delay_ms(1);

}

// Modify the display character function
void LCDdispchar(u8 u8Data) {
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW); // EN low
	DIO_vSetPinVal(PORTA_ID, PIN3_ID, VAL_HIGH); // RS high for data mode

	DIO_vSetPinVal(PORTB_ID, DataPin1,GET_BIT(u8Data, 4));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(u8Data, 5));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(u8Data, 6));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(u8Data, 7));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

	DIO_vSetPinVal(PORTB_ID, DataPin1, GET_BIT(u8Data, 0));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(u8Data, 1));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(u8Data, 2));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(u8Data, 3));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

}

void LCD_vDispStr(u8*A_u8Str){
	u8 L_u8Iterator=0;
	while(A_u8Str[L_u8Iterator]!='\0')
	{LCDdispchar(A_u8Str[L_u8Iterator]);
	L_u8Iterator ++;
	}
}

void LCD_vClrScr(){
	LCD_SendCommand(0x01);
	_delay_ms(2);
}

void LCD_vGoToRowCol(u8 A_u8ROW_ID ,u8 A_u8COL_ID){
	/*	if (A_u8COL_ID>0 && A_u8COL_ID<=19)
	{
		switch(A_u8ROW_ID)
		{
		case 0:LCD_SendCommand(A_u8COL_ID+127); break;
		case 1:LCD_SendCommand(A_u8COL_ID+191); break;
		case 2:LCD_SendCommand(A_u8COL_ID+148); break;
		case 3:LCD_SendCommand(A_u8COL_ID+212); break;
		default: break;
		}
	}
	 */

	if (A_u8ROW_ID < 4 && A_u8COL_ID < 20) {
		// Calculate the DDRAM address based on the row and column
		u8 address = A_u8COL_ID;
		switch (A_u8ROW_ID) {
		case 1: address += 0x40; break; // Add 0x40 for the second row
		case 2: address += 0x14; break; // Add 0x14 for the third row
		case 3: address += 0x54; break; // Add 0x54 for the fourth row
		default: break;
		}

		// Set the cursor to the calculated DDRAM address
		LCD_SendCommand(0x80 | address);
	}
}

void LCD_vDispNum(u32 A_u32Num){

	u8 Local_u8NumArr[10]= {0};
	u8 Local_u8ArrIndex = 0;
	while(A_u32Num > 0)
	{
		Local_u8NumArr[Local_u8ArrIndex] = (A_u32Num % 10);
		A_u32Num /=10;
		Local_u8ArrIndex++;
	}
	for (int i = Local_u8ArrIndex-1 ; i>=0 ;i--)
	{
		LCDdispchar( Local_u8NumArr[i] + '0');
	}
}

void lcd_write_data(u8 A_u8Data){

	DIO_vSetPinVal(ENPort, ENPIN,VAL_LOW);  //en low
	DIO_vSetPinVal(RSPort,RSPIN,VAL_HIGH); //rs high


	DIO_vSetPinVal(PORTB_ID, DataPin1, GET_BIT(A_u8Data, 4));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(A_u8Data, 5));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(A_u8Data, 6));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(A_u8Data, 7));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

	DIO_vSetPinVal(PORTB_ID, DataPin1, GET_BIT(A_u8Data, 0));
	DIO_vSetPinVal(PORTB_ID, PIN1_ID, GET_BIT(A_u8Data, 1));
	DIO_vSetPinVal(PORTB_ID, PIN2_ID, GET_BIT(A_u8Data, 2));
	DIO_vSetPinVal(PORTB_ID, PIN4_ID, GET_BIT(A_u8Data, 3));

	// Trigger
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_HIGH); // EN high
	_delay_ms(2);
	DIO_vSetPinVal(PORTA_ID, PIN2_ID, VAL_LOW);
	_delay_ms(2);

}


// Function to store a special character in the LCD CGRAM
void LCD_u8StoreSpecialChar(u8 u8CharNum, u8* pu8CharShape)
{
	// Check if the character number is within the valid range (0 to 7)
	if (u8CharNum <= 7)
	{
		// Send a command to set CGRAM address to the appropriate location for the custom character
		LCD_SendCommand(0b01000000 + (u8CharNum * 8));

		// Loop to send the character shape data to the CGRAM (Custom Graphic RAM) of the LCD
		for (int i = 0; i < 8; i++)
		{
			LCDdispchar(pu8CharShape[i]);
		}

	}
}

// Function to display a stored special character on the LCD
void LCD_u8DisplaySpecialChar(u8 u8CharNum, u8 A_u8ROW_ID, u8 A_u8COL_ID)
{
	// Check if the character number, location, and line number are within valid ranges
	if ((u8CharNum<= 7) && (A_u8COL_ID <= 19) && (A_u8ROW_ID <= 4))
	{
		// Set the cursor position to the specified line and location
		LCD_vGoToRowCol(A_u8ROW_ID, A_u8COL_ID);

		// Display the custom character on the LCD at the specified location
		LCDdispchar(u8CharNum);
	}
}
/*
void LCD_voidShiftRight(void)
{
	LCD_SendCommand(0b00011100);
	_delay_ms(100);
}

void LCD_voidShiftLeft(void)
{
	LCD_SendCommand(0b00011000);
	_delay_ms(100);
}
 */


void LCD_ShiftSpecialChar(u8 u8CharNum, u8 A_u8Direction, u8 A_u8ROW_ID, u8 A_u8COL_ID, u8* pu8CharShape) {
    // Check if the character number is within the valid range (0 to 7)
    if (u8CharNum <= 7) {
        // Store the custom character in a variable
        u8 customChar[8];
        for (int i = 0; i < 8; i++) {
            customChar[i] = pu8CharShape[u8CharNum * 8 + i];
        }

        // Shift the custom character in the specified direction
        if (A_u8Direction == SHIFT_RIGHT) {
            // Right shift the custom character
            u8 temp = customChar[7];
            for (int i = 7; i > 0; i--) {
                customChar[i] = customChar[i - 1];
            }
            customChar[0] = temp;
        } else if (A_u8Direction == SHIFT_LEFT) {
            // Left shift the custom character
            u8 temp = customChar[0];
            for (int i = 0; i < 7; i++) {
                customChar[i] = customChar[i + 1];
            }
            customChar[7] = temp;
        }

        // Store the modified custom character back to the character shape array
        for (int i = 0; i < 8; i++) {
            pu8CharShape[u8CharNum * 8 + i] = customChar[i];
        }

        // Set the cursor position to the specified location
        LCD_vGoToRowCol(A_u8ROW_ID, A_u8COL_ID);

        // Display the modified custom character on the LCD
        for (int i = 0; i < 8; i++) {
            LCDdispchar(customChar[i]);
        }
    }
}


void LCD_ShiftChar(u8 A_u8Row, u8 A_u8Col, u8 A_u8Direction) {
	// Calculate the DDRAM address based on the row and column of the character
	u8 address = A_u8Col;
	switch (A_u8Row) {
	case 1: address += 0x40; break; // Add 0x40 for the second row
	case 2: address += 0x14; break; // Add 0x14 for the third row
	case 3: address += 0x54; break; // Add 0x54 for the fourth row
	default: break;
	}

	// Set the DDRAM address to the location of the character
	LCD_SendCommand(0x80 | address);

	// Shift the character in the specified direction
	if (A_u8Direction == SHIFT_RIGHT) {
		LCD_SendCommand(0b00011100); // Shift right command
	} else if (A_u8Direction == SHIFT_LEFT) {
		LCD_SendCommand(0b00011000); // Shift left command
	}

	// Add a small delay to ensure the shift operation is completed
	_delay_ms(2);
}



