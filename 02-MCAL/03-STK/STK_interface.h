/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V01                                                               */
/* Date      : 7 November 2022                                                   */
/*********************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Intialize Systick Configurations */
void MSTK_voidInit (void);

/* Systick Delay Function */
void MSTK_voidSetBusyWait (u32 Copy_u32Ticks);

/* Set Single interval function */
void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks, void (*Copy_ptr) (void));

/* Set a periodic function */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr) (void));

/* Stop Timer */
void MSTK_voidStopTimer (void);

/* Get Elapsed Time */
u32 MSTK_u32GetElapsedTime (void);

/* Get Remaining Time */
u32 MSTK_u32GetRemainingTime (void);

#endif
