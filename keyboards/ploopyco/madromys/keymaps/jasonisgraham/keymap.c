#include QMK_KEYBOARD_H

enum custom_keycodes {
    FIRST = SAFE_RANGE,
};

enum {
    TD_LEFT_CLICK,
    TD_BACK,
    TD_RIGHT_CLICK,
    TD_BROWSER_TABS,
};

#define MOUSE_LEFT MS_BTN1
#define MOUSE_RIGHT TD(TD_RIGHT_CLICK)
#define MOUSE_BACK TD(TD_BACK)
#define WINDOWS_SELECTION LSFT(LGUI(LCTL(KC_R)))
#define BROWSER_SEARCH_OPEN_TABS RCTL(LSFT(KC_A))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( MOUSE_BACK, MS_BTN5, DRAG_SCROLL, MOUSE_RIGHT,
                  MOUSE_LEFT, MS_BTN3 )
};


const uint16_t PROGMEM windows_selection[] = {MOUSE_LEFT, MS_BTN3, COMBO_END};
const uint16_t PROGMEM middle_click[] = {MOUSE_LEFT, MOUSE_RIGHT, COMBO_END};
const uint16_t PROGMEM left_browser_tab[] = {MOUSE_BACK, MS_BTN5, COMBO_END};
const uint16_t PROGMEM recent_browser_tab[] = {MS_BTN5, DRAG_SCROLL, COMBO_END};
const uint16_t PROGMEM right_browser_tab[] = {DRAG_SCROLL, MOUSE_RIGHT, COMBO_END};

combo_t key_combos[] = {
    COMBO(middle_click, MS_BTN3),
    COMBO(left_browser_tab, RCTL(KC_PGUP)),
    COMBO(recent_browser_tab, TD(TD_BROWSER_TABS)),
    COMBO(right_browser_tab, RCTL(KC_PGDN)),
    COMBO(windows_selection, WINDOWS_SELECTION),
};


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[10];

enum {TAP = 1, HOLD, TAP2, HOLD2};

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
    }
    return TAP;
}

void on_dance_back(tap_dance_state_t *state, void *user_data) {}

void dance_back_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
    case TAP: tap_code16(MS_BTN4); break;
    case HOLD: tap_code16(MS_BTN5); break;
    default: tap_code16(MS_BTN4); break;
    }
}

void dance_back_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
}

void on_dance_right_click(tap_dance_state_t *state, void *user_data) {}

void dance_right_click_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
    case TAP: tap_code16(MS_BTN2); break;
    case HOLD: toggle_drag_scroll(); break;
    default: tap_code16(MS_BTN2); break;
    }
}

void dance_right_click_reset(tap_dance_state_t *state, void *user_data) {
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

tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_left_click, dance_left_click_finished, dance_left_click_reset),
    [TD_BROWSER_TABS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_browser_tabs, dance_browser_tabs_finished, dance_browser_tabs_reset),
    [TD_BACK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_back, dance_back_finished, dance_back_reset),
    [TD_RIGHT_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_right_click, dance_right_click_finished, dance_right_click_reset),
};
