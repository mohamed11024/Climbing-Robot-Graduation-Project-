
/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : RCC_program.c                          */
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSysInit(void)
{


#if SYS_CLOCK == HSI
	/* Set Trimming System to Adjust HSI  */
	RCC_CR &= ~(0b11111 << 3);
	RCC_CR |=  (TRIM_VALUE << 3);

	/* Polling Until Flag is Set (By Hardware) */
	while(GET_BIT(RCC_CR,RCC_CR_HSIRDY) == 0);
	/* Enable HSI Clock */
	RCC_CR |= 1 << RCC_CR_HSION;
	/* Enable HSI Clock As a System Clock */
	RCC_CFGR &= ~(0b11 << RCC_CFGR_SW0);
	RCC_CFGR |=  (HSI << RCC_CFGR_SW0);


#elif SYS_CLOCK == HSE
#if  HSE_CLOCK_T == HSE_CRYSTAL

	/* Polling Until Flag is Set (By Hardware) */
	while(GET_BIT(RCC_CR,RCC_CR_HSERDY) == 0);
	/* Enable HSI Clock */
	RCC_CR |= 1 << RCC_CR_HSEON;
	/* Enable HSE Clock As a System Clock */
	RCC_CFGR &= ~(0b11 << RCC_CFGR_SW0);
	RCC_CFGR |=  (HSE << RCC_CFGR_SW0);

	/* Enable Clock Security System  */
    SET_BIT (RCC_CR , RCC_CR_CSSON);

#elif HSE_CLOCK_T == HSE_BYPASS
	/* Polling Until Flag is Set (By Hardware) */
	while(GET_BIT(RCC_CR,RCC_CR_HSERDY) == 0);
	/* Enable HSI Clock */
	RCC_CR |= 1 << RCC_CR_HSEON;
	/* Enable HSE Clock As a System Clock */
	RCC_CFGR &= ~(0b11 << RCC_CFGR_SW0);
	RCC_CFGR |=  (HSE << RCC_CFGR_SW0);
	/* Enable HSE Clock As a RC */
	RCC_CR |= 1 << RCC_CR_HSEBYP;
	/* Enable Clock Security System  */
    SET_BIT (RCC_CR , RCC_CR_CSSON);

#endif


#endif


#if PLL_CLOCK == PLL_EN
	/* Set Multiplier of the PLL clock that enter to the system */
	RCC_CFGR &= ~(0b1111 << RCC_CFGR_PLLMUL0);
	RCC_CFGR |= (PLL_MUL << RCC_CFGR_PLLMUL0);

	/* Set Prescaler of the PLL clock */
	RCC_CFGR &= ~(0b1 << RCC_CFGR_PLLXTPRE);
	RCC_CFGR |= (PLL_PRESCALER << RCC_CFGR_PLLXTPRE);
	/* Select input Clock of the PLL */
	RCC_CFGR &= ~(0b1 << RCC_CFGR_PLLSRC);
	RCC_CFGR |=  (PLL_SRC << RCC_CFGR_PLLSRC);


	/* Enable PLL Clock */
	RCC_CR |= 1 << RCC_CR_PLLON;
	/* Polling Until Flag is Cleared (By Hardware) */
	while(GET_BIT(RCC_CR,RCC_CR_PLLRDY) == 0);
	/* Enable PLL Clock As a System Clock */
	RCC_CFGR &= ~(0b11 << RCC_CFGR_SW0);
	RCC_CFGR |=  (PLL << RCC_CFGR_SW0);



#endif

}


void RCC_voidEnableAHBPer(AHB_t Peripheral)
{

	RCC_AHBENR |= 1 << Peripheral;

}
void RCC_voidEnableAPB2Per(APB2_t Peripheral)
{

	RCC_APB2ENR |= 1 << Peripheral;

}
void RCC_voidEnableAPB1Per(APB1_t Peripheral)
{

	RCC_APB1ENR |= 1 << Peripheral;

}

void RCC_voidDisableAHBPer(AHB_t Peripheral)
{

	RCC_AHBENR &= ~(1 << (Peripheral));

}
void RCC_voidDisableAPB2Per(APB2_t Peripheral)
{

	RCC_APB2ENR &= ~(1 << (Peripheral));

}
void RCC_voidDisableAPB1Per(APB1_t Peripheral)
{

	RCC_APB1ENR &= ~(1 << (Peripheral));

}


