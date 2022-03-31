enum tap_dance_codes {
                      DANCE_0,
                      DANCE_Q,
                      DANCE_W,
                      DANCE_E,
                      DANCE_R,
                      DANCE_T,
                      DANCE_U,
                      DANCE_I,
                      DANCE_O,
                      DANCE_P,
                      DANCE_A,
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
                      DANCE_23,
                      DANCE_24,
                      DANCE_25,
                      DANCE_26,
                      DANCE_27,
                      DANCE_28,
                      DANCE_29,
                      DANCE_30,
                      DANCE_31,
                      DANCE_32,
                      DANCE_33,
                      DANCE_34,
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
                      DANCE_46,
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
                      SUPER_WINDOWS,
                      Z_OR_SHIFT,
                      WINDOWS_OR_ALT_TAB,
                      DANCE_B,
                      DANCE_C,
                      DANCE_D,
                      DANCE_X,
                      DANCE_MIN_OR_EXIT,
                      DANCE_EXLM,
                      DANCE_AT,
                      DANCE_HASH,
                      DANCE_DLR,
                      DANCE_PERC,
                      DANCE_CIRC,
                      DANCE_AMPR,
                      DANCE_ASTR,
                      DANCE_LPRN,
                      DANCE_RPRN,
};

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
      SINGLE_TAP = 1,
      SINGLE_HOLD,
      DOUBLE_TAP,
      DOUBLE_HOLD,
      DOUBLE_SINGLE_TAP,
      TRIPLE_TAP,
      TRIPLE_HOLD,
      TRIPLE_SINGLE_TAP,
      MORE_TAPS
};

static tap dance_state[100];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }

  } else if (state->count == 2) {
    if (state->interrupted) {
      return DOUBLE_SINGLE_TAP;
    } else if (state->pressed) {
      return DOUBLE_HOLD;
    } else {
      return DOUBLE_TAP;
    }

  }
  else if (state->count == 3) {
    if (state->interrupted) {
      return TRIPLE_SINGLE_TAP;
    } else if (state->pressed) {
      return TRIPLE_HOLD;
    } else {
      return TRIPLE_TAP;
    }
  }
  return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
  }
  if(state->count > 3) {
    tap_code16(KC_TAB);
  }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
    /* case SINGLE_HOLD: layer_on(6); break; */
  case SINGLE_HOLD:
    register_code16(KC_LCTL);
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_BLUE);
    break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case SINGLE_HOLD:
    unregister_code16(KC_LCTL);
    rgblight_disable();
    break;
    /* case SINGLE_HOLD: layer_off(6); break; */
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
  }
  dance_state[0].step = 0;
}
void on_dance_Q(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Q(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Q);
    tap_code16(KC_Q);
    tap_code16(KC_Q);
  }
  if(state->count > 3) {
    tap_code16(KC_Q);
  }
}

void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_Q); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_Q));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_Q);
    register_code16(KC_Q);
    break;
  }
}

void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[1].step) {
  case SINGLE_TAP: unregister_code16(KC_Q); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_Q));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_Q);
    break;
  }
  dance_state[1].step = 0;
}

void on_dance_W(qk_tap_dance_state_t *state, void *user_data);
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_W_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_W(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_W);
    tap_code16(KC_W);
    tap_code16(KC_W);
  }
  if(state->count > 3) {
    tap_code16(KC_W);
  }
}

void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
  case SINGLE_TAP: register_code16(KC_W); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_W));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_W);
    register_code16(KC_W);
    break;

  }
}

void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[2].step) {
  case SINGLE_TAP: unregister_code16(KC_W); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_W));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_W);
    break;

  }
  dance_state[2].step = 0;
}

void on_dance_R(qk_tap_dance_state_t *state, void *user_data);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_R(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_R);
    tap_code16(KC_R);
    tap_code16(KC_R);
  }
  if(state->count > 3) {
    tap_code16(KC_R);
  }
}

void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
  case SINGLE_TAP: register_code16(KC_R); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_R));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_R);
    register_code16(KC_R);
  }
}

void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
  case SINGLE_TAP: unregister_code16(KC_R); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_R));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_R);
    break;

  }
  dance_state[4].step = 0;
}
void on_dance_T(qk_tap_dance_state_t *state, void *user_data);
void dance_T_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_T_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_T(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_T);
    tap_code16(KC_T);
    tap_code16(KC_T);
  }
  if(state->count > 3) {
    tap_code16(KC_T);
  }
}

void dance_T_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
  case SINGLE_TAP: register_code16(KC_T); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_T));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_T);
    register_code16(KC_T);
    break;
  }
}

void dance_T_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
  case SINGLE_TAP: unregister_code16(KC_T); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_T));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_T);
    break;
  }
  dance_state[5].step = 0;
}


void on_dance_U(qk_tap_dance_state_t *state, void *user_data);
void dance_U_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_U_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_U(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_U);
    tap_code16(KC_U);
    tap_code16(KC_U);
  }
  if(state->count > 3) {
    tap_code16(KC_U);
  }
}

void dance_U_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
  case SINGLE_TAP: register_code16(KC_U); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_U));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_U);
    register_code16(KC_U);
    break;
  }
}

void dance_U_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
  case SINGLE_TAP: unregister_code16(KC_U); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_U));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_U);
    break;
  }
  dance_state[6].step = 0;
}
void on_dance_I(qk_tap_dance_state_t *state, void *user_data);
void dance_I_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_I_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_I(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_I);
    tap_code16(KC_I);
    tap_code16(KC_I);
  }
  if(state->count > 3) {
    tap_code16(KC_I);
  }
}

void dance_I_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
  case SINGLE_TAP: register_code16(KC_I); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_I));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_I);
    register_code16(KC_I);
    break;

  }
}

void dance_I_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
  case SINGLE_TAP: unregister_code16(KC_I); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_I));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_I);
    break;
  }
  dance_state[7].step = 0;
}

void on_dance_O(qk_tap_dance_state_t *state, void *user_data);
void dance_O_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_O_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_O(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_O);
    tap_code16(KC_O);
    tap_code16(KC_O);
  }
  if(state->count > 3) {
    tap_code16(KC_O);
  }
}

void dance_O_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[8].step = dance_step(state);
  switch (dance_state[8].step) {

  case SINGLE_TAP: register_code16(KC_O); break;
  case SINGLE_HOLD:
    register_code16(LSFT (KC_O));
    break;

  case DOUBLE_HOLD:
    register_code16(KC_END);
    break;

  case DOUBLE_SINGLE_TAP:
  case DOUBLE_TAP:
    register_code16(KC_O);
    register_code16(KC_O);
    break;

  }
}

