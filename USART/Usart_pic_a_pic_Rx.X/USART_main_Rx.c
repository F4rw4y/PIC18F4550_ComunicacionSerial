/*
 * File:   USART_main_Rx.c
 * Author: USER
 *
 * Created on 2 de octubre de 2019, 01:01 AM
 */


#include <xc.h>
#include "fuses.h"
#include "usart_libreria.h"

void main(void) {
    
    TRISD   =   0;  //Puerto D como salida para que se muestre la recepcion
    
    USART_In(9600); //Inicializar el USART  
    
    while(1){
        
        PORTD   =   USART_Rx;   //El Puerto D toma el valor recibido
        
    }
    
    return;
}
