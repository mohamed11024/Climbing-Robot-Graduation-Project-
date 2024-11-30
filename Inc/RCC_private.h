
/******************************************************/
/* Author    : Mohamed Kamal                          */
/* Date      : 7/9/2023                               */
/* Version   : 01                                     */
/* File      : RCC_private.h                          */
/******************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*   Register Definition    */


#define RCC_CR                              (*(u32*)0x40021000)
#define RCC_CFGR                            (*(u32*)0x40021004)
#define RCC_CIR                             (*(u32*)0x40021008)
#define RCC_APB2RSTR                        (*(u32*)0x4002100C)
#define RCC_APB1RSTR                        (*(u32*)0x40021010)
#define RCC_AHBENR                          (*(u32*)0x40021014)
#define RCC_APB2ENR                         (*(u32*)0x40021018)
#define RCC_APB1ENR                         (*(u32*)0x4002101C)
#define RCC_BDCR                            (*(u32*)0x40021020)
#define RCC_CSR                             (*(u32*)0x40021024)


/* Pins Of Register CR */
#define RCC_CR_HSION             0
#define RCC_CR_HSIRDY            1
#define RCC_CR_HSITRIM0          3
#define RCC_CR_HSITRIM1          4
#define RCC_CR_HSITRIM2          5
#define RCC_CR_HSITRIM3          6
#define RCC_CR_HSITRIM4          7

#define RCC_CR_HSICAL0           8
#define RCC_CR_HSICAL1           9
#define RCC_CR_HSICAL2           10
#define RCC_CR_HSICAL3           11
#define RCC_CR_HSICAL4           12
#define RCC_CR_HSICAL5           13
#define RCC_CR_HSICAL6           14
#define RCC_CR_HSICAL7           15

#define RCC_CR_HSEON             16
#define RCC_CR_HSERDY            17
#define RCC_CR_HSEPYB            18
#define RCC_CR_CSSON             19

#define RCC_CR_PLLON             24
#define RCC_CR_PLLRDY            25

#define RCC_CR_PLL2ON            26
#define RCC_CR_PLL2RDY           27

#define RCC_CR_PLL3ON            28
#define RCC_CR_PLL3RDY           29

/* Pins Of Register CFGR */
#define RCC_CFGR_SW0             0
#define RCC_CFGR_SW1             1   
 
#define RCC_CFGR_SWS0            2
#define RCC_CFGR_SWS1            3

#define RCC_CFGR_HPRE0           4
#define RCC_CFGR_HPRE1           5
#define RCC_CFGR_HPRE2           6
#define RCC_CFGR_HPRE3           7
 
#define RCC_CFGR_PPRE10          8
#define RCC_CFGR_PPRE11          9
#define RCC_CFGR_PPRE12          10

#define RCC_CFGR_PPRE20          11
#define RCC_CFGR_PPRE21          12
#define RCC_CFGR_PPRE22          13

#define RCC_CFGR_ADCPRE0         14
#define RCC_CFGR_ADCPRE1         15


#define RCC_CFGR_PLLSRC          16
#define RCC_CFGR_PLLXTPRE        17


#define RCC_CFGR_PLLMUL0         18
#define RCC_CFGR_PLLMUL1         19
#define RCC_CFGR_PLLMUL2         20
#define RCC_CFGR_PLLMUL3         21

#define RCC_CFGR_OTGFSPRE        22

#define RCC_CFGR_MCO0            24
#define RCC_CFGR_MCO1            25
#define RCC_CFGR_MCO2            26
#define RCC_CFGR_MCO3            27



/* Configuration System Clock */
#define HSI                          0
#define HSE                          1
#define PLL                          2


#define HSE_CRYSTAL                  0
#define HSE_BYPASS                   1



#define PLL_DIS                       0
#define PLL_EN                        1

#define PLL_input_clock_2               0
#define PLL_INPUT_CLOCK_3               1
#define PLL_INPUT_CLOCK_4               2
#define PLL_INPUT_CLOCK_5               3
#define PLL_INPUT_CLOCK_6               4
#define PLL_INPUT_CLOCK_7               5
#define PLL_INPUT_CLOCK_8               6
#define PLL_INPUT_CLOCK_9               7
#define PLL_INPUT_CLOCK_10              8
#define PLL_INPUT_CLOCK_11              9
#define PLL_INPUT_CLOCK_12              10
#define PLL_INPUT_CLOCK_13              11
#define PLL_INPUT_CLOCK_14              12
#define PLL_INPUT_CLOCK_15              13
#define PLL_INPUT_CLOCK_16              14


#define HSE_DIV_0                       0
#define HSE_DIV_2                       1


#define HSI_Div_2                                 0
#define HSE_Div_0                                 1



#endif
