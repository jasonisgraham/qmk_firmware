void alpha_char_default_finished(uint16_t k, int state_idx, tap_dance_state_t *state) {
  dance_state[state_idx].step = dance_step(state);
  switch (dance_state[state_idx].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP: tap_code16(k);
    break;
  case HOLD:
    register_key(k);
    break;
  case HOLD2:
    register_code16(LGUI(k));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(k);
    tap_code16(k);
    break;
  }
}

void alpha_char_default_reset(uint16_t k, int state_idx) {
  wait_ms(10);
  switch (dance_state[state_idx].step) {
  case HOLD:
    unregister_key(k);
    break;

  case HOLD2:
    unregister_code16(LGUI(k));
    break;
  }
  dance_state[state_idx].step = 0;
}



void on_dance_A(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_A, state, user_data);
}

void dance_A_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[11].step = dance_step(state);
  switch (dance_state[11].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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
  }
}

void dance_A_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[11].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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

void on_dance_b(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_B);
    tap_code16(KC_B);
    tap_code16(KC_B);
  }
  if(state->count > 3) {
    tap_code16(KC_B);
  }
}

void dance_b_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[64].step = dance_step(state);
  switch (dance_state[64].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_B); break;
  case HOLD:
    register_key(KC_B); break;
  case TAP2: register_code16(KC_B); register_code16(KC_B); break;
  case TAP2_INTERRUPTED: tap_code16(KC_B); register_code16(KC_B);
  }
}

void dance_b_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[64].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_B); break;
  case HOLD:
    unregister_key(KC_B); break;
  case TAP2: unregister_code16(KC_B); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_B); break;
  }
  dance_state[64].step = 0;
}


void on_dance_C(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_C);
    tap_code16(KC_C);
    tap_code16(KC_C);
  }
  if(state->count > 3) {
    tap_code16(KC_C);
  }
}

void dance_C_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[77].step = dance_step(state);
  switch (dance_state[77].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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

void dance_C_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[77].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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





void on_dance_D(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_D);
    tap_code16(KC_D);
    tap_code16(KC_D);
  }
  if(state->count > 3) {
    tap_code16(KC_D);
  }
}

void dance_D_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[78].step = dance_step(state);
  switch (dance_state[78].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_D); break;
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

void dance_D_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[78].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP:  break;
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





void on_dance_E(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_E);
    tap_code16(KC_E);
    tap_code16(KC_E);
  }
  if(state->count > 3) {
    tap_code16(KC_E);
  }
}

void dance_E_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {

    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_E); break;
  case HOLD:
    register_key(KC_E); break;
  case HOLD2:
      tap_code16(TERM_PASTE);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_E);
    tap_code16(KC_E);
    break;

  }
}

void dance_E_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {

    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_E); break;
  case HOLD:
    unregister_key(KC_E); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_E);
    break;
  }
  dance_state[3].step = 0;
}





void on_dance_F(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F);
    tap_code16(KC_F);
    tap_code16(KC_F);
  }
  if(state->count > 3) {
    tap_code16(KC_F);
  }
}

void dance_F_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[14].step = dance_step(state);
  switch (dance_state[14].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_F); break;
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

void dance_F_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[14].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP:  break;
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





void on_dance_G(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_G, state, user_data);
}

void dance_G_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[15].step = dance_step(state);
  switch (dance_state[15].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_G); break;
  case HOLD:
    register_key(KC_G); break;
  case HOLD2:
    tap_code16(LGUI(KC_T));
    tap_code16(RCTL(LALT(KC_G)));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_G);
    register_code16(KC_G);
    break;
  }
}

void dance_G_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[15].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_G); break;
  case HOLD:
    unregister_key(KC_G); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_G);
    break;

  }
  dance_state[15].step = 0;
}



void on_dance_H(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_H);
    tap_code16(KC_H);
    tap_code16(KC_H);
  }
  if(state->count > 3) {
    tap_code16(KC_H);
  }
}

void dance_H_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[62].step = dance_step(state);
  switch (dance_state[62].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_H); break;
  case HOLD:
    register_key(KC_H); break;
  case HOLD2:
    register_code16(KC_LEFT);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_H);
    register_code16(KC_H);
    break;

  }
}

