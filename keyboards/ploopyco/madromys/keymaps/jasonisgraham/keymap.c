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
    WINDOW_TILING,
};

enum td_codes {
    TD_U1,
    TD_U4,
    TD_SCROLL_OR_MOVE,
    TD_BROWSER_TABS,
    TD_WORKSPACES,
    TD_WINDOWS_TOGGLE_SCROLL,
};

#define winmove_UL LGUI(LSFT(KC_Y))
#define winmove_UR LGUI(LSFT(KC_O))
#define winmove_R LGUI(LSFT(KC_L))
#define winmove_L LGUI(LSFT(KC_H))
#define winmove_DL LGUI(LSFT(KC_N))
#define winmove_DR LGUI(LSFT(KC_DOT))

bool move_window_active = false;
bool hold_m1 = false;

void hold_m1_off(void) {
    hold_m1 = false;
    unregister_code16(MS_BTN1);
}

void move_window_off(void) {
    hold_m1_off();
    move_window_active = false;
    unregister_code16(LGUI(MS_BTN1));
}

void _toggle_drag_scroll(void) {
    hold_m1_off();
    move_window_off();
    toggle_drag_scroll();
}

void drag_scroll_off(void) {if (is_drag_scroll_active()) _toggle_drag_scroll();}

void drag_scroll_on(void) {if (!is_drag_scroll_active()) _toggle_drag_scroll();}

void hold_m1_on(void) {
    hold_m1 = true;
    register_code16(MS_BTN1);
}

void toggle_hold_m1(void) {hold_m1 ? hold_m1_off() : hold_m1_on();}

void set_drag_scroll(bool new_state) {new_state ? drag_scroll_on() : drag_scroll_off();}

void move_window_on(void) {
    set_drag_scroll(false);
    move_window_active = true;
    register_code16(LGUI(MS_BTN1));
}

void toggle_move_window(void) {
    move_window_active ? move_window_off() : move_window_on();
}

#define WINDOW_SELECTION LSFT(LGUI(LCTL(KC_R)))
#define WINDOW_MINIMIZE LSFT(LGUI(KC_J))
#define WINDOW_MAXIMIZE KC_F11

#define BROWSER_TAB_LEFT RCTL(KC_PGUP)
#define BROWSER_TAB_RIGHT RCTL(KC_PGDN)
#define BROWSER_SEARCH_OPEN_TABS RCTL(LSFT(KC_A))

#define MS_U1 TD(TD_U1)
#define MS_U2 MO(BROWSER)
#define MS_U3 TD(TD_WINDOWS_TOGGLE_SCROLL) // TOGGLE_DRAG_SCROLL)
#define MS_U4 TD(TD_U4)

#define MS_L1 MS_BTN1
#define MS_L2 TD(TD_SCROLL_OR_MOVE)
#define WORKSPACE_SELECT_NEXT LGUI(KC_COMMA)
#define WORKSPACE_MOVE_NEXT LCTL(LGUI(KC_COMMA))
#define WINDOW_ALWAYS_ON_TOP LCTL(LSFT(RCTL(KC_UP)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(MS_U1, MS_U2, MS_U3, MS_U4,
                    MS_L1, MS_L2),

    [BROWSER] = LAYOUT(BROWSER_TAB_LEFT, _______, BROWSER_TAB_RIGHT, TD(TD_BROWSER_TABS),
                       BROWSER_TAB_CLOSE, _______),

    [WINDOWS] = LAYOUT(WINDOW_MAXIMIZE, WINDOW_SELECTION, _______, TD(TD_WORKSPACES),
                       WINDOW_MINIMIZE, _______),

    [SYSTEM] = LAYOUT(QK_BOOTLOADER, _______, _______, _______,
                      DPI_CONFIG, _______),

    [WINDOW_TILING] = LAYOUT(winmove_UL, winmove_L, winmove_R, winmove_UR,
                             winmove_DL, winmove_DR),
};

const uint16_t PROGMEM L1_L2[] = {MS_L1, MS_L2, COMBO_END};
const uint16_t PROGMEM L1_U4[] = {MS_L1, MS_U4, COMBO_END};
const uint16_t PROGMEM U2_U3[] = {MS_U2, MS_U3, COMBO_END};
const uint16_t PROGMEM U3_U4[] = {MS_U3, MS_U4, COMBO_END};
const uint16_t PROGMEM U1_U2_U3_U4[] = {MS_U1, MS_U2, MS_U3, MS_U4, COMBO_END};
/* const uint16_t PROGMEM winmove_DL_LR[] = {winmove_DL, winmove_DR, COMBO_END}; */
const uint16_t PROGMEM winmove_L_R[] = {winmove_L, winmove_R, COMBO_END};

