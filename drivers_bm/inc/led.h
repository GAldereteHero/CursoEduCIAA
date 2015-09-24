
#ifndef LED_H
#define LED_H

# include "chip.h" // manejo la libreria del LPC open

void inicializarled(); // Llamo a las funciones que voy a utilizar
void prenderled(uint8_t cualprendo);
void apagarled(uint8_t cualapago);
void ParpadearLed(uint8_t a);

#endif /* #ifndef LED_H */
