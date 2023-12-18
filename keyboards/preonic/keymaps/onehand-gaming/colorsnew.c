int default_rgblight_mode = 2; // RGBLIGHT_MODE_BREATHING;

layer_state_t layer_state_set_user(layer_state_t state) {
  /* float x[][2] = SONG(zelda); */

  /* rgblight_config_t rgblight_config; */

  /* if (do_breathing) { */
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
  /* } else { */
    /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
  /* } */

  switch(biton32(state)) {
  case 0:
    /* rgblight_enable_noeeprom(); */
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
    /* rgblight_sethsv_noeeprom(HSV_BLACK); */
    /* rgblight_mode(default_rgblight_mode); */
    break;

  case _LOWER:
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_PINK);
    /* rgblight_mode(RGBLIGHT_MODE_KNIGHT); */
    break;

  case _RAISE:
    /* float x[][2] = SONG(ROCK_A_BYE_BABY); */
    /* PLAY_SONG(x);             /\*  *\/ */
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _MOUSE:
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case _APL:

    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case _WINMOVE:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_BLACK);


    rgblight_sethsv_range(HSV_BLACK, 6, 0);
    rgblight_sethsv_range(HSV_BLACK,   5, 0);
    rgblight_sethsv_range(HSV_GREEN, 4, 6);
    rgblight_sethsv_range(HSV_GREEN, 3, 0);
    rgblight_sethsv_range(HSV_GREEN,   2, 1);
    rgblight_sethsv_range(HSV_GREEN, 1, 10);
    rgblight_sethsv_range(HSV_BLACK, 8, 5);
    rgblight_sethsv_range(HSV_BLACK,   7, 11);
    rgblight_sethsv_range(HSV_GREEN,   0, 0);

    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_GREEN);

    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

    /* rgblight_sethsv_at(HSV_BLACK, 6); */
    /* rgblight_sethsv_at(HSV_BLACK,   5); */
    /* rgblight_sethsv_at(HSV_BLACK, 4); */
    /* rgblight_sethsv_at(HSV_BLACK, 3); */
    /* rgblight_sethsv_at(HSV_BLACK,   2); */
    /* rgblight_sethsv_at(HSV_BLACK, 1); */
    /* rgblight_sethsv_at(HSV_BLACK, 8); */
    /* rgblight_sethsv_at(HSV_BLACK,   7); */
    /* rgblight_sethsv_at(HSV_BLACK,   0); */


  case _SUPER:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_sethsv_range(HSV_BLACK, 6, 0);
    rgblight_sethsv_range(HSV_BLACK,   5, 0);
    rgblight_sethsv_range(HSV_MAGENTA, 4, 6);
    rgblight_sethsv_range(HSV_MAGENTA, 3, 0);
    rgblight_sethsv_range(HSV_MAGENTA,   2, 1);
    rgblight_sethsv_range(HSV_AZURE, 1, 10);
    rgblight_sethsv_range(HSV_BLACK, 8, 5);
    rgblight_sethsv_range(HSV_BLACK,   7, 11);
    rgblight_sethsv_range(HSV_AZURE,   0, 0);


    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_MAGENTA);


    /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
    /* rgblight_sethsv_at(HSV_BLACK, 0); // led 0 */
    /* rgblight_sethsv_at(HSV_BLACK,   1); // led 1 */
    /* rgblight_sethsv_at(HSV_TURQUOISE, 2); // led 2 */
    /* rgblight_sethsv_at(HSV_BLACK, 3); // led 0 */
    /* rgblight_sethsv_at(HSV_BLACK,   4); // led 1 */
    /* rgblight_sethsv_at(HSV_BLACK, 5); // led 2 */
    /* rgblight_sethsv_at(HSV_TURQUOISE, 6); // led 0 */
    /* rgblight_sethsv_at(HSV_BLACK,   7); // led 1 */
    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

  case _SYSTEM:
    // system stuff
    /* PLAY_SONG(x);             /\*  *\/ */
    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    /* rgblight_enable_noeeprom(); */

    /* rgblight_mode(RGBLIGHT_MODE_SNAKE); */
    rgblight_enable_noeeprom();

    /* rgblight_mode(default_rgblight_mode); */
    rgblight_mode(24);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    break;

  case _WINDOWS:
    // windows
    rgblight_enable_noeeprom();
    /* rgblight_mode(default_rgblight_mode); */
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
    rgblight_mode(14);
    break;


  case _MACROS:
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_PINK);
    break;

  case _SHIFTLOCK:
    // shiftlok
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_sethsv_range(HSV_BLACK, 6, 0);
    rgblight_sethsv_range(HSV_BLACK,   5, 0);
    rgblight_sethsv_range(HSV_RED, 4, 6);
    rgblight_sethsv_range(HSV_RED, 3, 0);
    rgblight_sethsv_range(HSV_RED,   2, 1);
    rgblight_sethsv_range(HSV_RED, 1, 10);
    rgblight_sethsv_range(HSV_BLACK, 8, 5);
    rgblight_sethsv_range(HSV_BLACK,   7, 11);
    rgblight_sethsv_range(HSV_RED,   0, 0);

    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);

    /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
    break;

  /* case 16: */
  /*   rgblight_enable_noeeprom(); */
    /* rgblight_mode(default_rgblight_mode); */
  /*   /\* rgblight_mode(RGBLIGHT_MODE_BREATHING); *\/ */
  /*   rgblight_sethsv_noeeprom(HSV_PURPLE); */
  /*   break; */

  case _EDITING:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_mode(default_rgblight_mode);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;

  case _WINMOVE:
    rgblight_enable_noeeprom();
    rgblight_mode(default_rgblight_mode);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case 16:
    rgblight_mode(default_rgblight_mode);
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

  case 19:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_CORAL);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    /* rgblight_sethsv_noeeprom(HSV_GREEN); */
    break;

  case 20:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_AZURE);
    break;

  case 21:
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_WHITE);
    break;

  case 22:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case 23:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_WHITE);
    break;

  case _APL:
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_WHITE);
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