void dance_O_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[8].step) {
  case SINGLE_TAP: unregister_code16(KC_O); break;
  case SINGLE_HOLD:
    unregister_code16(LSFT (KC_O));
    break;

  case DOUBLE_HOLD:
    unregister_code16(KC_END);
    break;

  case DOUBLE_SINGLE_TAP:
  case DOUBLE_TAP:
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
  if(state->count == 3) {
    tap_code16(KC_P);
    tap_code16(KC_P);
    tap_code16(KC_P);
  }
  if(state->count > 3) {
    tap_code16(KC_P);
  }
}

void dance_P_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[9].step = dance_step(state);
  switch (dance_state[9].step) {
  case SINGLE_TAP: register_code16(KC_P); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_P));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_P);
    register_code16(KC_P);
    break;

  }
}

void dance_P_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[9].step) {
  case SINGLE_TAP: unregister_code16(KC_P); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_P));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_P);
    break;

  }
  dance_state[9].step = 0;
}

void on_dance_A(qk_tap_dance_state_t *state, void *user_data);
void dance_A_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_A_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_A(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_A);
    tap_code16(KC_A);
    tap_code16(KC_A);
  }
  if(state->count > 3) {
    tap_code16(KC_A);
  }
}

void dance_A_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[11].step = dance_step(state);
  switch (dance_state[11].step) {
  case SINGLE_TAP: register_code16(KC_A); break;
  case SINGLE_HOLD:
    register_code16(KC_RCTL);break;
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_A));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_A);
    register_code16(KC_A);
    break;
  }
}

void dance_A_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[11].step) {
  case SINGLE_TAP: unregister_code16(KC_A); break;
  case SINGLE_HOLD:
    unregister_code16(KC_RCTL);break;
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_A));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_A);
    break;
  }
  dance_state[11].step = 0;
}


void on_dance_S(qk_tap_dance_state_t *state, void *user_data);
void dance_S_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_S_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_S(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_S);
    tap_code16(KC_S);
    tap_code16(KC_S);
  }
  if(state->count > 3) {
    tap_code16(KC_S);
  }
}

void dance_S_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[12].step = dance_step(state);
  switch (dance_state[12].step) {
  case SINGLE_TAP: register_code16(KC_S); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_S));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_S);
    register_code16(KC_S);
    break;
  }
}

void dance_S_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[12].step) {
  case SINGLE_TAP: unregister_code16(KC_S); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_S));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_S);
    break;
  }
  dance_state[12].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_D);
    tap_code16(KC_D);
    tap_code16(KC_D);
  }
  if(state->count > 3) {
    tap_code16(KC_D);
  }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[13].step = dance_step(state);
  switch (dance_state[13].step) {
  case SINGLE_TAP: register_code16(KC_D); break;
  case SINGLE_HOLD: register_code16(KC_D); break;
  case DOUBLE_TAP: register_code16(KC_D); register_code16(KC_D); break;
  case DOUBLE_HOLD: register_code16(KC_8); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_D); register_code16(KC_D);
  }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[13].step) {
  case SINGLE_TAP: unregister_code16(KC_D); break;
  case SINGLE_HOLD: unregister_code16(KC_D); break;
  case DOUBLE_TAP: unregister_code16(KC_D); break;
  case DOUBLE_HOLD: unregister_code16(KC_8); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_D); break;
  }
  dance_state[13].step = 0;
}



void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_J);
    tap_code16(KC_J);
    tap_code16(KC_J);
  }
  if(state->count > 3) {
    tap_code16(KC_J);
  }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[16].step = dance_step(state);
  switch (dance_state[16].step) {
  case SINGLE_TAP: register_code16(KC_J); break;
  case SINGLE_HOLD: register_code16(KC_J); break;
  case DOUBLE_TAP: register_code16(KC_ESC); break;
  case DOUBLE_HOLD: register_code16(KC_DLR); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
  }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[16].step) {
  case SINGLE_TAP: unregister_code16(KC_J); break;
  case SINGLE_HOLD: unregister_code16(KC_J); break;
  case DOUBLE_TAP: unregister_code16(KC_ESC); break;
  case DOUBLE_HOLD: unregister_code16(KC_DLR); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
  }
  dance_state[16].step = 0;
}

void on_dance_K(qk_tap_dance_state_t *state, void *user_data);
void dance_K_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_K_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_K(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_K);
    tap_code16(KC_K);
    tap_code16(KC_K);
  }
  if(state->count > 3) {
    tap_code16(KC_K);
  }
}

void dance_K_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[17].step = dance_step(state);
  switch (dance_state[17].step) {
  case SINGLE_TAP: register_code16(KC_K); break;
  case SINGLE_HOLD: register_code16(RSFT(KC_K)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_SCOLON)); break;
  case DOUBLE_HOLD: register_code16(KC_UP); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_K_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[17].step) {
  case SINGLE_TAP: unregister_code16(KC_K); break;
  case SINGLE_HOLD: unregister_code16(RSFT(KC_K)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_SCOLON)); break;
  case DOUBLE_HOLD: unregister_code16(KC_UP); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
  }
  dance_state[17].step = 0;
}
void on_dance_L(qk_tap_dance_state_t *state, void *user_data);
void dance_L_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_L_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_L(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_L);
    tap_code16(KC_L);
    tap_code16(KC_L);
  }
  if(state->count > 3) {
    tap_code16(KC_L);
  }
}

void dance_L_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[18].step = dance_step(state);
  switch (dance_state[18].step) {
  case SINGLE_TAP: register_code16(KC_L); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_L));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_L);
    register_code16(KC_L);
    break;

  }
}

void dance_L_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[18].step) {


  case SINGLE_TAP: unregister_code16(KC_L); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_L));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_L);
    break;
  }
  dance_state[18].step = 0;
}

