#include QMK_KEYBOARD_H
#include "user_song_list.c"
#include "version.h"
/* #include "muse.h" */

/* #include "musical_notes.h" */
#include "layer_lock.h"
#include "../../quantum/hacks.c"

#define EMACS_FASD_DEFAULT RCTL(KC_ASTR)
#define EMACS_FASD_GLOBAL_NO_EXT KC_F12
#define EMACS_FASD_PROJECT_NO_EXT LCTL(KC_F12)
#define EMACS_FASD_PROJECT_CURR_EXT RCTL(KC_F12)

#define WINDOW_ALWAYS_ON_TOP LCTL(LSFT(LGUI(RCTL(KC_UP))))
#define WINDOW_TOGGLE_HORIZONTAL_MAX LSFT(LGUI(RCTL(KC_MINUS)))

#define winmove_mon_up LGUI(LSFT(KC_UP))
#define winmove_mon_left LGUI(LSFT(KC_LEFT))
#define winmove_mon_right LGUI(LSFT(KC_RIGHT))
#define winmove_mon_down LGUI(LSFT(KC_DOWN))

#define winmove_tile_up LGUI(LSFT(KC_K))
#define winmove_tile_left LGUI(LSFT(KC_H))
#define winmove_tile_right LGUI(LSFT(KC_L))
#define winmove_tile_down LGUI(LSFT(KC_J))

