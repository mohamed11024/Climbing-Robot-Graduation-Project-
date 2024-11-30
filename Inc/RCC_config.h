

/******************************************************/
/* Author    : MohamedKamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : RCC_config.h                           */
/******************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options:
  1- 0:HSI
  2- 1:HSE
  3- 2:PLL                   */
#define SYS_CLOCK               HSE
/* Options:
  1- 0:HSE_CRYSTAL
  2- 1:HSE_BYPASS          */
#define HSE_CLOCK_T             HSE_CRYSTAL              


 /* Options:
  1- 00000: TRIMING_VAL 0
  2- 00001: TRIMING_VAL 1
  3- 00010: TRIMING_VAL 2
  4- 00011: TRIMING_VAL 3
  5- 00100: TRIMING_VAL 4
  6- 00101: TRIMING_VAL 5
  7- 00110: TRIMING_VAL 6
  8- 00111: TRIMING_VAL 7
  9- 01000: TRIMING_VAL 8
  10-01001: TRIMING_VAL 9
  11-01010: TRIMING_VAL 10
  12-01011: TRIMING_VAL 11
  13-01100: TRIMING_VAL 12
  14-01101: TRIMING_VAL 13
  15-01110: TRIMING_VAL 14
  16-01111: TRIMING_VAL 15
  17-10000  TRIMING_VAL 16     */

#define TRIM_VALUE              16


/* Options:
  1- 0:Disabled
  2- 1:Enabled      */
#define PLL_CLOCK               PLL_DIS



 /* Options:
  1- 0000: PLL input clock x 2
  2- 0001: PLL input clock x 3
  3- 0010: PLL input clock x 4
  4- 0011: PLL input clock x 5
  5- 0100: PLL input clock x 6
  6- 0101: PLL input clock x 7
  7- 0110: PLL input clock x 8
  8- 0111: PLL input clock x 9
  9- 1000: PLL input clock x 10
  10-1001: PLL input clock x 11
  11-1010: PLL input clock x 12
  12-1011: PLL input clock x 13
  13-1100: PLL input clock x 14
  14-1101: PLL input clock x 15
  15-1110: PLL input clock x 16    */
#define PLL_MUL                 PLL_input_clock_2



 /* Options:
  1- 0: HSE clock not divided
  2- 1: HSE clock divided by 2                 */
#define PLL_PRESCALER           HSE_DIV_0
/* Options:
  1- 0: HSI oscillator clock / 2 selected as PLL input clock
  2- 1: HSE oscillator clock selected as PLL input clock        */
#define PLL_SRC                  HSE_Div_0




#endif
