
#include <util/delay.h>
#include "../MCAL/DIO/Bit_Functions.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"

static Initialization_Finished=0;

void LCD_Intialization()
{
	DIO_SetPortDiraction(PORTA_,OUTPUT);
	DIO_SetPortDiraction(PORTB_,OUTPUT);
	
	_delay_ms(30);
	
	/*  4-bit mode */
	LCD_Write_C_OR_Data(0x00,0x20);
	LCD_Write_C_OR_Data(0x00,0x20);
	/* send N and F N-->num_of_lines F-->font_size */
	LCD_Write_C_OR_Data(0x00,0x80);
	
	_delay_ms(1);
	
	
	LCD_Write_C_OR_Data(0x00,0x00);
	/* send N F D-->Disply off  C-->cursor off B-->blink off */
	LCD_Write_C_OR_Data(0x00,0xf0);
	
	_delay_ms(1);
	
	LCD_Write_C_OR_Data(0x00,0x00);
	/* Clear the LCD*/
	LCD_Write_C_OR_Data(0x00,0x10);
	
	_delay_ms(2);
	
	Initialization_Finished=1;
}
void LCD_Write_C_OR_Data(u8 RS_RW,u8 Data_OR_C) /* 0000 00RSRW == RS_RW */
{
	/* Get RS */
	DIO_SetPinValue(PORTB_,PIN2,GETBIT(RS_RW,1));	
	
	
	/* Get RW */
	DIO_SetPinValue(PORTB_,PIN1,GETBIT(RS_RW,0));
	
	
	/* send data in 4 bit mode */
	
	/* set the E with high */
	DIO_SetPinValue(PORTB_,PIN0,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB_,PIN0,LOW);  //falling edge
	
	/* send UPPER bits first */
	DIO_SetPinValue(PORTA_,PIN0,GETBIT(Data_OR_C,4));
	DIO_SetPinValue(PORTA_,PIN1,GETBIT(Data_OR_C,5));
	DIO_SetPinValue(PORTA_,PIN2,GETBIT(Data_OR_C,6));
	DIO_SetPinValue(PORTA_,PIN3,GETBIT(Data_OR_C,7));
	
	if(Initialization_Finished)
	{
	/* set the E with high */
	DIO_SetPinValue(PORTB_,PIN0,HIGH);
	_delay_ms(1);
	/* falling edge */
	DIO_SetPinValue(PORTB_,PIN0,LOW);  
	
	/* send LOWER bits first */
	DIO_SetPinValue(PORTA_,PIN0,GETBIT(Data_OR_C,0));
	DIO_SetPinValue(PORTA_,PIN1,GETBIT(Data_OR_C,1));
	DIO_SetPinValue(PORTA_,PIN2,GETBIT(Data_OR_C,2));
	DIO_SetPinValue(PORTA_,PIN3,GETBIT(Data_OR_C,3));
	}
	_delay_ms(2);
	
}
u8 LCD_Set_Cursor_Pos(u8 Row,u8 Col)
{
	u8 address;
	if(Row<2&&Col<16)
	{
		address=(Row*0x40)+Col;
		address=SETBIT(address,7);
		LCD_Write_C_OR_Data(0x00,address);
		return 1;	
	}
	return 0;
} 
void LCD_Write_String(u8 Row,u8 Col,u8* str)
{
	
	if(LCD_Set_Cursor_Pos(Row,Col))
	{
		u8 letter,index=0;
	   for(u8*i=str;letter=*i;i++)
	   {
		/* check if the 2 lines have ended or the string has ended*/
		if(letter=='\r'&&((Row*16)+(index+Col))>=32) 
		break;
		
		/* the first line has finished */
		if(((Row*16)+(index+Col))==16) 
		LCD_Set_Cursor_Pos(1,0);
		
		LCD_Write_C_OR_Data(0x02,letter);
		index++;
	   }
	return ;
	}
	/* if the user enter a not valid pos for the cursor */
	LCD_Write_String(0,0,"Please enter a valid position :)");
	return 0;

	
}

void LED_Store_Diff_Char(u8* pattern,u8 Location_CGRAM)

{
	/* CGRAM CONFIGURATION 8 LOCATION EACH LOCATION LIKE A 8 REGISTER EACH ONE IS 8 BIT
	
	pattern is an array of the data that will be written in the 8 register in the location
	
	to set the AC in the CGRAM (point to the location we want) use command 0001AC */
	u8 i,address;
	address=Location_CGRAM*8;
	address=SETBIT(address,6);
	LCD_Write_C_OR_Data(0x00,address);
	for (i=0;i<8;i++)
	{
		LCD_Write_C_OR_Data(0x02,pattern[i]);
	}
	LCD_Write_C_OR_Data(0x00,0x02); //to return back the AC in DDRAM
}

void LED_Display_Diff_Char(u8 CGROM,u8 Row, u8 Col)
{
	
	LCD_Set_Cursor_Pos(Row,Col);
	LCD_Write_C_OR_Data(0x02,CGROM);
}

void Clear_LCD()
{
	/* Clear the display screen */
	LCD_Write_C_OR_Data(0x00,0x01);
	_delay_ms(2);
	
	/* Force the cursor to the beginning of the 1st line */
	LCD_Write_C_OR_Data(0x00,0x80);
	
}