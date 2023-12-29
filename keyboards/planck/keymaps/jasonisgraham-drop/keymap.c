#include "../../../common/drop_keymap.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

    [_BASE] = LAYOUT_wrapper(planck_base),
    [_ALT] = LAYOUT_wrapper(planck_alt                                         ),

    [_RAISE] = LAYOUT_wrapper(planck_raise),

    [_SHIFTLOCK] = LAYOUT_wrapper(planck_shiftlock),


    [_LOWER] = LAYOUT_wrapper(planck_lower),
[_FN] = LAYOUT_wrapper(planck_fn),



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

[_LAYER_LOCK] = LAYOUT_wrapper(planck_layer_lock                                         ),

[_CODE] = LAYOUT_wrapper(planck_code                                         ),
[_EMACS_SELECT] = LAYOUT_wrapper(planck_emacs_select                                         ),

[_FILES] = LAYOUT_wrapper(planck_files                                         ),
[_WEB] = LAYOUT_wrapper(planck_web                                         ),
[_MOTION] = LAYOUT_wrapper(planck_motion                                         ),
[_LEADER1] = LAYOUT_wrapper(planck_leader1                                         )

  };
