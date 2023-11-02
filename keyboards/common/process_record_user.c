void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_CTRL) {
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode(RGBLIGHT_MODE_TWINKLE);
    }
    if (!mods) {
        rgblight_disable();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //   if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }

    //   if (!process_layer_lock(keycode, record, LAYER_LOCK)) {
    //     if (biton32(layer_state) != _BASE) {
    // #ifdef RGBLIGHT_ENABLE
    //       rgblight_mode(RGBLIGHT_MODE_SNAKE);
    // #endif
    //     }
    //     return false;
    //   }

    switch (keycode) {

        /* case esc_ctrl: */
        /*   if (record->event.pressed) { */
        /*     rgblight_blink_layer(1, 500); */

        /*   } */
        /*   break; */
    case EASYMOTION_LEADER:
        if (record->event.pressed) {
            tap_code16(KC_ESC);
            wait_ms(50);
            tap_code16(KC_PIPE);
            wait_ms(50);
            tap_code16(KC_PIPE);
        }
        break;


    case OPEN_NOTIFICATIONS:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_RCTL("$")));
        }
        break;

    case CLEAR_NOTIFICATIONS:
        if (record->event.pressed) {
            tap_code16(LALT(KC_DLR));
            SEND_STRING(SS_DELAY(30));
            tap_code16(KC_ESC);
        }
        break;

    case LPRN_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("(= ");
        }
        break;

    case CIDER_EVAL_OR_TERMINAL_EDIT:
        if (record->event.pressed) {
            SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(50) SS_RCTL (SS_TAP (X_E)));
        }
        break;

    case SAVE_FILE_THEN_VIM_NORMAL_MODE:
        if (record->event.pressed) {
        }
        break;

    case EQUAL_THEN_SPACE:
        if (record->event.pressed) {
            SEND_STRING("= ");
        }
        break;

    case THREAD_LAST_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("->> % (= ");
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(" ");
        }
        break;

    case FN_THEN_THREAD_LAST_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("(->> % (= ");
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(" ");
        }
        break;

    case LISP_COMMENT:
        if (record->event.pressed) {
            SEND_STRING(";; ");
        }
        break;






    case EMACS_WINNER_UNDO:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            SEND_STRING(SS_DELAY(50) "wu");
        }
        break;

    case EMACS_WINNER_REDO:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            SEND_STRING(SS_DELAY(50) "wU");
        }
        break;


    case SHRUG:
        if (record->event.pressed) {
            SEND_STRING(SS_DELAY(50) "🤷‍");
        }
        break;

    case TO_BASE:
        if (record->event.pressed) {
            PLAY_SONG(caps_lock_off_sound);
            layer_move(_BASE);
            clear_modifiers();
            unregister_key(level3);
            unregister_key(KEYBOARD_LAYOUT_HOLD_KEY);
        }
        break;


    case LLOCK_ALT_KEYBOARD:
        if (record->event.pressed) {
            clear_modifiers();
            layer_move(_BASE);
            register_key(KEYBOARD_LAYOUT_HOLD_KEY);
            return false;
        }
        break;

    case LLOCK_LEVEL3:
        if (record->event.pressed) {
            clear_modifiers();
            layer_move(_BASE);
            register_key(level3);
            return false;
        }
        break;

    case LLOCK_LOWER:
#ifdef AUDIO_ENABLE
        PLAY_SONG(caps_lock_on_sound);
#endif
        layer_move(_LOWER);
        return false;
        break;

    case LLOCK_EDITING:
#ifdef AUDIO_ENABLE
        PLAY_SONG(caps_lock_on_sound);
#endif
        layer_move(_EDITING);
        return false;
        break;

    case LLOCK_RAISE:
#ifdef AUDIO_ENABLE
        PLAY_SONG(caps_lock_on_sound);
#endif
        layer_move(_RAISE);
        return false;
        break;

    case LLOCK:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(caps_lock_on_sound);
#endif
#ifdef RGBLIGHT_ENABLE
            rgblight_enable_noeeprom();
            rgblight_mode(RGBLIGHT_MODE_SNAKE);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
