#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include <stdio.h>
#define BASE 0 // default layer
#define GAME 1
#define _LOWER 2 // code layer
#define _RAISE 3 // symbols
#define _ADJUST 4
#define _MAC 5

#define shfted SFT_T(KC_CAPS)
/*enum layers = {
     BASE=0, // default layer
     TEST
     GAME,
     _LOWER, // code layer
     _RAISE, // symbols
     _ADJUST
     _MAC
};*/

//#define _______ KC_TRNS
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
#define SNAP_U LGUI(KC_UP)
#define SNAP_D LGUI(KC_DOWN)
#define SEL_AL LCTL(KC_A)
#define DESKTOP LGUI(KC_D)
#define EXP LGUI(KC_E)
#define TASKVIEW LGUI(KC_TAB)
#define WINDOWS LALT(KC_TAB)
#define SCNSHT SWIN(KC_S)
#define SUPER_ALT LALT(KC_LGUI)
#define SUPER_CTL LCTL(KC_LGUI)
#define ALT_CTL LALT(KC_LCTL)

const uint16_t PROGMEM test_combo1[] = {SNAP_L, SNAP_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, SNAP_U),
    //COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
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
  clrfilt,
  deg,
  mu,
  cool,
  delta,
  alpha,
  xl,
  colrst,
  autoclick,
  autoup,
  autodown,
  autoprint,
  songme,
  DYNAMIC_MACRO_RANGE
};

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

};


enum unicode_names {
  MU,
  DELTA,
  ALPHA,
  LAMDA,
  sigma,
  SIGMA,
  DEG,
  PLSMIN,
  VULCAN,
  ROCKON,
  THMUP,
  COOL,
  SMILE,
  SMIRK,
  ROFL,
  ABOUT,
  LEQ,
  GEQ,
  SNEK,
  FUNC,
  SUP1,SUP2,SUP3,SUP4,SUP5,SUP6,SUP7,SUP8,SUP9,SUP0,
  SUB1,SUB2,SUB3,SUB4,SUB5,SUB6,SUB7,SUB8,SUB9,SUB0,
};

const uint32_t PROGMEM unicode_map[] = {
  [MU]     = 0x03BC,  // μ
  [DELTA]  = 0x03B4,  // δ
  [ALPHA]  = 0x03B1, // α
  [LAMDA]  = 0x03BB, //  λ
  [sigma]  = 0x03C3, //  σ
  [SIGMA]  = 0x03A3, // Σ
  [DEG]    = 0x00B0, //°
  [PLSMIN] = 0x00B1, //±
  [VULCAN] = 0x1F596, //🖖
  [ROCKON] = 0x1F918, //🤘
  [THMUP]  = 0x1F44D, //👍
  [COOL]   = 0x1F60E,//😎
  [SMILE]  = 0x263A, //☺
  [SMIRK]  = 0x1F60F, //😏
  [ROFL]   = 0x1F923, //🤣
  [ABOUT]  = 0x2248,	// ≈
  [LEQ]    = 0x2264, //≤
  [GEQ]    = 0x2265, //≥
  [FUNC]   = 0x0192, // ƒ
  [SUP1]   = 0x00B9,
  [SUP2]   = 0x00B2,
  [SUP3]   = 0x00B3,
  [SUP4]   = 0x2074,
  [SUP5]   = 0x2075,
  [SUP6]   = 0x2076,
  [SUP7]   = 0x2077,
  [SUP8]   = 0x2078,
  [SUP9]   = 0x2079,
  [SUP0]   = 0x2070,
  [SUB1]   = 0x2081,
  [SUB2]   = 0x2082,
  [SUB3]   = 0x2083,
  [SUB4]   = 0x2084,
  [SUB5]   = 0x2085,
  [SUB6]   = 0x2086,
  [SUB7]   = 0x2087,
  [SUB8]   = 0x2088,
  [SUB9]   = 0x2089,
  [SUB0]   = 0x2080,
  [SNEK]  = 0x1F40D, // 🐍
};


