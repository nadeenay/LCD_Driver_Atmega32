
/*
 * Bit_Functions.h
 *
 * Created: 8/11/2021 10:24:06 AM
 *  Author: Speed
 */ 
#define SETBIT(Port_ID,Pin_Num)     (Port_ID) |=(1<<(Pin_Num));
#define GETBIT(Port_ID,Pin_Num)     (((Port_ID) >> (Pin_Num)) & 0x01) //0 or 1
#define CLEARBIT(Port_ID,Pin_Num)   (Port_ID)&=~(1<<(Pin_Num));
#define TOGGLEBIT(Port_ID,Pin_Num)  (Port_ID)^=(1<<(Pin_Num));
