#pragma once


#define HAL_USE_SERIAL TRUE
#define SERIAL_BUFFERS_SIZE 256
#define HAL_USE_PWM TRUE
#define HAL_USE_SPI TRUE

// #define HAL_USE_DAC                 TRUE
// #define HAL_USE_GPT                 TRUE

// #define HAL_USE_ADC TRUE
// // If you are using SPI (e.g. for FRAM, flash, etc.) include these lines
// #define HAL_USE_SPI TRUE
// #define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
// // This enables interrupt-driven mode
// #define SPI_USE_WAIT TRUE

#include_next <halconf.h>