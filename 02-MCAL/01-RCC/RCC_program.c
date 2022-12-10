/********************************************************/
/* Author      : Ali Mabrouk                            */
/* Date        : 1/12/2022                              */			
/* Version     : V.01									*/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "../include/RCC_private.H"
#include "../include/RCC_config.H"
#include "../include/RCC_interface.H"


/* Intialize System Clock */
void RCC_voidInitSysClock (void)
{
	/* Trimming */
	RCC_CR |=8<<4;	/* no Trimming*/


	/* Enable Clock */
	#if 	RCC_CLOCK_TYPE  == RCC_HSE_CRYSTAL
			SET_BIT (RCC_CR,16);		/* Enable HSE  */			
			
	#elif 	RCC_CLOCK_TYPE  == RCC_HSE_RC
			SET_BIT (RCC_CR,16);		/* Enable HSE  */
			SET_BIT (RCC_CR,18);		/* Enable By Pass */
	
	#elif 	RCC_CLOCK_TYPE  == RCC_HSI
			SET_BIT (RCC_CR,0);			/* Enable HSI  */
	
	#elif	RCC_CLOCK_TYPE  == RCC_PLL
			SET_BIT (RCC_CR,24);		/* Enable PLL */
			
	#endif
	/* PLL Configuration */ 
	
	/* Clock configuration register*/
	/* APB2 high-speed prescaler */
	#if   APB2_DIV_FACTOR    == 1
		  RCC_CFGR |= 0b000 << 13;		/* Division Factor = 1 */
	
	#elif APB2_DIV_FACTOR    == 2
		  RCC_CFGR |= 0b100 << 13;		/* Division Factor = 2 */
	
	#elif APB2_DIV_FACTOR    == 4
		  RCC_CFGR |= 0b101 << 13;		/* Division Factor = 4 */
	
	#elif APB2_DIV_FACTOR    == 8
		  RCC_CFGR |= 0b110 << 13;		/* Division Factor = 8 */
	
	#elif APB2_DIV_FACTOR    == 16
		  RCC_CFGR |= 0b111 << 13;		/* Division Factor = 16 */
	
	#endif
	
	/* APB1 Low speed prescaler */
	#if   APB1_DIV_FACTOR    == 1
		  RCC_CFGR |= 0b000 << 10;		/* Division Factor = 1 */
	
	#elif APB1_DIV_FACTOR    == 2
		  RCC_CFGR |= 0b100 << 10;		/* Division Factor = 2 */
	
	#elif APB1_DIV_FACTOR    == 4
		  RCC_CFGR |= 0b101 << 10;		/* Division Factor = 4 */
	
	#elif APB1_DIV_FACTOR    == 8
		  RCC_CFGR |= 0b110 << 10;		/* Division Factor = 8 */
	
	#elif APB1_DIV_FACTOR    == 16
		  RCC_CFGR |= 0b111 << 10;		/* Division Factor = 16 */
		  
	#endif
	/* AHB prescaler */
	#if   AHB_DIV_FACTOR     == 1
		  RCC_CFGR |= 0b0000 << 4;		/* Division Factor = 1 */
	
	#elif AHB_DIV_FACTOR     == 2
		  RCC_CFGR |= 0b1000 << 4;		/* Division Factor = 2 */
	
	#elif AHB_DIV_FACTOR     == 4
		  RCC_CFGR |= 0b1001 << 4;		/* Division Factor = 4 */
	
	#elif AHB_DIV_FACTOR     == 8
		  RCC_CFGR |= 0b1010 << 4;		/* Division Factor = 8 */
	
	#elif AHB_DIV_FACTOR     == 16
		  RCC_CFGR |= 0b1011 << 4;		/* Division Factor = 16 */
     
	#elif AHB_DIV_FACTOR     == 64
		  RCC_CFGR |= 0b1100 << 4;		/* Division Factor = 64 */
    	
    #elif AHB_DIV_FACTOR     == 128
		  RCC_CFGR |= 0b1101 << 4;		/* Division Factor = 128 */
	
	 #elif AHB_DIV_FACTOR    == 256
		  RCC_CFGR |= 0b1110 << 4;		/* Division Factor = 256 */
		  
     #elif AHB_DIV_FACTOR    == 512
		  RCC_CFGR |= 0b1111 << 4;		/* Division Factor = 512 */
		  
	#endif
		  
	
	
	/* System clock switch */
	#if 	RCC_CLOCK_TYPE  == RCC_HSI
			RCC_CFGR |=0b00;			/* Select HSI as Input System Clock */
	
	#elif	RCC_CLOCK_TYPE  == RCC_HSE_CRYSTAL || RCC_CLOCK_TYPE  == RCC_HSE_RC
			RCC_CFGR |=0b01;			/* Select HSE as Input System Clock */

	#elif	RCC_CLOCK_TYPE  == RCC_PLL
			RCC_CFGR |=0b10;			/* Select PLL as Input System Clock */
	
	#endif
}





