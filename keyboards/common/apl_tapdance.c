enum apl_tap_dance_codes {
                          DANCE_APL_ALPHA,
};

void on_dance_apl_alpha(qk_tap_dance_state_t *state, void *user_data);
void dance_apl_alpha_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_apl_alpha_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_apl_alpha(qk_tap_dance_state_t *state, void *user_data) {
  int x = APL_ALPHA;
  if(state->count == 3) {
    tap_code16(x);
    tap_code16(x);
    tap_code16(x);
  }
  if(state->count > 3) {
    tap_code16(x);
  }
}

void dance_apl_alpha_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[100].step = dance_step(state);

  int x = APL_ALPHA;
  int h = APL_ALPHA_UNDERBAR;

  switch (dance_state[100].step) {
  case HOLD:
    register_code16(h); break;
  default:
    register_code16(x); break;
  }
}

void dance_apl_alpha_reset(qk_tap_dance_state_t *state, void *user_data) {
  int x = APL_ALPHA;
  int h = APL_ALPHA_UNDERBAR;

  switch (dance_state[100].step) {
  case HOLD:
    unregister_code16(h); break;
  default:
    unregister_code16(x); break;
  }
}

/* [DANCE_APL_ALPHA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_apl_alpha, dance_apl_alpha_finished, dance_apl_alpha_reset), */
