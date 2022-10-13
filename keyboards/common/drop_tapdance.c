#include "keymap_us_international_linux.h"

enum tap_dance_codes {
                      DANCE_TAB,
                      DANCE_Q,
                      DANCE_SUPER,
                      DANCE_MIC,
                      DANCE_SHIFT,
                      DANCE_W,
                      DANCE_E,
                      DANCE_R,
                      DANCE_T,
                      DANCE_U,
                      DANCE_I,
                      DANCE_O,
                      DANCE_P,
                      DANCE_A,
                      PREONIC_A,
                      PREONIC_Z,
                      DANCE_S,
                      DANCE_13,
                      DANCE_F,
                      DANCE_G,
                      DANCE_16,
                      DANCE_K,
                      DANCE_L,
                      DANCE_19,
                      DANCE_20,
                      DANCE_N,
                      DANCE_M,
                      DANCE_SPACE,
                      DANCE_24,
                      DANCE_25,
                      WWW_BACK_FORWARD,
                      DANCE_28,
                      DANCE_29,
                      DANCE_30,
                      DANCE_31,
                      DANCE_33,
                      DANCE_35,
                      DANCE_36,
                      DANCE_37,
                      DANCE_38,
                      DANCE_39,
                      DANCE_40,
                      DANCE_Y,
                      DANCE_42,
                      DANCE_43,
                      DANCE_44,
                      DANCE_45,
                      DANCE_WINDOWS_N,
                      DANCE_47,
                      DANCE_48,
                      DANCE_49,
                      DANCE_50,
                      DANCE_51,
                      DANCE_52,
                      DANCE_53,
                      DANCE_54,
                      DANCE_55,
                      DANCE_56,
                      DANCE_57,
                      DANCE_58,
                      DANCE_59,
                      DANCE_60,
                      DANCE_61,
                      DANCE_H,
                      DANCE_J,
                      DANCE_64,
                      DANCE_65,
                      DANCE_66,
                      DANCE_67,
                      DANCE_68,
                      DANCE_69,
                      T_LCRB_H_ALT,
                      ONLY_N,
                      T_ALT_TAB_H_BASE,
                      DANCE_73,
                      DANCE_V,
                      DANCE_Z,
                      WINDOWS_OR_ALT_TAB,
                      DANCE_B,
                      DANCE_C,
                      DANCE_D,
                      DANCE_X,
                      DANCE_MIN_OR_EXIT,
                      DANCE_PAREN_BRACKET,
                      DANCE_SAVE_LOAD_NS_SWITCH,
                      DANCE_F5,
                      DANCE_COMMA,
                      DANCE_DOT,
                      DANCE_WINDOWS_I,
                      DANCE_WINDOWS_U,
                      DANCE_WINDOWS_O,
                      DANCE_WINDOWS_P,
};

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
      TAP = 1,
      HOLD,

      TAP2,
      HOLD2,
      TAP2_INTERRUPTED,

      TAP3,
      HOLD3,
      TAP3_INTERRUPTED,

      TAP4,
      HOLD4,
      TAP4_INTERRUPTED,

      TAP5,
      HOLD5,
      TAP5_INTERRUPTED,

      MORE_TAPS
};

static tap dance_state[200];

void register_key(uint16_t k);
void register_key(uint16_t k) {
  register_code16(get_autoshift_state() ? LSFT (k) : k);
}

void unregister_key(uint16_t k);
void unregister_key(uint16_t k) {
  unregister_code16(get_autoshift_state() ? LSFT (k) : k);
}



uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return TAP;
    } else {
      return HOLD;
    }

  } else if (state->count == 2) {
    if (state->interrupted) {
      return TAP2_INTERRUPTED;
    } else if (state->pressed) {
      return HOLD2;
    } else {
      return TAP2;
    }

  }
  else if (state->count == 3) {
    if (state->interrupted) {
      return TAP3_INTERRUPTED;
    } else if (state->pressed) {
      return HOLD3;
    } else {
      return TAP3;
    }
  }

  else if (state->count == 4) {
    if (state->interrupted) {
      return TAP4_INTERRUPTED;
    } else if (state->pressed) {
      return HOLD4;
    } else {
      return TAP4;
    }
  }


  else if (state->count == 5) {
    if (state->interrupted) {
      return TAP5_INTERRUPTED;
    } else if (state->pressed) {
      return HOLD5;
    } else {
      return TAP5;
    }
  }


  return MORE_TAPS;
}


void on_dance_fn(int key, qk_tap_dance_state_t *state, void *user_data);

void on_dance_fn(int key, qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(key);
    tap_code16(key);
    tap_code16(key);
  }
  if(state->count > 3) {
    tap_code16(key);
  }
}

void on_dance_tab(qk_tap_dance_state_t *state, void *user_data);
void dance_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_tab_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_tab(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_TAB, state, user_data);
}

void dance_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case TAP: tap_code16(KC_TAB); break;
    /* case HOLD: layer_on(6); break; */
  case HOLD2:
    tap_code16(RSFT(KC_TAB));
    break;

  case TAP2: tap_code16(KC_TAB); register_code16(KC_TAB); break;
  case HOLD:
    register_code16(KC_LCTL);
    PLAY_SONG(__f6);
    layer_on(_HYPER);
    break;

  case HOLD3:
    layer_move(_SHIFTLOCK);
    PLAY_SONG(caps_lock_on_sound);
    /* layer_on(); */
    break;

  case TAP2_INTERRUPTED: tap_code16(KC_TAB); register_code16(KC_TAB);
    break;

  case TAP3:
    layer_move(_BASE);
  }
}


void dance_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
  case TAP: unregister_code16(KC_TAB); break;
  case HOLD2:
    unregister_code16(RSFT(KC_TAB));
 break;
  case TAP2: unregister_code16(KC_TAB); break;
  case HOLD:
    unregister_code16(KC_LCTL);
    layer_off(_HYPER);

     break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;

  }
  dance_state[0].step = 0;
}
void on_dance_Q(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Q(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_Q, state, user_data);
}

void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case TAP: register_code16(KC_Q); break;
  case HOLD:
    register_key(KC_Q);
    break;
  case HOLD2:
    register_code16(LSFT (KC_Q));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_Q);
    register_code16(KC_Q);
    break;
  }
}

void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[1].step) {
  case TAP: unregister_code16(KC_Q); break;
  case HOLD:
  case HOLD2:
    unregister_key(KC_Q);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_Q);
    break;
  }
  dance_state[1].step = 0;
}

void on_dance_W(qk_tap_dance_state_t *state, void *user_data);
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_W_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_W(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_W, state, user_data);
}

void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
  case TAP: register_code16(KC_W); break;
  case HOLD:
    register_key(KC_W); break;
    unregister_key(KC_W); break;
  case HOLD2:
    register_code16(LSFT (KC_W));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_W);
    register_code16(KC_W);
    break;

  }
}

void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[2].step) {
  case TAP: unregister_code16(KC_W); break;
  case HOLD:
    unregister_key(KC_W); break;
  case HOLD2:
    unregister_code16(LSFT (KC_W));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_W);
    break;

  }
  dance_state[2].step = 0;
}

void on_dance_R(qk_tap_dance_state_t *state, void *user_data);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_R(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_R, state, user_data);
}

void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
  case TAP: register_code16(KC_R); break;
  case HOLD:
    register_key(KC_R); break;
  case HOLD2:
    tap_code16(KC_R);
    register_code16(LSFT (KC_R));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_R);
    register_code16(KC_R);
  }
}

void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
  case TAP: unregister_code16(KC_R); break;
  case HOLD:
    unregister_key(KC_R); break;
  case HOLD2:
    unregister_code16(LSFT (KC_R));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_R);
    break;

  }
  dance_state[4].step = 0;
}
void on_dance_T(qk_tap_dance_state_t *state, void *user_data);
void dance_T_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_T_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_T(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_T, state, user_data);
}

void dance_T_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
  case TAP: register_code16(KC_T); break;
  case HOLD:
    register_key(KC_T); break;
  case HOLD2:
    register_code16(LSFT (KC_T));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_T);
    register_code16(KC_T);
    break;
  }
}

void dance_T_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
  case TAP: unregister_code16(KC_T); break;
  case HOLD:
    unregister_key(KC_T); break;
  case HOLD2:
    unregister_code16(LSFT (KC_T));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_T);
    break;
  }
  dance_state[5].step = 0;
}


void on_dance_U(qk_tap_dance_state_t *state, void *user_data);
void dance_U_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_U_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_U(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_U, state, user_data);
}

void dance_U_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
  case TAP: register_code16(KC_U); break;
  case HOLD:
    register_key(KC_U);
    break;
  case HOLD2:
    register_code16(KC_7);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_U);
    register_code16(KC_U);
    break;
  }
}

void dance_U_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
  case TAP: unregister_code16(KC_U); break;
  case HOLD:
    unregister_key(KC_U);
    break;
  case HOLD2:
    unregister_code16(KC_7);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_U);
    break;
  }
  dance_state[6].step = 0;
}

void on_dance_I(qk_tap_dance_state_t *state, void *user_data);
void dance_I_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_I_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_I(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_I, state, user_data);
}

void dance_I_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
  case TAP: register_code16(KC_I); break;
  case HOLD:
    register_key(KC_I);
    break;
  case HOLD2:
    register_code16(KC_8);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_I);
    register_code16(KC_I);
    break;

  }
}

void dance_I_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
  case TAP: unregister_code16(KC_I); break;
  case HOLD:
    unregister_key(KC_I);
    break;
  case HOLD2:
    unregister_code16(KC_8);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_I);
    break;
  }
  dance_state[7].step = 0;
}

