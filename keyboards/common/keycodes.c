#include QMK_KEYBOARD_H
#include "user_song_list.c"
#include "version.h"
#include "muse.h"

#include "../../quantum/hacks.c"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum custom_keycodes {
                      /* RGB_SLD = SAFE_RANGE, */
                      /* RGB_SLD = EZ_SAFE_RANGE, */
                      FIRST = SAFE_RANGE,
                      LPRN_LIT,
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
                      EMACS_YAS_TF,
                      EMACS_YAS_TL,
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
};

#define max_buffer RALT(KC_ENTER)
#define close_x_window RCTL(RGUI(KC_Q))
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case RGBLIGHT_TOGGLE:
    rgblight_toggle();
    break;
  case RGBLIGHT_STEP:
    rgblight_step();
    break;
  case CYCLE_FAVE_ANIMATIONS:
    cycle_fave_animations();
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
      PLAY_SONG(zelda_puzzle);
      layer_move(_SYSTEM);
      return false;
    }
    break;

  case SYSTEM_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      /* PLAY_SONG(one_up_sound); */
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

  case EMACS_OTHER_WINDOW:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)  SS_RCTL(SS_TAP(X_W))  SS_RCTL(SS_TAP(X_W)));

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
  case EMACS_YAS_MAP_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESC) "imapa" macro_alt_slash);

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

    }
    break;

  case LAYER_LOWER_HOLD:
    if (record->event.pressed) {
      PLAY_SONG(minor_sound);
      /* PLAY_SONG(old_spice); */
      layer_move(_LOWER);

    }
    break;

  case LPRN_LIT :
    if (record->event.pressed) {
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_GREEN);
      SEND_STRING("(");
      rgblight_sethsv_noeeprom(HSV_WHITE);
      return true;
    }
    break;

  case LAYER_COLORS_HOLD:
    if (record->event.pressed) {
      layer_move(_COLORS);
      PLAY_SONG(num_lock_on_sound);

    }
    break;

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

  }


  return true;

}

/* bool echo = false; */
/* void toggle_echo(void) { */
/*   if (echo) { */
/*     echo = false; */
/*   } else { */
/*     echo = true; */
/*   } */
/* } */


char * int2str(uint8_t i) {
  static char s[10];
  itoa(i, s, 10);
  return s;


}

/* SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) */
/* SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_RALT(SS_TAP(X_M)) */
