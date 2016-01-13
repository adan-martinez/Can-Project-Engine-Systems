#include "MPC5606B.h"
#include "InitModesClocks.h"
#include "eMIOSetup.h"
#include "ADCsetup.h"
#include "PortInit.h"
#include "IntcInterrupts.h"




int main(void) {
	/* PCTL [72] -> eMIOS0 added to RUN0 */
	/* PCTL [73] -> eMIOS1 added to RUN0 */	
	/* PCTL [33] -> ADC_1 added to RUN0 */
	InitModesClocks();
	
	INTC_InitINTCInterrupts();
	
	INTC_InstallINTCInterruptHandler( emiosISR , 149 , 1 );
	INTC_InstallINTCInterruptHandler( ADCTwdtISR , 64 , 2 );
	
	INTC.CPR.R=0;
	

	boardLEDS();
	
	/* Output Pulse Width & Frequency Modulation Buffered */
	eMIOSinit();
	ModuleCounter();
	
	/* Start ADC conversion */
	ADCinit();
	
	
	
	
	for(;;)
	{
		readADC();
		//EMIOS_1.CH[0].CADR.B.A = X;
		
		if(!read_pin(70))
		{
			set_pin( 70 , 0 );
		}
		
	}
}



