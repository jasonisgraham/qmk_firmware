const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
                                                         /* [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) }, */
                                                         [_BASE] =   { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_EMACS] =   { ENCODER_CCW_CW(EMACS_WINNER_REDO, EMACS_WINNER_UNDO), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_EDITING] =   { ENCODER_CCW_CW(LCTL(KC_TAB), LCTL(KC_TAB)), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_MOUSE] =   { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_LOWER] =   { ENCODER_CCW_CW(BROWSER_TAB_NEXT, BROWSER_TAB_PREV), ENCODER_CCW_CW(KC_A, KC_B)  },
                                                         [_SYSTEM] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_SHIFTLOCK] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_ROFI] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         [_RAISE] =  { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN ), ENCODER_CCW_CW(KC_A, KC_B) },
                                                         /* [_BRIGHTNESS] =  { ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN), ENCODER_CCW_CW(KC_A, KC_B) }, */
                                                         /* [_CTRL] =  { ENCODER_CCW_CW(C(KC_U), C(KC_D)), ENCODER_CCW_CW(KC_A, KC_B) }, */
                                                         [_SUPER] =  { ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)), ENCODER_CCW_CW(KC_A, KC_B) },
};
