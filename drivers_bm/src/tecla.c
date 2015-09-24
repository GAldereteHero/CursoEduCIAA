
#include "tecla.h"
#include "led.h"

void InicializaTecla()
{

		Chip_GPIO_Init(LPC_GPIO_PORT);


		Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_0 en GPIO0[4], Tecla 1 y habilita el pull up*/
		Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_1 en GPIO0[8], Tecla 2 y habilita el pull up */
		Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_2 en GPIO0[9], Tecla 3 y habilita el pull up */
		Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_6 en GPIO1[9], LED1 y habilita el pull up */


		Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1<<4),0); // Defino las teclas como entradas
		Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1<<8),0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1<<9),0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT,1,(1<<9),0);
}



void LeerTecla()
{
	//int d,f,g,h;
	//d=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4);
	//f=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8);
	//g=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9);
	//h=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9);
	do
	{

	if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4)){ParpadearLed(1);}
	if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8)){ParpadearLed(4);}
	if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9)){ParpadearLed(5);}
	if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9)){ParpadearLed(6);}

	}while(1);
}



