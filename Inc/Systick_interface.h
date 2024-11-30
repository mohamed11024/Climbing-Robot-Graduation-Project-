/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : Sys_interface.h                        */
/******************************************************/


#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void Sys_voidInit(void);
void Sys_voidSetBusyWait(u32 Copy_u32Ticks);
void Sys_voidSetIntervalSingle(u32 Copy_u32Ticks,void(*ptr)(void));
void Sys_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*ptr)(void));
void Sys_voidStopInterval(void);
uint32_t Sys_voidu32GetElapsedTime(void);
uint32_t Sys_voidu32GetRemainingTime(void);









#endif /* SYSTICK_INTERFACE_H_ */
