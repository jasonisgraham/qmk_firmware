/* #include "keymap_us_extended.h" */
/* #include "keymap_us_international_linux.h" */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case THREAD_LAST_EQUAL:
  case KC_DQUO:
  case KC_F1:
  case KC_F2:
  case KC_F3:
  case KC_F4:
  case KC_F5:
  case KC_F6:
  case KC_F7:
  case KC_F8:
  case KC_F9:
  case KC_F10:
  case KC_F11:
  case KC_F12:
  case KC_TAB:
  case KC_LCBR:
  case KC_EXLM:
  case KC_AT:
  case KC_HASH:
  case KC_DLR:
  case KC_PERC:
  case KC_CIRC:
  case KC_AMPR:
  case KC_ASTR:
  case KC_LPRN:
  case KC_RPRN:
  case KC_ENTER:
  /* case KC_COLN: */
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

  /* case KC_COLN: */
  /*   register_code16((!shifted) ? KC_COLN : KC_SCLN); */
  /*   break; */

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
    register_code16((!shifted) ? KC_TAB : backtab);
    break;



  case KC_F1:
      register_code16((!shifted) ? KC_F1 : LSFT(KC_F1));
      break;

  case KC_F2:
          register_code16((!shifted) ? KC_F2 : LSFT(KC_F2));
      break;

  case KC_F3:
      register_code16((!shifted) ? KC_F3 : LSFT(KC_F3));
      break;

  case KC_F4:
      register_code16((!shifted) ? KC_F4 : LSFT(KC_F4));
      break;

  case KC_F5:
      register_code16((!shifted) ? KC_F5 : LSFT(KC_F5));
      break;

  case KC_F6:
      register_code16((!shifted) ? KC_F6 : LSFT(KC_F6));
      break;

  case KC_F7:
      register_code16((!shifted) ? KC_F7 : LSFT(KC_F7));
      break;

  case KC_F8:
      register_code16((!shifted) ? KC_F8 : LSFT(KC_F8));
      break;

  case KC_F9:
      register_code16((!shifted) ? KC_F9 : LSFT(KC_F9));
      break;

  case KC_F10:
      register_code16((!shifted) ? KC_F10 : LSFT(KC_F10));
      break;

  case KC_F11:
      register_code16((!shifted) ? KC_F11 : LSFT(KC_F11));
      break;

  case KC_F12:
      register_code16((!shifted) ? KC_F12 : LSFT(KC_F12));
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

  /* case KC_COLN: */
  /*   unregister_code16((!shifted) ? KC_COLN : KC_SCLN); */
  /*   break; */


  case KC_LCBR:
    unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    unregister_code16((!shifted) ? KC_TAB : backtab);
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

  case KC_F1:
      unregister_code16((!shifted) ? KC_F1 : LSFT(KC_F1));
      break;

  case KC_F2:
          unregister_code16((!shifted) ? KC_F2 : LSFT(KC_F2));
      break;

  case KC_F3:
      unregister_code16((!shifted) ? KC_F3 : LSFT(KC_F3));
      break;

  case KC_F4:
      unregister_code16((!shifted) ? KC_F4 : LSFT(KC_F4));
      break;

  case KC_F5:
      unregister_code16((!shifted) ? KC_F5 : LSFT(KC_F5));
      break;

  case KC_F6:
      unregister_code16((!shifted) ? KC_F6 : LSFT(KC_F6));
      break;

  case KC_F7:
      unregister_code16((!shifted) ? KC_F7 : LSFT(KC_F7));
      break;

  case KC_F8:
      unregister_code16((!shifted) ? KC_F8 : LSFT(KC_F8));
      break;

  case KC_F9:
      unregister_code16((!shifted) ? KC_F9 : LSFT(KC_F9));
      break;

  case KC_F10:
      unregister_code16((!shifted) ? KC_F10 : LSFT(KC_F10));
      break;

  case KC_F11:
      unregister_code16((!shifted) ? KC_F11 : LSFT(KC_F11));
      break;

  case KC_F12:
      unregister_code16((!shifted) ? KC_F12 : LSFT(KC_F12));
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
