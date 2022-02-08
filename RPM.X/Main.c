#include "Configuracion.h"

void initMain( void ){
        
    internal_4();//Configuramos el clock interno a 4MHz
    TRISAbits.TRISA0=0;
    TRISAbits.TRISA4=1;
    CMCONbits.CM0=1;//Deshabilitamos comparadores en puerto A
    CMCONbits.CM1=1;
    CMCONbits.CM2=1;  
    PORTAbits.RA0=0;
    //Configuro TIMER0
    OPTION_REGbits.nRBPU=0;
    OPTION_REGbits.T0CS=1;
    OPTION_REGbits.T0SE=0;
    OPTION_REGbits.PSA=0;
    OPTION_REGbits.PS=000;
    //Configuro interrupcion TIMER0
    //INTCONbits.T0IE=1;
    //INTCONbits.T0IF=0;
    //INTCONbits.GIE=1;
    TMR0=0;
    
    //Configuracion de TIMER0
    
    
}

void main(void) {
    
    initMain();
    uint8_t count;
    while(1){
        
        count=ReadTimer0();
        if(count==5){
            
            PORTAbits.RA0=~PORTAbits.RA0;
            TMR0=0;
            __delay_ms(2000);
        }
    }
    return;
}
