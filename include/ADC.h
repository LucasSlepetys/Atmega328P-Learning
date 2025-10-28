#ifndef ADC_H
#define ADC_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif /* F_CPU */


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void ADC_START(void);
uint16_t ADC_read(uint8_t channel);


#endif /* ADC_H */