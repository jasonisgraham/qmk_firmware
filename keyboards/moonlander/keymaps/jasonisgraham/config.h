#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(OLD_SPICE)
#endif
#include "../../../common/config.h"

#define MOONLANDER

#define DRIVER_LED_TOTAL 72

#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 6

/* #undef TAPPING_TERM */
/* #define TAPPING_TERM 195 */

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#define NO_AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"yBwNd/gEveM"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define RGB_MATRIX_STARTUP_SPD 60


#undef COMBO_TERM
#define COMBO_TERM 25  // default is 50.  50ms produces false positives when typing kinda fast

