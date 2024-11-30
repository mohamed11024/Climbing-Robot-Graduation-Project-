/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : SCB_interface.h                        */
/******************************************************/


#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_


typedef enum
{
	GROUP_4_SUB_0,
	GROUP_3_SUB_1,
	GROUP_2_SUB_2,
	GROUP_1_SUB_3,
	GROUP_0_SUB_4
}GROUOP_SUB_t;



uint8_t SCB_voidSetGroupSubPriority(GROUOP_SUB_t Prioity_Type);


#endif /* SCB_INTERFACE_H_ */
