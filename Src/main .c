/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "App.h"
#include "02-MCAL/07-UART/UART_interface.h"

u8 switch_right_up_close    = 0;
u8 switch_left_up_close     = 0;
u8 switch_right_down_close  = 0;
u8 switch_left_down_close   = 0;
u8 switch_right_up_open     = 0;
u8 switch_left_up_open      = 0;
u8 switch_right_down_open   = 0;
u8 switch_left_down_open    = 0;

u8 switch_move_up_open      = 0;
u8 switch_move_down_close   = 0;

#define OpenRobot  5
#define CloseRobot 6
#define UpRobot    7
#define DownRobot  8
#define StopRobot  9

Robot_voidInit();
UART_voidinit();
int main(void)
{

    while(1)
    {
    	switch_right_up_close    = GPIO_u8GetPinValue(GPIOC,PIN13);
    	switch_left_up_close     = GPIO_u8GetPinValue(GPIOC,PIN14);
    	switch_right_down_close  = GPIO_u8GetPinValue(GPIOC,PIN15);
    	switch_left_down_close   = GPIO_u8GetPinValue(GPIOA,PIN0) ;
    	switch_right_up_open     = GPIO_u8GetPinValue(GPIOA,PIN1) ;
    	switch_left_up_open      = GPIO_u8GetPinValue(GPIOA,PIN2) ;
    	switch_right_down_open   = GPIO_u8GetPinValue(GPIOA,PIN3) ;
    	switch_left_down_open    = GPIO_u8GetPinValue(GPIOA,PIN4) ;

    	switch_move_up_open      = GPIO_u8GetPinValue(GPIOA,PIN5) ;
    	switch_move_down_close   = GPIO_u8GetPinValue(GPIOA,PIN6) ;
		u32 GetMsg = UART_u32ReceiveMsg ;

		switch(GetMsg)
		{
			case OpenRobot  : Robot_voidOpenGripers();  break;
			case CloseRobot : Robot_voidCloseGripers(); break;
			case UpRobot    : Robot_voidMoveUp();       break;
			case DownRobot  : Robot_voidMoveDown();     break;
			case StopRobot  : Robot_voidInit();         break;
		}


    }
    return 0;
}

