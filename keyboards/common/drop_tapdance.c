#include "keymap_us_international_linux.h"
#include "print.h"

enum tap_dance_codes {
                      DANCE_TAB,
                      DANCE_Q,
                      DANCE_SUPER,
                      DANCE_QUOTE,
                      DANCE_LEVEL3_APL,
                      DANCE_SHIFT_PAREN,
                      DANCE_SHIFT_BRACKET,
                      DANCE_SHIFT_CURLY,
                      DANCE_SHIFT_ANGLE,
                      DANCE_THREAD_FIRST,
                      DANCE_E,
                      DANCE_R,
                      DANCE_T,
                      DANCE_U,
                      DANCE_I,
                      DANCE_O,
                      DANCE_P,
                      DANCE_A,
                      DANCE_EDITING_Q,
                      DANCE_ALT_OR_RCTRL,
                      DANCE_ALT,
                      DANCE_THREAD_LAST,
                      DANCE_F,
                      DANCE_G,
                      DANCE_ROFI_WINDOWS,
                      DANCE_K,
                      DANCE_L,
                      DANCE_N,
                      DANCE_M,
                      DANCE_SPACE,
                      DANCE_ENTER,
                      DANCE_FORWARD_SLASH,
                      WWW_BACK_FORWARD,
                      DANCE_COLN,
                      DANCE_29,
                      DANCE_30,
                      DANCE_31,
                      DANCE_33,
                      DANCE_35,
                      DANCE_36,
                      DANCE_37,
                      DANCE_ADHOC_SET_HOTKEY,
                      DANCE_39,
                      DANCE_40,
                      DANCE_Y,
                      DANCE_42,
                      DANCE_HOTKEY_OR_COMPOSE,
                      DANCE_44,
                      DANCE_45,
                      DANCE_RAISE,
                      DANCE_47,
                      DANCE_48,
                      DANCE_49,
                      DANCE_50,
                      DANCE_SLASH,
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
                      DANCE_MINUS,
                      DANCE_CTRL,
                      DANCE_LOWER,
                      DANCE_MACROS,
                      DANCE_HYPER,
                      DANCE_ROFI,
                      DANCE_ALL_MODS,
                      DANCE_SCREENSHOT,
                      DANCE_Z,
                      DANCE_PASTE_OR_CLIPBOARD,

                      DANCE_C,
                      DANCE_D,
                      DANCE_X,
                      DANCE_RIGHT_OR_END,
                      DANCE_PAREN_BRACKET,
                      DANCE_SAVE_LOAD_NS_SWITCH,
                      DANCE_F5,
                      DANCE_COMMA,
                      DANCE_DOT,
                      DANCE_PAGE_UP_OR_HOME,
                      DANCE_LEFT_OR_HOME,
                      DANCE_PAGE_DOWN_OR_END,
                      DANCE_MICROPHONE,
};

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
      TAP = 1,
      TAP_INTERRUPTED,
      TAP_INTERRUPTED_HELD,
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

void register_key(uint16_t k) {
  register_code16(get_autoshift_state() ? LSFT (k) : k);
}

void unregister_key(uint16_t k) {
  unregister_code16(get_autoshift_state() ? LSFT (k) : k);
}

uint8_t _dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      if (state->pressed) {
        return TAP_INTERRUPTED_HELD;
      } else {
        return TAP_INTERRUPTED;
      }
      }
    else if (!state->pressed) {
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

uint8_t dance_step(tap_dance_state_t *state) {
  uint8_t step = _dance_step(state);
  /* printf("count: %u, pressed: %u, interrupted: %u: step: %u\n", state->count, state->pressed, state->interrupted, step); */
  return step;
}


void on_dance_fn_gen(int key, tap_dance_state_t *state, void *user_data, int count) {
  if(state->count == count)
    for (int i=1; i<=count; i++) {
      tap_code16(key);
    }
  if(state->count > count) {
    tap_code16(key);
  }
}

void on_dance_fn(int key, tap_dance_state_t *state, void *user_data) {
  on_dance_fn_gen(key, state, user_data, 3);
}

void on_dance_fn4(int key, tap_dance_state_t *state, void *user_data) {
  on_dance_fn_gen(key, state, user_data, 4);
}


void on_dance_fn5(int key, tap_dance_state_t *state, void *user_data) {
  on_dance_fn_gen(key, state, user_data, 5);
}



void on_dance_tab(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_TAB, state, user_data);
}

void dance_tab_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {

  case TAP_INTERRUPTED:
  case TAP:
    tap_code16(KC_TAB);
    break;

  case TAP_INTERRUPTED_HELD:
  case HOLD:
    layer_on(_EDITING);
    break;


  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(LCTL(KC_TAB));
    break;

  case HOLD2:
    layer_on(_CODE);
    break;

  case HOLD3:
    tap_code16(CLEAR_MODIFIERS);
    layer_move(_BASE);
#ifdef AUDIO_ENABLE
    PLAY_SONG(caps_lock_on_sound);
#endif

    break;
  }
}


void dance_tab_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
  case TAP: unregister_code16(KC_TAB); break;
  case HOLD2:
    layer_off(_CODE);
 break;

  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case HOLD:
    layer_off(_EDITING);
#ifdef RGBLIGHT_ENABLE
  rgblight_disable();
#endif
  break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;
  }
  dance_state[0].step = 0;
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


void on_dance_thread_first(tap_dance_state_t *state, void *user_data) {}

void dance_thread_first_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP:
    tap_code16(THREAD_FIRST); break;
  case HOLD:
    tap_code16(EMACS_WRAP_IN_THREAD_FIRST); break;
  }
}

void dance_thread_first_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[2].step = 0;
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
    tap_code16(KC_END);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_R);
    register_code16(KC_R);
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




void on_dance_T(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_T, state, user_data);
}

void dance_T_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP: tap_code16(KC_T); break;

  case HOLD:
    register_key(KC_T); break;
  case HOLD2:
    tap_code16(LGUI (KC_T));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_T);
    tap_code16(KC_T);
    break;
  }
}

void dance_T_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP: unregister_code16(KC_T); break;
  case HOLD:
    unregister_key(KC_T); break;
  case HOLD2:
    unregister_code16(LGUI (KC_T));
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    unregister_code16(KC_T);
    break;
  }
  dance_state[5].step = 0;
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
    register_code16(KC_7);
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
  /* default: */
  /*   tap_code16(KC_A); */
  /*   break; */
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





void on_dance_editing_q(tap_dance_state_t *state, void *user_data) {}

void dance_editing_q_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[81].step = dance_step(state);
  switch (dance_state[81].step) {

  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: tap_code16(EMACS_DESC_KEY); break;
  case HOLD: tap_code16(EMACS_FINDER_COMMENTARY); break;
  }
}

void dance_editing_q_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[81].step = 0;
}






void on_dance_thread_last(tap_dance_state_t *state, void *user_data) {}

void dance_thread_last_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[12].step = dance_step(state);
  switch (dance_state[12].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
  case TAP:
  tap_code16(THREAD_LAST); break;
  case HOLD:
    tap_code16(EMACS_WRAP_IN_THREAD_LAST); break;
  }
}

void dance_thread_last_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[12].step = 0;
}

