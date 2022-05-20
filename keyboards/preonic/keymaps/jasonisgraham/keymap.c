#include QMK_KEYBOARD_H
#include "muse.h"

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
};

#include "../../../common/keycodes.c"
#include "tapdance.c"

#define test KC_ASTR
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TD_D TD(DANCE_13)
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
#define hyper KC_LCTL // OSL(_WINDOWS)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(RALT(KC_RSFT))
#define key_4_11 KC_BSPACE //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_ENTER
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))
#define my_a TD(DANCE_11)
#define my_b KC_B
#define my_c KC_C
#define my_cap_h RSFT(KC_H)
#define my_cap_i RSFT(KC_I)
#define my_cap_j RSFT(KC_J)
#define my_cap_k RSFT(KC_K)
#define my_cap_l RSFT(KC_L)
#define my_cap_m RSFT(KC_M)
#define my_cap_o RSFT(KC_O)
#define my_comma TD(DANCE_23)
#define my_d KC_D
#define my_e TD(DANCE_3)
#define my_f TD(DANCE_14)
#define my_forward_slash TD(DANCE_25)
#define my_g TD(DANCE_15)
#define my_grave TD(DANCE_0)
#define my_h KC_H
#define my_i TD(DANCE_7)
#define my_j TD(DANCE_16)
#define my_k TD(DANCE_17)
#define my_l TD(DANCE_18)
#define my_lctl MT(MOD_RCTL, KC_ESCAPE)
#define my_left_shift KC_LSFT
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_comma TD(DANCE_29)
#define my_lower_d KC_F7
#define my_lower_f  KC_F8
#define my_lower_i KC_PGDOWN
#define my_lower_j KC_DOWN
#define my_lower_k KC_UP
#define my_lower_l KC_RIGHT
#define my_lower_m TD(DANCE_29)
#define my_lower_n TD(DANCE_69)
#define my_lower_o KC_END
#define my_lower_p TD(DANCE_27)
#define my_lower_period TD(DANCE_30)
#define my_lower_semi esc_ctrl
#define my_lower_slash SHIFTLOCK_LAYER_ACTIVATE
#define my_m TD(DANCE_22)
#define my_minus TD(DANCE_10)
#define my_n TD(DANCE_21)
#define my_o TD(DANCE_8)
#define my_p TD(DANCE_9)
#define my_period TD(DANCE_24)
#define my_q TD(DANCE_1)
#define my_r TD(DANCE_4)
#define my_raise RAISE
#define my_raise_comma KC_2
#define my_raise_h KC_BSPACE
#define my_raise_i KC_8
#define my_raise_j KC_4
#define my_raise_k KC_5
#define my_raise_l KC_6
#define my_raise_m KC_1
#define my_raise_n KC_0
#define my_raise_o KC_9
#define my_raise_p KC_0
#define my_raise_period KC_3
#define my_raise_u  KC_7
#define my_right_shift KC_RSFT
#define my_s TD(DANCE_12)
#define my_semicolon TD(DANCE_19)
#define my_singlequote TD(DANCE_20)
#define my_space KC_SPACE
#define my_space KC_SPACE
#define my_t TD(DANCE_5)
#define my_u TD(DANCE_6)
#define my_v TD(DANCE_74)
#define my_w TD(DANCE_2)
#define my_x KC_X
#define my_y KC_Y
#define my_z KC_Z
#define right_of_lower esc_ctrl ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))
#define super KC_LGUI  // TD(SUPER_WINDOWS)
#define topright TD(DANCE_10)
#include "user_song_list.h"
/* #define hyper KC_LCTL */
/* #define key_4_12 KC_LCTL */
/* #define my_left_shift KC_LSPO */
/* #define my_right_shift KC_ENTER */

#include "keymaps.c"


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


#include "colors.c"

LEADER_EXTERNS();

