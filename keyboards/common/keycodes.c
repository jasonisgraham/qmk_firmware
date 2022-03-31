#include QMK_KEYBOARD_H
#include "user_song_list.c"
#include "version.h"
#include "muse.h"


/* enum custom_keycodes { */
/*                       RGB_SLD = SAFE_RANGE, */
/*                       /\* RGB_SLD = EZ_SAFE_RANGE, *\/ */
/*                       EMACS_ACE_WINDOW_SWAP, */
/*                       EMACS_BUFFER_REVERT, */
/*                       EMACS_INSERT_GET_FEED, */
/*                       EMACS_KILL_PROCESS, */
/*                       EMACS_OTHER_WINDOW, */
/*                       EMACS_WINDOW_CLOSE, */
/*                       EMACS_YAS_C, */
/*                       EMACS_YAS_DOC, */
/*                       EMACS_YAS_MAP_ANON, */
/*                       EMACS_YAS_TF, */
/*                       EMACS_YAS_TL, */
/*                       ESC_THEN_BASE_LAYER, */
/*                       FISH_ACCEPT_SEND, */
/*                       LAYER_LOWER_HOLD, */
/*                       LAYER_RAISE_HOLD, */
/*                       MUSIC_LAYER_ACTIVATE, */
/*                       SHIFTLOK_LAYER_ACTIVATE, */
/*                       SHIFTLOK_LAYER_DEACTIVATE, */
/*                       SYSTEM_LAYER_ACTIVATE, */
/*                       SYSTEM_LAYER_DEACTIVATE, */
/*                       TMUX_COPY_MODE, */
/* }; */

#define max_buffer RALT(KC_ENTER)
#define close_x_window RSFT(RGUI(KC_Q))
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))

/* #define my_comma TD(T_COMMA_H_LTHAN_TH_AT) */
/* #define my_d KC_D */
/* #define my_e KC_E */
/* #define my_f KC_F */
/* #define my_forward_slash TD(T_FS_H_QU_DT_BS_TH_PIPE) */
/* #define my_h KC_H */
/* #define my_i TD(T_I_TH_ASTR) */
/* #define my_j TD(T_J_TH_DLR) */
/* #define my_k TD(T_K_TH_AMP) */
/* #define my_l TD(T_L_TH_CIRC) */
/* #define my_left_shift KC_LSFT */
/* #define my_lower MO(_LOWER) */
/* #define my_m TD(T_M_TH_EXLAM) */
/* /\* #define my_minus TD(T_MINUS_TH_PLUS) *\/ */
/* #define my_n KC_N */
/* #define my_o TD(T_O_TH_LPRN) */
/* #define my_p TD(T_P_TH_RPRN) */
/* #define my_period TD(T_PERIOD_H_GTHAN_TH_HASH) */
/* #define my_right_of_lower KC_BSPACE */
/* #define my_right_shift KC_RSFT */
/* #define my_s KC_S */
/* #define my_semicolon TD(T_SEMI_H_COLON_DT_LSBR_TH_LCBR) */
/* #define my_single_quote TD(T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR) */
/* #define my_space KC_SPACE */
/* #define my_u TD(T_U_TH_AMPR) */
/* #define my_w KC_W */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case SYSTEM_LAYER_ACTIVATE:
    PLAY_SONG(zelda_puzzle);
    layer_on(_SYSTEM);
    return false;

  case SHIFTLOK_LAYER_ACTIVATE:
    if (record->event.pressed) {
      layer_move(_SHIFTLOK);
      /* PLAY_SONG(caps_lock_on_sound); */
      PLAY_SONG(coin_sound);
      return false;
    }
    break;

  case SYSTEM_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      layer_move(_BASE);
      PLAY_SONG(caps_lock_off_sound);
      return false;
    }
    break;

  case EMACS_OTHER_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)  SS_RCTL(SS_TAP(X_W))  SS_RCTL(SS_TAP(X_W)));

    }
    break;
  case EMACS_BUFFER_REVERT:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C))  SS_TAP(X_R));

    }
    break;

  case FISH_ACCEPT_SEND:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_L)))   SS_TAP(X_ENTER));

    }
    break;

  case EMACS_YAS_DOC:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "idoc" macro_alt_slash);

    }
    break;
  case EMACS_YAS_TF:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "itf" macro_alt_slash);
    }
    break;
  case EMACS_YAS_C:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ic" macro_alt_slash);
    }
    break;
  case EMACS_YAS_TL:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "itl" macro_alt_slash);
    }
    break;
  case EMACS_YAS_MAP_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "imapa" macro_alt_slash);

    }
    break;

  case EMACS_ACE_WINDOW_SWAP:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_RSFT(SS_TAP(X_M)));

    }
    break;

  case EMACS_WINDOW_CLOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M))  SS_TAP(X_W)  SS_TAP(X_C));

    }
    break;

  case EMACS_KILL_PROCESS:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_RCTL(SS_TAP(X_B)));
    }
    break;

  case EMACS_INSERT_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING("(def xs (get-feed))");
    }
    break;
  case TMUX_COPY_MODE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_TAP(X_LBRACKET));
    }
    break;

  case ESC_THEN_BASE_LAYER:
    if (record->event.pressed) {
      // only used when returning from shiftlok
      PLAY_SONG(caps_lock_off_sound);
      SEND_STRING(SS_TAP(X_ESCAPE));
      layer_move(_BASE);

    }
    break;

  case LAYER_RAISE_HOLD:
    if (record->event.pressed) {
      PLAY_SONG(major_sound);
      layer_move(_RAISE);

    }
    break;

  case LAYER_LOWER_HOLD:
    if (record->event.pressed) {
      PLAY_SONG(old_spice);
      layer_move(_LOWER);

    }
    break;
  }
  return true;
}
