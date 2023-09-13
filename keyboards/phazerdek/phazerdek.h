#pragma once



#if defined(KEYBOARD_phazerdek_avr)
#    include "avr.h"
#elif defined(KEYBOARD_phazerdek_stm)
#    include "stm.h"
#endif


#include "quantum.h"


#define LAYOUT( \
        L00, L01, L02, L03, L04, L05, L06,         \
        L10, L11, L12, L13, L14, L15, L16,         \
        L20, L21, L22, L23, L24, L25, L26,         \
        L30, L31, L32, L33, L34, L35,             \
                  L40, L41,        L36, L37,      \
                              L42, L44, L45, L47, \
                                        L43, L46, \
                                                  \
        R06, R05, R04, R03, R02, R01, R00,        \
        R16, R15, R14, R13, R12, R11, R10,        \
        R26, R25, R24, R23, R22, R21, R20,        \
             R35, R34, R33, R32, R31, R30,         \
       R37, R36,       R41, R40,                   \
  R47, R45, R44, R42,                             \
  R46, R43                                      \
)\
    { \
        { L00  , L01  , L02, L03, L04, L05, L06, KC_NO , R00  , R01  , R02, R03, R04, R05, R06, KC_NO}, \
        { L10  , L11  , L12, L13, L14, L15, L16, KC_NO, R10  , R11  , R12, R13, R14, R15, R16, KC_NO}, \
        { L20  , L21  , L22, L23, L24, L25, L26, KC_NO, R20  , R21  , R22, R23, R24, R25, R26, KC_NO}, \
        { L30  , L31  , L32, L33, L34, L35, L36, L37 ,R30  , R31  , R32, R33, R34, R35, R36, R37   }, \
        { L40  , L41  , L42, L43, L44, L45, L46, L47,R40  , R41  , R42, R43, R44, R45, R46, R47}\
    }
