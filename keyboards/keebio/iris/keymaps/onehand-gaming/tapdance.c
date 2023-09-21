enum tap_dance_codes {
    DANCE_TILDE_RAISE,
    DANCE_ENTER_SPACE,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_4,
    DANCE_5,
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

static tap dance_state[10];

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

/* -----------^ */
void on_dance_1(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_1, state, user_data);
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
    case HOLD:
        register_code16(KC_6);
        break;
	default:
        register_code16(KC_1);
        break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state[1].step) {
    case HOLD:
        unregister_code16(KC_6);
        break;
	default:
        unregister_code16(KC_1);
        break;
    }
    dance_state[1].step = 0;
}
/* -----------^ */

/* -----------^ */
void on_dance_2(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_2, state, user_data);
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
    case HOLD:
        register_code16(KC_7);
        break;
	default:
        register_code16(KC_2);
        break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state[2].step) {
    case HOLD:
        unregister_code16(KC_7);
        break;
	default:
        unregister_code16(KC_2);
        break;
    }
    dance_state[2].step = 0;
}
/* -----------^ */

/* -----------^ */
void on_dance_3(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_3, state, user_data);
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
    case HOLD:
        register_code16(KC_8);
        break;
	default:
        register_code16(KC_3);
        break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state[3].step) {
    case HOLD:
        unregister_code16(KC_8);
        break;
	default:
        unregister_code16(KC_3);
        break;
    }
    dance_state[3].step = 0;
}
/* -----------^ */

/* -----------^ */
void on_dance_4(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_4, state, user_data);
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
    case HOLD:
        register_code16(KC_9);
        break;
	default:
        register_code16(KC_4);
        break;
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state[4].step) {
    case HOLD:
        unregister_code16(KC_9);
        break;
	default:
        unregister_code16(KC_4);
        break;
    }
    dance_state[4].step = 0;
}
/* -----------^ */

/* -----------^ */
void on_dance_5(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_5, state, user_data);
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
    case HOLD:
        register_code16(KC_0);
        break;
	default:
        register_code16(KC_5);
        break;
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_state[5].step) {
    case HOLD:
        unregister_code16(KC_0);
        break;
	default:
        unregister_code16(KC_5);
        break;
    }
    dance_state[5].step = 0;
}
/* -----------^ */


void on_dance_raise(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_GRAVE, state, user_data);
}

void dance_raise_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
    case TAP:
    case TAP_INTERRUPTED:
        tap_code16(KC_GRAVE);
        break;
    case TAP2:
    case TAP2_INTERRUPTED:
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        break;
    case TAP3:
    case TAP3_INTERRUPTED:
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        break;
    case TAP4:
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        break;
    default:
        layer_on(_RAISE);
        break;
    }
}

void dance_raise_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(_RAISE);
    dance_state[0].step = 0;
}


void on_dance_space_enter(tap_dance_state_t *state, void *user_data) {
    on_dance_fn(KC_SPACE, state, user_data);
}

void dance_space_enter_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
    case TAP:
    case TAP_INTERRUPTED:
        tap_code16(KC_SPACE);
        break;
    case TAP2:
    case TAP2_INTERRUPTED:
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        break;
    case TAP3:
    case TAP3_INTERRUPTED:
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        break;
    case TAP4:
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        break;
    case HOLD:
    case HOLD2:
    case HOLD3:
    case HOLD4:
        register_code16(KC_ENTER);
        break;
    }
}

void dance_space_enter_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_ENTER);
    dance_state[10].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_TILDE_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_raise, dance_raise_finished, dance_raise_reset),
    [DANCE_ENTER_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_space_enter, dance_space_enter_finished, dance_space_enter_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};