void leader_matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_C) {
      // Anything you can do in my_a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(TD_D, TD_D) {
      SEND_STRING(SS_LCTL("k") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

#include "../../../common/combos.c"

/* #include QMK_KEYBOARD_H */
/* #include "muse.h" */

/* enum preonic_layers { */
/*   _BASE, */
/*   _LOWER, */
/*   _RAISE, */
/*   _ADJUST, */
/*   _MOUSE, */
/*   _SYSTEM, */
/*   _WINDOWS, */
/*   _MACROS, */
/*   _SHIFTLOCK, */
/*   _WINMOVE, */
/*   _ALT, */
/*   _SUPER, */
/*   _EDITING, */
/*   _LAYER13, */
/*   _VIM_CMDS, */
/*   _LAYER15, */
/*   _COLORS, */
/*   _LAYER17, */
/*   _LAYER18, */
/*   _LAYER19, */
/*   _EMACS_SEL_WINDOW */
/* }; */

/* #define LOWER MO(_LOWER) */
/* #define RAISE MO(_RAISE) */
/* #define TD_D TD(DANCE_13) */
/* #define backspace KC_BSPACE */
/* #define below_b KC_RALT */
/* #define below_m MT(MOD_RCTL, KC_ESCAPE) */
/* #define below_n KC_RALT */
/* #define below_v MT(MOD_RCTL, KC_ESCAPE) */
/* #define esc_ctrl MT(MOD_RCTL, KC_ESCAPE) */
/* #define hyper KC_LCTL */
/* #define key_0_0 KC_LCTL */
/* #define key_0_1 RCTL(RALT(KC_RSFT)) */
/* #define key_4_11 KC_BSPACE //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD */
/* #define key_4_12 KC_ENTER */
/* #define macro_alt_slash SS_RALT(SS_TAP(X_SLASH)) */
/* #define my_a TD(DANCE_11) */
/* #define my_b KC_B */
/* #define my_c KC_C */
/* #define my_cap_h RSFT(KC_H) */
/* #define my_cap_i RSFT(KC_I) */
/* #define my_cap_j RSFT(KC_J) */
/* #define my_cap_k RSFT(KC_K) */
/* #define my_cap_l RSFT(KC_L) */
/* #define my_cap_o RSFT(KC_O) */
/* #define my_cap_m RSFT(KC_M) */
/* #define my_comma TD(DANCE_23) */
/* #define my_d KC_D */
/* #define my_e TD(DANCE_3) */
/* #define my_f TD(DANCE_14) */
/* #define my_forward_slash TD(DANCE_25) */
/* #define my_g TD(DANCE_15) */
/* #define my_grave TD(DANCE_0) */
/* #define my_h KC_H */
/* #define my_i TD(DANCE_7) */
/* #define my_j TD(DANCE_16) */
/* #define my_k TD(DANCE_17) */
/* #define my_l TD(DANCE_18) */
/* #define my_left_shift KC_LSFT */
/* #define my_lower MO(_LOWER) */
/* #define my_lower MO(_LOWER) */
/* #define my_lower_comma TD(DANCE_29) */
/* #define my_lower_d KC_F7 */
/* #define my_lower_f  KC_F8 */
/* #define my_lower_i KC_PGDOWN */
/* #define my_lower_j KC_DOWN */
/* #define my_lower_k KC_UP */
/* #define my_lower_l KC_RIGHT */
/* #define my_lower_m TD(DANCE_29) */
/* #define my_lower_n TD(DANCE_69) */
/* #define my_lower_o KC_END */
/* #define my_m TD(DANCE_22) */
/* #define my_minus TD(DANCE_10) */
/* #define my_n TD(DANCE_21) */
/* #define my_o TD(DANCE_8) */
/* #define my_p TD(DANCE_9) */
/* #define my_period TD(DANCE_24) */
/* #define my_q TD(DANCE_1) */
/* #define my_r TD(DANCE_4) */
/* #define my_raise RAISE */
/* #define my_raise_comma KC_2 */
/* #define my_raise_h KC_BSPACE */
/* #define my_raise_i KC_8 */
/* #define my_raise_j KC_4 */
/* #define my_raise_k KC_5 */
/* #define my_raise_l KC_6 */
/* #define my_raise_m KC_1 */
/* #define my_raise_n KC_0 */
/* #define my_raise_o KC_9 */
/* #define my_raise_p KC_0 */
/* #define my_raise_period KC_3 */
/* #define my_raise_u  KC_7 */
/* #define my_right_shift KC_RSPC */
/* #define my_s TD(DANCE_12) */
/* #define my_semicolon TD(DANCE_19) */
/* #define my_singlequote TD(DANCE_20) */
/* #define my_space KC_SPACE */
/* #define my_space KC_SPACE */
/* #define my_split_left OSL(_WINDOWS) */
/* #define my_split_left_windows ALT_TAB */
/* #define my_t TD(DANCE_5) */
/* #define my_u TD(DANCE_6) */
/* #define my_v KC_V */
/* #define my_w TD(DANCE_2) */
/* #define my_x KC_X */
/* #define my_y KC_Y */
/* #define my_z KC_Z */
/* #define right_of_lower esc_ctrl// MT(MOD_RCTL, KC_ESCAPE) */
/* #define select_slack LGUI(KC_S) */
/* #define show_desktop LALT(LGUI(LCTL(KC_D))) */
/* #define topright my_minus */
/* #include "../../../common/keycodes.c" */
/* #include "tapdance.c" */


/* #include "user_song_list.h" */

/* #define my_lctl MT(MOD_RCTL, KC_ESCAPE) */


/* #include "keymaps.c" */


/* bool muse_mode = false; */
/* uint8_t last_muse_note = 0; */
/* uint16_t muse_counter = 0; */
/* uint8_t muse_offset = 70; */
/* uint16_t muse_tempo = 50; */

/* bool encoder_update_user(uint8_t index, bool clockwise) { */
/*   if (muse_mode) { */
/*     if (IS_LAYER_ON(_RAISE)) { */
/*       if (clockwise) { */
/*         muse_offset++; */
/*       } else { */
/*         muse_offset--; */
/*       } */
/*     } else { */
/*       if (clockwise) { */
/*         muse_tempo+=1; */
/*       } else { */
/*         muse_tempo-=1; */
/*       } */
/*     } */
/*   } else { */
/*     if (clockwise) { */
/*       register_code(KC_PGDN); */
/*       unregister_code(KC_PGDN); */
/*     } else { */
/*       register_code(KC_PGUP); */
/*       unregister_code(KC_PGUP); */
/*     } */
/*   } */
/*     return true; */
/* } */

/* bool dip_switch_update_user(uint8_t index, bool active) { */
/*     switch (index) { */
/*         case 0: */
/*             if (active) { */
/*                 layer_on(_ADJUST); */
/*             } else { */
/*                 layer_off(_ADJUST); */
/*             } */
/*             break; */
/*         case 1: */
/*             if (active) { */
/*                 muse_mode = true; */
/*             } else { */
/*                 muse_mode = false; */
/*             } */
/*     } */
/*     return true; */
/* } */


/* #include "colors.c" */

/* LEADER_EXTERNS(); */

/* void leader_matrix_scan_user(void) { */
/*   LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */

/*     SEQ_ONE_KEY(KC_C) { */
/*       // Anything you can do in my_a macro. */
/*       SEND_STRING("QMK is awesome."); */
/*     } */
/*     SEQ_TWO_KEYS(TD_D, TD_D) { */
/*       SEND_STRING(SS_LCTL("a") SS_LCTL("c")); */
/*     } */
/*     SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
/*       SEND_STRING("https://start.duckduckgo.com\n"); */
/*     } */
/*     SEQ_TWO_KEYS(KC_A, KC_S) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_S); */
/*       unregister_code(KC_S); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*   } */
/* } */


/* #include "../../../common/combos.c" */
