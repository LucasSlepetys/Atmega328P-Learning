#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "USART.h"
#include "ADC.h"

uint16_t potVal0 = 0;
uint16_t potVal1 = 0;


int main(void) {

  const uint8_t start[] = "Program Start \n\r";

  USART_INIT(9600);
  sei();

  usart_send_string(start);

  ADC_START();

  DDRC &= ~(1<<PC0);
  PORTC &= ~(1 << PC0); //disables pull up resistor

  while(1) {

    // if(usart_read_count() > 0) {

    //   uint8_t data = usart_read();
    //   usart_send_byte(data);
    // } 

    potVal0 = ADC_read(0);
    
    potVal1 = ADC_read(3);

    usart_send_string("Pot value 0: "); usart_send_int(potVal0); usart_send_byte('\n');
    usart_send_string("Pot value 1: "); usart_send_int(potVal1); usart_send_byte('\n');

  
    _delay_ms(1000);
    
    

  }
 
}