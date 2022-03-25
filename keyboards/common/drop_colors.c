/* int default_rgblight_mode = 2; // RGBLIGHT_MODE_BREATHING; */
int default_rgblight_mode =  1;

void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val);
void static_kinda_dim(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_enable_noeeprom();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom(hue, sat, val);

  /* rgblight_sethsv_range(HSV_OFF, 6, 0); */
  /* rgblight_sethsv_range(HSV_OFF,   5, 0); */
  /* rgblight_sethsv_range(hue, sat, val, 4, 6); */
  /* rgblight_sethsv_range(hue, sat, val, 3, 0); */
  /* rgblight_sethsv_range(hue, sat, val,   2, 1); */
  /* rgblight_sethsv_range(hue, sat, val, 1, 10); */
  /* rgblight_sethsv_range(HSV_OFF, 8, 5); */
  /* rgblight_sethsv_range(HSV_OFF,   7, 11); */
  /* rgblight_sethsv_range(hue, sat, val,   0, 0); */

}


layer_state_t layer_state_set_user(layer_state_t state) {
  /* float x[][2] = SONG(zelda); */

  /* rgblight_config_t rgblight_config; */

  /* if (do_breathing) { */
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
  /* } else { */
    /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
  /* } */

  switch(biton32(state)) {
  case _CTRL:
    static_kinda_dim(HSV_CHARTREUSE);
    break;

  case 0:
    rgblight_disable();
    /* rgblight_sethsv_noeeprom(DROP_LAYER_0_COLOR); */
    /* rgblight_sethsv(); */
    /* rgblight_set_mode(DROP_LAYER_0_COLOR) */
    /* rgblight_mode(DROP_LAYER_0_ANIMATION); */
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */

    /* rgblight_sethsv_at(HSV_WHITE, 0); // led 0 */
    /* rgblight_sethsv_at(HSV_RED,   1); // led 1 */
    /* rgblight_sethsv_at(HSV_GREEN, 2); // led 2 */
    /* rgblight_sethsv_at(HSV_PURPLE, 3); // led 2 */
    /* rgblight_sethsv_at(HSV_YELLOW, 4); // led 2 */
    /* rgblight_sethsv_at(HSV_BLUE, 5); // led 2 */
    /* rgblight_sethsv_at(HSV_WHITE, 6); // led 2 */
    /* rgblight_sethsv_at(HSV_PURPLE, 7); // led 2 */
    /* rgblight_sethsv_noeeprom(HSV_WHITE); */

    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD); */
    /* rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT); */
    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    /* rgblight_sethsv_noeeprom(HSV_OFF); */
    /* rgblight_mode(default_rgblight_mode); */
    break;

  case _LOWER:
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
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
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _HYPER:
    static_kinda_dim(HSV_WHITE);
    break;

  case _MOUSE :
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;


  case _ALL_MODS:
    static_kinda_dim(HSV_YELLOW);
    break;

  case _MENU:
    static_kinda_dim(HSV_PINK);
    break;


  case _ALT:
    static_kinda_dim(HSV_GREEN);
    break;

  case _SYSTEM:
    rgblight_enable_noeeprom();
    rgblight_mode(24);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    break;

  case _SUPER:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT);
    rgblight_sethsv_noeeprom(HSV_RED);
    break;

  case _WINDOWS:
    // windows
    rgblight_enable_noeeprom();
    /* rgblight_mode(default_rgblight_mode); */
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
    break;


  case _MACROS:
    static_kinda_dim(HSV_PINK);
    break;

  case _SHIFTLOCK:
    // shiftlok
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_OFF);
    rgblight_sethsv_range(HSV_OFF, 6, 0);
    rgblight_sethsv_range(HSV_OFF,   5, 0);
    rgblight_sethsv_range(HSV_RED, 4, 6);
    rgblight_sethsv_range(HSV_RED, 3, 0);
    rgblight_sethsv_range(HSV_RED,   2, 1);
    rgblight_sethsv_range(HSV_RED, 1, 10);
    rgblight_sethsv_range(HSV_OFF, 8, 5);
    rgblight_sethsv_range(HSV_OFF,   7, 11);
    rgblight_sethsv_range(HSV_RED,   0, 0);

    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_PINK);

    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    break;

  /* case 16: */
  /*   rgblight_enable_noeeprom(); */
    /* rgblight_mode(default_rgblight_mode); */
  /*   /\* rgblight_mode(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   rgblight_sethsv_noeeprom(HSV_PURPLE); */
  /*   break; */

  case _EDITING:
    static_kinda_dim(HSV_PLUM);
    break;

  case _WINMOVE:
    static_kinda_dim(HSV_SPRINGGREEN);
    break;


  case _LAYER19:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CORAL);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

  case _EMACS_SEL_WINDOW:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_AZURE);
    break;

  case _GAUTH:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_WHITE);
    break;

  case _AUDIO:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_GREEN);
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
