#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#include "../../../../common/drop_keymap.c"
#include "colors.c"


#define LAYOUT_wrapper(...) LAYOUT_voyager(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wrapper(planck_base,                             super, my_left_shift, MO(_WINMOVE), alt),


    [_ALT] = LAYOUT_wrapper(planck_alt                           ,_______, _______, _______, _______              ),

    [_RAISE] = LAYOUT_wrapper(planck_raise,_______, raise_left_shift, _______, _______),

    [_SHIFTLOCK] = LAYOUT_wrapper(planck_shiftlock,_______, SHIFTLOCK_LAYER_DEACTIVATE, _______, _______),


    [_LOWER] = LAYOUT_wrapper(planck_lower,_______, lower_left_shift, _______, _______),

    [_FN] = LAYOUT_wrapper(planck_fn,_______, _______, _______, _______),



    [_ROFI] = LAYOUT_wrapper(planck_rofi                             ,_______, _______, _______, _______),

    [_EMACS] = LAYOUT_wrapper(planck_emacs ,_______, emacs_left_shift, _______, _______),

    [_SA] = LAYOUT_wrapper(planck_sa
                           ,_______, _______, _______, _______),


    [_MOUSE] = LAYOUT_wrapper(planck_mouse,_______, _______, _______, _______),


// 11
    [_SUPER] = LAYOUT_wrapper(planck_super                              ,_______, _______, _______, _______),



// 12
    [_EDITING] = LAYOUT_wrapper(planck_editing ,_______,editing_left_shift, _______, _______),
// 9
    [_WINMOVE] = LAYOUT_wrapper(planck_winmove                                ,_______, _______, _______, _______),

// 4
    [_ALL_MODS] = LAYOUT_wrapper(planck_all_mods
                                 ,_______, _______, _______, _______),


// 5
    [_SYSTEM] = LAYOUT_wrapper(planck_system,_______, _______, _______, _______),

// 6
    [_WINDOWS] = LAYOUT_wrapper(planck_windows
                                ,ALT_TAB, _______, _______, _______),


// 7
    [_MACROS] = LAYOUT_wrapper(planck_macros                              ,_______, _______, _______, _______),
    [_ADHOC_SET_HOTKEY] = LAYOUT_wrapper(planck_adhoc_set_key                              ,_______, _______, _______, _______),

    [_HYPER] = LAYOUT_wrapper(planck_hyper                                         ,_______, _______, _______, _______),

    [_LAYER_LOCK] = LAYOUT_wrapper(planck_layer_lock                                         ,_______, _______, _______, _______),

    [_CODE] = LAYOUT_wrapper(planck_code                                         ,_______, _______, _______, _______),
    [_EMACS_SELECT] = LAYOUT_wrapper(planck_emacs_select                                         ,_______, _______, _______, _______),

    [_FILES] = LAYOUT_wrapper(planck_files                                         ,_______, _______, _______, _______),
    [_WEB] = LAYOUT_wrapper(planck_web                                         ,_______, _______, _______, _______),
    [_MOTION] = LAYOUT_wrapper(planck_motion                                         ,_______, _______, _______, _______),
    [_LEADER1] = LAYOUT_wrapper(planck_leader1                                         ,_______, _______, _______, _______)

};