#endif
            layer_move(_LAYER_LOCK);
            return false;
        }
        break;


    case level3:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable_noeeprom();
            rgblight_mode(RGBLIGHT_MODE_SNAKE);
            rgblight_sethsv_noeeprom(HSV_YELLOW);
#endif
            register_code16(KC_KP_ENTER);
        } else {
            unregister_code16(KC_KP_ENTER);
#ifdef RGBLIGHT_ENABLE
            rgblight_disable();
#endif

        }

        break;


    case CLEAR_MODIFIERS:
        if (record->event.pressed) {
            clear_modifiers();
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

    case REFRAME_DISPATCH:
        if (record->event.pressed) {
            SEND_STRING("(");
            wait_ms(50);
            SEND_STRING("r");
            wait_ms(50);
            SEND_STRING("f");
            wait_ms(50);
            SEND_STRING("/");
            wait_ms(50);
            SEND_STRING("d");
            wait_ms(50);
            SEND_STRING("i");
            wait_ms(50);
            SEND_STRING("s");
            wait_ms(50);
            SEND_STRING("p");
            wait_ms(50);
            SEND_STRING("a");
            wait_ms(50);
            SEND_STRING("t");
            wait_ms(50);
            SEND_STRING("c");
            wait_ms(50);
            SEND_STRING("h");
            wait_ms(50);
            SEND_STRING(" ");
            wait_ms(50);
            SEND_STRING("[");
        }
        break;

    case CLJ_FREQS:
        if (record->event.pressed) {
            SEND_STRING(" frequencies (sort-by val)");
            layer_move(_BASE);
        }
        break;

    case REFRAME_SUBSCRIBE:
        if (record->event.pressed) {
            SEND_STRING("@(rf/subscribe [");
            layer_move(_BASE);
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

    case CIDER_RUN_TEST:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            SEND_STRING("mtt");
        }
        break;

    case EMACS_FOCUS_REPL_IMMEDIATELY:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            SEND_STRING(SS_DELAY(50));
            tap_code16(KC_M);
            tap_code16(KC_TAB);
            layer_move(_BASE);
        }
        break;



    case EMACS_FOCUS_REPL:
        if (record->event.pressed) {
            tap_code16(select_emacs_clojure);
            SEND_STRING(SS_DELAY(500));
            tap_code16(LALT(KC_M));
            tap_code16(KC_M);
            tap_code16(KC_TAB);
            layer_move(_BASE);
        }
        break;


    case EMACS_TOGGLE_REPL:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            SEND_STRING("mss");
        }
        break;

    case RESET_INPUT_PREFS:
        if (record->event.pressed) {
            tap_code16(GUI(KC_F5));
#ifdef AUDIO_ENABLE
            PLAY_SONG(major_sound);
#endif
        }
        break;

    case RELOAD_TAP_INSPECTOR:
        if (record->event.pressed) {
            // select firefox
            tap_code16(select_firefox);
            SEND_STRING(SS_DELAY(100));
            // go to first tab
            tap_code16(LALT(KC_1));
            SEND_STRING(SS_DELAY(100));
            // reload
            tap_code16(KC_F5);
            SEND_STRING(SS_DELAY(100));
            // return to emacs
            tap_code16(select_emacs);
            SEND_STRING(SS_DELAY(100));
            layer_move(_BASE);
        }
        break;

    case RG_FZF:
        if (record->event.pressed) {
            tap_code16(LALT(KC_Z));
        }

        break;


    case CLJ_ADD_REQS:
        if (record->event.pressed) {
            tap_code16(KC_ESC);
            tap_code16(CTRL_L);
            SEND_STRING("i");
            SEND_STRING(SS_DELAY(100));
            SEND_STRING("rs");
            SEND_STRING(SS_DELAY(100));
            SEND_STRING(macro_alt_slash);
            layer_move(_BASE);
            SEND_STRING(SS_DELAY(100) SS_TAP(X_ENTER));
        }

        break;

    case CLJ_TAP:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
            SEND_STRING("i");
            SEND_STRING(SS_DELAY(100));
            SEND_STRING("tapm");
            SEND_STRING(SS_DELAY(100));
            SEND_STRING(macro_alt_slash);
            layer_move(_BASE);
        }
        break;



    case EMACS_JUMP_ITEM:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_COMMA));
        }
        break;


    case EMACS_DEFUN_END:
        if (record->event.pressed) {
            tap_code16(LCTL(LALT((KC_E))));
            SEND_STRING(SS_TAP(X_ESC) "zz");
        }
        break;

    case EMACS_DEFUN_BEGIN:
        if (record->event.pressed) {
            tap_code16(LCTL(LALT(KC_A)));
            SEND_STRING(SS_TAP(X_ESC) "zz");
        }
        break;


    case EMACS_PREV_SEXP:
        if (record->event.pressed) {
            tap_code16(KC_LCBR);
            SEND_STRING(SS_TAP(X_ESC) "zz");
        }
        break;

    case EMACS_NEXT_SEXP:
        if (record->event.pressed) {
            tap_code16(KC_RCBR);
            SEND_STRING(SS_TAP(X_ESC) "zz");
        }
        break;


        // ------

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
            tap_code16(winmove_U_monitor);
            tap_code16(winmove_R_monitor);
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
            DROP_CURRENT_ANIMATION = 0;
            rgblight_mode(DROP_CURRENT_ANIMATION);
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


    case CYCLE_FAVE_ANIMATIONS:
        if (record->event.pressed) {
            cycle_fave_animations();
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

    case CYCLE_ACTIVE_ALT_KEYBOARD_LEVEL3_FN:
        if (record->event.pressed) {
            cycle_active_alt_keyboard_level3_fn();
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
            tap_code16(KC_ESC);
            SEND_STRING("dgg");
            SEND_STRING("dG");
            tap_code16(CTRL_L);
            SEND_STRING("i");
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
        /* layer_off(_WINDOWS); */
        // layer_move(_BASE);
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
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "no");
    }
    break;

    case TERM_CD_PREVIOUS:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_C));
      SEND_STRING("cd - " SS_TAP(X_ENTER));
      layer_move(_BASE);
    }
    break;


  case TERM_CD_UP_DIR:
    if (record->event.pressed) {
      SEND_STRING("cd ../" SS_TAP(X_ENTER));
      /* layer_move(_BASE); */
    }
    break;

  case TERM_HOME:
    if (record->event.pressed) {
      SEND_STRING("~/");
    }
    break;

  case EMACS_OTHER_WINDOW:
    if (record->event.pressed) {
        SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(50) SS_TAP(X_O));
    }
    break;

  case EMACS_BUFFER_REVERT:
    if (record->event.pressed) {
        tap_code16(RCTL (KC_X));
        wait_ms(50);
        tap_code16(RCTL(KC_R));
    }
    break;

  case FISH_ACCEPT_SEND:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_L)))  SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;

  case EMACS_YAS_DOC:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("doc" macro_alt_slash);
      layer_move(_BASE);
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
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("tf" macro_alt_slash);
      layer_move(_BASE);
    }
    break;
  case EMACS_YAS_C:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("c" macro_alt_slash);
      layer_move(_BASE);
    }
    break;
  case EMACS_YAS_TL:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("tl" macro_alt_slash);
      layer_move(_BASE);
    }
    break;

  case THREAD_FIRST:
    if (record->event.pressed) {
        tap_code16(KC_MINUS);
        wait_ms(50);
        tap_code16(KC_RIGHT_ANGLE_BRACKET);
        tap_code16(KC_SPACE);
    }
    break;

  case CLJ_ARROW:
    if (record->event.pressed) {
      SEND_STRING("->") ;
    }
    break;

  case THREAD_LAST:
    if (record->event.pressed) {
      SEND_STRING("->> ") ;
    }
    break;

  case EMACS_WRAP_HYDRA:
    if (record->event.pressed) {
      tap_code16(LALT(KC_M));
      SEND_STRING(SS_DELAY(10));
      tap_code16(KC_W);
      SEND_STRING(SS_DELAY(10));
      tap_code16(KC_S);
      SEND_STRING(SS_DELAY(10));
    }
    break;

  case HOME_THEN_EMACS_WRAP_IN_THREAD_LAST:
    if (record->event.pressed) {
      tap_code16(KC_HOME);
      tap_code16(LALT(KC_M));
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_W);
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_S);
      SEND_STRING(SS_DELAY(100));
      tap_code16(KC_L);
    }
    break;

  case HOME_THEN_EMACS_WRAP_IN_THREAD_FIRST:
    if (record->event.pressed) {
      tap_code16(KC_HOME);
      tap_code16(LALT(KC_M));
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_W);
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_S);
      SEND_STRING(SS_DELAY(100));
      tap_code16(KC_F);
    }
    break;


  case EMACS_WRAP_IN_THREAD_LAST:
    if (record->event.pressed) {
      tap_code16(LALT(KC_M));
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_W);
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_S);
      SEND_STRING(SS_DELAY(100));
      tap_code16(KC_L);
    }
    break;

  case EMACS_WRAP_IN_THREAD_FIRST:
    if (record->event.pressed) {
      tap_code16(LALT(KC_M));
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_W);
      SEND_STRING(SS_DELAY(30));
      tap_code16(KC_S);
      SEND_STRING(SS_DELAY(100));
      tap_code16(KC_F);
    }
    break;



  case EMACS_WRAP_IN_THREAD_LAST_SOME:
    if (record->event.pressed) {
      tap_code16(LALT(KC_LPRN));
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(10));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(10));
      SEND_STRING("some->> ") ;
      tap_code16(PAREDIT_BACKWARD_UP);
      SEND_STRING(SS_DELAY(10));
      tap_code16(EMACS_JUMP_ITEM);
      SEND_STRING(SS_DELAY(10));
      SEND_STRING("i ");
    }
    break;

  case EMACS_YAS_REMOVE_ANON:
    if (record->event.pressed) {

      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("(remove #(->> % ");
      layer_move(_BASE);
    }
    break;

  case EMACS_YAS_FILTER_ANON:
    if (record->event.pressed) {

      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("fa" macro_alt_slash);
      layer_move(_BASE);
    }
    break;

  case EMACS_YAS_MAP_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("mapa" macro_alt_slash);
      layer_move(_BASE);
    }
    break;

  case EMACS_YAS_KEYS_DESCRUCTURE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("kd" macro_alt_slash);
      layer_move(_BASE);
    }
    break;

  case EMACS_HELM_OCCUR:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "so");
      break;
    }

  case EMACS_HELM_KILL_RINGS:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "ry");
      break;
    }


  case EMACS_HELM_MARK_RINGS:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "rm");
      break;
    }

  case CIDER_RUN_PREV_COMMAND:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_P)) SS_TAP(X_ENTER));
      break;
    }

  case EMACS_DESC_KEY:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F1) SS_DELAY(50) "k");
    }
    break;

  case EMACS_FINDER_COMMENTARY:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F1) SS_DELAY(50) SS_TAP(X_F8));
    }
    break;

  case EMACS_PRIVATE_READER:
    if (record->event.pressed) {
      SEND_STRING("#'");
    }
    break;


  case EMACS_COMMENT_READER:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("#_" SS_TAP(X_ESC));
    }
    break;

  case CLJ_REGEX:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("rx" macro_alt_slash);
    }
    break;

  case TEMP_TEXT:
    if (record->event.pressed) {
        SEND_STRING("dogman");
    }
    break;

  case EMACS_BACKWARD_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "99" SS_LALT(SS_RCTL(SS_TAP(X_U))));
    }
    layer_move(_BASE);
    break;



  case CLJ_SET:
    if (record->event.pressed) {
      SEND_STRING("#{");
    }
    break;

  case CLJ_ANON_FN:
    if (record->event.pressed) {
      SEND_STRING("#(");
    }
    break;

  case EMACS_ANON_FN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("anon" macro_alt_slash);
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
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "xt");
    }
    break;

  case EMACS_PROJECTILE_FIND_FILE:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(50) "pf");
    }
    break;

  case EMACS_RE_FIND:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("rf" macro_alt_slash);
    }
    break;

  case EMACS_ACE_WINDOW_SELECT:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_LSFT(SS_TAP(X_W)));

    }
    break;

  case EMACS_ACE_WINDOW_SWAP:
    if (record->event.pressed) {
      SEND_STRING( SS_LALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_LSFT(SS_TAP(X_M)));

    }
    break;

    case EMACS_BUFFER_MAXIMIZE:
        if (record->event.pressed) {
            SEND_STRING( SS_RCTL(SS_TAP(X_X))  SS_DELAY(50) SS_TAP(X_1));

        }
        break;



  case EMACS_KILL_PROCESS:
    if (record->event.pressed) {
        SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_DELAY(50) SS_RCTL(SS_TAP(X_B)));
    }
    break;

  case COPY_TEXT_OPEN_NEW_TAB_SEARCH:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C))  SS_DELAY(10) SS_RCTL(SS_TAP(X_T)) SS_DELAY(100)  SS_RCTL(SS_TAP(X_V)) SS_DELAY(10) SS_TAP(X_ENTER));
      layer_move(_BASE);
    }
    break;

  case EMACS_INSERT_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING("(def xs (get-feed))");
      layer_move(_BASE);
    }
    break;

  case TMUX_CLOSE:
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_DELAY(50) SS_TAP(X_X));
    }
    break;

  case ESC_THEN_BASE_LAYER:
    if (record->event.pressed) {
      // only used when returning from shiftlok
      /* #ifdef AUDIO_ENABLE */
      /*       PLAY_SONG(caps_lock_off_sound); */
      /* #endif */
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
        tap_code16(RCTL(KC_X));
        wait_ms(30);
        tap_code16(KC_2);
    }
    break;

    case EMACS_SPLIT_WINDOW_DOWN:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            tap_code16(RCTL(KC_2));
        }
        break;

    case EMACS_SPLIT_WINDOW_RIGHT:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            tap_code16(RCTL(KC_3));
        }
        break;


    case EMACS_SPLIT_WINDOW_LEFT:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            tap_code16(KC_3);
    }
    break;

    case EMACS_WINDOW_DELETE:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            tap_code16(KC_0);
        }
        break;

    case MOVE_STATEMENT_UP:
        if (record->event.pressed) {
            tap_code16(LALT(LSFT(KC_UP)));
        }
        break;

    case MOVE_STATEMENT_DOWN:
        if (record->event.pressed) {
            tap_code16(LALT(LSFT(KC_DOWN)));
        }
        break;

    case DUPLICATE_LINE:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            add_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
            tap_code16(KC_Y);
            del_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);

        }
        break;

    case SURROUND:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(30);
            add_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
            tap_code16(KC_S);
            del_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);

        }
        break;


    case EMACS_SEL_P:
        if (record->event.pressed) {
            tap_code16(LALT(KC_0));
        }
    break;

    case EMACS_SEL_M:
        if (record->event.pressed) {
            tap_code16(LALT(KC_1));
        }
        break;

    case EMACS_SEL_COMMA:
        if (record->event.pressed) {
            tap_code16(LALT(KC_2));
        }
        break;

    case EMACS_SEL_DOT:
        if (record->event.pressed) {
        tap_code16(LALT(KC_3));
        }
        break;

    case EMACS_SEL_J:
        if (record->event.pressed) {
        tap_code16(LALT(KC_4));
        }
        break;

    case EMACS_SEL_K:
        if (record->event.pressed) {
        tap_code16(LALT(KC_5));
    }
    break;

  case EMACS_SEL_L:
    if (record->event.pressed) {
        tap_code16(LALT(KC_6));
    }
    break;

  case EMACS_SEL_U:
    if (record->event.pressed) {
        tap_code16(LALT(KC_7));
    }
    break;

  case EMACS_SEL_I:
    if (record->event.pressed) {
        tap_code16(LALT(KC_8));
    }
    break;

  case EMACS_COPY_FILE_PATH:
    if (record->event.pressed) {
      SEND_STRING( SS_LSFT(SS_LALT(SS_TAP(X_G))) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_W) SS_TAP(X_Y) SS_DELAY(100) );}
    layer_move(_BASE);
    break;

  case EMACS_SET_GLOBAL_LOCATE_DOCS_FILTER_DIR:
    if (record->event.pressed) {
      SEND_STRING( SS_LSFT(SS_LALT(SS_TAP(X_G))) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) );
