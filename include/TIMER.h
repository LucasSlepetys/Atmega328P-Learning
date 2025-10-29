#ifndef TIMER_H
#define TIMER_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif /* F_CPU */


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void millis_init(void);
uint32_t millis(void);

#endif /* TIMER_H */