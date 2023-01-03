#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _WINDOWS,
                    _MACROS,
                    _SHIFTLOCK,
                    _WINMOVE,
                    _SUPER,
                    _EDITING,
                    _EMACS,
                    _MOUSE,
                    _SYSTEM,
                    _ALL_MODS,
                    _ADHOC_SET_HOTKEY,
                    _HYPER,
                    _SA,
                    _ROFI,
};

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX

#include "../../../../common/key_overrides.c"
#include "../../../../common/keycodes.c"
#include "../../../../common/drop_tapdance.c"
#include "../../../../common/tapdance_keycodes.c"
#include "../../../../common/combos.c"
#include "../../../../common/autoshift.c"
#include "../../../../common/layer_lock.h"

/* #include "encoder.h" */
/* const int row0[10]; */
/* #define row0  { top_left } */
/* const int row0[] = { top_left, top_left,    my_q,    my_w,    my_e,    my_r,   my_t, backspace ,    my_y,           my_u,    my_i,    my_o,     my_p}; */
/* int row0[10] = {}; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12(
                             top_left,    my_q,    my_w,    my_e,    my_r,   my_t, key_1_7,    my_y,           my_u,    my_i,    my_o,     my_p,
                             esc_ctrl , my_a,   my_s,   my_d,   my_f,   my_g, key_2_7,  my_h,         my_j,   my_k,   my_l,   my_semicolon,
                             my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b, key_3_7,     my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
                             hyper, level3, all_mods,      alt, RAISE,  super, key_4_7,   my_space,           LOWER,          my_right_of_lower,   key_4_11,  key_4_12
                              ),


[_LOWER] = LAYOUT_ortho_4x12(
                              LALT(KC_C),   KC_F1,          KC_F2,          KC_F3,          KC_F4,  TD(DANCE_73),        _______ ,    KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p,
_______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          my_lower_g, lower_backspace,      my_lower_h,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi,
                              _______,   KC_F9,         KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, KC_SCROLL_LOCK,  my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash,
                              SYSTEM_LAYER_ACTIVATE, _______, _______ , alt,   MO(_EDITING), MO(_MOUSE),           lower_right_of_super,         MO(_MOUSE), lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12


                              ),

// 8
[_SHIFTLOCK] = LAYOUT_ortho_4x12(
                                  SHIFTLOCK_LAYER_DEACTIVATE,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T), _______,    LSFT(KC_Y),     LSFT(KC_U),     my_cap_i,     my_cap_o,     my_cap_p,
                                  ESC_THEN_BASE_LAYER,          LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G), _______,    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),
                                  SHIFTLOCK_LAYER_DEACTIVATE,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B), _______,   LSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        my_forward_slash,
                                  _______, _______, _______, _______, MO(_RAISE), _______, KC_NO,       _______,    MO(_LOWER),  _______, _______, _______
                                  ),


[_RAISE] = LAYOUT_ortho_4x12(
                              LSFT(KC_TAB),    _______,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       _______, _______, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                              _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  TD(DANCE_MACROS), raise_backspace,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           raise_semi,
                              SHIFTLOCK_LAYER_ACTIVATE, _______, _______,_______,   _______,          _______, KC_INSERT,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash,
                              SYSTEM_LAYER_ACTIVATE, _______, _______,        _______,        _______, _______,  lower_right_of_super,      my_space,   raise_key_4_9,       raise_backspace,  _______,         TO(_BASE)

                              ),

[_ROFI] = LAYOUT_ortho_4x12(
                             _______, _______, _______, _______, _______,    _______, _______, _______, LALT(KC_7), LALT(KC_8), LALT(KC_9), _______,
                             _______, _______, _______, _______, _______,   _______, _______, _______, LALT(KC_4), LALT(KC_5), LALT(KC_6),_______,
                             _______, _______, _______, _______, _______, _______, _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3),_______,
                             _______, _______, _______,    _______, _______, _______, TO(_BASE), LALT(LGUI(KC_SPC)),    _______, _______, _______,_______
                             ),

[_EMACS] = LAYOUT_ortho_4x12(
                              _______, EMACS_DESC_KEY, _______, _______, _______, _______,    _______, EMACS_YANK_IN_SEXP  , EMACS_BACKWARD_UP, _______, _______, _______,
                              _______, _______, _______, _______, EMACS_FINDER_COMMENTARY, _______,   _______, EMACS_SPLIT_WINDOW_RIGHT, EMACS_SPLIT_WINDOW_DOWN, EMACS_SPLIT_WINDOW_UP, EMACS_SPLIT_WINDOW_LEFT,_______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                                ),

[_SA] = LAYOUT_ortho_4x12(
                           ESC_THEN_BASE_LAYER, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                           ESC_THEN_BASE_LAYER, _______, KC_LEFT, _______, KC_RIGHT, _______,   KC_DELETE, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, WEB_SAVE_FILE_UNDER_CURSOR, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______,    MO(_MOUSE), _______, _______, _______,    _______, _______, _______, _______

                            ),


[_MOUSE] = LAYOUT_ortho_4x12(
                              TO(_BASE),   _______, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______,  KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                              _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,  KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                              _______, _______, _______, _______, _______, _______, _______,  LALT(LGUI(KC_N)), KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   all_mods,
                              _______, _______, _______, _______, _______, _______,  _______,  _______, LGUI(LCTL(KC_M)),          _______, _______, _______



                              ),


// 11
[_SUPER] = LAYOUT_ortho_4x12(
                              _______, _______,   _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    _______, _______,  _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, LALT(KC_7), _______,    _______, _______, _______, _______,
                              _______, adhoc_set_hotkey, _______, _______,    _______, _______, LALT(KC_7), _______,    LALT(KC_9), LALT(KC_8), LSFT(KC_TAB), KC_TAB
                              ),



// 12
[_EDITING] = LAYOUT_ortho_4x12(
                                _______, EMACS_DESC_KEY, LCTL(KC_7),     LCTL(KC_E), EMACS_HELM_MARK_RINGS,     EMACS_TRANSPOSE,        LALT(KC_UNDS), EMACS_YANK_IN_SEXP  , EMACS_NEXT_SEXP ,EMACS_PREV_SEXP ,  EMACS_HELM_OCCUR, _______,
                                _______, _______, EMACS_LOCCUR, EMACS_KILL_IN_SEXP, LALT(KC_ENTER), EMACS_COPY_FILE_PATH,               EMACS_SCROLL_UP, LALT(LSFT(KC_H)), editing_j, editing_k, editing_l, EMACS_COMMENT_READER,
                                _______, EMACS_RECENTER_ON_DEFUN, _______, EMACS_WINDOW_CLOSE,    KC_F12, _______,                                      _______, next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  emacs_buffer_stack_down, emacs_buffer_stack_up, TERM_CD_UP_DIR,
                                _______, _______, _______, _______, KC_HYPR,  _______,                                                  _______, all_mods, MO(_EMACS), _______, _______, _______

                                ),
// 9
[_WINMOVE] = LAYOUT_ortho_4x12(
                                _______,   _______, _______, _______, _______, _______,  WINDOW_ALWAYS_ON_TOP, LGUI(LSFT(KC_Y)),_______, _______, LGUI(LSFT(KC_O)),_______,
                                _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______, _______, winmove_L,   winmove_D, winmove_U ,   winmove_R,   _______,
                                _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______,  _______, LGUI(LSFT(KC_N)), winmove_U_monitor, _______, LGUI(LSFT(KC_DOT)),_______,
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
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, CYCLE_ACTIVE_K74_FN, KC_PSTE, KC_AGIN, QK_DEBUG_TOGGLE, QK_CLEAR_EEPROM, QK_BOOTLOADER,
                               _______, _______,_______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, CYCLE_DROP_ANIMATIONS, DB_TOGG,
                               _______, _______ , _______, _______, _______, _______,   _______, _______,  KC_AUDIO_MUTE, _______, _______, _______,
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______,  _______, _______, _______, _______,   _______, _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP

                               /* SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET, */
                               /* RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______, */
                               /* KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK, */
                               /* CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
                               ),

// 6
[_WINDOWS] = LAYOUT_ortho_4x12(
                                _______, LGUI(KC_Q),   LGUI(KC_W),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T), LGUI(KC_MINUS),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),
                                LALT(LGUI(KC_ESCAPE)), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, TD(DANCE_42),  LGUI(KC_H),     TD(DANCE_43),   windows_k,   windows_l,   LALT(LGUI(KC_N)),
                                TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),    _______, LGUI(KC_MINUS), LGUI(KC_N),   LGUI(KC_M),  _______, LSFT(LGUI(KC_K)), LALT(KC_F4),
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
                              _______, _______, _______, _______, _______, _______,    WINDOW_ALWAYS_ON_TOP, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                              ),




  };

#include "oled.c"

/* bool oled_task_user(void) { */
/*   // Host Keyboard Layer Status */
/*   oled_write_P(PSTR("Layer: "), false); */

/*   switch (get_highest_layer(layer_state)) { */
/*   case _BASE: */
/*     oled_write_P(PSTR("Default\n"), false); */
/*     break; */
/*   case _RAISE: */
/*     oled_write_P(PSTR("FN\n"), false); */
/*     break; */
/*   case _LOWER: */
/*     oled_write_P(PSTR("ADJ\n"), false); */
/*     break; */
/*   default: */
/*     // Or use the write_ln shortcut over adding '\n' to the end of your string */
/*     oled_write_ln_P(PSTR("Undefined"), false); */
/*   } */

/*   // Host Keyboard LED Status */
/*   led_t led_state = host_keyboard_led_state(); */
/*   oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false); */
/*   oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false); */
/*   oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false); */
    
/*   return false; */
/* } */
