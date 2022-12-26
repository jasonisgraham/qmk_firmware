#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _HYPER,
                    _ROFI,
                    _WINDOWS,
                    _MACROS,
                    _SHIFTLOCK,
                    _WINMOVE,
                    _SUPER,
                    _EDITING,
                    _EMACS,
                    _MOUSE,
                    _ADHOC_SET_HOTKEY,
                    _SYSTEM,
                    _ALL_MODS,
                    _ALT,
};

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX

#include "../../../../../quantum/rgblight/rgblight.h"
/* #include "../../../../common/drop_animations.c" */
#include "../../../../common/keycodes.c"
#include "../../../../common/key_overrides.c"
#include "../../../../common/drop_tapdance.c"
/* #include "../../../../common/drop_colors.c" */
/* #include "../../../../common/encoder.c" */
#include "../../../../common/layer_lock.h"

/* #include "encoder.h" */
/* const int row0[10]; */
/* #define row0  { top_left } */
/* const int row0[] = { top_left, top_left,    my_q,    my_w,    my_e,    my_r,   my_t, backspace ,    my_y,           my_u,    my_i,    my_o,     my_p}; */
/* int row0[10] = {}; */

#define key_1_7 top_alpha_mid_column
#define key_2_7 backspace
#define key_3_7 KC_ENTER
#define key_4_7 esc_ctrl

#define k1_1 top_left
/* #define k1_1 QK_BOOT */
#define k2_1 my_lctl
/* #define k2_1  RESET */

#define EMACS_RECENTER_ON_DEFUN RCTL(RALT(KC_Z))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

                                                              // LAYER_LOCK
[_BASE] = LAYOUT_ortho_4x12(
                             k1_1,    my_q,    my_w,    my_e,    my_r,   my_t, key_1_7,    my_y,           my_u,    my_i,    my_o,     my_p,
                             k2_1, my_a,   my_s,   my_d,   my_f,   my_g, key_2_7,  my_h,         my_j,   my_k,   my_l,   my_semicolon,
                             my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b, key_3_7,     my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
                             KC_1, KC_2, KC_3,   KC_4, KC_5,  KC_6, KC_7,   KC_8,           KC_9,          KC_A,   KC_B,  KC_C
                             /* hyper, super_meta_hyper, all_mods,   alt, RAISE,  super, key_4_7,   my_space,           LOWER,          my_right_of_lower,   key_4_11,  key_4_12 */
                              ),

[_LOWER] = LAYOUT_ortho_4x12(
                              LALT(KC_C),   KC_F1,          KC_F2,          KC_F3,          KC_F4,  TD(DANCE_73),        _______ ,    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p,
                              _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          my_lower_g, lower_backspace,      KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi,
                              _______,   KC_F9,         KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, KC_SCROLL_LOCK,  my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash,
                              SYSTEM_LAYER_ACTIVATE, _______, _______ , alt,   MO(_EDITING), MO(_MOUSE),           lower_right_of_super,         MO(_MOUSE), lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12


                              ),

[_RAISE] = LAYOUT_ortho_4x12(
                              LSFT(KC_TAB),    _______,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       _______, _______, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                              _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  OSL(_MACROS), raise_backspace,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           raise_semi,
                              _______, _______, _______,_______,   _______,          _______, KC_INSERT,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash,
                              SYSTEM_LAYER_ACTIVATE, _______, _______,        _______,        _______, _______,  lower_right_of_super,      my_space,   raise_key_4_9,       raise_backspace,  _______,         TO(_BASE)

                              ),

[_ROFI] = LAYOUT_ortho_4x12(
                             _______, _______, _______, _______, _______,    _______, _______, _______, LALT(KC_7), LALT(KC_8), LALT(KC_9), _______,
                             _______, _______, _______, _______, _______,   _______, _______, _______, LALT(KC_4), LALT(KC_5), LALT(KC_6),_______,
                             _______, _______, _______, _______, _______, _______, _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3),_______,
                             _______, _______, _______,    _______, _______, _______, TO(_BASE), RALT(RGUI(KC_SPC)),    _______, _______, _______,_______
                             ),

[_EMACS] = LAYOUT_ortho_4x12(
                              _______, EMACS_DESC_KEY, _______, _______, _______, _______,    _______, EMACS_YANK_IN_SEXP  , EMACS_BACKWARD_UP, _______, _______, _______,
                              _______, _______, _______, _______, EMACS_FINDER_COMMENTARY, _______,   _______, EMACS_SPLIT_WINDOW_RIGHT, EMACS_SPLIT_WINDOW_DOWN, EMACS_SPLIT_WINDOW_UP, EMACS_SPLIT_WINDOW_LEFT,_______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                                ),

[_MOUSE] = LAYOUT_ortho_4x12(
                              TO(_BASE),   _______, _______, KC_MS_UP,       _______, _______, _______,  KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                              _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,  KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                              _______, _______, _______, _______, _______, _______, _______,  LALT(LGUI(KC_N)), KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   TO(_ALL_MODS),
                              _______, _______, _______, _______, _______, _______,  _______,  _______, RGUI(LCTL(KC_M)),          _______, _______, _______



                              ),


// 10
[_ALT] = LAYOUT_ortho_4x12(
                            _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                            ),


// 11
[_SUPER] = LAYOUT_ortho_4x12(
                              _______, WINDOWS_Q,   WINDOWS_W, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, WINDOWS_N,    _______, _______, _______, _______,
                              _______, adhoc_set_hotkey, _______, _______,    _______, _______, _______, _______,    LALT(KC_9), LALT(KC_8), LSFT(KC_TAB), KC_TAB
                              ),




