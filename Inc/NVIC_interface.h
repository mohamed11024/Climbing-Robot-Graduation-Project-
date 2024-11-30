/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : NVIC_interface.h                       */
/******************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum
{
	NVIC_WWDG,
	NVIC_PVD,
	NVIC_TAMPER,
	NVIC_RTC,
	NVIC_FLASH,
	NVIC_RCC,
	NVIC_EXTI0,
	NVIC_EXTI1,
	NVIC_EXTI2,
	NVIC_EXTI3,
	NVIC_EXTI4,
	NVIC_DMA1_Channel1,
	NVIC_DMA1_Channel2,
	NVIC_DMA1_Channel3,
	NVIC_DMA1_Channel4,
	NVIC_DMA1_Channel5,
	NVIC_DMA1_Channel6,
	NVIC_DMA1_Channel7,
	NVIC_ADC1_2,
	NVIC_USB_HP_CAN_TX,
	NVIC_USB_LP_CAN_RX0,
	NVIC_CAN_RX1,
	NVIC_CAN_SCE,
	NVIC_EXTI9_5,
	NVIC_TIM1_BRK,
	NVIC_TIM1_UP,
	NVIC_TIM1_TRG_COM,
	NVIC_TIM1_CC,
	NVIC_TIM2,
	NVIC_TIM3,
	NVIC_TIM4,
	NVIC_I2C1_EV,
	NVIC_I2C1_ER,
	NVIC_I2C2_EV,
	NVIC_I2C2_ER,
	NVIC_SPI1,
	NVIC_SPI2,
	NVIC_USART1,
	NVIC_USART2,
	NVIC_USART3,
	NVIC_EXTI15_10,
	NVIC_RTCAlarm,
	NVIC_USBWakeup,
	NVIC_TIM8_BRK,
	NVIC_TIM8_UP,
	NVIC_TIM8_TRG_COM,
	NVIC_TIM8_CC,
	NVIC_ADC3,
	NVIC_FSMC,
	NVIC_SDIO,
	NVIC_TIM5,
	NVIC_SPI3,
	NVIC_UART4,
	NVIC_UART5,
	NVIC_TIM6,
	NVIC_TIM7,
	NVIC_DMA2_Channel1,
	NVIC_DMA2_Channel2,
	NVIC_DMA2_Channel3,
	NVIC_DMA2_Channel4_5

}IntReq_t;




void NVIC_voidEnableNVICPerInterrupt(IntReq_t IntPer);
void NVIC_voidDisableNVICPerInterrupt(IntReq_t IntPer);
void NVIC_voidSetPendingFlag(IntReq_t IntPer);
void NVIC_voidClearPendingFlag(IntReq_t IntPer);
uint8_t NVIC_u8SetPriority(u8 Copy_u8PerIndx,u8 Copy_u8Priority);

uint8_t NVIC_u8RaedActiveFlag(IntReq_t IntPer);





#endif /* NVIC_INTERFACE_H_ */
