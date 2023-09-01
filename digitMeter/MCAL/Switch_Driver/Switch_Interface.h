#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#define SWITCH_PULL_UP		1

void Switch_Init(Switch *Arr, u8 Switch_Num);
void Switch_GetValue(u8 *ptr_Value);

#endif
