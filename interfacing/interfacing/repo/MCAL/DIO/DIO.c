/*
 * DIO.c
 *
 * Created: 8/10/2021 8:37:41 PM
 *  Author: Speed
 */ 
#include "REG.h"
#include "DIO_types.h"	
#include <avr/io.h>	  
#include "Bit_Functions.h"
void DIO_SetPortDiraction(DIO_PORT Port_ID,DIO_DIRECTION Direction)
{
	if(Direction==OUTPUT)
	switch(Port_ID)
	{
		case PORTA_ : DDRA =0xFF;break; //DDRA -->*((volatile unsighned char*)0x1A)..and so on
		case PORTB_ : DDRB =0xFF;break;
		case PORTC_ : DDRC =0xFF;break;
		case PORTD_ : DDRD =0xFF;break;
	}
	else
	switch(Port_ID)
	{
		case PORTA_ : DDRA =0x00;break;
		case PORTB_ : DDRB =0x00;break;
		case PORTC_ : DDRC =0x00;break;
		case PORTD_ : DDRD =0x00;break;
	}
}

void DIO_SetPortValue(DIO_PORT Port_ID, unsigned char Port_Value)
{
	switch(Port_ID)
	{
		case PORTA_ : PORTA=Port_Value;break;
		case PORTB_ : PORTB=Port_Value;break;
		case PORTC_ : PORTC=Port_Value;break;
		case PORTD_ : PORTD=Port_Value;break;
	}
	
}

void DIO_SetPinDirection(DIO_PORT Port_ID,PIN_NUM Pin_Num, DIO_DIRECTION Direction)
{
		if(Pin_Num<=PIN7&&Port_ID<=PORTD_)
		{
			if(Direction==OUTPUT)
			{
			switch(Port_ID)
			{
				case PORTA_ : SETBIT(DDRA,Pin_Num);break;
				case PORTB_ : SETBIT(DDRB,Pin_Num);break;
				case PORTC_ : SETBIT(DDRC,Pin_Num);break;
				case PORTD_ : SETBIT(DDRD,Pin_Num);break;
			}
		}
		else
		{
			switch(Port_ID)
			{
				case PORTA_ : CLEARBIT(DDRA,Pin_Num);break;
				case PORTB_ : CLEARBIT(DDRB,Pin_Num);break;
				case PORTC_ : CLEARBIT(DDRC,Pin_Num);break;
				case PORTD_ : CLEARBIT(DDRD,Pin_Num);break;
			}
		}
		
				
		}
}

void DIO_SetPinValue(DIO_PORT Port_ID,PIN_NUM Pin_Num, VALUE Pin_Value)
{
	if(Pin_Num<=PIN7&&Port_ID<=PORTD_)
	{
		if(Pin_Value==HIGH)
		{
		        switch(Port_ID)
		        {
			        case PORTA_ : SETBIT(PORTA,Pin_Num);break;
			        case PORTB_ : SETBIT(PORTB,Pin_Num);break;
			        case PORTC_ : SETBIT(PORTC,Pin_Num);break;
			        case PORTD_ : SETBIT(PORTD,Pin_Num);break;
		        }
				}
				else
				{
					switch(Port_ID)
					{
						case PORTA_ : CLEARBIT(PORTA,Pin_Num);break;
						case PORTB_ : CLEARBIT(PORTB,Pin_Num);break;
						case PORTC_ : CLEARBIT(PORTC,Pin_Num);break;
						case PORTD_ : CLEARBIT(PORTD,Pin_Num);break;
					}
				}
	
	}
	
}

VALUE DIO_GetPinValue(DIO_PORT Port_ID,PIN_NUM Pin_Num)
{
	VALUE PIN_VALUE;
	if(Pin_Num<=PIN7&&Port_ID<=PORTD_)
	{
		
	switch(Port_ID)
		{
			case PORTA_ : PIN_VALUE=GETBIT(PINA,Pin_Num);break;
			case PORTB_ : PIN_VALUE=GETBIT(PINB,Pin_Num);break;
			case PORTC_ : PIN_VALUE=GETBIT(PINC,Pin_Num);break;
			case PORTD_ : PIN_VALUE=GETBIT(PIND,Pin_Num);break;
		}
	}
	return PIN_VALUE;
}

unsigned char DIO_GetPortValue(DIO_PORT Port_ID)
{
	if(Port_ID<=PORTD_)
	{
		
		switch(Port_ID)
		{
			case PORTA_ :return PINA;break;
			case PORTB_ :return PINB;break;
			case PORTC_ :return PINC;break;
			case PORTD_ :return PIND;break;
		}
	}
}
