#include QMK_KEYBOARD_H
#include "muse.h"
/* #include "keymap_us_extended.h" */

enum preonic_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _HYPER,
                    _BOTH,
                    _MENU,
                    _DIAMOND,
                    _SYSTEM,
                    _WINDOWS,
                    _MACROS,
                    _SHIFTLOCK,
                    _WINMOVE,
                    _ALT,
                    _SUPER,
                    _EDITING,
                    _LAYER13,
                    _CTRL,
                    _VIM_CMDS,
                    _MOUSE,
                    _LAYER17,
                    _LAYER18,
                    _LAYER19,
                    _EMACS_SEL_WINDOW,
                    _GAUTH,
                    _AUDIO,
                    _VOLUME,
                    _BRIGHTNESS,
                    _ADHOC_SET_HOTKEY,
                    _ROFI,
                    _EXTENDED,
};

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX

#include "../../../common/keycodes.c"
#include "../../../common/key_overrides.c"
#include "../../../common/drop_tapdance.c"
#include "../../../common/drop_colors.c"
#include "../../../common/encoder.c"
#include "../../../common/layer_lock.h"
#include "encoder.h"

#define test KC_ASTR
/* #define super TD(SUPER_WINDOWS) */
#include "user_song_list.h"
/* #define hyper KC_LCTL */
/* #define key_4_12 KC_LCTL */
/* #define my_left_shift KC_LSPO */
/* #define my_right_shift KC_ENTER */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
                              LAYER_LOCK, KC_1 , KC_2 ,KC_3 ,KC_4 ,KC_5 , KC_6 ,KC_7 ,KC_8 ,KC_9 ,KC_0, KC_MINUS,
                              top_left,    my_q,    my_w,    my_e,    my_r,    my_t,   my_y,           my_u,    my_i,    my_o,     my_p, KC_BSPACE,
                              my_lctl , my_a,   my_s,   my_d,   my_f,   my_g,   my_h,         my_j,   my_k,   my_l,   my_semicolon, KC_QUOT,
                              my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,      my_n,   my_m,   my_comma,   my_period,   my_forward_slash, KC_ENTER,
                              hyper, super_meta_hyper , all_mods , alt, RAISE,  super,    my_space,           LOWER,          my_right_of_lower, right_of_super,   key_4_11,  key_4_12
                              ),


[_LOWER] = LAYOUT_preonic_grid(
                              _______, KC_F1 , KC_F2 ,KC_F3 ,KC_F4 ,KC_F5 , KC_F6 ,KC_F7 ,KC_F8 ,KC_F9 ,KC_F10,  KC_F11,
                              KC_AUDIO_MUTE,   KC_F1,          KC_F2,          KC_F3,          KC_F4,          TD(DANCE_73),    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p,  TD(WWW_BACK_FORWARD),
                              _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          _______,       KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi, _______,
                              _______,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,   my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash, _______,
                              _______, _______, _______ , _______, MO(_MOUSE),  _______ ,                    _______, lower_LOWER,          lower_right_of_lower, _______, lower_key_4_11, lower_key_4_12


                              ),

[_RAISE] = LAYOUT_preonic_grid(
                              _______, KC_F1 , KC_F2 ,KC_F3 ,KC_F4 ,KC_F5 , KC_F6 ,KC_F7 ,KC_F8 ,KC_F9 ,KC_F10, KC_F11,
                              LALT(KC_D),    _______,          EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,      _______,            my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, KC_DEL,
                              _______, _______, _______,  my_raise_d, my_raise_f,  OSL(_MACROS),        my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           raise_semi,  KC_INSERT,
                              _______, _______, _______,_______,   _______,          FISH_ACCEPT_SEND,      my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           KC_QUES, _______,
                              _______, _______, _______,        _______,        _______, _______,         KC_UNDS,   raise_key_4_9,       KC_0, MO(_ROFI) , _______,         TO(_BASE)

                              ),

[_HYPER] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
),

// 4
[_BOTH] = LAYOUT_preonic_grid(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______,     MO(_MOUSE), _______, _______, _______, _______

                             /* _______, KC_EXECUTE, KC_HELP, KC_MENU, KC_SELECT,KC_CANCEL,   KC_SEPARATOR, _______, KC_CRSEL, KC_EXSEL	, KC_CALCULATOR, QK_MAKE, */
                             /* _______, KC_STOP, KC_AGAIN, KC_UNDO, KC_FIND , KC_PRIOR,   _______, _______, BL_INC, BL_DEC, BL_TOGG, BL_BRTG, */
                             /* KC_SEPARATOR, KC_CUT, KC_COPY, KC_PASTE, _______, _______, _______, _______, MO(_MOUSE), _______, _______, _______, */
                             /* _______, KC_RETURN, KC_CLEAR, KC_CLEAR_AGAIN,   PROGRAMMABLE_BUTTON_1, PROGRAMMABLE_BUTTON_2, _______, _______,     MO(_MOUSE), _______, _______, _______ */

                              ),


// 5
[_SYSTEM] = LAYOUT_preonic_grid(
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, _______, KC_PSTE, KC_AGIN, DEBUG, RESET, RESET,
                               SYSTEM_LAYER_DEACTIVATE, MO(_AUDIO),_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               KC_ASTG, _______ , _______, _______, _______, MO(_BRIGHTNESS),   _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,  SYSTEM_LAYER_DEACTIVATE, _______,  _______,   SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______
                               ),