void dance_H_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[62].step) {


    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_H); break;
  case HOLD2:
    unregister_code16(KC_LEFT);
  case HOLD:
    unregister_key(KC_H); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_H);
    break;

  /*   case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_H); break; */
  /* case HOLD: unregister_code16(KC_LEFT); break; */
  /* case TAP2: unregister_code16(KC_H); break; */
  /* case TAP2_INTERRUPTED: unregister_code16(KC_H); break; */
  /* case HOLD2:  unregister_code16(RSFT(KC_H));break; */
  }
  dance_state[62].step = 0;
}


void on_dance_I(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_I, state, user_data);
}

void dance_I_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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

void dance_I_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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


void on_dance_J(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_J, state, user_data);
}

void dance_J_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[63].step = dance_step(state);
  switch (dance_state[63].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_J); break;
  case HOLD:
    register_key(KC_J); break;
  case TAP2_INTERRUPTED:
    register_code16(KC_J);
    register_code16(KC_J);
    break;


  case HOLD2:
    register_code16(KC_DOWN);
    break;
  case TAP2:
    tap_code16(KC_ESC);
    break;

  }
}

void dance_J_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[63].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_J); break;
  case HOLD:
    unregister_key(KC_J); break;

  case TAP2_INTERRUPTED:
    unregister_code16(KC_J);
    break;
  case HOLD2:
    unregister_code16(KC_DOWN);
    break;
  case TAP2:
     break;

  }
  dance_state[63].step = 0;
}


void on_dance_K(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_K, state, user_data);
}

void dance_K_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[17].step = dance_step(state);
  switch (dance_state[17].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_K); break;

  case HOLD:
    register_key(KC_K); break;
  case HOLD2:
    register_code16(KC_UP);
    break;

  case TAP2:
      save_all_and_esc();
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_off_sound);
#endif
      break;
  case TAP2_INTERRUPTED: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_K_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[17].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(KC_K); break;

  case HOLD:
    unregister_key(KC_K); break;
  /* case HOLD2: */
  /*   /\* unregister_code16(KC_5); *\/ */
  /*   break; */

  case HOLD2:
    unregister_code16(KC_UP);
    break;

  case TAP2: unregister_code16(RCTL(KC_COLON)); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_K); break;
  }
  dance_state[17].step = 0;
}




void on_dance_L(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_L, state, user_data);
}

void dance_L_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[18].step = dance_step(state);
  switch (dance_state[18].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_L); break;
  case HOLD:
    register_key(KC_L); break;
  case HOLD2:
    register_code16(KC_RIGHT);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_L);
    register_code16(KC_L);
    break;

  }
}

void dance_L_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[18].step) {


  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(KC_L); break;
  case HOLD2:
    unregister_code16(KC_RIGHT);
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


void on_dance_M(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_M, state, user_data);
}

void dance_M_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[22].step = dance_step(state);
  switch (dance_state[22].step) {

  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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

void dance_M_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[22].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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


void on_dance_N(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_N, state, user_data);
}

void dance_N_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[21].step = dance_step(state);
  switch (dance_state[21].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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

void dance_N_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[21].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

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



void on_dance_O(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_O, state, user_data);
}

void dance_O_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[8].step = dance_step(state);
  switch (dance_state[8].step) {

  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

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

void dance_O_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[8].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

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





void on_dance_P(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_P, state, user_data);
}

void dance_P_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[9].step = dance_step(state);
  switch (dance_state[9].step) {

  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_P); break;
  case HOLD:
    register_key(KC_P);
    break;

  case HOLD2:
    register_code16(KC_0);
    break;

  case TAP2_INTERRUPTED:
  case TAP2:
    register_code16(KC_P);
    register_code16(KC_P);
    break;
}
}

void dance_P_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  unregister_code16(KC_P);
  unregister_code16(KC_0);
  dance_state[9].step = 0;
}




void on_dance_Q(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_Q, state, user_data);
}

void dance_Q_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_Q); break;
  case HOLD:
    register_key(KC_Q);
    break;
  case HOLD2:
    tap_code16(KC_HOME);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_Q);
    register_code16(KC_Q);
    break;
  }
}

void dance_Q_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[1].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(KC_Q); break;
  case HOLD:
    unregister_key(KC_Q);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_Q);
    break;
  }
  dance_state[1].step = 0;
}

void on_dance_R(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_R, state, user_data);
}

void dance_R_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_R); break;
  case HOLD:
    register_key(KC_R); break;
  case HOLD2:
    tap_code16(KC_F5);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_R);
    register_code16(KC_R);
    break;
  }
}

void dance_R_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(KC_R); break;
  case HOLD:
    unregister_key(KC_R); break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_R);
    break;

  }
  dance_state[4].step = 0;
}

