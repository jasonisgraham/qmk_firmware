#include QMK_KEYBOARD_H
/* #include "muse.h" */
#include "colors.c"
/* #include "keymap_us_extended.h" */

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _HYPER,
                    _BOTH,
                    _MENU,
                    _DIAMOND,
                    _SYSTEM,
                    _WINDOWS,
                    _MACROS,
                    _SHIFTLOCK,
                    _WINMOVE,
                    _ALT,
                    _SUPER,
                    _EDITING,
                    _LAYER13,
                    _CTRL,
                    _MOUSE,
                    _COLORS,
                    _LAYER17,
                    _LAYER18,
                    _LAYER19,
                    _EMACS_SEL_WINDOW,
                    _GAUTH,
                    _AUDIO,
                    _VOLUME,
                    _BRIGHTNESS,
                    _ADHOC_SET_HOTKEY,
                    _ROFI,
                    _EXTENDED,
};

/* #include "../../../common/config.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX
#include "../../../../common/keycodes.c"
/* #include "../../../../common/key_overrides.c" */
/* #include "../../../../common/drop_tapdance.c" */
/* #include "../../../../common/drop_colors.c" */

#define test KC_ASTR
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define alt_tab ALT_TAB
#define backspace KC_BSPACE
#define below_b KC_RALT
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_n KC_RALT
#define below_v MT(MOD_RCTL, KC_ESCAPE)
#define emacs_a _______
#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_m EMACS_YAS_MAP_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
#define esc_ctrl MT(MOD_RCTL, KC_ESCAPE)
#define hyper LM(_HYPER, MOD_LCTL) //KC_LCTL // OSL(_WINDOWS)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(RALT(KC_RSFT))
#define key_4_10 OSL(_EDITING)
#define key_4_11 KC_DOWN //CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_UP
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))
#define my_cap_h RSFT(KC_H)
#define my_cap_i RSFT(KC_I)
#define my_cap_j RSFT(KC_J)
#define my_cap_k RSFT(KC_K)
#define my_cap_l RSFT(KC_L)
#define my_cap_m RSFT(KC_M)
#define my_cap_o RSFT(KC_O)
#define my_comma KC_COMMA //
#define my_forward_slash KC_SLASH
#define my_left_shift KC_LSFT //  LM(_SHIFTLOCK, MOD_LSFT)

#define my_lctl MT(MOD_RCTL, KC_ESCAPE)
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_comma BROWSER_TAB_PREV

#define my_lower_d KC_F7
#define my_lower_f  KC_F8
#define my_lower_h  KC_MINUS
#define my_lower_u KC_PGDOWN
#define my_lower_i KC_PGUP
#define my_lower_j KC_DOWN
#define my_lower_k KC_UP
#define my_lower_l KC_RIGHT
#define my_lower_m _______
#define my_lower_n _______
#define my_lower_o KC_END
#define my_lower_p LALT(KC_LEFT)
#define my_lower_bs KC_DEL
#define my_lower_period BROWSER_TAB_NEXT
#define my_lower_semi esc_ctrl
#define my_lower_slash SHIFTLOCK_LAYER_ACTIVATE
#define lower_LOWER TO(_BASE)
#define lower_right_of_lower _______
#define lower_key_4_11 KC_LEFT
#define lower_key_4_12 KC_RIGHT
#define raise_key_4_9 KC_ENTER // KC_BSPC

#define my_raise RAISE
#define my_raise_top_right KC_DEL
#define my_raise_comma KC_2
#define my_raise_d _______ //kc_bspace
#define my_raise_f RALT(KC_ENTER)
#define my_raise_h KC_BSPACE
#define my_raise_i KC_8
#define my_raise_j KC_4
#define my_raise_k KC_5
#define my_raise_l KC_6
#define my_raise_m KC_1
#define my_raise_n KC_DQUO
#define my_raise_o KC_9
#define my_raise_p KC_0
#define my_raise_period KC_3
#define my_raise_u  KC_7
#define my_raise_y  KC_QUOT
#define my_right_shift KC_RSFT // shift LM(_ALT, MOD_LSFT)
#define raise_semi KC_PLUS

