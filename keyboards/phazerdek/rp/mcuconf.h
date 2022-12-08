#pragma once

#include_next <mcuconf.h>

#undef RP_PWM_USE_PWM3
#define RP_PWM_USE_PWM3 TRUE

// Used for EEPROM
#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

// #undef RP_SIO_USE_UART0
// #define RP_SIO_USE_UART0 TRUE
