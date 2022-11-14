/* Copyright 2021
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>

#include <hal.h>

#if HAL_USE_SERIAL

typedef SerialDriver QMKSerialDriver;
typedef SerialConfig QMKSerialConfig;

#    if !defined(SERIAL_DRIVER)
#        define SERIAL_DRIVER SD1
#    endif

#elif HAL_USE_SIO

typedef SIODriver QMKSerialDriver;
typedef SIOConfig QMKSerialConfig;

#    if !defined(SERIAL_DRIVER)
#        define SERIAL_DRIVER SIOD0
#    endif

#endif

