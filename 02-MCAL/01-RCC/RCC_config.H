/****************************************************/
/* Author  : Ali Mabrouk                            */
/* Date    : 16/9/2022								*/
/* Version : V.01									*/
/****************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
#include "RCC_private.h"


/* Configure clock type */

/* Options:
		  RCC_HSE_CRYSTAL   0
	      RCC_HSE_RC     	1    
	      RCC_HSI			2
	      RCC_PLL			3    */
#define RCC_CLOCK_TYPE  RCC_HSI

/********************************************/
/* Configure division factor for APB2 clock  */
/*
	Options: 1, 2, 4, 8, 16
	
*/

#define APB2_DIV_FACTOR  1
/********************************************/
/* Configure division factor for APB1 clock  */
/*
	Options: 1, 2, 4, 8, 16
	
*/

#define APB1_DIV_FACTOR  1
/********************************************/
/* Configure division factor for AHB clock  */
/*
	Options: 1, 2, 4, 8, 16, 64, 128, 256, 512
	
*/

#define AHB_DIV_FACTOR  2
/********************************************/




#endif





