void on_dance_pb(tap_dance_state_t *state, void *user_data) {
  on_dance_fn4(KC_LPRN, state, user_data);
}

void dance_pb_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[13].step = dance_step(state);
  switch (dance_state[13].step) {

  case TAP3: tap_code16(KC_LCBR);  break;
  case HOLD3: tap_code16(KC_RCBR); break;
    /* case TAP3_INTERRUPTED: register_code16(KC_LPRN); register_code16(KC_LPRN); register_code16(KC_LPRN); break; */


  case TAP2: tap_code16(KC_LBRACKET);  break;
  case HOLD2: tap_code16(KC_RBRACKET); break;
    /* case TAP2_INTERRUPTED: register_code16(KC_LPRN); register_code16(KC_LPRN); break; */

  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: tap_code16(KC_LPRN); break;
  case HOLD: tap_code16(KC_RPRN); break;

  default: break;


  }
}

void dance_pb_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[13].step) {
  /* case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 */
  /* case TAP: unregister_code16(KC_LPRN); break; */
  /* case HOLD: unregister_code16(KC_RPRN); break; */
  /* case TAP2: unregister_code16(KC_LBRACKET);  break; */
  /* case HOLD2: unregister_code16(KC_RBRACKET); break; */
  /* /\* case TAP2_INTERRUPTED: unregister_code16(KC_LPRN); break; *\/ */

  /* case TAP3: */
  /* /\* case TAP3_INTERRUPTED: *\/ */
  /*   unregister_code16(KC_LCBR);  break; */
  /* case HOLD3: unregister_code16(KC_RCBR); break; */

  }
  dance_state[13].step = 0;
}







void on_dance_rofi_windows(tap_dance_state_t *state, void *user_data) {}

// tap:  drun
// hold: rofi
// double-tab: alt_tab
void dance_rofi_windows_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[16].step = dance_step(state);
  switch (dance_state[16].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: layer_on(_ROFI); break;
  case HOLD: tap_code16(GUI(KC_SPACE)); break;
  case TAP2:
  case HOLD2:
    layer_on(_SHIFTLOCK);
    break;
  }
}

void dance_rofi_windows_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  // layer off is handled in process_record_user
  dance_state[16].step = 0;
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

  case TAP2: register_code16(RCTL(KC_COLON)); break;
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
    register_code16(KC_LEFT);
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
    unregister_code16(KC_LEFT);
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





void on_dance_space(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_SPACE, state, user_data);
}

void dance_space_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[23].step = dance_step(state);
  switch (dance_state[23].step) {
  case HOLD:
    set_oneshot_layer(_ROFI, ONESHOT_START);
    break;

  case TAP2:
  case TAP2_INTERRUPTED:
    register_code16(KC_SPACE); register_code16(KC_SPACE); break;
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case HOLD2:
  case TAP: register_code16(KC_SPACE); break;
  }
}

void dance_space_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    unregister_code16(KC_SPACE);
    layer_off(_ROFI);
  dance_state[23].step = 0;
}




void on_dance_enter(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_ENTER, state, user_data);
}

void dance_enter_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[24].step = dance_step(state);
  switch (dance_state[24].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(KC_ENTER);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    break;
  case TAP3:
  case TAP3_INTERRUPTED:
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    break;
  case TAP4:
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    tap_code16(KC_ENTER);
    break;
  case HOLD2:
    tap_code16(RCTL(KC_ENTER));
    break;
  default:
    layer_on(_LOWER);
    break;
  }
}

void dance_enter_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    layer_off(_LOWER);
  dance_state[24].step = 0;
}




void on_dance_forward_slash(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_SLASH, state, user_data);
}

void dance_forward_slash_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[25].step = dance_step(state);
  switch (dance_state[25].step) {
        case HOLD: tap_code16(KC_QUES); break;
    case TAP2: tap_code16(KC_BSLASH);  break;
    case HOLD2: tap_code16(KC_PIPE); break;
    default: tap_code16(KC_SLASH); break;
  }
}

void dance_forward_slash_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[25].step = 0;
}

void on_www_back_forward(tap_dance_state_t *state, void *user_data) {
}

void www_back_forward_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[27].step = dance_step(state);
  switch (dance_state[27].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(LALT(KC_LEFT)); break;
  case HOLD: register_code16(LALT(KC_RIGHT)); break;
  case TAP2: register_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); break;
  case HOLD2: register_code16(LALT(KC_RIGHT)); break;
  case TAP2_INTERRUPTED: tap_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT));
  }
}

void www_back_forward_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[27].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(LALT(KC_LEFT)); break;
  case TAP2: unregister_code16(LALT(KC_LEFT)); break;
  case HOLD: unregister_code16(LALT(KC_RIGHT)); break;
  case HOLD2: unregister_code16(LALT(KC_RIGHT)); break;
  case TAP2_INTERRUPTED: unregister_code16(LALT(KC_LEFT)); break;
  }
  dance_state[27].step = 0;
}




void on_dance_coln(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_COLN, state, user_data);
}

void dance_coln_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[28].step = dance_step(state);
  switch (dance_state[28].step) {
  case TAP2:
  case TAP2_INTERRUPTED:
  case HOLD2:
  case HOLD:
    tap_code16(KC_SCLN);
    break;
  default:
    tap_code16(KC_COLN);

    break;
  }
}

void dance_coln_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[28].step = 0;
}




void on_dance_29(tap_dance_state_t *state, void *user_data) {
}

void dance_29_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[29].step = dance_step(state);
  switch (dance_state[29].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: register_code16(RCTL(KC_PGUP)); break;
  case TAP2: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_29_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[29].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:

  case TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case TAP2: unregister_code16(RCTL(KC_PGUP)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[29].step = 0;
}




void on_dance_30(tap_dance_state_t *state, void *user_data) {
}

void dance_30_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[30].step = dance_step(state);
  switch (dance_state[30].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_30_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[30].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: unregister_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[30].step = 0;
}




void on_dance_31(tap_dance_state_t *state, void *user_data) {
}

void dance_31_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[31].step = dance_step(state);
  switch (dance_state[31].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_INSERT); break;
  case TAP2: layer_move(8); break;
  case TAP2_INTERRUPTED: tap_code16(KC_INSERT); register_code16(KC_INSERT);
  }
}

void dance_31_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[31].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_INSERT); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_INSERT); break;
  }
  dance_state[31].step = 0;
}





void on_dance_33(tap_dance_state_t *state, void *user_data) {
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[33].step = dance_step(state);
  switch (dance_state[33].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LALT(KC_ENTER)); break;
  case TAP2: register_code16(LALT(KC_ENTER)); register_code16(LALT(KC_ENTER)); break;
  case HOLD2: register_code16(LGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: tap_code16(LALT(KC_ENTER)); register_code16(LALT(KC_ENTER));
  }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[33].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LALT(KC_ENTER)); break;
  case TAP2: unregister_code16(LALT(KC_ENTER)); break;
  case HOLD2: unregister_code16(LGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: unregister_code16(LALT(KC_ENTER)); break;
  }
  dance_state[33].step = 0;
}





void on_dance_35(tap_dance_state_t *state, void *user_data) {
}

void dance_35_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[35].step = dance_step(state);
  switch (dance_state[35].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(RCTL(KC_PGUP)); break;
  case TAP2: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
  }
}

