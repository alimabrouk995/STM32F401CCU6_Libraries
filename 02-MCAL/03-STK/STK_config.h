/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V01                                                               */
/* Date      : 7 November 2022                                                   */
/*********************************************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/* Configure input clock source to Systick Peripheral */
/* Options:
 * 	STK_CLK_SRC_AHB
 * 	STK_CLK_SRC_AHB_8
 *
 * */
#define STK_CLK_SRC   STK_CLK_SRC_AHB_8


/* Configure Exception Request to counting down to zero */
/* Options:
 * 	STK_INT_ENABLE
 * 	STK_INT_DISABLE
 *
 * */


#define STK_INT  STK_INT_ENABLE



#endif
