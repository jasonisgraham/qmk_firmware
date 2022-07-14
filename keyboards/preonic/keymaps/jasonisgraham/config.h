/* #pragma once */

/* #include "song_list.h" */
/* #include "config_common.h" */

#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }


#define MOUSEKEY_MAX_SPEED 2
/* #define COMBO_COUNT 50 */

/* /\* #define BACKLIGHT_LEVELS 31 *\/ */
/* /\* #define BACKLIGHT_BREATHING *\/ */
/* /\* #define RGBLIGHT_LAYERS *\/ */


/* #define LEADER_TIMEOUT 300 */

/* #ifdef AUDIO_ENABLE */
/* #    define STARTUP_SONG SONG(PREONIC_SOUND) */
/* // #define STARTUP_SONG SONG(NO_SOUND) */

/* #    define DEFAULT_LAYER_SONGS                                   \ */
/*   { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) } */
/* #endif */

/* #define MUSIC_MASK (keycode != KC_NO) */

/* #define FORCE_NKRO */


/* #define AUTO_SHIFT_TIMEOUT 150 */
/* /\* #define AUTO_SHIFT_SPECIAL *\/ */

/* /\* */
/*   Set any config.h overrides for your specific keymap here. */
/*   See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file */
/* *\/ */
/* #define ORYX_CONFIGURATOR */
/* #undef TAPPING_TERM */
/* #define TAPPING_TERM 195 */

/* #define PERMISSIVE_HOLD */

/* #undef IGNORE_MOD_TAP_INTERRUPT */

/* #undef RGB_MATRIX_VAL_STEP */
/* #define RGB_MATRIX_VAL_STEP 11 */

/* #define USB_SUSPEND_WAKEUP_DELAY 0 */
/* #undef MOUSEKEY_INTERVAL */
/* #define MOUSEKEY_INTERVAL 16 */

/* #define NO_AUTO_SHIFT_TAB */
/* #define HOLD_ON_OTHER_KEY_PRESS */
/* /\* #define FIRMWARE_VERSION u8"jaa0Y/EPRjD" *\/ */
/* #define RGB_MATRIX_STARTUP_SPD 60 */



/* /\* */
/*  * MIDI options */
/*  *\/ */

/* /\* enable basic MIDI features: */
/*  #@109  - MIDI notes can be sent when in Music mode is on */
/* *\/ */

/* #define MIDI_BASIC */

/* /\* enable advanced MIDI features: */
/*    - MIDI notes can be added to the keymap */
/*    - Octave shift and transpose */
/*    - Virtual sustain, portamento, and modulation wheel */
/*    - etc. */
/* *\/ */
/* #define MIDI_ADVANCED */

/* /\* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) *\/ */
/* //#define MIDI_TONE_KEYCODE_OCTAVES 2 */

/* #ifndef WEBUSB_ENABLE */
/* #    define WEBUSB_PAIR KC_NO */
/* #endif */
