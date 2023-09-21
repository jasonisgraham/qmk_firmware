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
                                                         [_BASE] =   { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
                                                         [_EMACS] =   { ENCODER_CCW_CW(EMACS_WINNER_REDO, EMACS_WINNER_UNDO) },
                                                         [_EDITING] =   { ENCODER_CCW_CW(LCTL(KC_TAB), LCTL(KC_TAB)) },
                                                         [_MOUSE] =   { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         [_LOWER] =   { ENCODER_CCW_CW(BROWSER_TAB_NEXT, BROWSER_TAB_PREV)  },
                                                         [_SYSTEM] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         [_SHIFTLOCK] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         [_ROFI] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         [_RAISE] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ) },
                                                         /* [_BRIGHTNESS] =  { ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN) }, */
                                                         /* [_CTRL] =  { ENCODER_CCW_CW(C(KC_U), C(KC_D)) }, */
                                                         [_SUPER] =  { ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)) },
};
