#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */

enum drop_layers {
    _BASE,
    _ALT,
    _NUMLOCK,
    _SHIFTLOCK,
    _LOWER,
    _RAISE,
    _WINDOWS,
    _WINMOVE,
    _WINMOVE_MONITOR,
    _SUPER,
    _EDITING,
    _EMACS,
    _MOUSE,
    _MOTION,
    _SYSTEM,
    _LEADER1,
    _ADHOC_SET_HOTKEY,
    _HYPER,
    _ROFI,
    _ALL_MODS,
    _CODE,
    _SA,
    _EMACS_SELECT,
    _MACROS,
    _LAYER_LOCK,
    _WEB,
    _FILES,
    _SCRATCH
};

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX
#include "../../../common/common_fns.c"

#include "../../../common/key_overrides.c"
#include "../../../common/drop_colors.c"
#include "../../../common/keycodes.c"
#include "../../../common/drop_tapdance.c"

#include "../../../common/combos.c"
#include "../../../common/autoshift.c"
/* #include "../../../common/drop_animations.c" */
/* #include "../../../common/layer_lock.h" */

#if defined(JSG_LHS_MODS)
#include "../../../common/planck_lhs_keymap.h"
#else
#include "../../../common/planck_keymap.h"
#endif

#include "../../../common/matrix_scan_user.c"
#include "../../../common/process_record_user.c"

/* const int row0[10]; */
/* #define row0  { top_left } */
/* const int row0[] = { top_left, top_left,    my_q,    my_w,    my_e,    my_r,   my_t, backspace ,    my_y,           my_u,    my_i,    my_o,     my_p}; */
/* int row0[10] = {}; */

/* #include "../../../common/leader.c" */
