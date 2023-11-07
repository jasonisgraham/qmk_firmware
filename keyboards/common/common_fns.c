void clear_modifiers(void) {
    unregister_code16(KC_LGUI);
    unregister_code16(KC_RGUI);
    unregister_code16(KC_RALT);
    unregister_code16(KC_LALT);
    unregister_code16(KC_RCTL);
    unregister_code16(KC_LCTL);
    unregister_code16(COMPOSE);
    unregister_code16(KEYBOARD_LAYOUT_HOLD_KEY);
    unregister_code16(KC_LSHIFT);
    unregister_code16(KC_RSHIFT);
}

void save_then_goto_base(void);
void save_then_goto_base(void) {
    tap_code16(RCTL(KC_X));
    wait_ms(MACRO_WAIT);
    tap_code16(KC_S);
    clear_modifiers();
    layer_move(_BASE);
}

void save_all_then_goto_base(void);
void save_all_then_goto_base(void) {
    tap_code16(RCTL(KC_X));
    wait_ms(MACRO_WAIT);
    tap_code16(RCTL(KC_F5));
    wait_ms(MACRO_WAIT);
    tap_code16(KC_ESC);
    wait_ms(MACRO_WAIT);
    clear_modifiers();
    layer_move(_BASE);
}
