/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : SCB_program.c                          */
/******************************************************/

#include <stdint.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"
#include "SCB_register.h"




uint8_t SCB_voidSetGroupSubPriority(GROUOP_SUB_t Prioity_Type)
{
	u8 LocalErrorState = OK;

		switch(Prioity_Type)
		{
			case GROUP_0_SUB_4: SCB_AIRCR = 0x05FA0300 ;break;
			case GROUP_1_SUB_3: SCB_AIRCR = 0x05FA0400 ;break;
			case GROUP_2_SUB_2: SCB_AIRCR = 0x05FA0500 ;break;
			case GROUP_3_SUB_1: SCB_AIRCR = 0x05FA0600 ;break;
			case GROUP_4_SUB_0: SCB_AIRCR = 0x05FA0700 ;break;
			default: LocalErrorState = NOK ;break;

		}




	return LocalErrorState;



}