/* Enable Peripheral Clock */
void RCC_PeripheralEnable (u8 copy_u8PeripheralName)
{
	switch (copy_u8PeripheralName)
	{

	/* Peripherals connected to AHB */
	case (RCC_GPIOA_AHB1)   : SET_BIT (RCC_AHB1ENR,0);			break;			/* Enable GPIOA   Peripheral  */
	case (RCC_GPIOB_AHB1)   : SET_BIT (RCC_AHB1ENR,1);			break;			/* Enable GPIOB   Peripheral  */
	case (RCC_GPIOC_AHB1)   : SET_BIT (RCC_AHB1ENR,2);			break;			/* Enable GPIOC   Peripheral  */
	case (RCC_GPIOD_AHB1)   : SET_BIT (RCC_AHB1ENR,3);			break;			/* Enable GPIOD   Peripheral  */
	case (RCC_GPIOE_AHB1)   : SET_BIT (RCC_AHB1ENR,4);			break;			/* Enable GPIOE   Peripheral  */
	case (RCC_GPIOH_AHB1)   : SET_BIT (RCC_AHB1ENR,7);			break;			/* Enable GPIOH   Peripheral  */
	case (RCC_CRC_AHB1)     : SET_BIT (RCC_AHB1ENR,12);			break;			/* Enable CRC     Peripheral  */
	case (RCC_DMA1_AHB1)    : SET_BIT (RCC_AHB1ENR,21);			break;			/* Enable DMA1    Peripheral  */
	case (RCC_DMA2_AHB1)    : SET_BIT (RCC_AHB1ENR,22);			break;			/* Enable DMA2    Peripheral  */
	
	/* Peripherals connected to APB1 Bus */	
	case (RCC_TIM2_APB1)    : SET_BIT (RCC_APB1ENR,0);			break;			/* Enable Timer2  Peripheral  */
	case (RCC_TIM3_APB1)    : SET_BIT (RCC_APB1ENR,1);			break;			/* Enable Timer3  Peripheral  */
	case (RCC_TIM4_APB1)    : SET_BIT (RCC_APB1ENR,2);			break;			/* Enable Timer4  Peripheral  */
	case (RCC_TIM5_APB1)    : SET_BIT (RCC_APB1ENR,3);			break;			/* Enable Timer5  Peripheral  */
	case (RCC_WWDG_APB1)    : SET_BIT (RCC_APB1ENR,4);			break;			/* Enable WWDG    Peripheral  */
	case (RCC_SPI2_APB1)    : SET_BIT (RCC_APB1ENR,7);			break;			/* Enable SPI2    Peripheral  */
	case (RCC_SPI3_APB1)    : SET_BIT (RCC_APB1ENR,12);			break;			/* Enable SPI3    Peripheral  */
	case (RCC_USART2_APB1)  : SET_BIT (RCC_APB1ENR,21);			break;			/* Enable USART2  Peripheral  */
	case (RCC_I2C1_APB1)    : SET_BIT (RCC_APB1ENR,22);			break;			/* Enable I2C1    Peripheral  */
	case (RCC_I2C2_APB1)    : SET_BIT (RCC_APB1ENR,21);			break;			/* Enable I2C2    Peripheral  */
	case (RCC_I2C3_APB1)    : SET_BIT (RCC_APB1ENR,22);			break;			/* Enable I2C3    Peripheral  */
		
	
	/* Peripherals connected to APB2 Bus */	
	
	case (RCC_TIM1_APB2)    :  SET_BIT (RCC_APB2ENR,0);			break;			/* Enable Timer2  Peripheral  */
	case (RCC_USART1_APB2)  :  SET_BIT (RCC_APB2ENR,4);			break;			/* Enable Timer3  Peripheral  */
	case (RCC_USART6_APB2)  :  SET_BIT (RCC_APB2ENR,5);			break;			/* Enable Timer4  Peripheral  */
	case (RCC_ADC1_APB2)    :  SET_BIT (RCC_APB2ENR,8);			break;			/* Enable Timer5  Peripheral  */
	case (RCC_SDIO_APB2)    :  SET_BIT (RCC_APB2ENR,11);		break;			/* Enable WWDG    Peripheral  */
	case (RCC_SPI1_APB2)    :  SET_BIT (RCC_APB2ENR,12);		break;			/* Enable SPI2    Peripheral  */
	case (RCC_SPI4_APB2)    :  SET_BIT (RCC_APB2ENR,13);		break;			/* Enable SPI3    Peripheral  */
	case (RCC_SYSCFG_APB2)  :  SET_BIT (RCC_APB2ENR,14);		break;			/* Enable USART2  Peripheral  */
	case (RCC_TIM9_APB2)    :  SET_BIT (RCC_APB2ENR,16);		break;			/* Enable I2C1    Peripheral  */
	case (RCC_TIM10_APB2)   :  SET_BIT (RCC_APB2ENR,17);		break;			/* Enable I2C2    Peripheral  */
	case (RCC_TIM11_APB2)   :  SET_BIT (RCC_APB2ENR,18);		break;			/* Enable I2C3    Peripheral  */


	}



}

