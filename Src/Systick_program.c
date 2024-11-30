/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : NVIC_program.h                         */
/******************************************************/

#include <stdint.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "Systick_interface.h"
#include "Systick_config.h"
#include "Systick_private.h"
#include "Systick_register.h"

u8 Copy_u8Flag = 0;
void (*CallBack)(void) = NULL;

void Sys_voidInit(void)
{
#if STK_CLK == AHB
	SET_BIT(SYSTICK->STK_CTRL,2);

#elif STK_CLK == AHB_DIVIDE_8
	CLR_BIT(SYSTICK->STK_CTRL,2);
#endif


}
void Sys_voidSetBusyWait(u32 Copy_u32Ticks)
{

	//Put time in Load register
	SYSTICK->STK_LOAD = Copy_u32Ticks;
	//Disable Systick Interrupt
	CLR_BIT(SYSTICK->STK_CTRL,1);
	//Enable Systick
	SET_BIT(SYSTICK->STK_CTRL,0);
	//Busy Waiting till flag is raised
	while(GET_BIT(SYSTICK->STK_CTRL,16));

}
void Sys_voidSetIntervalSingle(u32 Copy_u32Ticks,void(*ptr)(void))
{
	//Put time in Load register
	SYSTICK->STK_LOAD = Copy_u32Ticks;
	//Enable Systick
	SET_BIT(SYSTICK->STK_CTRL,0);
	//Enable Systick Interrupt
	SET_BIT(SYSTICK->STK_CTRL,1);
	CallBack = ptr;





}
void Sys_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*ptr)(void))
{


	//Put time in Load register
	SYSTICK->STK_LOAD = Copy_u32Ticks;
	//Enable Systick
	SET_BIT(SYSTICK->STK_CTRL,0);
	//Enable Systick Interrupt
	SET_BIT(SYSTICK->STK_CTRL,1);
	CallBack = ptr;
	Copy_u8Flag = 1;



}
void Sys_voidStopInterval(void)
{
	CLR_BIT(SYSTICK->STK_CTRL,0);
	CLR_BIT(SYSTICK->STK_CTRL,1);
}
uint32_t Sys_voidu32GetElapsedTime(void)
{
	u32 Local_u32LoadTime = SYSTICK->STK_LOAD;
	u32 Local_u32ValueTime = SYSTICK->STK_VAL;
	u32 Local_u32ElapsedTime = Local_u32ValueTime - Local_u32LoadTime;
	return Local_u32ElapsedTime;

}
uint32_t Sys_voidu32GetRemainingTime(void)
{
	u32 Local_u32LoadTime = SYSTICK->STK_LOAD;
	return Local_u32LoadTime;


}
void SysTick_Handler(void)
{
    CallBack();
    if(Copy_u8Flag == 0)
    {
    	Sys_voidStopInterval();
    }


}
