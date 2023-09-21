#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#include "../../../../common/drop_keymap.c"
#include "colors.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_voyager(top_left,    my_q,    my_w,    my_e,    my_r,   my_t, mod_r1, my_y,           my_u,    my_i,    my_o,     my_p,   \
                             esc_ctrl, my_a,   my_s,   my_d,   my_f,   my_g,  mod_r2, my_h,         my_j,   my_k,   my_l,   my_semicolon,  \
                             left_of_z,        my_z,           my_x,           my_c,           my_v,           my_b, mod_r3,  my_n,   my_m,   my_comma,   my_dot,   my_forward_slash, \
                             hyper, level3,   alt_keyboard,         alt,  RAISE,   QK_REPEAT_KEY,     QK_ALT_REPEAT_KEY, my_space, LOWER,           my_right_of_lower,   key_left,  key_right, \
                             super,  TD(DANCE_OSM_LEADER_MO_MOUSE), TD(DANCE_OSM_LEADER_MO_MOUSE),  TD(DANCE_WINMOVE_SELECT)),


    // layer to swap left & right.  or maybe already exists?

    [_ALT] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_TAB), KC_TAB, \
                            _______, _______, _______, _______              ),

    [_RAISE] = LAYOUT_voyager(raise_tab,    my_raise_q,          my_raise_w,  my_raise_e,         my_raise_r,       my_raise_t, raise_mod_r1,  my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, \
                              _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  my_raise_g,  raise_mod_r2,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,      raise_semi,\
                              raise_left_shift, my_raise_z, my_raise_x, my_raise_c,  my_raise_v,      my_raise_b,  raise_mod_r3,     my_raise_n,           my_raise_m,           my_raise_comma,         my_raise_period,           raise_slash,\
                              MO(_SYSTEM), _______, _______,        _______,        TO(_BASE), _______, _______,  my_space,   raise_key_4_9,       KC_INSERT,  KC_DOWN,         KC_UP, \
                              _______, raise_left_shift, _______, _______),

    [_SHIFTLOCK] = LAYOUT_voyager(KC_TAB,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T), TO_BASE,     LSFT(KC_Y),     my_cap_u,     my_cap_i,     my_cap_o,     my_cap_p,\
                                  _______,          my_cap_a,     my_cap_s,     my_cap_d,     my_cap_f,     LSFT(KC_G), _______,     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     my_cap_semi,\
                                  SHIFTLOCK_LAYER_DEACTIVATE,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     my_cap_v,     LSFT(KC_B), _______,    my_cap_n,     my_cap_m,     my_cap_comma,        my_cap_period,        my_forward_slash,\
                                  _______, _______, _______, _______, RAISE, _______, _______,        _______,    LOWER,  _______, _______, _______,\
                                  _______, SHIFTLOCK_LAYER_DEACTIVATE, _______, _______),


    [_LOWER] = LAYOUT_voyager(KC_GRAVE,   my_lower_q,          my_lower_w,          my_lower_e,          my_lower_r,  my_lower_t, _______,     my_lower_y,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p, \
                              _______, my_lower_a,          my_lower_s,          my_lower_d,          my_lower_f,          my_lower_g,    _______,   my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi,\
                              lower_left_shift,   my_lower_z,         my_lower_x,         my_lower_c,         my_lower_v,         my_lower_b,  _______, my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash, \
                              _______, _______, _______ , alt,  MO(_EDITING),               KC_APP, _______,_______, lower_LOWER,          lower_right_of_lower, _______, MO(_SYSTEM), \
                              MO(_EDITING), RESET_INPUT_PREFS, _______,            lower_right_of_lower),

    /* [_FN] = LAYOUT_voyager(planck_fn,_______, _______, _______, _______), */



    [_ROFI] = LAYOUT_voyager(ESC_THEN_BASE_LAYER, _______, LAUNCHER_WIKI, _______,  _______, LAUNCHER_TRANSLATE, _______,  ROFI_LOCATE_GLOBAL, ROFI_LOCATE, LAUNCHER_WINDOWS, LAUNCHER_CLIPBOARD, COPY_LATEST_FILE_TO_CLIPBOARD, \

                             CLEAR_NOTIFICATIONS, _______, LAUNCHER_SOUND, LAUNCHER_DEFINE, LAUNCHER_FDFIND,   LAUNCHER_GOOGLE, _______,  CIDER_HISTORY_WRITE, ROFI_CIDER_HISTORY, ROFI_EMOJI, ROFI_PROCESSES, ULAUNCHER, \

                             _______, _______, _______, ROFI_CALCULATOR, _______, _______, _______,  OPEN_NOTIFICATIONS, CINNAMON_MENU_OPEN, PLASMA_SEARCH, _______, _______, \

                             _______, _______, _______,    _______, _______, _______, _______,  _______,    _______, DM_REC1, DM_RSTP, DM_PLY1, \

                             ROFI_DRUN, _______, _______, _______),

    [_SA] = LAYOUT_voyager(ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______,    _______,  _______, _______, _______, _______, RCTL(KC_0),\
                           ESC_THEN_BASE_LAYER, _______, KC_LEFT, _______, KC_RIGHT,    KC_DELETE,  _______, _______, _______, _______, _______, _______,\
                           _______, _______, _______, KC_F11, WEB_SAVE_FILE_UNDER_CURSOR, RCTL(KC_0),  _______, _______, _______, _______, _______, LALT(KC_F4),\
                           _______, _______, _______, _______,    MO(_MOUSE), _______,  _______, _______,    _______, _______, _______, _______,\
                           _______, _______, _______, _______),


    [_MOUSE] = LAYOUT_voyager(TO_BASE,          KC_NO, KC_NO, MS_UP,        WEB_RELOAD, WEB_OPEN_TABS,
                              KC_NO, MS_WHLL,  MS_WHLD,  MS_WHLU,    MS_WHLR, KC_NO,

                              TO_BASE,          MS_BTN1,     MS_LEFT,     MS_DOWN,     MS_RGHT,    MS_BTN1,
                              KC_NO, KC_WWW_BACK,    MS_BTN1,     MS_BTN3,     MS_BTN2,     KC_WWW_FORWARD,

                              TO_BASE, my_raise_z, my_raise_x, my_raise_c, WEB_SAVE_FILE_UNDER_CURSOR, WEB_BOOKMARKS,
                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, WEB_CLOSE_TAB,

                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO, KC_NO, CYCLE_WINDOWS_BACKWARD, CYCLE_WINDOWS_FORWARD,

                              KC_NO, TT(_MOUSE),                                 KC_NO, KC_NO
                                  ),