void on_dance_O(qk_tap_dance_state_t *state, void *user_data);
void dance_O_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_O_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_O(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_O, state, user_data);
}

void dance_O_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[8].step = dance_step(state);
  switch (dance_state[8].step) {

  case TAP: register_code16(KC_O); break;
  case HOLD:
    register_key(KC_O);
    break;

  case HOLD2:
    register_code16(KC_9);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    register_code16(KC_O);
    register_code16(KC_O);
    break;

  }
}

void dance_O_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[8].step) {
  case TAP: unregister_code16(KC_O); break;
  case HOLD:
    unregister_key(KC_O);
    break;

  case HOLD2:
    unregister_code16(KC_9);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    unregister_code16(KC_O);
    unregister_code16(KC_O);
    break;

  }
  dance_state[8].step = 0;
}

void on_dance_P(qk_tap_dance_state_t *state, void *user_data);
void dance_P_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_P_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_P(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_P, state, user_data);
}

void dance_P_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[9].step = dance_step(state);
  switch (dance_state[9].step) {
  case TAP: register_code16(KC_P); break;
  case HOLD:
    register_key(KC_P);
      break;
  case HOLD2:
    register_code16(KC_0);
    break;
  case TAP3:
  case HOLD3:
    tap_code16(KC_P);
    tap_code16(KC_P);
    register_code16(KC_P);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_P);
    register_code16(KC_P);
    break;
  case TAP4:
    layer_move(_SYSTEM);
    PLAY_SONG(scroll_lock_on_sound);
#ifdef RGBLIGHT_MODE
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif
    break;


  }
}

void dance_P_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[9].step) {
  case TAP: unregister_code16(KC_P); break;
  case HOLD:
    unregister_key(KC_P);

    break;

  case HOLD2:
    unregister_code16(KC_0);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_P);
    break;
  default:
    unregister_code16(LSFT(KC_P));
    unregister_code16(KC_P);


  }
  dance_state[9].step = 0;
}

void on_dance_A(qk_tap_dance_state_t *state, void *user_data);
void dance_A_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_A_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_A(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_A, state, user_data);
}

void dance_A_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[11].step = dance_step(state);
  switch (dance_state[11].step) {
  case TAP: register_code16(KC_A); break;
  case HOLD:
    register_key(KC_A); break;
  case HOLD2:
    register_code16(LSFT (KC_A));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_A);
    register_code16(KC_A);
    break;
  /* default: */
  /*   tap_code16(KC_A); */
  /*   break; */
  }
}

void dance_A_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[11].step) {
  case TAP: unregister_code16(KC_A); break;
  case HOLD:
    unregister_key(KC_A); break;
  case HOLD2:
    unregister_code16(LSFT (KC_A));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_A);
    break;
  }
  dance_state[11].step = 0;
}

void on_preonic_A(qk_tap_dance_state_t *state, void *user_data);
void preonic_A_finished(qk_tap_dance_state_t *state, void *user_data);
void preonic_A_reset(qk_tap_dance_state_t *state, void *user_data);

void on_preonic_A(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_A, state, user_data);
}

void preonic_A_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[81].step = dance_step(state);
  switch (dance_state[81].step) {
  case TAP: register_code16(KC_A); break;
  case HOLD:
    register_code16(KC_RCTL);
    break;

  case HOLD2:
    register_code16(LSFT (KC_A));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_A);
    register_code16(KC_A);
    break;
  }
}

void preonic_A_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[81].step) {
  case TAP: unregister_code16(KC_A); break;
  case HOLD:
    unregister_code16(KC_RCTL);
    break;
  case HOLD2:
    unregister_code16(LSFT (KC_A));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_A);
    break;
  }
  dance_state[81].step = 0;
}


void on_dance_S(qk_tap_dance_state_t *state, void *user_data);
void dance_S_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_S_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_S(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_S, state, user_data);
}

void dance_S_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[12].step = dance_step(state);
  switch (dance_state[12].step) {
  case TAP: register_code16(KC_S); break;
  case HOLD:
    register_key(KC_S); break;
  case HOLD2:
    register_code16(LSFT (KC_S));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_S);
    register_code16(KC_S);
    break;
  }
}

void dance_S_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[12].step) {
  case TAP: unregister_code16(KC_S); break;
  case HOLD:
    unregister_key(KC_S); break;
  case HOLD2:
    unregister_code16(LSFT (KC_S));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_S);
    break;
  }
  dance_state[12].step = 0;
}


void on_dance_pb(qk_tap_dance_state_t *state, void *user_data);
void dance_pb_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_pb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_pb(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LPRN, state, user_data);
}

void dance_pb_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[13].step = dance_step(state);
  switch (dance_state[13].step) {
  case TAP: register_code16(KC_LPRN); break;
  case HOLD: register_code16(KC_RPRN); break;

  case TAP2: register_code16(KC_LBRACKET);  break;
  case HOLD2: register_code16(KC_RBRACKET); break;
  case TAP2_INTERRUPTED: register_code16(KC_LPRN); register_code16(KC_LPRN); break;

  case TAP3: register_code16(KC_LCBR);  break;
  case HOLD3: register_code16(KC_RCBR); break;
  case TAP3_INTERRUPTED: register_code16(KC_LPRN); register_code16(KC_LPRN); register_code16(KC_LPRN); break;


  }
}

void dance_pb_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[13].step) {
  case TAP: unregister_code16(KC_LPRN); break;
  case HOLD: unregister_code16(KC_RPRN); break;
  case TAP2: unregister_code16(KC_LBRACKET);  break;
  case HOLD2: unregister_code16(KC_RBRACKET); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_LPRN); break;

  case TAP3:
  case TAP3_INTERRUPTED:
    unregister_code16(KC_LCBR);  break;
  case HOLD3: unregister_code16(KC_RCBR); break;

  }
  dance_state[13].step = 0;
}


void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[16].step = dance_step(state);
  switch (dance_state[16].step) {
  case TAP: register_code16(KC_J); break;
  case HOLD: register_key(KC_J); break;
  case HOLD2: register_code16(KC_DLR); break;

  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_J);
    register_code16(KC_J);
    break;
  }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[16].step) {
  case TAP: unregister_code16(KC_J); break;
  case HOLD: unregister_key(KC_J); break;

  case HOLD2: unregister_code16(KC_DLR); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_J); break;
  }
  dance_state[16].step = 0;
}

void on_dance_K(qk_tap_dance_state_t *state, void *user_data);
void dance_K_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_K_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_K(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_K, state, user_data);
}

void dance_K_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[17].step = dance_step(state);
  switch (dance_state[17].step) {
  case TAP: register_code16(KC_K); break;

  case HOLD:
    register_key(KC_K); break;
  case HOLD2:
    register_code16(KC_5);
    break;

  case TAP2: register_code16(RCTL(KC_SCOLON)); break;
  case TAP2_INTERRUPTED: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_K_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[17].step) {
  case TAP: unregister_code16(KC_K); break;

  case HOLD:
    unregister_key(KC_K); break;
  case HOLD2:
    unregister_code16(KC_5);
    break;

  case TAP2: unregister_code16(RCTL(KC_SCOLON)); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_K); break;
  }
  dance_state[17].step = 0;
}
void on_dance_L(qk_tap_dance_state_t *state, void *user_data);
void dance_L_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_L_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_L(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_L, state, user_data);
}

void dance_L_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[18].step = dance_step(state);
  switch (dance_state[18].step) {
  case TAP: register_code16(KC_L); break;
  case HOLD:
    register_key(KC_L); break;
  case HOLD2:
    register_code(KC_6);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_L);
    register_code16(KC_L);
    break;

  }
}

void dance_L_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[18].step) {


  case TAP: unregister_code16(KC_L); break;
  case HOLD2:
    unregister_code(KC_6);
    break;

  case HOLD:
    unregister_key(KC_L); break;
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_L);
    break;
  }
  dance_state[18].step = 0;
}

void on_dance_N(qk_tap_dance_state_t *state, void *user_data);
void dance_N_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_N_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_N(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_N, state, user_data);
}

void dance_N_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[21].step = dance_step(state);
  switch (dance_state[21].step) {
  case TAP: register_code16(KC_N); break;
  case HOLD:
    register_key(KC_N); break;
  case HOLD2:
    register_code16(LSFT (KC_N));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_N);
    register_code16(KC_N);
    break;

  }
}

void dance_N_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[21].step) {
  case TAP: unregister_code16(KC_N); break;
  case HOLD:
    unregister_key(KC_N); break;
  case HOLD2:
    unregister_code16(LSFT (KC_N));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_N);
    break;

  }
  dance_state[21].step = 0;
}

void on_dance_M(qk_tap_dance_state_t *state, void *user_data);
void dance_M_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_M_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_M(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_M, state, user_data);
}

void dance_M_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[22].step = dance_step(state);
  switch (dance_state[22].step) {

  case TAP: register_code16(KC_M); break;
  case HOLD:
    register_key(KC_M); break;
  case HOLD2:
    register_code16(KC_1);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_M);
    register_code16(KC_M);
    break;

  }
}

void dance_M_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[22].step) {
  case TAP: unregister_code16(KC_M); break;
  case HOLD:
    unregister_key(KC_M); break;
  case HOLD2:
    unregister_code16(KC_1);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_M);
    break;
  }
  dance_state[22].step = 0;
}

void on_dance_space(qk_tap_dance_state_t *state, void *user_data);
void dance_space_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_space_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_space(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_SPACE, state, user_data);
}

