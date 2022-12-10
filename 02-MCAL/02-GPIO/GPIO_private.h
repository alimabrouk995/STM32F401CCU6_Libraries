/*********************************************************************************/
/* Author    : Ali Mabrouk                                                       */
/* Version   : V01                                                               */
/* Date      : 7 November 2022                                                   */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA_Base_Address        0x40020000           // define the boundary address of GPIO port A
#define GPIOB_Base_Address        0x40020400           // define the boundary address of GPIO port B
#define GPIOC_Base_Address        0x40020800           // define the boundary address of GPIO port C

        /*       REGISTERS ADDRESSES FOR Port A        */

#define GPIOA_MODER                   *((u32*)(GPIOA_Base_Address + 0x00))
#define GPIOA_OTYPER                  *((u32*)(GPIOA_Base_Address + 0x04))
#define GPIOA_OSPEEDR                 *((u32*)(GPIOA_Base_Address + 0x08))
#define GPIOA_PUPDR                	  *((u32*)(GPIOA_Base_Address + 0x0c))
#define GPIOA_IDR                     *((u32*)(GPIOA_Base_Address + 0x10))
#define GPIOA_ODR                     *((u32*)(GPIOA_Base_Address + 0x14))
#define GPIOA_BSRR                    *((u32*)(GPIOA_Base_Address + 0x18))
#define GPIOA_LCKR                    *((u32*)(GPIOA_Base_Address + 0x1C))
#define GPIOA_AFRL                    *((u32*)(GPIOA_Base_Address + 0x20))
#define GPIOA_AFRH                    *((u32*)(GPIOA_Base_Address + 0x24))

        /*       REGISTERS ADDRESSES FOR Port B        */

#define GPIOB_MODER                   *((u32*)(GPIOB_Base_Address + 0x00))
#define GPIOB_OTYPER                  *((u32*)(GPIOB_Base_Address + 0x04))
#define GPIOB_OSPEEDR                 *((u32*)(GPIOB_Base_Address + 0x08))
#define GPIOB_PUPDR                	  *((u32*)(GPIOB_Base_Address + 0x0c))
#define GPIOB_IDR                     *((u32*)(GPIOB_Base_Address + 0x10))
#define GPIOB_ODR                     *((u32*)(GPIOB_Base_Address + 0x14))
#define GPIOB_BSRR                    *((u32*)(GPIOB_Base_Address + 0x18))
#define GPIOB_LCKR                    *((u32*)(GPIOB_Base_Address + 0x1C))
#define GPIOB_AFRL                    *((u32*)(GPIOB_Base_Address + 0x20))
#define GPIOB_AFRH                    *((u32*)(GPIOB_Base_Address + 0x24))

        /*       REGISTERS ADDRESSES FOR Port C        */

#define GPIOC_MODER                   *((u32*)(GPIOC_Base_Address + 0x00))
#define GPIOC_OTYPER                  *((u32*)(GPIOC_Base_Address + 0x04))
#define GPIOC_OSPEEDR                 *((u32*)(GPIOC_Base_Address + 0x08))
#define GPIOC_PUPDR                	  *((u32*)(GPIOC_Base_Address + 0x0c))
#define GPIOC_IDR                     *((u32*)(GPIOC_Base_Address + 0x10))
#define GPIOC_ODR                     *((u32*)(GPIOC_Base_Address + 0x14))
#define GPIOC_BSRR                    *((u32*)(GPIOC_Base_Address + 0x18))
#define GPIOC_LCKR                    *((u32*)(GPIOC_Base_Address + 0x1C))
#define GPIOC_AFRL                    *((u32*)(GPIOC_Base_Address + 0x20))
#define GPIOC_AFRH                    *((u32*)(GPIOC_Base_Address + 0x24))

#endif
