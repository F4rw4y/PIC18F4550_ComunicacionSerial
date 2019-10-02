#include <xc.h>
#include "usart_libreria.h"
#include "fuses.h"

/*Para configurar la comunicaci�n serial as�ncrona se considera
 * los siguiente pasos:
 * 
 * 1.Determinar el baudiage. Configurar SPBRGH.
 * 2.Configurar BRGH como baja o alta velocidad.(Solo en As�ncrono)
 * 3.Configurar SYNC para s�ncrono o as�ncrono.
 * 4.Habilitar Tx y Rx.
 * 5.Interrupciones.
 * 6.9 bits o no e transmision.
 * 7.Habilitar la transmisi�n.
 * 8.9 bits o no de recepcion.
 * 10.Habilitar la recepcion.
 * 
 */
 
/************* Inicializar la configuracion para la Com. As�ncrona *******************/

void USART_In(long BAUD){
    
    TRISCbits.RC6   =   0;  //Tx Salida
    TRISCbits.RC7   =   1;  //Rx Entrada
    
    SPBRG = (((_XTAL_FREQ/BAUD)/64)-1); 
    TXSTAbits.BRGH  =   0;  //Baja velocidad
    
    TXSTAbits.SYNC  =   0;  //Modo As�ncrono
    RCSTAbits.SPEN  =   1;  //Habilitar  los puertos Seriales para que
                            //trabajen como Tx y Rx
    
    TXSTAbits.TX9   =   0;  //8 bits de transmisi�n
    TXSTAbits.TXEN  =   1;  //Habilitar transmisi�n
    
    RCSTAbits.RC9   =   0;  //8 bits de recepci�n
    RCSTAbits.CREN  =   1;  //Habilitar recepci�n   
    
}

/*********** Configuraci�n Transmision de INFO ****************/

void USART_Tx(char data){
    
    TXREG   =    data;  //TXREG es el registro que almacena lo que enviaremos 
    
}

/*********** Configuraci�n Recepci�n de INFO ****************/

char USART_Rx(){
    
    return RCREG;  
    
}
