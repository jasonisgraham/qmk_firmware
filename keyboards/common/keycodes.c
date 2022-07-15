#include QMK_KEYBOARD_H
#include "version.h"
/* #include "muse.h" */

#include "../../quantum/hacks.c"

/* #define LOWER MO(_LOWER) */
/* #define RAISE MO(_RAISE) */
#define MO_HYPER MO(KC_LCTL)
#define CTRL_P RCTL(KC_P)
#define CTRL_N RCTL(KC_N)
#define CTRL_L RCTL(KC_P)
#define HYPER_L LCTL(KC_L)
#define CTRL_SEMICOLON RCTL(KC_SCOLON)

#define EMACS_OTHER_WINDOW_NEXT RCTL(RALT(KC_PGUP))
#define EMACS_OTHER_WINDOW_PREV RCTL(RALT(KC_PGDOWN))
#define EMACS_NUMBER_INC LCTL(KC_PLUS)
#define EMACS_NUMBER_DEC LCTL(KC_UNDS)

#define BROWSER_TAB_NEXT KC_N//TD(DANCE_30)
#define BROWSER_TAB_PREV KC_P//TD(DANCE_29)


enum custom_keycodes {
                      FIRST = SAFE_RANGE,
                      ALT_TAB,
                      CLJ_ANON_FN,
                      CLJ_REGEX,
                      CLJ_SET,
                      CYCLE_DROP_ANIMATIONS,
                      CYCLE_DROP_COLORS,
                      EMACS_GOTO_GET_FEED,
                      EMACS_GOTO_SYNC_FEED,
                      EMACS_GOTO_PARSE_ITEM,
                      CD_CSV,
                      EMACS_ACE_WINDOW,
                      EMACS_ACE_WINDOW_SWAP,
                      EMACS_ANON_FN,
                      EMACS_BACKWARD_UP,
                      EMACS_BUFFER_REVERT,
                      EMACS_COMMENT_READER,
                      EMACS_COPY_FILE_PATH,
                      EMACS_EVIL_FIND,
                      EMACS_INSERT_GET_FEED,
                      EMACS_OTHER_WINDOW,
                      EMACS_PROJECTILE_FIND_FILE,
                      EMACS_RE_FIND,
                      EMACS_WINDOW_CLOSE,
                      EMACS_YANK_TO,
                      EMACS_YAS_C,
                      EMACS_YAS_DOC,
                      EMACS_YAS_FILTER_ANON,
                      EMACS_YAS_KEYS_DESCRUCTURE,
                      EMACS_YAS_MAP_ANON,
                      EMACS_YAS_REMOVE_ANON,
                      EMACS_YAS_TF,
                      EMACS_YAS_TL,
                      ESC_THEN_BASE_LAYER,
                      FISH_ACCEPT_SEND,
                      LAYER_COLORS_HOLD,
                      LAYER_LOWER_HOLD,
                      LAYER_MOUSE_HOLD,
                      LAYER_RAISE_HOLD,
                      SHIFTLOCK_LAYER_ACTIVATE,
                      SHIFTLOCK_LAYER_DEACTIVATE,
                      SYSTEM_LAYER_ACTIVATE,
                      SYSTEM_LAYER_DEACTIVATE,
                      TERM_CD_UP_DIR,
                      TERM_HOME,
                      TMUX_CLOSE,
                      TMUX_COPY_MODE,
                      TMUX_SPLIT_WINDOW,
};

#define max_buffer RALT(KC_ENTER)
#define close_x_window RCTL(RGUI(KC_Q))
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

/* #ifdef LEADER_ENABLE */
/* LEADER_EXTERNS(); */
/* #endif */

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 250) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }

}

/* #ifdef RGBLIGHT_ENABLE */

/* int8_t m; */
/* char b[3]; */
/* int i = 0; */
/* const uint8_t fireworks = 42; */
/* const uint8_t faves[7] = {fireworks, 15, 16, 17, 20, 22, 41}; */
/* /\* const uint8_t faves[7] = {fireworks, 15, 16, 17, 20, 22, 41}; *\/ */
/* void cycle_fave_animations(void) { */
/*   i++; */
/*   if (i >= 7) { */
/*     i = 0; */
/*   } */
/*   rgblight_mode(faves[i]); */
/* } */

/* void apply_fave_animation(void) { */
/*   rgblight_mode(faves[i]); */
/* } */

/* int DROP_LAYER_0_ANIMATION = 0;//RGBLIGHT_MODE_STATIC_LIGHT; */
/* int DROP_LAYER_0_COLOR = 0; */

/* /\* const uint8_t faves[7] = {2, // breathe *\/ */
/* /\*                           14, // rainbow *\/ */
/* /\*                           18, // snake *\/ */
/* /\*                           24, // xmas *\/ */
/* /\*                           29, // gradient *\/ */
/* /\*                           35, // test blinks *\/ */