void dance_space_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[23].step = dance_step(state);
  switch (dance_state[23].step) {
  case TAP: register_code16(KC_SPACE); break;
  case HOLD: tap_code16(KC_SPACE); break;

  case TAP2:
  case TAP2_INTERRUPTED:
  case HOLD2:
    register_code16(KC_SPACE); register_code16(KC_SPACE); break;
  }
}

void dance_space_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    unregister_code16(KC_SPACE);
  dance_state[23].step = 0;
}
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_DOT, state, user_data);
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[24].step = dance_step(state);
  switch (dance_state[24].step) {
  case TAP: register_code16(KC_DOT); break;
  case HOLD:
    register_key(KC_DOT); break;
  case TAP2: register_code16(KC_DOT); register_code16(KC_DOT); break;
  case HOLD2: register_code16(KC_HASH); break;
  case TAP2_INTERRUPTED: tap_code16(KC_DOT); register_code16(KC_DOT);
  }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[24].step) {
  case TAP: unregister_code16(KC_DOT); break;
  case HOLD:
    unregister_key(KC_DOT); break;
  case TAP2: unregister_code16(KC_DOT); break;
  case HOLD2: unregister_code16(KC_HASH); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_DOT); break;
  }
  dance_state[24].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_SLASH, state, user_data);
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[25].step = dance_step(state);
  switch (dance_state[25].step) {
  case TAP: register_code16(KC_SLASH); break;
  case HOLD:
    register_key(KC_SLASH); break;
  case TAP2: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
  case HOLD2: register_code16(US_IQUE); break;
  case TAP2_INTERRUPTED: tap_code16(KC_SLASH); register_code16(KC_SLASH);
  }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[25].step) {
  case TAP: unregister_code16(KC_SLASH); break;
  case HOLD:
    unregister_key(KC_SLASH); break;
  case TAP2: unregister_code16(KC_SLASH); break;
  case HOLD2: unregister_code16(KC_SLASH); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_SLASH); break;
  }
  dance_state[25].step = 0;
}
void on_www_back_forward(qk_tap_dance_state_t *state, void *user_data);
void www_back_forward_finished(qk_tap_dance_state_t *state, void *user_data);
void www_back_forward_reset(qk_tap_dance_state_t *state, void *user_data);

void on_www_back_forward(qk_tap_dance_state_t *state, void *user_data) {
}

void www_back_forward_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[27].step = dance_step(state);
  switch (dance_state[27].step) {
  case TAP: register_code16(LALT(KC_LEFT)); break;
  case TAP2: register_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); break;
  case HOLD2: register_code16(LALT(KC_RIGHT)); break;
  case TAP2_INTERRUPTED: tap_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT));
  }
}

void www_back_forward_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[27].step) {
  case TAP: unregister_code16(LALT(KC_LEFT)); break;
  case TAP2: unregister_code16(LALT(KC_LEFT)); break;
  case HOLD2: unregister_code16(LALT(KC_RIGHT)); break;
  case TAP2_INTERRUPTED: unregister_code16(LALT(KC_LEFT)); break;
  }
  dance_state[27].step = 0;
}
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[28].step = dance_step(state);
  switch (dance_state[28].step) {
  case TAP: register_code16(KC_LSPO); break;
  case TAP2: layer_move(8); break;
  case TAP2_INTERRUPTED: tap_code16(KC_LSPO); register_code16(KC_LSPO);
  }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[28].step) {
  case TAP: unregister_code16(KC_LSPO); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_LSPO); break;
  }
  dance_state[28].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[29].step = dance_step(state);
  switch (dance_state[29].step) {
  case TAP: register_code16(RCTL(KC_PGUP)); break;
  case TAP2: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[29].step) {
  case TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case TAP2: unregister_code16(RCTL(KC_PGUP)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[29].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[30].step = dance_step(state);
  switch (dance_state[30].step) {
  case TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[30].step) {
  case TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: unregister_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[30].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[31].step = dance_step(state);
  switch (dance_state[31].step) {
  case TAP: register_code16(KC_INSERT); break;
  case TAP2: layer_move(8); break;
  case TAP2_INTERRUPTED: tap_code16(KC_INSERT); register_code16(KC_INSERT);
  }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[31].step) {
  case TAP: unregister_code16(KC_INSERT); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_INSERT); break;
  }
  dance_state[31].step = 0;
}

void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[33].step = dance_step(state);
  switch (dance_state[33].step) {
  case TAP: register_code16(RALT(KC_ENTER)); break;
  case TAP2: register_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER)); break;
  case HOLD2: register_code16(RGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: tap_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER));
  }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[33].step) {
  case TAP: unregister_code16(RALT(KC_ENTER)); break;
  case TAP2: unregister_code16(RALT(KC_ENTER)); break;
  case HOLD2: unregister_code16(RGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: unregister_code16(RALT(KC_ENTER)); break;
  }
  dance_state[33].step = 0;
}

void on_dance_35(qk_tap_dance_state_t *state, void *user_data);
void dance_35_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_35_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_35(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_35_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[35].step = dance_step(state);
  switch (dance_state[35].step) {
  case TAP: register_code16(RCTL(KC_PGUP)); break;
  case TAP2: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_35_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[35].step) {
  case TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case TAP2: unregister_code16(RCTL(KC_PGUP)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[35].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[36].step = dance_step(state);
  switch (dance_state[36].step) {
  case TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[36].step) {
  case TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: unregister_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[36].step = 0;
}
void on_dance_37(qk_tap_dance_state_t *state, void *user_data);
void dance_37_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_37_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_37(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_37_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[37].step = dance_step(state);
  switch (dance_state[37].step) {
  case TAP: register_code16(KC_TAB); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_GRAVE); break;
  case HOLD2: register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_37_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[37].step) {
  case TAP: unregister_code16(KC_TAB); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case HOLD2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;
  }
  dance_state[37].step = 0;
}
void on_dance_38(qk_tap_dance_state_t *state, void *user_data);
void dance_38_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_38_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_38(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_38_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[38].step = dance_step(state);
  switch (dance_state[38].step) {
  case TAP: register_code16(LGUI(KC_Q)); break;
  case TAP2: register_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q)); break;
  case HOLD2: register_code16(set_window_q); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q));
  }
}

void dance_38_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[38].step) {
  case TAP: unregister_code16(LGUI(KC_Q)); break;
  case TAP2: unregister_code16(LGUI(KC_Q)); break;
  case HOLD2: unregister_code16(set_window_q); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_Q)); break;
  }
  dance_state[38].step = 0;
}
void on_dance_39(qk_tap_dance_state_t *state, void *user_data);
void dance_39_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_39_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_39(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_39_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[39].step = dance_step(state);
  switch (dance_state[39].step) {
  case TAP: register_code16(LGUI(KC_W)); break;
  case TAP2: register_code16(LGUI(KC_W)); register_code16(LGUI(KC_W)); break;
  case HOLD2: register_code16(set_window_w); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_W)); register_code16(LGUI(KC_W));
  }
}

void dance_39_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[39].step) {
  case TAP: unregister_code16(LGUI(KC_W)); break;
  case TAP2: unregister_code16(LGUI(KC_W)); break;
  case HOLD2: unregister_code16(set_window_w); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_W)); break;
  }
  dance_state[39].step = 0;
}
void on_dance_40(qk_tap_dance_state_t *state, void *user_data);
void dance_40_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_40_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_40(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_40_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[40].step = dance_step(state);
  switch (dance_state[40].step) {
  case TAP: register_code16(LGUI(KC_R)); break;
  case TAP2: register_code16(LGUI(KC_R)); register_code16(LGUI(KC_R)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_R)); register_code16(LGUI(KC_R));
  }
}

void dance_40_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[40].step) {
  case TAP: unregister_code16(LGUI(KC_R)); break;
  case TAP2: unregister_code16(LGUI(KC_R)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_R)); break;
  }
  dance_state[40].step = 0;
}
void on_dance_comma(qk_tap_dance_state_t *state, void *user_data);
void dance_comma_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_comma_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_comma(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_COMMA, state, user_data);
}

void dance_comma_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[99].step = dance_step(state);
  switch (dance_state[99].step) {
  case TAP: register_code16(KC_COMMA); break;
  case HOLD:
    register_key(KC_COMMA);
    break;

  case HOLD2:
    register_code16(KC_2);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    register_code16(KC_COMMA);
    register_code16(KC_COMMA);
    break;

  }
}

void dance_comma_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[99].step) {
  case HOLD:
    unregister_key(KC_COMMA); break;

  case HOLD2:
    unregister_code16(KC_2);
    break;

  default:
    unregister_code16(KC_COMMA);
    break;
  }
  dance_state[99].step = 0;
}

void on_dance_dot(qk_tap_dance_state_t *state, void *user_data);
void dance_dot_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_dot_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_dot(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_DOT, state, user_data);
}

void dance_dot_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[100].step = dance_step(state);
  switch (dance_state[100].step) {
  case TAP: register_code16(KC_DOT); break;
  case HOLD:
    register_key(KC_DOT); break;

  case HOLD2:
    register_code16(KC_3);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    register_code16(KC_DOT);
    register_code16(KC_DOT);
    break;

  }
}

void dance_dot_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[100].step) {
  case HOLD:
    unregister_key(KC_DOT); break;
  case HOLD2:
    unregister_code16(KC_3);
    break;

  default:
    unregister_code16(KC_DOT);
    break;
  }
  dance_state[100].step = 0;
}

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_Y, state, user_data);
}

void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[41].step = dance_step(state);
  switch (dance_state[41].step) {
  case TAP: register_code16(KC_Y); break;
  case HOLD:
    register_key(KC_Y); break;

  case HOLD2:
    register_code16(KC_HOME);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    register_code16(KC_Y);
    register_code16(KC_Y);
    break;

  }
}

