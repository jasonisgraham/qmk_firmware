#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _HYPER,
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
#include "../../../common/drop_tapdance.c"
#include "../../../common/drop_colors.c"

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
#define hyper LM(_HYPER, MOD_LCTL) //KC_LCTL // OSL(_WINDOWS)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(RALT(KC_RSFT))
#define key_4_11 KC_BSPACE //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_ENTER
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))
#define my_cap_h RSFT(KC_H)
#define my_cap_i RSFT(KC_I)
#define my_cap_j RSFT(KC_J)
#define my_cap_k RSFT(KC_K)
#define my_cap_l RSFT(KC_L)
#define my_cap_m RSFT(KC_M)
#define my_cap_o RSFT(KC_O)
#define my_comma KC_COMMA // TD(DANCE_23)
#define my_forward_slash TD(DANCE_25)
#define my_left_shift KC_LSFT //  LM(_SHIFTLOCK, MOD_LSFT)

#define my_lctl MT(MOD_RCTL, KC_ESCAPE)
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
#define lower_LOWER TO(_BASE)
#define lower_right_of_lower _______
#define lower_key_4_11 _______
#define lower_key_4_12 _______
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
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define raise_semi KC_MINUS

#define my_semicolon TD(DANCE_19)
#define my_singlequote TD(DANCE_20)
#define my_space KC_SPACE

#define my_period KC_DOT
#define my_minus _______
#define my_grave TD(DANCE_0)

#define WINDOWS_Q TD(DANCE_38)

#define my_a TD(DANCE_A)
#define preonic_a TD(PREONIC_A)
#define preonic_z TD(PREONIC_Z)
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

#define right_of_lower esc_ctrl  // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define super LM(_SUPER, MOD_LGUI) //TD(SUPER_WINDOWS)
/* #define super KC_LGUI */
/* #define alt  KC_LALT */
#define alt LM(_ALT, MOD_LALT)
/* #define super TD(SUPER_WINDOWS) */
#define topright _______
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

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    return true;
  case KC_LCBR:
    return true;
  default:
    return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    register_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;

  case KC_LCBR:
    register_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    register_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_EXLM:
    register_code16((!shifted) ? KC_EXLM : KC_1 );
    break;

  case KC_AT:
    register_code16((!shifted) ? KC_AT : KC_2 );
    break;

  case KC_HASH:
    register_code16((!shifted) ? KC_HASH : KC_3 );
    break;

  case KC_DLR:
    register_code16((!shifted) ? KC_DLR : KC_4 );
    break;

  case KC_PERC:
    register_code16((!shifted) ? KC_PERC : KC_5 );
    break;

  case KC_CIRC:
    register_code16((!shifted) ? KC_CIRC : KC_6 );
    break;

  case KC_AMPR:
    register_code16((!shifted) ? KC_AMPR : KC_7 );
    break;

  case KC_ASTR:
    register_code16((!shifted) ? KC_ASTR : KC_8 );
    break;

  case KC_RPRN:
    register_code16((!shifted) ? KC_RPRN : KC_0 );
    break;


  case KC_TAB:
    register_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;

  default:
    if (shifted) {
      add_weak_mods(MOD_BIT(KC_LSFT));
    }
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;
  case KC_LCBR:
    unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    unregister_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;

  case KC_EXLM:
    unregister_code16((!shifted) ? KC_EXLM : KC_1 );
    break;

  case KC_AT:
    unregister_code16((!shifted) ? KC_AT : KC_4 );
    break;

  case KC_HASH:
    unregister_code16((!shifted) ? KC_HASH : KC_3 );
    break;

  case KC_DLR:
    unregister_code16((!shifted) ? KC_DLR : KC_4 );
    break;

  case KC_PERC:
    unregister_code16((!shifted) ? KC_PERC : KC_5 );
    break;

  case KC_CIRC:
    unregister_code16((!shifted) ? KC_CIRC : KC_6 );
    break;

  case KC_AMPR:
    unregister_code16((!shifted) ? KC_AMPR : KC_7 );
    break;

  case KC_ASTR:
    unregister_code16((!shifted) ? KC_ASTR : KC_8 );
    break;

  case KC_RPRN:
    unregister_code16((!shifted) ? KC_RPRN : KC_0 );
    break;

  default:
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    // The IS_RETRO check isn't really necessary here, always using
    // keycode & 0xFF would be fine.
    unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot mods SHIFT");
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot mods CTRL");
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot mods ALT");
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot mods GUI");
  }
  if (!mods) {
    println("Oneshot mods off");
  }
}
