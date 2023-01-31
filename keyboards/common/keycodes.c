/* #include QMK_KEYBOARD_H */
#include "user_song_list.c"
/* #include "version.h" */
/* /\* #include "musical_notes.h" *\/ */
/* #include "../../quantum/hacks.c" */

#define COMPOSE KC_KP_ENTER
/* super_meta_hyper */
#define GUI LGUI

#define SET_HOTKEY_1 LCTL(LALT(LGUI(KC_F1)))
#define SET_HOTKEY_2 LCTL(LALT(LGUI(KC_F2)))
#define SET_HOTKEY_4 LCTL(LALT(LGUI(KC_F4)))
#define SET_HOTKEY_5 LCTL(LALT(LGUI(KC_F5)))
#define SET_HOTKEY_6 LCTL(LALT(LGUI(KC_F6)))
#define SET_HOTKEY_0 LCTL(LALT(LGUI(KC_F12)))

#define SELECT_HOTKEY_1 LALT(LGUI(KC_F1))
#define SELECT_HOTKEY_2 LALT(LGUI(KC_F2))
#define SELECT_HOTKEY_4 LALT(LGUI(KC_F4))
#define SELECT_HOTKEY_5 LALT(LGUI(KC_F5))
#define SELECT_HOTKEY_6 LALT(LGUI(KC_F6))
#define SELECT_HOTKEY_0 LALT(LGUI(KC_F12))
#define key_0_7 KC_GRAVE
#define key_1_7 SELECT_HOTKEY_2
#define key_2_7 SELECT_HOTKEY_4
#define key_3_7 SELECT_HOTKEY_5
#define key_4_7 TD(DANCE_ALT_OR_RCTRL)
/* #define key_4_7 TD(dance_k74) */



#define SELECT_TO_LINE_HOME LSFT(KC_HOME)
#define SELECT_TO_DOC_HOME RCTL(LSFT(KC_HOME))

#define SELECT_TO_LINE_END LSFT(KC_END)
#define SELECT_TO_DOC_END RCTL(LSFT(KC_END))


#define EMACS_RECENTER_ON_DEFUN RCTL(LALT(KC_Z))

#define KC_LBRACKET KC_LBRC
#define KC_RBRACKET KC_RBRC
#define KC_SCOLON KC_SCLN
#define KC_PGDOWN KC_PGDN
#define KC_PSCREEN KC_PSCR
#define KC_BSPACE KC_BACKSPACE
#define KC_BSLASH KC_BACKSLASH
#define KC_SCROLLLOCK KC_SCROLL_LOCK
#define KC_LSHIFT KC_LSFT
#define KC_RSHIFT KC_RSFT


#define EMACS_FASD_DEFAULT RCTL(KC_ASTR)
#define EMACS_FASD_GLOBAL_NO_EXT KC_F12
#define EMACS_FASD_PROJECT_NO_EXT LCTL(KC_F12)
#define EMACS_FASD_PROJECT_CURR_EXT RCTL(KC_F12)

#define WINDOW_ALWAYS_ON_TOP LCTL(LSFT(LGUI(RCTL(KC_UP))))
#define WINDOW_TOGGLE_HORIZONTAL_MAX LSFT(LGUI(RCTL(KC_MINUS)))

#define winmove_U_monitor LGUI(LSFT(KC_UP))
#define winmove_L_monitor LGUI(LSFT(KC_LEFT))
#define winmove_R_monitor LGUI(LSFT(KC_RIGHT))
#define winmove_D_monitor LGUI(LSFT(KC_DOWN))

#define winmove_U LGUI(LSFT(KC_K))
#define winmove_D LGUI(LSFT(KC_J))

#define winmove_UL LGUI(LSFT(KC_Y))
#define winmove_UR LGUI(LSFT(KC_O))
#define winmove_R LGUI(LSFT(KC_L))
#define winmove_L LGUI(LSFT(KC_H))
#define winmove_DL LGUI(LSFT(KC_N))
#define winmove_DR LGUI(LSFT(KC_DOT))


#define editing_j LALT(LSFT(KC_J))
#define editing_k LALT(LSFT(KC_K))
#define editing_l LALT(LSFT(KC_L))
#define next_win_or_frame LALT(KC_N)
#define prev_win_or_frame LALT(KC_P)


/* #define EMACS_LOCCUR RCTL(LALT(LGUI(KC_O))) */
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
#define LOWER LT(_LOWER, KC_MINUS) //TD(DANCE_SHIFT)