#define my_semicolon KC_SCOLON
#define my_singlequote KC_QUOTE
#define my_space KC_SPACE

#define my_period KC_DOT
#define my_minus _______
#define my_grave KC_TAB

#define WINDOWS_Q LGUI(KC_Q)

#define windows_k RGUI(KC_J)
#define windows_l LGUI(KC_K)
#define top_left KC_TAB

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
#define my_q KC_Q
#define my_r KC_R
#define my_s KC_S
#define my_t KC_T
#define my_u KC_U
#define my_v KC_V
#define my_w KC_W
#define my_x KC_X
#define my_y KC_Y
#define my_z KC_Z

#define right_of_lower  esc_ctrl  // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define super LM(_SUPER, MOD_LGUI) //TD(SUPER_WINDOWS)
/* #define super KC_LGUI */
/* #define alt  KC_LALT */
#define alt LM(_ALT, MOD_LALT)
/* #define super TD(SUPER_WINDOWS) */
#define topright _______
/* #include "user_song_list.h" */
/* #define hyper KC_LCTL */
/* #define key_4_12 KC_LCTL */
/* #define my_left_shift KC_LSPO */
/* #define my_right_shift KC_ENTER */

enum unicode_names {
                    BANG,
                    IRONY,
                    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
                                        [BANG]  = 0x203D,  // ‽
                                        [IRONY] = 0x2E2E,  // ⸮
                                        [SNEK]  = 0x1F40D, // 🐍
};

#define snek X(SNEK)

#define super_meta_hyper LM(_MENU, MOD_LGUI | MOD_LCTL | MOD_LALT)

#define all_mods LM(_BOTH, MOD_LGUI | MOD_LCTL | MOD_LALT | MOD_RCTL | MOD_LSFT)

#define scroll_next my_lower_u
#define scroll_prev my_lower_i
#define next_win_or_frame RALT(RSFT(KC_N))
#define prev_win_or_frame RALT(RSFT(KC_P))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12(
                             top_left,    my_q,    my_w,    my_e,    my_r,    my_t, KC_TAB,    my_y,           my_u,    my_i,    my_o,     my_p,
                             my_lctl , my_a,   my_s,   my_d,   my_f,   my_g, KC_BSPACE,  my_h,         my_j,   my_k,   my_l,   my_semicolon,
                             my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b, esc_ctrl,     my_n,   my_m,   my_comma,   my_period,   my_forward_slash,
                             hyper, super_meta_hyper , all_mods , alt, RAISE,  super, esc_ctrl,   my_space,           LOWER,          key_4_10,   key_4_11,  key_4_12
                              ),


[_LOWER] = LAYOUT_ortho_4x12(
                             KC_AUDIO_MUTE,   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,   _______,  KC_HOME,     my_lower_u,    my_lower_i,      my_lower_o,         my_lower_p,
                              _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          _______, KC_DEL,      KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi,
                              _______,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, KC_GRV,  my_lower_n, my_lower_m, my_lower_comma,   my_lower_period, my_lower_slash,
                              _______, _______, _______ , _______, MO(_MOUSE),  _______ ,           _______,         _______, lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12


                              ),

[_RAISE] = LAYOUT_ortho_4x12(
                              LALT(KC_D),    _______,          EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,      _______,  KC_EQL,          my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p,
                              _______, _______, _______,  my_raise_d, my_raise_f,  OSL(_MACROS), KC_DEL,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           raise_semi,
                              _______, _______, _______,_______,   _______,          FISH_ACCEPT_SEND, KC_GRV,     my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           KC_QUES,
                              _______, _______, _______,        _______,        _______, _______,  MO(_ROFI) ,       KC_BSPACE,   raise_key_4_9,       KC_0,  _______,         TO(_BASE)

                              ),

[_HYPER] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
),

