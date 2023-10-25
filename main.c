#include "librobot.h"


void init_button_sensor(void){

	/* --------------- Begin Answer to Task 1a Here ------------ */
	
	DDRD  = 0b01111111;  // Enabling PORTD pull resistor for PD7
	PORTD = 0b10000000; 


	/* --------------- End Answer to Task 1a Here -------------- */

	return;

}



int read_button_sensor(void){

	int pressed;

	/* --------------- Begin Answer to Task 1b Here ------------ */
     
	 if(PIND & 0b10000000){ //If the button is pressed then 0 is returned if not then 1 is returned.
			pressed = 0;
		}else{
			pressed = 1;
		}

	/* --------------- End Answer to Task 1b Here -------------- */

	return pressed;

}



float read_knob_sensor(int knob){

	float reading = 0; /* Sensor reading, normalised

						  (i.e., scaled) to be between 

						  zero and one. */

	/* --------------- Begin Answer to Task 2 Here ------------ */
	
	DDRC=0x00; //Setting analog ports as inputs
	
	if(knob==0){
	 ADMUX |= (0<<MUX0); //If the knob =0 then the ADC channel is switched to A0.
	}else if (knob==1){
	 ADMUX |= (1<<MUX0); //If the knob =1 then the ADC channel is switched to A1.
	}
	
	 ADCSRA |= (1<<ADSC);
	 
	 while(ADCSRA & (1<<ADSC)); //Waiting for ADC conversion to finish.
	 reading = (float)ADCH/255;
	 
	 ADMUX &=~(1<<MUX0);
	
	/* --------------- End Answer to Task 2 Here -------------- */

	return reading;

}





void init_arm_motors(void) {

	/* --------------- Begin Answer to Task 3 Here ------------ */
 
 DDRB = (1<<PB1) | (1<<PB2);
 PORTB = 0x00;

 TCCR1A = TCCR1A |(1<<COM1A1);
 TCCR1A = TCCR1A |(1<<COM1B1);

 TCCR1A |= (1<<WGM11);
 TCCR1B = (1<<WGM12) | (1<<WGM13);

 TCCR1B |= (1<<CS11);

 ICR1 = 40000;
 OCR1A = 4000;
 OCR1B = 2000;
 
 /* --------------- End Answer to Task 3 Here -------------- */

	return;

}





