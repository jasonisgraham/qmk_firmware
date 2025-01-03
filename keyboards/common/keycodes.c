/* #include QMK_KEYBOARD_H */
#include "user_song_list.c"
/* #include "version.h" */
/* /\* #include "musical_notes.h" *\/ */
/* #include "../../quantum/hacks.c" */


#define EMACS_SEL_0 LALT(KC_0)
#define EMACS_SEL_1 LALT(KC_1)
#define EMACS_SEL_2 LALT(KC_2)
#define EMACS_SEL_3 LALT(KC_3)
#define EMACS_SEL_4 LALT(KC_4)
#define EMACS_SEL_5 LALT(KC_5)

#define WINDOWS_COPY RCTL(KC_C)
#define TMUX_SELECT_TEXT LALT(KC_LCBR)

#define MOD_MASK_ALL_MODS_COMPAT (MOD_BIT_LCTRL | MOD_BIT_RCTRL | MOD_BIT_LALT | MOD_BIT_RGUI)
#define MOD_MASK_ALL_MODS (MOD_BIT_RALT | MOD_BIT_RCTRL | MOD_BIT_LCTRL | MOD_BIT_RCTRL | MOD_BIT_LALT | MOD_MASK_SHIFT | MOD_BIT_RGUI)
#define OSL_RCTL_LALT (MOD_BIT_RCTRL | MOD_BIT_LALT)
#define ULAUNCHER LGUI(KC_SPACE)
#define backtab LSFT(KC_TAB)
#define emacs_completion_at_point LALT(RCTL(KC_I))

#define super_mod_r2 KC_TAB
#define super_mod_r3 LSFT(KC_TAB)
#define super_f KC_F
#define super_b KC_B
#define super_r KC_R
#define super_w KC_R
#define super_g KC_G

#define GREP_STRING_IN_BUFFER_DIR LCTL(LALT(KC_G))
#define TERM_PASTE RCTL(RSFT(KC_V))

#define select_firefox LGUI(KC_X)
#define select_terminal GUI(KC_T)
#define select_emacs GUI(KC_E)
#define select_emacs_clojure GUI(KC_9)

#define osl_web OSL(_WEB)
#define osl_rofi OSL(_ROFI)
#define COMPOSE KC_KP_ENTER
/* super_meta_hyper */
#define GUI LGUI

#define FILE_SEARCH LALT(KC_3)
#define PLASMA_SEARCH LALT(KC_6)

#define FORWARD_SEXP LALT(LCTL(KC_F))
#define TOGGLE_MENU_BAR LSFT(LGUI(KC_F12))
#define PAREDIT_BACKWARD_UP LALT(RCTL(KC_U))
#define SET_HOTKEY_0 LCTL(LALT(LGUI(KC_F1)))
#define SET_HOTKEY_1 LCTL(LALT(LGUI(KC_F2)))
#define SET_HOTKEY_2 LCTL(LALT(LGUI(KC_F12)))
#define SET_HOTKEY_3 LCTL(LALT(LGUI(KC_F4)))
#define SET_HOTKEY_4 LCTL(LALT(LGUI(KC_F5)))
#define SET_HOTKEY_5 LCTL(LALT(LGUI(KC_F6)))

#define SELECT_HOTKEY_0 LALT(LGUI(KC_F1))
#define SELECT_HOTKEY_1 LALT(LGUI(KC_F2))
#define SELECT_HOTKEY_2 LALT(LGUI(KC_F12))
#define SELECT_HOTKEY_3 LALT(LGUI(KC_F4))
#define SELECT_HOTKEY_4 LALT(LGUI(KC_F5))
#define SELECT_HOTKEY_5 LALT(LGUI(KC_F6))
#define mod_r1 KC_ENTER
#define mod_r2 KC_UP
#define mod_r3 KC_DOWN
#define mod_r4 TD(DANCE_MOD_R4) // TD(DANCE_HOTKEY_OR_COMPOSE)
/* #define mod_r4 TD(dance_k74) */



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
#define winmove_cycle_horizontal_max LSFT(LGUI(LALT(KC_SCOLON)))

#define winmove_U_monitor LGUI(KC_UP)
#define winmove_L_monitor LGUI(KC_LEFT)
#define winmove_R_monitor LGUI(KC_RIGHT)
#define winmove_D_monitor LGUI(KC_DOWN)