/* /\* }; *\/ */
/* void cycle_drop_animations(void) { */
/*   i = i + 1; */
/*   if (i >= 42) { */
/*     i = 0; */
/*   } */

/*   DROP_LAYER_0_ANIMATION = i; */
/*   if (do_echo) { */
/*     static char s[10]; */
/*     itoa(i, s, 10); */
/*     SEND_STRING(""); */
/*     SEND_STRING(s); */
/*   } */
/*   rgblight_mode(DROP_LAYER_0_ANIMATION); */
/* } */

/* /\* enum colors { *\/ */
/* /\*              RGB_AZURE, *\/ */
/* /\*              RGB_BLUE *\/ */
/* /\* } *\/ */

/* void cycle_drop_color(void) { */
/*   rgblight_increase_hue(); */
/*   /\* DROP_LAYER_0_COLOR = colors[0]; *\/ */
/*   /\* int step = 10; *\/ */
/*   /\* DROP_LAYER_0_COLOR -= step; *\/ */
/*   /\* if (DROP_LAYER_0_COLOR > 255) { *\/ */
/*   /\*   DROP_LAYER_0_COLOR = 0; *\/ */
/*   /\* } *\/ */
/* } */

/* int k = 0; */
/* void cycle_rgblight_step(void) { */
/*   k++; */
/*   if (k >= 42) { */
/*     k = 0; */
/*   } */
/*   if (do_echo) { */
/*     static char s[10]; */
/*     itoa(k, s, 10); */
/*     SEND_STRING(s); */
/*   } */
/*   rgblight_mode(k); */
/* } */





/* bool do_breathing = false; */

/* #endif */

