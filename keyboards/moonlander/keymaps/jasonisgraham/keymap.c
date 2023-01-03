#include QMK_KEYBOARD_H
#include "version.h"

// must be included before drop stuff
#include "colors.c"
#include "../../../common/drop_keymap.c"

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX
#define MOON_LED_LEVEL LED_LEVEL

#include "muse.h"
/* #include "muse.h"user_song_list.h" */
#include "keymap_us_international_linux.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

/* #include "keymap_us_extended.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX



/* #include "../../../common/planck_keymap.h" */

/* #include QMK_KEYBOARD_H */


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
                              top_left,    my_q,    my_w,    my_e,    my_r,   my_t, _______, _______, mod_r1,   my_y,           my_u,    my_i,    my_o,     my_p,
                              esc_ctrl , my_a,   my_s,   my_d,   my_f,   my_g,  _______, _______, mod_r2,     my_h,         my_j,   my_k,   my_l,   my_semicolon,
                              my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,     _______, _______, mod_r3, my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
                              hyper, apl_level3_and_adhoc_hotkey, all_mods,      alt, RAISE,      super,       mod_r4, my_space,  LOWER,            emacs_and_backspace,    key_4_11,  key_4_12,
                              _______,_______,_______,_______,_______,   TD(DANCE_ROFI), SELECT_HOTKEY_0, _______,_______,_______,_______,_______,
                              my_lower_semi, TD(DANCE_LEFT_OR_HOME), KC_DOWN,   KC_UP, TD(DANCE_RIGHT_OR_END), EVIL_JUMP
                              ),

  [_RAISE] = LAYOUT_moonlander(LSFT(KC_TAB),    my_raise_q,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       QK_CAPS_WORD_TOGGLE, _______,  _______, _______, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                               _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  TD(DANCE_MACROS), _______,  _______, _______,        my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,       raise_semi,
                               SHIFTLOCK_LAYER_ACTIVATE, my_raise_z, my_raise_x, my_raise_c,  my_raise_v,      my_raise_b,  _______,  _______, _______,my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash,
                               MO(_SYSTEM), _______, KC_ENTER,        _______,        TO(_BASE),  _______, _______,      my_space , raise_key_4_9,       raise_up,     _______,      TO(_BASE),
                               _______,_______, _______,_______,_______,   CAPS_WORD,_______, RGB_MOD, _______,_______,_______,_______,
                               _______, TD(DANCE_RIGHT_OR_END), KC_UP, KC_DOWN,  TD(DANCE_LEFT_OR_HOME), _______
),


[_SHIFTLOCK] = LAYOUT_moonlander(
                                 SHIFTLOCK_LAYER_DEACTIVATE,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T), _______, _______, _______,  LSFT(KC_Y),     my_cap_u,     my_cap_i,     my_cap_o,     my_cap_p,
                                 ESC_THEN_BASE_LAYER,          LSFT(KC_A),     LSFT(KC_S),     my_cap_d,     my_cap_f,     LSFT(KC_G), _______, _______,  _______, my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     my_cap_semi,
                                 my_left_shift,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),    _______,  _______,  _______, my_cap_n,     my_cap_m,     my_cap_comma,        my_cap_period,        my_forward_slash,
                                 _______, _______, _______, _______, RAISE, _______,  _______, _______, LOWER,       _______,     _______,  _______,
                                 _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,  _______
),


[_LOWER] = LAYOUT_moonlander(
                             LALT(KC_C),   KC_F1,          KC_F2,          KC_F3,          KC_F4,  TD(DANCE_SCREENSHOT),      _______,_______,  _______,    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p, \
                             _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          my_lower_g, _______,_______,_______,   my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,      my_lower_semi,
                             lower_left_shift,   KC_F9,         KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, _______,_______, _______,   my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash,
                             MO(_SYSTEM), _______, _______ , alt,   MO(_EDITING), _______, _______,    _______, lower_LOWER,          lower_right_of_lower,  lower_key_4_11, lower_key_4_12,
                             _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                             _______, TD(DANCE_RIGHT_OR_END), KC_UP, KC_DOWN,  TD(DANCE_LEFT_OR_HOME), _______
                             ),



[_ROFI] = LAYOUT_moonlander(
                            ESC_THEN_BASE_LAYER, _______, _______, _______, _______,    _______, _______,_______, _______,  _______, ROFI_LOCATE, ROFI_WINDOWS, ROFI_CLIPBOARD, COPY_LATEST_FILE_TO_CLIPBOARD,
                            ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______,   _______,_______, _______, _______, _______, ROFI_EMOJI, PLASMA_SEARCH, _______,
                            TO(_BASE), _______, _______, _______, _______, _______, _______,_______, _______, NOTIFICATIONS, CINNAMON_MENU_OPEN, _______, _______, _______,
                            TO(_BASE), _______, _______, _______, _______, _______,_______, ROFI_DRUN,  _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                            TO(_BASE), _______,_______,_______,_______,  _______
                            ),