// float my_song[][2] = SONG(QWERTY_SOUND);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,         KC_2,     KC_3,     KC_4,        KC_5,    TASKVIEW,
        KC_TAB,        KC_Q,         KC_W,     KC_E,     KC_R,        KC_T,    SCNSHT,
        KC_LSFT,       KC_A,         KC_S,     KC_D,     KC_F,        KC_G,    KC_CALC,
        KC_LGUI,       KC_Z,         KC_X,     KC_C,     KC_V,        KC_B,
                                     KC_WHOM,  EXP ,                KC_LSFT, KC_LGUI,
                                                        KC_DEL,  KC_SPC,  LOWER,  KC_LALT,
                                                                          KC_LCTL, OSL(_MAC),
                        // right hand
              RGB_TOG,  KC_6,     KC_7,     KC_8,           KC_9,            KC_0,                   DESKTOP,
              CAD,      KC_Y,     KC_U,     KC_I,           KC_O,            KC_P,                   KC_CAPS,
              TM,       KC_H,     KC_J,     KC_K,           KC_L,            TD(TD_SEMICOLON_COLON), TD(TD_QUOT), //SFT_T(KC_QUOT),  //SFT_T(TD(TD_QUOT))
                        KC_N,     KC_M,     KC_COMM,        KC_DOT,          KC_SLSH ,               SNAP_R,
                KC_APP, KC_LSFT,                UM(SMILE),       SNAP_L,
        SUPER_ALT, RAISE , KC_BSPC,  KC_ENT,
        ALT_CTL,   SUPER_CTL
    ),

[GAME] = LAYOUT(  // layer 0 : default
        // left hand
        _______,        _______,         _______,     _______,     _______,        _______, _______,
        _______,        KC_G   ,         KC_Q   ,     KC_W   ,     KC_E   ,        KC_R   , KC_T,
        KC_B   ,        KC_LSFT,         KC_A   ,     KC_S   ,     KC_D   ,        KC_F   , KC_G,
        KC_T   ,        KC_LCTL,         KC_Z   ,     KC_X   ,     KC_C   ,        KC_V   ,
                                         _______ ,    KC_B  ,                    autoclick , _______,
                                                                   _______ ,   _______ ,  _______ ,  _______ ,
                                                                                          _______ ,  _______ ,
                        // right hand
                      autoup,        _______,        _______,        _______,        _______,        _______,         TO(BASE),
                      autodown,        _______,        _______,        _______,        _______,        _______,         _______,
                      autoprint,        _______,        _______,        _______,        _______,        _______,         _______,
                                      _______,        _______,        _______,        _______,        _______,         _______,
              _______, _______ ,                      _______,        _______,
  _______  ,  _______,  _______,        _______,
  _______  ,  _______
    ),

[_LOWER] = LAYOUT(  // layer 0 : default
        // left hand

        KC_PAUSE,       KC_F1,           KC_F2,       KC_F3,       KC_F4,          KC_F5  ,   _______,
        _______,        QUIT   ,         _______,     KC_UP  ,     LSFT(KC_TAB),   KC_TAB ,   KC_PGUP ,
        _______,        xl     ,         KC_LEFT,     KC_DOWN,     KC_RIGHT,       KC_HOME,   KC_PGDN ,
        _______,        UNDO,            CUT    ,     COPY   ,     PASTE   ,       KC_END ,
                                         _______ ,    _______ ,                    _______ , _______,
                                                                   _______ ,   _______ ,  _______ ,  _______ ,
                                                                                          _______ ,  _______ ,
                        // right hand
           KC_INS ,     KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,          KC_F11,
           KC_PSCR ,    KC_PLUS,        KC_LBRC,        KC_RBRC,        KC_CIRC,        KC_ASTR,         KC_F12,
           KC_BRK ,     KC_EQL,         KC_LPRN,        KC_RPRN,        KC_DLR ,        KC_GRAVE,        _______,
                        KC_MINS,        KC_LCBR,        KC_RCBR,        KC_AMPR,        KC_BSLS,         _______,
            _______,   _______ ,                        _______,        _______,
  _______  ,  _______,  _______,        _______,
  _______  ,  _______
    ),

