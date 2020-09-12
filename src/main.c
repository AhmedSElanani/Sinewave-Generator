/*
 * main.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Ahmed Salah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DAC_interface.h"

#include "SineWave.h"

#define SAMPLE_RATE_1		(4000UL)		//Gives frequency of 	(250  Hz)
#define SAMPLE_RATE_2		(8000UL)		//Gives frequency of 	(500  Hz)
#define SAMPLE_RATE_3		(16125UL)		//Gives frequency about (1008 Hz)
#define SAMPLE_RATE_4		(20000UL)		//Gives frequency of 	(1250 Hz)


int main (void)
{
	MRCC_voidInitSysClock ();
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPAEN);
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPBEN);

	HDAC_voidInit ();

	while(1)
	{
		u16 count = 0;
		while(count < 5000)
		{
			if( HDAC_voidPlay_Audiofile (SineWave, SINEWAVE_LEN, SAMPLE_RATE_1) == 1)
			{
				count++;
			}
		}

		count = 0;

		while(count < 5000)
		{
			if( HDAC_voidPlay_Audiofile (SineWave, SINEWAVE_LEN, SAMPLE_RATE_2) == 1)
			{
				count++;
			}
		}

		count = 0;

		while(count < 5000)
		{
			if( HDAC_voidPlay_Audiofile (SineWave, SINEWAVE_LEN, SAMPLE_RATE_3) == 1)
			{
				count++;
			}
		}

		count = 0;

		while(count < 5000)
		{
			if( HDAC_voidPlay_Audiofile (SineWave, SINEWAVE_LEN, SAMPLE_RATE_4) == 1)
			{
				count++;
			}
		}
	}
}