/* _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG, */
/* _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    GAUTH_LAYER_ACTIVATE, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______, */
/* KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT, */
/* _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */

// 4
[_BOTH] = LAYOUT_ortho_4x12(
                             _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______,     MO(_MOUSE), _______, _______, _______, _______

                             /* _______, KC_EXECUTE, KC_HELP, KC_MENU, KC_SELECT,KC_CANCEL,   KC_SEPARATOR, _______, KC_CRSEL, KC_EXSEL	, KC_CALCULATOR, QK_MAKE, */
                             /* _______, KC_STOP, KC_AGAIN, KC_UNDO, KC_FIND , KC_PRIOR,   _______, _______, BL_INC, BL_DEC, BL_TOGG, BL_BRTG, */
                             /* KC_SEPARATOR, KC_CUT, KC_COPY, KC_PASTE, _______, _______, _______, _______, MO(_MOUSE), _______, _______, _______, */
                             /* _______, KC_RETURN, KC_CLEAR, KC_CLEAR_AGAIN,   PROGRAMMABLE_BUTTON_1, PROGRAMMABLE_BUTTON_2, _______, _______,     MO(_MOUSE), _______, _______, _______ */

                              ),


// 5
[_SYSTEM] = LAYOUT_ortho_4x12(
                               SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______,     _______, _______, KC_PSTE, KC_AGIN, DEBUG, RESET_ANIMATION, RESET,
                               SYSTEM_LAYER_DEACTIVATE, MO(_AUDIO),_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               KC_ASTG, _______ , _______, _______, _______, MO(_BRIGHTNESS),   _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______,  SYSTEM_LAYER_DEACTIVATE, _______, _______, _______,   SYSTEM_LAYER_DEACTIVATE, _______, _______, _______

                               /* SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET, */
                               /* RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______, */
                               /* KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK, */
                               /* CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
                               ),

// 6
[_WINDOWS] = LAYOUT_ortho_4x12(
                                _______, WINDOWS_Q,   _______,   LGUI(KC_E),     _______,   LGUI(KC_T), LGUI(KC_MINUS),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),
                                RGUI(KC_ESCAPE), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, _______,  LGUI(KC_H),     _______,   windows_k,   windows_l,   _______,
                                TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),    _______, LGUI(KC_MINUS), _______,   LGUI(KC_M),  _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)),
                                _______, _______, _______,         _______,        _______,     _______,   ALT_TAB , LALT(KC_8),      _______,  ALT_TAB, _______, _______
                                ),

// 7
[_MACROS] = LAYOUT_ortho_4x12(
                               _______,   _______, _______, _______, emacs_r, _______, EMACS_GOTO_PARSE_ITEM, _______, EMACS_BACKWARD_UP, _______, EMACS_ANON_FN, _______,
                               _______, emacs_a, _______, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, EMACS_GOTO_GET_FEED,  _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,     EMACS_COMMENT_READER,
                               _______, _______, _______, EMACS_YAS_C,     _______, _______, EMACS_GOTO_SYNC_FEED, _______, emacs_m,     _______, _______, TERM_CD_UP_DIR,
                               _______, _______, _______, _______, _______, _______, KC_NO,          _______, _______, _______, _______, _______
                              ),

// 8
[_SHIFTLOCK] = LAYOUT_ortho_4x12(
                                  _______,   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T), _______,    RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P),
                                  ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G), _______,    my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     _______,
                                  SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B), _______,   RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,
                                  _______, _______, _______, _______, _______, _______, KC_NO,       _______,    LOWER,  _______, _______, _______
                                  ),

// 9
[_WINMOVE] = LAYOUT_ortho_4x12(
                                _______,   _______, _______, _______, _______, _______,  _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)),_______,
                                _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, _______, _______,   RGUI(RSFT(KC_J)),_______,   _______,   _______,
                                _______, _______, _______, KC_F11, _______, _______,  _______, RGUI(RSFT(KC_N)), _______, _______, RGUI(RSFT(KC_DOT)),_______,
                                _______, _______, _______, _______, TO(0),          _______,  _______,         _______,   _______,   _______,    _______, _______
                                ),

// 10
[_ALT] = LAYOUT_ortho_4x12(
                            _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                            ),


// 11
[_SUPER] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,    KC_TILD, KC_GRV,  _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,    LSFT(KC_TAB), KC_TAB,  _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______

                              ),


// 12
[_EDITING] = LAYOUT_ortho_4x12(
                                _______, _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,     _______, _______, EMACS_COPY_FILE_PATH, scroll_next,     scroll_prev, EMACS_OTHER_WINDOW, EMACS_PROJECTILE_FIND_FILE,
                                _______, _______, _______, _______, RALT(KC_ENTER), _______, _______, RALT(RSFT(KC_H)), RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)), EMACS_COMMENT_READER,
                                _______, _______, _______, EMACS_WINDOW_CLOSE,    KC_F12, _______, _______,  next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  _______, _______, TERM_CD_UP_DIR,
                                _______, _______, _______, _______, KC_HYPR,  _______, _______,  KC_NO,          KC_LCTL, _______, _______, _______

                                ),

[_ROFI] = LAYOUT_ortho_4x12(
                             _______, _______, _______, _______, _______,    _______, _______, _______, LALT(KC_7), LALT(KC_8), LALT(KC_9), _______,
                             _______, _______, _______, _______, _______,   _______, _______, _______, LALT(KC_4), LALT(KC_5), LALT(KC_6),_______,
                             _______, _______, _______, _______, _______, _______, _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3),_______,
                             _______, _______, _______,    _______, _______, _______, TO(_BASE), RALT(RGUI(KC_SPC)),    _______, _______, _______,_______
                             ),

[_MENU] = LAYOUT_ortho_4x12(
                                _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                ),


[_CTRL] = LAYOUT_ortho_4x12(
                             _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                 ),

[_MOUSE] = LAYOUT_ortho_4x12(
                              TO(_BASE),   _______, _______, KC_MS_UP,       _______, _______, _______,  KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______,
                              _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    TO(_GAUTH), _______,  KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______,
                              SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______, _______,  LALT(LGUI(KC_N)), KC_MS_BTN3,     _______,   _______,   TO(_BOTH),
                              _______, _______, _______, _______, MO(_EXTENDED), _______,  _______,  _______, TO(_BASE),          _______, _______, _______

                                ),

/* [_COLORS] = LAYOUT_ortho_4x12( */
/*                                _______,   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54), */
/*                                ESC_THEN_BASE_LAYER,          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     my_cap_h,     my_cap_j,     my_cap_k,     my_cap_l,     TD(DANCE_55),   TD(DANCE_56), */
/*                                SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE, */
/*                                RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,    RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, _______,    RGBLIGHT_MODE_STATIC_LIGHT, _______, _______, _______ */

/*                                ), */


[_LAYER17] = LAYOUT_ortho_4x12(
                                _______, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR,         KC_PERC,        KC_CIRC,        KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                ),
[_LAYER18] = LAYOUT_ortho_4x12(
                                _______, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, EMACS_SEL_7,    EMACS_SEL_8,           EMACS_SEL_9,           EMACS_SEL_0,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, EMACS_SEL_4,           EMACS_SEL_5,           EMACS_SEL_6, KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  EMACS_SEL_0,           EMACS_SEL_1,           EMACS_SEL_2,           EMACS_SEL_3, KC_TRANSPARENT,
                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
                                ),



[_GAUTH] = LAYOUT_ortho_4x12(
                                 TO(_BASE), _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______,
                                 _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                 ),

/* [_GAUTH] = LAYOUT_ortho_4x12( */
/*                               _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, gauth_plex, */
/*                               _______, _______, _______, _______,  gauth_fb,   gauth_gh, _______, gauth_hb, _______, _______, gauth_lp, _______, */
/*                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*                               _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______ */
/*                               ), */

[_AUDIO] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, KC_MEDIA_PREV_TRACK,
                              _______, _______, _______, _______, _______, _______,  _______,  KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______,
                              _______, _______, _______, _______, _______, _______,  _______, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,  _______,_______,_______,
                              _______, _______, _______, _______,    _______, _______,  _______, KC_MEDIA_PLAY_PAUSE,    _______, _______, _______,   _______
                              ),
