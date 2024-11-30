/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : GPIO_interface.h                            */
/******************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

typedef enum
{
	INPUT,
	OUTPUT_10,
	OUTPUT_2,
	OUTPUT_50
}MODE_t;


typedef enum
{
	INPUT_ANALOG,
	INPUT_FLOATING,
	INPUT_PULLUP_PULLDOWN,

}INPUT_t;

typedef enum
{
	OUTPUT_PUSH_PULL,
	OUTPUT_OPEN_DRAIN,
	OUTPUT_AF_PUSH_PULL,
	OUTPUT_AF_OPEN_DRAIN,


}OUTPUT_t;

typedef enum
{
	PORTA,
	PORTB,
	PORTC

}PORT_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,

}PIN_t;

typedef enum
{
	LOW,
	HIGh
}VAL_t;


typedef struct
{
	MODE_t Mode;
	INPUT_t Input_Type;
	OUTPUT_t Output_Type;
	PORT_t Port_Type;
	PIN_t Pin_Type;

}GPIO_t;


uint8_t GPIO_u8PinInit(GPIO_t* GPIO_Config);
uint8_t GPIO_u8SetPinValue(PORT_t Port, PIN_t PinNum, VAL_t Value);
uint8_t GPIO_u8TogglePortPinValue(PORT_t Port, PIN_t PinNum, VAL_t Value);
uint8_t GPIO_u8GetPinValue(PORT_t Port, PIN_t PinNum, VAL_t* Value);

uint8_t GPIO_u8SetPortValue(PORT_t Port,VAL_t Value);

uint8_t GPIO_u8LockPinMode(PORT_t Port, PIN_t PinNum);

uint8_t GPIO_u8LockPortMode(PORT_t Port);




#endif /* GPIO_REGISTER_H_ */
