DEFAULT_FOLDER = phazerdek/stm

# MCU name
MCU = STM32F411
##BOARD = GENERIC_STM32_F411XE
BOARD = BONSAI_C4
# Bootloader selection
BOOTLOADER = stm32-dfu

# CONVERT_TO = bonsai_c4

RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = ws2812
WS2812_DRIVER = pwm

# EEPROM_DRIVER = spi
RAW_ENABLE = yes
CONSOLE_ENABLE = no
UART_ENABLE = yes

AUDIO_DRIVER = pwm_hardware
AUDIO_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += ssd1351_spi

SRC += ui.c

VPATH += keyboards/phazerdek/stm/graphics
SRC += \
    atom_resize.qgf.c \
    lock-caps-ON.qgf.c \
    lock-scrl-ON.qgf.c \
    lock-num-ON.qgf.c \
    lock-caps-OFF.qgf.c \
    lock-scrl-OFF.qgf.c \
    lock-num-OFF.qgf.c \
    thintel15.qff.c

# QUANTUM_LIB_SRC += uart.c