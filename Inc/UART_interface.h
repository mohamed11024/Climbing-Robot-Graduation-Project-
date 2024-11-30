/********************************************************/ 
/* Author : Mohamed Kamal                             */
/* Date   : 24/9/2023                                   */
/* Version: 2.0                                         */
/* File   : UART_interface.h                            */
/********************************************************/ 
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum {
    UART1_CH = 0, 
    UART2_CH,
    UART3_CH,
}UART_CH;


/****************** Functions prototypes ********************/

/*************************************************************
    Function Name: UART_voidInit
    Description  : Initialize UART(s) according to config file 
    Parameters   : none
    Return value : none
***************************************************************/
void UART_voidInit();


/*************************************************************
    Function Name: UART_voidTransmitSync
    Description  : Send array of data through UART CH and halts
                   the processor till finish 
    Parameters   : cpy_ch : Specify which UART channel
                   cpy_arr: array of data to transmit
    Return value : none
***************************************************************/
void UART_voidTransmit_Sync(UART_CH cpy_ch ,uint8_t cpy_arr[] );

/*************************************************************
    Function Name: UART_u8RecieveSync
    Description  : Recieve a char of data through UART CH 
                   halt the processor till Recieve complete 
    Parameters   : cpy_ch : Specify which UART channel
    Return value : byte recieved from UART CH
***************************************************************/
uint8_t UART_u8Recieve_Sync(UART_CH cpy_ch);


/*************************************************************
    Function Name: UART_voidTransmit_Async
    Description  : Add data to transmition queue of UART CH 
    Parameters   : cpy_ch  : Specify which UART channel
                   cpy_data: data to transmit
    Return value : none
***************************************************************/
void UART_voidTransmit_Async(UART_CH cpy_ch ,uint8_t cpy_data_to_transmit  );

/*************************************************************
    Function Name: UART_u8RecieveA sync
    Description  : Store a Recieved char of data through UART CH 
                   in the data buffer 
    Parameters   : cpy_ch : Specify which UART channel
                   data_buffer: location of array to store recieved
                                data
    Return value : NONE
***************************************************************/
void UART_u8Recieve_Async(UART_CH cpy_ch ,uint8_t data_buffer[255]);


#endif // End Of File
