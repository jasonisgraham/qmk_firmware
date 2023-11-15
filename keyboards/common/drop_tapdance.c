#include "keymap_us_international_linux.h"
#include "print.h"

enum tap_dance_codes {
  DANCE_A,
  DANCE_B,
  DANCE_C,
  DANCE_D,
  DANCE_E,
  DANCE_F,
  DANCE_G,
  DANCE_H,
  DANCE_I,
  DANCE_J,
  DANCE_K,
  DANCE_CAP_K,
  DANCE_L,
  DANCE_M,
  DANCE_N,
  DANCE_O,
  DANCE_P,
  DANCE_Q,
  DANCE_R,
  DANCE_S,
  DANCE_T,
  DANCE_U,
  DANCE_V,
  DANCE_W,
  DANCE_X,
  DANCE_Y,
  DANCE_Z,

                      DANCE_29,
                      DANCE_30,
                      DANCE_ALL_MODS,
                      DANCE_33,
                      DANCE_35,
                      DANCE_36,
                      DANCE_37,
                      DANCE_39,
                      DANCE_40,
                      DANCE_42,
                      DANCE_44,
                      DANCE_45,
                      DANCE_48,
                      DANCE_49,
                      DANCE_50,
                      DANCE_52,
                      DANCE_53,
                      DANCE_55,
                      DANCE_56,
                      DANCE_57,
                      DANCE_58,
                      DANCE_59,
                      DANCE_60,
                      DANCE_61,
                      DANCE_ALT,
                      DANCE_ALT_OR_RCTRL,
                      DANCE_COLN,
                      DANCE_COMMA,
                      DANCE_CTRL,
                      DANCE_DOT,
                      DANCE_EDITING_Q,
                      DANCE_MOD_R4,
                      DANCE_CODE_SYSTEM,
                      DANCE_ESC_CTRL,
                      DANCE_F5,
                      DANCE_FORWARD_SLASH,
                      DANCE_HOTKEY_OR_COMPOSE,
                      DANCE_HYPER,
                      DANCE_LEFT_OR_HOME,
                      DANCE_LEVEL3_ALT_KEYBOARD,
                      DANCE_LOWER,
                      DANCE_MACROS,
                      DANCE_MICROPHONE,
                      DANCE_MINUS,
                      DANCE_PAGE_DOWN_OR_END,
                      DANCE_PAGE_UP_OR_HOME,
                      DANCE_PAREN_BRACKET,
                      DANCE_PASTE_OR_CLIPBOARD,
                      DANCE_QUOTE,
                      DANCE_RAISE,
                      DANCE_RIGHT_OR_END,
                      DANCE_ROFI,
                      DANCE_LAUNCHER_WINDOWS,
                      DANCE_SAVE_LOAD_NS_SWITCH,
                      DANCE_SCREENSHOT,
                      DANCE_LOWER_SHIFT,
                      DANCE_RAISE_SHIFT,
                      DANCE_SHIFT_CURLY,
                      DANCE_SHIFT,
                      DANCE_SLASH,
                      DANCE_SPACE,
                      DANCE_SUPER,
                      DANCE_TAB,
                      DANCE_THREAD_FIRST,
                      DANCE_THREAD_LAST,
                      WWW_BACK_FORWARD,
                      DANCE_ALT_KEYBOARD,
                      DANCE_LEVEL3,
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


#include "tapdance_alpha.c"


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
    tap_code16(emacs_completion_at_point);
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



void on_dance_code_system(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_ENTER, state, user_data);
}

void dance_code_system_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[103].step = dance_step(state);
    switch (dance_state[103].step) {
    case TAP:
    case TAP_INTERRUPTED:
        tap_code16(KC_ENTER);
        break;
    case TAP2:
    case TAP2_INTERRUPTED:
        set_oneshot_layer(_SYSTEM, ONESHOT_START);
        break;
    case TAP3:
    case TAP3_INTERRUPTED:
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        break;
    case TAP4:
        tap_code16 (QK_BOOTLOADER);
        break;
    case HOLD2:
        layer_on(_SYSTEM);
        break;
    default:
#ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom();
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_noeeprom(HSV_CORAL);
        layer_move(_CODE);
#endif
        break;
    }
}

