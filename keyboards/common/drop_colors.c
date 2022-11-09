/* int default_rgblight_mode = 2; // RGBLIGHT_MODE_BREATHING; */
int default_rgblight_mode =  1;

void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val);
void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
  rgblight_sethsv_noeeprom(hue, sat, val);
}


layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {

  case 0:
    rgblight_disable();
    break;

  case _LOWER:
    static_kinda_dim(HSV_RED);
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT); */
    break;

  case _ROFI:
    static_kinda_dim(HSV_PURPLE);
    break;

  case _RAISE:
    /* float x[][2] = SONG(ROCK_A_BYE_BABY); */
    /* PLAY_SONG(x);             /\*  *\/ */
    static_kinda_dim(HSV_BLUE);
    break;

  case _EDITING:
    static_kinda_dim(HSV_WHITE);
    break;

  case _HYPER:
    static_kinda_dim(HSV_WHITE);
    break;

  case _MOUSE :
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;


  case _ALL_MODS:
    static_kinda_dim(HSV_YELLOW);
    break;



  case _ALT:
    static_kinda_dim(HSV_GREEN);
    break;

  case _SYSTEM:
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(24);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    break;

  case _ADHOC_SET_HOTKEY:
    rgblight_enable_noeeprom();
    rgblight_sethsv_at(HSV_WHITE, 0);
    rgblight_sethsv_at(HSV_WHITE, 1);
    rgblight_sethsv_at(HSV_WHITE, 2);
    rgblight_sethsv_at(HSV_WHITE, 3);
    rgblight_sethsv_at(HSV_WHITE, 4);
    rgblight_sethsv_at(HSV_RED, 5);
    rgblight_sethsv_at(HSV_RED, 6);
    rgblight_sethsv_at(HSV_WHITE, 7);
    rgblight_sethsv_at(HSV_WHITE, 8);
    break;

  case _SUPER:

    rgblight_enable_noeeprom();
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT); */
    rgblight_sethsv_range(HSV_RED, 0, 0);
    rgblight_sethsv_range(HSV_RED, 1, 10);
    rgblight_sethsv_range(HSV_RED, 2, 1);
    rgblight_sethsv_range(HSV_RED, 3, 0);
    rgblight_sethsv_range(HSV_RED, 4, 6);
    rgblight_sethsv_range(HSV_OFF, 5, 0);
    rgblight_sethsv_range(HSV_OFF, 6, 0);
    rgblight_sethsv_range(HSV_OFF, 7, 11);
    rgblight_sethsv_range(HSV_OFF, 8, 5);

    /* rgblight_sethsv_noeeprom(HSV_RED); */
    break;

  case _WINDOWS:
    static_kinda_dim(HSV_SPRINGGREEN);
    break;


  case _MACROS:
    static_kinda_dim(HSV_PINK);
    break;

  case _SHIFTLOCK:
    // shiftlok
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE); */
    rgblight_set();
    rgblight_mode(42);
    rgblight_enable();

    rgblight_sethsv_at(HSV_BLUE, 0);
    rgblight_sethsv_at(HSV_BLUE, 1);
    rgblight_sethsv_at(HSV_BLUE, 2);
    rgblight_sethsv_at(HSV_BLUE, 3);
    rgblight_sethsv_at(HSV_BLUE, 4);
    rgblight_sethsv_at(HSV_RED, 5);
    rgblight_sethsv_at(HSV_RED, 6);
    rgblight_sethsv_at(HSV_RED, 7);
    rgblight_sethsv_at(HSV_RED, 8);


    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    break;

  /* case 16: */
  /*   rgblight_enable_noeeprom(); */
    /* rgblight_mode_noeeprom(default_rgblight_mode); */
  /*   /\* rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   rgblight_sethsv_noeeprom(HSV_PURPLE); */
  /*   break; */


  case _EMACS:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _WINMOVE:
    static_kinda_dim(HSV_SPRINGGREEN);
    break;


  case _APL:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CORAL);
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); */
    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

  case _APL_RHS:
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_AZURE);
    break;

  case _AUDIO:
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_WHITE);
    break;

  case _BRIGHTNESS:
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

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
