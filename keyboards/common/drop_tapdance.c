enum tap_dance_codes {
                      DANCE_0,
                      DANCE_Q,
                      DANCE_MIC,
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
                      DANCE_PAREN_BRACKET,
                      DANCE_SAVE_LOAD_NS_SWITCH,
                      DANCE_19,
                      DANCE_20,
                      DANCE_SPACE,
                      DANCE_25,
                      DANCE_29,
                      DANCE_30,
                      DANCE_33,
                      DANCE_35,
                      DANCE_36,
                      DANCE_38,
                      DANCE_39,
                      DANCE_40,
                      DANCE_44,
                      DANCE_46,
                      DANCE_48,
                      DANCE_49,
                      DANCE_50,
                      DANCE_58,
                      DANCE_59,
                      DANCE_60,
                      DANCE_69,
                      DANCE_73,
                      /* DANCE_A, */
                      /* DANCE_B, */
                      /* DANCE_C, */
                      DANCE_COMMA,
                      /* DANCE_D, */
                      /* DANCE_E, */
                      /* DANCE_F, */
                      /* DANCE_G, */
                      /* DANCE_H, */
                      /* DANCE_I, */
                      /* DANCE_J, */
                      /* DANCE_K, */
                      /* DANCE_L, */
                      /* DANCE_M, */
                      /* DANCE_N, */
                      /* DANCE_O, */
                      /* DANCE_P, */
                      /* DANCE_Q, */
                      /* DANCE_R, */
                      /* DANCE_S, */
                      /* DANCE_T, */
                      /* DANCE_U, */
                      /* DANCE_V, */
                      /* DANCE_W, */
                      /* DANCE_X, */
                      /* DANCE_Y, */
                      /* DANCE_Z, */
                      PREONIC_A,
                      PREONIC_Z,
                      WINDOWS_OR_ALT_TAB,
                      WWW_BACK_FORWARD,
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

static tap dance_state[85];

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

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: register_code16(KC_TAB); break;
    /* case SINGLE_HOLD: layer_on(6); break; */
  case SINGLE_HOLD:
    register_code16(KC_LCTL);
    /* layer_on(_HYPER); */
    break;

  case DOUBLE_TAP: register_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: register_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);

  case TRIPLE_TAP:
    /* layer_move(_BASE); */
    break;
  }
}


void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
  case SINGLE_TAP: unregister_code16(KC_TAB); break;
  case SINGLE_HOLD:
    unregister_code16(KC_LCTL);
    /* layer_off(_HYPER); */
 break;
  case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
  case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;

  }
  dance_state[0].step = 0;
}

/* void on_dance_Q(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_Q(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[1].step = dance_step(state); */
/*   switch (dance_state[1].step) { */
/*   case SINGLE_TAP: register_code16(KC_Q); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_Q)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_Q); */
/*     register_code16(KC_Q); */
/*     break; */
/*   } */
/* } */

/* void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[1].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_Q); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_Q)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_Q); */
/*     break; */
/*   } */
/*   dance_state[1].step = 0; */
/* } */

/* void on_dance_W(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_W_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_W_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_W(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[2].step = dance_step(state); */
/*   switch (dance_state[2].step) { */
/*   case SINGLE_TAP: register_code16(KC_W); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_W)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_W); */
/*     register_code16(KC_W); */
/*     break; */

/*   } */
/* } */

/* void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[2].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_W); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_W)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_W); */
/*     break; */

/*   } */
/*   dance_state[2].step = 0; */
/* } */

/* void on_dance_R(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_R_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_R_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_R(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[4].step = dance_step(state); */
/*   switch (dance_state[4].step) { */
/*   case SINGLE_TAP: register_code16(KC_R); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_R)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_R); */
/*     register_code16(KC_R); */
/*   } */
/* } */

/* void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[4].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_R); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_R)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_R); */
/*     break; */

/*   } */
/*   dance_state[4].step = 0; */
/* } */
/* void on_dance_T(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_T_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_T_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_T(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_T_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[5].step = dance_step(state); */
/*   switch (dance_state[5].step) { */
/*   case SINGLE_TAP: register_code16(KC_T); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_T)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_T); */
/*     register_code16(KC_T); */
/*     break; */
/*   } */
/* } */

/* void dance_T_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[5].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_T); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_T)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_T); */
/*     break; */
/*   } */
/*   dance_state[5].step = 0; */
/* } */


/* void on_dance_U(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_U_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_U_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_U(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_U_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[6].step = dance_step(state); */
/*   switch (dance_state[6].step) { */
/*   case SINGLE_TAP: register_code16(KC_U); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_U)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_U); */
/*     register_code16(KC_U); */
/*     break; */
/*   } */
/* } */

/* void dance_U_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[6].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_U); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_U)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_U); */
/*     break; */
/*   } */
/*   dance_state[6].step = 0; */
/* } */
/* void on_dance_I(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_I_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_I_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_I(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_I_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[7].step = dance_step(state); */
/*   switch (dance_state[7].step) { */
/*   case SINGLE_TAP: register_code16(KC_I); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_I)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_I); */
/*     register_code16(KC_I); */
/*     break; */

/*   } */
/* } */

/* void dance_I_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[7].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_I); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_I)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_I); */
/*     break; */
/*   } */
/*   dance_state[7].step = 0; */
/* } */

/* void on_dance_O(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_O_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_O_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_O(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_O_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[8].step = dance_step(state); */
/*   switch (dance_state[8].step) { */

