const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
   my_grave,    my_q,    my_w,    my_e,    my_r,    my_t,   _______, my_y,           my_u,    my_i,    my_o,     my_p,
   my_lctl ,my_a,   my_s,   my_d,   my_f,   my_g,  KC_BSPACE, my_h,           my_j,   my_k,   my_l,   my_semicolon,
   my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,   _______,        my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
    _______,  _______, _______,  KC_LALT, RAISE,  super,  hyper, my_space,           LOWER,           right_of_lower,   _______,  _______
  ),

  [_LOWER] = LAYOUT_planck_grid(
                                TD(DANCE_26),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,   _______,  KC_HOME,        KC_PGUP,        my_lower_i,      my_lower_o,         TD(DANCE_27),
                                _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_SCROLLLOCK,     KC_BSPACE, KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       _______,
                                SHIFTLOCK_LAYER_ACTIVATE,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, _______, my_lower_n, my_lower_m, my_lower_comma,   TD(DANCE_30),   KC_DELETE,
                                _______, _______, _______, _______,        MO(4),          TO(4),          _______,          _______, _______,          _______,          _______, _______


  ),

  [_RAISE] = LAYOUT_planck_grid(
   TD(DANCE_32),   OSL(_EDITING),          EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     _______, _______,          _______, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
   _______, DYN_REC_START1, DYN_MACRO_PLAY1,KC_NO,          TD(DANCE_33),   OSL(7),    _______,     my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           _______,
   SHIFTLOCK_LAYER_ACTIVATE, DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_NO,          FISH_ACCEPT_SEND,  _______,   KC_0,           my_raise_m,           my_raise_comma,         KC_3,           KC_QUES,
   _______, _______, _______,        _______,        _______, _______, _______,       _______,   KC_ENTER,       KC_0,  _______,         _______
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT,
    _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
  ),

  // 4
  [_MOUSE] = LAYOUT_planck_grid(
                                TD(DANCE_34),   _______, _______, KC_MS_UP,       _______, _______, _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                                _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   _______,
                                _______, KC_NO, _______, _______, _______, TO(_BASE), _______, _______,          _______, _______, _______, _______
  ),

  // 5
  [_SYSTEM] = LAYOUT_planck_grid(
    SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET,
    RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______,
    KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
  ),

  // 6
  [_WINDOWS] = LAYOUT_planck_grid(
                                   TO(_BASE), TD(DANCE_38),   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T),     TD(DANCE_41),   LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     LGUI(KC_MINUS),
                                   RGUI(KC_ESCAPE),LGUI(KC_A), select_slack, show_desktop     ,LGUI(KC_F),     TD(DANCE_42),   LGUI(KC_H),     TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   _______, _______,
                                   TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),     _______, TD(DANCE_46),   LGUI(KC_M),     TD(DANCE_47),   _______, RSFT(LGUI(KC_K)), SHIFTLOCK_LAYER_ACTIVATE,
                                   _______, _______, TO(14),         TT(12),         TT(9),      ALT_TAB , RGUI(KC_SPACE),           TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),   RGUI(KC_ESCAPE),RCTL(RGUI(KC_Q))
  ),

  // 7
  [_MACROS] = LAYOUT_planck_grid(
   TD(DANCE_52),   _______, _______, _______, emacs_r, _______, _______, _______, _______, _______, _______, _______,
   _______, emacs_a, CD_CSV, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     _______, _______,
   _______, _______, _______, EMACS_YAS_C,     _______, _______, _______, emacs_m,     _______, _______, TERM_CD_UP_DIR, _______,
   _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 8
  [_SHIFTLOCK] = LAYOUT_planck_grid(
                                    TO(_BASE),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),   _______,  RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P),
                                    ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),  _______,   my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),
                                    SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),   _______,  RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,
                                    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 9
  [_WINMOVE] = LAYOUT_planck_grid(
                                  TO(_BASE),   _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______,
                                  _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, _______, TD(DANCE_58),   RGUI(RSFT(KC_J)),TD(DANCE_59),   TD(DANCE_60),   _______,
                                  _______, _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_N)),_______, _______, RGUI(RSFT(KC_DOT)),_______,
    _______, _______, _______, _______, TO(0),          _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  // 10
  [_ALT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 11
  [_SUPER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  // 12
  [_EDITING] = LAYOUT_planck_grid(
                                  TO(_BASE), _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,     _______, _______, EMACS_COPY_FILE_PATH, LCTL(KC_7),     _______, EMACS_OTHER_WINDOW, _______,
                                  _______, _______, _______, _______, RALT(KC_ENTER), _______,RCTL(KC_QUOTE), RALT(RSFT(KC_H)),RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)),RCTL(KC_SCOLON),
                                  _______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______,  _______, RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP,  _______, _______, TERM_CD_UP_DIR,
                                  _______, _______, _______, _______, OSL(18), _______, _______, KC_NO,          RALT(KC_ENTER), _______, _______, _______

  ),

  [_LAYER13] = LAYOUT_planck_grid(
 TO(_BASE),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_MODE_PLAIN, _______, RGB_MODE_FORWARD, RGB_MODE_REVERSE, _______, _______, _______, _______, _______, _______, _______, _______,
    RGBLIGHT_HUE_STEP, RGBLIGHT_MODE_STATIC_LIGHT, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_VIM_CMDS] = LAYOUT_planck_grid(
                                   TO(0), _______, LALT(KC_F),     _______, _______, _______, _______, RCTL(KC_Y),     _______, TO(0),          _______, RCTL(KC_V),
                                   _______,          _______, _______, _______, _______, OSL(15),        TD(DANCE_62),  _______, TD(DANCE_63),   TD(DANCE_64),   TD(DANCE_65),   KC_LCBR,
                                   _______, _______, TD(DANCE_66),   _______, _______, LALT(KC_B),     _______, TD(DANCE_67),    _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_LAYER15] = LAYOUT_planck_grid(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
  ),

  [_COLORS] = LAYOUT_planck_grid(
                                 TO(_BASE),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54),
    ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),   TD(DANCE_56),
    SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, _______,    RGBLIGHT_MODE_STATIC_LIGHT, _______, _______, _______

  ),


  [_LAYER17] = LAYOUT_planck_grid(
                                  TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR,         KC_PERC,        KC_CIRC,        KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                  ),
  [_LAYER18] = LAYOUT_planck_grid(
                                  TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_7,    EMACS_SEL_8,           EMACS_SEL_9,           EMACS_SEL_0,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_4,           EMACS_SEL_5,           EMACS_SEL_6,           KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_0,           EMACS_SEL_1,           EMACS_SEL_2,           EMACS_SEL_3,           KC_TRANSPARENT,
                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                  ),
};
