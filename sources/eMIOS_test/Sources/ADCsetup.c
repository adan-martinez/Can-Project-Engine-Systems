/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        ADCsetup.c
* Instance:        RPL_1
* version:         1.1
* created_by:      Kevin Nevárez
* date_created:    January 9 2016
*=============================================================================*/
/* DESCRIPTION : ADC module configuration and ISR function handlers           */
/*============================================================================*/
/* FUNCTION COMMENT : This file is used to configure registers provided for   */
/* ADC peripheral.                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 9/01/2016   |     Project code: created     | Kevin Nevárez    */
/*----------------------------------------------------------------------------*/
/*  1.1      | 12/01/2016  |   2 Analog channels added     |         		  */
/*           |             |   and readADC() modified:     |  Kevin Nevárez   */
/*           |             |   parameters                  |                  */
/*----------------------------------------------------------------------------*/
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "ADCsetup.h"
#include "eMIOSetup.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */


/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */



/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ADCinit
 *  Description          :	Function that configures module 
 *  						registers
 *  Parameters           :  [none]
 *  Return               :	[none]
 *  Critical/explanation :  [yes / No]
 **************************************************************/

void ADCinit(void)
{
	
	INPUT(POT_CURRENT_CONFIG);
	ANALOG_PORT(POT_CURRENT_CONFIG);
	
	/***********************************************************/
	
	INPUT(POT_DUTYCYCLE_CONFIG);
	ANALOG_PORT(POT_DUTYCYCLE_CONFIG);
	
	/***********************************************************/
	
	INPUT(POT_FREQUENCY_CONFIG);
	ANALOG_PORT(POT_FREQUENCY_CONFIG);
	
	
	ADC_0.MCR.B.PWDN = 1;							/* Power down mode: enabled */
	ADC_0.MCR.B.ABORT = 1;							/* Abort All conversion */
	
	/* Clear INTERRUPT FLAGS */
	ADC_0.ISR.R = 0x0000001F; 
	/* B27: End of CTU Conversion EOCTU Flag 						*/
	/* B28: End of Injected Channel Conversion JEOC Flag 			*/
	/* B29: End of Injected Chain Conversion interrupt JECH Flag 	*/
	/* B30: End of Channel Conversion EOC Flag 						*/
	/* B31: End of Chain Conversion ECH Flag 						*/
	
	ADC_0.MCR.R = 0x00000000;
	/* Conversion data Overwrite : Disabled */
	/* Conversion Data Aligned: Right Aligned */
	/* Conversion Mode Selected :  One Shot Mode */
	/* Normal Start conversion Disabled :- can be configured using adc_normal_Start_fnc */
	/* Injected Start conversion Disabled :- can be configured using adc_injected_Start_fnc */
	/* Injection external trigger : Configured in adc_trigger_setup_fnc */
	/* Injection trigger edge : Configured in adc_trigger_setup_fnc */
	/* Cross Triggering Unit needs to be configured after CTU initialization */
	/* ADC Conversion clock selected as :  System Clock/2 */
	/* ADCLKSEL Init needs to be done in POWER DOWN State */
	/* Abort chain Conversion Disabled can be configured using adc_abort_chain_fnc */
	/* Abort Normal Conversion Disabled can be configured using adc_normal_stop_fnc */
	/* Auto Clock Off feature: Disabled */
	/* Power Down Mode is Enabled while ADC Clock initialization */

	ADC_0.MCR.B.PWDN = 0;
	/* ADC Power down state :Disabled */
	ADC_0.PDEDR.R = 0x00000000;
	/* The Power Down Delay : 0 clock Cycle      */

	ADC_0.CTR0.R = 0x00000203;
	/* Phase duration Latch : 0 */
	/* Input Sampling Duration : 3 clock Cycles  */
	/* Input Comparison Duration : 1 clock Cycles*/
	/* Offset Shift Duration : 0 clock Cycles*/

	ADC_0.PDEDR.R = 0;
	/* The Power Down Delay : 0 clock Cycle      */

	/* Interrupts enabled */
	ADC_0.IMR.R = 0;								
	ADC_0.CIMR0.B.CIM4 = 1;			/* Interrupt for channel 4 */
	
	ADC_0.THRHLR4.B.THRH = OVER_CURRENT;
	ADC_0.THRHLR4.B.THRL = 0;
	/* Lower Threshold value : 0 */
	/* Higher Threshold value : 875 */

	
	ADC_0.CWSELR0.R = 0x00040000;
	/* Watchdog selected for channel 0 : THRHLR0*/
	/* Watchdog selected for channel 1 : THRHLR0*/
	/* Watchdog selected for channel 2 : THRHLR0*/
	/* Watchdog selected for channel 3 : THRHLR0*/
	/* Watchdog selected for channel 4 : THRHLR0*/
	/* Watchdog selected for channel 5 : THRHLR0*/
	/* Watchdog selected for channel 6 : THRHLR0*/
	/* Watchdog selected for channel 7 : THRHLR0*/
	
	ADC_0.CWSELR0.B.WSEL_CH4 = 1;
	
	
	ADC_0.CWENR0.R = 0x00000010;
	/* Watchdog enable for channel 0 : Disabled */
	/* Watchdog enable for channel 1 : Disabled */
	/* Watchdog enable for channel 2 : Disabled */
	/* Watchdog enable for channel 3 : Disabled */
	/* Watchdog enable for channel 4 : Enabled */
	/* Watchdog enable for channel 5 : Disabled */
	/* Watchdog enable for channel 6 : Disabled */
	/* Watchdog enable for channel 7 : Disabled */
	/* Watchdog enable for channel 8 : Disabled */
	/* Watchdog enable for channel 9 : Disabled */
	/* Watchdog enable for channel 10 : Disabled */
	/* Watchdog enable for channel 11 : Disabled */
	/* Watchdog enable for channel 12 : Disabled */
	/* Watchdog enable for channel 13 : Disabled */
	/* Watchdog enable for channel 14 : Disabled */
	/* Watchdog enable for channel 15 : Disabled */
	
	ADC_0.WTIMR.R = 0x00000200;
	/* Low Threshold Interrupt for Watchdog 0 : Disabled */
	/* High Threshold Interrupt for Watchdog 0 : Disabled */
	/* Low Threshold Interrupt for Watchdog 1 : Disabled */
	/* High Threshold Interrupt for Watchdog 1 : Disabled */
	/* Low Threshold Interrupt for Watchdog 2 : Disabled */
	/* High Threshold Interrupt for Watchdog 2 : Disabled */
	/* Low Threshold Interrupt for Watchdog 3 : Disabled */
	/* High Threshold Interrupt for Watchdog 3 : Disabled */
	/* Low Threshold Interrupt for Watchdog 4 : Disabled */
	/* High Threshold Interrupt for Watchdog 4 : Enabled */
	/* Low Threshold Interrupt for Watchdog 5 : Disabled */
	/* High Threshold Interrupt for Watchdog 5 : Disabled */
	
	/* Presampling: disabled */
	ADC_0.PSR0.R = 0;
	
	/* Presampling value = Vss for ADC_0 */
	ADC_0.PSCR.B.PREVAL0 = 0;
	
	ADC_0.NCMR0.B.CH4 = 1;							/* Channel 4 normal mode: enabled */
	ADC_0.NCMR0.B.CH5 = 1;
	ADC_0.NCMR0.B.CH6 = 1;
	
	ADC_0.MCR.B.ABORT = 1;							/* Abort conversion in order to start ADC usage */
	
	ADC_0.MCR.B.PWDN = 0;							/* All configurations done for power down mode */
	
	ADC_0.MCR.B.NSTART = 1;							/* Starts ADC conversion */
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	readADC
 *  Description          :	Function that initializes conversion 
 *  						and writes the data value converted 
 *  						from analog input channels on the
 *  						duty cycle and frequency registers
 *  Parameters           :  [vuint16_t * ra_frequency , vuint16_t * ra_dutycycle]
 *  Return               :	[none]
 *  Critical/explanation :  
 **************************************************************/


void readADC(void)
{
	vuint32_t val;
	/* Starts conversion */
	ADC_START;

	while( ! ADC_CONVERSION_FINISHED(POT_FREQUENCY) )
	{
		/* Wait for conversion done */
	}
	val = ((vuint32_t)((1000*(ADC0_FREQ_VALUE) >> 10 ) + 1) * 64);
	FREQUENCY_REG = (vuint16_t)val;
	EMIOS_1.CH[0].CBDR.B.B = val;
	
	ADC_START;
	while( ! ADC_CONVERSION_FINISHED(POT_DUTYCYCLE) )
	{
		/* Wait for conversion done */
	}
	val = (vuint32_t)(( FREQUENCY_REG * (ADC0_DUTYCYCLE_VALUE) >> 10 ) + 1);
	DUTYCYCLE_REG =  (vuint16_t)val;
	EMIOS_1.CH[0].CADR.B.A = val;	
	
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ADCTwdtISR
 *  Description          :	Function handler to manage analog
 *  						watchdog for ADC0 module channel 0
 *  Parameters           :  [none]
 *  Return               :	[none]
 *  Critical/explanation :  
 **************************************************************/

void ADCTwdtISR(void)
{
	set_pin( 70 , 1 );
	
	/* 				Clear FLAGS 			*/
	ADC_0.WTISR.B.WDG0H = 1;
	ADC_0.AWORR0.B.AWORR_CH0 = 1;
	/*--------------------------------------*/
}
