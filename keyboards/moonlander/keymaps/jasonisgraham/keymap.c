#include QMK_KEYBOARD_H

enum planck_layers {
                    _BASE,
                    _LOWER,
                    _RAISE,
                    _HYPER,
                    _ALL_MODS,
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
#include "../../../common/keycodes.c"
#include "../../../common/key_overrides.c"
#include "../../../common/drop_tapdance.c"
#include "../../../common/layer_lock.h"

#include "muse.h"
#include "user_song_list.h"
#include "keymap_us_international_linux.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

/* #include "keymap_us_extended.h" */
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
                              KC_GRV, my_1,           my_2,           my_3,           my_4,           my_5,           LAYER_LOCK,                                 CAPS_WORD, my_6,           my_7,           my_8,           my_9,           my_0,         backspace,
                              top_left,    my_q,           my_w,           my_e,           my_r,           my_t,           LAYER_LOCK,                                 _______, my_y,           my_u,    my_i,    my_o,    my_p,    KC_MINUS,
    my_lctl, my_a,           my_s,           my_d,           my_f,           my_g,           _______,                                                                         backspace,      my_h,           my_j,    my_k,    my_l,    my_semicolon,    my_singlequote,
                              my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,                                          my_n,           my_m,   my_comma,   my_period,   my_forward_slash,   KC_ENTER,
                              hyper, super_meta_hyper ,      all_mods,   alt,  RAISE,          _______, _______, LOWER,         my_right_of_lower,    key_4_11,          key_4_12, _______,
                              super,  right_of_super, RGB_MODE_FORWARD,                       CYCLE_FAVE_ANIMATIONS, esc_ctrl, my_space
    ),

    // lower
  [_LOWER] = LAYOUT_moonlander(
                               KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
                               KC_AUDIO_MUTE,   KC_F1,          KC_F2,          KC_F3,          my_lower_r,          my_t,     _______,                                 _______,  KC_HOME,        my_lower_u,        my_lower_i,      my_lower_o,         my_lower_p, _______,
    _______, KC_F5,          KC_F6,          my_lower_d,          my_lower_f,          my_lower_g,  _______,                                                                          _______, KC_LEFT,        my_lower_j,        my_lower_k,          my_lower_l,       my_lower_semi, _______,
                               _______,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,   my_lower_n,   my_lower_m, my_lower_comma,   my_lower_period,   my_lower_slash,    _______,
                               SYSTEM_LAYER_ACTIVATE, _______, _______ , alt,   MO(_EDITING), _______,           _______,         lower_LOWER,          lower_right_of_lower, lower_key_4_11, lower_key_4_12, _______,
                               MO(_MOUSE), lower_right_of_super, _______,                 _______, lower_right_of_super, MO(_EXTENDED)
  ),

  // raise
  [_RAISE] = LAYOUT_moonlander(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    LALT(KC_D),    _______,          my_raise_w,  KC_END,         EMACS_BUFFER_REVERT,       _______, _______, _______,            my_raise_y, my_raise_u,           my_raise_i,           my_raise_o,           my_raise_p, _______,
    _______, my_raise_a, my_raise_s,   my_raise_d, my_raise_f,  OSL(_MACROS),_______,   KC_DEL,       my_raise_h,         my_raise_j,           my_raise_k,           my_raise_l,           raise_semi, _______,
    _______, _______, _______,_______,   _______,          _______, my_raise_n,           my_raise_m,           my_raise_comma,         KC_3,           raise_slash, _______,
    SYSTEM_LAYER_ACTIVATE, _______, _______,        _______,        _______, _______,  _______,         raise_key_4_9,       KC_0,  _______,         TO(_BASE), _______,
    lower_right_of_super, _______, _______,                 _______, _______, my_space
  ),

  [_BOTH] = LAYOUT_moonlander(
                              _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, _______,                                                                                                 _______, MO(_MOUSE), _______, _______, _______, _______,
                              _______, _______, _______,                 _______, _______, _______),


  [_HYPER] = LAYOUT_moonlander(
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,                                                                     _______, _______, _______
                             ),


  [_ALL_MODS] = LAYOUT_moonlander(
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,                 _______, _______, _______
                             ),

  //system
  [_SYSTEM] = LAYOUT_moonlander(
                                SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, RGB_SAD,        RGB_SAI,        WEBUSB_PAIR,    RESET,
                                SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, _______, _______,                                 _______, RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        RESET, RESET,
                                SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______, _______, _______,                                                                 _______, RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,KC_MEDIA_STOP,  _______,
                                _______, _______, _______, _______, _______, SYSTEM_LAYER_DEACTIVATE,                                 _______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    _______, _______, _______, _______, _______, _______,                                                                                                 KC_ASRP, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    _______, _______, _______,                 KC_ASTG,        KC_ASDN,        KC_ASUP
  ),


  // windows
  [_WINDOWS] = LAYOUT_moonlander(

                                 KC_GRAVE,       _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                                 TO(_BASE), WINDOWS_Q,   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T), _______, LGUI(KC_MINUS),  LGUI(KC_Y),   LGUI(KC_7),        LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0), LGUI(KC_MINUS),
                                 RALT(RGUI(KC_ESCAPE)), LGUI(KC_A),  select_slack, show_desktop     ,LGUI(KC_F),      _______, _______, TD(DANCE_42),  LGUI(KC_H),     TD(DANCE_43),   windows_k,   windows_l,   _______, _______,
                                 TO(_BASE), LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),    _______,  TD(DANCE_46),   LGUI(KC_M),  _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)), _______,
                                 _______, _______, _______,         _______,        _______,     _______,   _______, _______,      _______,  _______, _______, _______,
                                 LSFT(RCTL(KC_UNDS)),  ALT_TAB , _______,                       _______, _______, LALT(KC_8)
  ),


  // macros
  [_MACROS] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______,   EMACS_RE_FIND, _______, _______, emacs_r, _______, EMACS_GOTO_GET_FEED,                                 _______, _______, EMACS_BACKWARD_UP, _______, _______, EMACS_ANON_FN, _______,
    _______, emacs_a, CD_CSV, EMACS_YAS_DOC,     emacs_f,     EMACS_INSERT_GET_FEED, EMACS_GOTO_PARSE_ITEM,_______, _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL,    EMACS_COMMENT_READER, _______,
    _______, _______, _______, EMACS_YAS_C,     _______, _______,                                 _______, EMACS_YAS_MAP_ANON,     _______, _______, TERM_CD_UP_DIR, _______,
    _______, _______, _______, _______, _______, EMACS_GOTO_SYNC_FEED,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),

  // shiftlok
  [_SHIFTLOCK] = LAYOUT_moonlander(
                                   _______, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        SHIFTLOCK_LAYER_DEACTIVATE,
    _______,   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     _______,                                 _______, RSFT(KC_Y),     RSFT(KC_U),     my_cap_i,     my_cap_o,     RSFT(KC_P),     KC_UNDS,
                                   ESC_THEN_BASE_LAYER, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     _______,                                                                 _______, my_cap_h,     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(DANCE_55), _______,
                                   SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),                                     RSFT(KC_N),     my_cap_m,     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),

  // winmove
  [_WINMOVE] = LAYOUT_moonlander(
                                 _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                                 _______,   _______, _______, _______, _______, _______,  WINDOW_ALWAYS_ON_TOP, _______, RGUI(RSFT(KC_Y)),_______, _______, RGUI(RSFT(KC_O)), _______,_______,
                                 _______, _______, _______, LALT(LGUI(LCTL(RCTL(KC_D)))),_______, _______, _______, _______, winmove_tile_left,   winmove_tile_down, winmove_tile_up ,   winmove_tile_right,   _______,_______,
                                 _______, _______, _______, EMACS_FRAME_FULL_SCREEN, _______, _______,  RGUI(RSFT(KC_N)), _______, winmove_mon_up,  RGUI(RSFT(KC_DOT)),_______,_______,
                                 _______, _______, _______, _______, TO(0),          _______, _______,      winmove_mon_left,   winmove_mon_down,   winmove_mon_right,    _______, _______,
                                 _______, _______, _______,                 _______, _______, _______

                                 ),
  [_ALT] = LAYOUT_moonlander(
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,                 _______, _______, _______
                             ),

  [_SUPER] = LAYOUT_moonlander(
                               _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, LSFT(KC_TAB), KC_TAB,
                               _______, _______, _______,                 _______, _______, _______
                               ),


  [_ROFI] = LAYOUT_moonlander(
                              TO(_BASE),_______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
                              TO(_BASE),_______, _______, _______, _______, _______, _______,                      _______, _______, LALT(KC_7), LALT(KC_8), LALT(KC_9), _______, _______,
                              _______, _______, _______, _______, _______, _______, _______,                       _______, _______, LALT(KC_4), LALT(KC_5), LALT(KC_6), _______, _______,
                              _______, _______, _______, _______, _______, _______, _______,                       _______, _______, LALT(KC_1), LALT(KC_2), LALT(KC_3), _______, _______,
                              _______, _______, _______, _______,  TO(_BASE),                                                                                                 TO(_BASE),_______, _______, _______, _______,
                              _______, _______, TO(_BASE),                 TO(_BASE), _______, RALT(RGUI(KC_SPC))
                              ),

  // editing
  [_EDITING] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                                                     _______, _______, _______, _______, _______, _______, _______,
    _______, EMACS_DESC_KEY, LCTL(KC_7),     LCTL(KC_E), EMACS_HELM_MARK_RINGS,     EMACS_TRANSPOSE, _______,                          EMACS_BACKWARD_UP, EMACS_YANK_IN_SEXP  , scroll_next,     scroll_prev, EMACS_HELM_OCCUR, EMACS_PROJECTILE_FIND_FILE, _______,
    _______, _______, EMACS_LOCCUR, EMACS_KILL_IN_SEXP, RALT(KC_ENTER), EMACS_COPY_FILE_PATH, _______,                                 EMACS_SCROLL_UP, RALT(RSFT(KC_H)), editing_j, editing_k, editing_l, EMACS_COMMENT_READER, _______,
    _______, _______, _______, EMACS_WINDOW_CLOSE,    KC_F12, _______,                                                                 next_win_or_frame, EMACS_ACE_WINDOW_SWAP,  emacs_buffer_stack_down, emacs_buffer_stack_up, TERM_CD_UP_DIR, _______,
    _______, _______, _______, _______, KC_HYPR,  _______,                                                                             all_mods, _______, _______,  _______, _______, _______,
    _______, _______, _______,                                                                                                         _______, _______, _______

  ),


  [_MOUSE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, _______, KC_MS_UP,       _______, _______, _______,                                 _______, KC_HOME,   KC_PGUP,        KC_PGDOWN,      KC_END,         _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,                                                                 _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, KC_MS_BTN3,     RCTL(KC_PGUP),  RCTL(KC_PGDOWN), _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),


  [_AUDIO] = LAYOUT_moonlander(
                                 _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, _______,
                                 _______, _______, _______, _______, _______, _______,  _______, _______,  KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______,_______,
                                 _______, _______, _______, _______, _______, _______,  KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,  _______,_______,_______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______),

};

/* #include "colors.c" */

#include "../../../common/combos.c"
#include "../../../common/autoshift.c"
