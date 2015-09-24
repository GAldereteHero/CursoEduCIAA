
#ifndef LED_H
#define LED_H

# include "chip.h" // manejo la libreria del LPC open

void InicializaTecla(); // pongo las fns que voy a usar
void LeerTecla();
void ParpadearLed(uint8_t a);


#endif /* #ifndef LED_H */
