/*
 * eMIOSetup.c
 *
 *  Created on: Dec 31, 2015
 *      Author: Kevin
 */
#include "eMIOSetup.h"

void eMIOSinit(void)
{
	/* Alternate Function of Embedded LED Pin -> eMIOS0 PCR[71] */
	/* Alternate Function of PE[15] -> PCR[79] -> eMIOS1 channel 22 */
	SIU.PCR[110].B.OBE = 1;
	SIU.PCR[110].B.PA = 1;
	EMIOS_1.MCR.B.GPREN = 0;						/* Disable Global Prescaler*/
	EMIOS_1.CH[0].CCR.B.UCPEN = 0;					/* Disable Channel 0 Prescaler  */
	//EMIOS_1.CH[0].CADR.B.A = 32000;				/* Duty Cycle */
	//EMIOS_1.CH[0].CBDR.B.B = 64;					/* Frequency */
	EMIOS_1.CH[0].CCR.B.BSL = 3;					/* Internal counter: All channels */
	EMIOS_1.CH[0].CCR.B.MODE = 0x58;				/* OPWFMB Flags only on B1 match */
	EMIOS_1.CH[0].CCR.B.UCPRE = 0;					/* Prescaler ratio -> 1 */
	EMIOS_1.MCR.B.GPRE = 100;						/* Global Prescaler ratio -> 100 */
	EMIOS_1.CH[0].CCR.B.UCPEN = 1;					/* Channel 0 Prescaler: enabled */
	EMIOS_1.MCR.B.GPREN = 1;						/* Enable Global Prescaler*/
	EMIOS_1.MCR.B.GTBE = 1;							/* Global Time Base: enabled */
	EMIOS_1.MCR.B.MDIS = 0;
	EMIOS_1.MCR.B.FRZ = 0;
	/* Update from A0 to A1 Enabled */
	EMIOS_1.OUDR.B.OU0 = 0;


	/* Channel 0 Enabled */
	EMIOS_1.UCDIS.B.CHDIS0 = 0;

	EMIOS_1.CH[0].CCR.B.FREN = 0;					/* Freze mode disabled */
	EMIOS_1.CH[0].CCR.B.FEN = 0;					/* Disable Flags */
	EMIOS_1.CH[0].CCR.B.FORCMA = 1;				/* Force Match with Register A -> */
	EMIOS_1.CH[0].CCR.B.FORCMB = 1;				/* Force Match with Register B -> */
	EMIOS_1.CH[0].CCR.B.EDPOL = 1;					/* Edge polarity */
}


void ModuleCounter(void)
{

	/* Alternate Function of PE[0] -> PCR[64] -> eMIOS0 channel 16 */
	SIU.PCR[64].R = 0x0500;
	//SIU.PCR[64].B.IBE = 1;
	//SIU.PCR[64].B.PA = 1;
	//SIU.PCR[64].B.APC = 0;
	
	
	/* ----------------------------------------------------------- */
	/*	EMIOS Module Configuration Register (EMIOS_MCR)            */
	/* ----------------------------------------------------------- */
	EMIOS_0.MCR.R = 0x00000000;
	/* Module : Enable    */
	/* Global Freeze: Disabled                  */
	/* Global Time Base Enable: No              */
	/* Global Prescaler Enable: No              */
	/* Global Prescaler Value:   1              */

	/* ----------------------------------------------------------- */
	/* EMIOS Output Update Disable Register (EMIOS_OUDR)           */
	/* ----------------------------------------------------------- */
	EMIOS_0.OUDR.R = 0x00000000;
	/* Channel n output is Enabled  */
	/*   n = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 */

	/* ----------------------------------------------------------- */
	/* EMIOS Channel Disable Register  (EMIOS_UCDIS)           */
	/* ----------------------------------------------------------- */
	EMIOS_0.UCDIS.R = 0x00000000;
	/* Channel n is Enabled  */
	/*   n = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31, */

	/* ----------------------------------------------------------- */
	/*	Unified Channel 16 Registers                               */
	/* ----------------------------------------------------------- */
	EMIOS_0.CH[16].CADR.R = 5;
	/*  [16-31]  Channel eMIOS_0_CADR16 Data Register - eMIOS_0_CADR16 : Value = 0*/

	EMIOS_0.CH[16].CBDR.R = 0;
	/*  [16-31]  Channel eMIOS_0_CBDR16 Data Register - eMIOS_0_CBDR16 : Value = 0*/

	EMIOS_0.CH[16].CCR.R = 0x00020051;
	/* Channel Control Register                 */
	/* Freeze Enable : Normal operation         */
	/* Prescaler Divide Ratio : 1             */
	/* Prescaler Enable : Disable               */
	/* Flag generation Request: Assigned to Interrupt */
	/* Input Filter: Bypassed                   */
	/* Filter clock select : Prescaler clock    */
	/* Flag Enable : IRQ/DMA generated      */
	/* Force Match A : Disabled                 */
	/* Force Match B : Disabled                 */
	/* Bus Select : Counter bus[A]                */
	/* Edge Selection Bit :FLAG                 */
	/* Edge Polarity :Falling                   */
	/* Mode : MCB Mode                      */
	
	EMIOS_0.CH[16].CCR.B.FEN = 1;

	EMIOS_0.UCDIS.R = 0x00000000;
	/* Channel n is Enabled  */
	/*   n = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 */
}

void emiosISR(void)
{
	if(EMIOS_0.GFR.B.F16)
	{
		toggle_pin(68);
		EMIOS_0.CH[16].CSR.B.FLAG = 1;
	}
}