void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[41].step) {
  case TAP: unregister_code16(KC_Y); break;
  case HOLD:
    unregister_key(KC_Y); break;

  case HOLD2:
    unregister_code16(KC_HOME);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    unregister_code16(KC_Y);
    break;

  }
  dance_state[41].step = 0;
}

void on_dance_42(qk_tap_dance_state_t *state, void *user_data);
void dance_42_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_42_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_42(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_G, state, user_data);
}

void dance_42_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[42].step = dance_step(state);
  switch (dance_state[42].step) {
  case TAP: register_code16(LGUI(KC_G)); break;
  case TAP2: register_code16(LGUI(KC_G)); register_code16(LGUI(KC_G)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_G)); register_code16(LGUI(KC_G));
  }
}

void dance_42_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[42].step) {
  case TAP: unregister_code16(LGUI(KC_G)); break;
  case TAP2: unregister_code16(LGUI(KC_G)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_G)); break;
  }
  dance_state[42].step = 0;
}
void on_dance_43(qk_tap_dance_state_t *state, void *user_data);
void dance_43_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_43_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_43(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 4) {
    tap_code16(RGUI(KC_J));
    tap_code16(RGUI(KC_J));
    tap_code16(RGUI(KC_J));
    tap_code16(RGUI(KC_J));
  }
  if(state->count > 4) {
    tap_code16(RGUI(KC_J));
  }
}

void dance_43_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[43].step = dance_step(state);
  switch (dance_state[43].step) {
  case TAP: register_code16(RGUI(KC_J)); break;
  case TAP2: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_J)))); break;
  case TAP2_INTERRUPTED: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
  }
}

void dance_43_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[43].step) {
  case TAP: unregister_code16(RGUI(KC_J)); break;
  case TAP2: unregister_code16(RGUI(KC_J)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_J)))); break;
  case TAP2_INTERRUPTED: unregister_code16(RGUI(KC_J)); break;
  }
  dance_state[43].step = 0;
}
void on_dance_44(qk_tap_dance_state_t *state, void *user_data);
void dance_44_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_44_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_44(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_K));
    tap_code16(LGUI(KC_K));
    tap_code16(LGUI(KC_K));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_K));
  }
}

void dance_44_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[44].step = dance_step(state);
  switch (dance_state[44].step) {
  case TAP: register_code16(LGUI(KC_K)); break;
  case TAP2: register_code16(LGUI(KC_K)); register_code16(LGUI(KC_K)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_K)); register_code16(LGUI(KC_K));
  }
}

void dance_44_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[44].step) {
  case TAP: unregister_code16(LGUI(KC_K)); break;
  case TAP2: unregister_code16(LGUI(KC_K)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_K)); break;
  }
  dance_state[44].step = 0;
}
void on_dance_45(qk_tap_dance_state_t *state, void *user_data);
void dance_45_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_45_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_45(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_L));
    tap_code16(LGUI(KC_L));
    tap_code16(LGUI(KC_L));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_L));
  }
}

void dance_45_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[45].step = dance_step(state);
  switch (dance_state[45].step) {
  case TAP: register_code16(LGUI(KC_L)); break;
  case TAP2: register_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_L)); register_code16(LGUI(KC_L));
  }
}

void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[45].step) {
  case TAP: unregister_code16(LGUI(KC_L)); break;
  case TAP2: unregister_code16(LGUI(KC_L)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_L)); break;
  }
  dance_state[45].step = 0;
}
void on_dance_windows_n(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_n_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_windows_n(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_N));
    tap_code16(LGUI(KC_N));
    tap_code16(LGUI(KC_N));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_N));
  }
}

void dance_windows_n_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[46].step = dance_step(state);
  switch (dance_state[46].step) {
  case TAP: register_code16(LGUI(KC_N)); break;
  case HOLD: register_code16(LSFT(LGUI(KC_N))); break;
  case TAP2: register_code16(LGUI(KC_N)); register_code16(LGUI(KC_N)); break;
  case HOLD2: register_code16(set_window_n); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_N)); register_code16(LGUI(KC_N));
  }
}

void dance_windows_n_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[46].step) {
  case TAP: unregister_code16(LGUI(KC_N)); break;
  case HOLD: unregister_code16(LSFT(LGUI(KC_N))); break;
  case TAP2: unregister_code16(LGUI(KC_N)); break;
  case HOLD2: unregister_code16(set_window_n); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_N)); break;
  }
  dance_state[46].step = 0;
}
void on_dance_47(qk_tap_dance_state_t *state, void *user_data);
void dance_47_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_47_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_47(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
  }
}

void dance_47_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[47].step = dance_step(state);
  switch (dance_state[47].step) {
  case TAP: register_code16(LGUI(LSFT(KC_UP))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP))); break;
  case HOLD2: register_code16(RGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP)));
  }
}

void dance_47_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[47].step) {
  case TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case HOLD2: unregister_code16(RGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_UP))); break;
  }
  dance_state[47].step = 0;
}
void on_dance_48(qk_tap_dance_state_t *state, void *user_data);
void dance_48_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_48_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_48(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_LEFT)));
    tap_code16(LGUI(LSFT(KC_LEFT)));
    tap_code16(LGUI(LSFT(KC_LEFT)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_LEFT)));
  }
}

void dance_48_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[48].step = dance_step(state);
  switch (dance_state[48].step) {
  case TAP: register_code16(LGUI(LSFT(KC_LEFT))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT))); break;
  case HOLD2: register_code16(LGUI(LSFT(KC_H))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT)));
  }
}

void dance_48_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[48].step) {
  case TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case HOLD2: unregister_code16(LGUI(LSFT(KC_H))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  }
  dance_state[48].step = 0;
}
void on_dance_49(qk_tap_dance_state_t *state, void *user_data);
void dance_49_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_49_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_49(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_DOWN)));
    tap_code16(LGUI(LSFT(KC_DOWN)));
    tap_code16(LGUI(LSFT(KC_DOWN)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_DOWN)));
  }
}

void dance_49_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[49].step = dance_step(state);
  switch (dance_state[49].step) {
  case TAP: register_code16(LGUI(LSFT(KC_DOWN))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN))); break;
  case HOLD2: register_code16(RGUI(RSFT(KC_J))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN)));
  }
}

void dance_49_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[49].step) {
  case TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case HOLD2: unregister_code16(RGUI(RSFT(KC_J))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  }
  dance_state[49].step = 0;
}
void on_dance_50(qk_tap_dance_state_t *state, void *user_data);
void dance_50_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_50_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_50(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_RIGHT)));
    tap_code16(LGUI(LSFT(KC_RIGHT)));
    tap_code16(LGUI(LSFT(KC_RIGHT)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_RIGHT)));
  }
}

void dance_50_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[50].step = dance_step(state);
  switch (dance_state[50].step) {
  case TAP: register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case HOLD2: register_code16(LGUI(LSFT(KC_L))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT)));
  }
}

void dance_50_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[50].step) {
  case TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case HOLD2: unregister_code16(LGUI(LSFT(KC_L))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  }
  dance_state[50].step = 0;
}
void dance_51_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_51_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_51_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[51].step = dance_step(state);
  switch (dance_state[51].step) {
  case HOLD2: register_code16(RCTL(RGUI(KC_Q))); break;
  }
}

void dance_51_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[51].step) {
  case HOLD2: unregister_code16(RCTL(RGUI(KC_Q))); break;
  }
  dance_state[51].step = 0;
}
void on_dance_52(qk_tap_dance_state_t *state, void *user_data);
void dance_52_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_52_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_52(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_TAB, state, user_data);
}

void dance_52_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[52].step = dance_step(state);
  switch (dance_state[52].step) {
  case TAP: register_code16(KC_TAB); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_GRAVE); break;
  case HOLD2: register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_52_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[52].step) {
  case TAP: unregister_code16(KC_TAB); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case HOLD2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;
  }
  dance_state[52].step = 0;
}
void on_dance_53(qk_tap_dance_state_t *state, void *user_data);
void dance_53_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_53_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_53(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TILD);
    tap_code16(KC_TILD);
    tap_code16(KC_TILD);
  }
  if(state->count > 3) {
    tap_code16(KC_TILD);
  }
}

void dance_53_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[53].step = dance_step(state);
  switch (dance_state[53].step) {
  case TAP: register_code16(KC_TILD); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_TILD); register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TILD); register_code16(KC_TILD);
  }
}

void dance_53_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[53].step) {
  case TAP: unregister_code16(KC_TILD); break;
  case TAP2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TILD); break;
  }
  dance_state[53].step = 0;
}
void on_dance_54(qk_tap_dance_state_t *state, void *user_data);
void dance_54_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_54_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_54(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_UNDS, state, user_data);
}

void dance_54_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[54].step = dance_step(state);
  switch (dance_state[54].step) {
  case TAP: register_code16(KC_UNDS); break;
  case HOLD: register_code16(KC_PLUS); break;
  case TAP2: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
  case TAP2_INTERRUPTED: tap_code16(KC_UNDS); register_code16(KC_UNDS);
  }
}

void dance_54_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[54].step) {
  case TAP: unregister_code16(KC_UNDS); break;
  case HOLD: unregister_code16(KC_PLUS); break;
  case TAP2: unregister_code16(KC_UNDS); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_UNDS); break;
  }
  dance_state[54].step = 0;
}
void on_dance_55(qk_tap_dance_state_t *state, void *user_data);
void dance_55_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_55_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_55(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_COLN);
    tap_code16(KC_COLN);
    tap_code16(KC_COLN);
  }
  if(state->count > 3) {
    tap_code16(KC_COLN);
  }
}