void dance_35_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[35].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(RCTL(KC_PGUP)); break;
  case TAP2: unregister_code16(RCTL(KC_PGUP)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGUP)); break;
  }
  dance_state[35].step = 0;
}




void on_dance_36(tap_dance_state_t *state, void *user_data) {
}

void dance_36_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[36].step = dance_step(state);
  switch (dance_state[36].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
  }
}

void dance_36_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[36].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
  case TAP2: unregister_code16(RCTL(KC_PGDOWN)); break;
  case HOLD2: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
  case TAP2_INTERRUPTED: unregister_code16(RCTL(KC_PGDOWN)); break;
  }
  dance_state[36].step = 0;
}




void on_dance_37(tap_dance_state_t *state, void *user_data) {
}

void dance_37_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[37].step = dance_step(state);
  switch (dance_state[37].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_TAB); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_GRAVE); break;
  case HOLD2: register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_37_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[37].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_TAB); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case HOLD2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;
  }
  dance_state[37].step = 0;
}





void on_adhoc_set_hotkey(tap_dance_state_t *state, void *user_data) {
}

void adhoc_set_hotkey_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[38].step = dance_step(state);
  switch (dance_state[38].step) {
  default:
    register_code16(LGUI(LCTL(KC_LALT)));
#ifdef RGBLIGHT_MODE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
#endif
    break;
  }
}

void adhoc_set_hotkey_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[38].step) {
  default:
    unregister_code16(LGUI(LCTL(KC_LALT)));
#ifdef RGBLIGHT_MODE
    rgblight_disable();
#endif
    break;
  }
  dance_state[38].step = 0;
}




void on_dance_39(tap_dance_state_t *state, void *user_data) {
}

void dance_39_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[39].step = dance_step(state);
  switch (dance_state[39].step) {
  }
}

void dance_39_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[39].step) {
  }
  dance_state[39].step = 0;
}




void on_dance_40(tap_dance_state_t *state, void *user_data) {
}

void dance_40_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[40].step = dance_step(state);
  switch (dance_state[40].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(KC_R)); break;
  case TAP2: register_code16(LGUI(KC_R)); register_code16(LGUI(KC_R)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_R)); register_code16(LGUI(KC_R));
  }
}

void dance_40_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[40].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(KC_R)); break;
  case TAP2: unregister_code16(LGUI(KC_R)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_R)); break;
  }
  dance_state[40].step = 0;
}




void on_dance_comma(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_COMMA, state, user_data);
}

void dance_comma_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[99].step = dance_step(state);
  switch (dance_state[99].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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

void dance_comma_reset(tap_dance_state_t *state, void *user_data) {
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





void on_dance_dot(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_DOT, state, user_data);
}

void dance_dot_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[100].step = dance_step(state);
  switch (dance_state[100].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
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

void dance_dot_reset(tap_dance_state_t *state, void *user_data) {
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





void on_dance_42(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_G, state, user_data);
}

void dance_42_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[42].step = dance_step(state);
  switch (dance_state[42].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(KC_G)); break;
  case TAP2: register_code16(LGUI(KC_G)); register_code16(LGUI(KC_G)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_G)); register_code16(LGUI(KC_G));
  }
}

void dance_42_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[42].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(KC_G)); break;
  case TAP2: unregister_code16(LGUI(KC_G)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_G)); break;
  }
  dance_state[42].step = 0;
}




void on_dance_hotkey_or_compose(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(SELECT_HOTKEY_3, state, user_data);
}

void dance_hotkey_or_compose_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[43].step = dance_step(state);
  switch (dance_state[43].step) {
  case HOLD:
    register_code16(COMPOSE);
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_PINK);
#endif
    break;

  default:
    tap_code16(SELECT_HOTKEY_3);
    break;
  }
}

void dance_hotkey_or_compose_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[43].step) {
  case HOLD:
    unregister_code16(COMPOSE);
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    break;
  default:
    break;
  }
  dance_state[43].step = 0;
}




void on_dance_44(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_K));
    tap_code16(LGUI(KC_K));
    tap_code16(LGUI(KC_K));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_K));
  }
}

void dance_44_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[44].step = dance_step(state);
  switch (dance_state[44].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(KC_K)); break;
  case TAP2: register_code16(LGUI(KC_K)); register_code16(LGUI(KC_K)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_K)); register_code16(LGUI(KC_K));
  }
}

void dance_44_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[44].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(KC_K)); break;
  case TAP2: unregister_code16(LGUI(KC_K)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_K)); break;
  }
  dance_state[44].step = 0;
}




void on_dance_45(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_L));
    tap_code16(LGUI(KC_L));
    tap_code16(LGUI(KC_L));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_L));
  }
}

void dance_45_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[45].step = dance_step(state);
  switch (dance_state[45].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(KC_L)); break;
  case TAP2: register_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); break;
  case HOLD2: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(KC_L)); register_code16(LGUI(KC_L));
  }
}

void dance_45_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[45].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(KC_L)); break;
  case TAP2: unregister_code16(LGUI(KC_L)); break;
  case HOLD2: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(KC_L)); break;
  }
  dance_state[45].step = 0;
}



void on_dance_raise(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_UNDS, state, user_data);
}

void dance_raise_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[46].step = dance_step(state);
  switch (dance_state[46].step) {
  case TAP:
  case TAP_INTERRUPTED:
    /* printf("j4-"); */
    tap_code16(KC_UNDS);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    break;
  case TAP3:
  case TAP3_INTERRUPTED:
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    break;
  case TAP4:
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    tap_code16(KC_UNDS);
    break;
  case HOLD2:
    layer_on(_EMACS);
    break;
  default:
    layer_on(_RAISE);
    break;
  }
}

void dance_raise_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[46].step) {
  case HOLD2:
    layer_off(_EMACS);
    break;
  default:
    layer_off(_RAISE);
    break;
  }
  dance_state[46].step = 0;
}




void on_dance_47(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
  }
}

void dance_47_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[47].step = dance_step(state);
  switch (dance_state[47].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(LSFT(KC_UP))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP))); break;
  case HOLD2: register_code16(LGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP)));
  }
}

void dance_47_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[47].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_UP))); break;
  case HOLD2: unregister_code16(LGUI(RSFT(KC_K))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_UP))); break;
  }
  dance_state[47].step = 0;
}




void on_dance_48(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_LEFT)));
    tap_code16(LGUI(LSFT(KC_LEFT)));
    tap_code16(LGUI(LSFT(KC_LEFT)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_LEFT)));
  }
}

void dance_48_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[48].step = dance_step(state);
  switch (dance_state[48].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(LSFT(KC_LEFT))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT))); break;
  case HOLD2: register_code16(LGUI(LSFT(KC_H))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT)));
  }
}

void dance_48_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[48].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  case HOLD2: unregister_code16(LGUI(LSFT(KC_H))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
  }
  dance_state[48].step = 0;
}




void on_dance_49(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_DOWN)));
    tap_code16(LGUI(LSFT(KC_DOWN)));
    tap_code16(LGUI(LSFT(KC_DOWN)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_DOWN)));
  }
}

void dance_49_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[49].step = dance_step(state);
  switch (dance_state[49].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(LSFT(KC_DOWN))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN))); break;
  case HOLD2: register_code16(LGUI(RSFT(KC_J))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN)));
  }
}