void on_dance_S(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_S, state, user_data);
}

void dance_S_finished(tap_dance_state_t *state, void *user_data) {
  alpha_char_default_finished(KC_S, 54, state);
}

void dance_S_reset(tap_dance_state_t *state, void *user_data) {
  alpha_char_default_reset(KC_S, 54);
}

void on_dance_T(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_T, state, user_data);
}

void dance_T_finished(tap_dance_state_t *state, void *user_data) {
  alpha_char_default_finished(KC_T, 5, state);
}

void dance_T_reset(tap_dance_state_t *state, void *user_data) {
  alpha_char_default_reset(KC_T, 5);
}

void on_dance_U(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_U, state, user_data);
}

void dance_U_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(KC_U); break;
  case HOLD:
    register_key(KC_U);
    break;
  case HOLD2:
      tap_code16(EMACS_BUFFER_REVERT);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_U);
    register_code16(KC_U);
    break;
  }
}

void dance_U_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(KC_U); break;
  case HOLD:
    unregister_key(KC_U);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_U);
    break;
  }
  dance_state[6].step = 0;
}




void on_dance_v(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_V, state, user_data);
}

void dance_v_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[47].step = dance_step(state);
  switch (dance_state[47].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP: register_code16(KC_V); break;
  case HOLD:
    register_key(KC_V);
    break;

  case HOLD2:
    register_code16(LSFT (KC_V));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_V);
    register_code16(KC_V);
    break;
  }
}

void on_dance_w(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_W);
    tap_code16(KC_W);
    tap_code16(KC_W);
  }
  if(state->count > 3) {
    tap_code16(KC_W);
  }
}

void dance_w_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[65].step = dance_step(state);
  switch (dance_state[65].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_W); break;
  case HOLD:
    register_key(KC_W); break;
  case HOLD2:
      tap_code16(LALT(KC_F4)); break;

  case TAP2: register_code16(KC_W); register_code16(KC_W); break;
  case TAP2_INTERRUPTED: tap_code16(KC_W); register_code16(KC_W);
  }
}

void dance_w_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[65].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_W); break;
  case HOLD:
    unregister_key(KC_W); break;
  case TAP2: unregister_code16(KC_W); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_W); break;
  }
  dance_state[65].step = 0;
}





void dance_v_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[47].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP: unregister_code16(KC_V); break;
  case HOLD:
  case HOLD2:
    unregister_code16(LSFT (KC_V));
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_V);
    break;
  }
  dance_state[47].step = 0;
}


void on_dance_X(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_X);
    tap_code16(KC_X);
    tap_code16(KC_X);
  }
  if(state->count > 3) {
    tap_code16(KC_X);
  }
}

void dance_X_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[79].step = dance_step(state);
  switch (dance_state[79].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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

void dance_X_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[79].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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


void on_dance_Y(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_Y, state, user_data);
}

void dance_Y_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[41].step = dance_step(state);
  switch (dance_state[41].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
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

void dance_Y_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[41].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
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


void on_dance_z(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_Z, state, user_data);
}

void dance_z_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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

void dance_z_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[76].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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



void on_dance_cap_K(tap_dance_state_t *state, void *user_data) {}

void dance_cap_K_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[104].step = dance_step(state);
  switch (dance_state[104].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(LSFT(KC_K)); break;

  case HOLD:
    register_key(LSFT(KC_K)); break;
  case HOLD2:
    register_code16(KC_UP);
    break;

  case TAP2:
      tap_code16(RCTL(KC_X));
      wait_ms(10);
      tap_code16(RCTL(KC_S));
      wait_ms(10);
      tap_code16(KC_ESC);
      wait_ms(10);
      layer_off(_SHIFTLOCK);
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_off_sound);
#endif
      break;
  case TAP2_INTERRUPTED: tap_code16(LSFT(KC_K)); register_code16(LSFT(KC_K));
  }
}

void dance_cap_K_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[104].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(LSFT(KC_K)); break;

  case HOLD:
    unregister_key(LSFT(KC_K)); break;
  /* case HOLD2: */
  /*   /\* unregister_code16(KC_5); *\/ */
  /*   break; */

  case HOLD2:
    unregister_code16(KC_UP);
    break;

  case TAP2: unregister_code16(RCTL(KC_COLON)); break;
  case TAP2_INTERRUPTED: unregister_code16(LSFT(KC_K)); break;
  }
  dance_state[104].step = 0;
}