/*   case SINGLE_TAP: register_code16(KC_O); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_O)); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     register_code16(KC_END); */
/*     break; */

/*   case DOUBLE_SINGLE_TAP: */
/*   case DOUBLE_TAP: */
/*     register_code16(KC_O); */
/*     register_code16(KC_O); */
/*     break; */

/*   } */
/* } */

/* void dance_O_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[8].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_O); break; */
/*   case SINGLE_HOLD: */
/*     unregister_code16(LSFT (KC_O)); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     unregister_code16(KC_END); */
/*     break; */

/*   case DOUBLE_SINGLE_TAP: */
/*   case DOUBLE_TAP: */
/*     unregister_code16(KC_O); */
/*     unregister_code16(KC_O); */
/*     break; */

/*   } */
/*   dance_state[8].step = 0; */
/* } */

/* void on_dance_P(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_P_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_P_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_P(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_P_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[9].step = dance_step(state); */
/*   switch (dance_state[9].step) { */
/*   case SINGLE_TAP: register_code16(KC_P); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_P)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_P); */
/*     register_code16(KC_P); */
/*     break; */

/*   } */
/* } */

/* void dance_P_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[9].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_P); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_P)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_P); */
/*     break; */

/*   } */
/*   dance_state[9].step = 0; */
/* } */

/* /\* void on_dance_A(qk_tap_dance_state_t *state, void *user_data); *\/ */
/* /\* void dance_A_finished(qk_tap_dance_state_t *state, void *user_data); *\/ */
/* /\* void dance_A_reset(qk_tap_dance_state_t *state, void *user_data); *\/ */

/* /\* void on_dance_A(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\* } *\/ */

/* /\* void dance_A_finished(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   dance_state[11].step = dance_step(state); *\/ */
/* /\*   switch (dance_state[11].step) { *\/ */
/* /\*   case SINGLE_TAP: register_code16(KC_A); break; *\/ */
/* /\*   case SINGLE_HOLD: *\/ */
/* /\*   case DOUBLE_HOLD: *\/ */
/* /\*     register_code16(LSFT (KC_A)); *\/ */
/* /\*     break; *\/ */

/* /\*   case DOUBLE_TAP: *\/ */
/* /\*   case DOUBLE_SINGLE_TAP: *\/ */
/* /\*     register_code16(KC_A); *\/ */
/* /\*     register_code16(KC_A); *\/ */
/* /\*     break; *\/ */
/* /\*   } *\/ */
/* /\* } *\/ */

/* /\* void dance_A_reset(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   wait_ms(10); *\/ */
/* /\*   switch (dance_state[11].step) { *\/ */
/* /\*   case SINGLE_TAP: unregister_code16(KC_A); break; *\/ */
/* /\*   case SINGLE_HOLD: *\/ */
/* /\*   case DOUBLE_HOLD: *\/ */
/* /\*     unregister_code16(LSFT (KC_A)); *\/ */
/* /\*     break; *\/ */

/* /\*   case DOUBLE_TAP: *\/ */
/* /\*   case DOUBLE_SINGLE_TAP: *\/ */
/* /\*     unregister_code16(KC_A); *\/ */
/* /\*     break; *\/ */
/* /\*   } *\/ */
/* /\*   dance_state[11].step = 0; *\/ */
/* /\* } *\/ */

/* void on_preonic_A(qk_tap_dance_state_t *state, void *user_data); */
/* void preonic_A_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void preonic_A_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_preonic_A(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void preonic_A_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[81].step = dance_step(state); */
/*   switch (dance_state[81].step) { */
/*   case SINGLE_TAP: register_code16(KC_A); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(KC_RCTL); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_A)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_A); */
/*     register_code16(KC_A); */
/*     break; */
/*   } */
/* } */

/* void preonic_A_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[81].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_A); break; */
/*   case SINGLE_HOLD: */
/*     unregister_code16(KC_RCTL); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_A)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_A); */
/*     break; */
/*   } */
/*   dance_state[81].step = 0; */
/* } */


/* void on_dance_S(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_S_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_S_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_S(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_S_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[12].step = dance_step(state); */
/*   switch (dance_state[12].step) { */
/*   case SINGLE_TAP: register_code16(KC_S); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_S)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_S); */
/*     register_code16(KC_S); */
/*     break; */
/*   } */
/* } */

/* void dance_S_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[12].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_S); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_S)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_S); */
/*     break; */
/*   } */
/*   dance_state[12].step = 0; */
/* } */


/* void on_dance_pb(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_pb_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_pb_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_pb(qk_tap_dance_state_t *state, void *user_data) { */

/* } */

/* void dance_pb_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[13].step = dance_step(state); */
/*   switch (dance_state[13].step) { */
/*   case SINGLE_TAP: register_code16(KC_LPRN); break; */
/*   case SINGLE_HOLD: register_code16(KC_RPRN); break; */

/*   case DOUBLE_TAP: register_code16(KC_LBRACKET);  break; */
/*   case DOUBLE_HOLD: register_code16(KC_RBRACKET); break; */
/*   case DOUBLE_SINGLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break; */

/*   case TRIPLE_TAP: register_code16(KC_LCBR);  break; */
/*   case TRIPLE_HOLD: register_code16(KC_RCBR); break; */
/*   case TRIPLE_SINGLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); register_code16(KC_LPRN); break; */


/*   } */
/* } */

/* void dance_pb_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[13].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_LPRN); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_RPRN); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_LBRACKET);  break; */
/*   case DOUBLE_HOLD: unregister_code16(KC_RBRACKET); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break; */

