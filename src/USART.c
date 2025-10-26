#include "USART.h"


volatile static uint8_t rx_buffer[RX_BUFFER_SIZE] = {0};
volatile static uint16_t rx_count = 0;


volatile static uint8_t usart_tx_busy = 1; //not busy

//Interrupt for receiver:   
//whenver enabled: ready to receive
ISR(USART_RX_vect) {

    volatile static uint16_t rx_write_pos = 0;

    rx_buffer[rx_write_pos] = UDR0; //clearas rx interrupt flag
    rx_count++;
    rx_write_pos++;

    if(rx_write_pos >= RX_BUFFER_SIZE) {
        rx_write_pos = 0; //overflow = override oldest data
    }

}



//Interrupt for transmitter:
//Whenver enabled: just finished transmitting
ISR(USART_TX_vect) {

    //transmission is not busy
    usart_tx_busy = 1;

}

void USART_INIT(uint32_t baud_rate) {

    // Normal speed
    UCSR0A &= ~(1 << U2X0);

    uint8_t speed = 16;

    uint32_t baud = (F_CPU / (speed * baud_rate)) - 1;

    uint16_t LOW_baud = (baud & 0b11111111);
    uint16_t HIGH_baud = ( (baud >> 8) &  0b11111111 );

    UBRR0L = LOW_baud;
    UBRR0H = HIGH_baud;

    //enables receiver and transmitter:
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);

    //enables receiver and transmitter interrupts:
    UCSR0B |= (1 << TXCIE0) | (1 << RXCIE0);

    //Reset C-register to default for 8 bit data frame:
    UCSR0C = 0b00000110;

}


//! ---------- Transmitting -----------

void usart_send_byte(uint8_t c){ 
    while(usart_tx_busy == 0); //wait until data is sending //usart is busy
    usart_tx_busy = 0; //usart is busy

    UDR0 = c;   //load data into buffer
}

void usart_send_array(uint8_t *c, uint16_t len) {
    for(uint16_t i = 0; i < len; i++) {
        usart_send_byte(c[i]);
    }
}

void usart_send_string(uint8_t *str) {
    while(*str) {usart_send_byte(*str++);}
}

//! -------------------------------


uint16_t usart_read_count(void) {
    return rx_count;
}

uint8_t usart_read(void) {

    static uint16_t rx_read_pos = 0;
    uint8_t data = 0;

    data = rx_buffer[rx_read_pos];
    rx_read_pos++;
    rx_count--; //since one data from buffer was removed

    if(rx_read_pos >= RX_BUFFER_SIZE) {
        rx_read_pos = 0;
    }

    return data;

}