void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_SCOLON);
    tap_code16(KC_SCOLON);
    tap_code16(KC_SCOLON);
  }
  if(state->count > 3) {
    tap_code16(KC_SCOLON);
  }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[19].step = dance_step(state);
  switch (dance_state[19].step) {
  case SINGLE_TAP: register_code16(KC_SCOLON); break;
  case SINGLE_HOLD: register_code16(KC_COLN); break;
  case DOUBLE_TAP: register_code16(KC_SCOLON); register_code16(KC_SCOLON); break;
  case DOUBLE_HOLD: register_code16(KC_SCOLON); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
  }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[19].step) {
  case SINGLE_TAP: unregister_code16(KC_SCOLON); break;
  case SINGLE_HOLD: unregister_code16(KC_COLN); break;
  case DOUBLE_TAP: unregister_code16(KC_SCOLON); break;
  case DOUBLE_HOLD: unregister_code16(KC_SCOLON); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCOLON); break;
  }
  dance_state[19].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_QUOTE);
    tap_code16(KC_QUOTE);
    tap_code16(KC_QUOTE);
  }
  if(state->count > 3) {
    tap_code16(KC_QUOTE);
  }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[20].step = dance_step(state);
  switch (dance_state[20].step) {
  case SINGLE_TAP: register_code16(KC_QUOTE); break;
  case SINGLE_HOLD: register_code16(KC_DQUO); break;
  case DOUBLE_TAP: register_code16(KC_QUOTE); break;
  case DOUBLE_HOLD: register_code16(KC_QUOTE); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
  }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[20].step) {
  case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
  case SINGLE_HOLD: unregister_code16(KC_DQUO); break;
  case DOUBLE_TAP: unregister_code16(KC_QUOTE); break;
  case DOUBLE_HOLD: unregister_code16(KC_QUOTE); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
  }
  dance_state[20].step = 0;
}

void on_dance_N(qk_tap_dance_state_t *state, void *user_data);
void dance_N_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_N_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_N(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_N);
    tap_code16(KC_N);
    tap_code16(KC_N);
  }
  if(state->count > 3) {
    tap_code16(KC_N);
  }
}

void dance_N_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[21].step = dance_step(state);
  switch (dance_state[21].step) {
  case SINGLE_TAP: register_code16(KC_N); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_N));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_N);
    register_code16(KC_N);
    break;

  }
}

void dance_N_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[21].step) {
  case SINGLE_TAP: unregister_code16(KC_N); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_N));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_N);
    break;

  }
  dance_state[21].step = 0;
}

void on_dance_M(qk_tap_dance_state_t *state, void *user_data);
void dance_M_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_M_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_M(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_M);
    tap_code16(KC_M);
    tap_code16(KC_M);
  }
  if(state->count > 3) {
    tap_code16(KC_M);
  }
}

void dance_M_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[22].step = dance_step(state);
  switch (dance_state[22].step) {

  case SINGLE_TAP: register_code16(KC_M); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_M));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_M);
    register_code16(KC_M);
    break;

  }
}

void dance_M_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[22].step) {
  case SINGLE_TAP: unregister_code16(KC_M); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_M));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_M);
    break;
  }
  dance_state[22].step = 0;
}

void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_COMMA);
    tap_code16(KC_COMMA);
    tap_code16(KC_COMMA);
  }
  if(state->count > 3) {
    tap_code16(KC_COMMA);
  }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[23].step = dance_step(state);
  switch (dance_state[23].step) {
  case SINGLE_TAP: register_code16(KC_COMMA); break;
  case SINGLE_HOLD: register_code16(KC_LABK); break;
  case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
  case DOUBLE_HOLD: register_code16(KC_AT); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
  }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[23].step) {
  case SINGLE_TAP: unregister_code16(KC_COMMA); break;
  case SINGLE_HOLD: unregister_code16(KC_LABK); break;
  case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
  case DOUBLE_HOLD: unregister_code16(KC_AT); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
  }
  dance_state[23].step = 0;
}
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DOT);
    tap_code16(KC_DOT);
    tap_code16(KC_DOT);
  }
  if(state->count > 3) {
    tap_code16(KC_DOT);
  }
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[24].step = dance_step(state);
  switch (dance_state[24].step) {
  case SINGLE_TAP: register_code16(KC_DOT); break;
  case SINGLE_HOLD: register_code16(KC_RABK); break;
  case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
  case DOUBLE_HOLD: register_code16(KC_HASH); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
  }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[24].step) {
  case SINGLE_TAP: unregister_code16(KC_DOT); break;
  case SINGLE_HOLD: unregister_code16(KC_RABK); break;
  case DOUBLE_TAP: unregister_code16(KC_DOT); break;
  case DOUBLE_HOLD: unregister_code16(KC_HASH); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
  }
  dance_state[24].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_SLASH);
    tap_code16(KC_SLASH);
    tap_code16(KC_SLASH);
  }
  if(state->count > 3) {
    tap_code16(KC_SLASH);
  }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[25].step = dance_step(state);
  switch (dance_state[25].step) {
  case SINGLE_TAP: register_code16(KC_SLASH); break;
  case SINGLE_HOLD: register_code16(KC_QUES); break;
  case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
  case DOUBLE_HOLD: register_code16(KC_SLASH); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
  }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[25].step) {
  case SINGLE_TAP: unregister_code16(KC_SLASH); break;
  case SINGLE_HOLD: unregister_code16(KC_QUES); break;
  case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
  case DOUBLE_HOLD: unregister_code16(KC_SLASH); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
  }
  dance_state[25].step = 0;
}
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
  }
  if(state->count > 3) {
    tap_code16(KC_TAB);
  }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[26].step = dance_step(state);
  switch (dance_state[26].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[26].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
  }
  dance_state[26].step = 0;
}
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_LEFT));
    tap_code16(LALT(KC_LEFT));
    tap_code16(LALT(KC_LEFT));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_LEFT));
  }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[27].step = dance_step(state);
  switch (dance_state[27].step) {
  case SINGLE_TAP: register_code16(LALT(KC_LEFT)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); break;
  case DOUBLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT));
  }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[27].step) {
  case SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
  }
  dance_state[27].step = 0;
}
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_LSPO);
    tap_code16(KC_LSPO);
    tap_code16(KC_LSPO);
  }
  if(state->count > 3) {
    tap_code16(KC_LSPO);
  }
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[28].step = dance_step(state);
  switch (dance_state[28].step) {
  case SINGLE_TAP: register_code16(KC_LSPO); break;
  case DOUBLE_TAP: layer_move(8); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LSPO); register_code16(KC_LSPO);
  }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[28].step) {
  case SINGLE_TAP: unregister_code16(KC_LSPO); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSPO); break;
  }
  dance_state[28].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RCTL(KC_PGUP));
    tap_code16(RCTL(KC_PGUP));
    tap_code16(RCTL(KC_PGUP));
  }
  if(state->count > 3) {
    tap_code16(RCTL(KC_PGUP));
  }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[29].step = dance_step(state);
  switch (dance_state[29].step) {
  case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[29].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[29].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RCTL(KC_PGDOWN));
    tap_code16(RCTL(KC_PGDOWN));
    tap_code16(RCTL(KC_PGDOWN));
  }
  if(state->count > 3) {
    tap_code16(RCTL(KC_PGDOWN));
  }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[30].step = dance_step(state);
  switch (dance_state[30].step) {
  case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[30].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[30].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_INSERT);
    tap_code16(KC_INSERT);
    tap_code16(KC_INSERT);
  }
  if(state->count > 3) {
    tap_code16(KC_INSERT);
  }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[31].step = dance_step(state);
  switch (dance_state[31].step) {
  case SINGLE_TAP: register_code16(KC_INSERT); break;
  case DOUBLE_TAP: layer_move(8); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_INSERT); register_code16(KC_INSERT);
  }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[31].step) {
  case SINGLE_TAP: unregister_code16(KC_INSERT); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_INSERT); break;
  }
  dance_state[31].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_SLASH));
    tap_code16(LALT(KC_SLASH));
    tap_code16(LALT(KC_SLASH));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_SLASH));
  }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[32].step = dance_step(state);
  switch (dance_state[32].step) {
  case SINGLE_TAP: register_code16(LALT(KC_SLASH)); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(LALT(KC_SLASH)); register_code16(LALT(KC_SLASH)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SLASH)); register_code16(LALT(KC_SLASH));
  }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[32].step) {
  case SINGLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
  }
  dance_state[32].step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RALT(KC_ENTER));
    tap_code16(RALT(KC_ENTER));
    tap_code16(RALT(KC_ENTER));
  }
  if(state->count > 3) {
    tap_code16(RALT(KC_ENTER));
  }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[33].step = dance_step(state);
  switch (dance_state[33].step) {
  case SINGLE_TAP: register_code16(RALT(KC_ENTER)); break;
  case DOUBLE_TAP: register_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER)); break;
  case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER));
  }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[33].step) {
  case SINGLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
  case DOUBLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
  }
  dance_state[33].step = 0;
}
void on_dance_34(qk_tap_dance_state_t *state, void *user_data);
void dance_34_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_34_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_34(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
  }
  if(state->count > 3) {
    tap_code16(KC_TAB);
  }
}

