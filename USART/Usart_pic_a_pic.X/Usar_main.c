/*
 * File:   Usar_main.c
 * Author: USER
 *
 * Created on 2 de octubre de 2019, 12:26 AM
 */


#include <xc.h>
#include "fuses.h"
#include "usart_libreria.h"

void main(void) {
    
    USART_In(9600);
    
    while(1){
        
        USART_Tx(0x33);
        __delay_ms(500);
        USART_Tx(0x99);
        __delay_ms(500);
        
    }
    
    return;
}