#define winmove_U LGUI(LSFT(KC_K))
#define winmove_D LCTL(LGUI(LSFT(KC_J)))

#define winmove_UL LGUI(LSFT(KC_Y))
#define winmove_UR LGUI(LSFT(KC_O))
#define winmove_R LGUI(LSFT(KC_L))
#define winmove_L LGUI(LSFT(KC_H))
#define winmove_DL LGUI(LSFT(KC_N))
#define winmove_DR LGUI(LSFT(KC_DOT))

#define winmove_top LGUI(LSFT(KC_I))
#define winmove_bottom LGUI(LSFT(KC_COMMA))

#define editing_h LALT(LSFT(KC_H))
#define editing_j LALT(LSFT(KC_J))
#define editing_k LALT(LSFT(KC_K))
#define editing_l LALT(LSFT(KC_L))
#define next_win_or_frame LALT(KC_N)
#define prev_win_or_frame LALT(KC_P)


/* #define EMACS_LOCCUR RCTL(LALT(LGUI(KC_O))) */
/* #define CTRL_L RCTL(KC_P) */
#define CTRL_N RCTL(KC_N)
#define ALT_N LALT(KC_N)
#define CTRL_P RCTL(KC_P)
#define ALT_P LALT(KC_P)
#define CTRL_SEMICOLON RCTL(KC_SCOLON)
/* H-M-s-d */
#define EMACS_EVIL_LISP_STATE    LCTL(KC_6)
#define EMACS_KILL_IN_SEXP LCTL(LALT(LGUI(KC_D)))
#define EMACS_YANK_IN_SEXP LCTL(LALT(LGUI(KC_I)))
#define EMACS_NUMBER_DEC LCTL(KC_UNDS)
#define EMACS_NUMBER_INC LCTL(KC_PLUS)
#define EMACS_OTHER_WINDOW_NEXT RCTL(LALT(KC_PGUP))
#define EMACS_OTHER_WINDOW_PREV RCTL(LALT(KC_PGDOWN))
#define HYPER_L LCTL(KC_L)


/* #define RAISE MO(_RAISE) */
#define CINNAMON_MENU_OPEN LALT(LGUI(KC_7))
#define RAISE TD(DANCE_RAISE) //
#define alt_tab ALT_TAB
#define KC_BSPACE KC_BACKSPACE
#define KC_BSLASH KC_BACKSLASH
#define backspace KC_BSPACE
#define raise_up KC_RIGHT
#define raise_right EMACS_NEXT_SEXP
#define raise_down KC_LEFT
#define raise_left EMACS_PREV_SEXP
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
#define key_4_11 LAYER_MOUSE_HOLD  // KC_DOWN //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_ENTER
#define key_left KC_LEFT
#define key_right KC_RIGHT
#define lm_ctrl LM(_CTRL, MOD_RCTL)
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



#define my_cap_a LSFT(KC_A)
#define my_cap_s LSFT(KC_S)
#define my_cap_comma KC_COMMA
#define my_cap_period KC_DOT
#define my_cap_d LSFT(KC_D)
#define my_cap_f LSFT(KC_F)
#define my_cap_h LSFT(KC_H)
#define my_cap_h LSFT(KC_H)
#define my_cap_i LSFT(KC_I)
#define my_cap_j LSFT(KC_J)
#define my_cap_k TD(DANCE_CAP_K)
#define my_cap_l LSFT(KC_L)
#define my_cap_m LSFT(KC_M)
#define my_cap_n LSFT(KC_N)
#define my_cap_u LSFT(KC_U)

#define my_cap_o LSFT(KC_O)
#define my_cap_p LSFT(KC_P)
#define my_lctl  TD(DANCE_ESC_CTRL) // MT(MOD_RCTL, KC_ESCAPE)
#define esc_ctrl my_lctl


#define BROWSER_SEARCH_OPEN_TABS RCTL(LSFT(KC_A))
#define LOWER TD(DANCE_LOWER) // LT(_LOWER, KC_MINUS) //TD(DANCE_SHIFT)
#define lower_LOWER TO(_BASE)
#define lower_backspace RCTL(KC_UP)
#define lower_down RCTL(KC_DOWN)
#define lower_key_4_11 KC_DOWN
#define lower_key_4_12 KC_UP
#define lower_right_of_lower TD(WWW_BACK_FORWARD)
#define lower_right_of_super TD(WWW_BACK_FORWARD)
#define my_lower MO(_LOWER)
#define my_lower_bs KC_DEL
#define my_lower_comma BROWSER_TAB_LEFT

