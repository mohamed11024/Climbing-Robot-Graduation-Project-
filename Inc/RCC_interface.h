/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : RCC_interface.h                        */
/******************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



/* Pins Of Register AHBENR */


typedef enum
{
	DMA1 = 0,
	DMA2,
	SRAM,
	FLITF = 4,
	CRCE = 6,
	FSMC = 8,
	SDIO = 10

}AHB_t;

/* Pins Of Register APB2ENR */
typedef enum
{
	AFIO = 0,
	IOPA = 2,
	IOPB,
	IOPC,
	IOPD,
	IOPE,
	IOPF,
	IOPG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART1,
	ADC3,
	TIM9 = 19,
	TIM10,
	TIM11

}APB2_t;

/* Pins Of Register APB1ENR */
typedef enum
{
	TIM2 = 0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG = 11,
	SPI2 = 14,
	SPI3,
	USART2 = 17,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	USB,
	CAN = 25,
	BKP = 27,
	PWR,
	DAC,

}APB1_t;



void RCC_voidSysInit(void);
void RCC_voidEnableAHBPer(AHB_t Peripheral);
void RCC_voidEnableAPB2Per(APB2_t Peripheral);
void RCC_voidEnableAPB1Per(APB1_t Peripheral);

void RCC_voidDisableAHBPer(AHB_t Peripheral);
void RCC_voidDisableAPB2Per(APB2_t Peripheral);
void RCC_voidDisableAPB1Per(APB1_t Peripheral);











#endif
