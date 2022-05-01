#include QMK_KEYBOARD_H
#include "user_song_list.c"
#include "version.h"
#include "muse.h"

#include "../../quantum/hacks.c"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MO_HYPER MO(KC_LCTL)
#define CTRL_P RCTL(KC_P)
#define CTRL_L RCTL(KC_P)
#define HYPER_L LCTL(KC_L)
#define CTRL_SEMICOLON RCTL(KC_SCOLON)


bool do_echo = false;
void toggle_echo(void) {
  if (do_echo) {
    do_echo = false;
  } else {
    do_echo = true;
  }
}

char * int2str(uint8_t i) {
  static char s[10];
  itoa(i, s, 10);
  return s;
}


enum custom_keycodes {
                      /* RGB_SLD = SAFE_RANGE, */
                      /* RGB_SLD = EZ_SAFE_RANGE, */
                      FIRST = SAFE_RANGE,
                      CYCLE_DROP_COLORS,
                      TOGGLE_ECHO,
                      TOGGLE_BREATHING,
                      EMACS_ACE_WINDOW,
                      TERM_HOME,
                      LPRN_LIT,
                      CD_CSV,
                      EMACS_SEL_0,
                      EMACS_SEL_1,
                      EMACS_SEL_2,
                      EMACS_SEL_3,
                      EMACS_SEL_4,
                      EMACS_SEL_5,
                      EMACS_SEL_6,
                      EMACS_SEL_7,
                      EMACS_SEL_8,
                      EMACS_SEL_9,
                      TMUX_SPLIT_WINDOW,
                      CYCLE_FAVE_ANIMATIONS,
                      CYCLE_DROP_ANIMATIONS,
                      CYCLE_RGBLIGHT_STEP,
                      ALT_TAB,
                      EMACS_ACE_WINDOW_SWAP,
                      EMACS_BUFFER_REVERT,
                      EMACS_INSERT_GET_FEED,
                      EMACS_KILL_PROCESS,
                      EMACS_OTHER_WINDOW,
                      EMACS_WINDOW_CLOSE,
                      EMACS_COPY_FILE_PATH,
                      EMACS_YAS_C,
                      EMACS_YAS_DOC,
                      EMACS_YAS_MAP_ANON,
                      EMACS_YAS_FILTER_ANON,
                      EMACS_YAS_REMOVE_ANON,
                      EMACS_YAS_TF,
                      EMACS_YAS_TL,
                      EMACS_YAS_KEYS_DESCRUCTURE,
                      ESC_THEN_BASE_LAYER,
                      FISH_ACCEPT_SEND,
                      LAYER_LOWER_HOLD,
                      LAYER_COLORS_HOLD,
                      LAYER_RAISE_HOLD,
                      MUSIC_LAYER_ACTIVATE,
                      WINDOWS_LAYER_ACTIVATE,
                      SHIFTLOCK_LAYER_ACTIVATE,
                      SHIFTLOCK_LAYER_DEACTIVATE,
                      SYSTEM_LAYER_ACTIVATE,
                      SYSTEM_LAYER_DEACTIVATE,
                      RGBLIGHT_STEP,
                      RGBLIGHT_TOGGLE,
                      TMUX_COPY_MODE,
                      TMUX_CLOSE,
                      TERM_CD_UP_DIR
};

#define max_buffer RALT(KC_ENTER)
#define close_x_window RCTL(RGUI(KC_Q))
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

LEADER_EXTERNS();
void matrix_scan_user(void) {
  /* LEADER_DICTIONARY() { */
  /*   leading = false; */
  /*   leader_end(); */

  /*   SEQ_ONE_KEY(KC_F) { */
  /*     // Anything you can do in a macro. */
  /*     SEND_STRING("QMK is awesome."); */
  /*   } */
  /*   SEQ_TWO_KEYS(KC_D, KC_D) { */
  /*     SEND_STRING(SS_LCTL("a") SS_LCTL("c")); */
  /*   } */
  /*   SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
  /*     SEND_STRING("https://start.duckduckgo.com\n"); */
  /*   } */
  /*   SEQ_TWO_KEYS(KC_A, KC_S) { */
  /*     register_code(KC_LGUI); */
  /*     register_code(KC_S); */
  /*     unregister_code(KC_S); */
  /*     unregister_code(KC_LGUI); */
  /*   } */
  /* } */

  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 250) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }

}

int8_t m;
char b[3];
int i = 0;
const uint8_t fireworks = 42;
const uint8_t faves[7] = {fireworks, 15, 16, 17, 20, 22, 41};
void cycle_fave_animations(void) {
  i++;
  if (i >= 7) {
    i = 0;
  }
  rgblight_mode(faves[i]);
}

void apply_fave_animation(void) {
  rgblight_mode(faves[i]);
}

int DROP_LAYER_0_ANIMATION = RGBLIGHT_MODE_STATIC_LIGHT;
int DROP_LAYER_0_COLOR = 0;

void cycle_drop_animations(void) {
  i++;
  if (i >= 43) {
    i = 0;
  }
  DROP_LAYER_0_ANIMATION = i;
  rgblight_mode(DROP_LAYER_0_ANIMATION);
}

/* enum colors { */
/*              RGB_AZURE, */
/*              RGB_BLUE */
/* } */