void dance_49_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[49].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  case HOLD2: unregister_code16(LGUI(RSFT(KC_J))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
  }
  dance_state[49].step = 0;
}




void on_dance_50(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_RIGHT)));
    tap_code16(LGUI(LSFT(KC_RIGHT)));
    tap_code16(LGUI(LSFT(KC_RIGHT)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_RIGHT)));
  }
}

void dance_50_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[50].step = dance_step(state);
  switch (dance_state[50].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case TAP2: register_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT))); break;
  case HOLD2: register_code16(LGUI(LSFT(KC_L))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT)));
  }
}

void dance_50_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[50].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case TAP2: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  case HOLD2: unregister_code16(LGUI(LSFT(KC_L))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
  }
  dance_state[50].step = 0;
}



void dance_slash_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[51].step = dance_step(state);
  switch (dance_state[51].step) {
  case HOLD2: register_code16(RCTL(LGUI(KC_Q))); break;
  }
}

void dance_slash_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[51].step) {
  case HOLD2: unregister_code16(RCTL(LGUI(KC_Q))); break;
  }
  dance_state[51].step = 0;
}




void on_dance_52(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_TAB, state, user_data);
}

void dance_52_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[52].step = dance_step(state);
  switch (dance_state[52].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_TAB); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_GRAVE); break;
  case HOLD2: register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TAB); register_code16(KC_TAB);
  }
}

void dance_52_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[52].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_TAB); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case HOLD2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TAB); break;
  }
  dance_state[52].step = 0;
}




void on_dance_53(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_TILD);
    tap_code16(KC_TILD);
    tap_code16(KC_TILD);
  }
  if(state->count > 3) {
    tap_code16(KC_TILD);
  }
}

void dance_53_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[53].step = dance_step(state);
  switch (dance_state[53].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_TILD); break;
  case HOLD: layer_move(0); break;
  case TAP2: register_code16(KC_TILD); register_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: tap_code16(KC_TILD); register_code16(KC_TILD);
  }
}

void dance_53_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[53].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_TILD); break;
  case TAP2: unregister_code16(KC_TILD); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_TILD); break;
  }
  dance_state[53].step = 0;
}




void on_dance_54(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_UNDS, state, user_data);
}

void dance_54_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[54].step = dance_step(state);
  switch (dance_state[54].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_UNDS); break;
  case HOLD: register_code16(KC_PLUS); break;
  case TAP2: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
  case TAP2_INTERRUPTED: tap_code16(KC_UNDS); register_code16(KC_UNDS);
  }
}

void dance_54_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[54].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_UNDS); break;
  case HOLD: unregister_code16(KC_PLUS); break;
  case TAP2: unregister_code16(KC_UNDS); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_UNDS); break;
  }
  dance_state[54].step = 0;
}




void on_dance_55(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_COLN);
    tap_code16(KC_COLN);
    tap_code16(KC_COLN);
  }
  if(state->count > 3) {
    tap_code16(KC_COLN);
  }
}

void dance_55_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[55].step = dance_step(state);
  switch (dance_state[55].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_COLN); break;
  case HOLD: register_code16(KC_LCBR); break;
  case TAP2: register_code16(KC_COLN); register_code16(KC_COLN); break;
  case TAP2_INTERRUPTED: tap_code16(KC_COLN); register_code16(KC_COLN);
  }
}

void dance_55_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[55].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_COLN); break;
  case HOLD: unregister_code16(KC_LCBR); break;
  case TAP2: unregister_code16(KC_COLN); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_COLN); break;
  }
  dance_state[55].step = 0;
}




void on_dance_56(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DQUO);
    tap_code16(KC_DQUO);
    tap_code16(KC_DQUO);
  }
  if(state->count > 3) {
    tap_code16(KC_DQUO);
  }
}

void dance_56_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[56].step = dance_step(state);
  switch (dance_state[56].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_DQUO); break;
  case HOLD: register_code16(KC_RCBR); break;
  case TAP2: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
  case TAP2_INTERRUPTED: tap_code16(KC_DQUO); register_code16(KC_DQUO);
  }
}

void dance_56_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[56].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_DQUO); break;
  case HOLD: unregister_code16(KC_RCBR); break;
  case TAP2: unregister_code16(KC_DQUO); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_DQUO); break;
  }
  dance_state[56].step = 0;
}



void dance_57_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[57].step = dance_step(state);
  switch (dance_state[57].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: layer_move(6); break;
  case HOLD: layer_move(0); break;
  case TAP2: layer_move(6); break;
  case TAP2_INTERRUPTED: layer_move(6); break;
  }
}

void dance_57_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[57].step) {
  }
  dance_state[57].step = 0;
}




void on_dance_58(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(RSFT(KC_H)));
    tap_code16(LGUI(RSFT(KC_H)));
    tap_code16(LGUI(RSFT(KC_H)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(RSFT(KC_H)));
  }
}

void dance_58_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[58].step = dance_step(state);
  switch (dance_state[58].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(RSFT(KC_H))); break;
  case TAP2: register_code16(LGUI(RSFT(KC_H))); register_code16(LGUI(RSFT(KC_H))); break;
  case HOLD2: register_code16(LGUI(RSFT(KC_LEFT))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(RSFT(KC_H))); register_code16(LGUI(RSFT(KC_H)));
  }
}

void dance_58_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[58].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(RSFT(KC_H))); break;
  case TAP2: unregister_code16(LGUI(RSFT(KC_H))); break;
  case HOLD2: unregister_code16(LGUI(RSFT(KC_LEFT))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(RSFT(KC_H))); break;
  }
  dance_state[58].step = 0;
}




void on_dance_59(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(RSFT(KC_K)));
    tap_code16(LGUI(RSFT(KC_K)));
    tap_code16(LGUI(RSFT(KC_K)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(RSFT(KC_K)));
  }
}

void dance_59_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[59].step = dance_step(state);
  switch (dance_state[59].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(RSFT(KC_K))); break;
  case TAP2: register_code16(LGUI(RSFT(KC_K))); register_code16(LGUI(RSFT(KC_K))); break;
  case HOLD2: register_code16(KC_F11); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(RSFT(KC_K))); register_code16(LGUI(RSFT(KC_K)));
  }
}

void dance_59_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[59].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(RSFT(KC_K))); break;
  case TAP2: unregister_code16(LGUI(RSFT(KC_K))); break;
  case HOLD2: unregister_code16(KC_F11); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(RSFT(KC_K))); break;
  }
  dance_state[59].step = 0;
}




void on_dance_60(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(RSFT(KC_L)));
    tap_code16(LGUI(RSFT(KC_L)));
    tap_code16(LGUI(RSFT(KC_L)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(RSFT(KC_L)));
  }
}

void dance_60_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[60].step = dance_step(state);
  switch (dance_state[60].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(LGUI(RSFT(KC_L))); break;
  case TAP2: register_code16(LGUI(RSFT(KC_L))); register_code16(LGUI(RSFT(KC_L))); break;
  case HOLD2: register_code16(LGUI(RSFT(KC_RIGHT))); break;
  case TAP2_INTERRUPTED: tap_code16(LGUI(RSFT(KC_L))); register_code16(LGUI(RSFT(KC_L)));
  }
}

