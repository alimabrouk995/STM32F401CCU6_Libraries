/****************************************************/
/* Author  : Ali Mabrouk                            */
/* Date    : 16/9/2022								*/
/* Version : V.01									*/
/****************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(R,N) R|=1<<N
#define CLEAR_BIT(R,N) R&=~(1<<N)
#define TOGGLE_BIT(R,N) R^=(1<<N)
#define GET_BIT(R,N) ((R&(1<<N))>>N)


#endif