/* Disable Peripheral Clock */
void RCC_PeripheralDisable (u8 copy_u8PeripheralName)
{
	switch (copy_u8PeripheralName)
	{

	/* Peripherals connected to AHB */
	case (RCC_GPIOA_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,0);		break;			/* Enable GPIOA   Peripheral  */
	case (RCC_GPIOB_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,1);		break;			/* Enable GPIOB   Peripheral  */
	case (RCC_GPIOC_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,2);		break;			/* Enable GPIOC   Peripheral  */
	case (RCC_GPIOD_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,3);		break;			/* Enable GPIOD   Peripheral  */
	case (RCC_GPIOE_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,4);		break;			/* Enable GPIOE   Peripheral  */
	case (RCC_GPIOH_AHB1)   : CLEAR_BIT (RCC_AHB1ENR,7);		break;			/* Enable GPIOH   Peripheral  */
	case (RCC_CRC_AHB1)     : CLEAR_BIT (RCC_AHB1ENR,12);		break;			/* Enable CRC     Peripheral  */
	case (RCC_DMA1_AHB1)    : CLEAR_BIT (RCC_AHB1ENR,21);		break;			/* Enable DMA1    Peripheral  */
	case (RCC_DMA2_AHB1)    : CLEAR_BIT (RCC_AHB1ENR,22);		break;			/* Enable DMA2    Peripheral  */
	
	/* Peripherals connected to APB1 Bus */
	case (RCC_TIM2_APB1)    : CLEAR_BIT (RCC_APB1ENR,0);		break;			/* Enable Timer2  Peripheral  */
	case (RCC_TIM3_APB1)    : CLEAR_BIT (RCC_APB1ENR,1);		break;			/* Enable Timer3  Peripheral  */
	case (RCC_TIM4_APB1)    : CLEAR_BIT (RCC_APB1ENR,2);		break;			/* Enable Timer4  Peripheral  */
	case (RCC_TIM5_APB1)    : CLEAR_BIT (RCC_APB1ENR,3);		break;			/* Enable Timer5  Peripheral  */
	case (RCC_WWDG_APB1)    : CLEAR_BIT (RCC_APB1ENR,4);		break;			/* Enable WWDG    Peripheral  */
	case (RCC_SPI2_APB1)    : CLEAR_BIT (RCC_APB1ENR,7);		break;			/* Enable SPI2    Peripheral  */
	case (RCC_SPI3_APB1)    : CLEAR_BIT (RCC_APB1ENR,12);		break;			/* Enable SPI3    Peripheral  */
	case (RCC_USART2_APB1)  : CLEAR_BIT (RCC_APB1ENR,21);		break;			/* Enable USART2  Peripheral  */
	case (RCC_I2C1_APB1)    : CLEAR_BIT (RCC_APB1ENR,22);		break;			/* Enable I2C1    Peripheral  */
	case (RCC_I2C2_APB1)    : CLEAR_BIT (RCC_APB1ENR,21);		break;			/* Enable I2C2    Peripheral  */
	case (RCC_I2C3_APB1)    : CLEAR_BIT (RCC_APB1ENR,22);		break;			/* Enable I2C3    Peripheral  */
	
	
	/* Peripherals connected to APB2 Bus */
	
	case (RCC_TIM1_APB2)    : CLEAR_BIT (RCC_APB2ENR,0);		break;			/* Enable Timer2  Peripheral  */
	case (RCC_USART1_APB2)  : CLEAR_BIT (RCC_APB2ENR,4);		break;			/* Enable Timer3  Peripheral  */
	case (RCC_USART6_APB2)  : CLEAR_BIT (RCC_APB2ENR,5);		break;			/* Enable Timer4  Peripheral  */
    case (RCC_ADC1_APB2)    : CLEAR_BIT (RCC_APB2ENR,8);		break;			/* Enable Timer5  Peripheral  */
    case (RCC_SDIO_APB2)    : CLEAR_BIT (RCC_APB2ENR,11);		break;			/* Enable WWDG    Peripheral  */
    case (RCC_SPI1_APB2)    : CLEAR_BIT (RCC_APB2ENR,12);		break;			/* Enable SPI2    Peripheral  */
	case (RCC_SPI4_APB2)    : CLEAR_BIT (RCC_APB2ENR,13);		break;			/* Enable SPI3    Peripheral  */
    case (RCC_SYSCFG_APB2)  : CLEAR_BIT (RCC_APB2ENR,14);		break;			/* Enable USART2  Peripheral  */
    case (RCC_TIM9_APB2)    : CLEAR_BIT (RCC_APB2ENR,16);		break;			/* Enable I2C1    Peripheral  */
    case (RCC_TIM10_APB2)   : CLEAR_BIT (RCC_APB2ENR,17);		break;			/* Enable I2C2    Peripheral  */
    case (RCC_TIM11_APB2)   : CLEAR_BIT (RCC_APB2ENR,18);		break;			/* Enable I2C3    Peripheral  */
	
}


}