void dance_60_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[60].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(LGUI(RSFT(KC_L))); break;
  case TAP2: unregister_code16(LGUI(RSFT(KC_L))); break;
  case HOLD2: unregister_code16(LGUI(RSFT(KC_RIGHT))); break;
  case TAP2_INTERRUPTED: unregister_code16(LGUI(RSFT(KC_L))); break;
  }
  dance_state[60].step = 0;
}




void on_dance_61(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_GRAVE);
    tap_code16(KC_GRAVE);
    tap_code16(KC_GRAVE);
  }
  if(state->count > 3) {
    tap_code16(KC_GRAVE);
  }
}

void dance_61_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[61].step = dance_step(state);
  switch (dance_state[61].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_GRAVE); break;
  case HOLD: register_code16(KC_TILD); break;
  case TAP2: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
  case TAP2_INTERRUPTED: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
  }
}

void dance_61_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[61].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_GRAVE); break;
  case HOLD: unregister_code16(KC_TILD); break;
  case TAP2: unregister_code16(KC_GRAVE); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_GRAVE); break;
  }
  dance_state[61].step = 0;
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
    tap_code16(RCTL(KC_LBRACKET));
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




void on_dance_64(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_K);
    tap_code16(KC_K);
    tap_code16(KC_K);
  }
  if(state->count > 3) {
    tap_code16(KC_K);
  }
}

void dance_64_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[64].step = dance_step(state);
  switch (dance_state[64].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_K); break;
  case HOLD:
    register_key(KC_K); break;
  case TAP2: register_code16(KC_K); register_code16(KC_K); break;
  case TAP2_INTERRUPTED: tap_code16(KC_K); register_code16(KC_K);
  }
}

void dance_64_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[64].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_K); break;
  case HOLD:
    unregister_key(KC_K); break;
  case TAP2: unregister_code16(KC_K); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_K); break;
  }
  dance_state[64].step = 0;
}




void on_dance_65(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_L);
    tap_code16(KC_L);
    tap_code16(KC_L);
  }
  if(state->count > 3) {
    tap_code16(KC_L);
  }
}

void dance_65_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[65].step = dance_step(state);
  switch (dance_state[65].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: register_code16(KC_L); break;
  case HOLD:
    register_key(KC_L); break;
  case TAP2: register_code16(KC_L); register_code16(KC_L); break;
  case TAP2_INTERRUPTED: tap_code16(KC_L); register_code16(KC_L);
  }
}

void dance_65_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[65].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(KC_L); break;
  case HOLD:
    unregister_key(KC_L); break;
  case TAP2: unregister_code16(KC_L); break;
  case TAP2_INTERRUPTED: unregister_code16(KC_L); break;
  }
  dance_state[65].step = 0;
}




void on_dance_minus(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_MINUS, state, user_data);
}

void dance_minus_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[66].step = dance_step(state);
  switch (dance_state[66].step) {
  case HOLD: register_code16(KC_UNDS); break;
  case TAP2_INTERRUPTED:
  case TAP2: tap_code16(KC_MINUS); tap_code16(KC_MINUS);  break;
  case HOLD2: register_code16(KC_PIPE); break;
  default: register_code16(KC_MINUS); break;
  }
}

void dance_minus_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[66].step) {
  default:
    unregister_code16(KC_UNDS);
    unregister_code16(KC_PIPE);
    unregister_code16(KC_MINUS);
  }
  dance_state[66].step = 0;
}




void on_dance_ctrl(tap_dance_state_t *state, void *user_data) {}

void dance_ctrl_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[67].step = dance_step(state);
  switch (dance_state[67].step) {
  case TAP:
  case TAP2:
  case TAP3:
  case TAP4:
  case TAP5:
  tap_code16(KC_ESCAPE);
  break;

  case HOLD2:
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE);
    rgblight_sethsv_noeeprom(HSV_WHITE);
#endif
    register_code16(KC_LCTL);
    break;

  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
    set_oneshot_mods(MOD_BIT(KC_RCTL));
    break;

  default:
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE);
    rgblight_sethsv_noeeprom(HSV_MAGENTA);
#endif
    register_code16(KC_RCTL);
    break;


  }
}

void dance_ctrl_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[67].step) {
  case TAP:
  case TAP2:
  case TAP3:
  case TAP4:
  case TAP5:
    /* tap_code16(KC_ESCAPE); */
  break;

  case HOLD2:
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    unregister_code16(KC_LCTL);
    break;

  case TAP_INTERRUPTED_HELD:
  case TAP_INTERRUPTED:
    break;

  default:
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    unregister_code16(KC_RCTL);
    break;
  }
  dance_state[67].step = 0;
}




#define LOWER_TAP KC_MINUS
void on_dance_lower(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_MINUS, state, user_data);
}

void dance_lower_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[68].step = dance_step(state);
  switch (dance_state[68].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(LOWER_TAP);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    break;
  case TAP3:
  case TAP3_INTERRUPTED:
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    break;
  case TAP4:
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    tap_code16(LOWER_TAP);
    break;
  case HOLD2:
    layer_on(_EDITING);
    break;
  default:
    layer_on(_LOWER);
    break;
  }
}

void dance_lower_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[68].step) {
    case HOLD2:
      layer_off(_EDITING);
      break;
    default:
      layer_off(_LOWER);
      break;
  }
  dance_state[68].step = 0;
}






void on_all_mods(tap_dance_state_t *state, void *user_data) {}

void all_mods_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[70].step = dance_step(state);
  switch (dance_state[70].step) {
  default:
    register_code16(LGUI (LCTL (LALT (RCTL (KC_LSFT)))));
#ifdef RGBLIGHT_MODE
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    rgblight_sethsv_noeeprom(HSV_PINK);
#endif
    break;
  }
}

void all_mods_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[70].step) {
  default:
    unregister_code16(LGUI (LCTL (LALT (RCTL (KC_LSFT)))));
#ifdef RGBLIGHT_MODE
    rgblight_disable();
#endif
  }
  dance_state[70].step = 0;
}





void on_dance_rofi(tap_dance_state_t *state, void *user_data) {}

void dance_rofi_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[69].step = dance_step(state);
  switch (dance_state[69].step) {
  case HOLD2:
    set_oneshot_layer(_ADHOC_SET_HOTKEY, ONESHOT_START);
    break;

  default:
    set_oneshot_layer(_ROFI, ONESHOT_START);
    break;
  }
}

void dance_rofi_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  clear_oneshot_layer_state(ONESHOT_PRESSED);
  dance_state[69].step = 0;
}

void on_dance_macros(tap_dance_state_t *state, void *user_data) {}

void dance_macros_finished(tap_dance_state_t *state, void *user_data) {
  set_oneshot_layer(_MACROS, ONESHOT_START);
}

void dance_macros_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  clear_oneshot_layer_state(ONESHOT_PRESSED);
  dance_state[29].step = 0;
}





void on_hyper(tap_dance_state_t *state, void *user_data) {}

void hyper_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[71].step = dance_step(state);
  switch (dance_state[71].step) {
  case HOLD3:
    layer_on(_SYSTEM);
    break;

  case TAP:
  case TAP_INTERRUPTED:
    set_oneshot_mods(MOD_BIT(KC_LCTL));
    break;

    default:
/* #ifdef RGBLIGHT_ENABLE */
      /* rgblight_enable_noeeprom(); */
      /* rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); */
      rgblight_sethsv_noeeprom(HSV_WHITE);
/* #endif */
      register_code16(KC_LCTL);
      layer_on(_HYPER);
      break;
    }
}

