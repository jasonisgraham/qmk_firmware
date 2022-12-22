bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */

  if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }

  if (!process_layer_lock(keycode, record, LAYER_LOCK)) {
    if (biton32(layer_state) != _BASE) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
#endif
    }
    return false;
  }

  switch (keycode) {


  case level3:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      rgblight_sethsv_noeeprom(HSV_PINK);
#endif
      register_code16(KC_KP_ENTER);
    } else {
      unregister_code16(KC_KP_ENTER);
#ifdef RGBLIGHT_ENABLE
      rgblight_disable();
#endif

    }

    break;


  case KEY_4_7:
    printf("active_k74_fn: %u, pressed: %u\n", active_k74_fn, record->event.pressed);
    if (record->event.pressed) {
      switch (active_k74_fn) {
      case K74_MO_LEVEL3:
#ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom();
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_noeeprom(HSV_PINK);
#endif
        register_code16(KC_KP_ENTER);
        break;
      case K74_MO_APL:
#ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom();
        rgblight_mode(RGBLIGHT_MODE_KNIGHT);
        rgblight_sethsv_noeeprom(HSV_GREEN);
#endif
        register_code16(KEYBOARD_LAYOUT_HOLD_KEY);
        break;
      }
    } else {
      unregister_code16(KC_KP_ENTER);
      unregister_code16(KEYBOARD_LAYOUT_HOLD_KEY);
#ifdef RGBLIGHT_ENABLE
      rgblight_disable();
#endif
    }

    break;

  case WEB_SAVE_FILE_UNDER_CURSOR:
    if (record->event.pressed) {
      tap_code16(KC_MS_BTN2);
      wait_ms(300);
      tap_code16(KC_V);
      wait_ms(500);
      tap_code16(KC_ENTER);
    }
    break;


  case EMACS_FASD:
    if (record->event.pressed) {
      fasd_timer = timer_read();
      fasd_timer_active = true;
      fasd_level = 0;
      return false;
    } else {
      if (fasd_level >= 4) {
        tap_code16(EMACS_FASD_DEFAULT);
      } else if (fasd_level >= 3) {
        tap_code16(EMACS_FASD_GLOBAL_NO_EXT);
      } else if (fasd_level >= 2) {
        tap_code16(EMACS_FASD_PROJECT_NO_EXT);
      } else {
        tap_code16(EMACS_FASD_PROJECT_CURR_EXT);
      }
      fasd_timer_active = false;
      fasd_timer = 0;
    }
    break;

  case SSH_CRONJOBS_PROD:
    if (record->event.pressed) {
      SEND_STRING("ssh cronjobs-prod" SS_TAP(X_ENTER) SS_DELAY(1500));
      SEND_STRING("su app " SS_TAP(X_ENTER) SS_DELAY(250) "cd " SS_TAP(X_ENTER) "cd collage" SS_TAP(X_ENTER));
    }
    break;

  case EMACS_PREV_SEXP:
    if (record->event.pressed) {
      tap_code16(KC_RCBR);
      SEND_STRING(SS_TAP(X_ESC) "zz");
    }
    break;

  case EMACS_NEXT_SEXP:
    if (record->event.pressed) {
      tap_code16(KC_LCBR);
      SEND_STRING(SS_TAP(X_ESC) "zz");
    }
    break;


    // ------
  case APL_ALPHA:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_A);
      tap_code16(KC_L);
      return false;

    }
    break;

  case APL_AND:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_A);
      tap_code16(KC_N);
      return false;


    }
    break;

  case APL_APOSTROPHE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_A);
      tap_code16(KC_P);
      return false;


    }
    break;

  case APL_ALPHA_UNDERBAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_A);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_BACKSLASH_BAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_B);
      tap_code16(KC_B);
      return false;


    }
    break;

  case APL_COMMA_BAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_B);
      return false;


    }
    break;

  case APL_CIRCLE_DIAERESIS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_CHI:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_H);
      return false;


    }
    break;

  case APL_CIRCLE_BACKSLASH:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_CIRCLE_STILE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_L);
      return false;


    }
    break;

  case APL_CIRCLED_MINUS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_M);
      return false;


    }
    break;

  case APL_CIRCLE_STAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_C);
      tap_code16(KC_S);
      return false;


    }
    break;

  case APL_DOWNWARDS_ARROW:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_A);
      return false;


    }
    break;



  case APL_DOWN_CARET_TILDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_DIAERESIS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_DOWN_TACK_JOT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_J);
      return false;


    }
    break;

  case APL_DEL_STILE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_L);
      return false;


    }
    break;

  case APL_DIAMOND:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_M);
      return false;


    }
    break;

  case APL_DELTA_STILE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_S);
      return false;


    }
    break;

  case APL_DELTA_UNDERBAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_DIVISION:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_D);
      tap_code16(KC_V);
      return false;


    }
    break;

  case APL_EPSILON:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_E);
      tap_code16(KC_P);
      return false;


    }
    break;

  case APL_EQUALS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_E);
      tap_code16(KC_Q);
      return false;


    }
    break;

  case APL_EPSILON_UNDERBAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_E);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_GREATER_EQUAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_G);
      tap_code16(KC_E);
      return false;


    }
    break;

  case APL_GREATER:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_G);
      tap_code16(KC_R);
      return false;


    }
    break;

  case APL_IBEAM:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_B);
      return false;


    }
    break;

  case APL_INCREMENT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_IDENTICAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_INTERSECTION:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_N);
      return false;


    }
    break;

  case APL_IOTA:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_O);
      return false;


    }
    break;

  case APL_IOTA_UNDERBAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_I);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_JOT_DIAERESIS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_J);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_LEFT_ARROW:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_A);
      return false;


    }
    break;

  case APL_LEFT_CEILING:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_LESS_EQUAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_E);
      return false;


    }
    break;

  case APL_LEFT_FLOOR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_F);
      return false;


    }
    break;

  case APL_LOW_LINE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_L);
      return false;


    }
    break;

  case APL_LESS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_S);
      return false;


    }
    break;

  case APL_LEFT_TACK:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_L);
      tap_code16(KC_T);
      return false;


    }
    break;

  case APL_MACRON:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_M);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_MULT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_M);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_NABLA:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_N);
      tap_code16(KC_A);
      return false;


    }
    break;

  case APL_NOT_EQUAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_N);
      tap_code16(KC_E);
      return false;


    }
    break;

  case APL_NOT_IDENTICAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_N);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_OMEGA:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_O);
      tap_code16(KC_M);
      return false;


    }
    break;

  case APL_OR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_O);
      tap_code16(KC_R);
      return false;


    }
    break;

  case APL_OMEGA_UNDERBAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_O);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_WHITE_CIRCLE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_P);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_QUAD_COLON:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_QUAD_DIVIDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_QUAD_EQUAL:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_E);
      return false;


    }
    break;

  case APL_QUESTION_MARK:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_M);
      return false;


    }
    break;

  case APL_QUOTE_QUAD:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_Q);
      return false;


    }
    break;

  case APL_QUAD:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Q);
      tap_code16(KC_U);
      return false;


    }
    break;

  case APL_RIGHT_ARROW:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_R);
      tap_code16(KC_A);
      return false;


    }
    break;

  case APL_RHO:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_R);
      tap_code16(KC_H);
      return false;


    }
    break;

  case APL_RING_OPERATOR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_R);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_RIGHT_TACK:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_R);
      tap_code16(KC_T);
      return false;


    }
    break;

  case APL_SLASH_BAR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_B);
      return false;


    }
    break;

  case APL_STAR_DIAERESIS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_SMALL_ELEMENT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_E);
      return false;


    }
    break;

  case APL_STAR_OPERATOR:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_O);
      return false;


    }
    break;

  case APL_SUPERSET:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_P);
      return false;


    }
    break;

  case APL_SQUISH_QUAD:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_S);
      tap_code16(KC_Q);
      return false;


    }
    break;

  case APL_TILDE_DIAERESIS:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_T);
      tap_code16(KC_D);
      return false;


    }
    break;

  case APL_TILDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_T);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_UPWARDS_ARROW:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_U);
      tap_code16(KC_A);
      return false;


    }
    break;

  case APL_UP_CARET_TILDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_U);
      tap_code16(KC_C);
      return false;


    }
    break;

  case APL_UNION:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_U);
      tap_code16(KC_N);
      return false;


    }
    break;

  case APL_UP_TACK:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_U);
      tap_code16(KC_T);
      return false;


    }
    break;

  case APL_VERTICAL_LINE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_V);
      tap_code16(KC_L);
      return false;


    }
    break;

  case APL_ZILDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_A);
      tap_code16(KC_Z);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_DEL_TILDE:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_D);
      tap_code16(KC_T);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_DOWN_TACK:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_D);
      tap_code16(KC_T);
      tap_code16(KC_K);
      return false;


    }
    break;

  case APL_QUAD_DIAMOND:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_Q);
      tap_code16(KC_D);
      tap_code16(KC_I);
      return false;


    }
    break;

  case APL_SUBSET:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_S);
      tap_code16(KC_U);
      tap_code16(KC_B);
      return false;


    }
    break;

  case APL_UP_SHOE_JOT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_U);
      tap_code16(KC_S);
      tap_code16(KC_J);
      return false;


    }
    break;

  case APL_UP_TACK_JOT:
    if (record->event.pressed) {
      tap_code16(KC_SCROLL_LOCK);
      tap_code16(KC_U);
      tap_code16(KC_T);
      tap_code16(KC_J);
      return false;


    }
    break;


    // ----



  case OPEN_PAREN:
    if (record->event.pressed) {
      open_paren_timer = timer_read();
      open_paren_timer_active = true;
      open_paren_level = 0;
      return false;
    } else {
      if (open_paren_level >= 3) {
        tap_code16(KC_LCBR);
      } else if (open_paren_level >= 2) {
        tap_code16(KC_LBRC);
      } else {
        tap_code16(KC_LPRN);
      }
      open_paren_timer_active = false;
      open_paren_timer = 0;
    }
    break;

  case CLOSED_PAREN:
    if (record->event.pressed) {
      closed_paren_timer = timer_read();
      closed_paren_timer_active = true;
      closed_paren_level = 0;
      return false;
    } else {
      if (closed_paren_level >= 3) {
        tap_code16(KC_RCBR);
      } else if (closed_paren_level >= 2) {
        tap_code16(KC_RBRC);
      } else {
        tap_code16(KC_RPRN);
      }
      closed_paren_timer_active = false;
      closed_paren_timer = 0;
    }
    break;


  case EMACS_FRAME_FULL_SCREEN:
    if (record->event.pressed) {
      tap_code16(winmove_mon_up);
      tap_code16(winmove_mon_left);
      tap_code16(KC_F11);
      tap_code16(LCTL(KC_C));
    }
    break;


  case TOGGLE_BREATHING:
    if (record->event.pressed) {
    }
    break;


  case RGBLIGHT_TOGGLE:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_toggle();
