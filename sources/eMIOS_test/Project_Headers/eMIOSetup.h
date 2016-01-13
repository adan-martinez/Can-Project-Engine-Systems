/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        eMIOSetup.h
* Instance:         RPL_1
* version:         1.0
* created_by:      Kevin Nevárez
* date_created:    December 31 2015
*=============================================================================*/
/* DESCRIPTION : Header file to support eMIOSetup.c which includes function 
 * prototypes and global variables											  */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/12/2015  | Library creation              | Kevin Nevárez	  */
/* Integration under Continuous CM                                            */
/*============================================================================*/

#ifndef EMIOSETUP_H_
#define EMIOSETUP_H_

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

void eMIOSinit(void);

void emiosISR(void);

void ModuleCounter(void);

/* Functions macros */

#define	FREQUENCY_REG									 EMIOS_1.CH[0].CBDR.B.B 
#define	DUTYCYCLE_REG									 EMIOS_1.CH[0].CADR.B.A 

/* Exported defines */


#endif /* EMIOSETUP_H_ */
