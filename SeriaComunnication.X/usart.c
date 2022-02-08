#include "usart.h"

void internal_4( void ){
    
    PCONbits.OSCF=1;
    
}

unsigned char RX( void ){
    return RCREG;
}

void writeRXIN(volatile unsigned char a){
    RXIN = a;
}

void TX(unsigned char a){
    while(!PIR1bits.TXIF); // TXIF is usually 1, only 0 when busy transmitting
    TXREG = a;
}


void interrupt ISR( void ){
    
    if(PIE1bits.RCIE && PIR1bits.RCIF){
        while(PIR1bits.RCIF){
            writeRXIN(RX());
        }
        
        if(RCSTAbits.FERR){
            flagRXFramingError = 1;
            SPEN = 0;
            SPEN = 1;

        }
        if(RCSTAbits.OERR){
            flagRXOverrunError = 1;
            CREN = 0;
            CREN = 1;
        }
       
        
    }
    
}