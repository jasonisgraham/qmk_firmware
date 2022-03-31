#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif



enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _ADJUST,
                    _MOUSE,
                    _SYSTEM,
                    _WINDOWS,
                    _MACROS,
                    _SHIFTLOCK,
                    _WINMOVE,
                    _ALT,
                    _SUPER,
                    _EDITING,
                    _LAYER13,
                    _VIM_CMDS,
                    _LAYER15,
                    _LAYER16,
                    _LAYER17,
                    _LAYER18,
                    _LAYER19,
                    _EMACS_SEL_WINDOW
};


#include "tapdance.c"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

/* enum planck_keycodes { */

/* } */

#include "../../../common/keycodes.c"

#define key_4_11 CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_ENTER


#define esc_ctrl MT(MOD_RCTL, KC_ESCAPE)
#define my_grave TD(DANCE_0)
#define my_0 KC_0
#define my_1 KC_1
#define my_2 KC_2
#define my_3 KC_3
#define my_4 KC_4
#define my_5 KC_5
#define my_6 KC_6
#define my_7 KC_7
#define my_8 KC_8
#define my_9 KC_9

#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
#define emacs_a _______
#define emacs_m EMACS_YAS_MAP_ANON

#define my_cap_l RSFT(KC_L)
#define my_cap_k RSFT(KC_K)
#define my_cap_i RSFT(KC_I)
#define my_cap_o RSFT(KC_O)
#define my_cap_j RSFT(KC_J)
#define my_cap_h RSFT(KC_H)
#define my_cap_m RSFT(KC_M)

#define my_raise_j KC_4
#define my_raise_i KC_8
#define my_raise_k KC_5
#define my_raise_o KC_9
#define my_raise_m KC_1
#define my_raise_u  KC_7
#define my_raise_h KC_BSPACE
#define my_raise_n KC_0
#define my_raise_p KC_0


#define my_a TD(DANCE_11)
#define my_b KC_B
#define my_c KC_C
#define my_comma TD(DANCE_23)
/* #define my_comma TD(T_COMMA_H_LTHAN_TH_AT) */
/* #define my_d KC_D */
#define my_d TD(DANCE_13)
/* #define my_e KC_E */
#define my_e TD(DANCE_3)
/* #define my_f KC_F */
#define my_f TD(DANCE_14)
#define my_forward_slash KC_SLASH // TD(DANCE_25)
#define my_g TD(DANCE_15)
#define my_h KC_H
/* #define my_h KC_H */
#define my_i TD(DANCE_7)
/* #define my_i TD(T_I_TH_ASTR) */
#define my_j TD(DANCE_16)

#define my_lower_a KC_F5
#define my_lower_r KC_F4
#define my_lower_g KC_SCROLLLOCK
#define my_lower_comma TD(DANCE_29)
#define my_lower_l KC_RIGHT
#define my_lower_j KC_DOWN
#define my_lower_i KC_PGDOWN
#define my_lower_k KC_UP
#define my_lower_o KC_END
#define my_lower_n TD(DANCE_69)

#define my_lower_m TD(DANCE_29)
#define my_lower_k KC_UP

#define my_raise RAISE
#define my_raise_j KC_4
#define my_raise_i KC_8
#define my_raise_k KC_5
#define my_raise_o KC_9
#define my_raise_m KC_1
#define my_raise_u  KC_7
#define my_raise_h KC_BSPACE
#define my_raise_n KC_0



#define my_raise_comma KC_2
#define my_raise_period KC_3
#define my_raise_l KC_6
/* kmdd */

/* #define my_j TD(T_J_TH_DLR) */
#define my_k TD(DANCE_17)
/* #define my_k TD(T_K_TH_AMP) */
#define my_l TD(DANCE_18)
/* #define my_l TD(T_L_TH_CIRC) */
/* #define my_left_shift KC_LSPO */
#define my_left_shift KC_LSFT
#define my_lower MO(_LOWER)
#define my_m TD(DANCE_22)
/* #define my_m TD(T_M_TH_EXLAM) */
/* #define my_n KC_N */
#define my_n TD(DANCE_21)
#define my_o TD(DANCE_8)
/* #define my_o TD(T_O_TH_LPRN) */
#define my_p TD(DANCE_9)
/* #define my_p TD(T_P_TH_RPRN) */
#define my_period TD(DANCE_24)
/* #define my_period TD(T_PERIOD_H_GTHAN_TH_HASH) */
#define my_q TD(DANCE_1)
#define my_r TD(DANCE_4)
#define my_minus KC_MINUS // TD(DANCE_10)
#define backspace KC_BSPACE
#define my_backspace backspace
/* #define topright my_minus */
#define topright backspace

#define my_split_left OSL(_WINDOWS)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))

#define right_of_lower esc_ctrl
/* #define my_right_shift KC_RSPC */
#define my_right_shift KC_RSFT
/* #define my_s KC_S */
#define my_s TD(DANCE_12)
#define my_semicolon KC_SCOLON //TD(DANCE_19)
/* #define my_semicolon TD(T_SEMI_H_COLON_DT_LSBR_TH_LCBR) */
#define my_singlequote  KC_QUOTE //TD(DANCE_20)
/* #define my_singlequote TD(T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR) */
/* #define my_space KC_SPACE */
#define my_t TD(DANCE_5)
#define my_u TD(DANCE_6)
/* #define my_u TD(T_U_TH_AMPR) */
/* #define my_w KC_W */
#define my_w TD(DANCE_2)
#define my_v KC_V
#define my_x KC_X
#define my_y KC_Y
#define my_z KC_Z
/* #define my_space LT(6,KC_SPACE) */
#define my_space KC_SPACE
#define my_lower_d KC_F7
#define my_lower_f KC_F8

/* #include "../../../common/keymaps.c" */
#include "keymaps.c"
#include "colors.c"




uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#include "../../../common/combos.c"