/* #define RAISE MO(_RAISE) */
#define RAISE TD(DANCE_RAISE) // LT(_RAISE, KC_PLUS)
#define all_mods LM(_ALL_MODS, MOD_LGUI | MOD_LCTL | MOD_LALT | MOD_RCTL | MOD_LSFT)
#define alt_tab ALT_TAB
#define KC_BSPACE KC_BACKSPACE
#define KC_BSLASH KC_BACKSLASH
#define backspace KC_BSPACE
#define lower_backspace TD(WWW_BACK_FORWARD)
#define raise_backspace LT(_EDITING, KC_DEL)
#define below_b KC_LALT
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_n KC_LALT
#define below_v MT(MOD_RCTL, KC_ESCAPE)
#define emacs_a _______
#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_m EMACS_YAS_MAP_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(LALT(KC_LSFT))
#define key_4_11 KC_DOWN //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_UP
#define key_left KC_LEFT
#define key_right KC_RIGHT
#define lm_ctrl LM(_CTRL, MOD_RCTL)
#define lower_LOWER TO(_BASE)
#define lower_key_4_11 KC_DOWN
#define lower_key_4_12 KC_UP
#define lower_right_of_lower TD(WWW_BACK_FORWARD)
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
#define my_b KC_B



#define my_cap_comma KC_COMMA
#define my_cap_period KC_DOT
#define my_cap_d LSFT(KC_D)
#define my_cap_f LSFT(KC_F)
#define my_cap_h LSFT(KC_H)
#define my_cap_h LSFT(KC_H)
#define my_cap_i LSFT(KC_I)
#define my_cap_j LSFT(KC_J)
#define my_cap_k LSFT(KC_K)
#define my_cap_l LSFT(KC_L)
#define my_cap_m LSFT(KC_M)
#define my_cap_n LSFT(KC_N)
#define my_cap_u LSFT(KC_U)

#define my_cap_o LSFT(KC_O)
#define my_cap_p LSFT(KC_P)
#define my_lctl  MT(MOD_RCTL, KC_ESCAPE)
#define esc_ctrl my_lctl
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_bs KC_DEL
#define my_lower_comma BROWSER_TAB_PREV
#define my_lower_comma BROWSER_TAB_PREV
#define my_lower_d KC_F7
#define my_lower_f  KC_F8
#define my_lower_g KC_TAB
#define my_lower_m LALT(KC_M)
#define my_lower_n _______
#define my_lower_o KC_END
#define my_lower_p KC_BSPACE
/* #define my_lower_p KC_MINUS */
#define my_lower_period BROWSER_TAB_NEXT
#define my_lower_r KC_F4
#define my_lower_semi TD(DANCE_QUOTE)
/* #define my_lower_slash KC_GRAVE */
#define my_lower_slash KC_ENTER
#define my_minus _______
#define my_raise RAISE
#define my_raise_comma KC_2

#define my_raise_z LCTL(KC_Z)
#define my_raise_x RCTL(KC_X)
#define my_raise_c RCTL(KC_C)
#define my_raise_v TD(DANCE_SAVE_LOAD_NS_SWITCH)
#define my_raise_b _______
#define my_raise_q KC_HOME

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
#define my_right_of_lower editing_and_backspace
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define my_semicolon KC_SCOLON
#define my_singlequote KC_QUOTE
#define my_v KC_V
#define raise_space KC_UNDS
#define raise_key_4_9 KC_ENTER // KC_BSPC
#define raise_semi  KC_MINUS
#define raise_slash KC_ENTER
/* #define right_of_lower  esc_ctrl  // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE) */
#define lower_right_of_super TD(WWW_BACK_FORWARD)
#define scroll_next RCTL(KC_D)
#define scroll_prev RCTL(KC_U)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_F3)))

#define adhoc_set_hotkey OSL(_ADHOC_SET_HOTKEY)
#define super_meta_hyper adhoc_set_hotkey
#define topright _______
#define emacs_buffer_stack_down LCTL(LALT(KC_H))
#define emacs_buffer_stack_up LCTL(LALT(KC_L))

#define EMACS_SELECT_WINDOW SS_LGUI(SS_TAP(X_E)) SS_DELAY(150)
#define EMACS_SCROLL_DOWN RCTL(LGUI(KC_Y))
#define EMACS_SCROLL_UP RCTL(KC_Y)


#define toggle_microphone LALT(LGUI(KC_F7))
#define on_microphone LALT(LGUI(KC_F8))
#define off_microphone LALT(LGUI(KC_F9))

#define top_alpha_mid_column TD(DANCE_MICROPHONE)


#define KEYBOARD_LAYOUT_HOLD_KEY KC_RGUI


/* #define key_4_7 TD(dance_k74) */

enum col7_row4_fns {
                    K74_MO_LEVEL3 = SAFE_RANGE,
                    K74_MO_APL
};
static int active_apl_level3_fn = K74_MO_APL;

enum alt_rctrl_fns {
                    MO_ALT = SAFE_RANGE,
                    MO_RCTRL

};
static int active_alt_rctrl_key_fn = MO_ALT;

void clear_modifiers(void) {
  unregister_code16(KC_LGUI);
  unregister_code16(KC_RGUI);
  unregister_code16(KC_RALT);
  unregister_code16(KC_LALT);
  unregister_code16(KC_RCTL);
  unregister_code16(KC_LCTL);
  unregister_code16(COMPOSE);
  unregister_code16(KEYBOARD_LAYOUT_HOLD_KEY);
}