// 6
[_WINDOWS] = LAYOUT_preonic_grid(
                                 ALT_TAB , _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,  LGUI(KC_MINUS),
                                 _______, WINDOWS_Q,   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), _______,
                                 RGUI(KC_ESCAPE), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______,  LGUI(KC_H),     TD(DANCE_43),   windows_k,   windows_l,   _______,  TD(DANCE_42),
                                 TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),    _______,  TD(DANCE_46),   LGUI(KC_M),  _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)), LGUI(KC_MINUS),
                                 _______, _______, _______,         _______,        _______,     _______,   LALT(KC_8),      _______,  ALT_TAB ,  ALT_TAB, _______, _______
                                ),

// 7
[_MACROS] = LAYOUT_preonic_grid(
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______,   EMACS_RE_FIND, _______, _______, emacs_r, _______,  _______, EMACS_BACKWARD_UP, _______, EMACS_ANON_FN, _______, EMACS_GOTO_PARSE_ITEM,
                                _______, emacs_a, _______, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED,   _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     EMACS_COMMENT_READER, EMACS_GOTO_GET_FEED,
                                _______, _______, _______, EMACS_YAS_C,     _______, _______,  _______, emacs_m,     _______, _______, TERM_CD_UP_DIR,EMACS_GOTO_SYNC_FEED,
                               _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
                              ),

// 8
[_SHIFTLOCK] = LAYOUT_preonic_grid(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   _______,   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P), _______,
                                   ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),  _______,
                                   SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),   RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,  _______,
                                   _______, _______, _______, _______, _______, _______,  _______,       _______,    LOWER,  _______, _______, _______
                                  ),

// 9
[_WINMOVE] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______,   _______, _______, _______, _______, _______,  RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______,  _______,
                                 _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, TD(DANCE_58),   RGUI(RSFT(KC_J)),TD(DANCE_59),   TD(DANCE_60),   _______, _______,
                                 _______, _______, _______, KC_F11, _______, _______,  RGUI(RSFT(KC_N)), TD(DANCE_47), _______, RGUI(RSFT(KC_DOT)),_______, _______,
                                 _______, _______, _______, _______, TO(0),          _______,          TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),    _______,  _______, _______
                                ),

// 10
[_ALT] = LAYOUT_preonic_grid(
                             _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                            ),


// 11
[_SUPER] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                              ),
[_ROFI] = LAYOUT_preonic_grid(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______,    _______,  _______, LALT(KC_7), LALT(KC_8), LALT(KC_9), _______,_______,
                              _______, _______, _______, _______, _______,   _______,  _______, LALT(KC_4), LALT(KC_5), LALT(KC_6),_______,_______,
                               _______, _______, _______, _______, _______, _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3),_______,_______,
                              _______, _______, _______,    _______, _______,  TO(_BASE), RALT(RGUI(KC_SPC)),    _______, _______, _______, _______,_______
                             ),

// 12
[_EDITING] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, LCTL(KC_7),     LCTL(KC_E), EMACS_BUFFER_REVERT,     _______, EMACS_COPY_FILE_PATH, scroll_next,     scroll_prev, EMACS_OTHER_WINDOW, EMACS_FASD, _______,
                                 _______,  _______,EMACS_LOCCUR, _______, RALT(KC_ENTER), LCTL(KC_G), RALT(RSFT(KC_H)), RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)), EMACS_COMMENT_READER, _______,
                                 _______, _______, _______, EMACS_WINDOW_CLOSE,    KC_F12, _______,  next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  emacs_buffer_stack_down, emacs_buffer_stack_up, TERM_CD_UP_DIR, _______,
                                 _______, _______, _______, _______, KC_HYPR,  _______,  _______,          KC_LCTL, _______, _______,  _______, _______

                                ),

[_MENU] = LAYOUT_preonic_grid(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                ),


[_CTRL] = LAYOUT_preonic_grid(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                 ),

[_MOUSE] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                               TO(_BASE),   _______, _______, KC_MS_UP,       _______, _______,   KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,_______,
                               _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    TO(_GAUTH),  KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
                               SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______,   LALT(LGUI(KC_N)), KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   TO(_BOTH),_______,
                               _______, _______, _______, _______, MO(_EXTENDED), _______,   _______, RGUI(LCTL(KC_M)),          _______, _______,  _______, _______

                                ),



[_GAUTH] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 TO(_BASE), _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                 ),

[_AUDIO] = LAYOUT_preonic_grid(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, _______,
                               _______, _______, _______, _______, _______, _______,   KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______, _______,
                               _______, _______, _______, _______, _______, _______, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,  _______,_______,_______,  _______,
                               _______, _______, _______, _______,    _______, _______, KC_MEDIA_PLAY_PAUSE,    _______, _______, _______,    _______, _______
                              ),
[_BRIGHTNESS] = LAYOUT_preonic_grid(
                                    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______, _______, _______, _______,  _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP, _______,   _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                   ),

[_ADHOC_SET_HOTKEY] = LAYOUT_preonic_grid(
                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                          _______, LCTL(RALT(RGUI(KC_Y))), LCTL(RALT(RGUI(KC_W))), _______, LCTL(RALT(RGUI(KC_R))), _______,  LCTL(RALT(RGUI(KC_Y))),_______, _______, _______, _______, _______,
                                          _______, _______, _______, _______, _______, LCTL(RALT(RGUI(KC_G))),  _______, LCTL(RALT(RGUI(KC_J))), LCTL(RALT(RGUI(KC_K))), LCTL(RALT(RGUI(KC_L))), _______, _______,
                                         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______, _______,    _______, _______, LCTL(RALT(RGUI(KC_N))),    _______, _______, _______,  _______, _______
                                         ),
[_DIAMOND] = LAYOUT_preonic_grid(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                              ),




  };


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


#include "../../../common/combos.c"
#include "../../../common/autoshift.c"