[_EMACS] = LAYOUT_moonlander(
                             EMACS_TOGGLE_REPL, EMACS_DESC_KEY, _______, _______, EMACS_HELM_MARK_RINGS, EMACS_TRANSPOSE, _______,_______, _______, EMACS_HELM_KILL_RINGS, EMACS_DEFUN_END, EMACS_DEFUN_BEGIN, _______, _______,
                             _______, _______, REFRAME_SUBSCRIBE, REFRAME_DISPATCH, EMACS_FINDER_COMMENTARY, _______, _______,_______, _______,  EMACS_SPLIT_WINDOW_LEFT, EMACS_SPLIT_WINDOW_DOWN, EMACS_SPLIT_WINDOW_UP, EMACS_SPLIT_WINDOW_RIGHT,_______,
                             _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______
                                ),

[_SA] = LAYOUT_moonlander(
                          ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______, _______,_______, _______,  _______,  _______,  _______,  _______,  _______,
                          ESC_THEN_BASE_LAYER, _______, KC_LEFT, _______, KC_RIGHT, KC_DELETE, _______,_______, _______, _______,         _______, _______, _______, _______,
                          _______, _______, _______, _______, WEB_SAVE_FILE_UNDER_CURSOR, _______, _______,_______,_______,_______,_______,_______,
                          _______, _______, _______, _______,    MO(_MOUSE), _______,_______, _______, _______,    _______, _______, _______,
                          _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______,_______,_______,_______
                            ),


[_MOUSE] = LAYOUT_moonlander(
                             TO(_BASE),    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______,   _______,_______,   _______,    KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                             _______,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,   _______,_______,   _______,  KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                             _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,_______,    LALT(LGUI(KC_N)), KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   all_mods,
                             _______, _______, _______, _______, _______, _______,_______,   _______,  _______, LGUI(LCTL(KC_M)),          _______, _______,
                             _______,  _______,  _______,  _______, _______, _______
),


// 11
[_SUPER] = LAYOUT_moonlander(
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             LSFT(KC_J), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, adhoc_set_hotkey,  _______,  _______, _______,    _______,_______, ROFI_DRUN,     ROFI_CLIPBOARD, ROFI_WINDOWS, LSFT(KC_TAB), KC_TAB,
                             _______, _______, _______, _______,    _______, _______,_______,   _______,    _______, _______, _______,  LALT(KC_7),
                             TD(DANCE_ALT_OR_RCTRL), _______, _______, _______, _______,   _______

                              ),



// 12
[_EDITING] = LAYOUT_moonlander(
                               EMACS_ACE_WINDOW_SELECT, EMACS_DESC_KEY, LCTL(KC_7),     LCTL(KC_E), _______,     LCTL(KC_S) , _______,_______, LALT(KC_UNDS),  EMACS_YANK_IN_SEXP  , EMACS_NEXT_SEXP ,EMACS_PREV_SEXP ,  EMACS_HELM_OCCUR, KC_DELETE,

                               _______, _______, EMACS_LOCCUR, EMACS_KILL_IN_SEXP, LALT(KC_ENTER), EMACS_COPY_FILE_PATH, EMACS_SCROLL_UP,_______, _______, editing_h, editing_j, editing_k, editing_l, EMACS_PRIVATE_READER,
                               emacs_left_shift, EMACS_RECENTER_ON_DEFUN, _______, EMACS_WINDOW_CLOSE,    TD(DANCE_SAVE_LOAD_NS_SWITCH), _______, _______,_______,_______,   next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  editing_comma, editing_period, TERM_CD_UP_DIR,
                               _______, _______, _______, _______, KC_HYPR,  _______,_______,  _______,                    MO(_EMACS), TO(_BASE), _______,  emacs_indent_buffer,
                               _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, all_mods
                               ),


// 9
[_WINMOVE] = LAYOUT_moonlander(
                               TO(0),   _______, _______, _______, _______, WINDOW_ALWAYS_ON_TOP, _______,_______,  _______, winmove_UL,_______, _______, winmove_UR, TOGGLE_MENU_BAR,
                               _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______,  _______,_______, _______, winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______,
                               _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______, _______,_______,_______,   winmove_DL, winmove_U_monitor, _______, winmove_DR,_______,
                               _______, _______, _______, _______, MO(_WINMOVE_MONITOR),          _______,_______, winmove_L_monitor,    winmove_D_monitor,   winmove_R_monitor,    _______, _______,
                               _______, _______, _______, _______, _______, _______,_______, WINDOW_ALWAYS_ON_TOP, _______, _______, _______, _______,
                               _______, _______,_______,_______,_______, winmove_L_monitor),

