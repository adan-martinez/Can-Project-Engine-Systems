/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:       ADCsetup.h
* Instance:        RPL_1
* version:         1.1
* created_by:      Kevin Nevárez
* date_created:    January 5 2016
*=============================================================================*/
/* DESCRIPTION : Header file for ADC module                                   */
/*============================================================================*/
/* FUNCTION COMMENT : contains defines and macros relative to the project in  */
/* in ADC usage and provides methods to manage ADC functionalities and ISR's  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 05/01/2016  | Library created               | Kevin Nevárez	  */
/*----------------------------------------------------------------------------*/
/*  1.1		 | 11/0172016  | Ddefines and macros added     | Kevin Nevárez	  */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef ADCSETUP_H_
#define ADCSETUP_H_

/* Includes */
/* -------- */

#include "MPC5606B.h"
#include "PortInit.h"


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */

void ADCTwdtISR(void);

void ADCinit(void);

void readADC(void);

/* Functions macros */

#define ADC0_FREQ_VALUE							(ADC_0.CDR[6].B.CDATA)
#define ADC0_DUTYCYCLE_VALUE					(ADC_0.CDR[5].B.CDATA)
#define ADC_CONVERSION_FINISHED(channel)		(ADC_0.CDR[channel].B.VALID)
#define ADC_START								(ADC_0.MCR.B.NSTART = 1)
#define ANALOG_PORT(CHANNEL)					(SIU.PCR[CHANNEL].B.APC = 1)
#define INPUT(CHANNEL)							(SIU.PCR[CHANNEL].B.IBE = 1)

/* Exported defines */

#define OVER_CURRENT							(875)
#define POT_CURRENT								(4)
#define POT_DUTYCYCLE							(5)
#define POT_FREQUENCY							(6)
#define POT_CURRENT_CONFIG						(48)
#define POT_DUTYCYCLE_CONFIG					(49)
#define POT_FREQUENCY_CONFIG					(50)

#endif /* ADCSETUP_H_ */