#define my_lower_q KC_F1
#define my_lower_w KC_F2
#define my_lower_e KC_F3
#define my_lower_r KC_F4

#define my_lower_a KC_F5
#define my_lower_s KC_F6
#define my_lower_d KC_F7
#define my_lower_f KC_F8

#define my_lower_z KC_F9
#define my_lower_x KC_F10
#define my_lower_c KC_F11
#define my_lower_v KC_F12

#define my_lower_b KC_APPLICATION
#define my_lower_g RCTL(KC_GRAVE)
#define my_lower_h KC_LEFT // LEFT_OR_HOME
#define my_lower_i KC_PGUP
#define my_lower_j KC_DOWN // PAGE_DOWN_OR_END
#define my_lower_k KC_UP // PAGE_UP_OR_HOME
#define my_lower_l KC_RIGHT   // RIGHT_OR_END
#define my_lower_m EMACS_JUMP_ITEM // BROWSER_SEARCH_OPEN_TABS
#define my_lower_n KC_BSLASH
#define my_lower_o KC_END
#define my_lower_p KC_BSPACE
#define my_lower_period BROWSER_TAB_RIGHT
#define my_lower_semi TD(DANCE_QUOTE)
#define my_lower_slash TD(WWW_BACK_FORWARD)
#define my_lower_u KC_PGDOWN
/* #define my_lower_p KC_MINUS */
/* #define my_lower_slash KC_GRAVE */



#define my_minus _______

#define raise_bspace LSFT(KC_TAB)
#define my_raise RAISE
#define my_raise_comma KC_2

#define my_raise_q _______
#define my_raise_w osl_web
#define my_raise_e TD(DANCE_PASTE_OR_CLIPBOARD)
#define my_raise_r EMACS_BUFFER_REVERT
#define my_raise_t KC_PGUP

#define my_raise_tab backtab
#define BROWSER_MOST_RECENT_TAB LALT(KC_Z)
#define my_raise_a TD(DANCE_F5)
#define my_raise_s _______
#define my_raise_d KC_ENTER
#define my_raise_f LALT(LSFT(KC_F8))
#define my_raise_g KC_PGDOWN

#define my_raise_z BROWSER_MOST_RECENT_TAB
#define my_raise_x BROWSER_TAB_LEFT
#define my_raise_c BROWSER_TAB_RIGHT
#define my_raise_v TD(DANCE_SAVE_LOAD_NS_SWITCH)
#define my_raise_b TD(WWW_BACK_FORWARD)

#define HELM_CIDER_HISTORY LCTL(KC_H)
#define my_raise_h KC_BSLASH
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
#define my_raise_y  KC_BSLASH
#define my_right_of_lower LT(_EMACS, KC_BACKSPACE)
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define my_singlequote KC_QUOTE
#define raise_space KC_UNDS
#define raise_key_4_9 KC_ENTER // KC_BSPC
#define raise_semi  KC_DQUO
#define raise_slash KC_BSLASH

#define scroll_next RCTL(KC_D)
#define scroll_prev RCTL(KC_U)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_F3)))

#define super_backtab LSFT(KC_TAB)
#define super_tab KC_TAB

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


/* #define mod_r4 TD(dance_k74) */


enum col7_row4_fns {
    K74_MO_LEVEL3 = SAFE_RANGE,
    K74_MO_ALT_KEYBOARD
};
static int active_alt_keyboard_level3_fn = K74_MO_LEVEL3;

enum alt_rctrl_fns {
    MO_ALT = SAFE_RANGE,
    MO_RCTRL

};
static int active_alt_rctrl_key_fn = MO_ALT;

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


