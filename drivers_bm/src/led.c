

#include "led.h"

void inicializarled()

{
	Chip_GPIO_Init(LPC_GPIO_PORT);


	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); /* remapea P2_1 en GPIO5[1], LED0G y habilita el pull up */
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); /* remapea P2_2 en GPIO5[2], LED0B y habilita el pull up */
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* remapea P2_10 en GPIO0[14], LED1 y habilita el pull up */
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* remapea P2_11 en GPIO1[11], LED2 y habilita el pull up */
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* remapea P2_12 en GPIO1[12], LED3 y habilita el pull up */

	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,(1<<0)|(1<<1)|(1<<2),1); // Defino ls puertos como salidas
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1<<14),1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,(1<<11)|(1<<12),1);


	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0); // reseteo todos los leds
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1); // reseteo todos los leds
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2); // reseteo todos los leds
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14); // reseteo todos los leds
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11); // reseteo todos los leds
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,14); // reseteo todos los leds
}

void prenderled(uint8_t cualprendo) // defino la funcion para prender leds
{
	switch (cualprendo)
	{

		case 1:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,0); // seteo el led rgb rojo
					break;

		case 2:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,1); // seteo el led rgb verde
					break;

		case 3:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,2); // seteo el led rgb azul
					break;

		case 4:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,0,14); // seteo el led 1
					break;

		case 5:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,11); // seteo el led 2
					break;

		case 6:
					Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,12); // seteo el led 3
					break;

		default:

			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,0); // seteo el led rgb rojo
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,1); // seteo el led rgb verde
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,2); // seteo el led rgb azul
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,0,14); // seteo el led 1
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,11); // seteo el led 2
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,12); // seteo el led 3
			break;
	}
}



void apagarled(uint8_t cualapago)
{


	switch (cualapago)
		{

			case 1:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0); // reseteo el led rgb rojo
						break;

			case 2:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1); // reseteo el led rgb verde
						break;

			case 3:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2); // reseteo el led rgb azul
						break;

			case 4:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14); // reseteo el led 1
						break;

			case 5:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11); // reseteo el led 2
						break;

			case 6:
						Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,12); // reseteo el led 3
						break;

			default:


				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0); // reseteo el led rgb rojo
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1); // reseteo el led rgb verde
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2); // reseteo el led rgb azul
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14); // reseteo el led 1
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11); // reseteo el led 2
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,12); // reseteo el led 3
				break;



}



}

void ParpadearLed(uint8_t a)
{
	int x=1;
	do{

	uint32_t i;
	prenderled(a);
	for(i=0;i<=3000000;i++);
	apagarled(a);
	for(i=0;i<=3000000;i++);

	}while(x==1);

}









