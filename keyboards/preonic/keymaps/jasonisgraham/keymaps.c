const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_preonic_grid(
  /* my_grave, OSL(_WINDOWS), _______, _______,  KC_EXLM, KC_AT, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, */
  /* my_q,    my_w,    my_e,    my_r,    my_t,   KC_HASH,KC_ASTR, my_y,           my_u,    my_i,    my_o,     my_p, */
  /* preonic_a,   my_s,   my_d,   my_f,   my_g, KC_DLR, KC_AMPR, my_h,           my_j,   my_k,   my_l,   my_semicolon, */
  /* preonic_z,           my_x,           my_c,           my_v,           my_b, KC_PERC,  KC_CIRC,      my_n,   my_m,   my_comma,   my_period,   my_forward_slash, */
  /* hyper,  LGUI(LCTL(KC_LALT)), alt, RAISE,  super,  esc_ctrl, OSL(_SHIFTLOCK), my_space,           LOWER,           right_of_lower,   key_4_11,  key_4_12 */

                                my_grave, OSL(_WINDOWS), _______, KC_GRAVE,  KC_1, KC_2, KC_9, KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
                                my_q,    my_w,    my_e,    my_r,    my_t,   KC_3,KC_8, my_y,           my_u,    my_i,    my_o,     my_p,
                                preonic_a,   my_s,   my_d,   my_f,   my_g, KC_4, KC_7, my_h,           my_j,   my_k,   my_l,   my_semicolon,
                                preonic_z,           my_x,           my_c,           my_v,           my_b, KC_5,  KC_6,      my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
                                hyper,  LGUI(LCTL(KC_LALT)), alt, RAISE,  super,  esc_ctrl, OSL(_SHIFTLOCK), my_space,           LOWER,           right_of_lower,   key_4_11,  key_4_12

  ),


  [_LOWER] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 KC_F1,          KC_F2,          KC_F3,          KC_F4,          TD(DANCE_SCREENSHOT), _______,  _______,  KC_HOME,        KC_PGUP, my_lower_i,      my_lower_o,         my_lower_p,
                                 KC_F5,          KC_F6,          KC_F7,          KC_F8,          _______,    _______, _______, KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi,
                                 KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, _______, _______, my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash,
                                 KC_F13, KC_F14, KC_F15, MO(_MOUSE),          _______, _______,          _______,         TO(4), lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12


  ),

  [_RAISE] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 OSL(_EDITING),          EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     _______, _______, _______,          _______, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                                 DYN_REC_START1, DYN_MACRO_PLAY1,KC_NO,          TD(DANCE_33),   OSL(7), _______,    _______,     my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           _______,
                                 DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_NO,          FISH_ACCEPT_SEND, _______,  _______,   KC_0,           my_raise_m,           my_raise_comma,         KC_3,           KC_QUES,
                                 _______, _______,        _______,        _______, _______, _______, _______,       _______,   KC_ENTER,       KC_0,  _______,         _______
  ),

  [_HYPER] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
    /* _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG, */
    /* _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    GAUTH_LAYER_ACTIVATE, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______, */
    /* KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT, */
    /* _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
  ),

  // 4
  [_MOUSE] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, KC_MS_UP,       _______, _______,  _______, _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                                 _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    OSL(_GAUTH), _______, _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                                 _______, _______, _______, _______, _______, SHIFTLOCK_LAYER_ACTIVATE, _______, _______, KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   _______,
                                 KC_NO, _______, _______, _______, TO(_BASE), _______, _______, _______,          _______, _______, _______, _______
  ),


  // 5
[_SYSTEM] = LAYOUT_preonic_grid(
                                SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,    _______, KC_PSTE, KC_AGIN, DEBUG, RESET_ANIMATION, RESET,
                                MO(_AUDIO),_______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                                _______ , _______, _______, _______, MO(_BRIGHTNESS), KC_ASTG, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

    /* SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET, */
    /* RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______, */
    /* KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK, */
    /* CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
  ),

  // 6
  [_WINDOWS] = LAYOUT_preonic_grid(
                                   _______, ALT_TAB, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   WINDOWS_Q,   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T), _______,    LGUI(KC_MINUS), LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),
                                   LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),     TD(DANCE_42), RGUI(KC_ESCAPE), _______,  LGUI(KC_H),     TD(DANCE_HOTKEY_OR_COMPOSE),   TD(DANCE_44),   TD(DANCE_45),   _______,
                                   LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),     _______, TO(_BASE),  _______, TD(DANCE_46),   LGUI(KC_M),  _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)),
                                   _______, _______,         LALT(KC_6),        _______,      ALT_TAB , RGUI(KC_ESCAPE), _______,  LALT(KC_8), RGUI(KC_ESCAPE),  OSL(_ADHOC_SET_HOTKEY), _______, _______
  ),

  // 7
  [_MACROS] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  EMACS_RE_FIND, _______, _______, emacs_r, _______ ,  _______, EMACS_GOTO_PARSE_ITEM, _______, EMACS_BACKWARD_UP, _______, EMACS_ANON_FN, _______,
                                  emacs_a, CD_CSV, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, _______, CLJ_TAP, _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     EMACS_COMMENT_READER,
                                  _______, _______, EMACS_YAS_C,     _______, _______, _______, EMACS_GOTO_SYNC_FEED, _______, emacs_m,     _______, _______, TERM_CD_UP_DIR,
   _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 8
  [_SHIFTLOCK] = LAYOUT_preonic_grid(
                                     _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                     RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),  _______,   _______,  RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P),
                                     RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G), ESC_THEN_BASE_LAYER,  _______,   my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),
                                     RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B), SHIFTLOCK_LAYER_DEACTIVATE,   _______,  RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,
                                     _______, _______, _______, _______, _______, _______, KC_NO,      _______,    LOWER,  _______, _______, _______
  ),

  // 9
  [_WINMOVE] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______,
                                   _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, _______, _______, TD(DANCE_58),   RGUI(RSFT(KC_J)),TD(DANCE_59),   TD(DANCE_60),   _______,
                                   _______, _______, KC_F11, _______, _______, _______, _______, RGUI(RSFT(KC_N)), TD(DANCE_47), _______, RGUI(RSFT(KC_DOT)),_______,
                                   _______, _______, _______, TO(0),          _______, _______, KC_NO,        TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),    _______, _______
  ),

  // 10
  [_ALT] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 11
  [_SUPER] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 12
  [_EDITING] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,     _______,  _______, _______, EMACS_COPY_FILE_PATH, LCTL(KC_7),     _______, EMACS_OTHER_WINDOW, _______,
                                   _______, _______, _______, RALT(KC_ENTER), _______, _______, RCTL(KC_QUOTE), RALT(RSFT(KC_H)),RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)),RCTL(KC_SCOLON),
                                   _______, _______, EMACS_WINDOW_CLOSE,    _______, _______, _______,  _______, RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP,  _______, _______, TERM_CD_UP_DIR,
                                   _______, _______, _______, OSL(18), _______, _______, _______, KC_NO,          RALT(KC_ENTER), _______, _______, _______

  ),

  [_LAYER13] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
 TO(_BASE),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_MODE_PLAIN, _______, RGB_MODE_FORWARD, RGB_MODE_REVERSE, _______, _______, _______, _______, _______, _______, _______, _______,
    RGBLIGHT_HUE_STEP, RGBLIGHT_MODE_STATIC_LIGHT, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_VIM_CMDS] = LAYOUT_preonic_grid(
                                    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                    _______, LALT(KC_F),     _______, _______, _______, _______, _______, RCTL(KC_Y),     _______, TO(0),          _______, RCTL(KC_V),
                                    _______, _______, _______, _______, OSL(15), _______,        TD(DANCE_H),  _______, TD(DANCE_J),   TD(DANCE_64),   TD(DANCE_65),   KC_LCBR,
                                    _______, TD(DANCE_66),   _______, _______, LALT(KC_B), _______,     _______, TD(DANCE_67),    _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_LAYER15] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_COLORS] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T), _______,     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54),
                                  RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G), ESC_THEN_BASE_LAYER,     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),   TD(DANCE_56),
                                  RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B), SHIFTLOCK_LAYER_DEACTIVATE,     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, _______,    RGBLIGHT_MODE_STATIC_LIGHT, _______, _______, _______

  ),


  [_LAYER17] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  _______, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR,         KC_PERC,        KC_CIRC,        KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                  ),
  [_LAYER18] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  _______, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_7,    EMACS_SEL_8,           EMACS_SEL_9,           EMACS_SEL_0,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_4,           EMACS_SEL_5,           EMACS_SEL_6,           KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_0,           EMACS_SEL_1,           EMACS_SEL_2,           EMACS_SEL_3,           KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                  ),
  [_GAUTH] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, gauth_plex,
                                 _______, _______, _______,  gauth_fb,   gauth_gh, _______, _______, gauth_hb, _______, _______, gauth_lp, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                  ),

  [_AUDIO] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK,
                                 _______, _______, _______, _______, _______, _______,   _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,  _______,_______,_______,
  _______, _______, _______, _______,    _______, _______, _______, KC_MEDIA_PLAY_PAUSE,    _______, _______, _______, _______
                                ),
  [_BRIGHTNESS] = LAYOUT_preonic_grid(
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,   _______, _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                ),

  [_ADHOC_SET_HOTKEY] = LAYOUT_preonic_grid(
                                            _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,

                                            LCTL(RALT(RGUI(KC_Y))), LCTL(RALT(RGUI(KC_W))), _______, LCTL(RALT(RGUI(KC_R))), _______, TO(_BASE),    _______, LCTL(RALT(RGUI(KC_Y))),_______, _______, _______, _______,
                                            _______, _______, _______, _______, LCTL(RALT(RGUI(KC_G))), _______,    _______, _______, LCTL(RALT(RGUI(KC_J))), LCTL(RALT(RGUI(KC_K))), LCTL(RALT(RGUI(KC_L))), _______,
                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______,    _______, _______, _______, LCTL(RALT(RGUI(KC_N))),    _______, _______, _______, _______
                                           ),


};
