#ifndef UART_CONFIG_H
#define UART_CONFIG_H


/* Select Operation */
#define ASynch								0
#define Synch								1

#define Operation_Mode						ASynch



/* Select Parity Mode  */
#define None								0
#define Even								1
#define Odd									2

#define Parity_Mode							None



/* Select Stop Bit Mode */
#define One_Bit								0
#define Two_Bits							1

#define StopBits_Mode						One_Bit



/* Select Speed Mode */
#define Normal_Speed						0
#define Double_Speed						1

#define Speed_Mode							Normal_Speed



/* Select Bit Data Mode */
#define Five_Data							0
#define Six_Data							1
#define Seven_Data							2
#define Eight_Data							3
#define Nine_Data							4

#define BitData_Mode						Eight_Data

#endif
