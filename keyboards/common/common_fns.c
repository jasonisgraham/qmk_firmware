void save_all(void);
void save_all(void) {
    tap_code16(RCTL(KC_X));
    wait_ms(MACRO_WAIT);
    tap_code16(KC_S);
    layer_off(_SHIFTLOCK);
}

void save_all_and_esc(void);
void save_all_and_esc(void) {
    tap_code16(RCTL(KC_X));
    wait_ms(MACRO_WAIT);
    tap_code16(RCTL(KC_S));
    wait_ms(MACRO_WAIT);
    tap_code16(KC_ESC);
    wait_ms(MACRO_WAIT);
    layer_off(_SHIFTLOCK);
}
