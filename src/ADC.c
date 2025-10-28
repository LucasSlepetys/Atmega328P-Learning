#include "ADC.h"

void ADC_START(void){ 

    //Reference voltage:
    ADMUX = (1 << REFS0); // REFS0 = AVcc reference //ADC channel 0 by default
    
    //ADC enable //ADC Prescaler

    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable + 64 division factor


    //! Add interrupt and non blocking code
    //Analog register:
    //ADC Interrupt enable
}

uint16_t ADC_read(uint8_t channel) {

    //specifing channel
    ADMUX = (ADMUX & 0b11110000) | (channel & 0b00001111);

    ADCSRA |= (1 << ADSC); //Start conversion 

    while(ADCSRA & (1 << ADSC));
    return ADC;

}