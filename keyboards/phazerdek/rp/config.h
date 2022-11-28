#pragma once

#include "config_common.h"



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
//  */
 #define RGB_DI_PIN GP25    // The pin your RGB strip is wired to
 #define RGBLED_NUM 1
 #define WS2812_PIO_USE_PIO1
// // FRAM configuration
// #define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A0
// #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8 // 96MHz / 8 = 12MHz; max supported by MB85R64 is 20MHz
// #define EXTERNAL_EEPROM_PAGE_SIZE 64 // does not matter for FRAM, just sets the RAM buffer size in STM32F chip
// #define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191

// // External flash configuration
// #define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B12
// #define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 1  // 96MHz; max supported by W25Q128JV is 133MHz
// #define EXTERNAL_FLASH_BYTE_COUNT (16 * 1024 * 1024)  //128Mbit or 16MByte
// #define EXTERNAL_FLASH_PAGE_SIZE 256
// #define EXTERNAL_FLASH_SPI_TIMEOUT 200000 //datasheet max is 200 seconds for flash chip erase
// #define NOP_FUDGE 0.4

// #define SERIAL_DRIVER uart0

#define SERIAL_DRIVER SIOD0
#define SIO_USE_SYNCHRONIZATION 1
#define SD_TX_PIN GP0
#define SD_RX_PIN GP1