#endif
    }
    break;

  case RESET_ANIMATION:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      DROP_DEFAULT_ANIMATION = 0;
      rgblight_mode(DROP_DEFAULT_ANIMATION);
#endif
    }
    break;

  case RGBLIGHT_STEP:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_step();
#endif
    }
    break;

#ifdef RGBLIGHT_ENABLE
  case CYCLE_RGBLIGHT_STEP:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(scroll_lock_on_sound);
#endif
      cycle_rgblight_step();
      /* static char s[10]; */
      /* itoa(k, s, 10); */
      /* SEND_STRING(s); */
    }
    break;

  case CYCLE_FAVE_ANIMATIONS:
    if (record->event.pressed) {
      /* cycle_fave_animations(); */
    }
    break;

  case CYCLE_DROP_COLORS:
    if (record->event.pressed) {
      cycle_drop_color();
    }
    break;

  case CYCLE_DROP_ANIMATIONS:
    if (record->event.pressed) {
      cycle_drop_animations();
    }
    break;
#endif

  case CYCLE_ACTIVE_K74_FN:
    if (record->event.pressed) {
      cycle_active_k74_fn();
    }
    break;


  case TOGGLE_ECHO:
    if (record->event.pressed) {
      toggle_echo();
    }
    break;

  case CLEAR_THAT_REPL:
    if (record->event.pressed) {
      /* SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_RCTL(SS_TAP(X_K)) SS_RCTL(SS_TAP(X_L))); */
      SEND_STRING(SS_RCTL(SS_TAP(X_L)));
    }
    break;


  case ALT_TAB:
    if (record->event.pressed) {

      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LGUI);
      }
      alt_tab_timer = timer_read();
      register_code(KC_TAB);
    } else {
      unregister_code(KC_TAB);

    }
    break;

  case SA_LAYER_ACTIVATE:
    if (record->event.pressed) {
      layer_move(_SA);
#ifdef AUDIO_ENABLE
      PLAY_SONG(zelda_treasure);
#endif
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif

      return false;
    }
    break;



  case SYSTEM_LAYER_ACTIVATE:
    if (record->event.pressed) {
      layer_move(_SYSTEM);
#ifdef AUDIO_ENABLE
      PLAY_SONG(scroll_lock_on_sound);
#endif
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif

      return false;
    }
    break;

  case SYSTEM_LAYER_DEACTIVATE:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(one_up_sound);
      PLAY_SONG(scroll_lock_off_sound);
