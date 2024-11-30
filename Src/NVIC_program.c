/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : NVIC_program.h                         */
/******************************************************/


#include <stdint.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_register.h"

void NVIC_voidEnableNVICPerInterrupt(IntReq_t IntPer)
{

	NVIC->ISER[IntPer/32] |= (1 << (IntPer%32));

}
void NVIC_voidDisableNVICPerInterrupt(IntReq_t IntPer)
{

	NVIC->ICER[IntPer/32] &= ~(1 << (IntPer%32));


}
void NVIC_voidSetPendingFlag(IntReq_t IntPer)
{

	NVIC->ISPR[IntPer/32] |= (1 << (IntPer%32));


}
void NVIC_voidClearPendingFlag(IntReq_t IntPer)
{

	NVIC->ICPR[IntPer/32] &= ~(1 << (IntPer%32));


}
uint8_t NVIC_u8RaedActiveFlag(IntReq_t IntPer)
{
	u8 Copy_u8LocalGetValue;

	Copy_u8LocalGetValue = (NVIC->IABR[IntPer/32] >> (IntPer%32) & 1);

	return Copy_u8LocalGetValue;


}
uint8_t NVIC_u8SetPriority(IntReq_t IntPer,u8 Copy_u8Priority)
{
	u8 Local_ErrorState = OK;

	if(IntPer < 60)
	{
		NVIC->IPR[IntPer] = Copy_u8Priority << 4;

	}
	else
	{
		Local_ErrorState = NOK;
	}



	return Local_ErrorState;



}