[_RAISE] = LAYOUT(  // layer 0 : default
        // left hand

        TO(GAME),       UP(SUB1,SUP1) , UP(SUB2,SUP2) , UP(SUB3,SUP3) , UP(SUB4,SUP4) , UP(SUB5,SUP5), UM(SNEK),
        _______,   _______       , _______      , KC_WH_U      , _______      , _______         , _______,
        _______,   _______       , KC_WH_L      , KC_WH_D      , KC_WH_R      , _______         , _______,
        _______,   AS_DOWN       , AS_UP      , AS_RPT      , AS_ON     , AS_OFF         ,
                                         _______ ,    _______ ,                    _______ , _______,
                                                                   _______ ,   KC_UNDS ,  _______ ,  _______ ,
                                                                                          _______ ,  _______ ,
                        // right hand
            DM_PLY1, UP(SUB6,SUP6)  , UP(SUB7,SUP7), UP(SUB8,SUP8),  UP(SUB9,SUP9), UP(SUB0,SUP0), QK_BOOT,
            DM_RSTP,     UM(GEQ)       , _______     , _______     ,  _______     , _______     , _______,
            DM_REC1, UM(ABOUT)      ,  UM(PLSMIN)  , _______     ,  _______     , _______     , _______,
                     UM(LEQ)       , _______     , _______     ,  _______     , _______     , _______,
             _______,  _______ ,                  _______,        _______,
  _______  ,  _______,  _______,        _______,
  _______  ,  _______
    ),

[_ADJUST] = LAYOUT(  // layer 0 : default
        // left hand

        _______,        UM(SMILE), _______          , _______ , _______   , _______, _______,
        _______,        _______ , _______          , _______ , colrst , UM(DEG)  , _______,
        _______,        UM(ALPHA), UP(sigma,SIGMA) , UM(DELTA), UM(FUNC), _______ , _______,
        _______,        _______ , _______          , _______ , _______, _______ ,
                                         _______ ,    _______ ,                    _______ , _______,
                                                                   _______ ,   _______ ,  _______ ,  _______ ,
                                                                                          _______ ,  _______ ,
                        // right hand
         _______,       _______,        _______,        _______,        _______,        _______    ,         LCTL(LALT(KC_2)),
         _______,       _______,        _______,        _______,        _______,        _______    ,         LCTL(LALT(KC_3)),
         _______,       _______,        _______,        _______,        UM(LAMDA),       _______    ,         LCTL(LALT(KC_4)),
                        _______,        UM(MU)  ,        _______,        _______,        _______    ,         LCTL(LALT(KC_5)),
               _______,   _______ ,                     _______,        _______,
  _______  ,  _______,  _______,        _______,
  _______  ,  _______
    ),

[_MAC] = LAYOUT(  // layer 0 : default
        // left hand

        _______,        _______,         _______,     _______,     _______,        _______, _______,
        _______,        merge  ,         wrap   ,     VB     ,     clrfilt,        newwin , _______,
        _______,        dups   ,         sort   ,     del    ,     filt   ,        frz    , _______,
        _______,        pivot  ,         t2c    ,     COL    ,     _______,        _______,
                                         _______ ,    _______ ,                    _______ , _______,
                                                                   _______ ,   _______ ,  _______ ,  _______ ,
                                                                                          _______ ,  _______ ,
                        // right hand
       _______,         _______,        _______,        _______,        _______,        _______,         _______,
       _______,         _______,        _______,        _______,        _______,        _______,         _______,
       _______,         _______,        _______,        _______,        _______,        _______,         _______,
                        _______,        _______,        _______,        _______,        _______,         _______,
               _______,   _______ ,                     _______,        _______,
  _______  ,  _______,  _______,        _______,
  _______  ,  _______
    ),

};



//const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls
//const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};
//default layer hue, sat and val settings
uint16_t dhue = 190;
uint8_t dsat = 255;
uint8_t dval = 150;

uint8_t prev = BASE;
uint32_t check;
uint32_t desired = 1;

bool autoclick_active = false;
uint16_t autoclick_timer = 0;
uint16_t autoclick_int = 10;

//Set rgb on LEDs
bool led_update_user(led_t led_state) {

    if (led_state.caps_lock) {
        //rgblight_mode_noeeprom(5);

        //rgblight_sethsv_noeeprom(dhue, dsat, dval);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3 );

    }
    else {

        rgblight_mode_noeeprom(desired);

    }
    return true;

}


//Turn on LEDs
void matrix_init_user() {
    rgblight_mode_noeeprom(desired);
    //set_led_blue;
    // set_unicode_input_mode(UC_WIN);
}

