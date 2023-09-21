#include QMK_KEYBOARD_H
/* #include "muse.h" */
/* #include "keymap_us_extended.h" */

/* #define UNICODE_ENABLE */
#include "/home/jason/Projects/qmk_firmware/keyboards/common/planck_keymap.h"

enum drop_layers {
    _BASE,
    _FUNCTION,
    _RAISE,
    _ALT,
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
    _LEADER1,
    _NUMPAD,
};

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX
#include "../../../common/keycodes.c"
#include "../../../common/common_fns.c"

#include "../../../common/key_overrides.c"
#include "../../../common/drop_colors.c"
#include "../../../common/drop_tapdance.c"

#include "../../../common/combos.c"
/* #include "../../../common/autoshift.c" */

#include "../../../common/matrix_scan_user.c"
/* #include "../../../common/process_record_user.c" */

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW( KC_VOLU, KC_VOLD) },
    [_FUNCTION] = { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_RAISE] = { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_ALT] = { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_SHIFTLOCK]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_LOWER]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_ROFI]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_EMACS]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_CODE]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_EMACS_SELECT]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_SA]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_MOUSE]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_SUPER]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_EDITING]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_WINMOVE]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_SYSTEM]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_WINDOWS]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_MACROS]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_ADHOC_SET_HOTKEY]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_HYPER]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_LAYER_LOCK]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_FILES]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_WEB]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_MOTION]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_FN]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_ALL_MODS]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_LEADER1]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },
    [_NUMPAD]= { ENCODER_CCW_CW(KC_PGDOWN, KC_PGUP) },

};

#define preonic_all_transparent _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)
    [_BASE] = LAYOUT_wrapper(
                             KC_MUTE, KC_1, KC_2, KC_3,   KC_4, KC_5, KC_ESC, KC_6, KC_7, KC_8, KC_9, KC_0,
                             KC_TAB,    my_q,    my_w,    my_e,    my_r,   my_t, super,    my_y,           my_u,    my_i,    my_o,     my_p, \
                             esc_ctrl , my_a,   my_s,   my_d,   my_f,   my_g, mod_r2,  my_h,         my_j,   my_k,   my_l,   my_semicolon, \
                             left_of_z,        my_z,           my_x,           my_c,           my_v,           my_b, mod_r3,     my_n,   my_m,   my_comma,   my_dot,   my_forward_slash, \
                             KC_LALT, level3,   KC_LGUI,         MO(_RAISE), MO(_FUNCTION),  KC_SPACE, mod_r4,  KC_SPACE,           LOWER,          my_right_of_lower,   key_left,  key_right
                             ),


    [_FUNCTION] = LAYOUT_wrapper(KC_GRAVE, KC_6, KC_7,   KC_8, KC_9,  KC_0,_______,_______,_______,_______,_______,_______, \
                                 KC_GRAVE, KC_F1, KC_F2,   KC_F3, KC_F4, KC_MINUS,   _______, _______, _______, _______, _______, _______, \
                                 KC_ENTER,  KC_F5,    KC_F6,    KC_F7,    KC_F8, KC_EQUAL,   _______, _______, _______, _______, _______, _______, \
                                 _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_TILDE,   _______, _______, _______, _______, _______, _______, \
                                 MO(_SYSTEM),   _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______, _______),

    [_RAISE] = LAYOUT_wrapper(_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
                              KC_K,    my_q,        KC_PGDOWN, KC_UP,    KC_PGUP,   my_t, mod_r1,    my_y,           my_u,    my_i,    my_o,     my_p, \
                              KC_L, my_a,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   my_g, mod_r2,  my_h,         my_j,   my_k,   my_l,   my_semicolon, \
                              KC_M, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______),

    [_ALT] = LAYOUT_wrapper(preonic_all_transparent),
    [_SHIFTLOCK] = LAYOUT_wrapper(_______,SHIFTLOCK_LAYER_DEACTIVATE, _______,_______,_______,_______,_______,_______, _______,_______,_______,_______,planck_shiftlock),
    [_LOWER] = LAYOUT_wrapper(_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,planck_lower),
    [_ROFI]= LAYOUT_wrapper(preonic_all_transparent),
    [_EMACS]= LAYOUT_wrapper(preonic_all_transparent),
    [_CODE]= LAYOUT_wrapper(preonic_all_transparent),
    [_EMACS_SELECT]= LAYOUT_wrapper(preonic_all_transparent),
    [_SA]= LAYOUT_wrapper(preonic_all_transparent),
    [_MOUSE] = LAYOUT_wrapper(_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
                              ,planck_mouse),
    [_SUPER]= LAYOUT_wrapper(preonic_all_transparent),
    [_EDITING]= LAYOUT_wrapper(preonic_all_transparent),
    [_WINMOVE]= LAYOUT_wrapper(preonic_all_transparent),
    [_SYSTEM] = LAYOUT_wrapper(_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,planck_system),

    [_WINDOWS]= LAYOUT_wrapper(preonic_all_transparent),
    [_MACROS]= LAYOUT_wrapper(preonic_all_transparent),
    [_ADHOC_SET_HOTKEY]= LAYOUT_wrapper(preonic_all_transparent),
    [_HYPER]= LAYOUT_wrapper(preonic_all_transparent),
    [_LAYER_LOCK]= LAYOUT_wrapper(preonic_all_transparent),
    [_FILES]= LAYOUT_wrapper(preonic_all_transparent),
    [_WEB]= LAYOUT_wrapper(preonic_all_transparent),
    [_MOTION]= LAYOUT_wrapper(preonic_all_transparent),
    [_FN]= LAYOUT_wrapper(preonic_all_transparent),
    [_ALL_MODS]= LAYOUT_wrapper(preonic_all_transparent),
    [_LEADER1]= LAYOUT_wrapper(preonic_all_transparent),
    [_NUMPAD]= LAYOUT_wrapper(preonic_all_transparent)

};