/*   case TRIPLE_TAP: */
/*   case TRIPLE_SINGLE_TAP: */
/*     unregister_code16(KC_LCBR);  break; */
/*   case TRIPLE_HOLD: unregister_code16(KC_RCBR); break; */

/*   } */
/*   dance_state[13].step = 0; */
/* } */


/* void on_dance_K(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_K_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_K_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_K(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_K_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[17].step = dance_step(state); */
/*   switch (dance_state[17].step) { */
/*   case SINGLE_TAP: register_code16(KC_K); break; */
/*   case SINGLE_HOLD: register_code16(RSFT(KC_K)); break; */
/*   case DOUBLE_TAP: register_code16(RCTL(KC_SCOLON)); break; */
/*   case DOUBLE_HOLD: register_code16(KC_UP); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K); */
/*   } */
/* } */

/* void dance_K_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[17].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_K); break; */
/*   case SINGLE_HOLD: unregister_code16(RSFT(KC_K)); break; */
/*   case DOUBLE_TAP: unregister_code16(RCTL(KC_SCOLON)); break; */
/*   case DOUBLE_HOLD: unregister_code16(KC_UP); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break; */
/*   } */
/*   dance_state[17].step = 0; */
/* } */
/* void on_dance_L(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_L_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_L_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_L(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_L_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[18].step = dance_step(state); */
/*   switch (dance_state[18].step) { */
/*   case SINGLE_TAP: register_code16(KC_L); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_L)); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     register_code(KC_RIGHT); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_L); */
/*     register_code16(KC_L); */
/*     break; */

/*   } */
/* } */

/* void dance_L_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[18].step) { */


/*   case SINGLE_TAP: unregister_code16(KC_L); break; */
/*   case DOUBLE_HOLD: */
/*     unregister_code(KC_RIGHT); */
/*     break; */

/*   case SINGLE_HOLD: */
/*     unregister_code16(LSFT (KC_L)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_L); */
/*     break; */
/*   } */
/*   dance_state[18].step = 0; */
/* } */



/* void on_dance_N(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_N_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_N_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_N(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_N_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[21].step = dance_step(state); */
/*   switch (dance_state[21].step) { */
/*   case SINGLE_TAP: register_code16(KC_N); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_N)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_N); */
/*     register_code16(KC_N); */
/*     break; */

/*   } */
/* } */

/* void dance_N_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[21].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_N); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_N)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_N); */
/*     break; */

/*   } */
/*   dance_state[21].step = 0; */
/* } */

/* void on_dance_M(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_M_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_M_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_M(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_M_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[22].step = dance_step(state); */
/*   switch (dance_state[22].step) { */

/*   case SINGLE_TAP: register_code16(KC_M); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_M)); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     register_code16(KC_1); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_M); */
/*     register_code16(KC_M); */
/*     break; */

/*   } */
/* } */

/* void dance_M_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[22].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_M); break; */
/*   case SINGLE_HOLD: */
/*     unregister_code16(LSFT (KC_M)); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(KC_1); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_M); */
/*     break; */
/*   } */
/*   dance_state[22].step = 0; */
/* } */

/* void on_dance_space(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_space_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_space_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_space(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_space_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[23].step = dance_step(state); */
/*   switch (dance_state[23].step) { */
/*   case SINGLE_TAP: register_code16(KC_SPACE); break; */
/*   case SINGLE_HOLD: tap_code16(KC_SPACE); break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*   case DOUBLE_HOLD: */
/*     register_code16(KC_SPACE); register_code16(KC_SPACE); break; */
/*   } */
/* } */

/* void dance_space_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*     unregister_code16(KC_SPACE); */
/*   dance_state[23].step = 0; */
/* } */

/* void on_www_back_forward(qk_tap_dance_state_t *state, void *user_data); */
/* void www_back_forward_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void www_back_forward_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_www_back_forward(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void www_back_forward_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[27].step = dance_step(state); */
/*   switch (dance_state[27].step) { */
/*   case SINGLE_TAP: register_code16(LALT(KC_LEFT)); break; */
/*   case DOUBLE_TAP: register_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); break; */
/*   case DOUBLE_HOLD: register_code16(LALT(KC_RIGHT)); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); */
/*   } */
/* } */

/* void www_back_forward_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[27].step) { */
/*   case SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break; */
/*   case DOUBLE_TAP: unregister_code16(LALT(KC_LEFT)); break; */
/*   case DOUBLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break; */
/*   } */
/*   dance_state[27].step = 0; */
/* } */

/* void on_dance_37(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_37_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_37_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_37(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_37_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[37].step = dance_step(state); */
/*   switch (dance_state[37].step) { */
/*   case SINGLE_TAP: register_code16(KC_TAB); break; */
/*   case SINGLE_HOLD: layer_move(0); break; */
/*   case DOUBLE_TAP: register_code16(KC_GRAVE); break; */
/*   case DOUBLE_HOLD: register_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB); */
/*   } */
/* } */

/* void dance_37_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[37].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_TAB); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_GRAVE); break; */
/*   case DOUBLE_HOLD: unregister_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break; */
/*   } */
/*   dance_state[37].step = 0; */
/* } */


/* void on_dance_comma(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_comma_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_comma_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_comma(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* /\* void dance_comma_finished(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   dance_state[99].step = dance_step(state); *\/ */
/* /\*   switch (dance_state[99].step) { *\/ */
/* /\*   case SINGLE_TAP: register_code16(KC_COMMA); break; *\/ */
/* /\*   case SINGLE_HOLD: *\/ */
/* /\*     register_code16(LSFT (KC_COMMA)); *\/ */
/* /\*     break; *\/ */

