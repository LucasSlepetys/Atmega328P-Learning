#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "USART.h"


int main(void) {

  const uint8_t start[] = "Program Start \n\r";

  USART_INIT(9600);
  sei();

  usart_send_string(start);

  while(1) {

    if(usart_read_count() > 0) {

      uint8_t data = usart_read();
      usart_send_byte(data);
    } 

  }

}