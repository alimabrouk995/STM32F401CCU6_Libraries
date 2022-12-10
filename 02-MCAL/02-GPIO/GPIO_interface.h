/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V1.0                                                               */
/* Date      : 30 Novemeber 2022                                                  */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.H"

/* Pin Output Values */
#define HIGH    1
#define LOW     0

#define DEFAULT 255
/* Ports */
#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

/* Pins */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15


/* GPIO Configurations */
typedef struct
{

	u8 pin_mode;
	u8 output_type;
	u8 output_speed;
	u8 pull_type;
	u8 alternFn;



} Pinx_Config;


/* Pin Mode */
enum
{
	GPIOMode_INPUT		= 0b00,
	GPIOMode_OUTPUT     = 0b01,
	GPIOMode_AF         = 0b10,
	GPIOMode_ANALOG     = 0b11


};




/* Pin Output open-drain / push-pull configurations */
enum {

	Push_Pull  = 0b0,
	Open_Drain = 0b1,

};

/* Pin Output Speed */
enum {

	LOW_SPEED       = 0b00,
	MED_SPEED       = 0b01,
	HIGH_SPEED      = 0b10,
	VERY_HIGH_SPEED = 0b11


};

/* Pin pull-up / pull-down configurations */
enum {

	NO_PULL       = 0b00,
	PULL_UP       = 0b01,
	PULL_DOWN     = 0b10,


};

/* Pin Alternate Function */
enum {
	/* AF0 */
	AF0_SYS     = 0b0000,
	
	/* AF1 */
	AF1_TIM1    = 0b0001,
	AF1_TIM2    = 0b0001,
			   
	/* AF2 */  
	AF2_TIM3    = 0b0010,
	AF2_TIM4    = 0b0010,
	AF2_TIM5    = 0b0010,
			   
	/* AF3 */  
	AF3_TIM9    = 0b0011,
	AF3_TIM10   = 0b0011,
	AF3_TIM11   = 0b0011,
			   
	/* AF4 */  
	AF4_I2C1    = 0b0100,
	AF4_I2C2    = 0b0100,
	AF4_I2C3    = 0b0100,
			   
	/* AF5 */  
	AF5_SPI1    = 0b0101,
	AF5_SPI2    = 0b0101,
	AF5_SPI3    = 0b0101,
	AF5_SPI4    = 0b0101,
	
	/* AF6 */
	AF6_SPI3    = 0b0110,
	
	/* AF7 */
	AF7_USART1  = 0b0111,
	AF7_USART2  = 0b0111,
	
	/* AF8 */
	AF8_USART6  = 0b1000,
	
	/* AF9 */
	AF9_I2C2    = 0b1001,
	AF9_I2C3    = 0b1001,
	
	/* AF10 */
	AF10 		= 0b1010,
	
	/* AF11 */
	AF11 		= 0b1011,
	
	/* AF12 */
	AF12_SDIO   = 0b1100,
	
	/* AF13 */
	AF13 		= 0b1101,
	
	/* AF14 */
	AF14 		= 0b1110,
	
	/* AF15 */
	AF15 		= 0b1111,
	
	
};



/* Pin Value Reading  */
u8 MGPIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin);

/* Pin Value Set/Reset  */
void MGPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value );

/* Set all Pin Configuration */
void GPIOx_SetPinConfiguration (u8 copy_u8Port,u8 copy_u8Pin, Pinx_Config *ptr);

#endif