void hyper_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[71].step) {
  /* case TAP: */
  /*   clear_oneshot_mods(); */
  /*   break; */

  case HOLD3:
    layer_off(_SYSTEM);
    break;


  default:
    unregister_code16(KC_LCTL);
    layer_off(_HYPER);

#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    break;
  }
  dance_state[71].step = 0;
}






void on_dance_screenshot(tap_dance_state_t *state, void *user_data) {}

void dance_screenshot_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[73].step = dance_step(state);
  switch (dance_state[73].step) {
  case HOLD2:
    tap_code16(LGUI(RCTL(KC_PSCREEN)));
    break;

  default:
    tap_code16(LSFT(KC_PSCREEN));
    break;
  }
}

void dance_screenshot_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[73].step = 0;
}

void on_dance_z(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_Z);
    tap_code16(KC_Z);
    tap_code16(KC_Z);
  }
  if(state->count > 3) {
    tap_code16(KC_Z);
  }
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








void on_paste_or_clipboard(tap_dance_state_t *state, void *user_data) {}

void paste_or_clipboard_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[76].step = dance_step(state);
  switch (dance_state[76].step) {
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
  case TAP:
    tap_code16(TERM_PASTE);
    break;
  case HOLD:
    tap_code16(LALT(KC_9));
    break;
  case TAP2:
    tap_code16(LCTL(KC_Y));
    break;
  }
}

void paste_or_clipboard_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[76].step = 0;
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
    tap_code16(LGUI(KC_E));
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
  case HOLD2:
    unregister_code16(LGUI (KC_E));
    break;
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
  if(state->count == 3) {
    tap_code16(KC_G);
    tap_code16(KC_G);
    tap_code16(KC_G);
  }
  if(state->count > 3) {
    tap_code16(KC_G);
  }
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
    tap_code16(RCTL(LALT(LGUI(KC_G))));
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






void on_dance_save_load_ns_switch(tap_dance_state_t *state, void *user_data) {
}

void dance_save_load_ns_switch_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[83].step = dance_step(state);
  switch (dance_state[83].step) {
  case HOLD:
    // save all
    tap_code16(RCTL(KC_X));
    tap_code16(KC_S);
 break;
  case HOLD2:
    // save and switch to repl
    tap_code16(RCTL(KC_X));
    tap_code16(KC_S);
    tap_code16(KC_1);
    tap_code16(KC_COMMA);
    tap_code16(KC_S);
    tap_code16(KC_S);
    break;
  case TAP2:
    tap_code16(RCTL(KC_QUOT));
    break;
  default:
    // save
    tap_code16(RCTL(KC_COLON));
    // load buffer
    tap_code16(RCTL(KC_C));
    tap_code16(RCTL(KC_K));
    break;
  }
}

void dance_save_load_ns_switch_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  dance_state[83].step = 0;
}


void on_dance_right_or_end(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_RIGHT, state, user_data);
}

void dance_right_or_end_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[80].step = dance_step(state);
  switch (dance_state[80].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_RIGHT); break;
  case HOLD: register_code16(KC_RIGHT); break;
  case TAP2_INTERRUPTED: case TAP2: tap_code16(KC_RIGHT); tap_code16(KC_RIGHT);  break;
  case HOLD2: tap_code16(KC_END); break;
  }
}

void dance_right_or_end_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    unregister_code16(KC_RIGHT);
    unregister_code16(KC_END);
  dance_state[80].step = 0;
}




void on_alt_or_rctrl(tap_dance_state_t *state, void *user_data) {}

void alt_or_rctrl_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[82].step = dance_step(state);
  switch (dance_state[82].step) {
    case TAP2:
      set_oneshot_mods(MOD_BIT(KC_LCTL));
      break;

    case HOLD3:
      cycle_active_key_alt_rctrl_fn();
      break;

  case HOLD2:
#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_noeeprom(HSV_ORANGE);
#endif
    register_code16(COMPOSE);
    break;

  case TAP_INTERRUPTED_HELD:
  case HOLD:

#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
#endif

      switch (active_alt_rctrl_key_fn) {
      case MO_ALT:
#ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_noeeprom(HSV_GREEN);
#endif
        register_code16(KC_LALT);
        break;
      case MO_RCTRL:
#ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_noeeprom(HSV_ORANGE);
#endif
        register_code16(KC_RCTL);
        break;

      }
      break;

  case TAP_INTERRUPTED:
  default:
    /* set_oneshot_mods(MOD_BIT(KC_RCTL)); */
    tap_code16(KC_ENTER);
/* #ifdef RGBLIGHT_ENABLE */
/*     rgblight_enable_noeeprom(); */
/*     rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); */
/*     rgblight_sethsv_noeeprom(HSV_ORANGE); */
/* #endif */

    break;

  }
}

void alt_or_rctrl_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
#ifdef RGBLIGHT_ENABLE
  rgblight_disable();
#endif

  switch (dance_state[82].step) {
       case HOLD2:
    unregister_code16(COMPOSE);
    break;
  default:
    unregister_code16(KC_LALT);
    unregister_code16(KC_RCTL);
    unregister_code16(COMPOSE);
  }
}



void on_alt(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_DEL, state, user_data);
}

void alt_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[82].step = dance_step(state);
  switch (dance_state[82].step) {
  case TAP:
    tap_code16(KC_DEL);
    break;
  case TAP2:
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    break;
  case TAP3:
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    break;
  case TAP4:
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    tap_code16(KC_DEL);
    break;
  case HOLD2:
    register_code16(KC_DEL);
    break;

  default:
#ifdef MOONLANDER
    /* RGB_MATRIX_EFFECT(BREATHING); */
    /* rgblight_mode(0); */
    /* rgb_matrix_set_color_all(HSV_GREEN); */
    /* printf("here"); */
    /* set_layer_color(2); */

#endif

/* #ifdef MOONLANDER */
/*     rgb_matrix_sethsv_noeeprom(HSV_GREEN); */
/*   #endif */


#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    rgblight_sethsv_noeeprom(HSV_GREEN);
#endif
    register_code16(KC_LALT);
    break;
  }
}

void alt_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[82].step) {
  case HOLD2:
    unregister_code16(KC_DEL);
    break;
  default:
#ifdef AUDIO_ENABLE
    /* PLAY_SONG(caps_lock_on_sound); */
#endif
    unregister_code16(KC_LALT);
/* #ifdef MOONLANDER */
/*     rgb_matrix_sethsv_noeeprom(HSV_BLACK); */
/* #endif */

#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
  }
}






void on_DANCE_LEVEL3_APL(tap_dance_state_t *state, void *user_data) {
  // on_dance_fn(KC_UP, state, user_data);
}

