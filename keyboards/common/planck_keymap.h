enum unicode_names {
  BANG,
  IRONY,
  SNEK
};

const uint32_t PROGMEM unicode_map[] = {
  [BANG]  = 0x203D,  // ‽
  [IRONY] = 0x2E2E,  // ⸮
  [SNEK]  = 0x1F40D, // 🐍
};

#define planck_base  top_left,    my_q,    my_w,    my_e,    my_r,   my_t, mod_r1,    my_y,           my_u,    my_i,    my_o,     my_p, \
    esc_ctrl , my_a,   my_s,   my_d,   my_f,   my_g, mod_r2,  my_h,         my_j,   my_k,   my_l,   my_semicolon, \
        my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b, mod_r3,     my_n,   my_m,   my_comma,   my_period,   my_forward_slash, \
        level3,   alt_keyboard, hyper,        alt, RAISE,  super, mod_r4,   my_space,           LOWER,          my_right_of_lower,   key_left,  key_right


#define planck_numlock TO_BASE,    _______,          _______,  _______,         _______,       _______, _______, _______, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, \
        _______, _______, _______,   _______, _______,  _______, _______,       _______,         my_raise_j,           my_raise_k,           my_raise_l,       _______, \
    _______, _______, _______, _______,  _______,      _______, _______,     _______,           my_raise_m,           my_raise_comma,         KC_3,           _______, \
        _______, _______, _______, _______,        _______,        _______, _______, _______,      _______, _______ ,       _______,           _______

#define planck_raise KC_GRAVE,    my_raise_q,          my_raise_w,  my_raise_e,         my_raise_r,       my_raise_t, TO_BASE, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, \
    _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  my_raise_g, raise_up,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,       raise_semi, \
    raise_left_shift, my_raise_z, my_raise_x, my_raise_c,  my_raise_v,      my_raise_b, raise_down,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash, \
    MO(_SYSTEM), _______, KC_ENTER,        _______,        TO(_BASE), _______, raise_left,      my_space,   raise_key_4_9,       KC_INSERT,  KC_DOWN,         KC_UP


#define planck_shiftlock KC_TAB,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T), TO_BASE,    LSFT(KC_Y),     my_cap_u,     my_cap_i,     my_cap_o,     my_cap_p, \
    esc_ctrl,          LSFT(KC_A),     LSFT(KC_S),     my_cap_d,     my_cap_f,     LSFT(KC_G), _______,    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     my_cap_semi, \
        SHIFTLOCK_LAYER_DEACTIVATE,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B), _______,   my_cap_n,     my_cap_m,     my_cap_comma,        my_cap_period,        my_forward_slash, \
    _______, _______, _______, _______, RAISE, _______, _______,       _______,    LOWER,  _______, _______, _______

#define planck_lower                               backtab,   my_lower_q,          my_lower_w,          my_lower_e,          my_lower_r,  TD(DANCE_SCREENSHOT),  TO_BASE,    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p, \
    _______, my_lower_a,          my_lower_s,          my_lower_d,          my_lower_f,          my_lower_g, lower_backspace,      my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi, \
    lower_left_shift,   my_lower_z,         my_lower_x,         my_lower_c,         my_lower_v,         my_lower_b, lower_down,  my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash, \
    LAYER_MOUSE_HOLD, _______, _______ , alt,   MO(_EDITING), _______,       _______,             _______, lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12

#define planck_rofi ESC_THEN_BASE_LAYER, _______, LAUNCHER_WIKI, _______,  _______, LAUNCHER_TRANSLATE,    _______,  ROFI_LOCATE_GLOBAL, ROFI_LOCATE, LAUNCHER_WINDOWS, LAUNCHER_CLIPBOARD, COPY_LATEST_FILE_TO_CLIPBOARD, \
        CLEAR_NOTIFICATIONS, _______, LAUNCHER_SYSTEM, LAUNCHER_DEFINE, LAUNCHER_FDFIND,   LAUNCHER_GOOGLE, _______, CIDER_HISTORY_WRITE, ROFI_CIDER_HISTORY, ROFI_EMOJI, ROFI_PROCESSES, ULAUNCHER, \
        AUTOSHIFT_TOGGLE, _______, _______, ROFI_CALCULATOR, _______, _______, _______, OPEN_NOTIFICATIONS, CINNAMON_MENU_OPEN, PLASMA_SEARCH, _______, _______, \
    _______, _______, _______,    _______, _______, ROFI_DRUN, TO(_BASE), ROFI_DRUN,    _______, DM_REC1, DM_RSTP, DM_PLY1

