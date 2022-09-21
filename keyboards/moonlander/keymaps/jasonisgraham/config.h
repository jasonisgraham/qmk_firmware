#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(OLD_SPICE)
#endif

#undef COMBO_TERM
#define COMBO_TERM 25  // default is 50.  50ms produces false positives when typing kinda fast

#define AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS

/* #define FIRMWARE_VERSION u8"yBwNd/mo7om" */
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define CAPS_LOCK_STATUS