void dance_code_system_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[103].step) {
    case TAP2:
        case TAP2_INTERRUPTED:
            clear_oneshot_layer_state(_SYSTEM);
            break;
    default:
        rgblight_disable();
#ifdef RGBLIGHT_ENABLE
        layer_off(_SYSTEM);
#endif
        layer_off(_CODE);
    }
        dance_state[103].step = 0;

}




void on_dance_mod_r4(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_ENTER, state, user_data);
}

void dance_mod_r4_finished(tap_dance_state_t *state, void *user_data) {
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
    layer_on(_MOTION);
    break;
  }
}

void dance_mod_r4_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
      layer_off(_LEADER1);
    layer_off(_MOTION);
  dance_state[24].step = 0;
}




void on_dance_forward_slash(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_SLASH, state, user_data);
}

void dance_forward_slash_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[25].step = dance_step(state);
  switch (dance_state[25].step) {
  case HOLD:
      register_code16(KC_QUES); break;
  case TAP2:
      tap_code16(KC_SLASH);
      tap_code16(KC_SLASH);
      break;
  case HOLD2:
      register_code16(KC_PIPE); break;
  default: tap_code16(KC_SLASH); break;
  }
}

void dance_forward_slash_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {

    case HOLD: unregister_code16(KC_QUES); break;

  case HOLD2: unregister_code16(KC_PIPE); break;
    default:
        break;
  }
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
  on_dance_fn(KC_SCLN, state, user_data);
}

void dance_coln_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[28].step = dance_step(state);
  switch (dance_state[28].step) {
  case HOLD:
      register_code16(KC_SCLN);
      break;
  case TAP2:
  case HOLD2:
      save_all_then_goto_base();
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_off_sound);
#endif
      break;
  default:
    tap_code16(KC_COLN);

    break;
  }
}

void dance_coln_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
  switch (dance_state[28].step) {
  case HOLD2:
  case HOLD:
      unregister_code16(KC_SCLN);
      break;
  }
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




void on_DANCE_ALL_MODS(tap_dance_state_t *state, void *user_data) {
}

void DANCE_ALL_MODS_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[31].step = dance_step(state);
  switch (dance_state[31].step) {
  /* case TAP_INTERRUPTED: */
  /* case TAP_INTERRUPTED_HELD: */
  case TAP:
    layer_move(_SHIFTLOCK);
#ifdef AUDIO_ENABLE
    PLAY_SONG(caps_lock_on_sound);
#endif
    break;
  case HOLD2:
    register_code16(KC_RALT);
    break;
  default:
    layer_move(_ALL_MODS);
    add_mods(MOD_MASK_ALL_MODS_COMPAT);
    break;
  }
}

void DANCE_ALL_MODS_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[31].step) {
    /* case TAP_INTERRUPTED: */
    /* case TAP_INTERRUPTED_HELD: */
    case TAP:
      break;

  case HOLD2:
    unregister_code16(KC_RALT);
    break;
  default:
    layer_move(_BASE);
    del_mods(MOD_MASK_ALL_MODS_COMPAT);
    clear_mods();
    break;
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
      layer_on(_FN);
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
      layer_off(_FN );
    break;
  default:
    layer_off(_RAISE);
    break;
  }
  dance_state[46].step = 0;
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





void on_dance_55(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_SCLN);
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
  }
}

void dance_ctrl_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[67].step) {
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






void on_esc_ctrl(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_ESC, state, user_data);
}

