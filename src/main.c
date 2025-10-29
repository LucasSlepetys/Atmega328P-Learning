#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "USART.h"
#include "ADC.h"
#include "TIMER.h"


int main(void) {

  const char start[] = "Program Start \n\r";

  USART_INIT(9600);
  ADC_START();
  millis_init();
  sei();

  usart_send_string(start);

  uint32_t previous = millis();
  uint32_t previous_tx = millis();
  uint32_t lastLight = millis();

  //Analog input 0
  DDRC &= ~(1<<PC0);
  PORTC &= ~(1 << PC0); //disables pull up resistor

  //LEDs:
  DDRB |= (1 << PB1);
  DDRB |= (1 << PB0);

  //button:
  DDRD &= ~(1 << PD7);
  PORTD |= (1 << PD7); //pull up resistor


  uint16_t potVal0 = 0;
  uint16_t potVal1 = 0;

  uint32_t interval = 0;

  while(1) {

    potVal0 = ADC_read(1);
    potVal1 = ADC_read(3);

    //reading and sending data to USART
    if(usart_read_count() > 0) {
      uint8_t data = usart_read();
      usart_send_byte(data);
    } 

    uint32_t now = millis();

    // if(now - previous_tx >= 1000) {
    //   previous_tx = now;

    //   usart_send_string("Pot value 0: "); usart_send_int(potVal0); usart_send_byte('\n');
    //   usart_send_string("Pot value 1: "); usart_send_int(potVal1); usart_send_byte('\n');

    // }

    interval = 5UL * (uint32_t)potVal1; 
    if (potVal1 <= 50) interval = 50;  // safety
    if(potVal1 >= 1010) interval = 5000;

    now = millis();

    if(now - previous >= interval) {

      previous = now;
      
      //toggle LED:
      PORTB ^= (1 << PB1);
    }

    now = millis();
    if(now - lastLight >= 50) {
      if(!(PIND & (1 << PD7))) {
            PORTB |= (1 << PB0);
          } else {
            PORTB &= ~(1 << PB0);
          }
    }
    

  }
 
}