#endif
      layer_move(_BASE);
      return false;
    }
    break;

  case SHIFTLOCK_LAYER_ACTIVATE:
    if (record->event.pressed) {
      /* #ifdef RGBLIGHT_ENABLE */
      /*       rgblight_mode(42); */
      /* #endif */
      layer_move(_SHIFTLOCK);
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_on_sound);
#endif
#ifdef RGBLIGHT_ENABLE
      /* rgblight_mode(RGBLIGHT_ENABLE_RAINBOW_SWIRL); */
#endif
      return false;
    }
    break;

  case SHIFTLOCK_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      /* #ifdef RGBLIGHT_ENABLE */
      /*       apply_fave_animation(); */
      /*       /\* rgblight_mode(42); *\/ */
      /* #endif */
      layer_move(_BASE);
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_off_sound);
#endif
#ifdef RGBLIGHT_ENABLE
      /* rgblight_mode(RGBLIGHT_ENABLE_RAINBOW_SWIRL); */
#endif

      /* return true; */
    }
    break;

  case EMACS_LOCCUR:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) "no");
    }
    break;

  case TERM_CD_UP_DIR:
    if (record->event.pressed) {
      SEND_STRING("cd ../" SS_TAP(X_ENTER));
    }
    break;

  case TERM_HOME:
    if (record->event.pressed) {
      SEND_STRING("~/");
    }
    break;

  case EMACS_OTHER_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(150) SS_RCTL(SS_TAP(X_X))  SS_TAP(X_O));
    }
    break;

  case EMACS_BUFFER_REVERT:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C))  SS_TAP(X_R));

    }
    break;

  case FISH_ACCEPT_SEND:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_L)))   SS_TAP(X_ENTER));

    }
    break;

  case EMACS_YAS_DOC:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "idoc" macro_alt_slash);
    }
    break;


  case EMACS_INSIDE_YANK:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "yi");
    }
    break;


  case EMACS_INSIDE_DELETE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "di");
    }
    break;


  case EMACS_TO_YANK:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "yt");
    }
    break;


  case EMACS_TO_DELETE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "dt");
    }
    break;

  case EMACS_YAS_TF:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "itf" macro_alt_slash);
    }
    break;
  case EMACS_YAS_C:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ic" macro_alt_slash);
    }
    break;
  case EMACS_YAS_TL:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "itl" macro_alt_slash);
    }
    break;

  case THREAD_FIRST:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i(some-> ");
    }
    break;


  case THREAD_LAST:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i(some->> ");
    }
    break;

  case EMACS_WRAP_IN_THREAD_LAST:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i");
      tap_code16(LALT(KC_LPRN));

      SEND_STRING("->> ") ;
    }
    break;

  case EMACS_YAS_REMOVE_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i(remove #(->> % ");
    }
    break;

  case EMACS_YAS_FILTER_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ifa" macro_alt_slash);
    }
    break;

  case EMACS_YAS_MAP_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "imapa" macro_alt_slash);
    }
    break;

  case EMACS_YAS_KEYS_DESCRUCTURE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ikd" macro_alt_slash);
    }
    break;

  case EMACS_HELM_OCCUR:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) "so");
      break;
    }

  case EMACS_HELM_MARK_RINGS:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) "rm");
      break;
    }

  case CIDER_RUN_PREV_COMMAND:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_P)) SS_TAP(X_ENTER));
      break;
    }

  case EMACS_DESC_KEY:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F1) "k");
    }
    break;

  case EMACS_FINDER_COMMENTARY:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F1) SS_TAP(X_F8));
    }
    break;

  case EMACS_PRIVATE_READER:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i#'" SS_TAP(X_ESC));
    }
    break;


  case EMACS_COMMENT_READER:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "i#_" SS_TAP(X_ESC));
    }
    break;

  case CLJ_REGEX:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "irx" macro_alt_slash);
    }
    break;

  case TEMP_TEXT:
    if (record->event.pressed) {
      /* SEND_STRING("blsIB3Rx0R2tQmW0b9B9bDu4EOntt1i8%28*uE%OOC8FCfe653xevqd6szziAe$!"); */
    }
    break;

  case EMACS_BACKWARD_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "99" SS_LALT(SS_RCTL(SS_TAP(X_U))));
    }
    break;



  case CLJ_SET:
    if (record->event.pressed) {
      SEND_STRING("#{");
    }
    break;

  case CLJ_ANON_FN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ianon" macro_alt_slash);
    }
    break;

  case EMACS_ANON_FN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ianon" macro_alt_slash);
    }
    break;

  case EMACS_YANK_TO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "yt");
    }
    break;


  case EMACS_EVIL_FIND:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "f");
    }
    break;


  case CAPS_WORD_TOGGLE:
    break;

  case AUTOSHIFT_TOGGLE:
    if (record->event.pressed) {

      /* tap_code16(KC_ASTG); */
      if (get_autoshift_state()) {
        autoshift_disable();
#ifdef AUDIO_ENABLE
        PLAY_SONG(caps_lock_on_sound);
#endif
      } else {
        autoshift_enable();
#ifdef AUDIO_ENABLE
        PLAY_SONG(caps_lock_off_sound);
#endif
      }
      /* layer_move(_BASE); */
    }
    break;

  case EMACS_TRANSPOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) "xt");
    }
    break;

  case EMACS_PROJECTILE_FIND_FILE:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) "pf");
    }
    break;

  case EMACS_RE_FIND:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "irf" macro_alt_slash);
    }
    break;

  case EMACS_ACE_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(150) SS_LALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_LSFT(SS_TAP(X_W)));

    }
    break;

  case EMACS_ACE_WINDOW_SWAP:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_LSFT(SS_TAP(X_M)));

    }
    break;

  case EMACS_WINDOW_CLOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M))  SS_TAP(X_W)  SS_TAP(X_C));

    }
    break;

  case EMACS_KILL_PROCESS:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_RCTL(SS_TAP(X_B)));
    }
    break;

  case EMACS_INSERT_GI_GET_FEED:
      if (record->event.pressed) {
        SEND_STRING("(def xs (gi/get-feed importer-config))");
      }
    break;

  case EMACS_INSERT_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING("(def xs (get-feed))");
    }
    break;

  case TMUX_CLOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_TAP(X_X));
    }
    break;

  case ESC_THEN_BASE_LAYER:
    if (record->event.pressed) {
      // only used when returning from shiftlok
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_off_sound);
#endif
      SEND_STRING(SS_TAP(X_ESCAPE));
      layer_move(_BASE);

    }
    break;

  case LAYER_RAISE_HOLD:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(major_sound);