#define editing_q TD(DANCE_EDITING_Q)
#define editing_j LALT(LSFT(KC_J))
#define editing_k LALT(LSFT(KC_K))
#define editing_l LALT(LSFT(KC_L))
#define EMACS_LOCCUR LCTL(RCTL(LGUI(LALT(KC_O))))
#define BROWSER_TAB_NEXT TD(DANCE_30)
#define BROWSER_TAB_PREV TD(DANCE_29)
#define CTRL_L RCTL(KC_P)
#define CTRL_N RCTL(KC_N)
#define ALT_N LALT(KC_N)
#define CTRL_P RCTL(KC_P)
#define ALT_P LALT(KC_P)
#define CTRL_SEMICOLON RCTL(KC_SCOLON)
/* H-M-s-d */
#define EMACS_KILL_IN_SEXP LCTL(LALT(LGUI(KC_D)))
#define EMACS_YANK_IN_SEXP LCTL(LALT(LGUI(KC_I)))
#define EMACS_NUMBER_DEC LCTL(KC_UNDS)
#define EMACS_NUMBER_INC LCTL(KC_PLUS)
#define EMACS_OTHER_WINDOW_NEXT RCTL(LALT(KC_PGUP))
#define EMACS_OTHER_WINDOW_PREV RCTL(LALT(KC_PGDOWN))
#define HYPER_L LCTL(KC_L)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define RAISE MO(_RAISE)
#define all_mods LM(_ALL_MODS, MOD_LGUI | MOD_LCTL | MOD_LALT | MOD_RCTL | MOD_LSFT)
/* #define all_mods TD (DANCE_ALL_MODS) */
#define alt TD(DANCE_ALT)
#define alt_tab ALT_TAB
#define backspace KC_BSPACE
#define lower_backspace TD(WWW_BACK_FORWARD)
#define raise_backspace KC_DEL
#define below_b KC_LALT
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_n KC_LALT
#define below_v MT(MOD_RCTL, KC_ESCAPE)
#define emacs_a _______
#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_m EMACS_YAS_MAP_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
/* #define hyper LM(_HYPER, MOD_LCTL) //KC_LCTL // OSL(_WINDOWS) */
#define hyper TD(DANCE_HYPER)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(LALT(KC_LSFT))
#define key_4_11 KC_DOWN //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_UP
#define key_left KC_LEFT
#define key_right KC_RIGHT
#define lm_ctrl LM(_CTRL, MOD_RCTL)
#define lower_LOWER TO(_BASE)
#define lower_key_4_11 KC_MINUS
#define lower_key_4_12 KC_PLUS
#define lower_right_of_lower KC_DELETE
#define macro_alt_slash SS_LALT(SS_TAP(X_SLASH))
#define my_0 KC_0
#define my_1 KC_1
#define my_2 KC_2
#define my_3 KC_3
#define my_4 KC_4
#define my_5 KC_5
#define my_6 KC_6
#define my_7 KC_7
#define my_8 KC_8
#define my_9 KC_9
#define my_a TD(DANCE_A)
#define my_b KC_B
#define my_c TD(DANCE_C)
#define my_cap_h LSFT(KC_H)
#define my_cap_h LSFT(KC_H)
#define my_cap_i LSFT(KC_I)
#define my_cap_j LSFT(KC_J)
#define my_cap_k LSFT(KC_K)
#define my_cap_l LSFT(KC_L)
#define my_cap_m LSFT(KC_M)
#define my_cap_o LSFT(KC_O)
#define my_cap_p LSFT(KC_P)
#define my_comma TD(DANCE_COMMA) //KC_COMMA //
#define my_d TD(DANCE_D)
#define my_e TD(DANCE_E)
#define my_f TD(DANCE_F)
#define my_forward_slash TD(DANCE_25)
#define my_g TD(DANCE_G)
#define my_grave TD(DANCE_TAB)
#define my_h TD(DANCE_H)
#define my_i TD(DANCE_I)
#define my_j TD(DANCE_J)
#define my_k TD(DANCE_K)
#define my_l TD(DANCE_L)
#define my_lctl  MT(MOD_RCTL, KC_ESCAPE)
#define esc_ctrl my_lctl
#define my_left_shift TD(DANCE_SHIFT)
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_bs KC_DEL
#define my_lower_comma BROWSER_TAB_PREV
#define my_lower_comma BROWSER_TAB_PREV
#define my_lower_d KC_F7
#define my_lower_f  KC_F8
#define my_lower_g KC_DELETE
#define my_lower_i KC_PGUP
#define my_lower_h KC_LEFT
#define my_lower_j KC_DOWN
#define my_lower_k KC_UP
#define my_lower_l DANCE_RIGHT_OR_END
#define my_lower_m _______
#define my_lower_n _______
#define my_lower_o KC_END
#define my_lower_p KC_BSPACE
/* #define my_lower_p KC_MINUS */
#define my_lower_period BROWSER_TAB_NEXT
#define my_lower_r KC_F4
#define my_lower_semi KC_QUOTE
#define my_lower_slash KC_ENTER
#define my_lower_u KC_PGDOWN
#define my_m TD(DANCE_M)
#define my_minus _______
#define my_n TD(DANCE_N)
#define my_o TD(DANCE_O)
#define my_p TD(DANCE_P)
#define my_period TD(DANCE_DOT)
#define my_q TD(DANCE_Q)
#define my_r TD(DANCE_R)
#define my_raise RAISE
#define my_raise_comma KC_2
#define my_raise_d KC_RIGHT
#define my_raise_a KC_LEFT
#define my_raise_s KC_DOWN
#define my_raise_w KC_UP
#define my_raise_f LALT(KC_ENTER)
#define my_raise_h KC_MINUS
#define my_raise_i KC_8
#define my_raise_j KC_4
#define my_raise_k KC_5
#define my_raise_l KC_6
#define my_raise_m KC_1
#define my_raise_n KC_UNDS
#define my_raise_o KC_9
#define my_raise_p KC_0
#define my_raise_period KC_3
#define my_raise_top_right KC_DEL // TD(WWW_BACK_FORWARD)
#define my_raise_u  KC_7
#define my_raise_y  KC_PLUS
#define my_right_of_lower MO(_EDITING)
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define my_s TD(DANCE_S)
#define my_semicolon KC_SCOLON
#define my_singlequote KC_QUOTE
#define my_space TD(DANCE_SPACE)
#define my_t TD(DANCE_T)
#define my_u TD(DANCE_U)
#define my_v KC_V
#define my_w TD(DANCE_W)
#define my_x TD(DANCE_X)
#define my_y TD(DANCE_Y)
#define my_z TD(DANCE_Z)
#define next_win_or_frame LALT(LSFT(KC_N))
#define prev_win_or_frame LALT(LSFT(KC_P))
#define raise_space KC_UNDS
#define raise_key_4_9 KC_ENTER // KC_BSPC
#define raise_semi  KC_QUOTE
#define raise_slash KC_MINUS
#define right_of_lower  esc_ctrl  // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define lower_right_of_super CLOSED_PAREN
#define scroll_next RCTL(KC_D)
#define scroll_prev RCTL(KC_U)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_F3)))
#define super LM(_SUPER, MOD_LGUI) //TD(SUPER_WINDOWS)
/* #define super TD(DANCE_SUPER) //TD(SUPER_WINDOWS) */