/* /\*   case DOUBLE_HOLD: *\/ */
/* /\*     register_code16(KC_2); *\/ */
/* /\*     break; *\/ */

/* /\*   case DOUBLE_SINGLE_TAP: *\/ */
/* /\*   case DOUBLE_TAP: *\/ */
/* /\*     register_code16(KC_COMMA); *\/ */
/* /\*     register_code16(KC_COMMA); *\/ */
/* /\*     break; *\/ */

/* /\*   } *\/ */
/* /\* } *\/ */

/* /\* void dance_comma_reset(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   wait_ms(10); *\/ */
/* /\*   switch (dance_state[99].step) { *\/ */
/* /\*   case DOUBLE_HOLD: *\/ */
/* /\*     unregister_code16(KC_2); *\/ */
/* /\*     break; *\/ */

/* /\*   default: *\/ */
/* /\*     unregister_code16(KC_COMMA); *\/ */
/* /\*     break; *\/ */
/* /\*   } *\/ */
/* /\*   dance_state[99].step = 0; *\/ */
/* /\* } *\/ */


/* void on_dance_Y(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_Y(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[41].step = dance_step(state); */
/*   switch (dance_state[41].step) { */
/*   case SINGLE_TAP: register_code16(KC_Y); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_Y)); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     register_code16(KC_END); */
/*     break; */

/*   case DOUBLE_SINGLE_TAP: */
/*   case DOUBLE_TAP: */
/*     register_code16(KC_Y); */
/*     register_code16(KC_Y); */
/*     break; */

/*   } */
/* } */

/* void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[41].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_Y); break; */
/*   case SINGLE_HOLD: */
/*     unregister_code16(LSFT (KC_Y)); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     unregister_code16(KC_END); */
/*     break; */

/*   case DOUBLE_SINGLE_TAP: */
/*   case DOUBLE_TAP: */
/*     unregister_code16(KC_Y); */
/*     break; */

/*   } */
/*   dance_state[41].step = 0; */
/* } */


/* void on_dance_45(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_45_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_45_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_45(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_45_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[45].step = dance_step(state); */
/*   switch (dance_state[45].step) { */
/*   case SINGLE_TAP: register_code16(LGUI(KC_L)); break; */
/*   case DOUBLE_TAP: register_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); break; */
/*   case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); */
/*   } */
/* } */

/* void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[45].step) { */
/*   case SINGLE_TAP: unregister_code16(LGUI(KC_L)); break; */
/*   case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break; */
/*   case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_L)); break; */
/*   } */
/*   dance_state[45].step = 0; */
/* } */
/* void on_dance_46(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_46_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_46_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_46(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_46_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[46].step = dance_step(state); */
/*   switch (dance_state[46].step) { */
/*   case SINGLE_TAP: register_code16(LGUI(KC_N)); break; */
/*   case DOUBLE_TAP: register_code16(LGUI(KC_N)); register_code16(LGUI(KC_N)); break; */
/*   case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_N)); register_code16(LGUI(KC_N)); */
/*   } */
/* } */

/* void dance_46_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[46].step) { */
/*   case SINGLE_TAP: unregister_code16(LGUI(KC_N)); break; */
/*   case DOUBLE_TAP: unregister_code16(LGUI(KC_N)); break; */
/*   case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_N)); break; */
/*   } */
/*   dance_state[46].step = 0; */
/*   } */

/* void dance_51_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_51_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void dance_51_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[51].step = dance_step(state); */
/*   switch (dance_state[51].step) { */
/*   case DOUBLE_HOLD: register_code16(RCTL(RGUI(KC_Q))); break; */
/*   } */
/* } */

/* void dance_51_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[51].step) { */
/*   case DOUBLE_HOLD: unregister_code16(RCTL(RGUI(KC_Q))); break; */
/*   } */
/*   dance_state[51].step = 0; */
/* } */
/* void on_dance_52(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_52_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_52_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_52(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_52_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[52].step = dance_step(state); */
/*   switch (dance_state[52].step) { */
/*   case SINGLE_TAP: register_code16(KC_TAB); break; */
/*   case SINGLE_HOLD: layer_move(0); break; */
/*   case DOUBLE_TAP: register_code16(KC_GRAVE); break; */
/*   case DOUBLE_HOLD: register_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB); */
/*   } */
/* } */

/* void dance_52_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[52].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_TAB); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_GRAVE); break; */
/*   case DOUBLE_HOLD: unregister_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break; */
/*   } */
/*   dance_state[52].step = 0; */
/* } */
/* void on_dance_53(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_53_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_53_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_53(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_53_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[53].step = dance_step(state); */
/*   switch (dance_state[53].step) { */
/*   case SINGLE_TAP: register_code16(KC_TILD); break; */
/*   case SINGLE_HOLD: layer_move(0); break; */
/*   case DOUBLE_TAP: register_code16(KC_TILD); register_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_TILD); register_code16(KC_TILD); */
/*   } */
/* } */

/* void dance_53_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[53].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_TILD); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_TILD); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_TILD); break; */
/*   } */
/*   dance_state[53].step = 0; */
/* } */
/* void on_dance_54(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_54_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_54_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_54(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_54_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[54].step = dance_step(state); */
/*   switch (dance_state[54].step) { */
/*   case SINGLE_TAP: register_code16(KC_UNDS); break; */
/*   case SINGLE_HOLD: register_code16(KC_PLUS); break; */
/*   case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS); */
/*   } */
/* } */