#define planck_emacs                                EMACS_FOCUS_REPL, EMACS_DESC_KEY, EMACS_WRAP_HYDRA, LCTL(KC_E), EMACS_HELM_MARK_RINGS, EMACS_TRANSPOSE,    _______, EMACS_HELM_KILL_RINGS, EMACS_DEFUN_END, EMACS_DEFUN_BEGIN, EMACS_HELM_OCCUR, _______, \
    _______, _______, REFRAME_SUBSCRIBE, REFRAME_DISPATCH, EMACS_FINDER_COMMENTARY, _______,   _______, editing_h, editing_j, editing_k, editing_l, _______, \
    emacs_left_shift, _______, _______, EMACS_WINDOW_DELETE, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,_______, OSL(_EMACS_SELECT), MO(_CODE), OSL(_EMACS_SELECT), _______,_______,_______,_______,_______,_______



#define planck_code                                          COMPOSE, CLJ_FREQS, _______, _______, _______, _______,    _______, DUPLICATE_LINE, _______, _______, EMACS_WRAP_HYDRA, TEMP_TEXT, \
        TO_BASE, _______, _______, _______, _______, _______,   MOVE_STATEMENT_UP, EMACS_SPLIT_WINDOW_LEFT, EMACS_SPLIT_WINDOW_DOWN, EMACS_SPLIT_WINDOW_UP, EMACS_SPLIT_WINDOW_RIGHT, _______, \
        _______, _______, _______, _______, _______, _______, MOVE_STATEMENT_DOWN, _______, _______, _______, DM_REC2, DM_PLY2, \
        _______, _______, _______, _______, _______, _______, META_X, _______, _______, DM_RSTP, DM_REC1, DM_PLY1

#define planck_emacs_select EMACS_SEL_TAB, EMACS_SEL_Q,  EMACS_SEL_W, EMACS_SEL_E, EMACS_SEL_R, EMACS_SEL_T, EMACS_SEL_MODR1, EMACS_SEL_Y, EMACS_SEL_U,    EMACS_SEL_I,           EMACS_SEL_O,           EMACS_SEL_P, \
        TO(_BASE), EMACS_SEL_A, EMACS_SEL_S, EMACS_SEL_D, EMACS_SEL_F, EMACS_SEL_G, EMACS_SEL_MODR2, EMACS_SEL_H,  EMACS_SEL_J,           EMACS_SEL_K,           EMACS_SEL_L,           EMACS_SEL_SCLN, \
        _______, EMACS_SEL_Z, EMACS_SEL_X, EMACS_SEL_C, EMACS_SEL_V, EMACS_SEL_B, EMACS_SEL_MODR3, EMACS_SEL_N,           EMACS_SEL_M,           EMACS_SEL_COMMA,           EMACS_SEL_DOT,           EMACS_SEL_SLASH, \
        _______, _______, _______, EMACS_WINDOW_DELETE, EMACS_SEL_RAISE, _______, EMACS_SEL_MODR4,          _______, EMACS_SEL_LOWER, EMACS_WINDOW_DELETE, _______, _______



#define planck_sa                            ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, RCTL(KC_0), \
    ESC_THEN_BASE_LAYER, _______, KC_LEFT, _______, KC_RIGHT,    KC_DELETE, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_F11, WEB_SAVE_FILE_UNDER_CURSOR, RCTL(KC_0), _______, _______, _______, _______, _______, LALT(KC_F4), \
    _______, _______, _______, _______,    MO(_MOUSE), _______, _______, _______,    _______, _______, _______, _______


#define planck_mouse                               TO_BASE,    _______, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______,  KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, \
    TO_BASE,  _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,     _______,  _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     KC_MS_BTN3, \
      _______, _______, _______, _______, WEB_SAVE_FILE_UNDER_CURSOR, _______, _______,  LALT(LGUI(KC_N)), KC_MS_BTN3,     BROWSER_TAB_PREV,   BROWSER_TAB_NEXT,   LALT(KC_F4), \
    _______, _______, _______, _______, _______, _______,   _______, KC_BTN4, KC_BTN5,  KC_BTN6, KC_BTN7, KC_BTN8