void cycle_active_key_alt_rctrl_fn(void) {
  switch (active_alt_rctrl_key_fn) {
  case MO_ALT:
#ifdef AUDIO_ENABLE
    PLAY_SONG(voice_change_sound);
#endif

    active_alt_rctrl_key_fn = MO_RCTRL;
    break;

  case MO_RCTRL:
#ifdef AUDIO_ENABLE
    PLAY_SONG(guitar_sound);
#endif

    active_alt_rctrl_key_fn = MO_ALT;
    break;
  }
}


void cycle_active_apl_level3_fn(void) {
  dprintf("cycle active_apl_level3_fn: %u", active_apl_level3_fn);

  switch (active_apl_level3_fn) {
  case K74_MO_LEVEL3:
#ifdef AUDIO_ENABLE
    PLAY_SONG(voice_change_sound);
#endif

    active_apl_level3_fn = K74_MO_APL;
    break;
  case K74_MO_APL:
#ifdef AUDIO_ENABLE
    PLAY_SONG(guitar_sound);

#endif

    active_apl_level3_fn = K74_MO_LEVEL3;
    break;
    dprintf("active_apl_level3_fn: %u", active_apl_level3_fn);
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
                      EMACS_SYNC_FEED,
                      COPY_TEXT_OPEN_NEW_TAB_SEARCH,
                      TMPTXT,
                      ALT,
                      TO_BASE,
                      LLOCK,
                      LLOCK_RAISE,
                      LLOCK_LOWER,
                      LLOCK_EDITING,
                      LLOCK_LEVEL3,
                      LLOCK_APL,
                      COPY_LATEST_FILE_TO_CLIPBOARD,
                      CLJ_REFIND,
                      CD_C9,
                      ROFI_CLIPBOARD ,
                      ROFI_WINDOWS ,
                      ROFI_LOCATE ,
                      ROFI_DRUN ,
                      ROFI_EMOJI ,

                      WINDOWS_Q,
                      WINDOWS_E,

                      CLEAR_MODIFIERS,


                      EMACS_NEXT_SEXP,
                      CYCLE_ACTIVE_APL_LEVEL3_FN,
                      level3,
                      SSH_CRONJOBS_PROD,
                      EMACS_PREV_SEXP,
                      AUTOSHIFT_TOGGLE,
                      WEB_SAVE_FILE_UNDER_CURSOR,
                      CAPS_WORD_TOGGLE,
                      TEMP_TEXT,
                      BACKWARD_KILL_LINE,
                      EMACS_TRANSPOSE,
                      OPEN_PAREN,
                      CLOSED_PAREN,
                      TERM_CD_PREVIOUS,
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
                      EMACS_ACE_WINDOW_SELECT,
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
                      EMACS_INSERT_GI_GET_FEED,
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
                      EMACS_LOCCUR,
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


#define editing_and_backspace LT(_EDITING, KC_BSPACE)
#define apl_level3_and_adhoc_hotkey TD(DANCE_LEVEL3_APL)
/* #define key_4_7 apl_level3_and_adhoc_hotkey */

#define max_buffer LALT(KC_ENTER)
#define close_x_window RCTL(LGUI(KC_Q))
#define macro_alt_slash SS_LALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool fasd_timer_active = false;
uint16_t fasd_timer = 0;
int fasd_level = 0;
int fasd_level_duration = 400;

bool open_paren_timer_active = false;
uint16_t open_paren_timer = 0;
int open_paren_level = 0;
int open_paren_level_duration = 400;

bool closed_paren_timer_active = false;
uint16_t closed_paren_timer = 0;
int closed_paren_level = 0;
int closed_paren_level_duration = 400;


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

/* int DROP_CURRENT_ANIMATION = 0;//RGBLIGHT_MODE_STATIC_LIGHT; */
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

  DROP_CURRENT_ANIMATION = faves[i];
  /* dprintf("idx: %u, drop animation: %u\n", i, DROP_CURRENT_ANIMATION); */
  rgblight_mode(DROP_CURRENT_ANIMATION);
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
  /* k++; */
  /* if (k >= 42) { */
  /*   k = 0; */
  /* } */
  /* if (do_echo) { */
  /*   static char s[10]; */
  /*   itoa(k, s, 10); */
  /*   SEND_STRING(s); */
  /* } */
  /* rgblight_mode(k); */
}





bool do_breathing = false;

#endif



/* SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) */
/* SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LGUI(SS_TAP(X_E)) SS_DELAY(100) SS_LALT(SS_TAP(X_M)) */

#define right_of_super MO(_APL)  // X(BANG) // esc_ctrl //  BRACKET_PAREN //all_mods


#define editing_comma emacs_buffer_stack_down
#define editing_period emacs_buffer_stack_up
#define emacs_indent_buffer RCTL(LALT(KC_BSLASH))

#define EMACS_EVIL_JUMP_ITEM RCTL(KC_COMMA)
