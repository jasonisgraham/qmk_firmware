#pragma once

#include "song_list.h"
#include "config_common.h"

#define GOODBYE_SONG SONG(zelda_puzzle)
#define RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS


#define COMBO_STRICT_TIMER
#define COMBO_TERM 1  // default is 50.  50ms produces false positives when typing kinda fast

/* #define echo false */
/* #define COMBO_COUNT 100 */
/* #define RGBLIGHT_LAYER_BLINK 1 */
/* #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF */

/* #define BACKLIGHT_LEVELS 31 */
/* #define BACKLIGHT_BREATHING */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE


/* #define LEADER_TIMEOUT 1000 */
#define LEADER_NO_TIMEOUT


#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS                                   \
  { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define FORCE_NKRO


#define AUTO_SHIFT_TIMEOUT 150
/* #define AUTO_SHIFT_SPECIAL */

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
/* #define TAPPING_TERM 195 */

#define PERMISSIVE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#undef RGB_MATRIX_VAL_STEP
#define RGB_MATRIX_VAL_STEP 11

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#define NO_AUTO_SHIFT_TAB
#define HOLD_ON_OTHER_KEY_PRESS
/* #define FIRMWARE_VERSION u8"jaa0Y/EPRjD" */
#define RGB_MATRIX_STARTUP_SPD 60



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