#define planck_super                              _______, _______,   _______, _______, super_r, _______,    KC_TAB, _______,  _______, _______, _______, _______, \
    LSFT(KC_J), _______, _______, _______, super_f, super_g,    super_mod_r2, _______,  _______, _______, _______, _______, \
        KC_LSFT, _______, _______, _______,    _______, super_b, super_mod_r3, _______,    _______, _______, _______, _______, \
    _______, adhoc_set_hotkey, _______, _______,    _______, _______, LSFT(KC_TAB), ROFI_DRUN, _______, KC_GRAVE, LSFT(KC_TAB), KC_TAB


#define planck_editing EMACS_OTHER_WINDOW, EMACS_DESC_KEY, LCTL(KC_7),     CIDER_EVAL_OR_TERMINAL_EDIT, EMACS_BUFFER_REVERT, LCTL(KC_S),        TO_BASE, EMACS_YANK_IN_SEXP  , editing_u, editing_i, editing_o, PAREDIT_BACKWARD_UP, \
        _______, _______, SURROUND, EMACS_KILL_IN_SEXP, LALT(KC_ENTER), GREP_STRING_IN_BUFFER_DIR,               KC_DELETE, editing_h, editing_j, editing_k, editing_l, EMACS_PRIVATE_READER, \
        editing_left_shift, EMACS_RECENTER_ON_DEFUN, SWAP_SELECTION_BOUNDARIES, EMACS_WINDOW_DELETE,    TD(DANCE_SAVE_LOAD_NS_SWITCH), _______,                                      KC_BACKSPACE, next_win_or_frame, EMACS_BUFFER_MAXIMIZE,  editing_comma, editing_period, TERM_CD_UP_DIR, \
    _______, _______, _______, _______, MO(_EMACS),  _______,                                                  FISH_ACCEPT_SEND, all_mods, MO(_EMACS), TO(_BASE), _______, emacs_indent_buffer


#define planck_winmove                                 _______,   _______, _______, _______, _______, WINDOW_ALWAYS_ON_TOP,  WINDOW_ALWAYS_ON_TOP, winmove_UL,_______, winmove_top, winmove_UR, TOGGLE_MENU_BAR, \
    _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______, _______, winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______, \
    _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______,  _______, winmove_DL, winmove_U_monitor, winmove_bottom, winmove_DR,_______, \
    _______, _______, _______, _______, WINDOW_TOGGLE_HORIZONTAL_MAX,          _______,  _______,         winmove_L_monitor,   winmove_D_monitor,   winmove_R_monitor,    _______, _______

#define planck_winmove_monitor _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, winmove_L_monitor,   winmove_D_monitor, winmove_U_monitor, winmove_R_monitor, _______, \
    _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______


#define planck_all_mods                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,    _______, _______, _______,     _______, _______, _______, _______, _______


#define planck_system                                \
    QK_BOOTLOADER, _______, _______, _______, RESET_INPUT_PREFS,     _______, _______, _______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, QK_CLEAR_EEPROM, KC_MEDIA_PLAY_PAUSE, \
        _______, _______, _______, DB_TOGG, _______, _______, DM_REC1, DM_PLY1, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, QK_AUTOCORRECT_ON, DB_TOGG, \
        QK_AUTO_SHIFT_TOGGLE, _______ , _______, _______, _______, _______,   DM_REC2, DM_PLY2,  KC_AUDIO_MUTE, _______, _______, QK_BOOTLOADER, \
        SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, DM_RSTP, _______, _______, _______, _______, _______


#define planck_windows ALT_TAB, WINDOWS_Q,   LGUI(KC_W),   select_emacs,     TD(DANCE_40),   LGUI(KC_T), LGUI(KC_MINUS),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), \
    TO_BASE, LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, _______,  LGUI(KC_H),     windows_j,   windows_k,   windows_l,   LGUI(KC_SCLN), \
    TO_BASE, LGUI(KC_Z),     select_firefox,     LGUI(KC_C),     LGUI(KC_V),    _______, _______, LGUI(KC_N),   LGUI(KC_M),  _______, LSFT(LGUI(KC_K)), LALT(KC_F4), \
    _______, _______, _______,         _______,        _______,     ALT_TAB ,   ALT_TAB , ROFI_DRUN,      GUI(KC_MINUS),  ALT_TAB, LSFT(ALT_TAB), ALT_TAB


