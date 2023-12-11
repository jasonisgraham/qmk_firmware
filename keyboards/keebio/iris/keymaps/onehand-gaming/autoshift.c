/* #include "keymap_us_extended.h" */
/* #include "keymap_us_international_linux.h" */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_1:
  case KC_2:
  case KC_3:
  case KC_4:
  case KC_5:
      return true;


  default:
      return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

    case KC_1:
        register_code16((!shifted) ? KC_1 : KC_5);
        break;

    case KC_2:
        register_code16((!shifted) ? KC_2 : KC_7);
        break;

    case KC_3:
        register_code16((!shifted) ? KC_3 : KC_8);
        break;

    case KC_4:
        register_code16((!shifted) ? KC_4 : KC_9);
        break;

    case KC_5:
        register_code16((!shifted) ? KC_5 : KC_0);
        break;

  default:
    register_code16(keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

    case KC_1:
        unregister_code16((!shifted) ? KC_1 : KC_5);
        break;

    case KC_2:
        unregister_code16((!shifted) ? KC_2 : KC_7);
        break;

    case KC_3:
        unregister_code16((!shifted) ? KC_3 : KC_8);
        break;

    case KC_4:
        unregister_code16((!shifted) ? KC_4 : KC_9);
        break;

    case KC_5:
        unregister_code16((!shifted) ? KC_5 : KC_0);
        break;

  default:
    unregister_code16(keycode);
  }
}

