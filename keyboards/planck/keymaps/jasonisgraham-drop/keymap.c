#include "../../../common/drop_keymap.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

[_BASE] = LAYOUT_wrapper(planck_base),

[_RAISE] = LAYOUT_wrapper(planck_raise),

[_SHIFTLOCK] = LAYOUT_wrapper(planck_shiftlock),

[_RAISE] = LAYOUT_planck_grid(
                              LSFT(KC_TAB),    _______,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       _______, _______, my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                              KC_PLUS, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  OSL(_MACROS), raise_backspace,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,       raise_semi,
                              SHIFTLOCK_LAYER_ACTIVATE, _______, _______,_______,   _______,          _______, KC_INSERT,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash,
                              MO(_SYSTEM), _______, _______,        _______,        _______, _______,  lower_right_of_super,      my_space,   raise_key_4_9,       raise_backspace,  _______,         TO(_BASE)
                              ),

// 8
[_SHIFTLOCK] = LAYOUT_planck_grid(
                                  SHIFTLOCK_LAYER_DEACTIVATE,   LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T), _______,    LSFT(KC_Y),     LSFT(KC_U),     my_cap_i,     my_cap_o,     my_cap_p,
                                  ESC_THEN_BASE_LAYER,          LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G), _______,    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),
                                  SHIFTLOCK_LAYER_DEACTIVATE,          LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B), _______,   LSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        my_forward_slash,
                                  _______, _______, _______, _______, RAISE, _______, KC_NO,       _______,    LOWER,  _______, _______, _______
                                  ),


[_LOWER] = LAYOUT_wrapper(planck_lower),



[_ROFI] = LAYOUT_wrapper(planck_rofi                             ),

[_EMACS] = LAYOUT_wrapper(
planck_emacs
                                ),

[_SA] = LAYOUT_wrapper(
planck_sa
                            ),


[_MOUSE] = LAYOUT_wrapper(
planck_mouse),


// 11
[_SUPER] = LAYOUT_wrapper(
planck_super                              ),



// 12
[_EDITING] = LAYOUT_wrapper(
planck_editing
                                ),
// 9
[_WINMOVE] = LAYOUT_wrapper(
planck_winmove                                ),

// 4
[_ALL_MODS] = LAYOUT_wrapper(
planck_all_mods
                              ),


// 5
[_SYSTEM] = LAYOUT_wrapper(planck_system),

// 6
[_WINDOWS] = LAYOUT_wrapper(planck_windows
                                ),

// 7
[_MACROS] = LAYOUT_wrapper(
planck_macros                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_wrapper(
planck_adhoc_set_key                              ),

[_HYPER] = LAYOUT_wrapper(
planck_hyper                                         ),
  };
