/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : GPIO_register.h                            */
/******************************************************/

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_

/********** BASE ADDRESSES OF GPIOS ****************/
#define GPIOA_BASE_ADDRESS                  0x40010800
#define GPIOB_BASE_ADDRESS                  0x40010C00
#define GPIOC_BASE_ADDRESS                  0x40011000


/********** REGISTERS STRUCTURE OF GPIOS ***********/
typedef struct
{
	volatile uint32_t CR[2];
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_RegDef_t;

/************* GPIOS REGISTERS DEFINITIONS ***********/
#define GPIOA                            ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                            ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                            ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)












#endif /* GPIO_REGISTER_H_ */
