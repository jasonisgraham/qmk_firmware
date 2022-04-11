const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_preonic_grid(
    my_grave,    my_q,    my_w,    my_e,    my_r,    my_t,    my_y,           my_u,    my_i,    my_o,    my_p,    topright,
    my_lctl ,my_a,   my_s,   my_d,   my_f,   my_g,   my_h,           my_j,   my_k,   my_l,   my_semicolon,   my_singlequote,
    my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,           my_n,   my_m,   my_comma,   my_period,   my_forward_slash,   my_right_shift,
    MT(MOD_LCTL, KC_LBRACKET),  _______, KC_LGUI, KC_LALT, RAISE,    my_split_left, /* LM(6,MOD_LGUI),  */     my_space,           my_lower,           right_of_lower,   LAYER_RAISE_HOLD,          LAYER_LOWER_HOLD, SHIFTLOCK_LAYER_ACTIVATE,
    _______,SYSTEM_LAYER_ACTIVATE,_______,_______, hyper,  my_lctl,     my_left_shift,         KC_LALT,         KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    /* _______,_______,_______,_______, my_lctl,  MT(MOD_LCTL, KC_LBRACKET),      KC_LSPO,         TD(T_LCRB_H_ALT),         KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT */
    /* MT(MOD_LCTL, KC_LBRACKET),  SYSTEM_LAYER_ACTIVATE, KC_LGUI, _______,  */


  ),

  [_LOWER] = LAYOUT_preonic_grid(
    TD(DANCE_26),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     KC_HOME,        KC_PGUP,        my_lower_i,      my_lower_o,         _______, TD(DANCE_27),
    _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_SCROLLLOCK,  KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       KC_LCBR,        KC_RCBR,
    SHIFTLOCK_LAYER_ACTIVATE,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, my_lower_n, my_lower_m, my_lower_comma,   TD(DANCE_30),   KC_DELETE,      SHIFTLOCK_LAYER_ACTIVATE,
    _______, KC_NO, KC_LGUI,        KC_LALT,        MO(4),          TO(4),          KC_NO,          _______, KC_NO,          KC_NO,          _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______ ,   _______, _______, _______, _______


  ),

  [_RAISE] = LAYOUT_preonic_grid(
    TD(DANCE_32),   OSL(_EDITING),          EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     KC_NO,          _______, my_raise_u,           my_raise_i,           my_raise_o,           KC_0,           KC_UNDS,
    _______, DYN_REC_START1, DYN_MACRO_PLAY1,KC_NO,          TD(DANCE_33),   OSL(7),         my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           KC_LBRACKET,    KC_RBRACKET,
    _______, DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_NO,          FISH_ACCEPT_SEND,     KC_0,           my_raise_m,           my_raise_comma,         KC_3,           KC_QUES,      _______,
    _______, KC_NO, KC_LGUI,        KC_LALT,        _______, _______, KC_NO,          KC_ENTER,       KC_0,           KC_DOT,         KC_NO,          _______,
    _______, _______, _______, _______,    _______, KC_RBRACKET, KC_RPRN, KC_RCBR,    _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_preonic_grid(
    _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT,
    _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 4
  [_MOUSE] = LAYOUT_preonic_grid(
    TD(DANCE_34),   _______, _______, KC_MS_UP,       _______, _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   _______, _______,
    _______, KC_NO, _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 5
  [_SYSTEM] = LAYOUT_preonic_grid(
    SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET,
    RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______,
    BL_BRTG, BL_STEP, RGB_TOG, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), _______, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    RGB_MODE_FORWARD, RGB_MODE_REVERSE,  _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 6
  [_WINDOWS] = LAYOUT_preonic_grid(
                                   TO(_BASE), TD(DANCE_38),   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T),     TD(DANCE_41),   LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     LGUI(KC_MINUS),
                                   RGUI(KC_ESCAPE),LGUI(KC_A), select_slack, show_desktop     ,LGUI(KC_F),     TD(DANCE_42),   LGUI(KC_H),     TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   _______, _______,
                                   TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),     _______, TD(DANCE_46),   LGUI(KC_M),     TD(DANCE_47),   _______, RSFT(LGUI(KC_K)), SHIFTLOCK_LAYER_ACTIVATE,
                                   _______, _______, TO(14),         TT(12),         TT(9),       my_split_left_windows , KC_NO,          TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),   RGUI(KC_ESCAPE),RCTL(RGUI(KC_Q)),
                                   _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 7
  [_MACROS] = LAYOUT_preonic_grid(
    TD(DANCE_52),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, EMACS_YAS_DOC,     EMACS_YAS_TF,     EMACS_INSERT_GET_FEED, _______, _______, _______, EMACS_YAS_TL,     _______, _______,
    _______, _______, _______, EMACS_YAS_C,     _______, _______, _______, EMACS_YAS_MAP_ANON,     _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 8
  [_SHIFTLOCK] = LAYOUT_preonic_grid(
                                     /* RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, */
                                     /* RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, RGBLIGHT_MODE_RAINBOW_MOOD,    RGBLIGHT_MODE_STATIC_LIGHT, RGBLIGHT_MODE_STATIC_GRADIENT, _______, _______, */
                                     /* KC_Z, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
                                     /* _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, TO(0), */
                                     /* _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______ */

                                     TO(_BASE),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54),
    ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),   TD(DANCE_56),
    SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    _______, _______, _______, _______, _______, _______, KC_NO,          my_lower, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, my_lower,    _______, _______, _______, _______
  ),

  // 9
  [_WINMOVE] = LAYOUT_preonic_grid(
    TO(_BASE),   _______, _______, _______, _______, _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______, _______,
    _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, TD(DANCE_58),   RGUI(RSFT(KC_J)),TD(DANCE_59),   TD(DANCE_60),   _______, _______,
    _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_N)),_______, _______, RGUI(RSFT(KC_DOT)),_______, _______,
    _______, _______, _______, _______, TO(0),          _______, KC_NO,          _______, _______, _______, _______, _______,
    _______, _______, _______, _______, TO(0),          _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 10
  [_ALT] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 11
  [_SUPER] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 12
  [_EDITING] = LAYOUT_preonic_grid(
TO(_BASE), _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,     _______, EMACS_COPY_FILE_PATH, LCTL(KC_7),     _______, EMACS_OTHER_WINDOW, _______, TMUX_SPLIT_WINDOW,
_______, _______, _______, _______, RALT(KC_ENTER), _______, RALT(RSFT(KC_H)),RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)),RCTL(KC_SCOLON),RCTL(KC_QUOTE),
_______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______, RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP,    _______, _______, EMACS_WINDOW_CLOSE,    _______,
_______, _______, _______, _______, OSL(18), _______, KC_NO,          RALT(KC_ENTER), _______, _______, _______, _______,
_______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_LAYER13] = LAYOUT_preonic_grid(
 TO(_BASE),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_MODE_PLAIN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGBLIGHT_HUE_STEP, RGBLIGHT_MODE_STATIC_LIGHT, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_VIM_CMDS] = LAYOUT_preonic_grid(
    TO(0), _______, LALT(KC_F),     _______, _______, _______, RCTL(KC_Y),     _______, TO(0),          _______, RCTL(KC_V),     _______,
    _______,          _______, _______, _______, _______, OSL(15),        TD(DANCE_62),   TD(DANCE_63),   TD(DANCE_64),   TD(DANCE_65),   KC_LCBR,        KC_RCBR,
    _______, _______, TD(DANCE_66),   _______, _______, LALT(KC_B),     TD(DANCE_67),   _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_LAYER15] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, TD(DANCE_68),   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_COLORS] = LAYOUT_preonic_grid(
    /* RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, */
    /* RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, RGBLIGHT_MODE_RAINBOW_MOOD,    RGBLIGHT_MODE_STATIC_LIGHT, RGBLIGHT_MODE_STATIC_GRADIENT, _______, _______, */
    /* KC_Z, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
    /* _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, TO(0), */
    /* _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______ */

    TD(DANCE_53),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54),
    ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),   TD(DANCE_56),
    SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, RGBLIGHT_MODE_RAINBOW_MOOD,    RGBLIGHT_MODE_STATIC_LIGHT, RGBLIGHT_MODE_STATIC_GRADIENT, _______, _______,
    RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______
    /* _______, _______, _______, _______, _______, _______, KC_NO,          my_lower, _______, _______, _______, _______ */

  ),


  [_LAYER17] = LAYOUT_preonic_grid(
                                  TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR,         KC_PERC,        KC_CIRC,        KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                  ),
  [_LAYER18] = LAYOUT_preonic_grid(
                                  TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_7,    EMACS_SEL_8,           EMACS_SEL_9,           EMACS_SEL_0,           KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_4,           EMACS_SEL_5,           EMACS_SEL_6,           KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_0,           EMACS_SEL_1,           EMACS_SEL_2,           EMACS_SEL_3,           KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                  ),
};
