/* #include "keymap_us_extended.h" */
/* #include "keymap_us_international_linux.h" */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    return true;
  case KC_LCBR:
    return true;
  default:
    return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    register_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;

  case KC_LCBR:
    register_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    register_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    register_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;

  case US_PLUS:
    register_code16((!shifted) ? US_PLUS : US_EQL);
    break;

  case US_TQTR:
    register_code16((!shifted) ? US_TQTR : US_RDAQ);
    break;

  case US_IQUE:
    register_code16((!shifted) ? US_IQUE : US_BRKP);
    break;

  case KC_EXLM:
    register_code16((!shifted) ? KC_EXLM : US_IEXL);
      break;

  default:
    if (shifted) {
      add_weak_mods(MOD_BIT(KC_LSFT));
    }
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;
  case KC_LCBR:
    unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;
  case US_IQUE:
    unregister_code16((!shifted) ? US_IQUE : US_BRKP);
    break;

  case KC_LBRACKET:
    unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    unregister_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;

  case US_PLUS:
    unregister_code16((!shifted) ? US_PLUS : US_EQL);
    break;

  case US_TQTR:
    unregister_code16((!shifted) ? US_TQTR : US_RDAQ);
    break;

  case KC_EXLM:
    unregister_code16((!shifted) ? KC_EXLM : US_IEXL);
    break;

  default:
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    // The IS_RETRO check isn't really necessary here, always using
    // keycode & 0xFF would be fine.
    unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot mods SHIFT");
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot mods CTRL");
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot mods ALT");
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot mods GUI");
  }
  if (!mods) {
    println("Oneshot mods off");
  }
}
