#include "../../../common/drop_keymap.c"
#include "../../../common/encoder.c"
#include "encoder.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

[_BASE] = LAYOUT_wrapper(
                         preonic_00, preonic_01, preonic_02, preonic_03,   preonic_04, preonic_05, preonic_06, LEFT_OR_HOME, DOWN_OR_END, UP_OR_HOME , preonic_011, preonic_012,
                              planck_base),


[_RAISE] = LAYOUT_wrapper(KC_AUDIO_MUTE, KC_1, KC_2, KC_3, KC_4, KC_5,   TO_BASE, KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    planck_raise),

[_SHIFTLOCK] = LAYOUT_wrapper(_______, _______, _______, _______, SHIFTLOCK_LAYER_DEACTIVATE, _______,    _______, _______, _______, _______, _______, _______,
                              planck_shiftlock),


[_LOWER] = LAYOUT_wrapper(KC_AUDIO_MUTE, KC_1, KC_2, KC_3, KC_4, KC_5,   TO_BASE, KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   planck_lower),



[_ROFI] = LAYOUT_wrapper(
                         _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_rofi                             ),

[_EMACS] = LAYOUT_wrapper(
                               KC_F21, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, TO_BASE, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20,
planck_emacs
                                ),

[_SA] = LAYOUT_wrapper(
                            _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_sa
                            ),


[_MOUSE] = LAYOUT_wrapper(
                               _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_mouse),


// 11
[_SUPER] = LAYOUT_wrapper(_______, _______, ALT_TAB, OSL(_ROFI), _______, _______,    TO_BASE, LSFT(KC_GRAVE), LSFT(KC_TAB),    KC_TAB, KC_GRAVE, _______,
planck_super                              ),



// 12
[_EDITING] = LAYOUT_wrapper(_______, _______, KC_LBRC, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_editing
                                ),
// 9
[_WINMOVE] = LAYOUT_wrapper(
                                 _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_winmove                                ),

// 4
[_ALL_MODS] = LAYOUT_wrapper(
                                  _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_all_mods
                              ),


// 5
[_SYSTEM] = LAYOUT_wrapper(
                           CYCLE_ACTIVE_APL_LEVEL3_FN, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
                                planck_system),

// 6
[_WINDOWS] = LAYOUT_wrapper(
                            _______, _______, ALT_TAB, _______,  _______, _______,    TO_BASE,  GUI(LSFT(KC_GRAVE)), GUI(LSFT(KC_TAB)),    GUI(KC_TAB), GUI(KC_GRAVE), _______,
                                 planck_windows
                                ),

// 7
[_MACROS] = LAYOUT_wrapper(
                           _______, _______, _______, _______, _______, _______,    TO_BASE, SELECT_TO_LINE_HOME, SELECT_TO_DOC_END, SELECT_TO_DOC_HOME, SELECT_TO_LINE_END, _______,
planck_macros                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_wrapper(
                                     _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_adhoc_set_key                              ),

[_HYPER] = LAYOUT_wrapper(
                          _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
planck_hyper                                         ),
[_LAYER_LOCK] = LAYOUT_wrapper(
                          _______, _______, _______, _______, _______, _______,    TO_BASE, _______, _______, _______, _______, _______,
                          planck_layer_lock                                         ),

  };