void dance_34_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[34].step = dance_step(state);
  switch (dance_state[34].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_34_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[34].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
  }
  dance_state[34].step = 0;
}
void on_dance_35(qk_tap_dance_state_t *state, void *user_data);
void dance_35_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_35_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_35(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RCTL(KC_PGUP));
    tap_code16(RCTL(KC_PGUP));
    tap_code16(RCTL(KC_PGUP));
  }
  if(state->count > 3) {
    tap_code16(RCTL(KC_PGUP));
  }
}

void dance_35_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[35].step = dance_step(state);
  switch (dance_state[35].step) {
  case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_35_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[35].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[35].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(RCTL(KC_PGDOWN));
    tap_code16(RCTL(KC_PGDOWN));
    tap_code16(RCTL(KC_PGDOWN));
  }
  if(state->count > 3) {
    tap_code16(RCTL(KC_PGDOWN));
  }
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[36].step = dance_step(state);
  switch (dance_state[36].step) {
  case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[36].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[36].step = 0;
}
void on_dance_37(qk_tap_dance_state_t *state, void *user_data);
void dance_37_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_37_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_37(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
  }
  if(state->count > 3) {
    tap_code16(KC_TAB);
  }
}

void dance_37_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[37].step = dance_step(state);
  switch (dance_state[37].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_37_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[37].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
  }
  dance_state[37].step = 0;
}
void on_dance_38(qk_tap_dance_state_t *state, void *user_data);
void dance_38_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_38_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_38(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_Q));
    tap_code16(LGUI(KC_Q));
    tap_code16(LGUI(KC_Q));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_Q));
  }
}

void dance_38_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[38].step = dance_step(state);
  switch (dance_state[38].step) {
  case SINGLE_TAP: register_code16(LGUI(KC_Q)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Q)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q));
  }
}

void dance_38_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[38].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_Q)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_Q)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Q)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_Q)); break;
  }
  dance_state[38].step = 0;
}
void on_dance_39(qk_tap_dance_state_t *state, void *user_data);
void dance_39_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_39_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_39(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_W));
    tap_code16(LGUI(KC_W));
    tap_code16(LGUI(KC_W));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_W));
  }
}

void dance_39_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[39].step = dance_step(state);
  switch (dance_state[39].step) {
  case SINGLE_TAP: register_code16(LGUI(KC_W)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_W)); register_code16(LGUI(KC_W)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_W)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_W)); register_code16(LGUI(KC_W));
  }
}

void dance_39_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[39].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_W)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_W)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_W)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_W)); break;
  }
  dance_state[39].step = 0;
}
void on_dance_40(qk_tap_dance_state_t *state, void *user_data);
void dance_40_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_40_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_40(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_R));
    tap_code16(LGUI(KC_R));
    tap_code16(LGUI(KC_R));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_R));
  }
}

void dance_40_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[40].step = dance_step(state);
  switch (dance_state[40].step) {
  case SINGLE_TAP: register_code16(LGUI(KC_R)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_R)); register_code16(LGUI(KC_R)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_R)); register_code16(LGUI(KC_R));
  }
}

void dance_40_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[40].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_R)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_R)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_R)); break;
  }
  dance_state[40].step = 0;
}

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Y);
    tap_code16(KC_Y);
    tap_code16(KC_Y);
  }
  if(state->count > 3) {
    tap_code16(KC_Y);
  }
}

void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[41].step = dance_step(state);
  switch (dance_state[41].step) {
  case SINGLE_TAP: register_code16(KC_Y); break;
  case SINGLE_HOLD:
    register_code16(LSFT (KC_Y));
    break;

  case DOUBLE_HOLD:
    register_code16(KC_HOME);
    break;

  case DOUBLE_SINGLE_TAP:
  case DOUBLE_TAP:
    register_code16(KC_Y);
    register_code16(KC_Y);
    break;

  }
}

void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[41].step) {
  case SINGLE_TAP: unregister_code16(KC_Y); break;
  case SINGLE_HOLD:
    unregister_code16(LSFT (KC_Y));
    break;

  case DOUBLE_HOLD:
    unregister_code16(KC_HOME);
    break;

  case DOUBLE_SINGLE_TAP:
  case DOUBLE_TAP:
    unregister_code16(KC_Y);
    break;

  }
  dance_state[41].step = 0;
}

void on_dance_42(qk_tap_dance_state_t *state, void *user_data);
void dance_42_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_42_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_42(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_G));
    tap_code16(LGUI(KC_G));
    tap_code16(LGUI(KC_G));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_G));
  }
}

void dance_42_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[42].step = dance_step(state);
  switch (dance_state[42].step) {
  case SINGLE_TAP: register_code16(LGUI(KC_G)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_G)); register_code16(LGUI(KC_G)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_G)); register_code16(LGUI(KC_G));
  }
}

