#pragma once

#include_next <mcuconf.h>


#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_SPI_USE_SPI2
#define STM32_SPI_USE_SPI2 TRUE

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1                  TRUE
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE


// #undef STM32_GPT_USE_TIM5
// #define STM32_GPT_USE_TIM5                  TRUE

// #undef STM32_DAC_USE_DAC1_CH1
// #define STM32_DAC_USE_DAC1_CH1              TRUE
// // #undef STM32_DAC_USE_DAC1_CH2
// // #define STM32_DAC_USE_DAC1_CH2              TRUE
// #undef STM32_GPT_USE_TIM6
// #define STM32_GPT_USE_TIM6                  TRUE
// // #undef STM32_GPT_USE_TIM7
// // #define STM32_GPT_USE_TIM7                  TRUE
// #undef STM32_GPT_USE_TIM8
// #define STM32_GPT_USE_TIM8                  TRUE