combo_t key_combos[] = {
    COMBO(L1_U4, MS_BTN3),
    COMBO(L1_L2, DPI_CONFIG),
    COMBO(U2_U3, TO(WINDOW_TILING)),
    /* COMBO(U3_U4, TD(TD_SCROLL_OR_MOVE)), */
    COMBO(U1_U2_U3_U4, OSL(SYSTEM)),
    /* COMBO(winmove_DL_LR, TO(BASE)), */
    COMBO(winmove_L_R, TO(BASE)),
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

void dance_U1_reset(tap_dance_state_t *state, void *user_data) {}

void on_dance_U4(tap_dance_state_t *state, void *user_data) {}

void dance_U4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
    case TAP: tap_code16(MS_BTN2); break;
    case HOLD: _toggle_drag_scroll(); break;
    default: tap_code16(MS_BTN2); break;
    }
}

void dance_U4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    case HOLD: _toggle_drag_scroll(); break;
    }
}

void on_dance_scroll_or_window_move(tap_dance_state_t *state, void *user_data) {}

void dance_scroll_or_window_move_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
    case TAP: _toggle_drag_scroll(); break;
    case HOLD: toggle_move_window(); break;
    case HOLD2: toggle_hold_m1(); break;
    }
}

void dance_scroll_or_window_move_reset(tap_dance_state_t *state, void *user_data) {}

void on_dance_browser_tabs(tap_dance_state_t *state, void *user_data) {}

void dance_browser_tabs_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
    case TAP: tap_code16(LALT(KC_Z)); break;
    case HOLD: tap_code16(BROWSER_SEARCH_OPEN_TABS); break;
    default: tap_code16(LALT(KC_Z)); break;
    }
}

void dance_browser_tabs_reset(tap_dance_state_t *state, void *user_data) {}

void on_dance_workspaces(tap_dance_state_t *state, void *user_data) {}

void dance_workspaces_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
    case TAP: tap_code16(WORKSPACE_SELECT_NEXT); break;
    case HOLD: tap_code16(WORKSPACE_MOVE_NEXT); break;
    case HOLD2: tap_code16(WINDOW_ALWAYS_ON_TOP); break;
    }
}

void dance_workspaces_reset(tap_dance_state_t *state, void *user_data) {}

void on_dance_windows_toggle_scroll(tap_dance_state_t *state, void *user_data) {}

void dance_windows_toggle_scroll_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
    case TAP: _toggle_drag_scroll(); break;
    case TAP2: toggle_move_window(); break;
    case TAP3: toggle_hold_m1(); break;
    default:
        layer_on(WINDOWS);
        break;
    }
}

void dance_windows_toggle_scroll_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(WINDOWS);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BROWSER_TABS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_browser_tabs,
                                                     dance_browser_tabs_finished,
                                                     dance_browser_tabs_reset),
    [TD_U1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U1, dance_U1_finished, dance_U1_reset),
    [TD_U4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U4, dance_U4_finished, dance_U4_reset),
    [TD_SCROLL_OR_MOVE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_scroll_or_window_move,
                                                       dance_scroll_or_window_move_finished,
                                                       dance_scroll_or_window_move_reset),
    [TD_WORKSPACES] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_workspaces,
                                                   dance_workspaces_finished,
                                                   dance_workspaces_reset),
    [TD_WINDOWS_TOGGLE_SCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_windows_toggle_scroll,
                                                              dance_windows_toggle_scroll_finished,
                                                              dance_windows_toggle_scroll_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case BROWSER_TAB_CLOSE:
        if (record->event.pressed) {
            tap_code16(KC_ESC);
            tap_code16(RCTL(KC_W));
        }
        break;

    case MS_BTN1:
    case MS_BTN2:
    case MS_BTN4:
    case MS_BTN5:
        if (record->event.pressed) {
            hold_m1_off();
            drag_scroll_off();
            move_window_off();
        }
        break;
    }

    return true;
}