void dance_55_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[55].step = dance_step(state);
  switch (dance_state[55].step) {
  case TAP: register_code16(KC_COLN); break;
  case HOLD: register_code16(KC_LCBR); break;
  case TAP2: register_code16(KC_COLN); register_code16(KC_COLN); break;
  case TAP2_INTERRUPTED: tap_code16(KC_COLN); register_code16(KC_COLN);
  }
}

void dance_55_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[55].step) {
  case TAP: unregister_code16(KC_COLN); break;
  case HOLD: unregister_code16(KC_LCBR); break;
  case TAP2: unregister_code16(KC_COLN); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_COLN); break;
  }
  dance_state[55].step = 0;
}
void on_dance_56(qk_tap_dance_state_t *state, void *user_data);
void dance_56_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_56_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_56(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DQUO);
    tap_code16(KC_DQUO);
    tap_code16(KC_DQUO);
  }
  if(state->count > 3) {
    tap_code16(KC_DQUO);
  }
}

void dance_56_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[56].step = dance_step(state);
  switch (dance_state[56].step) {
  case TAP: register_code16(KC_DQUO); break;
  case HOLD: register_code16(KC_RCBR); break;
  case TAP2: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
  case TAP2_INTERRUPTED: tap_code16(KC_DQUO); register_code16(KC_DQUO);
  }
}

void dance_56_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[56].step) {
  case TAP: unregister_code16(KC_DQUO); break;
  case HOLD: unregister_code16(KC_RCBR); break;
  case TAP2: unregister_code16(KC_DQUO); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_DQUO); break;
  }
  dance_state[56].step = 0;
}
void dance_57_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_57_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_57_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[57].step = dance_step(state);
  switch (dance_state[57].step) {
  case TAP: layer_move(6); break;
  case HOLD: layer_move(0); break;
  case TAP2: layer_move(6); break;
  case TAP2_INTERRUPTED: layer_move(6); break;
  }
}

void dance_57_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[57].step) {
  }
  dance_state[57].step = 0;
}
void on_dance_58(qk_tap_dance_state_t *state, void *user_data);
void dance_58_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_58_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_58(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RGUI(RSFT(KC_H)));
    tap_code16(RGUI(RSFT(KC_H)));
    tap_code16(RGUI(RSFT(KC_H)));
  }
  if(state->count > 3) {
    tap_code16(RGUI(RSFT(KC_H)));
  }
}

void dance_58_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[58].step = dance_step(state);
  switch (dance_state[58].step) {
  case TAP: register_code16(RGUI(RSFT(KC_H))); break;
  case TAP2: register_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H))); break;
  case HOLD2: register_code16(RGUI(RSFT(KC_LEFT))); break;
  case TAP2_INTERRUPTED: tap_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H)));
  }
}

void dance_58_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[58].step) {
  case TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
  case TAP2: unregister_code16(RGUI(RSFT(KC_H))); break;
  case HOLD2: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
  case TAP2_INTERRUPTED: unregister_code16(RGUI(RSFT(KC_H))); break;
  }
  dance_state[58].step = 0;
}
void on_dance_59(qk_tap_dance_state_t *state, void *user_data);
void dance_59_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_59_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_59(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RGUI(RSFT(KC_K)));
    tap_code16(RGUI(RSFT(KC_K)));
    tap_code16(RGUI(RSFT(KC_K)));
  }
  if(state->count > 3) {
    tap_code16(RGUI(RSFT(KC_K)));
  }
}

void dance_59_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[59].step = dance_step(state);
  switch (dance_state[59].step) {
  case TAP: register_code16(RGUI(RSFT(KC_K))); break;
  case TAP2: register_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K))); break;
  case HOLD2: register_code16(KC_F11); break;
  case TAP2_INTERRUPTED: tap_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K)));
  }
}

void dance_59_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[59].step) {
  case TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
  case TAP2: unregister_code16(RGUI(RSFT(KC_K))); break;
  case HOLD2: unregister_code16(KC_F11); break;
  case TAP2_INTERRUPTED: unregister_code16(RGUI(RSFT(KC_K))); break;
  }
  dance_state[59].step = 0;
}
void on_dance_60(qk_tap_dance_state_t *state, void *user_data);
void dance_60_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_60_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_60(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RGUI(RSFT(KC_L)));
    tap_code16(RGUI(RSFT(KC_L)));
    tap_code16(RGUI(RSFT(KC_L)));
  }
  if(state->count > 3) {
    tap_code16(RGUI(RSFT(KC_L)));
  }
}

void dance_60_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[60].step = dance_step(state);
  switch (dance_state[60].step) {
  case TAP: register_code16(RGUI(RSFT(KC_L))); break;
  case TAP2: register_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L))); break;
  case HOLD2: register_code16(RGUI(RSFT(KC_RIGHT))); break;
  case TAP2_INTERRUPTED: tap_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L)));
  }
}

void dance_60_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[60].step) {
  case TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
  case TAP2: unregister_code16(RGUI(RSFT(KC_L))); break;
  case HOLD2: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
  case TAP2_INTERRUPTED: unregister_code16(RGUI(RSFT(KC_L))); break;
  }
  dance_state[60].step = 0;
}
void on_dance_61(qk_tap_dance_state_t *state, void *user_data);
void dance_61_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_61_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_61(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_GRAVE);
    tap_code16(KC_GRAVE);
    tap_code16(KC_GRAVE);
  }
  if(state->count > 3) {
    tap_code16(KC_GRAVE);
  }
}

void dance_61_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[61].step = dance_step(state);
  switch (dance_state[61].step) {
  case TAP: register_code16(KC_GRAVE); break;
  case HOLD: register_code16(KC_TILD); break;
  case TAP2: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
  case TAP2_INTERRUPTED: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
  }
}

void dance_61_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[61].step) {
  case TAP: unregister_code16(KC_GRAVE); break;
  case HOLD: unregister_code16(KC_TILD); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_GRAVE); break;
  }
  dance_state[61].step = 0;
}
void on_dance_H(qk_tap_dance_state_t *state, void *user_data);
void dance_H_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_H_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_H(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_H);
    tap_code16(KC_H);
    tap_code16(KC_H);
  }
  if(state->count > 3) {
    tap_code16(KC_H);
  }
}

void dance_H_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[62].step = dance_step(state);
  switch (dance_state[62].step) {
  case TAP: register_code16(KC_H); break;
  case HOLD:
    register_key(KC_H); break;
  case HOLD2:
    register_code16(KC_HOME);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_H);
    register_code16(KC_H);
    break;

  }
}

void dance_H_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[62].step) {


  case TAP: unregister_code16(KC_H); break;
  case HOLD2:
    unregister_code16(KC_HOME);
  case HOLD:
    unregister_key(KC_H); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_H);
    break;

  /* case TAP: unregister_code16(KC_H); break; */
  /* case HOLD: unregister_code16(KC_LEFT); break; */
  /* case TAP2: unregister_code16(KC_H); break; */
  /* case TAP2_INTERRUPTED: unregister_code16(KC_H); break; */
  /* case HOLD2:  unregister_code16(RSFT(KC_H));break; */
  }
  dance_state[62].step = 0;
}

void dance_J_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_J_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_J(qk_tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_J, state, user_data);
}

void dance_J_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[63].step = dance_step(state);
  switch (dance_state[63].step) {
  case TAP: register_code16(KC_J); break;
  case HOLD:
    register_key(KC_J); break;
  case TAP2_INTERRUPTED:
    register_code16(KC_J);
    register_code16(KC_J);
    break;


  case HOLD2:
    register_code(KC_4);
    break;
  case TAP2:
    register_code(KC_ESC);  break;
  }
}

void dance_J_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[63].step) {
  case TAP: unregister_code16(KC_J); break;
  case HOLD:
    unregister_key(KC_J); break;

  case TAP2_INTERRUPTED:
    unregister_code16(KC_J);
    break;
  case HOLD2:
    unregister_code(KC_4);
    break;
  case TAP2: unregister_code(KC_ESC);  break;

  }
  dance_state[63].step = 0;
}
void on_dance_64(qk_tap_dance_state_t *state, void *user_data);
void dance_64_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_64_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_64(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_K);
    tap_code16(KC_K);
    tap_code16(KC_K);
  }
  if(state->count > 3) {
    tap_code16(KC_K);
  }
}

void dance_64_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[64].step = dance_step(state);
  switch (dance_state[64].step) {
  case TAP: register_code16(KC_K); break;
  case HOLD:
    register_key(KC_K); break;
  case TAP2: register_code16(KC_K); register_code16(KC_K); break;
  case TAP2_INTERRUPTED: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_64_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[64].step) {
  case TAP: unregister_code16(KC_K); break;
  case HOLD:
    unregister_key(KC_K); break;
  case TAP2: unregister_code16(KC_K); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_K); break;
  }
  dance_state[64].step = 0;
}
void on_dance_65(qk_tap_dance_state_t *state, void *user_data);
void dance_65_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_65_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_65(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_L);
    tap_code16(KC_L);
    tap_code16(KC_L);
  }
  if(state->count > 3) {
    tap_code16(KC_L);
  }
}

void dance_65_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[65].step = dance_step(state);
  switch (dance_state[65].step) {
  case TAP: register_code16(KC_L); break;
  case HOLD:
    register_key(KC_L); break;
  case TAP2: register_code16(KC_L); register_code16(KC_L); break;
  case TAP2_INTERRUPTED: tap_code16(KC_L); register_code16(KC_L);
  }
}

