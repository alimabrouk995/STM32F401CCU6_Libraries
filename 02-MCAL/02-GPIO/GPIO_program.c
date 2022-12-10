/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V01                                                               */
/* Date      : 7 November 2022                                                   */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"
#include "../include/GPIO_interface.h"


/* Functions Prototypes */

/* Pin Mode */
static void GPIOx_voidSetMode(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinMode);

/* Pin Output Type */
static void GPIOx_voidSetOutputType (u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8OutputType);

/* Pin Output Speed  */
static void GPIOx_voidSetOutputSpeed(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8OutputSpeed);

/* Pin Pull-up/down selection  */
static void GPIOx_voidSetPullType (u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PullType);

/* Pin Alternate Function selection  */
static void GPIOx_voidSetPinAltFn(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8AltFnType);

/* Set all Pin Configuration */

void GPIOx_SetPinConfiguration (u8 copy_u8Port,u8 copy_u8Pin, Pinx_Config *ptr)
{
	/* Pin Mode */
	GPIOx_voidSetMode(copy_u8Port,copy_u8Pin,ptr->pin_mode);
	
	/* Pin Output Type */
	GPIOx_voidSetOutputType(copy_u8Port,copy_u8Pin,ptr->output_type);
	
	/* Pin Output Speed */
	GPIOx_voidSetOutputSpeed(copy_u8Port,copy_u8Pin,ptr->output_speed);
	
	/* Pin Pull-up/down */
	GPIOx_voidSetPullType(copy_u8Port,copy_u8Pin,ptr->pull_type);
	
	/* Pin Alternate Function */
	GPIOx_voidSetPinAltFn(copy_u8Port,copy_u8Pin,ptr->alternFn);
	
	
}





/* Pin Mode */
static void GPIOx_voidSetMode(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinMode)
{
	switch (copy_u8Port)
	{
		/* Port A */
		case GPIOA :
			GPIOA_MODER |= (copy_u8PinMode << (copy_u8Pin*2));break;
		
		/* Port B */		
		case GPIOB :
			GPIOB_MODER |= (copy_u8PinMode << (copy_u8Pin*2));break;
		 
		 /* Port C */
		case GPIOC :	
			GPIOC_MODER |= (copy_u8PinMode << (copy_u8Pin*2));break;
		
		
	}
	
}

/* Pin Output Type */
static void GPIOx_voidSetOutputType (u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8OutputType)
{
	
	switch (copy_u8Port)
	{
		/* Port A */
		case GPIOA :
			GPIOA_OTYPER |= (copy_u8OutputType << copy_u8Pin);break;
		
		/* Port B */		
		case GPIOB :
			GPIOB_OTYPER |= (copy_u8OutputType << copy_u8Pin);break;
		 
		 /* Port C */
		case GPIOC :	
			GPIOC_OTYPER |= (copy_u8OutputType << copy_u8Pin);break;
		
		
	}
	

}

/* Pin Output Speed  */
static void GPIOx_voidSetOutputSpeed(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8OutputSpeed)
{
	
	switch (copy_u8Port)
	{
		/* Port A */
		case GPIOA :
			GPIOA_OSPEEDR |= (copy_u8OutputSpeed << (copy_u8Pin*2));break;
		
		/* Port B */		
		case GPIOB :
			GPIOB_OSPEEDR |= (copy_u8OutputSpeed << (copy_u8Pin*2));break;
		 
		 /* Port C */
		case GPIOC :	
			GPIOC_OSPEEDR |= (copy_u8OutputSpeed << (copy_u8Pin*2));break;
		
		
	}
	
	
}

/* Pin Pull-up/down selection  */
static void GPIOx_voidSetPullType (u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PullType)
{
	
	switch (copy_u8Port)
	{
		/* Port A */
		case GPIOA :
			GPIOA_PUPDR |= (copy_u8PullType << (copy_u8Pin*2));break;
		
		/* Port B */		
		case GPIOB :
			GPIOB_PUPDR |= (copy_u8PullType << (copy_u8Pin*2));break;
		 
		 /* Port C */
		case GPIOC :	
			GPIOC_PUPDR |= (copy_u8PullType << (copy_u8Pin*2));break;
		
		
	}
	
}



/* Pin Alternate Function selection  */
static void GPIOx_voidSetPinAltFn(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8AltFnType)
{
	if (copy_u8Pin <=PIN7)
	{
		switch (copy_u8Port)
	{
		/* Port A */
		case GPIOA :
			GPIOA_AFRL |= (copy_u8AltFnType << (copy_u8Pin*4));break;
		
		/* Port B */		
		case GPIOB :
			GPIOA_AFRL |= (copy_u8AltFnType << (copy_u8Pin*4));break;
		 
		 /* Port C */
		case GPIOC :	
			GPIOA_AFRL |= (copy_u8AltFnType << (copy_u8Pin*4));break;
		
		
	}
		
		
		
	}
	
	else if (copy_u8Pin >=PIN8 && copy_u8Pin <=PIN15)
		{
			switch (copy_u8Port)
			{
			/* Port A */
			case GPIOA :
				GPIOA_AFRH |= (copy_u8AltFnType << ((copy_u8Pin-8)*4));	break;
		
			/* Port B */		
			case GPIOB :
				GPIOA_AFRH |= (copy_u8AltFnType << ((copy_u8Pin-8)*4));	break;
			
			/* Port C */
			case GPIOC :	
				GPIOA_AFRH |= (copy_u8AltFnType << ((copy_u8Pin-8)*4));	break;
		
		
			}
		
		
		
	}
	
	
	
	
}



/* Pin Value Set/Reset  */

void MGPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOA_ODR , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT(  GPIOA_ODR , Copy_u8Pin );
		}
		break;

	case GPIOB:
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOB_ODR  , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		break;

	case GPIOC:
		if( Copy_u8Value == HIGH ){

			SET_BIT( GPIOC_ODR , Copy_u8Pin );

		}else if( Copy_u8Value == LOW ){
			CLEAR_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		break;

	}

}


/* Pin Value Reading  */
u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