// static void send_layer_via_hid(int layer) {
//     uint8_t data[RAW_EPSIZE];
//     data[0] = 1;
//     data[1] = layer;
//     raw_hid_send(data, sizeof(data));
//     return;
// }

//Control LED states on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
  //uint8_t layer = biton32(state);
  // send_layer_via_hid(state);
  if (prev==_ADJUST) {
      desired = 0;//rgblight_get_mode();
  }
  switch (get_highest_layer(state)) {
    case BASE:
      rgblight_sethsv_noeeprom (dhue, dsat, dval);

      //rgblight_mode_noeeprom(desired);
      //led_set_user(host_keyboard_leds());
      break;

    case _LOWER:
      //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3 );
      rgblight_sethsv_noeeprom(0,204,dval);
      // send_layer_via_hid(20);
      break;

    case _RAISE:
      //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3 );
      rgblight_sethsv_noeeprom(106,255,dval);
      break;

    case _ADJUST:
      //rgblight_mode_noeeprom(desired);
      rgblight_sethsv_noeeprom (HSV_GOLDENROD);
      break;
    case GAME:
      //rgblight_mode_noeeprom(desired);
      rgblight_sethsv_noeeprom ( 0, 255, dval);

      break;


    case _MAC:
      rgblight_sethsv_noeeprom (HSV_SPRINGGREEN);

  }
  prev = get_highest_layer(state);
  return state;
}


//Custom Key Codes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_dynamic_macro(keycode, record)) {
        return false;
    }

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


//MACROS
  case autoclick:
    if (record->event.pressed) {
        autoclick_active=true;
        // register_code(KC_BTN1);
        // unregister_code(KC_BTN1);
        // autoclick_timer = timer_read();
    }
    else {
        autoclick_active=false;
    }
    return true;
    break;

  case autoup:
    if (record->event.pressed) {
        autoclick_int = autoclick_int+5;
    }
    return true;
    break;
  case autodown:
    if (record->event.pressed) {
        autoclick_int = autoclick_int-5;
    }
    return true;
    break;

  case autoprint:
    if (record->event.pressed) {
        char result[8];
        snprintf(result, 8, "%d", autoclick_int);
        send_string((const char *)result);
    }
    return true;
    break;


  case xl:
    if (record->event.pressed) {
        register_code(KC_LSFT),register_code(KC_LCTL);
    }
    else {
        clear_mods();
    }
    return false;
    break;

/*

    case cool:
    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT)    \
                        SS_TAP(X_KP_1) \
                        SS_TAP(X_KP_2) \
                        SS_TAP(X_KP_8) \
                        SS_TAP(X_KP_5) \
                        SS_TAP(X_KP_2) \
                        SS_TAP(X_KP_6) \
                        SS_UP(X_LALT));
    }
    return false;
    break;

    */

    //these need to return true or the
    //macro layer (which is layer tap) does not close
  //Highlight duplicates
  case dups:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"HLHD");
    }
    return true;
    break;
  //sort data
  case sort:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"ASS");
    }
    return true;
    break;
  //delete cells
  case del:
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("-"));
    }
    return true;
    break;
  //filter data
  case filt:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"AT");
    }
    return true;
    break;

  case frz:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"WFF");
    }
    return true;
    break;
  //merge cells
  case merge:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"HMM");
    }
    return true;
    break;
  //wrap text
  case wrap:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"HW");
    }
    return true;
    break;
  //open vba editor
  case VB:
    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F11)SS_UP(X_LALT));
    }
    //SEND_STRING(SS_TAP(X_LALT)"HW");
    return true;
    break;
  //open new window
  case newwin:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"WN");
    }
    return true;
    break;
  //text to columns
  case t2c:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"AFT");
    }
    return true;
    break;
  //
  case COL:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"AE");
    }
    return true;
    break;
  //clear filter
  case clrfilt:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT)"AC");
    }
    return true;
    break;
  
  // case songme:
  //   if (record->event.pressed) {
  //       PLAY_SONG(my_song);
  //   }
  //   return true;
  //   break;

/*

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

    */
//close switch
  }

//close proc bool record
return true;
};


void matrix_scan_user(void) {     // The very important timer.
  if (autoclick_active) {
    if (timer_elapsed(autoclick_timer) > autoclick_int) {
      register_code(KC_BTN1);
      unregister_code(KC_BTN1);
      autoclick_timer = timer_read();
    }
  }
}
