/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : Sys_register.h                         */
/******************************************************/




#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_

#define SYS_BASE_ADDRESSES                           0xE000E010


typedef struct
{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;

}Sys_RegDef_t;


#define SYSTICK               ((Sys_RegDef_t*)SYS_BASE_ADDRESSES)



#endif /* SYSTICK_REGISTER_H_ */