void dance_42_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[42].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_G)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_G)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_G)); break;
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
  case SINGLE_TAP: register_code16(RGUI(KC_J)); break;
  case DOUBLE_TAP: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_J)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
  }
}

void dance_43_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[43].step) {
  case SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
  case DOUBLE_TAP: unregister_code16(RGUI(KC_J)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_J)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
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
  case SINGLE_TAP: register_code16(LGUI(KC_K)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_K)); register_code16(LGUI(KC_K)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_K)); register_code16(LGUI(KC_K));
  }
}

void dance_44_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[44].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_K)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_K)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_K)); break;
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
  case SINGLE_TAP: register_code16(LGUI(KC_L)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_L)); register_code16(LGUI(KC_L));
  }
}

void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[45].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_L)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_L)); break;
  }
  dance_state[45].step = 0;
}
void on_dance_46(qk_tap_dance_state_t *state, void *user_data);
void dance_46_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_46_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_46(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_N));
    tap_code16(LGUI(KC_N));
    tap_code16(LGUI(KC_N));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_N));
  }
}

void dance_46_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[46].step = dance_step(state);
  switch (dance_state[46].step) {
  case SINGLE_TAP: register_code16(LGUI(KC_N)); break;
  case DOUBLE_TAP: register_code16(LGUI(KC_N)); register_code16(LGUI(KC_N)); break;
  case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_N)); register_code16(LGUI(KC_N));
  }
}

void dance_46_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[46].step) {
  case SINGLE_TAP: unregister_code16(LGUI(KC_N)); break;
  case DOUBLE_TAP: unregister_code16(LGUI(KC_N)); break;
  case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_N)); break;
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
  case SINGLE_TAP: register_code16(LGUI(LSFT(KC_UP))); break;
  case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP))); break;
  case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP)));
  }
}

void dance_47_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[47].step) {
  case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
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
  case SINGLE_TAP: register_code16(LGUI(LSFT(KC_LEFT))); break;
  case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT))); break;
  case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_H))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT)));
  }
}

void dance_48_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[48].step) {
  case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_H))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
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
  case SINGLE_TAP: register_code16(LGUI(LSFT(KC_DOWN))); break;
  case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN))); break;
  case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_J))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN)));
  }
}

void dance_49_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[49].step) {
  case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_J))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
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
  case SINGLE_TAP: register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_L))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT)));
  }
}

void dance_50_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[50].step) {
  case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_L))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  }
  dance_state[50].step = 0;
}
void dance_51_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_51_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_51_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[51].step = dance_step(state);
  switch (dance_state[51].step) {
  case DOUBLE_HOLD: register_code16(RCTL(RGUI(KC_Q))); break;
  }
}

void dance_51_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[51].step) {
  case DOUBLE_HOLD: unregister_code16(RCTL(RGUI(KC_Q))); break;
  }
  dance_state[51].step = 0;
}
void on_dance_52(qk_tap_dance_state_t *state, void *user_data);
void dance_52_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_52_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_52(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
    tap_code16(KC_TAB);
  }
  if(state->count > 3) {
    tap_code16(KC_TAB);
  }
}

void dance_52_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[52].step = dance_step(state);
  switch (dance_state[52].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_52_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[52].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
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
  case SINGLE_TAP: register_code16(KC_TILD); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: register_code16(KC_TILD); register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TILD); register_code16(KC_TILD);
  }
}

void dance_53_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[53].step) {
  case SINGLE_TAP: unregister_code16(KC_TILD); break;
  case DOUBLE_TAP: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TILD); break;
  }
  dance_state[53].step = 0;
}
void on_dance_54(qk_tap_dance_state_t *state, void *user_data);
void dance_54_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_54_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_54(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
  }
  if(state->count > 3) {
    tap_code16(KC_UNDS);
  }
}

void dance_54_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[54].step = dance_step(state);
  switch (dance_state[54].step) {
  case SINGLE_TAP: register_code16(KC_UNDS); break;
  case SINGLE_HOLD: register_code16(KC_PLUS); break;
  case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
  }
}

void dance_54_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[54].step) {
  case SINGLE_TAP: unregister_code16(KC_UNDS); break;
  case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
  case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
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
  case SINGLE_TAP: register_code16(KC_COLN); break;
  case SINGLE_HOLD: register_code16(KC_LCBR); break;
  case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
  }
}

void dance_55_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[55].step) {
  case SINGLE_TAP: unregister_code16(KC_COLN); break;
  case SINGLE_HOLD: unregister_code16(KC_LCBR); break;
  case DOUBLE_TAP: unregister_code16(KC_COLN); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
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
  case SINGLE_TAP: register_code16(KC_DQUO); break;
  case SINGLE_HOLD: register_code16(KC_RCBR); break;
  case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
  }
}

void dance_56_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[56].step) {
  case SINGLE_TAP: unregister_code16(KC_DQUO); break;
  case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
  case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
  }
  dance_state[56].step = 0;
}
void dance_57_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_57_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_57_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[57].step = dance_step(state);
  switch (dance_state[57].step) {
  case SINGLE_TAP: layer_move(6); break;
  case SINGLE_HOLD: layer_move(0); break;
  case DOUBLE_TAP: layer_move(6); break;
  case DOUBLE_SINGLE_TAP: layer_move(6); break;
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
  case SINGLE_TAP: register_code16(RGUI(RSFT(KC_H))); break;
  case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H))); break;
  case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_LEFT))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H)));
  }
}

void dance_58_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[58].step) {
  case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
  case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
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
  case SINGLE_TAP: register_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_HOLD: register_code16(KC_F11); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K)));
  }
}

void dance_59_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[59].step) {
  case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
  case DOUBLE_HOLD: unregister_code16(KC_F11); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
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
  case SINGLE_TAP: register_code16(RGUI(RSFT(KC_L))); break;
  case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L))); break;
  case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_RIGHT))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L)));
  }
}

void dance_60_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[60].step) {
  case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
  case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
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
  case SINGLE_TAP: register_code16(KC_GRAVE); break;
  case SINGLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_TAP: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
  }
}

void dance_61_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[61].step) {
  case SINGLE_TAP: unregister_code16(KC_GRAVE); break;
  case SINGLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break;
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
  case SINGLE_TAP: register_code16(KC_H); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_H));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_H);
    register_code16(KC_H);
    break;

  }
}

void dance_H_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[62].step) {


  case SINGLE_TAP: unregister_code16(KC_H); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_H));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_H);
    break;

  /* case SINGLE_TAP: unregister_code16(KC_H); break; */
  /* case SINGLE_HOLD: unregister_code16(KC_LEFT); break; */
  /* case DOUBLE_TAP: unregister_code16(KC_H); break; */
  /* case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break; */
  /* case DOUBLE_HOLD:  unregister_code16(RSFT(KC_H));break; */
  }
  dance_state[62].step = 0;
}

