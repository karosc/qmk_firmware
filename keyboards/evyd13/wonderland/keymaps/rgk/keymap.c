#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MAC
};


#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define TM C_S_T(KC_ESC)
#define CAD LCA(KC_DEL)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define QUIT LALT(KC_F4)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define SAVE LCTL(KC_S)
#define SNAP_L LGUI(KC_LEFT)
#define SNAP_R LGUI(KC_RIGHT)
#define SEL_AL LCTL(KC_A)
#define DESKTOP LGUI(KC_D)
#define EXP LGUI(KC_E)
#define TASKVIEW LGUI(KC_TAB)
#define WINDOWS LALT(KC_TAB)
#define SCNSHT SWIN(KC_S)
#define FIND LCTL(KC_F)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  pw1,
  dups,
  sort,
  del,
  filt,
  frz,
  merge,
  wrap,
  VB,
  newwin,
  pivot,
  t2c,
  COL,
  pw2,
  pw3,
  pw4,
  pw5,
  clrfilt,
  deg,
  mu,
  cool,
  delta,
  alpha,
  xl,
  colrst,
  DYNAMIC_MACRO_RANGE
};

 //#include "dynamic_macro.h"
/*enum custom_macros {

};*/

// Tap Dance Definitions
enum tap_dance_custom_keys {
  TD_SEMICOLON_COLON = 0,
  TD_QUOT,
  TD_TAB
  //TD_GAME
  //TD_filt
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
  [TD_QUOT]            = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_DQT),
  [TD_TAB]             = ACTION_TAP_DANCE_DOUBLE(KC_TAB,LSFT(KC_TAB))
  //[TD_GAME]= ACTION_TAP_DANCE_DOUBLE(KC_MYCM, layer_on(GAME)),
  //[TD_filt] = ACTION_TAP_DANCE_DOUBLE(KC_8, pw1)

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_ESC,  KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,      KC_5,    KC_6,          KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_NO,  KC_BSPC, \
  KC_HOME, KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS, \
  KC_END,  KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,      KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT, \
           KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,                   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  RAISE, \
           KC_LCTL,           SC_LAPO,      KC_BSPC,       LOWER,             KC_SPC, SC_RAPC,                             KC_RCTL \
   ),

[_LOWER] = LAYOUT(
  RGB_TOG,  _______, KC_F1,       KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, QK_RBT, \
	RGB_MOD,  _______, QUIT,        _______, KC_UP,   LSFT(KC_TAB), KC_TAB,                 KC_PLUS, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, \
	RGB_RMOD, _______, KC_LCTL,     KC_LEFT, KC_DOWN, KC_RGHT,      _______,                KC_EQL,  KC_LPRN, KC_RPRN, _______, _______, _______,          _______, \
				    _______, _______,     _______, _______, _______,      _______,                KC_MINS, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, \
					  _______,                       KC_LALT,        _______,        _______,       _______, KC_RALT,                            _______\
),

[_RAISE] = LAYOUT(
  _______,  _______, _______,     _______, _______, _______, _______,   _______,        _______, _______, _______, _______,  _______,_______,  _______, _______, \
	_______,  _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, \
	_______, _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,          _______, \
				    _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, \
					  _______,              _______,        _______,       _______,               _______, _______,                            _______\
),

[_ADJUST] = LAYOUT(
  _______,  _______, _______,     _______, _______, _______, _______,   _______,        _______, _______, _______, _______,  _______,_______,  _______, _______, \
	_______,  _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, \
	_______, _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,          _______, \
				    _______, _______,     _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, \
					  _______,              _______,        _______,       _______,               _______, _______,                            _______\
)

};


const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls
const uint8_t RGBLED_KNIGHT_INTERVALS[]        PROGMEM = {127, 63, 15};
//default layer hue, sat and val settings
uint16_t dhue = 190;
uint8_t dsat = 255;
//uint8_t dval = 150;
uint8_t dval = 185;

uint8_t prev = _BASE;
uint32_t check;
uint32_t desired = 1;


//Set rgb on LEDs
void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        //rgblight_mode(5);
        //rgblight_sethsv ( dhue, dsat, 200);
        rgblight_sethsv_range(112, 255, dval, 2, 4);

    } else {
        rgblight_sethsv ( dhue, dsat, dval);}

}

//Turn on LEDs
void matrix_init_user() {
    rgblight_mode(desired);
//    set_unicode_input_mode(UC_WIN);
}

