#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(OLD_SPICE)
#endif

#undef COMBO_TERM
#define COMBO_TERM 25  // default is 50.  50ms produces false positives when typing kinda fast

#define AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
