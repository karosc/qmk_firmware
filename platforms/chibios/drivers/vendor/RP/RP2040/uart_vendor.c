

#include "quantum.h"

#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "uart.h"

#ifndef SERIAL_DRIVER
#    define SERIAL_DRIVER uart0
#endif


void uart_init_iface(uint32_t baud) {
    static bool is_initialised = false;

    if (!is_initialised) {
        is_initialised = true;

    uart_init(SERIAL_DRIVER,baud);
    
    gpio_set_function(SD_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(SD_RX_PIN, GPIO_FUNC_UART);
 
    }
}

void uart_write_iface(uint8_t data) {
    uart_write_blocking(SERIAL_DRIVER,(const uint8_t *) &data,1);
}

uint8_t uart_read_iface(void) {
    uint8_t res;
    uart_read_blocking(SERIAL_DRIVER, &res, 1);
    return res;
}

void uart_transmit_iface(const uint8_t *data, uint16_t length) {
    uart_write_blocking(SERIAL_DRIVER,data,length);
}

void uart_receive_iface(uint8_t *data, uint16_t length) {
    uart_read_blocking(SERIAL_DRIVER, data, length);
}

bool uart_available_iface(void) {
    return uart_is_readable(SERIAL_DRIVER);
}