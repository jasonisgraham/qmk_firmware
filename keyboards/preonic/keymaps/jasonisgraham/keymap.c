#include "../../../common/drop_keymap.c"
#include "../../../common/encoder.c"
#include "encoder.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

[_BASE] = LAYOUT_wrapper(
                         LAYER_LOCK, KC_F9, KC_NO, OSL(_WINDOWS),   ROFI_DRUN, ROFI_WINDOWS , ROFI_CLIPBOARD, LEFT_OR_HOME, DOWN_OR_END, UP_OR_HOME , RIGHT_OR_END, KC_GRAVE,
                              planck_base),

[_RAISE] = LAYOUT_wrapper(_______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, planck_raise),

[_SHIFTLOCK] = LAYOUT_wrapper(_______, _______, _______, _______, SHIFTLOCK_LAYER_DEACTIVATE, _______,    _______, _______, _______, _______, _______, _______,
                              planck_shiftlock),


[_LOWER] = LAYOUT_wrapper(_______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, planck_lower),



[_ROFI] = LAYOUT_wrapper(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_rofi                             ),

[_EMACS] = LAYOUT_wrapper(
                               KC_F21, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F22, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20,
planck_emacs
                                ),

[_SA] = LAYOUT_wrapper(
                            _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_sa
                            ),


[_MOUSE] = LAYOUT_wrapper(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_mouse),


// 11
[_SUPER] = LAYOUT_wrapper(
                          _______, _______, _______, _______, _______, _______,    _______, LSFT(KC_GRAVE), LSFT(KC_TAB),    KC_TAB, KC_GRAVE, _______,
planck_super                              ),



// 12
[_EDITING] = LAYOUT_wrapper(
                                 KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
planck_editing
                                ),
// 9
[_WINMOVE] = LAYOUT_wrapper(
                                 _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_winmove                                ),

// 4
[_ALL_MODS] = LAYOUT_wrapper(
                                  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_all_mods
                              ),


// 5
[_SYSTEM] = LAYOUT_wrapper(
                           CYCLE_ACTIVE_K74_FN, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                planck_system),

// 6
[_WINDOWS] = LAYOUT_wrapper(
                            _______, _______, KC_NO, ALT_TAB,  _______, _______,    _______,  GUI(LSFT(KC_GRAVE)), GUI(LSFT(KC_TAB)),    GUI(KC_TAB), GUI(KC_GRAVE), _______,
                                 planck_windows
                                ),

// 7
[_MACROS] = LAYOUT_wrapper(
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_macros                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_wrapper(
                                          _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_adhoc_set_key                              ),

[_HYPER] = LAYOUT_wrapper(
                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
planck_hyper                                         ),
  };