[_BRIGHTNESS] = LAYOUT_ortho_4x12(
                                   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______,  _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP, _______,   _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                                   ),

[_ADHOC_SET_HOTKEY] = LAYOUT_ortho_4x12(
                                         _______, LCTL(RALT(RGUI(KC_Y))), LCTL(RALT(RGUI(KC_W))), _______, LCTL(RALT(RGUI(KC_R))), _______, _______,  LCTL(RALT(RGUI(KC_Y))),_______, _______, _______, _______,
                                         _______, _______, _______, _______, _______, LCTL(RALT(RGUI(KC_G))), _______,  _______, LCTL(RALT(RGUI(KC_J))), LCTL(RALT(RGUI(KC_K))), LCTL(RALT(RGUI(KC_L))), _______,
                                         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                         _______, _______, _______, _______,    _______, _______, _______, LCTL(RALT(RGUI(KC_N))),    _______, _______, _______,  _______
                                         ),
[_DIAMOND] = LAYOUT_ortho_4x12(
                              _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______
                              ),




  };



/* bool muse_mode = false; */
/* uint8_t last_muse_note = 0; */
/* uint16_t muse_counter = 0; */
/* uint8_t muse_offset = 70; */
/* uint16_t muse_tempo = 50; */

/* bool encoder_update_user(uint8_t index, bool clockwise) { */
/*   if (muse_mode) { */
/*     if (IS_LAYER_ON(_RAISE)) { */
/*       if (clockwise) { */
/*         muse_offset++; */
/*       } else { */
/*         muse_offset--; */
/*       } */
/*     } else { */
/*       if (clockwise) { */
/*         muse_tempo+=1; */
/*       } else { */
/*         muse_tempo-=1; */
/*       } */
/*     } */
/*   } else { */
/*     if (clockwise) { */
/*       register_code(KC_PGDN); */
/*       unregister_code(KC_PGDN); */
/*     } else { */
/*       register_code(KC_PGUP); */
/*       unregister_code(KC_PGUP); */
/*     } */
/*   } */
/*   return true; */
/* } */