/* void dance_54_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[54].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_UNDS); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_PLUS); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_UNDS); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break; */
/*   } */
/*   dance_state[54].step = 0; */
/* } */

/* void on_dance_56(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_56_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_56_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_56(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_56_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[56].step = dance_step(state); */
/*   switch (dance_state[56].step) { */
/*   case SINGLE_TAP: register_code16(KC_DQUO); break; */
/*   case SINGLE_HOLD: register_code16(KC_RCBR); break; */
/*   case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO); */
/*   } */
/* } */

/* void dance_56_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[56].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_DQUO); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_RCBR); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_DQUO); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break; */
/*   } */
/*   dance_state[56].step = 0; */
/* } */
/* void dance_57_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_57_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void dance_57_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[57].step = dance_step(state); */
/*   switch (dance_state[57].step) { */
/*   case SINGLE_TAP: layer_move(6); break; */
/*   case SINGLE_HOLD: layer_move(0); break; */
/*   case DOUBLE_TAP: layer_move(6); break; */
/*   case DOUBLE_SINGLE_TAP: layer_move(6); break; */
/*   } */
/* } */

/* void dance_57_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[57].step) { */
/*   } */
/*   dance_state[57].step = 0; */
/* } */

/* void on_dance_61(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_61_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_61_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_61(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_61_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[61].step = dance_step(state); */
/*   switch (dance_state[61].step) { */
/*   case SINGLE_TAP: register_code16(KC_GRAVE); break; */
/*   case SINGLE_HOLD: register_code16(KC_TILD); break; */
/*   case DOUBLE_TAP: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE); */
/*   } */
/* } */

/* void dance_61_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[61].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_GRAVE); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_TILD); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_GRAVE); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break; */
/*   } */
/*   dance_state[61].step = 0; */
/* } */
/* void on_dance_H(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_H_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_H_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_H(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_H_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[62].step = dance_step(state); */
/*   switch (dance_state[62].step) { */
/*   case SINGLE_TAP: register_code16(KC_H); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_H)); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     register_code16(KC_HOME); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_H); */
/*     register_code16(KC_H); */
/*     break; */

/*   } */
/* } */

/* void dance_H_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[62].step) { */


/*   case SINGLE_TAP: unregister_code16(KC_H); break; */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(KC_HOME); */
/*   case SINGLE_HOLD: */
/*     unregister_code16(LSFT (KC_H)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_H); */
/*     break; */

/*   /\* case SINGLE_TAP: unregister_code16(KC_H); break; *\/ */
/*   /\* case SINGLE_HOLD: unregister_code16(KC_LEFT); break; *\/ */
/*   /\* case DOUBLE_TAP: unregister_code16(KC_H); break; *\/ */
/*   /\* case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break; *\/ */
/*   /\* case DOUBLE_HOLD:  unregister_code16(RSFT(KC_H));break; *\/ */
/*   } */
/*   dance_state[62].step = 0; */
/* } */

/* void dance_J_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_J_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_J(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_J_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[63].step = dance_step(state); */
/*   switch (dance_state[63].step) { */
/*   case SINGLE_TAP: register_code16(KC_J); break; */
/*   case SINGLE_HOLD: register_code16(RSFT(KC_J)); break; */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_J); */
/*     register_code16(KC_J); */
/*     break; */

/*   case DOUBLE_HOLD: */
/*     register_code(KC_DOWN); */
/*     break; */
/*   case DOUBLE_TAP: */
/*     register_code(KC_ESC);  break; */
/*   } */
/* } */

/* void dance_J_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[63].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_J); break; */
/*   case SINGLE_HOLD: unregister_code16(RSFT(KC_J)); break; */

/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_J); */
/*     break; */
/*   case DOUBLE_HOLD: */
/*     unregister_code(KC_DOWN); */
/*     break; */
/*   case DOUBLE_TAP: unregister_code(KC_ESC);  break; */

/*   } */
/*   dance_state[63].step = 0; */
/* } */
/* void on_dance_64(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_64_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_64_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_64(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_64_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[64].step = dance_step(state); */
/*   switch (dance_state[64].step) { */
/*   case SINGLE_TAP: register_code16(KC_K); break; */
/*   case SINGLE_HOLD: register_code16(KC_K); break; */
/*   case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K); */
/*   } */
/* } */

/* void dance_64_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[64].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_K); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_K); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_K); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break; */
/*   } */
/*   dance_state[64].step = 0; */
/* } */
/* void on_dance_65(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_65_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_65_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_65(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_65_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[65].step = dance_step(state); */
/*   switch (dance_state[65].step) { */
/*   case SINGLE_TAP: register_code16(KC_L); break; */
/*   case SINGLE_HOLD: register_code16(KC_L); break; */
/*   case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L); */
/*   } */
/* } */

/* void dance_65_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[65].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_L); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_L); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_L); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break; */
/*   } */
/*   dance_state[65].step = 0; */
/* } */
/* void on_dance_66(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_66_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_66_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_66(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_66_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[66].step = dance_step(state); */
/*   switch (dance_state[66].step) { */
/*   case SINGLE_TAP: register_code16(KC_DELETE); break; */
/*   case SINGLE_HOLD: register_code16(KC_DELETE); break; */
/*   case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE); */
/*   } */
/* } */