void esc_ctrl_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[70].step = dance_step(state);
  printf("dance_state[70].step: %u\n", dance_state[70].step);
  switch (dance_state[70].step) {
  case TAP:
  case TAP_INTERRUPTED:
    printf("tap");
    tap_code16(KC_ESC);
    break;
  case TAP2:
  case TAP2_INTERRUPTED:
    printf("tap2");
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    break;
  case TAP3:
  case TAP3_INTERRUPTED:
    printf("tap3");
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    break;
  case TAP4:
  case TAP4_INTERRUPTED:
    printf("tap4");
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    tap_code16(KC_ESC);
    break;

  case TAP_INTERRUPTED_HELD:
  default:
    printf("default");
    register_code16(KC_RCTL);
    break;
  }
}

void esc_ctrl_reset(tap_dance_state_t *state, void *user_data) {
  println("reset  begin");
  wait_ms(10);
  unregister_code16(KC_RCTL);
  dance_state[70].step = 0;
  println("reset  end");
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
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("9"))));
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














void on_dance_save_load_ns_switch(tap_dance_state_t *state, void *user_data) {
}

void dance_save_load_ns_switch_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[83].step = dance_step(state);
  switch (dance_state[83].step) {
  case HOLD:
      // save
      tap_code16(RCTL(KC_SCLN));
      wait_ms(20);
      // load buffer
      tap_code16(RCTL(KC_C));
      wait_ms(20);
      tap_code16(RCTL(KC_K));
      break;
  case HOLD2:
      // save and switch to repl
      tap_code16(RCTL(KC_X));
      wait_ms(20);
      tap_code16(KC_S);
      wait_ms(20);
      tap_code16(KC_1);
      wait_ms(20);
      tap_code16(KC_COMMA);
      wait_ms(20);
      tap_code16(KC_S);
      wait_ms(20);
      tap_code16(KC_S);
      break;
  case TAP2:
      save_all_then_goto_base();
      break;
  default:
      save_then_goto_base();
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
  on_dance_fn(KC_BSPACE, state, user_data);
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
    register_code16(KC_LALT);
    layer_on(_ALT);
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
    unregister_code16(KC_LALT);
    layer_off(_ALT);

  }
}






void on_DANCE_LEVEL3_ALT_KEYBOARD(tap_dance_state_t *state, void *user_data) {
  // on_dance_fn(KC_UP, state, user_data);
}

void DANCE_LEVEL3_ALT_KEYBOARD_finished(tap_dance_state_t *state, void *user_data) {
  printf("active_alt_keyboard_level3_fn: %u\n", active_alt_keyboard_level3_fn);
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
    cycle_active_alt_keyboard_level3_fn();
    break;


  default:
    switch (active_alt_keyboard_level3_fn) {
    case K74_MO_LEVEL3:
#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      rgblight_sethsv_noeeprom(HSV_PINK);
#endif
      register_code16(COMPOSE);
      break;

    case K74_MO_ALT_KEYBOARD:
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

void DANCE_LEVEL3_ALT_KEYBOARD_reset(tap_dance_state_t *state, void *user_data) {
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




void on_dance_shift(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_shift_finished(tap_dance_state_t *state, void *user_data) {
 dance_state[85].step = dance_step(state);
 dprintf("state: %d", dance_state[85].step);
  switch  (dance_state[85].step) {
  case HOLD2:
    layer_move(_SHIFTLOCK);
#ifdef AUDIO_ENABLE
    PLAY_SONG(caps_lock_on_sound);
#endif
    break;

  case HOLD:
  case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
      register_code16(KC_LSFT);
      break;

  case TAP2:
  case TAP2_INTERRUPTED:
      tap_code16(KC_LSHIFT);
      tap_code16(KC_LSHIFT);
      break;

  default:
      tap_code16(KC_LPRN);
      break;

  }
}

void dance_shift_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[85].step) {
    case HOLD2:
        break;
    case HOLD:
    case TAP_INTERRUPTED:
  case TAP_INTERRUPTED_HELD:
    unregister_code16(KC_LSFT);
    break;

  }
  dance_state[85].step = 0;
}


void on_dance_raise_shift(tap_dance_state_t *state, void *user_data) {
  on_dance_fn(KC_LSFT, state, user_data);
}

void dance_raise_shift_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[101].step = dance_step(state);
  switch (dance_state[101].step) {
  case TAP:
  case TAP_INTERRUPTED:
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

void dance_raise_shift_reset(tap_dance_state_t *state, void *user_data) {
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
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
      break;
  case TAP3:
  case TAP3_INTERRUPTED:
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
      break;
  case TAP4:
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
      tap_code16(KC_PIPE);
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
    layer_on(_SUPER);
    break;
  case HOLD2:
      layer_on(_WINMOVE);
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
    layer_off(_SUPER);
    break;

  case HOLD2:
      layer_off(_WINMOVE);
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


void on_dance_lower_shift(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_LSFT, state, user_data);
}

void dance_lower_shift_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[102].step = dance_step(state);
    switch (dance_state[102].step) {

    case TAP:
    case TAP_INTERRUPTED:
        tap_code16(KC_LBRACKET);
        break;
    case TAP2:
    case TAP2_INTERRUPTED:
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        break;
    case TAP3:
    case TAP3_INTERRUPTED:
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        break;
    case TAP4:
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        break;

    default:
        register_code16(KC_LSFT);
        break;
  }
}

void dance_lower_shift_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[102].step) {
    case TAP:
    case TAP_INTERRUPTED:
    case TAP2:
    case TAP2_INTERRUPTED:
    case TAP3:
    case TAP3_INTERRUPTED:
    case TAP4:
        break;

    default:
        unregister_code16(KC_LSFT);
        break;
  }
  dance_state[101].step = 0;
}



