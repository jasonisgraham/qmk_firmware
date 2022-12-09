#ifdef RGBLIGHT_ENABLE
#include "user_song_list.c"
static int DROP_DEFAULT_ANIMATION = 0;//RGBLIGHT_MODE_STATIC_LIGHT;
/* static int DROP_DEFAULT_ANIMATION = DROP_DEFAULT_ANIMATION; // 2; // RGBLIGHT_MODE_BREATHING; */
/* int DROP_DEFAULT_ANIMATION =  1; */

void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val);
void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
  rgblight_mode_noeeprom(DROP_DEFAULT_ANIMATION);
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
    rgblight_mode(DROP_DEFAULT_ANIMATION);
    rgblight_sethsv_noeeprom(HSV_RED);
    /* rgblight_mode(RGBLIGHT_MODE_KNIGHT); */
    break;

  case _ROFI:
    static_kinda_dim(HSV_PURPLE);
    break;

  case _RAISE:
    /* float x[][2] = SONG(ROCK_A_BYE_BABY); */
    /* PLAY_SONG(x);             /\*  *\/ */
    rgblight_enable_noeeprom();
    rgblight_mode(DROP_DEFAULT_ANIMATION);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _HYPER:

  case _EDITING:
    static_kinda_dim(HSV_WHITE);
    break;

  case _SA:
    static_kinda_dim(HSV_WHITE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    break;

  case _MOUSE :
    rgblight_enable_noeeprom();
    rgblight_mode(1);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;


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
    break;


  case _ADHOC_SET_HOTKEY:
    rgblight_disable_noeeprom();
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(0);
    /* PLAY_SONG(major_sound); */
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
    static_kinda_dim(HSV_PINK);
    break;

  case _SHIFTLOCK:
    // shiftlok
    rgblight_disable_noeeprom();
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(0);
    sethsv(HSV_PINK, (LED_TYPE *)&led[0]);
    sethsv(HSV_RED, (LED_TYPE *)&led[1]);
    sethsv(HSV_WHITE, (LED_TYPE *)&led[2]);
    sethsv(HSV_PINK, (LED_TYPE *)&led[3]);
    sethsv(HSV_WHITE, (LED_TYPE *)&led[4]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[5]);
    sethsv(HSV_PINK,   (LED_TYPE *)&led[6]);
    sethsv(HSV_RED,   (LED_TYPE *)&led[7]);
    sethsv(HSV_PINK,   (LED_TYPE *)&led[8]);
    rgblight_set();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    /* rgblight_sethsv_range(HSV_OFF, 6, 0); */
    /* rgblight_sethsv_range(HSV_OFF,   5, 0); */
    /* rgblight_sethsv_range(HSV_RED, 4, 6); */
    /* rgblight_sethsv_range(HSV_RED, 3, 0); */
    /* rgblight_sethsv_range(HSV_RED,   2, 1); */
    /* rgblight_sethsv_range(HSV_RED, 1, 10); */
    /* rgblight_sethsv_range(HSV_OFF, 8, 5); */
    /* rgblight_sethsv_range(HSV_OFF,   7, 11); */
    /* rgblight_sethsv_range(HSV_RED,   0, 0); */

    /* rgblight_mode(RGBLIGHT_MODE_SNAKE); */
    /* rgblight_enable_noeeprom(); */
    /* rgblight_sethsv_noeeprom(HSV_RED); */

    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    break;

  /* case 16: */
  /*   rgblight_enable_noeeprom(); */
    /* rgblight_mode(DROP_DEFAULT_ANIMATION); */
  /*   /\* rgblight_mode(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   rgblight_sethsv_noeeprom(HSV_PURPLE); */
  /*   break; */


  case _EMACS:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _WINMOVE:
    static_kinda_dim(HSV_SPRINGGREEN);
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