#define adhoc_set_hotkey LM(_ADHOC_SET_HOTKEY, MOD_LGUI | MOD_LCTL | MOD_LALT)
/* #define adhoc_set_hotkey TD(DANCE_ADHOC_SET_HOTKEY) */
#define super_meta_hyper adhoc_set_hotkey
#define top_left TD(DANCE_TAB)
#define topright _______
#define windows_k TD(DANCE_43)
#define windows_l TD(DANCE_44)
#define emacs_buffer_stack_down LCTL(LALT(KC_H))
#define emacs_buffer_stack_up LCTL(LALT(KC_L))

#define EMACS_SELECT_WINDOW SS_LGUI(SS_TAP(X_E)) SS_DELAY(150)
#define EMACS_SCROLL_DOWN RCTL(LGUI(KC_Y))
#define EMACS_SCROLL_UP RCTL(KC_Y)


#define top_alpha_mid_column LAYER_LOCK


#define KEYBOARD_LAYOUT_HOLD_KEY KC_RGUI


#define BRACKET_PAREN TD(DANCE_PAREN_BRACKET)

enum col7_row4_fns {
                    K74_MO_LEVEL3 = SAFE_RANGE,
                    K74_MO_APL
};

static int active_k74_fn = K74_MO_LEVEL3;

void cycle_active_k74_fn(void) {
  dprintf("active_k74_fn: %u", active_k74_fn);

  switch (active_k74_fn) {
  case K74_MO_LEVEL3:
    active_k74_fn = K74_MO_APL;
    break;
  case K74_MO_APL:
    active_k74_fn = K74_MO_LEVEL3;
    break;
    dprintf("active_k74_fn: %u", active_k74_fn);
  }
}
  ;

