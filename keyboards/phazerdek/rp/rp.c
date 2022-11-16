#include "rp.h"


void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();

}


void keyboard_pre_init_user(void) {

}

void keyboard_post_init_user(void) {
    setPinOutput(GP2);
    setPinOutput(GP29);
    setPinOutput(GP28);
    
    writePinHigh(GP2);
    writePinHigh(GP29);
    writePinHigh(GP28);
}