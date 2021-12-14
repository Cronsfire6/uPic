#include "Configuracion.h"

void internal_4( void ){
    
    PCONbits.OSCF=1;
    
}

uint8_t ReadTimer0(void)
{
// Read value variable
uint8_t readVal;
// Set variable to timer0 value
readVal = TMR0;
// return value
return readVal;
}
