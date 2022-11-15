#include "uart.h"
#include "quantum.h"

void init_uart(uint32_t baud) {
    uart_init_iface(baud);
}

void uart_write(uint8_t data) {
    uart_write_iface(data);
}

uint8_t uart_read(void) {
    return uart_read_iface();
}

void uart_transmit(const uint8_t *data, uint16_t length) {
    uart_transmit_iface(data, length);
}

void uart_receive(uint8_t *data, uint16_t length) {
    uart_receive_iface(data, length);
}

bool uart_available(void) {
    return uart_available_iface();
}
