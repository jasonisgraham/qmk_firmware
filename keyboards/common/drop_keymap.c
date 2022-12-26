#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */

enum preonic_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _WINDOWS,
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
                    _MACROS,
                    _LAYER_LOCK,
};

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX

#include "../../../common/key_overrides.c"
#include "../../../common/drop_colors.c"
#include "../../../common/keycodes.c"
#include "../../../common/drop_tapdance.c"
#include "../../../common/tapdance_keycodes.c"

#include "../../../common/combos.c"
#include "../../../common/autoshift.c"
/* #include "../../../common/drop_animations.c" */
/* #include "../../../common/layer_lock.h" */

#include "../../../common/planck_keymap.h"
/* const int row0[10]; */
/* #define row0  { top_left } */
/* const int row0[] = { top_left, top_left,    my_q,    my_w,    my_e,    my_r,   my_t, backspace ,    my_y,           my_u,    my_i,    my_o,     my_p}; */
/* int row0[10] = {}; */
