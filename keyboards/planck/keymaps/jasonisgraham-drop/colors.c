layer_state_t layer_state_set_user(layer_state_t state) {
  float x[][2] = SONG(zelda);
  /* rgblight_config_t rgblight_config; */

  if (do_breathing) {
    rgblight_mode(RGBLIGHT_MODE_BREATHING);
  } else {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  }

  switch(biton32(state)) {
  case 0:
    // Green
    rgblight_enable_noeeprom();
    /* rgblight_sethsv_at(HSV_WHITE, 0); // led 0 */
    /* rgblight_sethsv_at(HSV_RED,   1); // led 1 */
    /* rgblight_sethsv_at(HSV_GREEN, 2); // led 2 */
    /* rgblight_sethsv_at(HSV_PURPLE, 3); // led 2 */
    /* rgblight_sethsv_at(HSV_YELLOW, 4); // led 2 */
    /* rgblight_sethsv_at(HSV_BLUE, 5); // led 2 */
    /* rgblight_sethsv_at(HSV_WHITE, 6); // led 2 */
    /* rgblight_sethsv_at(HSV_PURPLE, 7); // led 2 */
    rgblight_sethsv_noeeprom(HSV_BLACK);
    /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
    break;

  case 1:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_RED);
    /* rgblight_mode(RGBLIGHT_MODE_KNIGHT); */
    break;

  case 2:
    /* float x[][2] = SONG(ROCK_A_BYE_BABY); */
    /* PLAY_SONG(x);             /\*  *\/ */
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;
  case 3:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case 4:
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_GREEN);
    break;

  case 5:
    // system stuff
    PLAY_SONG(x);             /*  */
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    break;

  case 6:
    // windows
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
    break;


  case 7:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_PINK);
    break;

  case 8:
    // shiftlok
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);
    break;

  case 16:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    break;

  case 12:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;
  case 9:
    rgblight_enable_noeeprom();
    /* rgblight_mode(RGBLIGHT_MODE_BREATHING); */
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