/* #include "alt_keyboard_tapdance.c" */

tap_dance_action_t tap_dance_actions[] = {
                                             [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
                                             [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
                                             [DANCE_ALL_MODS] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_ALL_MODS, DANCE_ALL_MODS_finished, DANCE_ALL_MODS_reset),
                                             [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
                                             [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
                                             [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
                                             [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
                                             [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
                                             [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
                                             [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
                                             [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
                                             [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
                                             [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
                                             [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
                                             [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
                                             [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_52, dance_52_finished, dance_52_reset),
                                             [DANCE_53] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_53, dance_53_finished, dance_53_reset),
                                             [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
                                             [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
                                             [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
                                             [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_57_finished, dance_57_reset),
                                             [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
                                             [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset),
                                             [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset),
                                             [DANCE_61] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_61, dance_61_finished, dance_61_reset),
                                             [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_b, dance_b_finished, dance_b_reset),
                                             [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_w, dance_w_finished, dance_w_reset),
                                             [DANCE_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt, alt_finished, alt_reset),
                                             [DANCE_ALT_OR_RCTRL] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt_or_rctrl, alt_or_rctrl_finished, alt_or_rctrl_reset),
                                             [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
                                             [DANCE_COLN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_coln, dance_coln_finished, dance_coln_reset),
                                             [DANCE_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_comma, dance_comma_finished, dance_comma_reset),
                                             [DANCE_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ctrl, dance_ctrl_finished, dance_ctrl_reset),
                                             [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
                                             [DANCE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_dot, dance_dot_finished, dance_dot_reset),
                                             [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
                                             [DANCE_EDITING_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_editing_q, dance_editing_q_finished, dance_editing_q_reset),
                                             [DANCE_MOD_R4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_mod_r4, dance_mod_r4_finished, dance_mod_r4_reset),
                                             [DANCE_CODE_SYSTEM] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_code_system, dance_code_system_finished, dance_code_system_reset),
                                             [DANCE_ESC_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(on_esc_ctrl, esc_ctrl_finished, esc_ctrl_reset),
                                             [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset),
                                             [DANCE_F5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f5, dance_f5_finished, dance_f5_reset),
                                             [DANCE_FORWARD_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_forward_slash, dance_forward_slash_finished, dance_forward_slash_reset),
                                             [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
                                             [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
                                             [DANCE_HOTKEY_OR_COMPOSE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_hotkey_or_compose, dance_hotkey_or_compose_finished, dance_hotkey_or_compose_reset),
                                             [DANCE_HYPER]  = ACTION_TAP_DANCE_FN_ADVANCED(on_hyper, hyper_finished, hyper_reset),
                                             [DANCE_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_H, dance_H_finished, dance_H_reset),
                                             [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset),
                                             [DANCE_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_J, dance_J_finished, dance_J_reset),
                                             [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset),
                                             [DANCE_CAP_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cap_K, dance_cap_K_finished, dance_cap_K_reset),
                                             [DANCE_LEFT_OR_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_left_or_home, dance_left_or_home_finished, dance_left_or_home_reset),
                                             [DANCE_LEVEL3_ALT_KEYBOARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_LEVEL3_ALT_KEYBOARD, DANCE_LEVEL3_ALT_KEYBOARD_finished, DANCE_LEVEL3_ALT_KEYBOARD_reset),
                                             [DANCE_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lower, dance_lower_finished, dance_lower_reset),
                                             [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset),
                                             [DANCE_MACROS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macros, dance_macros_finished, dance_macros_reset),
                                             [DANCE_MICROPHONE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_microphone, dance_microphone_finished, dance_microphone_reset),
                                             [DANCE_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_minus, dance_minus_finished, dance_minus_reset),
                                             [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset),
                                             [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
                                             [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset),
                                             [DANCE_PAGE_DOWN_OR_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_down_or_end, dance_down_or_end_finished, dance_down_or_end_reset),
                                             [DANCE_PAGE_UP_OR_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_up_or_home, dance_up_or_home_finished, dance_up_or_home_reset),
                                             [DANCE_PAREN_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_pb, dance_pb_finished, dance_pb_reset),
                                             [DANCE_PASTE_OR_CLIPBOARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_paste_or_clipboard, paste_or_clipboard_finished, paste_or_clipboard_reset),
                                             [DANCE_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_P, dance_P_finished, dance_P_reset),
                                             [DANCE_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quote, dance_quote_finished, dance_quote_reset),
                                             [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
                                             [DANCE_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_raise, dance_raise_finished, dance_raise_reset),
                                             [DANCE_RIGHT_OR_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_right_or_end, dance_right_or_end_finished, dance_right_or_end_reset),
                                             [DANCE_ROFI] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rofi, dance_rofi_finished, dance_rofi_reset),
                                             [DANCE_LAUNCHER_WINDOWS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rofi_windows, dance_rofi_windows_finished, dance_rofi_windows_reset),
                                             [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
                                             [DANCE_SAVE_LOAD_NS_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_save_load_ns_switch, dance_save_load_ns_switch_finished, dance_save_load_ns_switch_reset),
                                             [DANCE_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_screenshot, dance_screenshot_finished, dance_screenshot_reset),
                                             [DANCE_LOWER_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lower_shift, dance_lower_shift_finished, dance_lower_shift_reset),
                                             [DANCE_RAISE_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_raise_shift, dance_raise_shift_finished, dance_raise_shift_reset),
                                             [DANCE_SHIFT_CURLY] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift_curly, dance_shift_curly_finished, dance_shift_curly_reset),
                                             [DANCE_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_shift, dance_shift_finished, dance_shift_reset),
                                             [DANCE_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_space, dance_space_finished, dance_space_reset),
                                             [DANCE_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_super, dance_super_finished, dance_super_reset),
                                             [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_tab, dance_tab_finished, dance_tab_reset),
                                             [DANCE_THREAD_FIRST] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_thread_first, dance_thread_first_finished, dance_thread_first_reset),
                                             [DANCE_THREAD_LAST] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_thread_last, dance_thread_last_finished, dance_thread_last_reset),
                                             [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset),
                                             [DANCE_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U, dance_U_finished, dance_U_reset),
                                             [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_v, dance_v_finished, dance_v_reset),
                                             [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
                                             [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
                                             [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
                                             [WWW_BACK_FORWARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_www_back_forward, www_back_forward_finished, www_back_forward_reset),

};
