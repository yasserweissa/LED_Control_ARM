/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*   FILE NAME					:  TIMER_program.c
 *   BRIEF DESCRIPTION	:  Implementation of TIMER_interface.h
 *   AUTHOR							:  Yasser Waleed  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM.h"
#include "TIMER_interface.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void TIMER_Init(ClockSource_t Clock_Source)
{
	SysTick->LOAD = CLOCK_FREQUENCY - 1 ;	// one second delay
	SysTick->CTRL |= 1;	// Enable counter (bit 0) 
	SysTick->VAL  = 0; // Initialize current value register 
	
	//select clock source (bit 2)
	switch(Clock_Source)
	{
		case SYSCLOCK			: SysTick->CTRL |= 4	; break;
		case PIOSC				: SysTick->CTRL &=~ 4	; break;
	}   
}
/**********************************************************************************************************************
 *  END OF FILE: TIMER_program.c
 *********************************************************************************************************************/