void dance_J_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_J_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_J(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 4) {
    tap_code16(KC_J);
    tap_code16(KC_J);
    tap_code16(KC_J);
    tap_code16(KC_J);
  }
  if(state->count > 4) {
    tap_code16(KC_J);
  }
}

void dance_J_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[63].step = dance_step(state);
  switch (dance_state[63].step) {
  case SINGLE_TAP: register_code16(KC_J); break;
  case SINGLE_HOLD: register_code16(RSFT(KC_J)); break;
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_J);
    register_code16(KC_J);
    break;

  case DOUBLE_TAP:
  case DOUBLE_HOLD:
    register_code(KC_ESC);  break;
  }
}

void dance_J_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[63].step) {
  case SINGLE_TAP: unregister_code16(KC_J); break;
  case SINGLE_HOLD: unregister_code16(RSFT(KC_J)); break;

  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_J);
    break;
  case DOUBLE_TAP:
  case DOUBLE_HOLD: unregister_code(KC_ESC);  break;

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
  case SINGLE_TAP: register_code16(KC_K); break;
  case SINGLE_HOLD: register_code16(KC_K); break;
  case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_64_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[64].step) {
  case SINGLE_TAP: unregister_code16(KC_K); break;
  case SINGLE_HOLD: unregister_code16(KC_K); break;
  case DOUBLE_TAP: unregister_code16(KC_K); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
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
  case SINGLE_TAP: register_code16(KC_L); break;
  case SINGLE_HOLD: register_code16(KC_L); break;
  case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
  }
}

void dance_65_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[65].step) {
  case SINGLE_TAP: unregister_code16(KC_L); break;
  case SINGLE_HOLD: unregister_code16(KC_L); break;
  case DOUBLE_TAP: unregister_code16(KC_L); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
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
  case SINGLE_TAP: register_code16(KC_DELETE); break;
  case SINGLE_HOLD: register_code16(KC_DELETE); break;
  case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
  }
}

void dance_66_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[66].step) {
  case SINGLE_TAP: unregister_code16(KC_DELETE); break;
  case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
  case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
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
  case SINGLE_TAP: register_code16(KC_N); break;
  case SINGLE_HOLD: register_code16(KC_N); break;
  case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
  }
}

void dance_67_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[67].step) {
  case SINGLE_TAP: unregister_code16(KC_N); break;
  case SINGLE_HOLD: unregister_code16(KC_N); break;
  case DOUBLE_TAP: unregister_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
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
  case SINGLE_TAP: register_code16(RCTL(KC_HOME)); break;
  case SINGLE_HOLD: register_code16(RCTL(KC_END)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME));
  }
}

void dance_68_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[68].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
  case SINGLE_HOLD: unregister_code16(RCTL(KC_END)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
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
  case SINGLE_TAP: register_code16(RCTL(KC_HOME)); break;
  case SINGLE_HOLD: register_code16(RCTL(KC_END)); break;
  case DOUBLE_TAP: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME));
  }
}

void t_alt_tab_h_base_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[70].step) {
  case SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
  case SINGLE_HOLD: unregister_code16(RCTL(KC_END)); break;
  case DOUBLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
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
  case SINGLE_TAP: register_code16(KC_N); break;
  case SINGLE_HOLD: register_code16(KC_N); break;
  case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
  }
}

void only_n_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[69].step) {
  case SINGLE_TAP: unregister_code16(KC_N); break;
  case SINGLE_HOLD: unregister_code16(KC_N); break;
  case DOUBLE_TAP: unregister_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
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
  case SINGLE_TAP: register_code16(KC_N); break;
  case SINGLE_HOLD: register_code16(KC_N); break;
  case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
  }
}

void dance_69_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[29].step) {
  case SINGLE_TAP: unregister_code16(KC_N); break;
  case SINGLE_HOLD: unregister_code16(KC_N); break;
  case DOUBLE_TAP: unregister_code16(KC_N); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
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
  case SINGLE_TAP: register_code16(KC_LCBR); break;
  case SINGLE_HOLD: register_code16(KC_RALT); break;
  case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
  }
}

void t_lbrc_h_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[71].step) {
  case SINGLE_TAP: unregister_code16(KC_LCBR); break;
  case SINGLE_HOLD: unregister_code16(KC_RALT); break;
  case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
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
  case SINGLE_TAP: register_code16(KC_PSCREEN); break;
  case SINGLE_HOLD: register_code16(KC_PSCREEN); break;
  case DOUBLE_TAP: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break;
  case DOUBLE_HOLD: register_code16(RGUI(KC_PSCREEN)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN);
  }
}

void dance_73_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[73].step) {
  case SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
  case SINGLE_HOLD: unregister_code16(KC_PSCREEN); break;
  case DOUBLE_TAP: unregister_code16(KC_PSCREEN); break;
  case DOUBLE_HOLD: unregister_code16(RGUI(KC_PSCREEN)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
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
  case SINGLE_TAP: register_code16(KC_V); break;
  case SINGLE_HOLD:
    register_code16(LSFT (KC_V));
 break;
  case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
  case DOUBLE_HOLD: layer_on(_AUDIO); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
  }
}

void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[74].step) {
  case SINGLE_TAP: unregister_code16(KC_V); break;
  case SINGLE_HOLD:  unregister_code16(RSFT( KC_V )); break;
  case DOUBLE_HOLD:  layer_off(_AUDIO);  break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
  }
  dance_state[74].step = 0;
}


void on_z_or_shift(qk_tap_dance_state_t *state, void *user_data);
void z_or_shift_finished(qk_tap_dance_state_t *state, void *user_data);
void z_or_shift_reset(qk_tap_dance_state_t *state, void *user_data);

void on_z_or_shift(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Z);
    tap_code16(KC_Z);
    tap_code16(KC_Z);
  }
  if(state->count > 3) {
    tap_code16(KC_Z);
  }
}

void z_or_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
  case SINGLE_TAP: register_code16(KC_Z); break;
  case SINGLE_HOLD:
    register_code16(KC_LSFT); break;
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_Z));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_Z);
    register_code16(KC_Z);

  }
}

void z_or_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case SINGLE_TAP: unregister_code16(KC_Z); break;
  case SINGLE_HOLD:
    unregister_code16(KC_LSFT); break;
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_Z));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_Z);
    break;

  }
  dance_state[76].step = 0;
}


void on_super_windows(qk_tap_dance_state_t *state, void *user_data);
void super_windows_finished(qk_tap_dance_state_t *state, void *user_data);
void super_windows_reset(qk_tap_dance_state_t *state, void *user_data);

