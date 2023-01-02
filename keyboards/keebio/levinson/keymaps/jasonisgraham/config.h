#pragma once
#undef RGBLIGHT_ENABLE

#define I2C_DRIVER I2CD1

#define AUTO_SHIFT_REPEAT
#define MOUSEKEY_MAX_SPEED 2
#define UNICODE_SELECTED_MODES UC_LNX
#define CAPS_WORD_TOGGLE_KEY

/* #define RGBLIGHT_EFFECT_SNAKE */
/* #define RGBLIGHT_EFFECT_BREATHING */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* /\* #define RGBLIGHT_MODE_STATIC_LIGHT *\/ */
/* /\* #define RGBLIGHT_MODE_RAINBOW_MOOD *\/ */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_KNIGHT */
/* #define RGBLIGHT_EFFECT_CHRISTMAS */
/* #define RGBLIGHT_MODE_STATIC_GRADIENT */
/* /\* #define RGBLIGHT_MODE_RGB_TEST *\/ */
/* /\* #define RGBLIGHT_MODE_ALTERNATING *\/ */
/* #define RGBLIGHT_EFFECT_TWINKLE */


/* #define ENABLE_RGB_MATRIX_STAR_LIGHT */
/* #define ENABLE_RGB_MATRIX_DUAL_SAT_STAR_LIGHT */
/* #define ENABLE_RGB_MATRIX_DUAL_HUE_STAR_LIGHT */

#include "../../../common/config.h"

/* /\* */
/* This is the c configuration file for the keymap */

/* Copyright 2012 Jun Wako <wakojun@gmail.com> */
/* Copyright 2015 Jack Humbert */
/* Copyright 2018 Danny Nguyen <danny@keeb.io> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 2 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/* *\/ */

/* #pragma once */

/* // #define USE_I2C */

/* /\* Select hand configuration *\/ */
/* // #define MASTER_RIGHT */
/* // #define EE_HANDS */
#define RGB_MATRIX_LED_COUNT 24


/* #define WS2812 */

/* #define I2C_DRIVER I2CD1 */
/* #define RGB_MATRIX_LED_COUNT 24 */
/* #define DRIVER_LED_TOTAL 24 */
/* #define DRIVER_COUNT 1 */

/* #define RGBLIGHT_ENABLE */
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
/* #define RGBLIGHT_MODE_STATIC_LIGHT */
/* #define RGBLIGHT_MODE_RAINBOW_MOOD */
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_MODE_STATIC_GRADIENT
/* #define RGBLIGHT_MODE_RGB_TEST */
/* #define RGBLIGHT_MODE_ALTERNATING */
#define RGBLIGHT_EFFECT_TWINKLE


