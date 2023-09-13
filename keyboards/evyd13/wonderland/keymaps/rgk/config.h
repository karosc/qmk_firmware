/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/




#ifndef CONFIG_USER_H
#define CONFIG_USER_H

// #include "config_common.h"

#include "../../config.h"

/* Use I2C or Serial, not both */

//#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT


#define AUTO_SHIFT_TIMEOUT 120
#define NO_AUTO_SHIFT_SPECIAL
// #define MASTER_RIGHT
//define EE_HANDS


/*
#define MOUSEKEY_INTERVAL	16	//Time between cursor movements
#define MOUSEKEY_DELAY	50	//Delay between pressing a movement key and cursor movement
#define MOUSEKEY_MAX_SPEED	5	//Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX	0	//Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_MAX_SPEED	8	//Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40
*/
#endif

