LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(my_p, my_p) {
      SEND_STRING("jasonisgraham@gmail.com");
    }

    SEQ_TWO_KEYS(my_p, my_w) {
      SEND_STRING("jason.graham@stylitics.com");
    }

      SEQ_THREE_KEYS(my_w, my_t, my_p) {
        SEND_STRING(SS_LGUI("w") SS_DELAY(100) SS_RCTL("t")  SS_DELAY(100) SS_RCTL("l")  SS_DELAY(100) SS_RCTL("v") SS_DELAY(100));
        tap_code16(KC_ENTER);
    }

      SEQ_TWO_KEYS(my_w, my_t) {
        SEND_STRING(SS_LGUI("w") SS_DELAY(100) SS_RCTL("t")  SS_DELAY(100) SS_RCTL("l"));
      }

      SEQ_TWO_KEYS(my_s, my_c) {
        SEND_STRING("ssh cronjobs-prod" SS_TAP(X_ENTER) SS_DELAY(1500));
        SEND_STRING("su app " SS_TAP(X_ENTER) SS_DELAY(250) "cd " SS_TAP(X_ENTER) "cd collage" SS_TAP(X_ENTER));
        SEND_STRING("source production_env_vars" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(my_s, my_p) {
        SEND_STRING("ssh prod" SS_TAP(X_ENTER) SS_DELAY(1500));
        SEND_STRING("su app " SS_TAP(X_ENTER) SS_DELAY(250) "cd " SS_TAP(X_ENTER) "cd collage" SS_TAP(X_ENTER));
        SEND_STRING("source production_env_vars" SS_TAP(X_ENTER));
          }



    /* SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
    /*   SEND_STRING("https://start.duckduckgo.com\n"); */
    /* } */
    /* SEQ_TWO_KEYS(KC_A, KC_S) { */
    /*   register_code(KC_LGUI); */
    /*   register_code(KC_S); */
    /*   unregister_code(KC_S); */
    /*   unregister_code(KC_LGUI); */
    /* } */
    /* return; */
  }

  // open paren
  if (open_paren_timer_active) {
    if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 2)) {
      // global no ext
      if (open_paren_level <= 2) {
        open_paren_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__a6);
#endif
      }

    } else if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 1)) {
      if (open_paren_level <= 1) {
        open_paren_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__g6);
#endif
      }

    } else {
      if (open_paren_level <= 0) {
        open_paren_level++;
      }
    }
    return;
  }


  // closed paren
  if (closed_paren_timer_active) {
    if (timer_elapsed(closed_paren_timer) > (closed_paren_level_duration * 2)) {
      // global no ext
      if (closed_paren_level <= 2) {
        closed_paren_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__a6);
#endif
      }

    } else if (timer_elapsed(closed_paren_timer) > (closed_paren_level_duration * 1)) {
      if (closed_paren_level <= 1) {
        closed_paren_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__g6);
#endif
      }

    } else {
      if (closed_paren_level <= 0) {
        closed_paren_level++;
      }
    }
    return;
  }

  // fasd
  if (fasd_timer_active) {
    if (timer_elapsed(fasd_timer) > (fasd_level_duration * 3)) {
      if (fasd_level <= 3) {
        fasd_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__as6);
#endif
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 2)) {
      // global no ext
      if (fasd_level <= 2) {
        fasd_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__a6);
#endif
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 1)) {
      if (fasd_level <= 1) {
        fasd_level++;
#ifdef AUDIO_ENABLE
        PLAY_SONG(__g6);
#endif
      }

    } else {
      if (fasd_level <= 0) {
        // project level current ext
        fasd_level++;
#ifdef AUDIO_ENABLE
        /* PLAY_SONG(__e6); */
#endif
      }
    }
    return;
  }

  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 250) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }

}
