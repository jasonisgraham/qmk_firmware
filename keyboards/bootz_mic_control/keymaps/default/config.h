#pragma once

/* #define MATRIX_ROWS 1 */
/* #define MATRIX_COLS 1 */

/* #define MATRIX_ROW_PINS { D4 } */
/* #define MATRIX_COL_PINS { D3 } */


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
#define RGB_DI_PIN B6
#define RGBLED_NUM 9
#define RGBLED_SPLIT { 18, 13 }
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_xxxx
#define RGBLIGHT_EFFECT_TWINKLE


/* Backlight LEDs */
#define BACKLIGHT_PIN B6
/* #define BACKLIGHT_LEVELS 7 */