[_HYPER] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                              ),
// 8
[_SHIFTLOCK] = LAYOUT_ortho_4x12(
                                  SHIFTLOCK_LAYER_DEACTIVATE,   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T), _______,    RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P),
                                  ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G), _______,    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),
                                  SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B), _______,   RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,
                                  _______, _______, _______, _______, _______, _______, KC_NO,       _______,    LOWER,  _______, _______, _______
                                  ),


// 12
[_EDITING] = LAYOUT_ortho_4x12(
                                _______, EMACS_DESC_KEY, LCTL(KC_7),     LCTL(KC_E), EMACS_HELM_MARK_RINGS,     EMACS_TRANSPOSE,        RALT(KC_UNDS), EMACS_YANK_IN_SEXP  , EMACS_NEXT_SEXP ,EMACS_PREV_SEXP ,  EMACS_HELM_OCCUR, _______,
                                _______, _______, EMACS_LOCCUR, EMACS_KILL_IN_SEXP, RALT(KC_ENTER), EMACS_COPY_FILE_PATH,               EMACS_SCROLL_UP, RALT(RSFT(KC_H)), editing_j, editing_k, editing_l, EMACS_COMMENT_READER,
                                _______, EMACS_RECENTER_ON_DEFUN, _______, EMACS_WINDOW_CLOSE,    KC_F12, _______,                                      _______, next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  emacs_buffer_stack_down, emacs_buffer_stack_up, TERM_CD_UP_DIR,
                                _______, _______, _______, _______, KC_HYPR,  _______,                                                  _______, all_mods, MO(_EMACS), _______, _______, _______

                                ),
// 9
[_WINMOVE] = LAYOUT_ortho_4x12(
                                _______,   _______, _______, _______, _______, _______,  WINDOW_ALWAYS_ON_TOP, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______,
                                _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______, _______, winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______,
                                _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______,  _______, RGUI(RSFT(KC_N)), winmove_U_monitor, _______, RGUI(RSFT(KC_DOT)),_______,
                                _______, _______, _______, _______, TO(0),          _______,  _______,         winmove_L_monitor,   winmove_D_monitor,   winmove_R_monitor,    _______, _______
                                ),

// 4
[_ALL_MODS] = LAYOUT_ortho_4x12(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, EMACS_FRAME_FULL_SCREEN, _______,    _______, _______, _______,     MO(_MOUSE), _______, _______, _______, _______

                             /* _______, KC_EXECUTE, KC_HELP, KC_MENU, KC_SELECT,KC_CANCEL,   KC_SEPARATOR, _______, KC_CRSEL, KC_EXSEL	, KC_CALCULATOR, QK_MAKE, */
                             /* _______, KC_STOP, KC_AGAIN, KC_UNDO, KC_FIND , KC_PRIOR,   _______, _______, BL_INC, BL_DEC, BL_TOGG, BL_BRTG, */
                             /* KC_SEPARATOR, KC_CUT, KC_COPY, KC_PASTE, _______, _______, _______, _______, MO(_MOUSE), _______, _______, _______, */
                             /* _______, KC_RETURN, KC_CLEAR, KC_CLEAR_AGAIN,   PROGRAMMABLE_BUTTON_1, PROGRAMMABLE_BUTTON_2, _______, _______,     MO(_MOUSE), _______, _______, _______ */

                              ),


// 5
[_SYSTEM] = LAYOUT_ortho_4x12(
                              SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, _______, KC_PSTE, KC_AGIN, DEBUG, EEPROM_RESET,  QK_BOOT,
                               _______, _______,_______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______, _______,
                               _______, _______ , _______, _______, _______, _______,   _______, _______,  KC_AUDIO_MUTE, _______, _______, _______,
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______,  _______, _______, _______, _______,   _______, _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP

                               /* SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET, */
                               /* RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______, */
                               /* KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK, */
                               /* CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
                               ),

// 6
[_WINDOWS] = LAYOUT_ortho_4x12(
                                _______, WINDOWS_Q,   WINDOWS_W,   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T), LGUI(KC_MINUS),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),
                                RALT(RGUI(KC_ESCAPE)), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, TD(DANCE_42),  LGUI(KC_H),     TD(DANCE_43),   windows_k,   windows_l,   RALT(RGUI(KC_N)),
                                TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),    _______, LGUI(KC_MINUS), WINDOWS_N,   LGUI(KC_M),  _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)),
                                _______, _______, _______,         _______,        _______,     LSFT(RCTL(KC_UNDS)),   ALT_TAB , LALT(KC_8),      _______,  ALT_TAB, _______, _______
                                ),

// 7
[_MACROS] = LAYOUT_ortho_4x12(
                               _______,   _______, _______, _______, emacs_r, _______, EMACS_GOTO_GET_FEED, EMACS_COPY_FILE_PATH, EMACS_BACKWARD_UP, EMACS_GOTO_REMOTEID, _______, _______,
                               _______, emacs_a, _______, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, EMACS_GOTO_PARSE_ITEM,  _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     _______,
                               _______, _______, _______, EMACS_YAS_C,     _______, _______, EMACS_GOTO_SYNC_FEED, _______, emacs_m,     _______, _______, TERM_CD_UP_DIR,
                               _______, _______, _______, _______, _______, _______,EMACS_GOTO_ROLLUP ,          EMACS_GOTO_REMOTEID, _______, _______, _______, _______
                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                              ),




  };

#include "../../../common/combos.c"
#include "../../../common/autoshift.c"
