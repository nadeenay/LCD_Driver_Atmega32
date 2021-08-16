/*
 * LCD.H
 *
 * Created: 8/12/2021 9:39:39 PM
 *  Author: Speed
 */
#include "../MCAL/DIO/DIO_types.h"
void LCD_Intialization();

void LCD_Write_C_OR_Data(u8 RS_RW,u8 Data_OR_C);

void LCD_Set_Cursor_Pos(u8 Row,u8 Col);

void LCD_Write_String(u8 Row,u8 Col,u8 str);

void LED_Store_Diff_Char(u8* pattern,u8 Location_CGRAM);

void LED_Display_Diff_Char(u8 CGROM,u8 Row, u8 Col);


