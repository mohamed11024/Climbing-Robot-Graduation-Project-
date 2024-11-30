#ifndef NRF24L01_INT_H_
#define NRF24L01_INT_H_

#include <stdint.h>


typedef enum
{
	SPI_1,
	SPI_2,
	SPI_3

}SPI_ID_t;



void NRF_voidInit(SPI_ID_t SPI_id);
uint8_t NRF_RD_CMD(SPI_ID_t SPI_id, uint8_t RegAdd);


#endif
