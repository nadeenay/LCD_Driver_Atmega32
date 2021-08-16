
/*
 * DIO.h
 *
 * Created: 8/10/2021 8:26:01 PM
 *  Author: Speed
 */ 
void DIO_SetPortDiraction(DIO_PORT Port_ID,DIO_DIRECTION Direction);

void DIO_SetPortValue(DIO_PORT Port_ID,unsigned char Port_Value);

void DIO_SetPinDirection(DIO_PORT Port_ID,PIN_NUM Pin_Num, DIO_DIRECTION Direction);

void DIO_SetPinValue(DIO_PORT Port_ID,PIN_NUM Pin_Num, VALUE Pin_Value);

VALUE DIO_GetPinValue(DIO_PORT Port_ID,PIN_NUM Pin_Num);

unsigned char DIO_GetPortValue(DIO_PORT Port_ID);


