/****************************************************/
/* Author  : Ali Mabrouk                            */
/* Date    : 16/9/2022								*/
/* Version : V.01									*/
/****************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

/* Peripherals */
enum
{
	/* Peripherals connected to AHB Bus */
	RCC_GPIOA_AHB1=0,  /* GPIOA      */
	RCC_GPIOB_AHB1,    /* GPIOB      */
	RCC_GPIOC_AHB1,    /* GPIOC      */
	RCC_GPIOD_AHB1,    /* GPIOD      */
	RCC_GPIOE_AHB1,    /* GPIOE      */
	RCC_GPIOH_AHB1,    /* GPIOH      */
	RCC_CRC_AHB1,      /* CRC        */
	RCC_DMA1_AHB1,     /* DMA1       */
	RCC_DMA2_AHB1,     /* DMA2       */

	/* Peripherals connected to APB1 Bus */
	RCC_TIM2_APB1,      /* TIMER2    */
	RCC_TIM3_APB1,      /* TIMER3    */
	RCC_TIM4_APB1,      /* TIMER4    */
	RCC_TIM5_APB1,      /* TIMER5    */
	RCC_WWDG_APB1,      /* WWDG      */
	RCC_SPI2_APB1,      /* SPI2      */
	RCC_SPI3_APB1,      /* SPI3      */
	RCC_USART2_APB1,    /* USART2    */
	RCC_I2C1_APB1,      /* I2C1      */
	RCC_I2C2_APB1,		/* I2C2      */
	RCC_I2C3_APB1,		/* I2C3      */

	/* Peripherals connected to APB2 Bus */
	RCC_TIM1_APB2,       /* TIMER1   */
	RCC_USART1_APB2,     /* USART1   */
	RCC_USART6_APB2,     /* USART6   */
	RCC_ADC1_APB2,       /* ADC1     */
	RCC_SDIO_APB2,       /* SDIO     */
	RCC_SPI1_APB2,       /* SPI1     */
	RCC_SPI4_APB2,       /* SPI4     */
	RCC_SYSCFG_APB2,     /* SYSCFG   */
	RCC_TIM9_APB2,       /* TIMER9   */
	RCC_TIM10_APB2,      /* TIMER10  */
	RCC_TIM11_APB2       /* TIMER11  */

};


/* Intialize System Clock */
void RCC_voidInitSysClock (void);

/* Enable Peripheral Clock */
void RCC_PeripheralEnable (u8 copy_u8PeripheralName);

/* Disable Peripheral Clock */
void RCC_PeripheralDisable (u8 copy_u8PeripheralName);


#endif