// 11
    [_SUPER] = LAYOUT_voyager(KC_TAB, _______,   _______, _______, super_r, _______, LALT(KC_TAB),     _______,  _______, _______, _______, _______,\
                              LGUI(LSFT(KC_J)), _______, _______, _______, super_f, super_g,     super_mod_r2, _______,  _______, _______, _______, _______,\
                              KC_LSFT, _______, _______, _______,    _______, super_b,  super_mod_r3, _______,    _______, _______, _______, _______,\
                              _______, adhoc_set_hotkey, _______, _______,    _______, _______, _______,  ROFI_DRUN, _______, KC_GRAVE, LSFT(KC_TAB), KC_TAB,\
                             _______, _______, _______, _______),



// 12
    [_EDITING] = LAYOUT_voyager(EMACS_OTHER_WINDOW, EMACS_DESC_KEY, LCTL(KC_7),     CIDER_EVAL_OR_TERMINAL_EDIT, EMACS_BUFFER_REVERT, LCTL(KC_S),        TO_BASE,                                 EMACS_YANK_IN_SEXP  , editing_u, editing_i, editing_o, PAREDIT_BACKWARD_UP, \
                                _______, _______, SURROUND, EMACS_KILL_IN_SEXP, HELM_FIND_FILE, GREP_STRING_IN_BUFFER_DIR,                KC_DELETE,                                 editing_h, editing_j, editing_k, editing_l, EMACS_PRIVATE_READER, \
                                editing_left_shift, EMACS_RECENTER_ON_DEFUN, SWAP_SELECTION_BOUNDARIES, EMACS_WINDOW_DELETE,    TD(DANCE_SAVE_LOAD_NS_SWITCH),                                       KC_BACKSPACE, _______,                                 next_win_or_frame, EMACS_BUFFER_MAXIMIZE,  EMACS_WINNER_UNDO, EMACS_WINNER_UNDO, TERM_CD_UP_DIR, \
                                _______, _______, _______, _______, MO(_EMACS),  OSL(_MOUSE),                                                   FISH_ACCEPT_SEND,                                 all_mods, MO(_EMACS), TO(_BASE), _______, emacs_indent_buffer, \

                                _______,editing_left_shift, _______, _______),

    [_EMACS] = LAYOUT_voyager(EMACS_FOCUS_REPL, EMACS_DESC_KEY, EMACS_WRAP_HYDRA, LCTL(KC_E), EMACS_HELM_MARK_RINGS, EMACS_TRANSPOSE,    _______,                               EMACS_HELM_KILL_RINGS, EMACS_DEFUN_END, EMACS_DEFUN_BEGIN, EMACS_HELM_OCCUR, _______, \
                              _______, _______, REFRAME_SUBSCRIBE, REFRAME_DISPATCH, EMACS_FINDER_COMMENTARY, _______,    _______,                               editing_h, editing_j, editing_k, editing_l, _______, \
                              emacs_left_shift, _______, _______, EMACS_WINDOW_DELETE, _______, _______,  _______,                               _______, _______, _______, _______, _______, \
                              _______, _______,_______, _______, MO(_CODE), OSL(_EMACS_SELECT), _______,                               _______,_______,_______, KC_DOWN, KC_UP, \

                              _______, emacs_left_shift, _______, _______),


