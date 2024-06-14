#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */

enum drop_layers {
    _BASE,
    _ALT,
    _RAISE,
    _SHIFTLOCK,
    _LOWER,
    _ROFI,
    _EMACS,
    _CODE,
    _EMACS_SELECT,
    _SA,
    _MOUSE,
    _SUPER,
    _EDITING,
    _WINMOVE,
    _SYSTEM,
    _WINDOWS,
    _MACROS,
    _ADHOC_SET_HOTKEY,
    _HYPER,
    _LAYER_LOCK,
    _FILES,
    _WEB,
    _MOTION,
    _FN,
    _ALL_MODS,
    _R4,
    _LEADER1,
};

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX
#include "../../../common/keycodes.c"
#include "../../../common/common_fns.c"

#include "../../../common/key_overrides.c"
#include "../../../common/drop_colors.c"
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

#include "../../../common/leader.c"