void dance_65_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[65].step) {
  case TAP: unregister_code16(KC_L); break;
  case HOLD:
    unregister_key(KC_L); break;
  case TAP2: unregister_code16(KC_L); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_L); break;
  }
  dance_state[65].step = 0;
}
void on_dance_66(qk_tap_dance_state_t *state, void *user_data);
void dance_66_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_66_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_66(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
  }
  if(state->count > 3) {
    tap_code16(KC_DELETE);
  }
}

void dance_66_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[66].step = dance_step(state);
  switch (dance_state[66].step) {
  case TAP: register_code16(KC_DELETE); break;
  case HOLD: register_code16(KC_DELETE); break;
  case TAP2: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
  case TAP2_INTERRUPTED: tap_code16(KC_DELETE); register_code16(KC_DELETE);
  }
}

void dance_66_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[66].step) {
  case TAP: unregister_code16(KC_DELETE); break;
  case HOLD: unregister_code16(KC_DELETE); break;
  case TAP2: unregister_code16(KC_DELETE); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_DELETE); break;
  }
  dance_state[66].step = 0;
}
void on_dance_67(qk_tap_dance_state_t *state, void *user_data);
void dance_67_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_67_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_67(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_N);
    tap_code16(KC_N);
    tap_code16(KC_N);
  }
  if(state->count > 3) {
    tap_code16(KC_N);
  }
}

void dance_67_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[67].step = dance_step(state);
  switch (dance_state[67].step) {
  case TAP: register_code16(KC_N); break;
  case HOLD: register_key(KC_N); break;
  case TAP2: register_code16(KC_N); register_code16(KC_N); break;
  case TAP2_INTERRUPTED: tap_code16(KC_N); register_code16(KC_N);
  }
}

void dance_67_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[67].step) {
  case TAP: unregister_code16(KC_N); break;
  case HOLD: unregister_key(KC_N); break;
  case TAP2: unregister_code16(KC_N); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_N); break;
  }
  dance_state[67].step = 0;
}
void on_dance_68(qk_tap_dance_state_t *state, void *user_data);
void dance_68_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_68_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_68(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RCTL(KC_HOME));
    tap_code16(RCTL(KC_HOME));
    tap_code16(RCTL(KC_HOME));
  }
  if(state->count > 3) {
    tap_code16(RCTL(KC_HOME));
  }
}

void dance_68_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[68].step = dance_step(state);
  switch (dance_state[68].step) {
  case TAP: register_code16(RCTL(KC_HOME)); break;
  case HOLD: register_code16(RCTL(KC_END)); break;
  case TAP2: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME));
  }
}

void dance_68_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[68].step) {
  case TAP: unregister_code16(RCTL(KC_HOME)); break;
  case HOLD: unregister_code16(RCTL(KC_END)); break;
  case TAP2: unregister_code16(RCTL(KC_HOME)); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_HOME)); break;
  }
  dance_state[68].step = 0;
}


void on_t_alt_tab_h_base(qk_tap_dance_state_t *state, void *user_data);
void t_alt_tab_h_base_finished(qk_tap_dance_state_t *state, void *user_data);
void t_alt_tab_h_base_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_alt_tab_h_base(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(TO(_BASE));
    tap_code16(TO(_BASE));
    tap_code16(TO(_BASE));
  }
  if(state->count > 3) {
    tap_code16(TO(_BASE));
  }
}

void t_alt_tab_h_base_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[70].step = dance_step(state);
  switch (dance_state[70].step) {
  case TAP: register_code16(RCTL(KC_HOME)); break;
  case HOLD: register_code16(RCTL(KC_END)); break;
  case TAP2: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME));
  }
}

void t_alt_tab_h_base_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[70].step) {
  case TAP: unregister_code16(RCTL(KC_HOME)); break;
  case HOLD: unregister_code16(RCTL(KC_END)); break;
  case TAP2: unregister_code16(RCTL(KC_HOME)); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_HOME)); break;
  }
  dance_state[70].step = 0;
}

void on_only_n(qk_tap_dance_state_t *state, void *user_data);
void only_n_finished(qk_tap_dance_state_t *state, void *user_data);
void only_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_only_n(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_N);
    tap_code16(KC_N);
    tap_code16(KC_N);
  }
  if(state->count > 3) {
    tap_code16(KC_N);
  }
}

void only_n_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[69].step = dance_step(state);
  switch (dance_state[69].step) {
  case TAP: register_code16(KC_N); break;
  case HOLD: register_key(KC_N); break;
  case TAP2: register_code16(KC_N); register_code16(KC_N); break;
  case TAP2_INTERRUPTED: tap_code16(KC_N); register_code16(KC_N);
  }
}

void only_n_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[69].step) {
  case TAP: unregister_code16(KC_N); break;
  case HOLD: unregister_key(KC_N); break;
  case TAP2: unregister_code16(KC_N); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_N); break;
  }
  dance_state[69].step = 0;
}

void on_dance_69(qk_tap_dance_state_t *state, void *user_data);
void dance_69_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_69_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_69(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_N);
    tap_code16(KC_N);
    tap_code16(KC_N);
  }
  if(state->count > 3) {
    tap_code16(KC_N);
  }
}

void dance_69_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[29].step = dance_step(state);
  switch (dance_state[29].step) {
  case TAP: register_code16(KC_N); break;
  case HOLD: register_key(KC_N); break;
  case TAP2: register_code16(KC_N); register_code16(KC_N); break;
  case TAP2_INTERRUPTED: tap_code16(KC_N); register_code16(KC_N);
  }
}

void dance_69_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[29].step) {
  case TAP: unregister_code16(KC_N); break;
  case HOLD: unregister_key(KC_N); break;
  case TAP2: unregister_code16(KC_N); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_N); break;
  }
  dance_state[29].step = 0;
}

void on_t_lbrc_h_alt(qk_tap_dance_state_t *state, void *user_data);
void t_lbrc_h_alt_finished(qk_tap_dance_state_t *state, void *user_data);
void t_lbrc_h_alt_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_lbrc_h_alt(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_LCBR);
    tap_code16(KC_LCBR);
    tap_code16(KC_LCBR);
  }
  if(state->count > 3) {
    tap_code16(KC_LCBR);
  }
}

void t_lbrc_h_alt_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[71].step = dance_step(state);
  switch (dance_state[71].step) {
  case TAP: register_code16(KC_LCBR); break;
  case HOLD: register_code16(KC_RALT); break;
  case TAP2: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
  case TAP2_INTERRUPTED: tap_code16(KC_LCBR); register_code16(KC_LCBR);
  }
}

void t_lbrc_h_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[71].step) {
  case TAP: unregister_code16(KC_LCBR); break;
  case HOLD: unregister_code16(KC_RALT); break;
  case TAP2: unregister_code16(KC_LCBR); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_LCBR); break;
  }
  dance_state[71].step = 0;
}


void on_dance_73(qk_tap_dance_state_t *state, void *user_data);
void dance_73_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_73_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_73(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_PSCREEN);
    tap_code16(KC_PSCREEN);
    tap_code16(KC_PSCREEN);
  }
  if(state->count > 3) {
    tap_code16(KC_PSCREEN);
  }
}

void dance_73_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[73].step = dance_step(state);
  switch (dance_state[73].step) {
  case TAP: register_code16(KC_PSCREEN); break;
  case HOLD: register_code16(KC_PSCREEN); break;
  case TAP2: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break;
  case HOLD2: register_code16(RGUI(KC_PSCREEN)); break;
  case TAP2_INTERRUPTED: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN);
  }
}

void dance_73_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[73].step) {
  case TAP: unregister_code16(KC_PSCREEN); break;
  case HOLD: unregister_code16(KC_PSCREEN); break;
  case TAP2: unregister_code16(KC_PSCREEN); break;
  case HOLD2: unregister_code16(RGUI(KC_PSCREEN)); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_PSCREEN); break;
  }
  dance_state[73].step = 0;
}


void on_dance_V(qk_tap_dance_state_t *state, void *user_data);
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_V_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_V(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_V);
    tap_code16(KC_V);
    tap_code16(KC_V);
  }
  if(state->count > 3) {
    tap_code16(KC_V);
  }
}

void dance_V_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[74].step = dance_step(state);
  switch (dance_state[74].step) {
  case TAP: register_code16(KC_V); break;
  case HOLD:
    register_key(KC_V);
 break;
  case TAP2: register_code16(KC_V); register_code16(KC_V); break;
  case HOLD2: layer_on(_AUDIO); break;
  case TAP2_INTERRUPTED: tap_code16(KC_V); register_code16(KC_V);
  }
}

void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[74].step) {
  case TAP: unregister_code16(KC_V); break;
  case HOLD:  unregister_key( KC_V ); break;
  case HOLD2:  layer_off(_AUDIO);  break;
  case TAP2: unregister_code16(KC_V); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_V); break;
  }
  dance_state[74].step = 0;
}


void on_dance_z(qk_tap_dance_state_t *state, void *user_data);
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_z(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Z);
    tap_code16(KC_Z);
    tap_code16(KC_Z);
  }
  if(state->count > 3) {
    tap_code16(KC_Z);
  }
}

void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
  case TAP: register_code16(KC_Z); break;
  case HOLD:
  case HOLD2:
    register_key(KC_Z);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_Z);
    register_code16(KC_Z);

  }
}

void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case TAP: unregister_code16(KC_Z); break;
  case HOLD:
  case HOLD2:
    unregister_key(KC_Z);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_Z);
    break;

  }
  dance_state[76].step = 0;
}



void on_windows_or_alt_tab(qk_tap_dance_state_t *state, void *user_data);
void windows_or_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void windows_or_alt_tab_reset(qk_tap_dance_state_t *state, void *user_data);


