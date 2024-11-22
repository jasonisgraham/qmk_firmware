/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "YPBVQ/YqLQ4"
#define LAYER_STATE_32BIT
#define RGB_MATRIX_STARTUP_SPD 60


#define LEADER_KEY_STRICT_KEY_PROCESSING
/* #define LEADER_NO_TIMEOUT */
#define LEADER_TIMEOUT 200
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#include "../../../../common/config.h"

#undef DEBOUNCE
#define DEBOUNCE 6

#undef TAPPING_TERM
#define TAPPING_TERM 195

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#define FORCE_NKRO


#undef AUTO_SHIFT_TIMEOUT
#define AUTO_SHIFT_TIMEOUT 150

#define NO_AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS

#define COMBO_STRICT_TIMER
#undef COMBO_TERM
#define COMBO_TERM 17  // default is 50.  50ms produces false positives when typing kinda fast
#undef COMBO_COUNT
#define COMBO_COUNT 175