/* void dance_66_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[66].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_DELETE); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_DELETE); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_DELETE); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break; */
/*   } */
/*   dance_state[66].step = 0; */
/* } */
/* void on_dance_67(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_67_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_67_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_67(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_67_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[67].step = dance_step(state); */
/*   switch (dance_state[67].step) { */
/*   case SINGLE_TAP: register_code16(KC_N); break; */
/*   case SINGLE_HOLD: register_code16(KC_N); break; */
/*   case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N); */
/*   } */
/* } */

/* void dance_67_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[67].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_N); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_N); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_N); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break; */
/*   } */
/*   dance_state[67].step = 0; */
/* } */
/* void on_dance_68(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_68_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_68_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_68(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_68_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[68].step = dance_step(state); */
/*   switch (dance_state[68].step) { */
/*   case SINGLE_TAP: register_code16(RCTL(KC_HOME)); break; */
/*   case SINGLE_HOLD: register_code16(RCTL(KC_END)); break; */
/*   case DOUBLE_TAP: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); */
/*   } */
/* } */

/* void dance_68_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[68].step) { */
/*   case SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   case SINGLE_HOLD: unregister_code16(RCTL(KC_END)); break; */
/*   case DOUBLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   } */
/*   dance_state[68].step = 0; */
/* } */


/* void on_t_alt_tab_h_base(qk_tap_dance_state_t *state, void *user_data); */
/* void t_alt_tab_h_base_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void t_alt_tab_h_base_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_t_alt_tab_h_base(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void t_alt_tab_h_base_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[70].step = dance_step(state); */
/*   switch (dance_state[70].step) { */
/*   case SINGLE_TAP: register_code16(RCTL(KC_HOME)); break; */
/*   case SINGLE_HOLD: register_code16(RCTL(KC_END)); break; */
/*   case DOUBLE_TAP: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); */
/*   } */
/* } */

/* void t_alt_tab_h_base_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[70].step) { */
/*   case SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   case SINGLE_HOLD: unregister_code16(RCTL(KC_END)); break; */
/*   case DOUBLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break; */
/*   } */
/*   dance_state[70].step = 0; */
/* } */


/* /\* void on_dance_69(qk_tap_dance_state_t *state, void *user_data); *\/ */
/* /\* void dance_69_finished(qk_tap_dance_state_t *state, void *user_data); *\/ */
/* /\* void dance_69_reset(qk_tap_dance_state_t *state, void *user_data); *\/ */

/* /\* void on_dance_69(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\* } *\/ */

/* /\* void dance_69_finished(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   dance_state[29].step = dance_step(state); *\/ */
/* /\*   switch (dance_state[29].step) { *\/ */
/* /\*   case SINGLE_TAP: register_code16(KC_N); break; *\/ */
/* /\*   case SINGLE_HOLD: register_code16(KC_N); break; *\/ */
/* /\*   case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break; *\/ */
/* /\*   case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N); *\/ */
/* /\*   } *\/ */
/* /\* } *\/ */

/* /\* void dance_69_reset(qk_tap_dance_state_t *state, void *user_data) { *\/ */
/* /\*   wait_ms(10); *\/ */
/* /\*   switch (dance_state[29].step) { *\/ */
/* /\*   case SINGLE_TAP: unregister_code16(KC_N); break; *\/ */
/* /\*   case SINGLE_HOLD: unregister_code16(KC_N); break; *\/ */
/* /\*   case DOUBLE_TAP: unregister_code16(KC_N); break; *\/ */
/* /\*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break; *\/ */
/* /\*   } *\/ */
/* /\*   dance_state[29].step = 0; *\/ */
/* /\* } *\/ */



/* void on_dance_73(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_73_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_73_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_73(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_73_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[73].step = dance_step(state); */
/*   switch (dance_state[73].step) { */
/*   case SINGLE_TAP: register_code16(KC_PSCREEN); break; */
/*   case SINGLE_HOLD: register_code16(KC_PSCREEN); break; */
/*   case DOUBLE_TAP: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break; */
/*   case DOUBLE_HOLD: register_code16(RGUI(KC_PSCREEN)); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN); */
/*   } */
/* } */

/* void dance_73_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[73].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_PSCREEN); break; */
/*   case SINGLE_HOLD: unregister_code16(KC_PSCREEN); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_PSCREEN); break; */
/*   case DOUBLE_HOLD: unregister_code16(RGUI(KC_PSCREEN)); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_PSCREEN); break; */
/*   } */
/*   dance_state[73].step = 0; */
/* } */


/* void on_dance_V(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_V_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_V_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_V(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_V_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[74].step = dance_step(state); */
/*   switch (dance_state[74].step) { */
/*   case SINGLE_TAP: register_code16(KC_V); break; */
/*   case SINGLE_HOLD: */
/*     register_code16(LSFT (KC_V)); */
/*  break; */
/*   case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break; */
/*   case DOUBLE_HOLD: layer_on(_AUDIO); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V); */
/*   } */
/* } */

/* void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[74].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_V); break; */
/*   case SINGLE_HOLD:  unregister_code16(RSFT( KC_V )); break; */
/*   case DOUBLE_HOLD:  layer_off(_AUDIO);  break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break; */
/*   } */
/*   dance_state[74].step = 0; */
/* } */


/* void on_dance_z(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_z_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_z_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_z(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[76].step = dance_step(state); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: register_code16(KC_Z); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_Z)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_Z); */
/*     register_code16(KC_Z); */

/*   } */
/* } */

/* void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_Z); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_Z)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_Z); */
/*     break; */

