/*
 * PortInit.c
 *
 *  Created on: Nov 3, 2015
 *      Author: Kevin
 */

#include "PortInit.h"

void GPIOport( vuint8_t PCR_ch )
{
	SIU.PCR[PCR_ch].B.PA = 0;
}


void GPIO_out( vuint8_t PCR_ch )
{
	SIU.PCR[PCR_ch].B.OBE = 1;
}



void GPIO_in( vuint8_t PCR_ch )
{
	SIU.PCR[PCR_ch].B.IBE = 1;
}



void set_pin( vuint8_t PCR_ch , vuint8_t value )
{
	SIU.GPDO[PCR_ch].B.PDO = value;
}



vuint8_t read_pin( vuint8_t PCR_ch )
{
	return SIU.GPDI[PCR_ch].B.PDI;
}

void toggle_pin( vuint8_t PCR_ch )
{
	SIU.GPDO[PCR_ch].B.PDO ^= 1;
}

void boardLEDS(void)
{
	GPIOport(68);
	GPIOport(69);
	GPIOport(70);
	GPIOport(71);
	
	GPIO_out(68);
	GPIO_out(69);
	GPIO_out(70);
	GPIO_out(71);
	
	set_pin(68,0);
	set_pin(69,0);
	set_pin(70,0);
	set_pin(71,0);
}


void boardButtons(void)
{
	GPIOport(64);
	GPIOport(65);
	GPIOport(66);
	GPIOport(67);

	GPIO_in(64);
	GPIO_in(65);
	GPIO_in(66);
	GPIO_in(67);
}

void LEDbarInit(void)
{
	GPIOport(0);
	GPIOport(1);
	GPIOport(2);
	GPIOport(3);
	GPIOport(4);
	GPIOport(5);
	GPIOport(6);
	GPIOport(7);
	GPIOport(8);
	GPIOport(9);

	GPIO_out(0);
	GPIO_out(1);
	GPIO_out(2);
	GPIO_out(3);
	GPIO_out(4);
	GPIO_out(5);
	GPIO_out(6);
	GPIO_out(7);
	GPIO_out(8);
	GPIO_out(9);

}
