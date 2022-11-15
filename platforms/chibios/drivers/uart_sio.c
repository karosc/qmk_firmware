#include "quantum.h"
#include "uart.h"
#include <hal.h>


#if defined(MCU_STM32) /* STM32 MCUs */
static SIOConfig serial_config = {
    .baud = (SERIAL_DEFAULT_BITRATE),
    .cr1   = (SERIAL_USART_CR1),
    .cr2   = (SERIAL_USART_CR2),
    .cr3  = (SERIAL_USART_CR3)

};
#elif defined(MCU_RP) /* Raspberry Pi MCUs */
/* USART in 8E2 config with RX and TX FIFOs enabled. */
// clang-format off
static SIOConfig serial_config = {
    .baud = (SERIAL_DEFAULT_BITRATE),
    .UARTLCR_H = UART_UARTLCR_H_WLEN_8BITS | UART_UARTLCR_H_PEN | UART_UARTLCR_H_STP2 | UART_UARTLCR_H_FEN,
    .UARTCR = 0U,
    .UARTIFLS = UART_UARTIFLS_RXIFLSEL_1_8F | UART_UARTIFLS_TXIFLSEL_1_8E,
    .UARTDMACR = 0U
};

#else
#    error MCU Familiy not supported by default, supply your own serial_config by defining SERIAL_USART_CONFIG in your keyboard files.
#endif

static SIODriver* serial_driver = (SIODriver*)&SERIAL_DRIVER;

void clear_rx_evt_cb(SIODriver* siop) {
    osalSysLockFromISR();
    /* If errors occured during transactions this callback is invoked. We just
     * clear the error sources and move on. We rely on the fact that we check
     * for the success of the transaction by comparing the received/send bytes
     * with the actual received/send bytes in the send/receive functions. */
    sioGetAndClearEventsI(serial_driver);
    osalSysUnlockFromISR();
}

static const SIOOperation serial_usart_operation = {.rx_cb = NULL, .rx_idle_cb = NULL, .tx_cb = NULL, .tx_end_cb = NULL, .rx_evt_cb = &clear_rx_evt_cb};


void uart_init_iface(uint32_t baud) {
    static bool is_initialised = false;

    if (!is_initialised) {
        is_initialised = true;


        serial_config.baud = baud;

#        if defined(MCU_STM32) /* STM32 MCUs */
#            if defined(USE_GPIOV1)
        palSetLineMode(SD_TX_PIN, PAL_MODE_ALTERNATE_PUSHPULL);
        palSetLineMode(SD_RX_PIN, PAL_MODE_INPUT);
#            else
        palSetLineMode(SD_TX_PIN, PAL_MODE_ALTERNATE(SERIAL_USART_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
        palSetLineMode(SD_RX_PIN, PAL_MODE_ALTERNATE(SERIAL_USART_RX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
#            endif

#        elif defined(MCU_RP) /* Raspberry Pi MCUs */
        palSetLineMode(SD_TX_PIN, PAL_MODE_ALTERNATE_UART);
        palSetLineMode(SD_RX_PIN, PAL_MODE_ALTERNATE_UART);
#        else
#            pragma message "usart_init: MCU Familiy not supported by default, please supply your own init code by implementing usart_init() in your keyboard files."
#        endif

    sioStart(&SERIAL_DRIVER, &serial_config);
    sioStartOperation(&SERIAL_DRIVER, &serial_usart_operation);
    }
}


void uart_write_iface(uint8_t data) {
    sioPutX(&SERIAL_DRIVER, data);
}

uint8_t uart_read_iface(void) {
    msg_t res = sioGetX(&SERIAL_DRIVER);

    return (uint8_t)res;
}

void uart_transmit_iface(const uint8_t *data, uint16_t length) {
    // sdWrite(&SERIAL_DRIVER, data, length);
}

void uart_receive_iface(uint8_t *data, uint16_t length) {
    // sdRead(&SERIAL_DRIVER, data, length);
}

bool uart_available_iface(void) {
    return !sioIsRXEmptyX(&SERIAL_DRIVER);
    // return !sdGetWouldBlock(&SERIAL_DRIVER);
}