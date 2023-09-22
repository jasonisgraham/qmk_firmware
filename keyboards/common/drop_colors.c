#ifdef RGBLIGHT_ENABLE
#ifdef AUDIO_ENABLE
#include "user_song_list.c"
#endif

#ifndef DROP_DEFAULT_ANIMATION
#define DROP_DEFAULT_ANIMATION 0
#endif

static int DROP_CURRENT_ANIMATION = DROP_DEFAULT_ANIMATION;//RGBLIGHT_MODE_STATIC_LIGHT;
/* static int DROP_CURRENT_ANIMATION = DROP_CURRENT_ANIMATION; // 2; // RGBLIGHT_MODE_BREATHING; */
/* int DROP_CURRENT_ANIMATION =  1; */

void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val);
void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
  rgblight_mode_noeeprom(DROP_CURRENT_ANIMATION);
  rgblight_sethsv_noeeprom(hue, sat, val);
}


layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {

  case _BASE:
    rgblight_disable();
    /* rgblight_mode_noeeprom(0); */
    break;

  case _LOWER:
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);
    /* rgblight_mode(RGBLIGHT_MODE_KNIGHT); */
    break;

  case _ROFI:
    rgblight_mode(DROP_CURRENT_ANIMATION);
    static_kinda_dim(HSV_PURPLE);
    break;

  case _NUMLOCK:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_TWINKLE);
    for (int i=0; i< RGBLED_NUM; i=i+3) {
      rgblight_sethsv_at(HSV_WHITE, i);
      rgblight_sethsv_at(HSV_BLACK, i+1);
      rgblight_sethsv_at(HSV_RED, i+2);
    }
    break;

  case _RAISE:
    /* float x[][2] = SONG(ROCK_A_BYE_BABY); */
    /* PLAY_SONG(x);             /\*  *\/ */
    rgblight_enable_noeeprom();
    rgblight_mode(DROP_CURRENT_ANIMATION);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _WEB:
    for (int i=0; i< RGBLED_NUM; i=i+2) {
      rgblight_sethsv_at(HSV_WHITE, i);
      rgblight_sethsv_at(HSV_PURPLE, i+1);
    }
    break;

  case _CODE:
    rgblight_enable_noeeprom();
    for (int i=0; i< RGBLED_NUM; i=i+2) {
      rgblight_sethsv_at(HSV_YELLOW, i);
      rgblight_sethsv_at(HSV_WHITE, i+1);
    }
    break;


  case _EMACS_SELECT:
    for (int i=0; i< RGBLED_NUM; i=i+2) {
      rgblight_sethsv_at(HSV_PURPLE, i);
      rgblight_sethsv_at(HSV_WHITE, i+1);
    }
    break;




  case _FILES:
    for (int i=0; i< RGBLED_NUM; i=i+2) {
      rgblight_sethsv_at(HSV_PURPLE, i);
      rgblight_sethsv_at(HSV_YELLOW, i+1);
    }
    break;


  case _HYPER:
    rgblight_enable_noeeprom();
    rgblight_mode(DROP_CURRENT_ANIMATION);
    rgblight_sethsv_noeeprom(HSV_WHITE);
    break;

  case _EDITING:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    rgblight_sethsv_noeeprom(180, 255, 255);
    break;

  case _SA:
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    static_kinda_dim(HSV_WHITE);
    break;

  case _MOUSE :
    rgblight_enable_noeeprom();
    rgblight_mode(1);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  /* case _CTRL: */
  /*   rgblight_enable_noeeprom(); */
  /*   rgblight_mode(RGBLIGHT_MODE_KNIGHT); */
  /*   rgblight_sethsv_noeeprom(HSV_MAGENTA); */
  /*   break; */

  case _ALL_MODS:
    static_kinda_dim(HSV_YELLOW);
    break;



  /* case _ALT: */
  /*   static_kinda_dim(HSV_GREEN); */
  /*   break; */

  case _SYSTEM:
    rgblight_enable_noeeprom();
    rgblight_mode(24);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    break;

  case _ADHOC_SET_HOTKEY:
    rgblight_disable_noeeprom();
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(0);

    #ifdef AUDIO_ENABLE
    /* PLAY_SONG(major_sound); */
    #endif

    #ifdef LEVINSON
    for (int i=0; i< RGBLED_NUM; i=i+2) {
      rgblight_sethsv_at(HSV_BLUE, i);
      rgblight_sethsv_at(HSV_RED, i+1);
    }
    #endif

