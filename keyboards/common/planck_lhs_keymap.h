#define planck_base   mod_r1, top_left,    my_q,    my_w,    my_e,    my_r,   my_t,    my_y,           my_u,    my_i,    my_o,     my_p, \
    mod_r2, esc_ctrl , my_a,   my_s,   my_d,   my_f,   my_g,  my_h,         my_j,   my_k,   my_l,   my_semicolon, \
    mod_r3, my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,      my_n,   my_m,   my_comma,   my_period,   my_forward_slash, \
    mod_r4, hyper,  all_mods,  apl_level3_and_adhoc_hotkey,    alt, RAISE,  super,   my_space,           LOWER,          emacs_and_backspace,   key_4_11,  key_4_12



#define planck_raise  _______, LSFT(KC_TAB),    my_raise_q,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       my_raise_t, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, \
    raise_up, _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  TD(DANCE_MACROS),        my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,       raise_semi, \
    _______, SHIFTLOCK_LAYER_ACTIVATE, my_raise_z, my_raise_x, my_raise_c,  my_raise_v,      my_raise_b,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash, \
    OSL(_HYPER), MO(_SYSTEM), _______, KC_ENTER,        _______,        TO(_BASE), _______,      my_space,   raise_key_4_9,       raise_up,  _______,         TO(_BASE)


#define planck_shiftlock _______, SHIFTLOCK_LAYER_DEACTIVATE,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),     LSFT(KC_Y),     my_cap_u,     my_cap_i,     my_cap_o,     my_cap_p, \
    _______, ESC_THEN_BASE_LAYER,          LSFT(KC_A),     LSFT(KC_S),     my_cap_d,     my_cap_f,     LSFT(KC_G),     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     my_cap_semi, \
    _______, my_left_shift,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),   my_cap_n,     my_cap_m,     my_cap_comma,        my_cap_period,        my_forward_slash, \
    _______, _______, _______, _______, _______, RAISE, _______,        _______,    LOWER,  _______, _______, _______

#define planck_lower                                       _______ , KC_GRAVE,   KC_F1,          KC_F2,          KC_F3,          KC_F4,  TD(DANCE_SCREENSHOT),    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p, \
    lower_backspace, _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          my_lower_g,      my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi, \
    _______, lower_left_shift,   KC_F9,         KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,  my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash, \
    _______, MO(_SYSTEM), _______, _______ , alt,   MO(_EDITING), _______,             _______, lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12

#define planck_rofi _______, ESC_THEN_BASE_LAYER, _______, _______, _______, _______,    _______,  _______, ROFI_LOCATE, ROFI_WINDOWS, ROFI_CLIPBOARD, COPY_LATEST_FILE_TO_CLIPBOARD, \
    _______, ESC_THEN_BASE_LAYER, _______, _______, _______, FILE_SEARCH,   _______, _______, _______, ROFI_EMOJI, PLASMA_SEARCH, _______, \
    _______, TO(_BASE), _______, _______, _______, _______, _______, NOTIFICATIONS, CINNAMON_MENU_OPEN, _______, _______, _______, \
    TO(_BASE), _______, _______,    _______, _______, _______, TO(_BASE), ROFI_DRUN,    _______, _______, _______,_______


#define planck_emacs                                    _______, EMACS_TOGGLE_REPL, EMACS_DESC_KEY, _______, _______, EMACS_HELM_MARK_RINGS, EMACS_TRANSPOSE, EMACS_HELM_KILL_RINGS, EMACS_DEFUN_END, EMACS_DEFUN_BEGIN, _______, _______, \
    _______, _______, _______, REFRAME_SUBSCRIBE, REFRAME_DISPATCH, EMACS_FINDER_COMMENTARY, _______,  editing_h, editing_j, editing_k, editing_l,  _______, \
    _______, emacs_left_shift, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______