/* /\* #include "autocorrection.h" *\/ */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {

/*  case ALT_TAB: */
/*    if (record->event.pressed) { */
/*      if (!is_alt_tab_active) { */
/*        is_alt_tab_active = true; */
/*        register_code(KC_LGUI); */
/*      } */
/*      alt_tab_timer = timer_read(); */
/*      register_code(KC_TAB); */
/*    } else { */
/*      unregister_code(KC_TAB); */

/*    } */
/*    break; */

/*  case SYSTEM_LAYER_ACTIVATE: */
/*    if (record->event.pressed) { */
/*      layer_move(_SYSTEM); */
/*      return false; */
/*    } */
/*    break; */

/*  case SYSTEM_LAYER_DEACTIVATE: */
/*    if (record->event.pressed) { */
/*      layer_move(_BASE); */
/*      return false; */
/*    } */
/*    break; */

/*  case SHIFTLOCK_LAYER_ACTIVATE: */
/*    if (record->event.pressed) { */
/*      layer_move(_SHIFTLOCK); */
/* #ifdef AUDIO_ENABLE */
/*      PLAY_SONG(caps_lock_on_sound); */
/* #endif */
/*      return false; */
/*    } */
/*    break; */

/*  case SHIFTLOCK_LAYER_DEACTIVATE: */
/*    if (record->event.pressed) { */
/*      layer_move(_BASE); */
/* #ifdef AUDIO_ENABLE */
/*      PLAY_SONG(caps_lock_off_sound); */
/* #endif */
/*      /\* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); *\/ */

/*      /\* return true; *\/ */
/*    } */
/*    break; */

/*  /\* case TERM_CD_UP_DIR: *\/ */
/*  /\*   if (record->event.pressed) { *\/ */
/*  /\*     SEND_STRING("cd ../" SS_TAP(X_ENTER)); *\/ */
/*  /\*   } *\/ */
/*  /\*   break; *\/ */

/*  /\* case TERM_HOME: *\/ */
/*  /\*   if (record->event.pressed) { *\/ */
/*  /\*     SEND_STRING("~/"); *\/ */
/*  /\*   } *\/ */
/*  /\*   break; *\/ */

 case EMACS_OTHER_WINDOW:
   if (record->event.pressed) {
     SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(150) SS_RCTL(SS_TAP(X_X))  SS_TAP(X_O));
   }
   break;

 /* case EMACS_BUFFER_REVERT: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_RCTL(SS_TAP(X_C))  SS_TAP(X_R)); */
 /*   } */
 /*   break; */

 /* case FISH_ACCEPT_SEND: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_L)))   SS_TAP(X_ENTER)); */
 /*   } */
 /*   break; */

 /* case EMACS_YAS_DOC: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "idoc" macro_alt_slash); */
 /*   } */
 /*   break; */

 /* case EMACS_YAS_TF: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "itf" macro_alt_slash); */
 /*   } */
   /* break; */
 /* case EMACS_YAS_C: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "ic" macro_alt_slash); */
 /*   } */
 /*   break; */
 case EMACS_YAS_TL:
   if (record->event.pressed) {
     SEND_STRING(SS_TAP(X_ESC) "itl" macro_alt_slash);
   }
   break;

 /* case EMACS_YAS_REMOVE_ANON: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "ira" macro_alt_slash); */
 /*   } */
 /*   break; */

 /* case EMACS_YAS_FILTER_ANON: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "ifa" macro_alt_slash); */
 /*   } */
 /*   break; */

 /* case EMACS_YAS_MAP_ANON: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "imapa" macro_alt_slash); */
 /*   } */
 /*   break; */

 case EMACS_YAS_KEYS_DESCRUCTURE:
   if (record->event.pressed) {
     SEND_STRING(SS_TAP(X_ESC) "ikd" macro_alt_slash);
   }
   break;

 /* case EMACS_COMMENT_READER: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "i#_"); */
 /*   } */
 /*   break; */

 case CLJ_REGEX:
   if (record->event.pressed) {
     SEND_STRING(SS_TAP(X_ESC) "irx" macro_alt_slash);
   }
   break;


 case EMACS_BACKWARD_UP:
   if (record->event.pressed) {
     SEND_STRING(SS_TAP(X_ESC) "99" SS_RALT(SS_RCTL(SS_TAP(X_U))));
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

   /* case EMACS_YANK_TO: */
   /*   if (record->event.pressed) { */
   /*     SEND_STRING(SS_TAP(X_ESC) "yt"); */
   /*   } */
   /*   break; */


   /* case EMACS_EVIL_FIND: */
   /*   if (record->event.pressed) { */
   /*     SEND_STRING(SS_TAP(X_ESC) "f"); */
   /*   } */
   /*   break; */


   /* case EMACS_PROJECTILE_FIND_FILE: */
   /*   if (record->event.pressed) { */
   /*     SEND_STRING(SS_LALT(SS_TAP(X_M)) "pf"); */
   /*   } */
   /*   break; */

 case EMACS_RE_FIND:
   if (record->event.pressed) {
     SEND_STRING(SS_TAP(X_ESC) "irf" macro_alt_slash);
   }
   break;
 /* case EMACS_INSERT_GET_FEED: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING("(def xs (get-feed))"); */
 /*   } */
 /*   break; */

 /* case TMUX_COPY_MODE: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_TAP(X_LBRACKET)); */
 /*   } */
 /*   break; */

/*  case LAYER_RAISE_HOLD: */
/*    if (record->event.pressed) { */
/* #ifdef AUDIO_ENABLE */
/*      PLAY_SONG(major_sound); */
/* #endif */
/*      layer_move(_RAISE); */
/* #ifdef RGBLIGHT_MODE */
/*      rgblight_mode(18); */
/*      rgblight_enable_noeeprom(); */
/*      rgblight_sethsv_noeeprom(HSV_BLUE); */
/* #endif */

/*      return false; */

/*    } */
/*    break; */

/*  case LAYER_LOWER_HOLD: */
/*    if (record->event.pressed) { */
/* #ifdef AUDIO_ENABLE */
/*      PLAY_SONG(minor_sound); */
/* #endif */
/*      layer_move(_LOWER); */

/* #ifdef RGBLIGHT_MODE */
/*      /\* rgblight_mode(RGBLIGHT_MODE_SNAKE); *\/ */
/*      rgblight_mode(18); */
/*      rgblight_enable_noeeprom(); */
/*      rgblight_sethsv_noeeprom(HSV_PURPLE); */
/* #endif */

/*      return false; */

/*    } */
/*    break; */

/*  case LAYER_MOUSE_HOLD: */
/*    if (record->event.pressed) { */
/*      /\* PLAY_SONG(minor_sound); *\/ */
/*      layer_move(_MOUSE); */

/* #ifdef RGBLIGHT_MODE */
/*      rgblight_mode(18); */
/*      rgblight_enable_noeeprom(); */
/*      rgblight_sethsv_noeeprom(HSV_GREEN); */
/* #endif */

/*      return false; */

/*    } */
/*    break; */

 /* case TMUX_SPLIT_WINDOW: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_RCTL(SS_TAP(X_V)) SS_TAP(X_MINUS)); */

 /*   } */
   /*   break; */


        // commented below
 /* case EMACS_COPY_FILE_PATH: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_RGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LSFT(SS_RALT(SS_TAP(X_G))) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_F)); */
 /*   } */
 /*   break; */

 /* case EMACS_GOTO_PARSE_ITEM: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "parse-item" SS_DELAY(500) SS_TAP(X_ENTER)); */
 /*   } */
 /*   break; */


 /* case EMACS_GOTO_GET_FEED: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "get-feed" SS_DELAY(500) SS_TAP(X_ENTER)); */
 /*   } */
 /*   break; */

 /* case EMACS_GOTO_SYNC_FEED: */
 /*   if (record->event.pressed) { */
 /*     SEND_STRING(SS_TAP(X_ESC) "go" SS_DELAY(250) "sync-feed" SS_DELAY(500) SS_TAP(X_ENTER)); */
 /*   } */
 /*   break; */

 default:
   return true;
 }




return true;

}
