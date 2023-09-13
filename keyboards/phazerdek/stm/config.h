#pragma once

// #include "config_common.h"



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
//  */


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



#define SD1_TX_PIN A15
#define SD1_RX_PIN B7

#define AUDIO_INIT_DELAY
#define AUDIO_PIN A3
#define AUDIO_PIN_ALT B10
// #define AUDIO_STATE_TIMER GPTD5
#define AUDIO_PWM_DRIVER PWMD5
#define AUDIO_PWM_CHANNEL 4
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_PIN_ALT_AS_NEGATIVE


// Display Configuration
#define OLED_CS_PIN A5
#define OLED_DC_PIN A1
#define OLED_RST_PIN B1


// SPI Configuration
#define SPI_DRIVER SPID2
#define SPI_SCK_PIN B13
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN B15
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN B14
#define SPI_MISO_PAL_MODE 5


#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DI_PIN B0     // The pin your RGB strip is wired to

#define RGBLED_NUM 8

#define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL 5  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP 

// #define WS2812_PWM_DRIVER PWMD1
// #define WS2812_PWM_CHANNEL 3
// #define WS2812_PWM_PAL_MODE 1
// #define WS2812_DMA_STREAM STM32_DMA2_STREAM5
// #define WS2812_DMA_CHANNEL 6


// #    define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN PAL_LINE(GPIOA, 0)
// #    define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8 // 96MHz / 8 = 12MHz; max supported by MB85R64 is 20MHz
// #    define EXTERNAL_EEPROM_BYTE_COUNT 8192
// #    define EXTERNAL_EEPROM_PAGE_SIZE 64 // does not matter for FRAM, just sets the RAM buffer size in STM32F chip
// #    define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191
// #    define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN PAL_LINE(GPIOB, 12)
// #    define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 2  // 48MHz; max supported by W25Q128JV is 133MHz
// #    define EXTERNAL_FLASH_BYTE_COUNT (16 * 1024 * 1024)  //128Mbit or 16MByte
// #    define EXTERNAL_FLASH_PAGE_SIZE 256
// #    define EXTERNAL_FLASH_SPI_TIMEOUT 200000 //datasheet max