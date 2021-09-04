/*
 * LCD.c
 *
 * Created: 8/12/2021 10:14:03 PM
 *  Author: Speed
 */ 
#include "../HAL/LCD.h"
#include <util/delay.h>

void LCD()
{  /*
	LCD_Intialization();
	LCD_Write_String(1,6,"Ahmed\r");
	
	_delay_ms(3000);
	LCD_Write_C_OR_Data(0x00,0x01);
	
	u8* pattern={0x0E,0x08,0x1E,0x00,0x04,0x04,0x04,0x04};
	LED_Store_Diff_Char(pattern,3);
	LED_Display_Diff_Char(3,0,0);
	*/

 LCD_Intialization();
 LCD_Write_String(1,13,"Ahmeddddddddddddddd\r");
 


}
