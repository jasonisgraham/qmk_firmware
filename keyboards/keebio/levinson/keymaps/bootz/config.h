#pragma once
#undef RGBLIGHT_ENABLE


#define I2C_DRIVER I2CD1

#define LEVINSON


#define AUTO_SHIFT_REPEAT
#define MOUSEKEY_MAX_SPEED 2
#define UNICODE_SELECTED_MODES UC_LNX
#define CAPS_WORD_TOGGLE_KEY

#include "../../../common/config.h"
/* /\* Select hand configuration *\/ */
/* // #define MASTER_RIGHT */
/* // #define EE_HANDS */
/* #define RGB_MATRIX_LED_COUNT 24 */


#define WS2812

#define RGBLIGHT_ENABLE

       #define C6_AUDIO

#define RGBLIGHT_LAYERS_RETAIN_VAL

#undef RGBLED_NUM
#define RGBLED_NUM 9


/* #define RGBLIGHT_LIMIT_VAL 150 */
#define DROP_DEFAULT_ANIMATION RGBLIGHT_MODE_BREATHING

/* #define ENCODERS_PAD_A { F4 } */
/* #undef NUM_ENCODERMAP_LAYERS */
/* #define NUM_ENCODERMAP_LAYERS 1 */