[_WINMOVE_MONITOR] = LAYOUT_moonlander(
                                       _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______,_______, _______, winmove_L_monitor,   winmove_D_monitor, winmove_U_monitor, winmove_R_monitor,  _______,
                                       _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                       _______, _______, _______, _______, _______, _______
                                                            ),


// 4
[_ALL_MODS] = LAYOUT_moonlander(
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______,_______, _______, _______, _______, _______

                              ),


[_SYSTEM] = LAYOUT_moonlander(
                              _______, _______, RGB_VAI, _______, QK_BOOTLOADER, _______,  _______,_______,  _______, QK_KEY_OVERRIDE_ON, QK_KEY_OVERRIDE_OFF, QK_DEBUG_TOGGLE, QK_CLEAR_EEPROM, QK_BOOTLOADER,
                              CLEAR_MODIFIERS, _______, RGB_VAD, _______, _______, _______,  _______,_______,  _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, QK_AUTOCORRECT_ON, DB_TOGG,
                              QK_CLEAR_EEPROM, _______ , _______, _______, _______, _______,  _______,_______, _______,    _______, KC_AUDIO_MUTE, CYCLE_DROP_ANIMATIONS,  _______, RGB_TOG,
                              SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______,_______,    RGB_TOG, RGB_MOD, RGB_HUI, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,
                              _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                              _______,  _______,  _______,  _______,  _______,  _______
                              ),

// 6
[_WINDOWS] = LAYOUT_moonlander(

                               ALT_TAB, WINDOWS_Q,   LGUI(KC_W),   WINDOWS_E,     TD(DANCE_40),   LGUI(KC_T), _______,_______, _______,  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),
                               LALT(LGUI(KC_ESCAPE)), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, _______,_______, _______,  LGUI(KC_H),     TD(DANCE_HOTKEY_OR_COMPOSE),   windows_k,   windows_l,   LGUI(KC_SCLN),
                               TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),    _______,  _______,_______, _______,LGUI(KC_N),   LGUI(KC_M),  _______, LSFT(LGUI(KC_K)), LALT(KC_F4),
                               _______, _______, _______,         _______,        _______,     ALT_TAB ,_______,    ROFI_DRUN,         GUI(KC_MINUS),  ALT_TAB, _______, _______,
                               _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                               ALT_TAB , _______,_______,_______,_______, _______
                                ),

// 7
[_MACROS] = LAYOUT_moonlander(

                              TO_BASE,   _______, SSH_PROD, _______, emacs_r, COPY_TEXT_OPEN_NEW_TAB_SEARCH, _______,_______, _______,  EMACS_COPY_FILE_PATH, EMACS_BACKWARD_UP, EMACS_INSERT_GI_GET_FEED, CD_C9, COPY_LATEST_FILE_TO_CLIPBOARD,
                              TO_BASE, emacs_a, SSH_CRONJOBS_PROD, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, _______,_______, _______, _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     EMACS_PF_UP,
                              _______, _______, CLJ_REFIND, EMACS_YAS_C,     _______, _______,   _______,_______, _______, _______, emacs_m,     _______, _______, TERM_CD_UP_DIR,
                              _______, _______, _______, _______, _______, _______,_______,   _______,  _______,           _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                              _______,  _______,_______,_______,_______,_______
                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_moonlander(

                                        _______, LCTL(LALT(LGUI(KC_Q))), LCTL(LALT(LGUI(KC_W))), _______,  LCTL(LALT(LGUI(KC_R))), _______, _______,_______,  SET_HOTKEY_1, LCTL(LALT(LGUI(KC_Y))), _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______,    LCTL(LALT(LGUI(KC_G))), _______,_______,  SET_HOTKEY_5, LCTL(LALT(LGUI(KC_J))), LCTL(LALT(LGUI(KC_K))), LCTL(LALT(LGUI(KC_L))), _______,_______,
                                        _______, _______, SET_HOTKEY_5, SET_HOTKEY_5, _______, _______, _______,_______, SET_HOTKEY_2,  LCTL(LALT(LGUI(KC_N))), _______, _______, _______, LCTL(LALT(LGUI(KC_SLASH))),
                                        _______, _______, _______,    _______, _______, _______, SET_HOTKEY_3,  _______, _______,    _______, SET_HOTKEY_4, _______,
                                        _______,_______,_______,_______,_______,   _______, SET_HOTKEY_0, _______,_______,_______, SET_HOTKEY_4,_______,
                                        _______,_______,_______,_______,  _______,  _______
                              ),

[_HYPER] = LAYOUT_moonlander(
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,_______, _______, MO(_EMACS), _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______
                                                                   ),

[_LAYER_LOCK] = LAYOUT_moonlander(
                                  _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  TO(_BASE),_______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,
                                  SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  SYSTEM_LAYER_ACTIVATE, _______, _______, _______, LLOCK_RAISE, _______,_______, LLOCK_APL, _______, LLOCK_LOWER, LLOCK_EDITING, _______, _______,
                                  _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______
)

};
