#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

void SevenSegment_Init(u8 Copy_u8PortId);
void SevenSegment_Display(u8 Copy_u8PortId, u8 Copy_u8Pin0, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3, u8 Copy_u8Pin4, u8 Copy_u8Pin5, u8 Copy_u8Pin6);
void SevenSegment_From0To9(u8 Copy_u8PortId);
void SevenSegment_FromAToH(u8 Copy_u8PortId);


#endif