void DANCE_LEVEL3_APL_finished(tap_dance_state_t *state, void *user_data) {
  printf("active_apl_level3_fn: %u\n", active_apl_level3_fn);
  printf("tap: %u, tap_int: %u, hold: %u, hold2: %u, mine: %u", TAP, TAP_INTERRUPTED, HOLD, HOLD2, dance_state[84].step);
  dance_state[84].step = dance_step(state);
  switch (dance_state[84].step) {
  case TAP:
    set_oneshot_layer(_ROFI, ONESHOT_START);
    break;

  case TAP3:
    set_oneshot_layer(_ADHOC_SET_HOTKEY, ONESHOT_START);
    break;

  case HOLD2:
    cycle_active_apl_level3_fn();
    break;


  default:
    switch (active_apl_level3_fn) {
    case K74_MO_LEVEL3:
#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      rgblight_sethsv_noeeprom(HSV_PINK);
#endif
      register_code16(COMPOSE);
      break;

    case K74_MO_APL:
#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_KNIGHT);
      rgblight_sethsv_noeeprom(HSV_GREEN);
#endif
      register_code16(KEYBOARD_LAYOUT_HOLD_KEY);
      break;
    }
    break;
  }
}

void DANCE_LEVEL3_APL_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[84].step) {
  /* case TAP: */
  /* case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 */
  /*   clear_oneshot_layer_state(ONESHOT_PRESSED); */
  /*   break; */

  case TAP3:
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    break;


  case HOLD2:
    break;
  default:
    unregister_code16(KC_KP_ENTER);
    layer_off(_ROFI);
    unregister_code16(KEYBOARD_LAYOUT_HOLD_KEY);
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    break;
  }
  dance_state[84].step = 0;
}




void on_dance_shift_paren(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_shift_paren_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(KC_LPRN);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_RPRN);
    break;
  case HOLD2:
    layer_move(_SHIFTLOCK);
#ifdef AUDIO_ENABLE
    PLAY_SONG(caps_lock_on_sound);
#endif
    break;

  default:
    register_code16(KC_LSFT);

    break;
  }
}

void dance_shift_paren_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[85].step) {
  case HOLD2:
    break;
  default:
    unregister_code16(KC_LSFT);
    break;

  }
  dance_state[85].step = 0;
}


void on_dance_shift_bracket(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_shift_bracket_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[101].step = dance_step(state);
  switch (dance_state[101].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(KC_LBRACKET);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_RBRACKET);
    break;
  default:
    register_code16(KC_LSFT);

    break;
  }
}

void dance_shift_bracket_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[101].step) {
  default:
    unregister_code16(KC_LSFT);
    break;

  }
  dance_state[101].step = 0;
}


void on_dance_shift_curly(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_shift_curly_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[102].step = dance_step(state);
  switch (dance_state[102].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(KC_LCBR);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_RCBR);
    break;
  default:
    register_code16(KC_LSFT);

    break;
  }
}

void dance_shift_curly_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[102].step) {
  default:
    unregister_code16(KC_LSFT);
    break;

  }
  dance_state[101].step = 0;
}


void on_dance_super(tap_dance_state_t *state, void *user_data) {}

void dance_super_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case HOLD:
  case HOLD3:
  /* case TAP_INTERRUPTED: */
    // hold down SUPER cuz i dont wanna explicitly apply SUPER to every key
    register_code16(KC_LGUI);
    layer_on(_SUPER);
    break;
  case HOLD2:
    layer_move(_ROFI);
    break;

  default:
    set_oneshot_layer(_WINDOWS, ONESHOT_START);
    break;       
  }
}

void dance_super_reset(tap_dance_state_t *state, void *user_data) {
  // layer_off(_ROFI) and layer_off(_ROFI) are handled by post_process_record_user
  switch (dance_state[85].step) {
  case HOLD:
  case HOLD3:
  /* case TAP_INTERRUPTED: */
    unregister_code16(KC_LGUI);
    layer_off(_SUPER);
    break;

  case HOLD2:
    layer_off(_ROFI);
    break;

  default:
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    break;
  }
  dance_state[85].step = 0;
}


void on_dance_f5(tap_dance_state_t *state, void *user_data) {}

void dance_f5_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[86].step = dance_step(state);
  switch (dance_state[86].step) {
    case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_F5); break;
  case HOLD:
    tap_code16(RCTL(KC_F5)); break;
  case TAP2: tap_code16(KC_F5); tap_code16(KC_F5); break;
  default:
    register_code16(KC_F5);
    break;
  }
}


void dance_f5_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[86].step) {
  /*   case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: unregister_code16(RCTL(KC_COLON)); break; */
  /* case HOLD: */
  /*   tap_code16(RCTL(KC_COLON)); */
  /*   tap_code16(RCTL(KC_C)); */
  /*   tap_code16(RCTL(KC_K)); */
    /* break; */
  default:
    unregister_code16(KC_F5);
    break;

  }
  dance_state[86].step = 0;
}






void on_dance_up_or_home(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_PGUP, state, user_data);
}

void dance_up_or_home_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[87].step = dance_step(state);
  switch (dance_state[87].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_UP); break;
  case HOLD: register_code16(KC_UP); break;
  case TAP2_INTERRUPTED: case TAP2: tap_code16(KC_UP); tap_code16(KC_UP);  break;
  case TAP3_INTERRUPTED: case TAP3: tap_code16(KC_UP); tap_code16(KC_UP); tap_code16(KC_UP);  break;
  case HOLD2: register_code16(PAREDIT_BACKWARD_UP); break;
  default:
    tap_code16(KC_UP);
  break;
  }
}

void dance_up_or_home_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  unregister_code16(KC_UP);
  unregister_code16(PAREDIT_BACKWARD_UP);
  dance_state[87].step = 0;
}





void on_dance_down_or_end(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_PGDOWN, state, user_data);
}

void dance_down_or_end_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[88].step = dance_step(state);
  switch (dance_state[88].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_PGDOWN); break;
  case HOLD: register_code16(KC_PGDOWN); break;
  case TAP2: tap_code16(KC_PGDOWN); tap_code16(KC_PGDOWN); break;
  case TAP2_INTERRUPTED:  tap_code16(KC_PGDOWN); tap_code16(KC_PGDOWN);  break;
  case HOLD2: tap_code16(RCTL(KC_END)); break;
  }
}

void dance_down_or_end_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  unregister_code16(KC_PGDOWN);
  unregister_code16(RCTL(KC_END));

    dance_state[88].step = 0;
}






void on_dance_microphone(tap_dance_state_t *state, void *user_data) {}

void dance_microphone_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[89].step = dance_step(state);
  switch (dance_state[89].step) {
  case HOLD5:
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode(24);
    rgblight_sethsv_noeeprom(HSV_YELLOW);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif
    tap_code16(QK_BOOTLOADER);
    break;

  case HOLD:
#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
    rgblight_sethsv_noeeprom(HSV_PINK);
#endif
    tap_code16(on_microphone);

    break;

  default:
    tap_code16(toggle_microphone);
    break;
  }
}

void dance_microphone_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  int step = dance_state[89].step;
  /* printf("reset count: %u, pressed: %u, interrupted: %u: step: %u\n", state->count, state->pressed, state->interrupted, step); */
  switch (step) {
  case HOLD:
    /* unregister_code16(on_microphone); */
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
    tap_code16(off_microphone);
    break;
  }
  dance_state[89].step = 0;

}


void on_dance_left_or_home(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LEFT, state, user_data);
}

