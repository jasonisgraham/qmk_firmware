const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
TO(0), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
my_q,    my_w,    my_e,    my_r,    my_t,   _______,_______, my_y, my_u,  my_i, my_o, my_p,
my_a,   my_s,   my_d,   my_f,   my_g,  _______,_______, my_h,           my_j,   my_k,   my_l,   my_semicolon,
my_z,           my_x,           my_c,           my_v,           my_b,    _______,_______,       my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
MT(MOD_LCTL, KC_LBRACKET),TT(5), KC_LGUI, KC_LALT, RAISE,    LM(6,MOD_LGUI),      my_space,           my_lower,          right_of_lower,      LAYER_LOWER_HOLD, LAYER_RAISE_HOLD, CYCLE_FAVE_ANIMATIONS
),

// _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

[_LOWER] = LAYOUT_preonic_grid(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  TD(DANCE_27),
TD(DANCE_26),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     KC_HOME,        KC_PGUP,        KC_PGDOWN,      my_lower_o,         _______, TD(DANCE_27),
_______, KC_F5,          KC_F6,          KC_F7,          my_lower_f,          KC_SCROLLLOCK,  KC_LEFT,        my_lower_j,        my_lower_k,          KC_RIGHT,       _______, _______,
TD(DANCE_28),   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, _______, my_lower_m,TD(DANCE_29),   TD(DANCE_30),   KC_DELETE,       SHIFTLOCK_LAYER_ACTIVATE,
_______, _______, KC_LGUI,        KC_LALT,        MO(4),         TO(8) ,        TO(4),          _______, KC_NO,          KC_NO,          _______, _______

),


[_RAISE] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               KC_NO,          EMACS_OTHER_WINDOW, KC_END,         EMACS_BUFFER_REVERT,     KC_NO,  _______,_______,        _______, KC_7,           KC_8,           KC_9,           KC_0,
                               DYN_REC_START1, DYN_MACRO_PLAY1,KC_NO,          RALT(KC_ENTER), OSL(7), _______, _______,         KC_BSPACE,      KC_4,           KC_5,           KC_6,           KC_LBRACKET,
                               DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_NO,          FISH_ACCEPT_SEND,  _______,_______,   KC_0,           KC_1,           KC_2,           KC_3,           KC_BSLASH,

 _______, _______, KC_LGUI,        KC_LALT,        _______, _______, KC_NO,          KC_ENTER,       KC_0,           KC_DOT,         KC_NO,          _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG,
  _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
  KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT,
  _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
),
  [_LAYER4] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_33),   _______, _______, KC_MS_UP,       _______, _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN3,     TD(DANCE_34),   TD(DANCE_35),   _______, _______,
    _______, _______, _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, _______, _______, _______
  ),

[_SYSTEM] = LAYOUT_preonic_grid(
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_36),   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET,
    BL_TOGG, BL_STEP, BL_BRTG, BL_ON, BL_OFF, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______,
    _______, _______, _______, _______, BL_INC, BL_DEC,      _______, RGB_MOD,        _______,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    _______, _______, _______, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
  ),

  [_WINDOWS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, TD(DANCE_37),   TD(DANCE_38),   LGUI(KC_E),     TD(DANCE_39),   LGUI(KC_T),     TD(DANCE_40),   LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     LGUI(KC_MINUS),
    RGUI(KC_ESCAPE),LGUI(KC_A),     LGUI(KC_S),     LALT(LGUI(LCTL(KC_D))),LGUI(KC_F),     TD(DANCE_41),   LGUI(KC_H),     TD(DANCE_42),   TD(DANCE_43),   TD(DANCE_44),   LGUI(LSFT(KC_TAB)),LGUI(KC_TAB),
    _______, LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),     _______, TD(DANCE_45),   LGUI(KC_M),     TD(DANCE_46),   _______, _______,       TO(8),
    _______, _______, _______, TT(12),         TT(9),          LGUI(KC_SPACE), LGUI(KC_SPACE),          TD(DANCE_47),   TD(DANCE_48),   TD(DANCE_49),   RGUI(KC_ESCAPE), TD(DANCE_50)
  ),

  [_MACROS] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_51),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, EMACS_YAS_DOC,     EMACS_YAS_TF,     _______, _______, _______, _______, EMACS_YAS_TL,     _______, _______,
    _______, _______, _______, EMACS_YAS_C,     _______, _______, _______, EMACS_YAS_MAP_ANON,     _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_SHIFTLOCK] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_52),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_53),
    ESC_THEN_BASE_LAYER, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(DANCE_54),   TD(DANCE_55),
    TO(0),          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        TO(0),
    _______, _______, _______, _______, _______,  TO(0),   _______,       _______, _______, _______, _______, _______
  ),

  [_WINMOVE] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_56),   _______, _______, _______, _______, _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______, _______,
    _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, TD(DANCE_57),   RGUI(RSFT(KC_J)),TD(DANCE_58),   TD(DANCE_59),   _______, _______,
    _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_N)),_______, _______, RGUI(RSFT(KC_DOT)),_______, _______,
    _______, _______, _______, _______, TO(0),          _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_LAYER10] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_LAYER11] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
  ),

  [_EDITING] = LAYOUT_preonic_grid(
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, EMACS_OTHER_WINDOW,     _______, EMACS_OTHER_WINDOW,     _______, _______, LCTL(KC_7),     _______, _______, _______, _______,
    _______, _______, _______, _______, RALT(KC_ENTER), _______, RALT(RSFT(KC_H)),RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)),RCTL(KC_SCOLON),RCTL(KC_QUOTE),
                                  _______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______, _______, RALT(RSFT(KC_N)),    _______, _______, EMACS_WINDOW_CLOSE,    _______,
    _______, _______, _______, _______, _______, _______, KC_NO,          RALT(KC_ENTER), _______, _______, _______, _______
  ),




};
