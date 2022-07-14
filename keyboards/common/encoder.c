/* #ifdef ENCODER_ENABLE */


/* bool encoder_update_user(uint8_t index, bool clockwise) { */
/*   if (clockwise) { */
/*     tap_code16(KC_VOLD); */
/*   } else { */
/*     tap_code16(KC_VOLU); */
/*   } */
/*   return true; */
/* } */

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
                                                         /* [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) }, */
                                                         [_BASE] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDOWN) },
                                                         /* [_EDITING] =   { ENCODER_CCW_CW(EMACS_OTHER_WINDOW_NEXT, EMACS_OTHER_WINDOW_PREV) }, */
                                                         [_EDITING] =   { ENCODER_CCW_CW(EMACS_NUMBER_INC, EMACS_NUMBER_DEC) },
                                                         [_SYSTEM] =   { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         [_LOWER] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
                                                         [_MOUSE] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
                                                         [_RAISE] =  { ENCODER_CCW_CW(BROWSER_TAB_NEXT, BROWSER_TAB_PREV) },
                                                         [_BRIGHTNESS] =  { ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN) },
                                                         /* [_ALT] =  { ENCODER_CCW_CW(TD(DANCE_29), TD(DANCE_30)) }, */
                                                         [_SUPER] =  { ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)) },
};
