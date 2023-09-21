/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#define JSG_VOYAGER 1

#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "YPBVQ/B4OXMQ"
#define LAYER_STATE_32BIT

#define RGB_MATRIX_STARTUP_SPD 60


#include "../../../../common/config.h"

#undef DEBOUNCE
#define DEBOUNCE 2

#undef TAPPING_TERM
#define TAPPING_TERM 195

#undef IGNORE_MOD_TAP_INTERRUPT

/* #undef TAPPING_TOGGLE */
/* #define TAPPING_TOGGLE 1 */

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0


#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 20

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 30

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 50

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 4

#define FORCE_NKRO


#undef AUTO_SHIFT_TIMEOUT
#define AUTO_SHIFT_TIMEOUT 150

#define NO_AUTO_SHIFT_TAB
/* #define CAPS_LOCK_STATUS */
#define HOLD_ON_OTHER_KEY_PRESS

/* #define COMBO_STRICT_TIMER */
#undef COMBO_TERM
#define COMBO_TERM 37  // default is 50.  50ms produces false positives when typing kinda fast
#undef COMBO_COUNT
#define COMBO_COUNT 300

#define AUTO_SHIFT_REPEAT