/*   } */
/*   dance_state[76].step = 0; */
/* } */



/* void on_windows_or_alt_tab(qk_tap_dance_state_t *state, void *user_data); */
/* void windows_or_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void windows_or_alt_tab_reset(qk_tap_dance_state_t *state, void *user_data); */


/* void on_windows_or_alt_tab(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void windows_or_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[76].step = dance_step(state); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: layer_on(_WINDOWS); break; */
/*   case SINGLE_HOLD: register_code16(KC_RGUI) ; break; */
/*   case DOUBLE_TAP: register_code16(KC_RGUI); register_code16(KC_RGUI); break; */
/*     /\* case DOUBLE_TAP: register_code16(ALT_TAB); break; *\/ */
/*   case DOUBLE_HOLD: register_code16(KC_RGUI) ; break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_RGUI); register_code16(KC_RGUI); */
/*   } */
/* } */

/* void windows_or_alt_tab_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: layer_off(_WINDOWS); break; */
/*   case SINGLE_HOLD: unregister_code16( KC_RGUI ); break; */
/*     /\* case DOUBLE_TAP: unregister_code16(ALT_TAB); break; *\/ */
/*   case DOUBLE_TAP: unregister_code16(KC_RGUI); break; */
/*   case DOUBLE_HOLD: unregister_code16(KC_RGUI) ;break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_RGUI); break; */
/*   } */
/*   dance_state[76].step = 0; */
/* } */

/* void on_dance_B(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_B_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_B_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_B(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_B_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[76].step = dance_step(state); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: register_code16(KC_B); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_B)); break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_B); register_code16(KC_B); */
/*     break; */
/*   } */
/* } */

/* void dance_B_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[76].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_B); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_B)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_B); */
/*     break; */
/*   } */
/*   dance_state[76].step = 0; */
/* } */

/* void on_dance_C(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_C_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_C_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_C(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_C_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[77].step = dance_step(state); */
/*   switch (dance_state[77].step) { */
/*   case SINGLE_TAP: register_code16(KC_C); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_C)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_C); */
/*     register_code16(KC_C); */
/*     break; */

/*   } */
/* } */

/* void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[77].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_C); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_C)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_C); */
/*     break; */
/*   } */
/*   dance_state[77].step = 0; */
/* } */

/* void on_dance_D(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_D_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_D_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_D(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_D_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[78].step = dance_step(state); */
/*   switch (dance_state[78].step) { */
/*   case SINGLE_TAP: register_code16(KC_D); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_D)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_D); */
/*     register_code16(KC_D); */
/*     break; */
/*   } */
/* } */

/* void dance_D_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[78].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_D); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_D)); */
/*     break; */

/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_D); */
/*     break; */
/*   } */
/*   dance_state[78].step = 0; */
/* } */

/* void on_dance_E(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_E_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_E_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_E(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_E_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[3].step = dance_step(state); */
/*   switch (dance_state[3].step) { */

/*   case SINGLE_TAP: register_code16(KC_E); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_E)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_E); */
/*     register_code16(KC_E); */
/*     break; */

/*   } */
/* } */

/* void dance_E_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[3].step) { */

/*   case SINGLE_TAP: unregister_code16(KC_E); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_E)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_E); */
/*     break; */
/*   } */
/*   dance_state[3].step = 0; */
/* } */

/* void on_dance_F(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_F_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_F_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_F(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_F_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[14].step = dance_step(state); */
/*   switch (dance_state[14].step) { */
/*   case SINGLE_TAP: register_code16(KC_F); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_F)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_F); */
/*     register_code16(KC_F); */
/*     break; */
/*   } */
/* } */

/* void dance_F_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[14].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_F); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_F)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_F); */
/*     break; */
/*   } */
/*   dance_state[14].step = 0; */
/* } */

/* void on_dance_G(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_G_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_G_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_G(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_G_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[15].step = dance_step(state); */
/*   switch (dance_state[15].step) { */
/*   case SINGLE_TAP: register_code16(KC_G); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_G)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_G); */
/*     register_code16(KC_G); */
/*     break; */
/*   } */
/* } */

/* void dance_G_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[15].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_G); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_G)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_G); */
/*     break; */

/*   } */
/*   dance_state[15].step = 0; */
/* } */



/* void on_dance_X(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_X_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_X_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_X(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_X_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[79].step = dance_step(state); */
/*   switch (dance_state[79].step) { */
/*   case SINGLE_TAP: register_code16(KC_X); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_X)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_X); */
/*     register_code16(KC_X); */
/*     break; */
/*   } */
/* } */

/* void dance_X_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[79].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_X); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_X)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_X); */
/*     break; */
/*   } */
/*   dance_state[79].step = 0; */
/* } */


/* void on_dance_save_load_ns_switch(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_save_load_ns_switch_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_save_load_ns_switch_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_save_load_ns_switch(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_save_load_ns_switch_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[83].step = dance_step(state); */
/*   switch (dance_state[83].step) { */
/*   case SINGLE_TAP: register_code16(RCTL(KC_SCOLON)); break; */
/*   case SINGLE_HOLD: */
/*     tap_code16(RCTL(KC_SCOLON)); */
/*     tap_code16(RCTL(KC_C)); */
/*     tap_code16(RCTL(KC_K)); */
/*  break; */
/*   default: */
/*     register_code16(RCTL(KC_QUOT)); */
/*     break; */
/*   } */
/* } */