#define planck_macros                                CLJ_ADD_REQS,   CLJ_FREQS, _______, _______, macros_r, COPY_TEXT_OPEN_NEW_TAB_SEARCH, _______, EMACS_COPY_FILE_PATH, EMACS_BACKWARD_UP, EMACS_YAS_FILTER_ANON, _______, _______, \
    TO_BASE, emacs_a, ctrl_alt_s, EMACS_YAS_DOC,     _______,     macros_g, _______,  _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     _______, \
    _______, _______, CLJ_REFIND, EMACS_YAS_C,     _______, _______,  _______, _______, emacs_m,     _______, CLJ_TAP, SHRUG, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, DM_REC1, DM_RSTP, DM_PLY1



#define planck_adhoc_set_key                                            \
    _______, LCTL(LALT(LGUI(KC_Q))), LCTL(LALT(LGUI(KC_W))), LCTL(LALT(LGUI(KC_E))),  LCTL(LALT(LGUI(KC_R))), _______,    SET_HOTKEY_1, LCTL(LALT(LGUI(KC_Y))), LCTL(LALT(LGUI(KC_U))), LCTL(LALT(LGUI(KC_I))), LCTL(LALT(LGUI(KC_O))), LCTL(LALT(LGUI(KC_P))), \
        _______, _______, _______, LCTL(LALT(LGUI(KC_D))), _______,    LCTL(LALT(LGUI(KC_G))), SET_HOTKEY_5, _______, LCTL(LALT(LGUI(KC_J))), LCTL(LALT(LGUI(KC_K))), LCTL(LALT(LGUI(KC_L))), LCTL(LALT(LGUI(KC_SCLN))), \
        _______,  LCTL(LALT(LGUI(KC_Z))), LCTL(LALT(LGUI(KC_X))), LCTL(LALT(LGUI(KC_C))), LCTL(LALT(LGUI(KC_V))), LCTL(LALT(LGUI(KC_V))), SET_HOTKEY_2, LCTL(LALT(LGUI(KC_N))), LCTL(LALT(LGUI(KC_M))), LCTL(LALT(LGUI(KC_COMMA))), LCTL(LALT(LGUI(KC_DOT))), LCTL(LALT(LGUI(KC_SLASH))), \
    _______, _______, _______, _______,    _______, _______, SET_HOTKEY_3, _______,    _______, _______, SET_HOTKEY_4, _______



#define planck_hyper                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

#define planck_dynamic_macros                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


#define planck_layer_lock                                      _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______, \
    TO_BASE, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    SYSTEM_LAYER_ACTIVATE, _______, _______, _______,    LLOCK_RAISE,  _______, LLOCK_LOWER, _______,    LLOCK_LOWER, LLOCK_EDITING, _______, _______

#define planck_scratch _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

#define planck_files _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, EMACS_SET_GLOBAL_LOCATE_DOCS_FILTER_DIR, \
    TO(_BASE), ROFI_LOCATE_GLOBAL, _______, _______, ROFI_LOCATE_WITH_FILTER, ROFI_LOCATE_GLOBAL, _______, _______, ROFI_LOCATE_CLJ, _______, ROFI_LOCATE_PRINT_FILTER_DIR, _______, \
    _______, RG_FZF, DELETE_LOCATE_DOCS_FILTER_DIR, ROFI_LOCATE_SOURCE_FILES, _______, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


#define planck_web _______, _______, _______, _______, RELOAD_TAP_INSPECTOR, COPY_TEXT_OPEN_NEW_TAB_SEARCH,   _______, _______, _______, _______, _______, _______, \
    TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, WEB_SAVE_FILE_UNDER_CURSOR, _______,   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

#define planck_motion                               EMACS_OTHER_WINDOW,   my_lower_q,          my_lower_w,          my_lower_e,          my_lower_r,  TD(DANCE_SCREENSHOT),      LLOCK,    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p, \
        _______, my_lower_a,          my_lower_s,          my_lower_d,          my_lower_f,          my_lower_g, RCTL(KC_UP),      my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi, \
        lower_left_shift,   my_lower_z,         my_lower_x,         my_lower_c,         my_lower_v,         my_lower_b, RCTL(KC_DOWN),  my_lower_n, my_lower_m, RCTL(KC_HOME),   RCTL(KC_END), my_lower_slash, \
        _______, _______, _______ , alt,   _______, _______,       _______,             _______, _______,          TD(WWW_BACK_FORWARD), RCTL(KC_LEFT), RCTL(KC_RIGHT)
