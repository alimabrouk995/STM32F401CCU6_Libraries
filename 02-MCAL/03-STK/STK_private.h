/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V01                                                               */
/* Date      : 7 November 2022                                                   */
/*********************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


/* Registers definitions */

 /* SYSTICK REGISTER BASE ADDRESS  0xE000E010 */
#define STK_BASE_ADDRESS  0xE000E010

#define STK_CTRL  *((volatile u32*) (STK_BASE_ADDRESS + 0x00) )	/* Systick Control Register*/
#define STK_LOAD  *((volatile u32*) (STK_BASE_ADDRESS + 0x04) )	/* Systick Preload Register*/
#define STK_VAL   *((volatile u32*) (STK_BASE_ADDRESS + 0x08) )	/* Systick Value  Register*/
#define STK_CALIB *((volatile u32*) (STK_BASE_ADDRESS + 0x0C) )	/* Calibration Register*/



/* Input Clock to Systick Peripheral options */

#define STK_CLK_SRC_AHB			0
#define STK_CLK_SRC_AHB_8		1



/* Interrupt Options to Systick   hint: if count down to zero exception is requested */

#define STK_INT_ENABLE			0
#define STK_INT_DISABLE			1


/* Options for Single / Periodic Interval,  */
#define STK_SINGLE_INTERVAL       0
#define STK_PERIODIC_INTERVAL     1


#endif