/* void dance_save_load_ns_switch_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[83].step) { */
/*   case SINGLE_TAP: unregister_code16(RCTL(KC_SCOLON)); break; */
/*   /\* case SINGLE_HOLD: *\/ */
/*   /\*   tap_code16(RCTL(KC_SCOLON)); *\/ */
/*   /\*   tap_code16(RCTL(KC_C)); *\/ */
/*   /\*   tap_code16(RCTL(KC_K)); *\/ */
/*     /\* break; *\/ */
/*   default: */
/*     unregister_code16(RCTL(KC_QUOT)); */
/*     break; */

/*   } */
/*   dance_state[83].step = 0; */
/* } */


/* void on_dance_min_or_exit(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_min_or_exit_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_min_or_exit_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_min_or_exit(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_min_or_exit_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[80].step = dance_step(state); */
/*   switch (dance_state[80].step) { */
/*   case SINGLE_TAP: register_code16(KC_X); break; */
/*   case SINGLE_HOLD: register_code16(KC_X); break; */
/*   case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break; */
/*   case DOUBLE_HOLD: register_code16(LSFT (KC_X)); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X); */
/*   } */
/* } */

/* void dance_min_or_exit_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[80].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_X); break; */
/*   case SINGLE_HOLD:  unregister_code16(KC_X); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_X); break; */
/*   case DOUBLE_HOLD: unregister_code16(LSFT (KC_X)); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break; */
/*   } */
/*   dance_state[80].step = 0; */
/* } */
/* void on_preonic_Z(qk_tap_dance_state_t *state, void *user_data); */
/* void preonic_Z_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void preonic_Z_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_preonic_Z(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void preonic_Z_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[82].step = dance_step(state); */
/*   switch (dance_state[82].step) { */
/*   case SINGLE_TAP: register_code16(KC_Z); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     register_code16(LSFT (KC_Z)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     register_code16(KC_Z); */
/*     register_code16(KC_Z); */
/*     break; */
/*   } */
/* } */

/* void preonic_Z_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state[82].step) { */
/*   case SINGLE_TAP: unregister_code16(KC_Z); break; */
/*   case SINGLE_HOLD: */
/*   case DOUBLE_HOLD: */
/*     unregister_code16(LSFT (KC_Z)); */
/*     break; */
/*   case DOUBLE_TAP: */
/*   case DOUBLE_SINGLE_TAP: */
/*     unregister_code16(KC_Z); */
/*     break; */
/*   } */
/*   dance_state[82].step = 0; */
/* } */


/* void on_dance_mic(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_mic_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_mic_reset(qk_tap_dance_state_t *state, void *user_data); */

/* void on_dance_mic(qk_tap_dance_state_t *state, void *user_data) { */
/* } */

/* void dance_mic_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state[84].step = dance_step(state); */
/*   switch (dance_state[84].step) { */
/*   case SINGLE_TAP: */
/*     tap_code16(RCTL(RALT(RGUI(KC_DOWN)))); */
/*     break; */
/*   case SINGLE_HOLD: */
/*     tap_code16(RCTL(RALT(RGUI(KC_UP)))); */
/*  break; */
/*   } */
/* } */

/* void dance_mic_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   dance_state[84].step = 0; */
/* } */

qk_tap_dance_action_t tap_dance_actions[] = {

                                             [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
                                             /* [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset), */
                                             /* [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset), */
                                             /* [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset), */
                                             /* [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset), */
                                             /* [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset), */
                                             /* [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset), */
                                             /* [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset), */
                                             /* [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset), */
                                             /* [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset), */
                                             /* [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset), */
                                             /* [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset), */
                                             /* [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset), */
                                             /* [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset), */
                                             /* [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset), */
                                             /* [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset), */
                                             /* [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset), */
                                             /* [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset), */
                                             /* [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset), */
                                             /* [DANCE_69] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_69, dance_69_finished, dance_69_reset), */
                                             /* [DANCE_73] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_73, dance_73_finished, dance_73_reset), */
                                             /* [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset), */
                                             /* [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset), */
                                             /* [DANCE_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_comma, dance_comma_finished, dance_comma_reset), */
                                             /* [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset), */
                                             /* [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset), */
                                             /* [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset), */
                                             /* [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset), */
                                             /* [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset), */
                                             /* [DANCE_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_H, dance_H_finished, dance_H_reset), */
                                             /* [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset), */
                                             /* [DANCE_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_J, dance_J_finished, dance_J_reset), */
                                             /* [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset), */
                                             /* [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset), */
                                             /* [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset), */
                                             /* [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset), */
                                             /* [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset), */
                                             /* [DANCE_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_P, dance_P_finished, dance_P_reset), */
                                             /* [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset), */
                                             /* [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset), */
                                             /* [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset), */
                                             /* [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset), */
                                             /* [DANCE_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U, dance_U_finished, dance_U_reset), */
                                             /* [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_V, dance_V_finished, dance_V_reset), */
                                             /* [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_W, dance_W_finished, dance_W_reset), */
                                             /* [DANCE_PAREN_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_pb, dance_pb_finished, dance_pb_reset), */
                                             /* [DANCE_SAVE_LOAD_NS_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_save_load_ns_switch, dance_save_load_ns_switch_finished, dance_save_load_ns_switch_reset), */
                                             /* [DANCE_MIC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_mic, dance_mic_finished, dance_mic_reset), */
                                             /* [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset), */
                                             /* [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset), */
                                             /* [WWW_BACK_FORWARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_www_back_forward, www_back_forward_finished, www_back_forward_reset), */

};