#endif
      layer_move(_RAISE);
      /* rgblight_mode(RGBLIGHT_ENABLE_SNAKE); */
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(18);
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_BLUE);
#endif

      return false;

    }
    break;

  case LAYER_LOWER_HOLD:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_on_sound);
#endif
      layer_move(_LOWER);

#ifdef RGBLIGHT_ENABLE
      /* rgblight_mode(RGBLIGHT_ENABLE_SNAKE); */
      /* rgblight_mode(RGB_MODE_RAINBOW); */
      /* rgblight_mode(18); */
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      /* rgblight_sethsv_noeeprom(HSV_PURPLE); */
#endif
      return false;

    }
    break;

  case LAYER_MOUSE_HOLD:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      /* PLAY_SONG(minor_sound); */
      layer_move(_MOUSE);
#endif

#ifdef RGBLIGHT_ENABLE
      /* rgblight_mode(RGBLIGHT_ENABLE_SNAKE); */
      rgblight_mode(18);
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_GREEN);
#endif

      return false;

    }
    break;



    /* case LAYER_COLORS_HOLD: */
    /*   if (record->event.pressed) { */
    /*     layer_move(_COLORS); */
#ifdef AUDIO_ENABLE
    /*     PLAY_SONG(num_lock_on_sound); */
#endif

    /*   } */
    /*   break; */

  case TMUX_SPLIT_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_V)) SS_TAP(X_MINUS));
    }
    break;

  case EMACS_SPLIT_WINDOW_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_TAP(X_W) SS_TAP(X_K));
    }
    break;

  case EMACS_SPLIT_WINDOW_DOWN:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_TAP(X_W) SS_TAP(X_J));
    }
    break;

  case EMACS_SPLIT_WINDOW_RIGHT:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_TAP(X_W) SS_TAP(X_L));
    }
    break;


  case EMACS_SPLIT_WINDOW_LEFT:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_TAP(X_W) SS_TAP(X_H));
    }
    break;


  case EMACS_SEL_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_0));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_1));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_2));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_3));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_4));
      layer_move(_BASE);
    }
    return true;
    break;

  case EMACS_SEL_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_5));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_6));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_7));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_8));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) SS_TAP(X_9));
      layer_move(_BASE);
    }
    break;

  case EMACS_COPY_FILE_PATH:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LSFT(SS_LALT(SS_TAP(X_G))) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_W) SS_TAP(X_Y) SS_DELAY(100) );}
    break;
  case CD_CSV:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) "cdcsv" SS_TAP(X_ENTER));
    }
    break;

  case gauth_fb:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_C) SS_DELAY(100) "ga-cmd fb  | to-clipboard"  SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_X));
      layer_move(_BASE);
    }
    break;

  case gauth_gh:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_C) SS_DELAY(100) "ga-cmd gh  | to-clipboard"  SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_X));
      layer_move(_BASE);
    }
    break;

  case gauth_hb:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_C) SS_DELAY(100) "ga-cmd hb  | to-clipboard"  SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_X));
      layer_move(_BASE);
    }
    break;

  case gauth_lp:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_C) SS_DELAY(100) "ga-cmd lp  | to-clipboard"  SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_X));
      layer_move(_BASE);
    }
    break;

  case gauth_plex:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_C) SS_DELAY(100) "ga-cmd plex  | to-clipboard"  SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_RCTL(SS_TAP(X_V)) SS_TAP(X_X));
      layer_move(_BASE);
    }
    break;


    /* case AUDIO_LAYER_HOLD: */
    /*   if (record->event.pressed) { */
    /*     layer_move(_AUDIO); */
    /*   } */
    /*   break; */


  case EMACS_GOTO_REMOTEID:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "remote-id" SS_DELAY(500) SS_TAP(X_ENTER));
    }
    break;


  case EMACS_GOTO_ROLLUP:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "rollup" SS_DELAY(500) SS_TAP(X_ENTER));
    }
    break;

  case EMACS_GOTO_PARSE_ITEM:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "parse-item" SS_DELAY(500) SS_TAP(X_ENTER));
    }
    break;


  case EMACS_GOTO_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "get-feed" SS_DELAY(500) SS_TAP(X_ENTER));
    }
    break;

  case EMACS_GOTO_SYNC_FEED:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "sync-feed" SS_DELAY(500) SS_TAP(X_ENTER));
    }
    break;
  }




  return true;

}
