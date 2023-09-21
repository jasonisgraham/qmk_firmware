#pragma once

/* #undef UNICODE_SELECTED_MODES */
/* #define UNICODE_SELECTED_MODES UC_LINX */

#ifdef AUDIO_ENABLE
  #include "song_list.h"
#endif
/* #include "user_song_list.c" */
/* #include "config_common.h" */

/* #define GOODBYE_SONG SONG(ZELDA_PUZZLE) */
/* #ifndef RGBLIGHT_ENABLE */
/* #define RGBLIGHT_ENABLE */
/* #endif */
/* #define RGBLIGHT_ANIMATIONS */

#undef MAX_LAYER
#define MAX_LAYER 32
#define LAYER_STATE_32BIT

#define COMBO_STRICT_TIMER
#undef COMBO_TERM
#define COMBO_TERM 17  // default is 50.  50ms produces false positives when typing kinda fast
#undef COMBO_COUNT
#define COMBO_COUNT 200

/* #define echo false */
/* #define RGBLIGHT_LAYER_BLINK 1 */
/* #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF */

/* #define BACKLIGHT_LEVELS 31 */
/* #define BACKLIGHT_BREATHING */
/* #define RGBLIGHT_LAYERS */
/* #define RGBLIGHT_LAYER_BLINK */
/* #define RGBLIGHT_ANIMATIONS */
/* #define RGBLIGHT_EFFECT_ALTERNATING */
/* #define RGBLIGHT_EFFECT_BREATHING */
/* #define RGBLIGHT_EFFECT_CHRISTMAS */
/* #define RGBLIGHT_EFFECT_KNIGHT */
/* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_RGB_TEST */
/* #define RGBLIGHT_EFFECT_SNAKE */
/* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
/* #define RGBLIGHT_EFFECT_TWINKLE */



#define LEADER_KEY_STRICT_KEY_PROCESSING
#define LEADER_NO_TIMEOUT
/* #define LEADER_TIMEOUT 200 */
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT



/* #ifdef AUDIO_ENABLE */
/* #    define STARTUP_SONG SONG(PREONIC_SOUND) */
/* // #define STARTUP_SONG SONG(NO_SOUND) */

/* #    define DEFAULT_LAYER_SONGS                                   \ */
/*   { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) } */

/* #define MUSIC_MASK (keycode != KC_NO) */
/* #endif */

#define FORCE_NKRO


#undef AUTO_SHIFT_TIMEOUT
#define AUTO_SHIFT_TIMEOUT 150
/* #define AUTO_SHIFT_SPECIAL */

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define PERMISSIVE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#undef RGB_MATRIX_VAL_STEP
#define RGB_MATRIX_VAL_STEP 11

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 2
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 25
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 30


#define NO_AUTO_SHIFT_TAB
#define HOLD_ON_OTHER_KEY_PRESS
/* #define FIRMWARE_VERSION u8"jaa0Y/EPRjD" */
#define RGB_MATRIX_STARTUP_SPD 60

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

/*
 * MIDI options
 */

/* enable basic MIDI features:
 #@109  - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#ifndef WEBUSB_ENABLE
#    define WEBUSB_PAIR KC_NO
#endif


#define MACRO_WAIT 10

#define AUTO_SHIFT_REPEAT
