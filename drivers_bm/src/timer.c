#include "led.h"

int i=0;
void InicializarTimer()
{
	Chip_RIT_Init(LPC_RITIMER);
	NVIC_EnableIRQ(RITIMER_IRQn);
	Chip_RIT_SetTimerInterval(LPC_RITIMER, 250);
}

void TimerServicio(void)
{
		if(i<6)
		{
		apagarled(i);
		i++;
		prenderled(i);
		Chip_RIT_ClearInt(LPC_RITIMER);
		}
		else {i=0;}
}

int GeneroSecuencia()
{	int cualsigue=0;

	cualsigue++;

	if(cualsigue>6) {cualsigue=0;}

	return cualsigue;


}



