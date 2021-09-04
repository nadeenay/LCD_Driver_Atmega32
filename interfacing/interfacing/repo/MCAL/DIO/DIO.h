

void DIO_SetPortDiraction(DIO_PORT Port_ID,DIO_DIRECTION Direction);

void DIO_SetPortValue(DIO_PORT Port_ID,u8 Port_Value);

void DIO_SetPinDirection(DIO_PORT Port_ID,u8 Pin_Num, DIO_DIRECTION Direction);

void DIO_SetPinValue(DIO_PORT Port_ID,u8 Pin_Num, u8 Pin_Value);

u8 DIO_GetPinValue(DIO_PORT Port_ID,u8 Pin_Num);

unsigned char DIO_GetPortValue(DIO_PORT Port_ID);


