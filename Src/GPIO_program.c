/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : GPIO_program.c                         */
/******************************************************/

#include <stdint.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_register.h"
#include "GPIO_config.h"


static GPIO_RegDef_t* Arr_GPIO[3] = {GPIOA, GPIOB, GPIOC};

uint8_t GPIO_u8PinInit(GPIO_t* GPIO_Config)
{
	u8 Local_ErrorState = OK;
	if(GPIO_Config == NULL)
	{
		Local_ErrorState = NULL_POINTER;
	}
	else
	{
		if((GPIO_Config->Port_Type <= PORTC) && (GPIO_Config->Pin_Type <= PIN15))
		{

			/* Set Mode : Input , Output_10MHZ, Output_2MHZ, Output_50MHZ */
			Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] &= ~(0b11 << ((GPIO_Config->Pin_Type)*4));
			Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] |=  (GPIO_Config->Mode << ((GPIO_Config->Pin_Type)*4));

			if(GPIO_Config->Mode == INPUT)
			{
				Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] &= ~(0b11 << (((GPIO_Config->Pin_Type)*4)+2));
				Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] |=  (GPIO_Config->Input_Type << (((GPIO_Config->Pin_Type)*4)+2));

			}
			else if(GPIO_Config->Mode == OUTPUT_10 || GPIO_Config->Mode == OUTPUT_2 || GPIO_Config->Mode == OUTPUT_50)
			{
				Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] &= ~(0b11 << (((GPIO_Config->Pin_Type)*4)+2));
				Arr_GPIO[GPIO_Config->Port_Type]->CR[GPIO_Config->Pin_Type/8] |=  (GPIO_Config->Output_Type << (((GPIO_Config->Pin_Type)*4)+2));

			}
			else
			{
				Local_ErrorState = NOK;
			}


		}
	}



	return Local_ErrorState;
}
uint8_t GPIO_u8SetPinValue(PORT_t Port, PIN_t PinNum, VAL_t Value)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC && PinNum <= PIN15)
	{
		if(Value == HIGh)
		{
			Arr_GPIO[Port]->BSRR = 1 << PinNum;

		}
		else if(Value == LOW)
		{
			Arr_GPIO[Port]->BRR = (1 << PinNum );
		}
		else
		{
			Local_ErrorState = NOK;

		}

	}
	else
	{
		Local_ErrorState = NOK;

	}


	return Local_ErrorState;



}
uint8_t GPIO_u8TogglePortPinValue(PORT_t Port, PIN_t PinNum, VAL_t Value)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC && PinNum <= PIN15)
	{
		Arr_GPIO[Port]->ODR ^= 1 << PinNum;

	}
	else
	{
		Local_ErrorState = NOK;

	}




	return Local_ErrorState;





}
uint8_t GPIO_u8GetPinValue(PORT_t Port, PIN_t PinNum, VAL_t* Value)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC && PinNum <= PIN15)
	{
		*Value = ((Arr_GPIO[Port]->IDR >> PinNum) & 1);

	}
	else
	{
		Local_ErrorState = NOK;

	}




	return Local_ErrorState;


}





uint8_t GPIO_u8SetPortValue(PORT_t Port,VAL_t Value)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC)
	{
		if(Value == HIGh)
		{
			Arr_GPIO[Port]->ODR = 0xffff;
		}
		else if(Value == LOW)
		{
			Arr_GPIO[Port]->ODR = 0x0000;
		}
		else
		{
			Local_ErrorState = NOK;
		}
	}
	else
	{
		Local_ErrorState = NOK;

	}



	return Local_ErrorState;

}

uint8_t GPIO_u8LockPinMode(PORT_t Port, PIN_t PinNum)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC && PinNum <= PIN15)
	{
		Arr_GPIO[Port]->LCKR |= (1<<PinNum);

	}
	else
	{
		Local_ErrorState = NOK;

	}

	return Local_ErrorState;

}

uint8_t GPIO_u8LockPortMode(PORT_t Port)
{
	u8 Local_ErrorState = OK;
	if(Port <= PORTC)
	{
		Arr_GPIO[Port]->LCKR = 0x00010000;
	}
	else
	{
		Local_ErrorState = NOK;

	}

	return Local_ErrorState;

}

