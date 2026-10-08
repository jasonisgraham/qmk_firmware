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
#define TAPPING_TERM 200

#undef IGNORE_MOD_TAP_INTERRUPT


/* #define FLOW_TAP_TERM_PER_KEY */
/* #define FLOW_TAP_TERM 100 */
#undef CHORDAL_HOLD
#undef SPECULATIVE_HOLD

#undef PERMISSIVE_HOLD
#undef HOLD_ON_OTHER_KEY_PRESS
