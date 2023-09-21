/* #include "keymap_us_extended.h" */
/* #include "keymap_us_international_linux.h" */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case THREAD_LAST_EQUAL:
    return true;


  case KC_DQUO:
    return true;



  case KC_LCBR:
    return true;

  case KC_EXLM:
    return true;

  case KC_AT:
    return true;

  case KC_HASH:
    return true;

  case KC_DLR:
    return true;

  case KC_PERC:
    return true;

  case KC_CIRC:
    return true;

  case KC_AMPR:
    return true;

  case KC_ASTR:
    return true;

  case KC_LPRN:
    return true;

  case KC_RPRN:
    return true;

  case KC_ENTER:
    return true;

  case KC_COLN:
    return true;

  case KC_LEFT_ANGLE_BRACKET:
  case KC_RIGHT_ANGLE_BRACKET:
    return true;


  default:
    return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_DQUO:
    register_code16((!shifted) ? KC_DQUO : KC_QUOT);
    break;

  case THREAD_LAST_EQUAL:
    register_code16((!shifted) ? THREAD_LAST_EQUAL : FN_THEN_THREAD_LAST_EQUAL);
    break;

  case KC_LEFT_ANGLE_BRACKET:
    register_code16((!shifted) ? KC_LEFT_ANGLE_BRACKET : KC_RIGHT_ANGLE_BRACKET);
    break;

  case KC_RIGHT_ANGLE_BRACKET:
    register_code16((!shifted) ? KC_RIGHT_ANGLE_BRACKET : KC_LEFT_ANGLE_BRACKET);
    break;

    case KC_ENTER:
    register_code16((!shifted) ? KC_ENTER : RCTL(KC_ENTER));
    break;

  case KC_COLN:
    register_code16((!shifted) ? KC_COLN : KC_SCLN);
    break;

  case KC_EXLM:
    register_code16((!shifted) ? KC_EXLM : KC_1);
    break;

  case KC_AT:
    register_code16((!shifted) ? KC_AT : KC_2);
    break;

  case KC_HASH:
    register_code16((!shifted) ? KC_HASH : KC_3);
    break;

  case KC_DLR:
    register_code16((!shifted) ? KC_DLR : KC_4);
    break;

  case KC_PERC:
    register_code16((!shifted) ? KC_PERC : KC_5);
    break;

  case KC_CIRC:
    register_code16((!shifted) ? KC_CIRC : KC_6);
    break;

  case KC_AMPR:
    register_code16((!shifted) ? KC_AMPR : KC_7);
    break;

  case KC_ASTR:
    register_code16((!shifted) ? KC_ASTR : KC_8);
    break;

  case KC_LPRN:
    register_code16((!shifted) ? KC_LPRN : KC_9);
    break;

  case KC_RPRN:
    register_code16((!shifted) ? KC_RPRN : KC_0);
    break;

  case KC_LCBR:
    register_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    register_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    register_code16((!shifted) ? KC_TAB : RCTL(KC_I));
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
  case KC_DQUO:
    unregister_code16((!shifted) ? KC_DQUO : KC_QUOT);
    break;

  case THREAD_LAST_EQUAL:
    unregister_code16((!shifted) ? THREAD_LAST_EQUAL : FN_THEN_THREAD_LAST_EQUAL);
    break;

  case KC_LEFT_ANGLE_BRACKET:
    unregister_code16((!shifted) ? KC_LEFT_ANGLE_BRACKET : KC_RIGHT_ANGLE_BRACKET);
    break;


  case KC_RIGHT_ANGLE_BRACKET:
    unregister_code16((!shifted) ? KC_RIGHT_ANGLE_BRACKET : KC_LEFT_ANGLE_BRACKET);
    break;


    case KC_ENTER:
  unregister_code16((!shifted) ? KC_ENTER : RCTL(KC_ENTER));
    break;

  case KC_COLN:
    unregister_code16((!shifted) ? KC_COLN : KC_SCLN);
    break;


  case KC_LCBR:
    unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    unregister_code16((!shifted) ? KC_TAB : RCTL(KC_I));
    break;

  case KC_EXLM:
    unregister_code16((!shifted) ? KC_EXLM : KC_1);
    break;

  case KC_AT:
    unregister_code16((!shifted) ? KC_AT : KC_2);
    break;

  case KC_HASH:
    unregister_code16((!shifted) ? KC_HASH : KC_3);
    break;

  case KC_DLR:
    unregister_code16((!shifted) ? KC_DLR : KC_4);
    break;

  case KC_PERC:
    unregister_code16((!shifted) ? KC_PERC : KC_5);
    break;

  case KC_CIRC:
    unregister_code16((!shifted) ? KC_CIRC : KC_6);
    break;

  case KC_AMPR:
    unregister_code16((!shifted) ? KC_AMPR : KC_7);
    break;

  case KC_ASTR:
    unregister_code16((!shifted) ? KC_ASTR : KC_8);
    break;

  case KC_LPRN:
    unregister_code16((!shifted) ? KC_LPRN : KC_9);
    break;

  case KC_RPRN:
    unregister_code16((!shifted) ? KC_RPRN : KC_0);
    break;

  default:
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    // The IS_RETRO check isn't really necessary here, always using
    // keycode & 0xFF would be fine.
    unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

/* void oneshot_mods_changed_user(uint8_t mods) { */
/*   if (mods & MOD_MASK_SHIFT) { */
/*     println("Oneshot mods SHIFT"); */
/*   } */
/*   if (mods & MOD_MASK_CTRL) { */
/*     println("Oneshot mods CTRL"); */
/*   } */
/*   if (mods & MOD_MASK_ALT) { */
/*     println("Oneshot mods ALT"); */
/*   } */
/*   if (mods & MOD_MASK_GUI) { */
/*     println("Oneshot mods GUI"); */
/*   } */
/*   if (!mods) { */
/*     println("Oneshot mods off"); */
/*   } */
/* } */
