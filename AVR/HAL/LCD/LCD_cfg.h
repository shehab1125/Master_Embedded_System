/*
 * LCD_cfg.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Shehab
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
/*modes*/
/*the mode is
 * 4_bit */


/*connection*/

#define DataPort  PORTB_ID
#define RSPort    PORTA_ID
#define ENPort    PORTA_ID

#define RSPIN     PIN3_ID
#define ENPIN     PIN2_ID
#define DataPin1  PIN0_ID
#define DataPin2  PIN1_ID
#define DataPin3  PIN2_ID
#define DataPin4  PIN4_ID

#endif /* HAL_LCD_LCD_CFG_H_ */