#define planck_sa                                _______, ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______, _______, _______, _______, _______, RCTL(KC_0), \
    _______, ESC_THEN_BASE_LAYER, _______, KC_LEFT, _______, KC_RIGHT,    KC_DELETE, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_F11, WEB_SAVE_FILE_UNDER_CURSOR, RCTL(KC_0), _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,    MO(_MOUSE), _______, _______,    _______, _______, _______, _______


#define planck_mouse                                _______, TO(_BASE),    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______,  KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, \
    _______, _______,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, \
_______, _______, _______, _______, _______, WEB_SAVE_FILE_UNDER_CURSOR, _______,  LALT(LGUI(KC_N)), KC_MS_BTN3,     BROWSER_TAB_PREV,   BROWSER_TAB_NEXT,   LALT(KC_F4), \
    _______, _______, _______, _______, _______, _______, _______,  _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT


#define planck_super                              _______, _______,   _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______, \
    _______, LSFT(KC_J), _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
    ROFI_LOCATE, KC_LSFT, _______, _______, _______,    _______, _______, _______,    _______, _______, _______, _______, \
    _______, _______, adhoc_set_hotkey, _______, _______,    _______,  TD(DANCE_ALT_OR_RCTRL), ROFI_DRUN, ROFI_LOCATE, KC_GRAVE, LSFT(KC_TAB), KC_TAB


#define planck_editing         LALT(KC_UNDS), EMACS_ACE_WINDOW_SELECT, EMACS_DESC_KEY, LCTL(KC_7),     LCTL(KC_E), _______, LCTL(KC_S), EMACS_YANK_IN_SEXP  , EMACS_NEXT_SEXP ,EMACS_PREV_SEXP ,  EMACS_HELM_OCCUR, PAREDIT_BACKWARD_UP, \
    EMACS_SCROLL_UP, _______, _______, EMACS_LOCCUR, EMACS_KILL_IN_SEXP, LALT(KC_ENTER), LCTL(KC_G),  editing_h, editing_j, editing_k, editing_l, EMACS_PRIVATE_READER, \
    _______, editing_left_shift, EMACS_RECENTER_ON_DEFUN, _______, EMACS_WINDOW_CLOSE,    TD(DANCE_SAVE_LOAD_NS_SWITCH), _______,                                       next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  editing_comma, editing_period, TERM_CD_UP_DIR, \
    _______, _______, _______, _______, MO(_EMACS),  _______,                                                  _______, all_mods, MO(_EMACS), TO(_BASE), _______, emacs_indent_buffer


#define planck_winmove                                  WINDOW_ALWAYS_ON_TOP, _______,   _______, _______, _______, _______, WINDOW_ALWAYS_ON_TOP,  winmove_UL,_______, _______, winmove_UR, TOGGLE_MENU_BAR, \
    _______, _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______, winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______, \
    _______, _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______, winmove_DL, winmove_U_monitor, _______, winmove_DR,_______, \
    _______, _______, _______, _______, _______, TO(0),          _______,         winmove_L_monitor,   winmove_D_monitor,   winmove_R_monitor,    _______, _______

#define planck_winmove_monitor _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, winmove_L_monitor,   winmove_D_monitor, winmove_U_monitor, winmove_R_monitor, _______, \
    _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______


#define planck_all_mods                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______,    _______, _______,     MO(_MOUSE), _______, _______, _______, _______


#define planck_system                                \
  CYCLE_ACTIVE_APL_LEVEL3_FN, QK_BOOTLOADER, _______, RGB_VAI, _______, _______,     _______,  QK_KEY_OVERRIDE_ON, QK_KEY_OVERRIDE_OFF, QK_DEBUG_TOGGLE, QK_CLEAR_EEPROM, KC_MEDIA_PLAY_PAUSE, \
    _______, CLEAR_MODIFIERS, _______, RGB_VAD, _______, _______, _______,  _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, QK_AUTOCORRECT_ON, DB_TOGG, \
    _______, QK_CLEAR_EEPROM, _______ , _______, _______, _______, _______,  _______,  KC_AUDIO_MUTE, CYCLE_DROP_ANIMATIONS, RGB_SAI, SHIFTLOCK_LAYER_ACTIVATE, \
    SYSTEM_LAYER_DEACTIVATE, SYSTEM_LAYER_DEACTIVATE,  _______, _______, _______,     _______, CYCLE_ACTIVE_APL_LEVEL3_FN, KC_MEDIA_PLAY_PAUSE, RGB_MOD, RGB_HUI, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP


#define planck_windows LGUI(KC_MINUS), ALT_TAB, WINDOWS_Q,   LGUI(KC_W),   WINDOWS_E,     TD(DANCE_40),   LGUI(KC_T),   LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), \
    _______, LALT(LGUI(KC_ESCAPE)), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______,   LGUI(KC_H),     TD(DANCE_HOTKEY_OR_COMPOSE),   windows_k,   windows_l,   LGUI(KC_SCLN), \
    _______, TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),    _______,  LGUI(KC_N),   LGUI(KC_M),  _______, LSFT(LGUI(KC_K)), LALT(KC_F4), \
    ALT_TAB , _______, _______, _______,         _______,        _______,     ALT_TAB ,  ROFI_DRUN,      GUI(KC_MINUS),  ALT_TAB, LSFT(ALT_TAB), ALT_TAB


#define planck_macros                                 CLJ_TAP, TO_BASE,   _______, _______, _______, emacs_r, COPY_TEXT_OPEN_NEW_TAB_SEARCH, EMACS_COPY_FILE_PATH, EMACS_BACKWARD_UP, EMACS_INSERT_GI_GET_FEED, CD_C9, COPY_LATEST_FILE_TO_CLIPBOARD, \
    EMACS_GOTO_PARSE_ITEM, TO_BASE, emacs_a, SSH_CRONJOBS_PROD, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED,   _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     EMACS_PF_UP, \
    EMACS_SYNC_FEED, _______, _______, CLJ_REFIND, EMACS_YAS_C,     _______, _______,  _______, emacs_m,     _______, _______, SHRUG, \
    EMACS_GOTO_ROLLUP ,  _______, _______, _______, _______, _______, _______,          EMACS_GOTO_REMOTEID, _______, _______, _______, _______



#define planck_adhoc_set_key                                            \
  SET_HOTKEY_1, _______, LCTL(LALT(LGUI(KC_Q))), LCTL(LALT(LGUI(KC_W))), _______,  LCTL(LALT(LGUI(KC_R))), _______,     LCTL(LALT(LGUI(KC_Y))), _______, _______, _______, _______, \
    SET_HOTKEY_5, _______, _______, _______, _______, _______,    LCTL(LALT(LGUI(KC_G))),  _______, LCTL(LALT(LGUI(KC_J))), LCTL(LALT(LGUI(KC_K))), LCTL(LALT(LGUI(KC_L))), _______, \
    SET_HOTKEY_2, _______, _______, SET_HOTKEY_5, SET_HOTKEY_5, _______, _______,  LCTL(LALT(LGUI(KC_N))), _______, _______, _______, LCTL(LALT(LGUI(KC_SLASH))), \
    SET_HOTKEY_3, _______, _______, _______, _______,    _______, _______,  _______,    _______, _______, SET_HOTKEY_4, _______



#define planck_hyper                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,    _______, _______, _______, _______,    MO(_EMACS), _______, _______, _______

#define planck_ctrl                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,


#define planck_layer_lock                                      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, TO(_BASE), _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
    _______, SHIFTLOCK_LAYER_ACTIVATE,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, SYSTEM_LAYER_ACTIVATE, _______, _______,    LLOCK_RAISE,  _______, LLOCK_APL, _______,    LLOCK_LOWER, LLOCK_EDITING, _______, _______

#define planck_scratch _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