// 9
    [_WINMOVE] = LAYOUT_voyager(_______,   _______, _______, _______, _______, WINDOW_ALWAYS_ON_TOP, _______,                                      winmove_UL, winmove_bottom, winmove_top,  winmove_UR, TOGGLE_MENU_BAR, \
                                _______, _______, _______, LGUI(KC_D),_______, _______, CYCLE_WINDOWS_FORWARD,                                 winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______, \
                                _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______, CYCLE_WINDOWS_BACKWARD,                                 winmove_DL, winmove_U_monitor, winmove_bottom, winmove_DR, CLOSE_WINDOW, \
                                _______, _______, _______, _______, WINDOW_TOGGLE_HORIZONTAL_MAX, _______,     _______,                                          winmove_L_monitor, winmove_D_monitor,   winmove_R_monitor, _______, _______,  \

                                TOGGLE_MENU_BAR, TOGGLE_MENU_BAR, TOGGLE_MENU_BAR, TOGGLE_MENU_BAR),

// 4
    [_ALL_MODS] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______,    _______, _______, _______,     _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______),


// 5
    [_SYSTEM] = LAYOUT_voyager(QK_BOOTLOADER, QK_RGB_MATRIX_MODE_PREVIOUS, QK_RGB_MATRIX_MODE_NEXT, _______, RESET_INPUT_PREFS,     _______, _______,                                _______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, _______, KC_MEDIA_PLAY_PAUSE, \
                               KC_ESC, _______, _______, DB_TOGG, _______, _______, QK_RGB_MATRIX_VALUE_UP,                                QK_RGB_MATRIX_SPEED_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, QK_AUTOCORRECT_ON, DB_TOGG, \
                               AUTOSHIFT_TOGGLE, _______ , _______, AC_ON, _______, TOGGLE_MENU_BAR,   QK_RGB_MATRIX_VALUE_DOWN,                                QK_RGB_MATRIX_SPEED_DOWN, KC_AUDIO_MUTE, _______, _______, TOGGLE_LAYER_COLOR, \
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, QK_RGB_MATRIX_MODE_NEXT,                                _______, _______,  _______, QK_RGB_MATRIX_MODE_PREVIOUS, QK_RGB_MATRIX_MODE_NEXT, \
                                _______, _______, _______, DM_RSTP),

