#include "stm.h"


extern void ui_init(void);
extern void ui_task(void);

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();

}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;

  ui_init();
  //debug_keyboard=true;
  //debug_mouse=true;
}

void housekeeping_task_user(void) {
    // Draw the display
    ui_task();
}