#ifdef AUDIO_ENABLE
      PLAY_SONG(caps_lock_on_sound);
#endif
    }
    layer_move(_BASE);
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


  case CLJ_REFIND:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(100));
      SEND_STRING("i");
      SEND_STRING(SS_DELAY(100));
      SEND_STRING("(re-find #\"(?i)\"");
      SEND_STRING(SS_TAP(X_ESC) SS_DELAY(50));
      SEND_STRING("hi");
      layer_move(_BASE);
    }
    break;

  case COPY_LATEST_FILE_TO_CLIPBOARD:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_F11))));
      layer_move(_BASE);
    }
    break;


  case CIDER_HISTORY_WRITE:
    if (record->event.pressed) {
      tap_code16(LALT(LCTL(KC_2)));
      layer_move(_BASE);
    }
    break;

  case ROFI_CIDER_HISTORY:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("3"))));
      layer_move(_BASE);
    }
    break;

   case LAUNCHER_SYSTEM:
        if (record->event.pressed) {
            tap_code16(ULAUNCHER);
            wait_ms(300);
            tap_code16(KC_S);
            wait_ms(100);
            tap_code16(KC_Y);
            wait_ms(100);
            tap_code16(KC_S);
            wait_ms(100);
            tap_code16(KC_SPACE);
            layer_move(_BASE);
        }
        break;

    case LAUNCHER_FDFIND:
        if (record->event.pressed) {
            tap_code16(ULAUNCHER);
            wait_ms(300);
            tap_code16(KC_F);
            wait_ms(100);
            tap_code16(KC_SPACE);
            layer_move(_BASE);
        }
        break;


    case LAUNCHER_GOOGLE:
        if (record->event.pressed) {
            tap_code16(ULAUNCHER);
            wait_ms(300);
            tap_code16(KC_G);
            wait_ms(100);
            tap_code16(KC_G);
            wait_ms(100);
            tap_code16(KC_SPACE);
            layer_move(_BASE);
        }
        break;

    case LAUNCHER_DEFINE:
        if (record->event.pressed) {
            tap_code16(ULAUNCHER);
            wait_ms(300);
            tap_code16(KC_D);
            wait_ms(100);
            tap_code16(KC_E);
            wait_ms(100);
            tap_code16(KC_F);
            wait_ms(100);
            tap_code16(KC_SPACE);
            layer_move(_BASE);
        }
        break;


  case LAUNCHER_TRANSLATE:
      if (record->event.pressed) {
          tap_code16(ULAUNCHER);
          wait_ms(300);
          tap_code16(KC_T);
          wait_ms(100);
          tap_code16(KC_R);
          wait_ms(100);
          tap_code16(KC_SPACE);
          layer_move(_BASE);
      }
      break;


    case ACEJUMP:
      if (record->event.pressed) {
          tap_code16(RCTL(KC_X));
          wait_ms(50);
          add_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
          tap_code16(KC_J);
          del_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
      }
      return false;
      break;


    case SELECTION_SHRINK:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            wait_ms(50);
            tap_code16(RSFT(KC_V));
        }
        return false;
        break;

    case SELECTION_EXPAND:
        if (record->event.pressed) {
            tap_code16(LALT(KC_M));
            wait_ms(50);
            tap_code16(KC_V);
        }
        return false;
        break;

    case ONE_SHOT_ALT_KEYBOARD:
    if (record->event.pressed) {
        set_oneshot_mods(MOD_BIT_RGUI);
    }
    return false;
    break;

    case ONE_SHOT_LEVEL3:
        if (record->event.pressed) {
            set_oneshot_mods(MOD_BIT_RALT);
        }
        return false;
        break;

    case EMACS_SEL_O:
        if (record->event.pressed) {
            tap_code16(LALT(KC_9));
        }
        return false;
        break;

    case EMACS_SEL_GRAVE:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_GRAVE));
        }
    return false;
    break;


    case EMACS_SEL_TAB:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_SPACE)));
        }
        return false;
        break;

    case EMACS_SEL_A:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_A));
        }
        return false;
        break;

    case EMACS_SEL_S:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_S));
        }
        return false;
        break;

    case EMACS_SEL_LOWER:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_MINUS));
        }
        return false;
        break;

    case EMACS_SEL_MODR1:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_EXLM)));
        }
        return false;
        break;


    case EMACS_SEL_MODR2:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_AT)));
        }
        return false;
        break;


    case EMACS_SEL_MODR3:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_HASH)));
        }
        return false;
        break;


    case EMACS_SEL_EXLM:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_EXLM)));
        }
        return false;
        break;

    case EMACS_SEL_AT:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_AT)));
        }
        return false;
        break;


    case EMACS_SEL_HASH:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_HASH)));
        }
        return false;
        break;


    case EMACS_SEL_DLR:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_DLR)));
        }
        return false;
        break;


    case EMACS_SEL_PERC:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_PERC)));
        }
        return false;
        break;


    case EMACS_SEL_CIRC:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_CIRC)));
        }
        return false;
        break;


    case EMACS_SEL_AMPR:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_AMPR)));
        }
        return false;
        break;


    case EMACS_SEL_ASTR:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_ASTR)));
        }
        return false;
        break;


    case EMACS_SEL_LPRN:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_LPRN)));
        }
        return false;
        break;


    case EMACS_SEL_RPRN:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_RPRN)));
        }
        return false;
        break;



    case EMACS_SEL_MODR4:
        if (record->event.pressed) {
            tap_code16(LSFT(RCTL(KC_X)));
            wait_ms(50);
            tap_code16(RCTL(LALT(KC_DLR)));
        }
        return false;
        break;

    case EMACS_SEL_SLASH:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_SLASH));
        }
        return false;
        break;

    case EMACS_SEL_N:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_N));
        }
        return false;
        break;



    case EMACS_SEL_SCLN:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_SCLN));
        }
        return false;
        break;


    case EMACS_SEL_D:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_D));
        }
        return false;
        break;

    case EMACS_SEL_T:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_T));
        }
        return false;
        break;


    case EMACS_SEL_C:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_C));
        }
        return false;
        break;

    case EMACS_SEL_R:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_R));
        }
        return false;
        break;

    case EMACS_SEL_G:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_G));
        }
        return false;
        break;

    case EMACS_SEL_F:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_F));
        }
        return false;
        break;

    case EMACS_SEL_RAISE:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_UNDS));
        }
        return false;
        break;

    case EMACS_SEL_H:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_H));
        }
        return false;
        break;

    case EMACS_SEL_Y:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_Y));
        }
        return false;
        break;

    case EMACS_SEL_E:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_E));
        }
        return false;
        break;

    case EMACS_SEL_V:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_V));
        }
        return false;
        break;

    case EMACS_SEL_B:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_B));
        }
        return false;
        break;

    case EMACS_SEL_Q:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_Q));
        }
        return false;
        break;

    case EMACS_SEL_W:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_W));
        }
        return false;
        break;

    case EMACS_SEL_X:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(LALT(KC_X));
        }
        return false;
        break;



    case CTRL_X_ALL_MODS_OSM:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            set_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
        }
        return false;
        break;

    case OSL_RCTL_LALT:
        if (record->event.pressed) {
            add_oneshot_mods(MOD_BIT_RCTRL);
            add_oneshot_mods(MOD_BIT_LALT);
        }
        return false;
        break;

    case ALL_MODS_OSM:
        if (record->event.pressed) {
            set_oneshot_mods(MOD_MASK_ALL_MODS_COMPAT);
        }
        return false;
        break;

    case LAUNCHER_WIKI:
        if (record->event.pressed) {
            tap_code16(ULAUNCHER);
            wait_ms(300);
            tap_code16(KC_W);
            wait_ms(100);
            tap_code16(KC_K);
            wait_ms(100);
            tap_code16(KC_SPACE);
            layer_move(_BASE);
        }
        break;


    case LAUNCHER_CLIPBOARD:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("9"))));
            layer_move(_BASE);
        }
        break;


    case SWAP_SELECTION_BOUNDARIES:
        if (record->event.pressed) {
            tap_code16(RCTL(KC_X));
            wait_ms(50);
            tap_code16(RCTL(KC_X));
        }
        break;


    case LAUNCHER_WINDOWS:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("8"))));
      layer_move(_BASE);
          /* tap_code16(ULAUNCHER); */
          /* wait_ms(300); */
          /* tap_code16(KC_W); */
          /* wait_ms(100); */
          /* tap_code16(KC_SPACE); */
      }
    break;


  case ROFI_LOCATE_PRINT_FILTER_DIR:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_RCTL("^")));
      layer_move(_BASE);
    }
    break;

  case ROFI_CALCULATOR:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("c"))));
      layer_move(_BASE);
    }
    break;


  case ROFI_PROCESSES:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("6"))));
      layer_move(_BASE);
    }
    break;

  case ROFI_LOCATE_CLJ:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("J"))));
      layer_move(_BASE);
    }
    break;

  case ROFI_LOCATE_GLOBAL:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("*"))));
          layer_move(_BASE);
      }
      break;

  case ROFI_LOCATE:
      if (record->event.pressed) {
          rgblight_mode(DROP_CURRENT_ANIMATION);
          static_kinda_dim(HSV_PURPLE);
          rofi_locate_timer = timer_read();
          rofi_locate_timer_active = true;
          rofi_locate_level = 0;
          return false;
      } else {
      if (rofi_locate_level >= 4) {
        // rofi_locate_all (no filtered file extension)
        SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("*"))));
      } else if (rofi_locate_level >= 3) {
        // rofi_locate_all (no filtered file extension)
        SEND_STRING(SS_LALT(SS_RCTL("*")));

      } else if (rofi_locate_level >= 2) {
        // rofi_locate_all (no filtered file extension)
          SEND_STRING(SS_LALT(SS_RCTL("@")));
      } else {
        // filter with only files in base directory
        SEND_STRING(SS_LALT(SS_RCTL("&")));
      }
      rofi_locate_timer_active = false;
      rofi_locate_timer = 0;
    }
    rgblight_disable();
    layer_move(_BASE);
    break;

  case ROFI_LOCATE_SOURCE_FILES:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_RCTL("C"))));
      layer_move(_BASE);
    }
    break;


  case ROFI_LOCATE_WITH_FILTER:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_RCTL("&")));
      layer_move(_BASE);
    }
    break;

  case DELETE_LOCATE_DOCS_FILTER_DIR:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_RCTL("#")));
      layer_move(_BASE);
    }
    break;

  case ROFI_DRUN:
    if (record->event.pressed) {
      tap_code16(GUI(KC_SPACE));
      layer_move(_BASE);
    }
    break;

  case ROFI_EMOJI:
    if (record->event.pressed) {
      tap_code16(GUI(KC_5));
    }
    break;

  case WINDOWS_Q:
    if (record->event.pressed) {
      tap_code16(GUI(KC_Q));
      layer_off(_WINDOWS);
    }
    break;


    /* if (rofi_windows_osl_rofi_active) { */
    /*   printf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */
    /*   return true; */
    /* } */

    /* if (rofi_windows_osl_windows_active) { */
    /*   printf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */
    /*   rofi_windows_osl_windows_active = false; */
    /*   return true; */
    /* } */


    /* if (layer_state_is(_WINDOWS) ||	layer_state_is(_ROFI)) { */
    /* layer_move} */

  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  // i cant think of any use case where id want to keep these layers active after 1st key.
  // these layers are only used as OSLs
  if (layer_state_is(_WINDOWS) || layer_state_is(_ROFI)) {
    layer_move(_BASE);
  }
}