// 6
    [_WINDOWS] = LAYOUT_voyager(_______, WINDOWS_Q,   LGUI(KC_W),   select_emacs,     TD(DANCE_40),   LGUI(KC_T), SELECT_HOTKEY_1,   LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), \
                                TO_BASE, LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),    LGUI(KC_G),  SELECT_HOTKEY_2,   LGUI(KC_H),     windows_j,   windows_k,   windows_l,   LGUI(KC_SCLN),\
                                TO_BASE, LGUI(KC_Z),     select_firefox,     LGUI(KC_C),     LGUI(KC_V),   LGUI(KC_B), SELECT_HOTKEY_3,  LGUI(KC_N),   LGUI(KC_M),  _______, LSFT(LGUI(KC_K)), CLOSE_WINDOW, \
                                WINDOW_SELECTION_SCREEN, _______, _______,         _______,        _______,     KC_LGUI,   SELECT_HOTKEY_4,  ROFI_DRUN,      GUI(KC_MINUS),  _______, CYCLE_WINDOWS_BACKWARD, CYCLE_WINDOWS_FORWARD,\
                                KC_LGUI, _______, _______, _______),

/* // 7 */
    [_MACROS] = LAYOUT_voyager(CLJ_ADD_REQS,   CLJ_FREQS, _______, _______, macros_r, COPY_TEXT_OPEN_NEW_TAB_SEARCH,_______,                                EMACS_COPY_FILE_PATH, EMACS_BACKWARD_UP, EMACS_YAS_FILTER_ANON, _______, _______, \
                               TO_BASE, emacs_a, ctrl_alt_s, EMACS_YAS_DOC,     _______,     macros_g,  _______,                                _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     _______, \
                               _______, _______, CLJ_REFIND, EMACS_YAS_C,     _______, _______, _______,                                _______, emacs_m,     _______, CLJ_TAP, SHRUG, \
                               _______, _______, _______, _______, _______, _______,  _______,                                _______, _______, DM_REC1, DM_RSTP, DM_PLY1, \

                               _______, _______, _______, _______),

    [_ADHOC_SET_HOTKEY] = LAYOUT_voyager(_______, LCTL(LALT(LGUI(KC_Q))), LCTL(LALT(LGUI(KC_W))), LCTL(LALT(LGUI(KC_E))),  LCTL(LALT(LGUI(KC_R))), _______,  SET_HOTKEY_1,   LCTL(LALT(LGUI(KC_Y))), LCTL(LALT(LGUI(KC_U))), LCTL(LALT(LGUI(KC_I))), LCTL(LALT(LGUI(KC_O))), LCTL(LALT(LGUI(KC_P))), \
                                         _______, _______, _______, LCTL(LALT(LGUI(KC_D))), _______,    LCTL(LALT(LGUI(KC_G))), SET_HOTKEY_2,  LCTL(LALT(LGUI(KC_H))), LCTL(LALT(LGUI(KC_J))), LCTL(LALT(LGUI(KC_K))), LCTL(LALT(LGUI(KC_L))), LCTL(LALT(LGUI(KC_SCLN))),\
                                         _______,  LCTL(LALT(LGUI(KC_Z))), LCTL(LALT(LGUI(KC_X))), LCTL(LALT(LGUI(KC_C))), LCTL(LALT(LGUI(KC_V))), LCTL(LALT(LGUI(KC_B))),  SET_HOTKEY_3, LCTL(LALT(LGUI(KC_N))), LCTL(LALT(LGUI(KC_M))), LCTL(LALT(LGUI(KC_COMMA))), LCTL(LALT(LGUI(KC_DOT))), LCTL(LALT(LGUI(KC_SLASH))),\
                                         _______, _______, _______, _______,    _______, _______,SET_HOTKEY_4,  _______,    _______, _______, _______, _______, \
                                         _______, _______, _______, _______),

    [_HYPER] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______, \
                              _______, _______, _______, _______),

    [_LAYER_LOCK] = LAYOUT_voyager(TO_BASE, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, \
                                   TO_BASE, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
                                   SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                   SYSTEM_LAYER_ACTIVATE, _______, _______, _______,    LLOCK_RAISE,  _______, _______, _______,    LLOCK_LOWER, LLOCK_EDITING, _______, _______, \
                                   _______, _______, _______, _______),

    [_CODE] = LAYOUT_voyager(COMPOSE, CLJ_FREQS, EMACS_WRAP_HYDRA, _______, _______, _______,     _______, _______, MOVE_STATEMENT_DOWN, MOVE_STATEMENT_UP,   _______, DUPLICATE_LINE, \
                             TO_BASE, _______, _______, _______, _______, _______,   _______, EMACS_SPLIT_WINDOW_LEFT, EMACS_SPLIT_WINDOW_DOWN, EMACS_SPLIT_WINDOW_UP, EMACS_SPLIT_WINDOW_RIGHT, _______,\
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,\
                             _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______, \
                                         _______, _______, _______, _______),

    [_EMACS_SELECT] = LAYOUT_voyager(BROWSER_MOST_RECENT_TAB, EMACS_SEL_1,  EMACS_SEL_2, EMACS_SEL_3, EMACS_SEL_4, EMACS_SEL_5,  EMACS_SEL_MODR1, EMACS_SEL_Y, EMACS_SEL_U,    EMACS_SEL_I,           EMACS_SEL_O,           EMACS_SEL_P, \
                                     TO(_BASE), EMACS_SEL_A, EMACS_SEL_S, EMACS_SEL_D, EMACS_SEL_F, EMACS_SEL_G,  EMACS_SEL_MODR2, EMACS_SEL_H,  EMACS_SEL_J,           EMACS_SEL_K,           EMACS_SEL_L,           EMACS_SEL_SCLN,\
                                     _______, EMACS_SEL_Z, EMACS_SEL_X, EMACS_SEL_C, EMACS_SEL_V, EMACS_SEL_B,  EMACS_SEL_MODR3, EMACS_SEL_N,           EMACS_SEL_M,           EMACS_SEL_COMMA,           EMACS_SEL_DOT,           EMACS_SEL_SLASH,\
                                     _______, _______, _______, EMACS_WINDOW_DELETE, EMACS_SEL_RAISE, _______, EMACS_SEL_MODR4,          _______, EMACS_SEL_LOWER, EMACS_WINDOW_DELETE, _______, _______, \
                                     _______, _______, _______, _______),

    [_FILES] = LAYOUT_voyager(_______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, EMACS_SET_GLOBAL_LOCATE_DOCS_FILTER_DIR,\
                              TO(_BASE), ROFI_LOCATE_GLOBAL, _______, _______, ROFI_LOCATE_WITH_FILTER, ROFI_LOCATE_GLOBAL,  _______, _______, ROFI_LOCATE_CLJ, _______, ROFI_LOCATE_PRINT_FILTER_DIR, _______,\
                              _______, RG_FZF, DELETE_LOCATE_DOCS_FILTER_DIR, ROFI_LOCATE_SOURCE_FILES, _______, _______,    _______, _______, _______, _______, _______, _______,\
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______, _______),

    [_WEB] = LAYOUT_voyager(_______, _______, BROWSER_SEARCH_OPEN_TABS, _______, RELOAD_TAP_INSPECTOR, COPY_TEXT_OPEN_NEW_TAB_SEARCH, _______, _______, WEB_UNSPLIT_TABS, _______, _______, _______, \
                            TO(_BASE), _______, WEB_NEW_SPLIT_VIEW, _______, _______, BRAVE_SEARCH_TO_GOOGLE, _______, _______, _______, _______, _______, _______, \
                            _______, _______, CUT_TEXT_IN_FIRST_FIELD, WEB_NEW_SPLIT_VIEW, WEB_SAVE_FILE_UNDER_CURSOR, _______, WEB_SWAP_TABS,   _______, _______, _______, _______, _______, \
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                            _______, _______, _______, _______),

/*     [_MOTION] = LAYOUT_voyager(planck_motion                                         ,_______, _______, _______, _______), */
/*     [_LEADER1] = LAYOUT_voyager(planck_leader1                                         ,_______, _______, _______, _______) */

};

// /home/jason/Projects/qmk_firmware/keyboards/zsa/voyager/keymaps/jasonisgraham/keymap.c
// /home/jason/Projects/qmk_firmware/keyboards/common/combos.c
