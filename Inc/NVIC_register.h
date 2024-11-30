/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : NVIC_register.h                        */
/******************************************************/


#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_

#define NVIC_BASE_ADDRESS                  0xE000E100






typedef struct
{
	uint32_t ISER[3];
	uint32_t RES0[120];
	uint32_t ICER[3];
	uint32_t RES1[120];
	uint32_t ISPR[3];
	uint32_t RES2[120];
	uint32_t ICPR[3];
	uint32_t IABR[64];
	uint8_t  IPR[84];

}NVIC_t;


#define NVIC                                               ((NVIC_t*) NVIC_BASE_ADDRESS)





#endif /* NVIC_REGISTER_H_ */
