/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

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

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
// for elite-pi {D4, D7, D8, D9 }
#define MATRIX_ROW_PINS { D4, E6, B4, B5 }
// for elite-pi { D0, A3/D29, A0/D26, D22, D20, D23 }
#define MATRIX_COL_PINS { D3, F4, F7, B1, B3, B2 }


// for elite-pi {D4, D23, D20, D22 }
#define MATRIX_ROW_PINS_RIGHT { D4, B2, B3, B1 }
// for elite-pi {D29, D26, D0, D9, D8, D7}
#define MATRIX_COL_PINS_RIGHT { F4, F7, D3, B5, B4, E6 }
#define SPLIT_HAND_PIN D2

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define LEVINSON
#define RGB_DI_PIN B6
/* #define RGB_DI_PIN F1 */
#define RGBLED_NUM 31    // Number of LEDs
#define RGBLED_SPLIT { 18, 13 }
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_xxxx
#define RGBLIGHT_EFFECT_TWINKLE


/* Backlight LEDs */
/* #define BACKLIGHT_PIN B6 */
/* #define BACKLIGHT_LEVELS 7 */