void on_windows_or_alt_tab(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_RGUI);
    tap_code16(KC_RGUI);
    tap_code16(KC_RGUI);
  }
  if(state->count > 3) {
    tap_code16(KC_RGUI);
  }
}

void windows_or_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
  case TAP: layer_on(_WINDOWS); break;
  case HOLD: register_code16(KC_RGUI) ; break;
  case TAP2: register_code16(KC_RGUI); register_code16(KC_RGUI); break;
    /* case TAP2: register_code16(ALT_TAB); break; */
  case HOLD2: register_code16(KC_RGUI) ; break;
  case TAP2_INTERRUPTED: tap_code16(KC_RGUI); register_code16(KC_RGUI);
  }
}

void windows_or_alt_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case TAP: layer_off(_WINDOWS); break;
  case HOLD: unregister_code16( KC_RGUI ); break;
    /* case TAP2: unregister_code16(ALT_TAB); break; */
  case TAP2: unregister_code16(KC_RGUI); break;
  case HOLD2: unregister_code16(KC_RGUI) ;break;
  case TAP2_INTERRUPTED: unregister_code16(KC_RGUI); break;
  }
  dance_state[76].step = 0;
}

void on_dance_B(qk_tap_dance_state_t *state, void *user_data);
void dance_B_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_B_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_B(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_B);
    tap_code16(KC_B);
    tap_code16(KC_B);
  }
  if(state->count > 3) {
    tap_code16(KC_B);
  }
}

void dance_B_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
  case TAP: register_code16(KC_B); break;
  case HOLD:
    register_key(KC_B);
    break;
  case TAP2: register_code16(KC_B); register_code16(KC_B); break;
  case HOLD2: layer_on(_BRIGHTNESS); break;
  case TAP2_INTERRUPTED: tap_code16(KC_B); register_code16(KC_B);
  }
}

void dance_B_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case TAP: unregister_code16(KC_B); break;
  case HOLD:  unregister_key( KC_B ); break;
  case HOLD2:  layer_off(_BRIGHTNESS);  break;
  case TAP2_INTERRUPTED: unregister_code16(KC_B); break;
  case TAP2: unregister_code16(KC_B); break;
  }
  dance_state[76].step = 0;
}

void on_dance_C(qk_tap_dance_state_t *state, void *user_data);
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_C_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_C(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_C);
    tap_code16(KC_C);
    tap_code16(KC_C);
  }
  if(state->count > 3) {
    tap_code16(KC_C);
  }
}

void dance_C_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[77].step = dance_step(state);
  switch (dance_state[77].step) {
  case TAP: register_code16(KC_C); break;
  case HOLD:
    register_key(KC_C);
    break;

  case HOLD2:
    register_code16(LSFT (KC_C));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_C);
    register_code16(KC_C);
    break;

  }
}

void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[77].step) {
  case TAP: unregister_code16(KC_C); break;
  case HOLD:
  case HOLD2:
    unregister_code16(LSFT (KC_C));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_C);
    break;
  }
  dance_state[77].step = 0;
}

void on_dance_D(qk_tap_dance_state_t *state, void *user_data);
void dance_D_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_D_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_D(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_D);
    tap_code16(KC_D);
    tap_code16(KC_D);
  }
  if(state->count > 3) {
    tap_code16(KC_D);
  }
}

void dance_D_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[78].step = dance_step(state);
  switch (dance_state[78].step) {
  case TAP: register_code16(KC_D); break;
  case HOLD:
    register_key(KC_D); break;
  case HOLD2:
    register_code16(LSFT (KC_D));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_D);
    register_code16(KC_D);
    break;
  }
}

void dance_D_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[78].step) {
  case TAP: unregister_code16(KC_D); break;
  case HOLD:
    unregister_key(KC_D); break;
  case HOLD2:
    unregister_code16(LSFT (KC_D));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_D);
    break;
  }
  dance_state[78].step = 0;
}

void on_dance_E(qk_tap_dance_state_t *state, void *user_data);
void dance_E_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_E_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_E(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_E);
    tap_code16(KC_E);
    tap_code16(KC_E);
  }
  if(state->count > 3) {
    tap_code16(KC_E);
  }
}

void dance_E_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {

  case TAP: register_code16(KC_E); break;
  case HOLD:
    register_key(KC_E); break;
  case HOLD2:
    tap_code16(LCTL (KC_E));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_E);
    register_code16(KC_E);
    break;

  }
}

void dance_E_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {

  case TAP: unregister_code16(KC_E); break;
  case HOLD:
    unregister_key(KC_E); break;
  case HOLD2:
    unregister_code16(LCTL (KC_E));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_E);
    break;
  }
  dance_state[3].step = 0;
}

void on_dance_F(qk_tap_dance_state_t *state, void *user_data);
void dance_F_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_F_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_F(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F);
    tap_code16(KC_F);
    tap_code16(KC_F);
  }
  if(state->count > 3) {
    tap_code16(KC_F);
  }
}

void dance_F_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[14].step = dance_step(state);
  switch (dance_state[14].step) {
  case TAP: register_code16(KC_F); break;
  case HOLD:
    register_key(KC_F); break;
  case HOLD2:
    register_code16(LSFT (KC_F));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_F);
    register_code16(KC_F);
    break;
  }
}

void dance_F_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[14].step) {
  case TAP: unregister_code16(KC_F); break;
  case HOLD:
    unregister_key(KC_F); break;
  case HOLD2:
    unregister_code16(LSFT (KC_F));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_F);
    break;
  }
  dance_state[14].step = 0;
}

void on_dance_G(qk_tap_dance_state_t *state, void *user_data);
void dance_G_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_G_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_G(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_G);
    tap_code16(KC_G);
    tap_code16(KC_G);
  }
  if(state->count > 3) {
    tap_code16(KC_G);
  }
}

void dance_G_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[15].step = dance_step(state);
  switch (dance_state[15].step) {
  case TAP: register_code16(KC_G); break;
  case HOLD:
    register_key(KC_G); break;
  case HOLD2:
    tap_code16(RCTL(LALT(LGUI(KC_G))));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_G);
    register_code16(KC_G);
    break;
  }
}

void dance_G_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[15].step) {
  case TAP: unregister_code16(KC_G); break;
  case HOLD:
    unregister_key(KC_G); break;
  case HOLD2:
    unregister_code16(LSFT (KC_G));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_G);
    break;

  }
  dance_state[15].step = 0;
}



void on_dance_X(qk_tap_dance_state_t *state, void *user_data);
void dance_X_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_X_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_X(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_X);
    tap_code16(KC_X);
    tap_code16(KC_X);
  }
  if(state->count > 3) {
    tap_code16(KC_X);
  }
}

void dance_X_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[79].step = dance_step(state);
  switch (dance_state[79].step) {
  case TAP: register_code16(KC_X); break;
  case HOLD:
    register_key(KC_X); break;
  case HOLD2:
    register_code16(LSFT (KC_X));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_X);
    register_code16(KC_X);
    break;
  }
}

void dance_X_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[79].step) {
  case TAP: unregister_code16(KC_X); break;
  case HOLD:
    unregister_key(KC_X); break;
  case HOLD2:
    unregister_code16(LSFT (KC_X));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_X);
    break;
  }
  dance_state[79].step = 0;
}


void on_dance_save_load_ns_switch(qk_tap_dance_state_t *state, void *user_data);
void dance_save_load_ns_switch_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_save_load_ns_switch_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_save_load_ns_switch(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_save_load_ns_switch_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[83].step = dance_step(state);
  switch (dance_state[83].step) {
  case TAP: register_code16(RCTL(KC_SCOLON)); break;
  case HOLD:
    tap_code16(RCTL(KC_SCOLON));
    tap_code16(RCTL(KC_C));
    tap_code16(RCTL(KC_K));
 break;
  default:
    register_code16(RCTL(KC_QUOT));
    break;
  }
}

void dance_save_load_ns_switch_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[83].step) {
  case TAP: unregister_code16(RCTL(KC_SCOLON)); break;
  /* case HOLD: */
  /*   tap_code16(RCTL(KC_SCOLON)); */
  /*   tap_code16(RCTL(KC_C)); */
  /*   tap_code16(RCTL(KC_K)); */
    /* break; */
  default:
    unregister_code16(RCTL(KC_QUOT));
    break;

  }
  dance_state[83].step = 0;
}


void on_dance_min_or_exit(qk_tap_dance_state_t *state, void *user_data);
void dance_min_or_exit_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_min_or_exit_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_min_or_exit(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_X);
    tap_code16(KC_X);
    tap_code16(KC_X);
  }
  if(state->count > 3) {
    tap_code16(KC_X);
  }
}

void dance_min_or_exit_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[80].step = dance_step(state);
  switch (dance_state[80].step) {
  case TAP: register_code16(KC_X); break;
  case HOLD: register_code16(KC_X); break;
  case TAP2: register_code16(KC_X); register_code16(KC_X); break;
  case HOLD2: register_code16(LSFT (KC_X)); break;
  case TAP2_INTERRUPTED: tap_code16(KC_X); register_code16(KC_X);
  }
}

void dance_min_or_exit_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[80].step) {
  case TAP: unregister_code16(KC_X); break;
  case HOLD:  unregister_code16(KC_X); break;
  case TAP2: unregister_code16(KC_X); break;
  case HOLD2: unregister_code16(LSFT (KC_X)); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_X); break;
  }
  dance_state[80].step = 0;
}
void on_preonic_Z(qk_tap_dance_state_t *state, void *user_data);
void preonic_Z_finished(qk_tap_dance_state_t *state, void *user_data);
void preonic_Z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_preonic_Z(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Z);
    tap_code16(KC_Z);
    tap_code16(KC_Z);
  }
  if(state->count > 3) {
    tap_code16(KC_Z);
  }
}

