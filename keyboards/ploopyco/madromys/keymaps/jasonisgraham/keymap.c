#include QMK_KEYBOARD_H

enum custom_codes {
    FIRST = SAFE_RANGE,
    BROWSER_TAB_CLOSE,
};

enum layers {
    BASE,
    WINDOWS,
    BROWSER,
    SYSTEM,
};

enum td_codes {
    TD_U1,
    TD_U4,
    TD_L2,
    TD_BROWSER_TABS,
};

#define WINDOW_SELECTION LSFT(LGUI(LCTL(KC_R)))
#define WINDOW_MINIMIZE LSFT(LGUI(KC_J))

#define BROWSER_TAB_LEFT RCTL(KC_PGUP)
#define BROWSER_TAB_RIGHT RCTL(KC_PGDN)
#define BROWSER_SEARCH_OPEN_TABS RCTL(LSFT(KC_A))

#define MS_U1 TD(TD_U1)
#define MS_U2 MO(BROWSER)
#define MS_U3 MO(WINDOWS)
#define MS_U4 TD(TD_U4)

#define MS_L1 MS_BTN1
#define MS_L2 TD(TD_L2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(MS_U1, MS_U2, MS_U3, MS_U4,
                    MS_L1, MS_L2),

    [BROWSER] = LAYOUT(BROWSER_TAB_LEFT, _______, BROWSER_TAB_RIGHT, TD(TD_BROWSER_TABS),
                       BROWSER_TAB_CLOSE, _______),

    [WINDOWS] = LAYOUT(WINDOW_MINIMIZE, WINDOW_SELECTION, _______, LGUI(MS_BTN1),
                       WINDOW_MINIMIZE, _______),

    [SYSTEM] = LAYOUT(QK_BOOTLOADER, _______, _______, _______,
                      DPI_CONFIG, _______),
};

const uint16_t PROGMEM L1_L2[] = {MS_L1, MS_L2, COMBO_END};
const uint16_t PROGMEM L1_U4[] = {MS_L1, MS_U4, COMBO_END};

combo_t key_combos[] = {
    COMBO(L1_U4, MS_BTN3),
    COMBO(L1_L2, BROWSER_TAB_CLOSE),
};


typedef struct {
    uint8_t step;
} tap;

static tap dance_state[10];

enum {TAP = 1, HOLD, TAP2, HOLD2, TAP3, HOLD3};

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) {
            return HOLD;
        } else {
            return TAP;
        }
    } else if (state->count == 2) {
        if (state->pressed) {
            return HOLD2;
        } else {
            return TAP2;
        }
    } else if (state->count == 3) {
        if (state->pressed) {
            return HOLD3;
        } else {
            return TAP3;
        }
    }
    return TAP;
}

void on_dance_U1(tap_dance_state_t *state, void *user_data) {}

void dance_U1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
    case TAP: tap_code16(MS_BTN4); break;
    case HOLD: tap_code16(MS_BTN5); break;
    default: tap_code16(MS_BTN4); break;
    }
}

void dance_U1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
}

void on_dance_U4(tap_dance_state_t *state, void *user_data) {}

void dance_U4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
    case TAP: tap_code16(MS_BTN2); break;
    case HOLD: toggle_drag_scroll(); break;
    case HOLD2: toggle_drag_scroll(); break;
    default: tap_code16(MS_BTN2); break;
    }
}

void dance_U4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    case HOLD: toggle_drag_scroll(); break;
    }
}

void on_dance_browser_tabs(tap_dance_state_t *state, void *user_data) {}

void dance_browser_tabs_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
    case TAP: tap_code16(LALT(KC_Z)); break;
    case HOLD: tap_code16(BROWSER_SEARCH_OPEN_TABS); break;
    default: tap_code16(LALT(KC_Z)); break;
    }
}

void dance_browser_tabs_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
}

void on_dance_L2(tap_dance_state_t *state, void *user_data) {}

void dance_L2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
    case TAP: tap_code16(MS_BTN3); break;
    case HOLD3: layer_on(SYSTEM); break;
    default: tap_code16(MS_BTN3); break;
    }
}

void dance_L2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    case HOLD3: layer_off(SYSTEM); break;
    default: break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_L2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L2, dance_L2_finished, dance_L2_reset),
    [TD_BROWSER_TABS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_browser_tabs, dance_browser_tabs_finished, dance_browser_tabs_reset),
    [TD_U1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U1, dance_U1_finished, dance_U1_reset),
    [TD_U4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U4, dance_U4_finished, dance_U4_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case BROWSER_TAB_CLOSE:
        if (record->event.pressed) {
            tap_code16(KC_ESC);
            tap_code16(RCTL(KC_W));
        }
        break;
    }

    return true;
}
