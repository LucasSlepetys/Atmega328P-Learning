#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void PWM_init(void);
void LED_brightness(uint16_t brightness);

#endif /* PWM_H */