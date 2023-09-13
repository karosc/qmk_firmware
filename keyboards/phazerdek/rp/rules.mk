MCU = RP2040
#BOARD = GENERIC_RP_RP2040
BOOTLOADER = rp2040

RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812
WS2812_DRIVER = vendor
CONSOLE_ENABLE = yes
UART_ENABLE = yes
# UART_DRIVER = sio
UART_DRIVER = vendor

AUDIO_DRIVER = pwm_hardware
AUDIO_ENABLE = yes


QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = ssd1351_spi

SRC += ui.c

#QUANTUM_LIB_SRC += uart_vendor.c