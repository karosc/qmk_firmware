#include "avr.h"

void led_init(void) {
    setPinOutput(D0);
    setPinOutput(D1);
    setPinOutput(F4);
    setPinOutput(F5);
    
    writePinHigh(D0);
    writePinHigh(D1);
    writePinHigh(F4);
    writePinHigh(F5);
}


void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init();
}