#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 195

#define PERMISSIVE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#undef RGB_MATRIX_VAL_STEP
#define RGB_MATRIX_VAL_STEP 11

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#define NO_AUTO_SHIFT_TAB
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"jaa0Y/9Jq67"
#define RGB_MATRIX_STARTUP_SPD 60
