#pragma once

#include "quantum.h"
#include "uart.h"
#include <hal.h>

#    if !defined(SERIAL_DRIVER)
#        define SERIAL_DRIVER SIOD0
#    endif


#if !defined(USE_GPIOV1)
/* The default PAL alternate modes are used to signal that the pins are used for USART. */
#    if !defined(SD_TX_PAL_MODE)
#        define SD_TX_PAL_MODE 7
#    endif
#    if !defined(SD_RX_PAL_MODE)
#        define SD_RX_PAL_MODE 7
#    endif
#endif

#if !defined(USART_CR1_M0)
#    define USART_CR1_M0 USART_CR1_M // some platforms (f1xx) dont have this so
#endif

#if !defined(SERIAL_USART_CR1)
#    define SERIAL_USART_CR1 (USART_CR1_PCE | USART_CR1_PS | USART_CR1_M0) // parity enable, odd parity, 9 bit length
#endif

#if !defined(SERIAL_USART_CR2)
#    define SERIAL_USART_CR2 (USART_CR2_STOP_1) // 2 stop bits
#endif

#if !defined(SERIAL_USART_CR3)
#    define SERIAL_USART_CR3 0
#endif

#if !defined(SERIAL_USART_TIMEOUT)
#    define SERIAL_USART_TIMEOUT 20
#endif