void cycle_drop_color(void) {
  rgblight_increase_hue();
  /* DROP_LAYER_0_COLOR = colors[0]; */
  /* int step = 10; */
  /* DROP_LAYER_0_COLOR -= step; */
  /* if (DROP_LAYER_0_COLOR > 255) { */
  /*   DROP_LAYER_0_COLOR = 0; */
  /* } */
}

int k = 0;
void cycle_rgblight_step(void) {
  k++;
  if (k >= 42) {
    k = 0;
  }
  if (do_echo) {
    static char s[10];
    itoa(k, s, 10);
    SEND_STRING(s);
  }
  rgblight_mode(k);
}




bool do_breathing = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {


  case TOGGLE_BREATHING:
    if (do_breathing) {
      do_breathing = false;
    } else {
      do_breathing = true;
    }
    break;

  case TOGGLE_ECHO:
    toggle_echo();
    break;
  case RGBLIGHT_TOGGLE:
    rgblight_toggle();
    break;
  case RGBLIGHT_STEP:
    rgblight_step();
    break;

  case CYCLE_RGBLIGHT_STEP:
    PLAY_SONG(scroll_lock_on_sound);
    cycle_rgblight_step();
    /* static char s[10]; */
    /* itoa(k, s, 10); */
    /* SEND_STRING(s); */
    break;

  case CYCLE_FAVE_ANIMATIONS:
    cycle_fave_animations();
    break;

  case CYCLE_DROP_COLORS:
    cycle_drop_color();
    break;

  case CYCLE_DROP_ANIMATIONS:
    cycle_drop_animations();
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

  case SYSTEM_LAYER_ACTIVATE:
    if (record->event.pressed) {
      rgblight_enable();
      rgblight_enable_noeeprom();
      PLAY_SONG(scroll_lock_on_sound);
      layer_move(_SYSTEM);
      return false;
    }
    break;

  case SYSTEM_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      /* PLAY_SONG(one_up_sound); */
      PLAY_SONG(scroll_lock_off_sound);
      layer_move(_BASE);
      return false;
    }
    break;

  case SHIFTLOCK_LAYER_ACTIVATE:
    if (record->event.pressed) {
      /* rgblight_mode(42); */
      layer_move(_SHIFTLOCK);
      PLAY_SONG(caps_lock_on_sound);
      /* PLAY_SONG(coin_sound); */
      /* rgblight_mode(42); */
      /* return true; */
    }
    break;

  case SHIFTLOCK_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      layer_move(_BASE);
      PLAY_SONG(caps_lock_off_sound);
      /* return true; */
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
      SEND_STRING( SS_RCTL(SS_TAP(X_X))  SS_TAP(X_O));

    }
    break;
  case EMACS_BUFFER_REVERT:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C))  SS_TAP(X_R));

    }
    break;

  case FISH_ACCEPT_SEND:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_L)))   SS_TAP(X_ENTER));

    }
    break;

  case EMACS_YAS_DOC:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "idoc" macro_alt_slash);

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

  case EMACS_YAS_REMOVE_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "ira" macro_alt_slash);
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


  case EMACS_ACE_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(150) SS_RALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_RSFT(SS_TAP(X_W)));

    }
    break;

  case EMACS_ACE_WINDOW_SWAP:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_RSFT(SS_TAP(X_M)));

    }
    break;

  case EMACS_WINDOW_CLOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M))  SS_TAP(X_W)  SS_TAP(X_C));

    }
    break;

  case EMACS_KILL_PROCESS:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_RCTL(SS_TAP(X_B)));
    }
    break;

  case EMACS_INSERT_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING("(def xs (get-feed))");
    }
    break;

  case TMUX_COPY_MODE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_TAP(X_LBRACKET));
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
      PLAY_SONG(caps_lock_off_sound);
      SEND_STRING(SS_TAP(X_ESCAPE));
      layer_move(_BASE);

    }
    break;

  case LAYER_RAISE_HOLD:
    if (record->event.pressed) {
      PLAY_SONG(major_sound);
      layer_move(_RAISE);
      return false;

    }
    break;

  case LAYER_LOWER_HOLD:
    if (record->event.pressed) {
      PLAY_SONG(minor_sound);
      /* PLAY_SONG(old_spice); */
      layer_move(_LOWER);
      return false;

    }
    break;

  case LPRN_LIT :
    if (record->event.pressed) {
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_GREEN);
      SEND_STRING("(");
      rgblight_sethsv_noeeprom(HSV_BLACK);
      return true;
    }
    break;

    /* case LAYER_COLORS_HOLD: */
    /*   if (record->event.pressed) { */
    /*     layer_move(_COLORS); */
    /*     PLAY_SONG(num_lock_on_sound); */

    /*   } */
    /*   break; */

  case TMUX_SPLIT_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_V)) SS_TAP(X_MINUS));

    }
    break;

  case EMACS_SEL_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_0));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_1:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_1));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_2));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_3));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_4:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_4));
      layer_move(_BASE);
    }
    return true;
    break;

  case EMACS_SEL_5:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_5));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_6:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_6));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_7:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_7));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_8:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_8));
      layer_move(_BASE);
    }
    break;

  case EMACS_SEL_9:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) SS_TAP(X_9));
      layer_move(_BASE);
    }
    break;

  case EMACS_COPY_FILE_PATH:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LSFT(SS_RALT(SS_TAP(X_G))) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_F));
    }
    break;
  case CD_CSV:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_T)) SS_DELAY(100) "cdcsv" SS_TAP(X_ENTER));
    }
    break;
  }




  return true;

}


/* SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) */
/* SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) */
