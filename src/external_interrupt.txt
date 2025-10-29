
// #define F_CPU 16000000UL

// #include <stdint.h>
// #include <avr/io.h>
// #include <util/delay.h>

// #include <avr/interrupt.h>

// volatile int isOn = 0;

// //Interrupt sub-routine:
// //when button in PD2 is pressed
// ISR(INT0_vect) {
  

//     //TURN On LED
//     if(isOn){
//       PORTD &= ~(1 << PD6);
//       isOn = 0;
//     } else{
//       PORTD |= (1 << PD6);
//       isOn = 1;
//     }

//     //debounce
//     _delay_ms(100); 
// }

// //ISR(INT2_vect) {}



// int main(void) {

//   //Steps for using interrups:
//   //1. Enable Interrupts ports as inputs (for external interrups)
//   //2. Enable interrups sense control (falling edge vs rising edge) for triggering ISR
//   //3. Enable - external interrupt mask register for external interrups
//   //4. Enable gloabal interrupt - sei()



//   //Interrupts: PD2 and PD3
//   //Make them inputs
//   DDRD &= 0b11110011;

//   //Outputs:
//   DDRD |= 0b11110000;

//   //Enable pull up resistor for PD2 and PD3
//   PORTD = 0b00001100;

//   //Set both interrups as falling edge trigger (button is pressed only):
//   EICRA = (1 << ISC11) | (1 << ISC01); //the rest default to zero

//   //Enable both external interrups:
//   EIMSK = (1 << INT1) | (1 << INT0);   //the rest default to zero


//   //Enable global interrupt so all interrups work:
//   sei();

//   while(1) 
//   {
//     //blink LED in PD4:
//     PORTD |= (1 << PD4);
//     _delay_ms(2000);
//     PORTD &= ~(1 << PD4);
//     _delay_ms(2000);
//   }

//   return 0;
// }
// //needs to add millis with internal clock