void on_super_windows(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_RGUI);
    tap_code16(KC_RGUI);
    tap_code16(KC_RGUI);
  }
  if(state->count > 3) {
    tap_code16(KC_RGUI);
  }
}

void super_windows_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[75].step = dance_step(state);
  switch (dance_state[75].step) {
  case SINGLE_TAP: layer_on(_WINDOWS); break;
  case SINGLE_HOLD: register_code16(KC_RGUI) ; break;
  case DOUBLE_TAP: register_code16(KC_RGUI); register_code16(KC_RGUI); break;
    /* case DOUBLE_TAP: register_code16(ALT_TAB); break; */
  case DOUBLE_HOLD: register_code16(KC_RGUI) ; break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RGUI); register_code16(KC_RGUI);
  }
}

void super_windows_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[75].step) {
  case SINGLE_TAP: layer_off(_WINDOWS); break;
  case SINGLE_HOLD: unregister_code16( KC_RGUI ); break;
    /* case DOUBLE_TAP: unregister_code16(ALT_TAB); break; */
  case DOUBLE_TAP: unregister_code16(KC_RGUI); break;
  case DOUBLE_HOLD: unregister_code16(KC_RGUI) ;break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RGUI); break;
  }
  dance_state[75].step = 0;
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
  case SINGLE_TAP: layer_on(_WINDOWS); break;
  case SINGLE_HOLD: register_code16(KC_RGUI) ; break;
  case DOUBLE_TAP: register_code16(KC_RGUI); register_code16(KC_RGUI); break;
    /* case DOUBLE_TAP: register_code16(ALT_TAB); break; */
  case DOUBLE_HOLD: register_code16(KC_RGUI) ; break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RGUI); register_code16(KC_RGUI);
  }
}

void windows_or_alt_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case SINGLE_TAP: layer_off(_WINDOWS); break;
  case SINGLE_HOLD: unregister_code16( KC_RGUI ); break;
    /* case DOUBLE_TAP: unregister_code16(ALT_TAB); break; */
  case DOUBLE_TAP: unregister_code16(KC_RGUI); break;
  case DOUBLE_HOLD: unregister_code16(KC_RGUI) ;break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RGUI); break;
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
  case SINGLE_TAP: register_code16(KC_B); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_B)); break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_B); register_code16(KC_B);
    break;
  }
}

void dance_B_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
  case SINGLE_TAP: unregister_code16(KC_B); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_B));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_B);
    break;
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
  case SINGLE_TAP: register_code16(KC_C); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_C));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_C);
    register_code16(KC_C);
    break;

  }
}

void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[77].step) {
  case SINGLE_TAP: unregister_code16(KC_C); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_C));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
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
  case SINGLE_TAP: register_code16(KC_D); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_D));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_D);
    register_code16(KC_D);
    break;
  }
}

void dance_D_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[78].step) {
  case SINGLE_TAP: unregister_code16(KC_D); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_D));
    break;

  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
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

  case SINGLE_TAP: register_code16(KC_E); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_E));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_E);
    register_code16(KC_E);
    break;

  }
}

void dance_E_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {

  case SINGLE_TAP: unregister_code16(KC_E); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_E));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
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
  case SINGLE_TAP: register_code16(KC_F); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_F));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_F);
    register_code16(KC_F);
    break;
  }
}

void dance_F_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[14].step) {
  case SINGLE_TAP: unregister_code16(KC_F); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_F));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
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
  case SINGLE_TAP: register_code16(KC_G); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_G));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_G);
    register_code16(KC_G);
    break;
  }
}

void dance_G_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[15].step) {
  case SINGLE_TAP: unregister_code16(KC_G); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_G));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
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
  case SINGLE_TAP: register_code16(KC_X); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(LSFT (KC_X));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_X);
    register_code16(KC_X);
    break;
  }
}

void dance_X_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[79].step) {
  case SINGLE_TAP: unregister_code16(KC_X); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(LSFT (KC_X));
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_X);
    break;
  }
  dance_state[79].step = 0;
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
  case SINGLE_TAP: register_code16(KC_X); break;
  case SINGLE_HOLD: register_code16(KC_X); break;
  case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
  case DOUBLE_HOLD: register_code16(LSFT (KC_X)); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
  }
}

void dance_min_or_exit_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[80].step) {
  case SINGLE_TAP: unregister_code16(KC_X); break;
  case SINGLE_HOLD:  unregister_code16(KC_X); break;
  case DOUBLE_TAP: unregister_code16(KC_X); break;
  case DOUBLE_HOLD: unregister_code16(LSFT (KC_X)); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
  }
  dance_state[80].step = 0;
}


void on_dance_exlm(qk_tap_dance_state_t *state, void *user_data);
void dance_exlm_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_exlm_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_exlm(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_EXLM);
    tap_code16(KC_EXLM);
    tap_code16(KC_EXLM);
  }
  if(state->count > 3) {
    tap_code16(KC_EXLM);
  }
}

void dance_exlm_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[81].step = dance_step(state);
  switch (dance_state[81].step) {
  case SINGLE_TAP: register_code16(KC_EXLM); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_1);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_EXLM); register_code16(KC_EXLM); break;
  }
}

void dance_exlm_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[81].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_EXLM); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_1);
    break;
  }
  dance_state[81].step = 0;
}


void on_dance_at(qk_tap_dance_state_t *state, void *user_data);
void dance_at_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_at_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_at(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_AT);
    tap_code16(KC_AT);
    tap_code16(KC_AT);
  }
  if(state->count > 3) {
    tap_code16(KC_AT);
  }
}

void dance_at_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[82].step = dance_step(state);
  switch (dance_state[82].step) {
  case SINGLE_TAP: register_code16(KC_AT); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_1);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_AT); register_code16(KC_AT); break;
  }
}

void dance_at_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[82].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_AT); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_1);
    break;
  }
  dance_state[82].step = 0;
}

void on_dance_hash(qk_tap_dance_state_t *state, void *user_data);
void dance_hash_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_hash_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_hash(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_HASH);
    tap_code16(KC_HASH);
    tap_code16(KC_HASH);
  }
  if(state->count > 3) {
    tap_code16(KC_HASH);
  }
}

void dance_hash_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[83].step = dance_step(state);
  switch (dance_state[83].step) {
  case SINGLE_TAP: register_code16(KC_HASH); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_3);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_HASH); register_code16(KC_HASH); break;
  }
}

void dance_hash_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[83].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_HASH); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_3);
    break;
  }
  dance_state[83].step = 0;
}