void dance_left_or_home_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[90].step = dance_step(state);
  switch (dance_state[90].step) {
  case TAP_INTERRUPTED:
case TAP_INTERRUPTED_HELD:
 case TAP: tap_code16(KC_LEFT); break;
  case HOLD: register_code16(KC_LEFT); break;
  case TAP2_INTERRUPTED: case TAP2: tap_code16(KC_LEFT); tap_code16(KC_LEFT);  break;
  case HOLD2: tap_code16(KC_HOME); break;
  }
}

void dance_left_or_home_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    dance_state[90].step = 0;
    switch (dance_state[90].step) {
    default:
      unregister_code16(KC_LEFT);
      unregister_code16(KC_HOME);
      break;
    }
}


void on_dance_quote(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_QUOTE, state, user_data);
}

void dance_quote_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[90].step = dance_step(state);
  switch (dance_state[90].step) {
  case HOLD: register_code16(KC_DQUO); break;
   case TAP2: tap_code16(KC_GRAVE);  break;
  case HOLD2: tap_code16(KC_TILDE); break;
  default: tap_code16(KC_QUOTE); break;
  }
}

void dance_quote_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  unregister_code16(KC_DQUO);
  dance_state[90].step = 0;
}


void on_dance_shift_angle(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_shift_angle_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[102].step = dance_step(state);
  switch (dance_state[102].step) {
  case TAP:
  case TAP_INTERRUPTED:
    tap_code16(KC_LEFT_ANGLE_BRACKET);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    tap_code16(KC_RIGHT_ANGLE_BRACKET);
    break;
  default:
    register_code16(KC_LSFT);

    break;
  }
}

void dance_shift_angle_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[102].step) {
  default:
    unregister_code16(KC_LSFT);
    break;

  }
  dance_state[101].step = 0;
}



/* #include "apl_tapdance.c" */

tap_dance_action_t tap_dance_actions[] = {
                                             [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_tab, dance_tab_finished, dance_tab_reset),
                                             [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
                                             [DANCE_THREAD_FIRST] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_thread_first, dance_thread_first_finished, dance_thread_first_reset),
                                             [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset),
                                             [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
                                             [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset),
                                             [DANCE_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U, dance_U_finished, dance_U_reset),
                                             [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset),
                                             [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset),
                                             [DANCE_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_P, dance_P_finished, dance_P_reset),
                                             [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
                                             [DANCE_EDITING_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_editing_q, dance_editing_q_finished, dance_editing_q_reset),
                                             [DANCE_ALT_OR_RCTRL] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt_or_rctrl, alt_or_rctrl_finished, alt_or_rctrl_reset),
                                             [DANCE_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt, alt_finished, alt_reset),
                                             [DANCE_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quote, dance_quote_finished, dance_quote_reset),
                                             [DANCE_THREAD_LAST] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_thread_last, dance_thread_last_finished, dance_thread_last_reset),
                                             [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
                                             [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
                                             [DANCE_ROFI_WINDOWS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rofi_windows, dance_rofi_windows_finished, dance_rofi_windows_reset),
                                             [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset),
                                             [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset),
                                             [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
                                             [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset),
                                             [DANCE_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_space, dance_space_finished, dance_space_reset),
                                             [DANCE_ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_enter, dance_enter_finished, dance_enter_reset),
                                             [DANCE_FORWARD_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_forward_slash, dance_forward_slash_finished, dance_forward_slash_reset),
                                             [WWW_BACK_FORWARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_www_back_forward, www_back_forward_finished, www_back_forward_reset),
                                             [DANCE_COLN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_coln, dance_coln_finished, dance_coln_reset),
                                             [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
                                             [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
                                             [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
                                             [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
                                             [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
                                             [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
                                             [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
                                             [DANCE_ADHOC_SET_HOTKEY] = ACTION_TAP_DANCE_FN_ADVANCED(on_adhoc_set_hotkey, adhoc_set_hotkey_finished, adhoc_set_hotkey_reset),
                                             [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
                                             [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
                                             [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
                                             [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
                                             [DANCE_HOTKEY_OR_COMPOSE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_hotkey_or_compose, dance_hotkey_or_compose_finished, dance_hotkey_or_compose_reset),

                                             [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
                                             [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
                                             [DANCE_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_raise, dance_raise_finished, dance_raise_reset),
                                             /* [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset), */
                                             [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
                                             [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
                                             [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
                                             /* [DANCE_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_slash_finished, dance_slash_reset), */
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
                                             [DANCE_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_minus, dance_minus_finished, dance_minus_reset),
                                             [DANCE_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ctrl, dance_ctrl_finished, dance_ctrl_reset),
                                             [DANCE_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lower, dance_lower_finished, dance_lower_reset),
                                             [DANCE_MACROS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macros, dance_macros_finished, dance_macros_reset),
                                             [DANCE_ROFI] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rofi, dance_rofi_finished, dance_rofi_reset),
                                             [DANCE_HYPER]  = ACTION_TAP_DANCE_FN_ADVANCED(on_hyper, hyper_finished, hyper_reset),
                                             [DANCE_ALL_MODS] = ACTION_TAP_DANCE_FN_ADVANCED(on_all_mods, all_mods_finished, all_mods_reset),
                                             [DANCE_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_screenshot, dance_screenshot_finished, dance_screenshot_reset),
                                             [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
                                             [DANCE_PASTE_OR_CLIPBOARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_paste_or_clipboard, paste_or_clipboard_finished, paste_or_clipboard_reset),
                                             [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
                                             [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
                                             [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
                                             [DANCE_PAREN_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_pb, dance_pb_finished, dance_pb_reset),
                                             [DANCE_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_comma, dance_comma_finished, dance_comma_reset),
                                             [DANCE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_dot, dance_dot_finished, dance_dot_reset),

                                             [DANCE_RIGHT_OR_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_right_or_end, dance_right_or_end_finished, dance_right_or_end_reset),
                                             [DANCE_SAVE_LOAD_NS_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_save_load_ns_switch, dance_save_load_ns_switch_finished, dance_save_load_ns_switch_reset),
                                             [DANCE_F5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f5, dance_f5_finished, dance_f5_reset),

                                             [DANCE_LEVEL3_APL] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_LEVEL3_APL, DANCE_LEVEL3_APL_finished, DANCE_LEVEL3_APL_reset),
                                             [DANCE_SHIFT_PAREN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift_paren, dance_shift_paren_finished, dance_shift_paren_reset),
                                             [DANCE_SHIFT_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift_bracket, dance_shift_bracket_finished, dance_shift_bracket_reset),
                                             [DANCE_SHIFT_CURLY] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift_curly, dance_shift_curly_finished, dance_shift_curly_reset),
                                             [DANCE_SHIFT_ANGLE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift_angle, dance_shift_angle_finished, dance_shift_angle_reset),
                                             [DANCE_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_super, dance_super_finished, dance_super_reset),

                                             [DANCE_LEFT_OR_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_left_or_home, dance_left_or_home_finished, dance_left_or_home_reset),

                                             [DANCE_PAGE_UP_OR_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_up_or_home, dance_up_or_home_finished, dance_up_or_home_reset),
                                             [DANCE_PAGE_DOWN_OR_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_down_or_end, dance_down_or_end_finished, dance_down_or_end_reset),
                                             [DANCE_MICROPHONE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_microphone, dance_microphone_finished, dance_microphone_reset),

};
