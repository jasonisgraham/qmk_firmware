


void matrix_scan_user(void) {

  // open paren
  if (open_paren_timer_active) {
    if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 2)) {
      // global no ext
      if (open_paren_level <= 2) {
        open_paren_level++;
      }

    } else if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 1)) {
      if (open_paren_level <= 1) {
        open_paren_level++;
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
      }

    } else if (timer_elapsed(closed_paren_timer) > (closed_paren_level_duration * 1)) {
      if (closed_paren_level <= 1) {
        closed_paren_level++;
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
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 2)) {
      // global no ext
      if (fasd_level <= 2) {
        fasd_level++;
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 1)) {
      if (fasd_level <= 1) {
        fasd_level++;
      }

    } else {
      if (fasd_level <= 0) {
        // project level current ext
        fasd_level++;
      }
    }
    return;
  }

  // rofi_locate
  if (rofi_locate_timer_active) {
    if (timer_elapsed(rofi_locate_timer) > (rofi_locate_level_duration * 3)) {
      if (rofi_locate_level <= 3) {
        rofi_locate_level++;
        rgblight_sethsv_noeeprom(HSV_BLUE);
        rgblight_mode(18);
      }
    } else if (timer_elapsed(rofi_locate_timer) > (rofi_locate_level_duration * 2)) {
      if (rofi_locate_level <= 2) {
        rgblight_sethsv_noeeprom(HSV_WHITE);
        rofi_locate_level++;
      }

    } else if (timer_elapsed(rofi_locate_timer) > (rofi_locate_level_duration * 1)) {
      if (rofi_locate_level <= 1) {
        rofi_locate_level++;
        rgblight_sethsv_noeeprom(HSV_RED);
      }

    } else {
      if (rofi_locate_level <= 0) {
        rofi_locate_level++;
      }
    }
    return;
  }


  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