void preonic_Z_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[82].step = dance_step(state);
  switch (dance_state[82].step) {
  case TAP: register_code16(KC_Z); break;
  case HOLD:
  case HOLD2:
    register_code16(LSFT (KC_Z));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_Z);
    register_code16(KC_Z);
    break;
  }
}

void preonic_Z_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[82].step) {
  case TAP: unregister_code16(KC_Z); break;
  case HOLD:
  case HOLD2:
    unregister_code16(LSFT (KC_Z));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_Z);
    break;
  }
  dance_state[82].step = 0;
}


void on_dance_mic(qk_tap_dance_state_t *state, void *user_data);
void dance_mic_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_mic_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_mic(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_mic_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[84].step = dance_step(state);
  switch (dance_state[84].step) {
  case TAP:
    tap_code16(RCTL(RALT(RGUI(KC_DOWN))));
    break;
  case HOLD:
    tap_code16(RCTL(RALT(RGUI(KC_UP))));
 break;
  }
}

void dance_mic_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[84].step = 0;
}


void on_dance_shift(qk_tap_dance_state_t *state, void *user_data);
void dance_shift_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_shift_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_shift(qk_tap_dance_state_t *state, void *user_data) {}

void dance_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case HOLD2:
    layer_move(_SHIFTLOCK);
    PLAY_SONG(caps_lock_on_sound);
    break;

  case TAP3:
    /* tap_code16(AUTOSHIFT_TOGGLE); */
    caps_word_on();
    break;

  default:
    register_code16(KC_LSFT);
    break;
  }
}

void dance_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[85].step = 0;
  unregister_code16(KC_LSFT);
}


void on_dance_super(qk_tap_dance_state_t *state, void *user_data);
void dance_super_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_super_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_super(qk_tap_dance_state_t *state, void *user_data) {}

void dance_super_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case TAP:
    /* set_oneshot_layer(_WINDOWS, null); */
    /* OSL(_WINDOWS); */
    break;
  case HOLD2:
    /* layer_move(_SUPERLOCK); */
    PLAY_SONG(caps_lock_on_sound);
    break;

  case TAP3:
    tap_code16(AUTOSHIFT_TOGGLE);
    break;

  default:
    /* register_code16(KC_LSFT); */
    break;
  }
}

void dance_super_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[85].step = 0;
  unregister_code16(KC_LSFT);
}



void on_dance_f5(qk_tap_dance_state_t *state, void *user_data);
void dance_f5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_f5(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_f5_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[86].step = dance_step(state);
  switch (dance_state[86].step) {
  case TAP: tap_code16(KC_F5); break;
  case HOLD:
    tap_code16(LCTL(KC_F5)); break;
  default:
    register_code16(KC_F5);
    break;
  }
}

void dance_f5_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[86].step) {
  /* case TAP: unregister_code16(RCTL(KC_SCOLON)); break; */
  /* case HOLD: */
  /*   tap_code16(RCTL(KC_SCOLON)); */
  /*   tap_code16(RCTL(KC_C)); */
  /*   tap_code16(RCTL(KC_K)); */
    /* break; */
  default:
    unregister_code16(KC_F5);
    break;

  }
  dance_state[86].step = 0;
}


void on_dance_windows_i(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_i_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_i_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_windows_i(qk_tap_dance_state_t *state, void *user_data) {}

void dance_windows_i_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[87].step = dance_step(state);
  switch (dance_state[87].step) {
  case HOLD:
    tap_code16(KC_8);
  case TAP:
    tap_code16(KC_I);
    break;
  }
}

void dance_windows_i_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[87].step = 0;
}

void on_dance_windows_o(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_o_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_o_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_windows_o(qk_tap_dance_state_t *state, void *user_data) {}

void dance_windows_o_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[88].step = dance_step(state);
  switch (dance_state[88].step) {
  case HOLD:
    tap_code16(KC_9);
  case TAP:
    tap_code16(KC_O);
    break;
  }
}

void dance_windows_o_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    dance_state[88].step = 0;
}


void on_dance_windows_p(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_p_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_p_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_windows_p(qk_tap_dance_state_t *state, void *user_data) {}

void dance_windows_p_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[89].step = dance_step(state);
  switch (dance_state[89].step) {
  case HOLD:
    tap_code16(KC_0);
  case TAP:
    tap_code16(KC_P);
    break;
  }
}

void dance_windows_p_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    dance_state[89].step = 0;
}


void on_dance_windows_u(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_u_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_windows_u_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_windows_u(qk_tap_dance_state_t *state, void *user_data) {}

void dance_windows_u_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[90].step = dance_step(state);
  switch (dance_state[90].step) {
  case HOLD:
    tap_code16(KC_7);
  case TAP:
    tap_code16(KC_U);
    break;
  }
}

void dance_windows_u_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    dance_state[90].step = 0;
}


#include "apl_tapdance.c"

qk_tap_dance_action_t tap_dance_actions[] = {
                                             [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_tab, dance_tab_finished, dance_tab_reset),
                                             [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
                                             [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_W, dance_W_finished, dance_W_reset),
                                             [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset),
                                             [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
                                             [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset),
                                             [DANCE_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U, dance_U_finished, dance_U_reset),
                                             [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset),
                                             [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset),
                                             [DANCE_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_P, dance_P_finished, dance_P_reset),
                                             [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
                                             [PREONIC_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_preonic_A, preonic_A_finished, preonic_A_reset),
                                             [PREONIC_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_preonic_Z, preonic_Z_finished, preonic_Z_reset),
                                             [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
                                             [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
                                             [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
                                             [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
                                             [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset),
                                             [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset),
                                             [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
                                             [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset),
                                             [DANCE_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_space, dance_space_finished, dance_space_reset),
                                             [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
                                             [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
                                             [WWW_BACK_FORWARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_www_back_forward, www_back_forward_finished, www_back_forward_reset),
                                             [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
                                             [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
                                             [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
                                             [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
                                             [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
                                             [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
                                             [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
                                             [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
                                             [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
                                             [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
                                             [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
                                             [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
                                             [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
                                             [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
                                             [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
                                             [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
                                             [DANCE_WINDOWS_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_n, dance_windows_n_finished, dance_windows_n_reset),
                                             [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
                                             [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
                                             [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
                                             [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
                                             [DANCE_51] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_51_finished, dance_51_reset),
                                             [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_52, dance_52_finished, dance_52_reset),
                                             [DANCE_53] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_53, dance_53_finished, dance_53_reset),
                                             [DANCE_54] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_54, dance_54_finished, dance_54_reset),
                                             [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
                                             [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
                                             [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_57_finished, dance_57_reset),
                                             [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
                                             [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset),
                                             [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset),
                                             [DANCE_61] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_61, dance_61_finished, dance_61_reset),
                                             [DANCE_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_H, dance_H_finished, dance_H_reset),
                                             [DANCE_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_J, dance_J_finished, dance_J_reset),
                                             [DANCE_64] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_64, dance_64_finished, dance_64_reset),
                                             [DANCE_65] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_65, dance_65_finished, dance_65_reset),
                                             [DANCE_66] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_66, dance_66_finished, dance_66_reset),
                                             [DANCE_67] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_67, dance_67_finished, dance_67_reset),
                                             [DANCE_68] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_68, dance_68_finished, dance_68_reset),
                                             [DANCE_69] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_69, dance_69_finished, dance_69_reset),
                                             [ONLY_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_only_n, only_n_finished, only_n_reset),
                                             [T_LCRB_H_ALT]  = ACTION_TAP_DANCE_FN_ADVANCED(on_t_lbrc_h_alt, t_lbrc_h_alt_finished, t_lbrc_h_alt_reset),
                                             [T_ALT_TAB_H_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_alt_tab_h_base, t_alt_tab_h_base_finished, t_alt_tab_h_base_reset),
                                             [DANCE_73] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_73, dance_73_finished, dance_73_reset),
                                             [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_V, dance_V_finished, dance_V_reset),
                                             [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
                                             [WINDOWS_OR_ALT_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_windows_or_alt_tab, windows_or_alt_tab_finished, windows_or_alt_tab_reset),
                                             [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset),
                                             [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
                                             [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
                                             [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
                                             [DANCE_PAREN_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_pb, dance_pb_finished, dance_pb_reset),
                                             [DANCE_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_comma, dance_comma_finished, dance_comma_reset),
                                             [DANCE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_dot, dance_dot_finished, dance_dot_reset),

                                             [DANCE_MIN_OR_EXIT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_min_or_exit, dance_min_or_exit_finished, dance_min_or_exit_reset),
                                             [DANCE_SAVE_LOAD_NS_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_save_load_ns_switch, dance_save_load_ns_switch_finished, dance_save_load_ns_switch_reset),
                                             [DANCE_F5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f5, dance_f5_finished, dance_f5_reset),
                                             [DANCE_MIC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_mic, dance_mic_finished, dance_mic_reset),
                                             [DANCE_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift, dance_shift_finished, dance_shift_reset),
                                             [DANCE_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_super, dance_super_finished, dance_super_reset),

                                             [DANCE_WINDOWS_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_u, dance_windows_u_finished, dance_windows_u_reset),

                                             [DANCE_WINDOWS_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_i, dance_windows_i_finished, dance_windows_i_reset),
                                             [DANCE_WINDOWS_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_o, dance_windows_o_finished, dance_windows_o_reset),
                                             [DANCE_WINDOWS_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_p, dance_windows_p_finished, dance_windows_p_reset),

};
