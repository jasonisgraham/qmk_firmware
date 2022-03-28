/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#include "config_common.h"

#define COMBO_COUNT 50
#define FORCE_NKRO


#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 6

#undef TAPPING_TERM
#define TAPPING_TERM 195

#define PERMISSIVE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#define NO_AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"yBwNd/qD05Z"
#define RGB_MATRIX_STARTUP_SPD 60