void on_dance_dlr(qk_tap_dance_state_t *state, void *user_data);
void dance_dlr_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_dlr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_dlr(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DLR);
    tap_code16(KC_DLR);
    tap_code16(KC_DLR);
  }
  if(state->count > 3) {
    tap_code16(KC_DLR);
  }
}

void dance_dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[84].step = dance_step(state);
  switch (dance_state[84].step) {
  case SINGLE_TAP: register_code16(KC_DLR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_4);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_DLR); register_code16(KC_DLR); break;
  }
}

void dance_dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[84].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_DLR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_4);
    break;
  }
  dance_state[84].step = 0;
}

void on_dance_perc(qk_tap_dance_state_t *state, void *user_data);
void dance_perc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_perc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_perc(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_PERC);
    tap_code16(KC_PERC);
    tap_code16(KC_PERC);
  }
  if(state->count > 3) {
    tap_code16(KC_PERC);
  }
}

void dance_perc_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case SINGLE_TAP: register_code16(KC_PERC); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_5);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_PERC); register_code16(KC_PERC); break;
  }
}

void dance_perc_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[85].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_PERC); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_5);
    break;
  }
  dance_state[85].step = 0;
}

void on_dance_circ(qk_tap_dance_state_t *state, void *user_data);
void dance_circ_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_circ_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_circ(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_CIRC);
    tap_code16(KC_CIRC);
    tap_code16(KC_CIRC);
  }
  if(state->count > 3) {
    tap_code16(KC_CIRC);
  }
}

void dance_circ_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[86].step = dance_step(state);
  switch (dance_state[86].step) {
  case SINGLE_TAP: register_code16(KC_CIRC); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_6);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_CIRC); register_code16(KC_CIRC); break;
  }
}

void dance_circ_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[86].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_CIRC); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_6);
    break;
  }
  dance_state[86].step = 0;
}



void on_dance_ampr(qk_tap_dance_state_t *state, void *user_data);
void dance_ampr_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_ampr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_ampr(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_AMPR);
    tap_code16(KC_AMPR);
    tap_code16(KC_AMPR);
  }
  if(state->count > 3) {
    tap_code16(KC_AMPR);
  }
}

void dance_ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[87].step = dance_step(state);
  switch (dance_state[87].step) {
  case SINGLE_TAP: register_code16(KC_AMPR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_7);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_AMPR); register_code16(KC_AMPR); break;
  }
}

void dance_ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[87].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_AMPR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_7);
    break;
  }
  dance_state[87].step = 0;
}


void on_dance_astr(qk_tap_dance_state_t *state, void *user_data);
void dance_astr_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_astr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_astr(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_ASTR);
    tap_code16(KC_ASTR);
    tap_code16(KC_ASTR);
  }
  if(state->count > 3) {
    tap_code16(KC_ASTR);
  }
}

void dance_astr_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[88].step = dance_step(state);
  switch (dance_state[88].step) {
  case SINGLE_TAP: register_code16(KC_ASTR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_8);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_ASTR); register_code16(KC_ASTR); break;
  }
}

void dance_astr_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[88].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_ASTR); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_8);
    break;
  }
  dance_state[88].step = 0;
}

void on_dance_lprn(qk_tap_dance_state_t *state, void *user_data);
void dance_lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_lprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_lprn(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_LPRN);
    tap_code16(KC_LPRN);
    tap_code16(KC_LPRN);
  }
  if(state->count > 3) {
    tap_code16(KC_LPRN);
  }
}

void dance_lprn_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[89].step = dance_step(state);
  switch (dance_state[89].step) {
  case SINGLE_TAP: register_code16(KC_LPRN); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_9);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_LPRN); register_code16(KC_LPRN); break;
  }
}

void dance_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[89].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_LPRN); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_9);
    break;
  }
  dance_state[89].step = 0;
}



void on_dance_rprn(qk_tap_dance_state_t *state, void *user_data);
void dance_rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_rprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_rprn(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_RPRN);
    tap_code16(KC_RPRN);
    tap_code16(KC_RPRN);
  }
  if(state->count > 3) {
    tap_code16(KC_RPRN);
  }
}

void dance_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[90].step = dance_step(state);
  switch (dance_state[90].step) {
  case SINGLE_TAP: register_code16(KC_RPRN); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    register_code16(KC_0);
    break;
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
    register_code16(KC_RPRN); register_code16(KC_RPRN); break;
  }
}

void dance_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[90].step) {
    case SINGLE_TAP:
  case DOUBLE_TAP:
  case DOUBLE_SINGLE_TAP:
   unregister_code16(KC_RPRN); break;
  case SINGLE_HOLD:
  case DOUBLE_HOLD:
    unregister_code16(KC_0);
    break;
  }
  dance_state[90].step = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
                                             [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
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
                                             [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
                                             [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
                                             [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
                                             [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
                                             [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
                                             [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset),
                                             [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset),
                                             [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
                                             [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
                                             [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
                                             [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset),
                                             [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
                                             [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
                                             [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
                                             [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
                                             [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
                                             [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
                                             [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
                                             [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
                                             [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
                                             [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
                                             [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
                                             [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
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
                                             [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
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
                                             [SUPER_WINDOWS] = ACTION_TAP_DANCE_FN_ADVANCED(on_super_windows, super_windows_finished, super_windows_reset),
                                             [Z_OR_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_z_or_shift, z_or_shift_finished, z_or_shift_reset),
                                             [WINDOWS_OR_ALT_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_windows_or_alt_tab, windows_or_alt_tab_finished, windows_or_alt_tab_reset),
                                             [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset),
                                             [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
                                             [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
                                             [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
                                             [ DANCE_MIN_OR_EXIT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_min_or_exit, dance_min_or_exit_finished, dance_min_or_exit_reset),
                                             [DANCE_EXLM] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_exlm, dance_exlm_finished, dance_exlm_reset),
                                             [DANCE_AT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_at, dance_at_finished, dance_at_reset),
                                             [DANCE_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_hash, dance_hash_finished, dance_hash_reset),
                                             [DANCE_DLR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_dlr, dance_dlr_finished, dance_dlr_reset),
                                             [DANCE_PERC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_perc, dance_perc_finished, dance_perc_reset),
                                             [DANCE_CIRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_circ, dance_circ_finished, dance_circ_reset),
                                             [DANCE_AMPR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ampr, dance_ampr_finished, dance_ampr_reset),
                                             [DANCE_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_astr, dance_astr_finished, dance_astr_reset),
                                             [DANCE_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lprn, dance_lprn_finished, dance_lprn_reset),
                                             [DANCE_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rprn, dance_rprn_finished, dance_rprn_reset),
};
