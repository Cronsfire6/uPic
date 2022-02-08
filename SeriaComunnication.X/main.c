#include "usart.h"

void initMain( void ){
    
    internal_4();
    CMCONbits.CM0=1;//Deshabilitamos comparadores en puerto A
    CMCONbits.CM1=1;
    CMCONbits.CM2=1;  
    TRISBbits.TRISB1=1;
    TRISBbits.TRISB2=1;
    TRISAbits.TRISA0=0;
    PORTAbits.RA0=0;
    //TXSTA register
    TXSTAbits.TX9=0;//8 bits de transmision
    TXSTAbits.TXEN=1;//Transmited enabled
    TXSTAbits.SYNC=0;//Asincronyc mode
    TXSTAbits.BRGH=1;//High speed
    //RCSTA register
    RCSTAbits.SPEN=1;//Serial port enabled
    RCSTAbits.RX9=0;//8 receiver bits
    RCSTAbits.CREN=1;//Continuos receiver
    //SPBRG register
    SPBRG=25;//Baudrate 9600
    //Configuration of TX and RX interrupt
    
    PIE1bits.TXIE=0;//USART transmiter interrupt disabled
    PIR1bits.RCIF=0;//USART receiver flag interrupt
    PIR1bits.TXIF=0;//USART transmiter flag interrupt
    PIE1bits.RCIE=1;//USART receive interrupt enable
    INTCONbits.PEIE=1;//Enable peripheral interrupts
    INTCONbits.GIE=1;//Enable Global interrupt
    
}

/*
char UART_RxChar( void )
{
    //while(PIR1bits.RCIF==0);    // Wait till the data is received 
    PIR1bits.RCIF=0;            // Clear receiver flag
    return(RCREG);     // Return the received data to calling function
}
*/
void main( void )
{
    initMain();
    //char i,a[]={"Daniel Rios"};
    //char ch;

    //uart_init(9600);          //Initialize the UART module with 9600 baud rate
    while(1)
    {
        if(RXIN>0){
            __delay_ms(500);
            PORTAbits.RA0=~PORTAbits.RA0;
            TX(RXIN);
            __delay_ms(500);
            RXIN--;
        }
    }
       // ch = UART_RxChar(); // Receive a char from serial port
       // UART_TxChar(ch);    // Transmit the received char
 
}
