#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _BASE,
  _HYPER,
  _BOTH,
  _MENU,
  _DIAMOND,
  _SYSTEM,
  _WINDOWS,
  _MACROS,
  _SHIFTLOCK,
  _WINMOVE,
  _ALT,
  _SUPER,
  _EDITING,
  _LAYER13,
  _CTRL,
  _MOUSE,
  _COLORS,
  _LAYER17,
  _LAYER18,
  _LAYER19,
  _EMACS_SEL_WINDOW,
  _GAUTH,
  _AUDIO,
  _VOLUME,
  _BRIGHTNESS,
  _ADHOC_SET_HOTKEY,
  _ROFI,
  _EXTENDED,

};

#define test KC_ASTR
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define alt_tab ALT_TAB
#define backspace KC_BSPACE
#define below_b KC_RALT
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_n KC_RALT
#define below_v MT(MOD_RCTL, KC_ESCAPE)
#define emacs_a _______
#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_m EMACS_YAS_MAP_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
#define esc_ctrl MT(MOD_RCTL, KC_ESCAPE)
#define hyper LM(_HYPER, MOD_LCTL) //KC_LCTL // OSL(_WINDOWS)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(RALT(KC_RSFT))
#define key_4_10 OSL(_EDITING)
#define key_4_11 KC_DOWN //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_UP
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))
#define my_cap_h RSFT(KC_H)
#define my_cap_i RSFT(KC_I)
#define my_cap_j RSFT(KC_J)
#define my_cap_k RSFT(KC_K)
#define my_cap_l RSFT(KC_L)
#define my_cap_m RSFT(KC_M)
#define my_cap_o RSFT(KC_O)
#define my_comma TD(DANCE_COMMA) //KC_COMMA //
#define my_forward_slash TD(DANCE_25)
#define my_left_shift KC_LSFT //  LM(_SHIFTLOCK, MOD_LSFT)

#define my_lctl MT(MOD_RCTL, KC_ESCAPE)
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_comma BROWSER_TAB_PREV

#define my_lower_d KC_F7
#define my_lower_f  KC_F8
#define my_lower_h  KC_MINUS
#define my_lower_u KC_PGDOWN
#define my_lower_i KC_PGUP
#define my_lower_j KC_DOWN
#define my_lower_k KC_UP
#define my_lower_l KC_RIGHT
#define my_lower_m TD(DANCE_29)
#define my_lower_n TD(DANCE_69)
#define my_lower_o KC_END
#define my_lower_p TD(WWW_BACK_FORWARD)
#define my_lower_bs KC_DEL
#define my_lower_period BROWSER_TAB_NEXT
#define my_lower_semi esc_ctrl
#define my_lower_slash SHIFTLOCK_LAYER_ACTIVATE
#define lower_LOWER TO(_BASE)
#define lower_right_of_lower _______
#define lower_key_4_11 KC_LEFT
#define lower_key_4_12 KC_RIGHT
#define raise_key_4_9 KC_ENTER // KC_BSPC

#define my_raise RAISE
#define my_raise_top_right KC_DEL // TD(WWW_BACK_FORWARD)
#define my_raise_comma KC_2
#define my_raise_d _______ //kc_bspace
#define my_raise_f RALT(KC_ENTER)
#define my_raise_h KC_BSPACE
#define my_raise_i KC_8
#define my_raise_j KC_4
#define my_raise_k KC_5
#define my_raise_l KC_6
#define my_raise_m KC_1
#define my_raise_n KC_DQUO
#define my_raise_o KC_9
#define my_raise_p KC_0
#define my_raise_period KC_3
#define my_raise_u  KC_7
#define my_raise_y  KC_QUOT
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define raise_semi KC_PLUS

#define my_semicolon TD(DANCE_19)
#define my_singlequote TD(DANCE_20)
#define my_space TD(DANCE_SPACE)

#define my_period KC_DOT
#define my_minus _______
#define my_grave TD(DANCE_0)

#define WINDOWS_Q TD(DANCE_38)

#define windows_k TD(DANCE_43)
#define windows_l TD(DANCE_44)
#define top_left TD(DANCE_MIC)

#define my_a TD(DANCE_A)
#define my_b TD(DANCE_B)
#define my_c TD(DANCE_C)
#define my_d TD(DANCE_D)
#define my_e TD(DANCE_E)
#define my_f TD(DANCE_F)
#define my_g TD(DANCE_G)
#define my_h TD(DANCE_H)
#define my_i TD(DANCE_I)
#define my_j TD(DANCE_J)
#define my_k TD(DANCE_K)
#define my_l TD(DANCE_L)
#define my_m TD(DANCE_M)
#define my_n TD(DANCE_N)
#define my_o TD(DANCE_O)
#define my_p TD(DANCE_P)
#define my_q TD(DANCE_Q)
#define my_r TD(DANCE_R)
#define my_s TD(DANCE_S)
#define my_t TD(DANCE_T)
#define my_u TD(DANCE_U)
#define my_v TD(DANCE_V)
#define my_w TD(DANCE_W)
#define my_x TD(DANCE_X)
#define my_y TD(DANCE_Y)
#define my_z TD(DANCE_Z)

#define right_of_lower  esc_ctrl  // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define super LM(_SUPER, MOD_LGUI) //TD(SUPER_WINDOWS)
/* #define super KC_LGUI */
/* #define alt  KC_LALT */
#define alt LM(_ALT, MOD_LALT)
/* #define super TD(SUPER_WINDOWS) */
#define topright _______
/* #include "user_song_list.h" */
/* #define hyper KC_LCTL */
/* #define key_4_12 KC_LCTL */
/* #define my_left_shift KC_LSPO */
/* #define my_right_shift KC_ENTER */


#include "../../../common/keycodes.c"
#include "../../../common/drop_tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

                                                              [_BASE] = LAYOUT_planck_grid(
                                                                                             TD(DANCE_0),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                                                                                             KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                                                                                             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
                                                                                             RESET, KC_LCTL, KC_LALT, KC_LGUI, _______,   KC_SPC,  KC_SPC,  _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
                                                                                             ),
[_QWERTY] = LAYOUT_planck_grid(
                               TD(DANCE_0),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    RESET, KC_LCTL, KC_LALT, KC_LGUI, _______,   KC_SPC,  KC_SPC,  _______,   KC_LEFT, KC_DOWN, KC_UP,   ALT_TAB
/* ), */

/* [_LOWER] = LAYOUT_planck_grid( */
/*     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY */
/* ), */

/* [_RAISE] = LAYOUT_planck_grid( */
/*     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY */
),


};

/* #include "../../../common/combos.c" */