#ifndef LEVINSON
    sethsv(HSV_BLUE, (LED_TYPE *)&led[0]);
    sethsv(HSV_RED, (LED_TYPE *)&led[1]);
    sethsv(HSV_BLUE, (LED_TYPE *)&led[2]);
    sethsv(HSV_RED, (LED_TYPE *)&led[3]);
    sethsv(HSV_BLUE, (LED_TYPE *)&led[4]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[5]);
    sethsv(HSV_BLUE,   (LED_TYPE *)&led[6]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[7]);
    sethsv(HSV_BLUE,   (LED_TYPE *)&led[8]);
    rgblight_set();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    #endif

    break;

  case _SUPER:
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT); */
    static_kinda_dim(HSV_PINK);
    break;

  case _WINDOWS:
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    break;


  case _MACROS:
    rgblight_mode(DROP_CURRENT_ANIMATION);
    static_kinda_dim(HSV_PINK);
    break;

  case _LAYER_LOCK:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    rgblight_sethsv_noeeprom(HSV_PURPLE);

    break;

  case _SHIFTLOCK:
    // shiftlok
/* #ifdef AUDIO_ENABLE */
/*     PLAY_SONG(caps_lock_on_sound); */
/* #endif */

    rgblight_disable_noeeprom();
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(0);
    #ifdef LEVINSON
    for (int i=0; i<RGBLED_NUM; i=i+3) {
      /* printf("i is %u\n", i); */
      rgblight_sethsv_at(HSV_PINK, i);
      if (i+1 < RGBLED_NUM) {
      rgblight_sethsv_at(HSV_RED, i+1);
      }
      if (i+2 < RGBLED_NUM) {
      rgblight_sethsv_at(HSV_WHITE, i+2);
      }
    }
    /* rgblight_sethsv_at(HSV_RED, (LED_TYPE *)&led[25]); */
    /* rgblight_set_clipping_range(12,13); */
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING); */
    #endif

    #ifndef LEVINSON
    sethsv(HSV_PINK, (LED_TYPE *)&led[0]);
    sethsv(HSV_RED, (LED_TYPE *)&led[1]);
    sethsv(HSV_WHITE, (LED_TYPE *)&led[2]);
    sethsv(HSV_PINK, (LED_TYPE *)&led[3]);
    sethsv(HSV_WHITE, (LED_TYPE *)&led[4]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[5]);
    sethsv(HSV_PINK,   (LED_TYPE *)&led[6]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[7]);
    sethsv(HSV_PINK,   (LED_TYPE *)&led[8]);
    #endif
    /* rgblight_set(); */
    break;

  /* case 16: */
  /*   rgblight_enable_noeeprom(); */
    /* rgblight_mode(DROP_CURRENT_ANIMATION); */
  /*   /\* rgblight_mode(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   rgblight_sethsv_noeeprom(HSV_PURPLE); */
  /*   break; */

  case _EMACS:
    rgblight_mode(RGBLIGHT_MODE_ALTERNATING);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _WINMOVE:
    rgblight_mode(DROP_CURRENT_ANIMATION);
    static_kinda_dim(HSV_SPRINGGREEN);
    break;

  case _WINMOVE_MONITOR:
    rgblight_mode(RGBLIGHT_MODE_ALTERNATING);
    static_kinda_dim(HSV_RED);
    break;



  /* case _APL: */
  /*   rgblight_mode(RGBLIGHT_MODE_SNAKE); */
  /*   rgblight_enable_noeeprom(); */
  /*   rgblight_sethsv_noeeprom(HSV_CORAL); */
  /*   /\* rgblight_mode(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   /\* rgblight_sethsv_noeeprom(HSV_GREEN); *\/ */
  /*   break; */

  /* case _APL_RHS: */
  /*   rgblight_mode(RGBLIGHT_MODE_SNAKE); */
  /*   rgblight_enable_noeeprom(); */
  /*   rgblight_sethsv_noeeprom(HSV_AZURE); */
  /*   break; */

  /* case _AUDIO: */
  /*   rgblight_enable_noeeprom(); */
  /*   rgblight_mode(RGBLIGHT_MODE_SNAKE); */
  /*   rgblight_sethsv_noeeprom(HSV_GREEN); */
  /*   break; */

  /* case _BRIGHTNESS: */
  /*   rgblight_enable_noeeprom(); */
  /*   rgblight_mode(RGBLIGHT_MODE_SNAKE); */
  /*   rgblight_sethsv_noeeprom(HSV_BLUE); */
  /*   break; */

  default:
    // White
    //Read RGB Light State
    /* rgblight_config.raw = eeconfig_read_rgblight(); */
    /* //If enabled, set white */
    /* if (rgblight_config.enable) { */
    /*   rgblight_sethsv_noeeprom(HSV_WHITE); */
    /* } else { //Otherwise go back to disabled */
    /*   rgblight_disable_noeeprom(); */
    /* } */
    break;
  }
  return state;
}

#endif