static bool do_echo = false;
void toggle_echo(void) {
  if (do_echo) {
    do_echo = false;
  } else {
    SEND_STRING("echo on");
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
                      ALT,
                      EMACS_NEXT_SEXP,
                      CYCLE_ACTIVE_K74_FN,
                      level3,
                      key_4_7,
                      EMACS_PREV_SEXP,
                      AUTOSHIFT_TOGGLE,
                      WEB_SAVE_FILE_UNDER_CURSOR,
                      CAPS_WORD_TOGGLE,
                      TEMP_TEXT,
                      BACKWARD_KILL_LINE,
                      EMACS_TRANSPOSE,
                      OPEN_PAREN,
                      CLOSED_PAREN,
                      LAYER_LOCK,
                      CIDER_RUN_PREV_COMMAND,
                      EMACS_DESC_KEY,
                      EMACS_FINDER_COMMENTARY,
                      EMACS_HELM_OCCUR,
                      EMACS_HELM_MARK_RINGS,
                      EMACS_INSIDE_YANK,
                      EMACS_INSIDE_DELETE,
                      EMACS_TO_YANK,
                      EMACS_TO_DELETE,
                      EMACS_EVIL_FIND,
                      EMACS_PROJECTILE_FIND_FILE,
                      EMACS_FASD,
                      EMACS_RE_FIND,
                      EMACS_BACKWARD_UP,
                      RESET_ANIMATION,
                      GAUTH_LAYER_ACTIVATE,
                      EMACS_COMMENT_READER,
                      EMACS_PRIVATE_READER,
                      EMACS_ANON_FN,
                      CLJ_REGEX,
                      CLJ_ANON_FN,
                      CLJ_SET,
                      EMACS_YANK_TO,
                      gauth_fb,
                      gauth_gh,
                      gauth_plex,
                      gauth_hb,
                      gauth_lp,
                      AUDIO_LAYER_HOLD,
                      CYCLE_DROP_COLORS,
                      EMACS_GOTO_REMOTEID,
                      EMACS_GOTO_GET_FEED,
                      EMACS_GOTO_SYNC_FEED,
                      EMACS_GOTO_PARSE_ITEM,
                      EMACS_GOTO_ROLLUP,
                      TOGGLE_ECHO,
                      TOGGLE_BREATHING,
                      EMACS_ACE_WINDOW,
                      TERM_HOME,
                      CD_CSV,
                      EMACS_SEL_0,
                      EMACS_SEL_1,
                      EMACS_SEL_2,
                      EMACS_SEL_3,
                      EMACS_SEL_4,
                      EMACS_SEL_5,
                      EMACS_SEL_6,
                      LAYER_MOUSE_HOLD,
                      EMACS_SEL_7,
                      EMACS_SEL_8,
                      EMACS_SEL_9,
                      TMUX_SPLIT_WINDOW,
                      EMACS_SPLIT_WINDOW_UP,
                      EMACS_SPLIT_WINDOW_DOWN,
                      EMACS_SPLIT_WINDOW_RIGHT,
                      EMACS_SPLIT_WINDOW_LEFT,
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
                      EMACS_FRAME_FULL_SCREEN,
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
                      TERM_CD_UP_DIR,
                      CLEAR_THAT_REPL,
                      EMACS_WRAP_IN_THREAD_LAST,
                      THREAD_LAST,
                      SA_LAYER_ACTIVATE,
                      THREAD_FIRST,

  APL_DIAMOND,
  APL_QUAD_DIAMOND,
  APL_DIAERESIS,
  APL_IBEAM,
  APL_MACRON,
  APL_DEL_TILDE,
  APL_LESS,
  APL_DEL_STILE,
  APL_LESS_EQUAL,
  APL_DELTA_STILE,
  APL_EQUALS,
  APL_CIRCLE_STILE,
  APL_GREATER_EQUAL,
  APL_CIRCLE_BACKSLASH,
  APL_GREATER,
  APL_CIRCLED_MINUS,
  APL_NOT_EQUAL,
  APL_CIRCLE_STAR,
  APL_OR,
  APL_DOWN_CARET_TILDE,
  APL_AND,
  APL_UP_CARET_TILDE,
  APL_MULT,
  APL_EXCL,
  APL_DIVISION,
  APL_QUAD_DIVIDE,
  APL_QUESTION_MARK,
  APL_OMEGA,
  APL_OMEGA_UNDERBAR,
  APL_EPSILON,
  APL_SMALL_ELEMENT,
  APL_EPSILON_UNDERBAR,
  APL_RHO,
  APL_TILDE,
  APL_TILDE_DIAERESIS,
  APL_UPWARDS_ARROW,
  APL_DOWNWARDS_ARROW,
  APL_IOTA,
  APL_IOTA_UNDERBAR,
  APL_WHITE_CIRCLE,
  APL_CIRCLE_DIAERESIS,
  APL_STAR_OPERATOR,
  APL_STAR_DIAERESIS,
  APL_LEFT_ARROW,
  APL_QUOTE_QUAD,
  APL_RIGHT_ARROW,
  APL_ZILDE,
  APL_ALPHA,
  APL_ALPHA_UNDERBAR,
  APL_LEFT_CEILING,
  APL_LEFT_FLOOR,
  APL_LOW_LINE,
  APL_NABLA,
  APL_INCREMENT,
  APL_DELTA_UNDERBAR,
  APL_RING_OPERATOR,
  APL_JOT_DIAERESIS,
  APL_APOSTROPHE,
  APL_QUAD_EQUAL,
  APL_QUAD,
  APL_SQUISH_QUAD,
  APL_DOWN_TACK_JOT,
  APL_IDENTICAL,
  APL_UP_TACK_JOT,
  APL_NOT_IDENTICAL,
  APL_RIGHT_TACK,
  APL_LEFT_TACK,
  APL_SUBSET,
  APL_SUPERSET,
  APL_CHI,
  APL_INTERSECTION,
  APL_UNION,
  APL_UP_TACK,
  APL_DOWN_TACK,
  APL_VERTICAL_LINE,
  APL_UP_SHOE_JOT,
  APL_COMMA_BAR,
  APL_BACKSLASH_BAR,
  APL_SLASH_BAR,
  APL_QUAD_COLON,

};

#define max_buffer LALT(KC_ENTER)
#define close_x_window RCTL(LGUI(KC_Q))
#define macro_alt_slash SS_LALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const int timer_default = 400;

bool fasd_timer_active = false;
uint16_t fasd_timer = 0;
int fasd_level = 0;
int fasd_level_duration = timer_default;

bool open_paren_timer_active = false;
uint16_t open_paren_timer = 0;
int open_paren_level = 0;
int open_paren_level_duration = timer_default;

bool closed_paren_timer_active = false;
uint16_t closed_paren_timer = 0;
int closed_paren_level = 0;
int closed_paren_level_duration = timer_default;

void matrix_scan_user(void) {
  // open paren
  if (open_paren_timer_active) {
    if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 2)) {
      // global no ext
      if (open_paren_level <= 2) {
        open_paren_level++;
        PLAY_SONG(__a6);
      }

    } else if (timer_elapsed(open_paren_timer) > (open_paren_level_duration * 1)) {
      if (open_paren_level <= 1) {
        open_paren_level++;
        PLAY_SONG(__g6);
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
        PLAY_SONG(__a6);
      }

    } else if (timer_elapsed(closed_paren_timer) > (closed_paren_level_duration * 1)) {
      if (closed_paren_level <= 1) {
        closed_paren_level++;
        PLAY_SONG(__g6);
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
        PLAY_SONG(__as6);
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 2)) {
      // global no ext
      if (fasd_level <= 2) {
        fasd_level++;
        PLAY_SONG(__a6);
      }

    } else if (timer_elapsed(fasd_timer) > (fasd_level_duration * 1)) {
      if (fasd_level <= 1) {
        fasd_level++;
        PLAY_SONG(__g6);
      }

    } else {
      if (fasd_level <= 0) {
        // project level current ext
        fasd_level++;
        /* PLAY_SONG(__e6); */
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

#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#endif

#ifdef RGBLIGHT_ENABLE

int8_t m;
char b[3];
int i = 0;
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

/* int DROP_DEFAULT_ANIMATION = 0;//RGBLIGHT_MODE_STATIC_LIGHT; */
int DROP_LAYER_0_COLOR = 0;

const uint8_t faves[7] = {1, // static
                          2, // breathe
                          14, // rainbow
                          18, // snake
                          24, // xmas
                          29, // gradient
                          35, // test blinks
};

void cycle_drop_animations(void) {
  i = i + 1;
  if (i >= 42) {
    i = 0;
  }

  DROP_DEFAULT_ANIMATION = faves[i];
  /* dprintf("idx: %u, drop animation: %u\n", i, DROP_DEFAULT_ANIMATION); */
  rgblight_mode(DROP_DEFAULT_ANIMATION);
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

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */

  if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }

  if (!process_layer_lock(keycode, record, LAYER_LOCK)) {
    if (biton32(layer_state) != _BASE) {
#ifdef RGBLIGHT_MODE
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
#endif


/* #ifdef AUDIO_ENABLE */
/*     PLAY_SONG(caps_lock_on_sound); */
/* #endif */
    }
    return false;
  }

  switch (keycode) {


  case level3:
    if (record->event.pressed) {
      rgblight_enable_noeeprom();
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      rgblight_sethsv_noeeprom(HSV_PINK);
      register_code16(KC_KP_ENTER);
    } else {
      unregister_code16(KC_KP_ENTER);
      rgblight_disable();

    }

    break;


  case key_4_7:
    printf("active_k74_fn: %u, pressed: %u\n", active_k74_fn, record->event.pressed);
    if (record->event.pressed) {
      switch (active_k74_fn) {
      case K74_MO_LEVEL3:
        rgblight_enable_noeeprom();
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_noeeprom(HSV_PINK);
        register_code16(KC_KP_ENTER);
        break;
      case K74_MO_APL:
        rgblight_mode(RGBLIGHT_MODE_SNAKE);
        rgblight_sethsv_noeeprom(HSV_WHITE);
        register_code16(KEYBOARD_LAYOUT_HOLD_KEY);
        break;
      }
    } else {
      unregister_code16(KC_KP_ENTER);
      unregister_code16(KEYBOARD_LAYOUT_HOLD_KEY);
      rgblight_disable();
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
        tap_code16(KC_LBRACKET);
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
        tap_code16(KC_RBRACKET);
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


#ifdef RGBLIGHT_ENABLE
  case TOGGLE_BREATHING:
    if (record->event.pressed) {
      if (do_breathing) {
        do_breathing = false;
      } else {
        do_breathing = true;
      }
    }
    break;


  case RGBLIGHT_TOGGLE:
    if (record->event.pressed) {
      rgblight_toggle();
    }
    break;

  case RESET_ANIMATION:
    if (record->event.pressed) {
      DROP_DEFAULT_ANIMATION = 0;
      rgblight_mode(DROP_DEFAULT_ANIMATION);
    }
    break;

  case RGBLIGHT_STEP:
    if (record->event.pressed) {
      rgblight_step();
    }
    break;

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
/* #ifdef AUDIO_ENABLE */
      PLAY_SONG(mario_mushroom);
/* #endif */
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
      PLAY_SONG(zelda_treasure);
#ifdef RGBLIGHT_MODE
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif

      return false;
    }
    break;



  case SYSTEM_LAYER_ACTIVATE:
    if (record->event.pressed) {
      layer_move(_SYSTEM);
      PLAY_SONG(scroll_lock_on_sound);
#ifdef RGBLIGHT_MODE
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif

      return false;
    }
    break;

  case SYSTEM_LAYER_DEACTIVATE:
    if (record->event.pressed) {
      PLAY_SONG(one_up_sound);
      PLAY_SONG(scroll_lock_off_sound);
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
      /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */
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
      /* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); */

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
    /* if (record->event.pressed) { */
    /*   caps_word_on(); */
    /*   PLAY_SONG(caps_lock_on_sound); */
    /* } */
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
      /* rgblight_mode(RGBLIGHT_MODE_SNAKE); */
#ifdef RGBLIGHT_MODE
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
      /* PLAY_SONG(minor_sound); */
      PLAY_SONG(caps_lock_on_sound);
#endif
      layer_move(_LOWER);

#ifdef RGBLIGHT_MODE
      /* rgblight_mode(RGBLIGHT_MODE_SNAKE); */
      rgblight_mode(RGB_MODE_RAINBOW);
      /* rgblight_mode(18); */
      rgblight_mode(RGBLIGHT_MODE_SNAKE);
      /* rgblight_sethsv_noeeprom(HSV_PURPLE); */

#endif
      return false;

    }
    break;

  case LAYER_MOUSE_HOLD:
    if (record->event.pressed) {
      /* PLAY_SONG(minor_sound); */
      layer_move(_MOUSE);

#ifdef RGBLIGHT_MODE
      /* rgblight_mode(RGBLIGHT_MODE_SNAKE); */
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
    /*     PLAY_SONG(num_lock_on_sound); */

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


/* SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) */
/* SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) */

#define right_of_super MO(_APL)  // X(BANG) // esc_ctrl //  BRACKET_PAREN //all_mods