/* #include "../../../../common/combos.c" */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    return true;
  case KC_LCBR:
    return true;
  default:
    return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    register_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;

  case KC_LCBR:
    register_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    register_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    register_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;


  default:
    if (shifted) {
      add_weak_mods(MOD_BIT(KC_LSFT));
    }
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    register_code16(keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
  case KC_LPRN:
    unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
    break;
  case KC_LCBR:
    unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
    break;

  case KC_LBRACKET:
    unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
    break;

  case KC_TAB:
    unregister_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
    break;

  default:
    // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
    // The IS_RETRO check isn't really necessary here, always using
    // keycode & 0xFF would be fine.
    unregister_code16(keycode);
  }
}

/* void oneshot_mods_changed_user(uint8_t mods) { */
/*   if (mods & MOD_MASK_SHIFT) { */
/*     /\* println("Oneshot mods SHIFT"); *\/ */
/*     static_kinda_dim(HSV_RED); */
/*   } */
/*   if (mods & MOD_MASK_CTRL) { */
/*     static_kinda_dim(HSV_YELLOW); */

/*     println("Oneshot mods CTRL"); */
/*   } */
/*   if (mods & MOD_MASK_ALT) { */
/*     println("Oneshot mods ALT"); */
/*   } */
/*   if (mods & MOD_MASK_GUI) { */
/*     println("Oneshot mods GUI"); */
/*   } */
/*   if (!mods) { */
/*     rgblight_disable(); */

/*     println("Oneshot mods off"); */
/*   } */
/* } */
