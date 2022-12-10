#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include "../include/STK_private.h"
#include "../include/STK_interface.h"
#include "../include/STK_config.h"


volatile u8 STK_funcInterval = 0;
void (*Callback) (void);

/* Intialize Systick Configuration */
void MSTK_voidInit (void)
{

	/* Choose Clock Source */

#if 	STK_CLK_SRC  == STK_CLK_SRC_AHB_8		/* AHB Clock Divided by 2 */
	CLEAR_BIT(STK_CTRL,2);

#elif	STK_CLK_SRC  == STK_CLK_SRC_AHB		    /* AHB Clock */

	SET_BIT(STK_CTRL,2);


#endif


}

/* Systick delay */
void MSTK_voidSetBusyWait (u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;			            /* Load Number of ticks to Preload Register */
	SET_BIT(STK_CTRL,0);				            /* Start Counter */
	while (GET_BIT(STK_CTRL,16) == 0);	            /* Wait until flag is set*/
	STK_LOAD = 0;						            /* Reset Preload Value */
	STK_VAL =0;							            /* Reset Counter Value */



}

/* Set Single interval function */
void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	STK_funcInterval = STK_SINGLE_INTERVAL;			/* Single Interval */
	STK_LOAD = Copy_u32Ticks;						/* Load Number of ticks to Preload Register */
	Callback = Copy_ptr;                    
	SET_BIT(STK_CTRL,0);							/* Start Counter */
	SET_BIT(STK_CTRL,1);							/* Enable Interrupt */



}

/* Set a periodic function */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr) (void))
{
	STK_funcInterval=STK_PERIODIC_INTERVAL;		   /* Periodic Interval */
	STK_LOAD = Copy_u32Ticks;					   /* Load Number of ticks to Preload Register */
	SET_BIT(STK_CTRL,0);						   /* Start Counter */
	Callback=Copy_ptr;                             
	SET_BIT(STK_CTRL,1);						   /* Enable Interrupt */




}

/* Stop Timer */
void MSTK_voidStopTimer (void)
{
	CLEAR_BIT(STK_CTRL,1);				/* Disable Interrupt */
	STK_LOAD = 0;						/* Write 0 to STK preload Register*/
	STK_VAL =0;							/* Write 0 to STK Value Register*/
	CLEAR_BIT(STK_CTRL,0);				/* Stop Counter */




}

/* Get Elapsed Time */
u32 MSTK_u32GetElapsedTime (void)
{

	return (STK_LOAD - STK_VAL);

}

/* Get Remaining time */
u32 MSTK_u32GetRemainingTime (void)
{

	return (STK_VAL);

}

/* Systick Handler */
void SysTick_Handler (void)
{
	u8 Local_u8Temporary;



	if (STK_funcInterval == STK_SINGLE_INTERVAL)
	{
		CLEAR_BIT(STK_CTRL,0);				/* Stop Counter */
		CLEAR_BIT(STK_CTRL,1);				/* Disable Interrupt */
		STK_LOAD = 0;						/* Write 0 to STK preload Register*/
		STK_VAL =0;							/* Write 0 to STK Value Register*/

	}

	Callback();
	Local_u8Temporary = GET_BIT(STK_CTRL,16);	/* Clear STK flag */


}
