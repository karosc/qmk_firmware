#include "uart.h"

#include "quantum.h"

#include "hardware/uart.h"



#ifndef SERIAL_DRIVER
#    define SERIAL_DRIVER uart0
#endif

#define BAUD_RATE 115200

void uart_init_iface(uint32_t baud) {
    static bool is_initialised = false;

    if (!is_initialised) {
        is_initialised = true;

    uart_init(SERIAL_DRIVER,baud);
    }
}

void uart_write_iface(uint8_t data) {
    //sdPut(&SERIAL_DRIVER, data);
    uart_write_blocking(SERIAL_DRIVER,(const uint8_t *) &data,1);
}

uint8_t uart_read_iface(void) {
    //msg_t res = sdGet(&SERIAL_DRIVER);
    uint8_t *res = 0;
    uart_read_blocking(SERIAL_DRIVER, res, 1);

    return *res;
}

void uart_transmit_iface(const uint8_t *data, uint16_t length) {
    //sdWrite(&SERIAL_DRIVER, data, length);
    uart_write_blocking(SERIAL_DRIVER,data,length);
}

void uart_receive_iface(uint8_t *data, uint16_t length) {
    //sdRead(&SERIAL_DRIVER, data, length);
    uart_read_blocking(SERIAL_DRIVER, data, length);
}

bool uart_available_iface(void) {
    //return !sdGetWouldBlock(&SERIAL_DRIVER);
    return uart_is_readable(SERIAL_DRIVER);

}