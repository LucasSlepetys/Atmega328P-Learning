#ifndef USART_H_
#define USART_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif /* F_CPU */


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RX_BUFFER_SIZE 128

void USART_INIT(uint32_t baud);
void usart_send_byte(uint8_t c);
void usart_send_array(uint8_t *c, uint16_t len);
void usart_send_string(uint8_t *str);

uint16_t usart_read_count(void);
uint8_t usart_read(void);


#endif /* USART_H_ */