void cycle_active_alt_keyboard_level3_fn(void) {
    dprintf("cycle active_alt_keyboard_level3_fn: %u", active_alt_keyboard_level3_fn);

    switch (active_alt_keyboard_level3_fn) {
    case K74_MO_LEVEL3:
#ifdef AUDIO_ENABLE
        PLAY_SONG(voice_change_sound);
#endif

        active_alt_keyboard_level3_fn = K74_MO_ALT_KEYBOARD;
        break;
    case K74_MO_ALT_KEYBOARD:
#ifdef AUDIO_ENABLE
        PLAY_SONG(guitar_sound);

#endif

        active_alt_keyboard_level3_fn = K74_MO_LEVEL3;
        break;
        dprintf("active_alt_keyboard_level3_fn: %u", active_alt_keyboard_level3_fn);
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
    COPY_TORRENT_URL_THEN_OPEN,
    MATRIX_INCREASE_SPEED,
    MATRIX_DECREASE_SPEED,
    MATRIX_SET_DEFAULT_ANIMATION,
    SAVE_ALL_THEN_GOTO_BASE,
    EMACS_SEL_EXLM,
    EMACS_SEL_AT,
    EMACS_SEL_HASH,
    EMACS_SEL_DLR,
    EMACS_SEL_PERC,
    EMACS_SEL_CIRC,
    EMACS_SEL_AMPR,
    EMACS_SEL_ASTR,
    EMACS_SEL_LPRN,
    EMACS_SEL_RPRN,

    EMACS_SEL_A,
    EMACS_SEL_B,
    EMACS_SEL_C,
    EMACS_SEL_COMMA,
    EMACS_SEL_D,
    EMACS_SEL_DB,
    EMACS_SEL_DOT,
    EMACS_SEL_E,
    EMACS_SEL_F,
    EMACS_SEL_G,
    EMACS_SEL_H,
    EMACS_SEL_I,
    EMACS_SEL_J,
    EMACS_SEL_K,
    EMACS_SEL_L,
    EMACS_SEL_LOWER,
    EMACS_SEL_M,
    EMACS_SEL_MODR1,
    EMACS_SEL_MODR2,
    EMACS_SEL_MODR3,
    EMACS_SEL_MODR4,
    EMACS_SEL_N,
    EMACS_SEL_O,
    EMACS_SEL_P,
    EMACS_SEL_Q,
    EMACS_SEL_GRAVE,
    EMACS_SEL_R,
    EMACS_SEL_RAISE,
    EMACS_SEL_S,
    EMACS_SEL_SCLN,
    EMACS_SEL_SLASH,
    EMACS_SEL_T,
    EMACS_SEL_TAB,
    EMACS_SEL_U,
    EMACS_SEL_V,
    EMACS_SEL_W,
    EMACS_SEL_X,
    EMACS_SEL_Y,                     EASYMOTION_LEADER,
    BRAVE_SEARCH_TO_GOOGLE,
    CUT_TEXT_IN_FIRST_FIELD,
    ACEJUMP,
    SWAP_SELECTION_BOUNDARIES,
    MOVE_STATEMENT_DOWN,
    MOVE_STATEMENT_UP,
    DUPLICATE_LINE,
    SELECTION_EXPAND,
    SELECTION_SHRINK,
    CTRL_X_ALL_MODS_OSM,
    SURROUND,
    EMACS_BUFFER_MAXIMIZE,
    LAUNCHER_FDFIND,
    ALL_MODS_OSM,
    ONE_SHOT_ALT_KEYBOARD,
    ONE_SHOT_LEVEL3,
    LAUNCHER_CLIPBOARD,
    LAUNCHER_WIKI,
    LAUNCHER_TRANSLATE,
    OPEN_NOTIFICATIONS,
    CLEAR_NOTIFICATIONS,
    ROFI_CALCULATOR,
    RG_FZF,
    EMACS_FOCUS_REPL,
    CIDER_HISTORY_WRITE,
    EMACS_FOCUS_REPL_IMMEDIATELY,
    LPRN_EQUAL,
    CIDER_EVAL_OR_TERMINAL_EDIT,
    ROFI_LOCATE_GLOBAL,
    ROFI_LOCATE_CLJ,
    ROFI_PROCESSES,
    ROFI_LOCATE_PRINT_FILTER_DIR,
    CLJ_FREQS,
    EMACS_SET_GLOBAL_LOCATE_DOCS_FILTER_DIR,
    ROFI_CIDER_HISTORY,
    ROFI_LOCATE_ALL,
    DELETE_LOCATE_DOCS_FILTER_DIR,
    ROFI_LOCATE_WITH_FILTER,
    ROFI_LOCATE_SOURCE_FILES,
    RESET_INPUT_PREFS,
    THREAD_LAST_EQUAL,
    FN_THEN_THREAD_LAST_EQUAL,
    LISP_COMMENT,
    EQUAL_THEN_SPACE,
    RELOAD_TAP_INSPECTOR,
    SHRUG,
    EMACS_WRAP_HYDRA,
    REFRAME_SUBSCRIBE,
    REFRAME_DISPATCH,
    EMACS_WINNER_UNDO,
    EMACS_WINNER_REDO,
    EMACS_DEFUN_END,
    EMACS_DEFUN_BEGIN,
    CIDER_RUN_TEST,
    EMACS_JUMP_ITEM,
    CLJ_ADD_REQS,
    COPY_TEXT_OPEN_NEW_TAB_SEARCH,
    TMPTXT,
    ALT,
    TO_BASE,
    LLOCK,
    LLOCK_RAISE,
    LLOCK_MOTION,
    LLOCK_LOWER,
    LLOCK_EDITING,
    LLOCK_LEVEL3,
    LLOCK_ALT_KEYBOARD,
    COPY_LATEST_FILE_TO_CLIPBOARD,
    CLJ_REFIND,
    LAUNCHER_SYSTEM,
    LAUNCHER_WINDOWS ,
    LAUNCHER_DEFINE,
    LAUNCHER_GOOGLE,
    ROFI_LOCATE ,
    ROFI_DRUN ,
    ROFI_EMOJI ,

    WINDOWS_Q,

    CLEAR_MODIFIERS,


    EMACS_NEXT_SEXP,
    CYCLE_ACTIVE_ALT_KEYBOARD_LEVEL3_FN,
    level3,
    EMACS_PREV_SEXP,
    AUTOSHIFT_TOGGLE,
    SAVE_FILE_THEN_VIM_NORMAL_MODE,
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
    EMACS_HELM_KILL_RINGS,
    EMACS_INSIDE_YANK,
    EMACS_INSIDE_DELETE,
    EMACS_TO_YANK,
    EMACS_TO_DELETE,
    CLJ_ANON,
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
    CLJ_TAP,
    TOGGLE_ECHO,
    TOGGLE_BREATHING,
    EMACS_ACE_WINDOW_SELECT,
    TERM_HOME,
    LAYER_MOUSE_HOLD,
    TMUX_SPLIT_WINDOW,
    EMACS_SPLIT_WINDOW_UP,
    EMACS_SPLIT_WINDOW_DOWN,
    EMACS_SPLIT_WINDOW_RIGHT,
    EMACS_SPLIT_WINDOW_LEFT,
    CYCLE_FAVE_ANIMATIONS,
    CYCLE_RGBLIGHT_STEP,
    ALT_TAB,
    ALT_BACKTAB,
    EMACS_ACE_WINDOW_SWAP,
    EMACS_BUFFER_REVERT,
    EMACS_INSERT_GET_FEED,
    EMACS_INSERT_GI_GET_FEED,
    EMACS_KILL_PROCESS,
    EMACS_OTHER_WINDOW,
    EMACS_WINDOW_DELETE,
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
    TMUX_CLOSE,
    TERM_CD_UP_DIR,
    EMACS_LOCCUR,
    EMACS_TOGGLE_REPL,
    CLEAR_THAT_REPL,
    HOME_THEN_EMACS_WRAP_IN_THREAD_LAST,
    HOME_THEN_EMACS_WRAP_IN_THREAD_FIRST,
    EMACS_WRAP_IN_THREAD_LAST,
    EMACS_WRAP_IN_THREAD_FIRST,
    EMACS_WRAP_IN_THREAD_LAST_SOME,
    THREAD_LAST,
                      SA_LAYER_ACTIVATE,
                      THREAD_FIRST,
                      CLJ_ARROW,
                      MORPH_LESS,
                      MORPH_NESS,
                      MORPH_ATION,
                      MORPH_MENT,
                      WORD_BECAUSE,
};


#define alt_keyboard_level3_and_adhoc_hotkey TD(DANCE_LEVEL3_ALT_KEYBOARD)
/* #define mod_r4 alt_keyboard_level3_and_adhoc_hotkey */

#define max_buffer LALT(KC_ENTER)
#define close_x_window RCTL(LGUI(KC_Q))
#define macro_alt_slash SS_LALT(SS_TAP(X_SLASH))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const int default_timer_increment = 300;

bool rofi_locate_timer_active = false;
uint16_t rofi_locate_timer = -20;
int rofi_locate_level = 0;
int rofi_locate_level_duration = default_timer_increment;

bool fasd_timer_active = false;
uint16_t fasd_timer = 0;
int fasd_level = 0;
int fasd_level_duration = default_timer_increment;

bool open_paren_timer_active = false;
uint16_t open_paren_timer = 0;
int open_paren_level = 0;
int open_paren_level_duration = default_timer_increment;

bool closed_paren_timer_active = false;
uint16_t closed_paren_timer = 0;
int closed_paren_level = 0;
int closed_paren_level_duration = default_timer_increment;



int8_t m;
char b[3];
int i = 0;

const uint8_t fireworks = 42;
const uint8_t faves[7] = {fireworks, 15, 16, 17, 20, 22, 41};
/* const uint8_t faves[7] = {fireworks, 15, 16, 17, 20, 22, 41}; */
void cycle_fave_animations(void) {
  i++;
  if (i >= 47) {
    i = 0;
  }
  /* printf("%i\n", i); */
  /* printf("mode: %u, hue: %u, sat: %u, val: %u, speed: %u\n", rgb_matrix_get_mode(), rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val(),  rgb_matrix_get_speed()); */
  rgblight_mode(i);
}

void apply_fave_animation(void) {
  rgblight_mode(faves[i]);
}

#ifdef RGBLIGHT_ENABLE

int DROP_LAYER_0_COLOR = 0;

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

#define right_of_super MO(_ALT_KEYBOARD)  // X(BANG) // esc_ctrl //  BRACKET_PAREN //all_mods


#define editing_comma emacs_buffer_stack_down
#define editing_period emacs_buffer_stack_up
#define emacs_indent_buffer RCTL(LALT(KC_BSLASH))

#define EMACS_EVIL_JUMP_ITEM RCTL(KC_PERC)

#define macros_r emacs_r
#define macros_g EMACS_INSERT_GET_FEED


#define editing_u SELECTION_SHRINK
#define editing_i SELECTION_EXPAND
#define editing_o EMACS_HELM_OCCUR

#define CTRL_L RCTL(KC_L)
#define ctrl_alt_s RALT(RCTL(KC_S))

#define level3 COMPOSE
#define alt_keyboard KEYBOARD_LAYOUT_HOLD_KEY
#define META_X LALT(KC_X)

#define MOVE_STATEMENT_UP LALT(LSFT(KC_UP))
#define MOVE_STATEMENT_DOWN LALT(LSFT(KC_DOWN))
#define MOVE_ELEMENT_UP LALT(LSFT(KC_UP))
#define MOVE_ELEMENT_DOWN LALT(LSFT(KC_DOWN))

#define EMACS_SEL_Z LALT(KC_Z)
#define JETBRAINS_CLOSE_TAB RCTL(LSFT(KC_F4))


#define super TD(DANCE_SUPER) // LM(_SUPER, MOD_LGUI) //TD(SUPER_WINDOWS)

#define editing_q TD(DANCE_EDITING_Q)
#define BROWSER_TAB_RIGHT TD(DANCE_30)
#define alt TD(DANCE_ALT)
#define alt_or_rctrl TD(DANCE_ALT_OR_RCTRL)
#define hyper TD(DANCE_HYPER) // LM(_HYPER, MOD_LCTL) //KC_LCTL // OSL(_WINDOWS)

/* #define hyper TD(DANCE_HYPER) */

#define BROWSER_TAB_LEFT TD(DANCE_29)
#define my_comma TD(DANCE_COMMA) //KC_COMMA //
#define my_left_shift TD(DANCE_SHIFT)
#define emacs_left_shift TD(DANCE_SHIFT_CURLY)
#define editing_left_shift TD(DANCE_SHIFT_CURLY)
#define raise_left_shift TD(DANCE_RAISE_SHIFT)
#define lower_left_shift TD(DANCE_LOWER_SHIFT)
#define my_semicolon TD(DANCE_COLN)
#define my_cap_semi my_semicolon

/* #define super TD(DANCE_SUPER) //TD(SUPER_WINDOWS) */

#define EVIL_FIRST_NON_BLANK KC_HOME
#define EVIL_END_OF_LINE KC_END
#define EVIL_JUMP RCTL(KC_COMMA)

#define EMACS_REPEAT KC_F9
#define preonic_00 QK_LOCK // QK_AREP // TD(DANCE_MICROPHONE) // toggle mic //
#define preonic_1  KC_1
#define preonic_2  KC_2
#define preonic_3  KC_3
#define preonic_4  KC_4
#define preonic_5  KC_5
#define preonic_6  TD(DANCE_CODE_SYSTEM)
#define preonic_7  KC_6
#define preonic_8  KC_7
#define preonic_9  KC_8
#define preonic_10 KC_9
#define preonic_11 KC_0

#define PAGE_DOWN_OR_END TD(DANCE_PAGE_DOWN_OR_END)
#define my_lower_j KC_DOWN // PAGE_DOWN_OR_END
#define PAGE_UP_OR_HOME TD(DANCE_PAGE_UP_OR_HOME)
#define my_lower_k KC_UP // PAGE_UP_OR_HOME

#define LEFT_OR_HOME TD(DANCE_LEFT_OR_HOME)
#define my_lower_h KC_LEFT // LEFT_OR_HOME
#define RIGHT_OR_END TD(DANCE_RIGHT_OR_END)
#define my_lower_l KC_RIGHT   // RIGHT_OR_END
#define tab TD(DANCE_TAB)
#define top_left tab
#define emacs_completion_at_point LALT(RCTL(KC_I))
#define BRACKET_PAREN TD(DANCE_PAREN_BRACKET)
#define windows_j LGUI(KC_J)
#define windows_k LGUI(KC_K)
#define windows_l LGUI(KC_L)

#define my_lower_u KC_PGDOWN
#define my_lower_i KC_PGUP

/* #ifdef USE_WORKMAN */
/* #define my_a TD(DANCE_A) */
/* #define my_b TD(DANCE_B) */
/* #define my_c TD(DANCE_C) */
/* #define my_d TD(DANCE_R) */
/* #define my_e TD(DANCE_D) */
/* #define my_f TD(DANCE_T) */
/* #define my_g TD(DANCE_G) */
/* #define my_h TD(DANCE_H) */
/* #define my_i TD(DANCE_L) */
/* #define my_j TD(DANCE_N) */
/* #define my_k TD(DANCE_E) */
/* #define my_l TD(DANCE_O) */
/* #define my_m TD(DANCE_M) */
/* #define my_n TD(DANCE_K) */
/* #define my_o TD(DANCE_P) */
/* #define my_p TD(DANCE_COLN) */
/* #define my_q TD(DANCE_Q) */
/* #define my_r TD(DANCE_Y) */
/* #define my_s TD(DANCE_S) */
/* #define my_t TD(DANCE_F) */
/* #define my_u TD(DANCE_U) */
/* #define my_v TD(DANCE_V) */
/* #define my_w TD(DANCE_W) */
/* #define my_x TD(DANCE_X) */
/* #define my_y TD(DANCE_J) */
/* #define my_z TD(DANCE_Z) */
/* #define my_semicolon TD(DANCE_I) */

/* #else */
#define my_a KC_A
#define my_b KC_B
#define my_c KC_C
#define my_d KC_D
#define my_e KC_E
#define my_f KC_F
#define my_g KC_G
#define my_h KC_H
#define my_i KC_I
#define my_j KC_J
#define my_k KC_K
#define my_l KC_L
#define my_m KC_M
#define my_n KC_N
#define my_o KC_O
#define my_p KC_P
#define my_q TD(DANCE_Q)
#define my_r KC_R
#define my_s KC_S
#define my_t KC_T
#define my_u KC_U
#define my_v KC_V
#define my_w KC_W
#define my_x KC_X
#define my_y KC_Y
#define my_z KC_Z
#define my_semicolon TD(DANCE_COLN)
/* #endif */

#define my_cap_semi my_semicolon

#define my_forward_slash KC_SLASH
#define my_grave TD(DANCE_TAB)
#define my_period TD(DANCE_DOT)
#define my_space TD(DANCE_SPACE)

#define all_mods TD(DANCE_ALL_MODS)
#define ROFI_CLIPBOARD SS_LCTL(SS_LALT(SS_RCTL("9")))

#define ACCEPT RCTL(KC_E)

#define preonic_lctl OSM(MOD_LCTL)
#define preonic_lalt OSM(MOD_LALT)
#define preonic_rctl OSM(MOD_RCTL)