//Control LED states on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  if (prev==_ADJUST) {
      desired = rgblight_get_mode();
  }
  switch (layer) {
    case _BASE:
      rgblight_sethsv ( dhue, dsat, dval);

      //rgblight_mode(desired);
      led_set_user(host_keyboard_leds());
      break;

    case _LOWER:
      //rgblight_mode(RGBLIGHT_MODE_KNIGHT + 2 );
      rgblight_sethsv(11,176,dval);
      break;

    case _RAISE:
      //rgblight_mode(RGBLIGHT_MODE_KNIGHT + 2 );
      rgblight_sethsv(106,255,dval);
      break;

    case _ADJUST:
      rgblight_mode(desired);
      rgblight_sethsv ( dhue, dsat, dval);
      break;
      /*
    case GAME:
      rgblight_mode(desired);
      rgblight_sethsv ( 0, 255, dval);
      break;
      */
    case _MAC:
      rgblight_mode(RGBLIGHT_EFFECT_RAINBOW_SWIRL + 5);
  }
  prev = layer;
  return state;
}


//Custom Key Codes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
*/
  switch (keycode) {
  case LOWER:
    if (record->event.pressed) {
    layer_on(_LOWER);

    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
    layer_off(_LOWER);

    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    clear_mods();
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
    layer_on(_RAISE);

    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
    layer_off(_RAISE);

    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    clear_mods();
    }
    return false;
    break;


//VBA
  case xl:
    if (record->event.pressed) {
        register_code(KC_LSFT),register_code(KC_LCTL);
    }
    else {
        clear_mods();
    }
    return false;
    break;

  //Highlight duplicates
  case dups:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"HLHD");
    }
    return true;
    break;
  //sort data
  case sort:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"ASS");
    }
    return true;
    break;
  //delete cells
  case del:
    if (record->event.pressed) {
        send_string(SS_LCTL("-"));
    }
    return true;
    break;
  //filter data
  case filt:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"AT");
    }
    return true;
    break;

  case frz:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"WFF");
    }
    return true;
    break;
  //merge cells
  case merge:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"HMM");
    }
    return true;
    break;
  //wrap text
  case wrap:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"HW");
    }
    return true;
    break;
  //open vba editor
  case VB:
    if (record->event.pressed) {
        send_string(SS_DOWN(X_LALT)SS_TAP(X_F11)SS_UP(X_LALT));
    }
    //send_string(SS_TAP(X_LALT)"HW");
    return true;
    break;
  //open new window
  case newwin:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"WN");
    }
    return true;
    break;
  //text to columns
  case t2c:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"AFT");
    }
    return true;
    break;
  //
  case COL:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"AE");
    }
    return true;
    break;
  //clear filter
  case clrfilt:
    if (record->event.pressed) {
        send_string(SS_TAP(X_LALT)"AC");
    }
    return true;
    break;



   //Setting default RGB colors
  case RGB_HUI:
    if (record->event.pressed) {
        dhue=(dhue+RGBLIGHT_HUE_STEP) % 255;
    }
    return true;
    break;

  case RGB_HUD:
    if (record->event.pressed) {
        dhue= (dhue-RGBLIGHT_HUE_STEP) % 255;
    }
    return true;
    break;

  case RGB_SAI:
    if (record->event.pressed) {
      if (dsat+RGBLIGHT_SAT_STEP>255){dsat=255;}
      else{dsat+=RGBLIGHT_SAT_STEP;}
    }
    return true;
    break;

  case RGB_SAD:
    if (record->event.pressed) {
      if (dsat-RGBLIGHT_SAT_STEP<0){dsat=0;}
      else{dsat-=RGBLIGHT_SAT_STEP;}
    }
    return true;
    break;

  case RGB_VAI:
    if (record->event.pressed) {
      if (dval+RGBLIGHT_VAL_STEP>255){dval=255;}
      else{dval+=RGBLIGHT_VAL_STEP;}
    }
    return true;
    break;

  case RGB_VAD:
    if (record->event.pressed) {
      if (dval-RGBLIGHT_VAL_STEP<0){dval=0;}
      else{dval-=RGBLIGHT_VAL_STEP;}
    }
    return true;
    break;

  case colrst:
    if (record->event.pressed) {
      dhue = 190;
      dsat = 255;
      dval = 150;
    }
    return false;
    break;
//close switch
  }

//close proc bool record
return true;
};
