#include <xc.h>
#include "usart_libreria.h"
#include "fuses.h"

/*Para configurar la comunicación serial asíncrona se considera
 * los siguiente pasos:
 * 
 * 1.Determinar el baudiage. Configurar SPBRGH.
 * 2.Configurar BRGH como baja o alta velocidad.(Solo en Asíncrono)
 * 3.Configurar SYNC para síncrono o asíncrono.
 * 4.Habilitar Tx y Rx.
 * 5.Interrupciones.
 * 6.9 bits o no e transmision.
 * 7.Habilitar la transmisión.
 * 8.9 bits o no de recepcion.
 * 10.Habilitar la recepcion.
 * 
 */
 
/************* Inicializar la configuracion para la Com. Asíncrona *******************/

void USART_In(long BAUD){
    
    TRISCbits.RC6   =   0;  //Tx Salida
    TRISCbits.RC7   =   1;  //Rx Entrada
    
    SPBRG = (((_XTAL_FREQ/BAUD)/64)-1); 
    TXSTAbits.BRGH  =   0;  //Baja velocidad
    
    TXSTAbits.SYNC  =   0;  //Modo Asíncrono
    RCSTAbits.SPEN  =   1;  //Habilitar  los puertos Seriales para que
                            //trabajen como Tx y Rx
    
    TXSTAbits.TX9   =   0;  //8 bits de transmisión
    TXSTAbits.TXEN  =   1;  //Habilitar transmisión
    
    RCSTAbits.RC9   =   0;  //8 bits de recepción
    RCSTAbits.CREN  =   1;  //Habilitar recepción   
    
}

/*********** Configuración Transmision de INFO ****************/

void USART_Tx(char data){
    
    TXREG   =    data;  //TXREG es el registro que almacena lo que enviaremos 
    
}

/*********** Configuración Recepción de INFO ****************/

char USART_Rx(){
    
    return RCREG;  
    
}
