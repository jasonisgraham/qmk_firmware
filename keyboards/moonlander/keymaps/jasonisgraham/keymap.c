#include QMK_KEYBOARD_H
#include "version.h"
#include "muse.h"
#include "user_song_list.h"

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

#define max_buffer RALT(KC_ENTER)


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

#define my_lower_j KC_DOWN
#define my_lower_i KC_PGDOWN
#define my_lower_k KC_UP
#define my_lower_o KC_PGUP
#define my_lower_m KC_M
#define my_lower_k KC_UP

#define my_raise_j KC_4
#define my_raise_i KC_8
#define my_raise_k KC_5
#define my_raise_o KC_9
#define my_raise_m KC_1
#define my_raise_u  KC_7
#define my_raise_h KC_BSPACE


#define my_a KC_A
#define my_b KC_B
#define my_comma TD(T_COMMA_H_LTHAN_TH_AT)
#define my_c KC_C
#define my_d KC_D
#define my_e KC_E
#define my_f KC_F
#define my_forward_slash TD(T_FS_H_QU_DT_BS_TH_PIPE)
#define my_g KC_G
#define my_h KC_H
#define my_i TD(T_I_TH_ASTR)
#define my_j TD(T_J_TH_DLR)
#define my_k TD(T_K_TH_AMP)
#define my_l TD(T_L_TH_CIRC)
#define my_left_shift KC_LSFT
#define my_lower MO(_LOWER)
#define my_m TD(T_M_TH_EXLAM)
#define my_minus TD(T_MINUS_TH_PLUS)
#define my_n KC_N
#define my_o TD(T_O_TH_LPRN)
#define my_p TD(T_P_TH_RPRN)
#define my_period TD(T_PERIOD_H_GTHAN_TH_HASH)
#define my_q KC_Q
#define backspace KC_BSPACE

#define right_of_lower backspace
#define my_right_of_lower right_of_lower
#define my_right_shift KC_RSFT
#define my_r KC_R
#define my_s KC_S
#define my_t KC_T
#define my_semicolon TD(T_SEMI_H_COLON_DT_LSBR_TH_LCBR)
#define my_singlequote TD(T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR)
#define my_space KC_SPACE
#define my_u TD(T_U_TH_AMPR)
  #define my_v KC_V
#define my_w KC_W
#define my_x KC_X
#define my_y KC_Y
#define my_z KC_Z
#define my_space KC_SPACE

#define my_lower_d KC_F7
#define my_lower_f KC_F8

#define my_cap_l RSFT(KC_L)
#define my_cap_k RSFT(KC_K)
#define my_cap_j RSFT(KC_J)

#define topright my_minus
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))



// #include "../../../common/keymap.c"

  enum layers {_BASE,
               _LOWER,
               _RAISE,
               _MOUSE,
               _SYSTEM,
               _WINDOWS,
               _MACROS,
               _SHIFTLOCK,
               _WINMOVE,
               _META,
               _SUPER,
               _EDITING,
               _SYMBOLS,
               _EMACS_SEL_BUFFER,
  };


#include "tapdance.c"
#include "../../../common/keycodes.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
                              RCTL(KC_LBRACKET),my_1,           my_2,           my_3,           my_4,           my_5,           MUSIC_LAYER_ACTIVATE,                                 _______, my_6,           my_7,           my_8,           my_9,           my_0,           SHIFTLOCK_LAYER_ACTIVATE,
    TD(T_TAB_H_WINDOWS_DT_TIC_TH_TILDE),    my_q,           my_w,           my_e,           my_r,           my_t,           _______,                                 _______, my_y,           my_u,    my_i,    my_o,    my_p,    my_minus,
    MT(MOD_RCTL, KC_ESCAPE), my_a,           my_s,           my_d,           my_f,           my_g,           OSL(1),                                                                         KC_BSPACE,      my_h,           my_j,    my_k,    my_l,    my_semicolon,    my_singlequote,
    my_left_shift,        my_z,           my_x,           my_c,           my_v,           my_b,                                           my_n,           my_m,   my_comma,   my_period,   my_forward_slash,   my_right_shift,
                              MT(MOD_LCTL, KC_LBRACKET), SYSTEM_LAYER_ACTIVATE,          KC_LGUI,KC_LALT, MO(_RAISE),          KC_RCTRL,                                                                                                       KC_BSPACE,      LOWER,         my_right_of_lower,      LAYER_RAISE_HOLD,          LAYER_LOWER_HOLD,          CYCLE_FAVE_ANIMATIONS,
    KC_BSPACE,      LM(_SUPER,MOD_LGUI),KC_ENTER,                       LM(9,MOD_LALT), LM(_WINDOWS, MOD_LGUI), my_space
  ),
  // lower
  [_LOWER] = LAYOUT_moonlander(
    _______, RCTL(KC_1),     RCTL(KC_2),     RCTL(KC_3),     RCTL(KC_4),     RCTL(KC_5),     TG(3),                                          _______, _______, _______, _______, _______, _______, TD(T_WWW_BACK_TH_WWW_FOR),
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     _______,                                 _______, KC_HOME,        my_lower_o,        my_lower_i,      KC_END,         _______, TD(T_WWW_BACK_TH_WWW_FOR),
    _______, KC_F5,          KC_F6,          my_lower_d,          my_lower_f,          KC_SCROLLLOCK,  TO(0),                                                                          _______, KC_LEFT,        my_lower_j,        my_lower_k,          KC_RIGHT,       _______, _______,
    _______,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,                                 TD(T_N_ALWAYS_LC),   my_lower_m, TD(T_PREV_TAB_TH_MOVE_TAB_LEFT),   TD(T_NEXT_TAB_TH_MOVE_TAB_RIGHT),   KC_DELETE,    SHIFTLOCK_LAYER_ACTIVATE,
    _______, _______, KC_LGUI,        KC_LALT,        TT(3),          _______,                                                                                                 _______, _______, KC_NO,          _______, _______, _______,
    _______, _______, _______,                 _______, _______, TT(3)
  ),
  // raise
  [_RAISE] = LAYOUT_moonlander(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    TD(T_EMACS_COMPLETE_H_BASE),   _______, EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     _______, _______,                                 _______, _______, my_raise_u,           my_raise_i,           my_raise_o,           KC_0,           _______,
    _______, DYN_REC_START1, DYN_MACRO_PLAY1,_______, RALT(KC_ENTER), OSL(6),         _______,                                                                 _______, my_raise_h,      my_raise_j,           my_raise_k,           KC_6,           KC_LBRACKET,    KC_RBRACKET,
    _______, DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   _______, FISH_ACCEPT_SEND,                                     KC_0,           KC_1,           KC_2,           KC_3,           KC_BSLASH,      _______,
    _______, _______, KC_LGUI,        KC_LALT,        _______, _______,                                                                                                 _______, KC_ENTER,       KC_0,           KC_DOT,         _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [_MOUSE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   _______, _______, KC_MS_UP,       _______, _______, _______,                                 _______, KC_HOME,   KC_PGUP,        KC_PGDOWN,      KC_END,         _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,                                                                 _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, KC_MS_BTN3,     RCTL(KC_PGUP),  RCTL(KC_PGDOWN),_______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  //system
  [_SYSTEM] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, RGB_SAD,        RGB_SAI,        WEBUSB_PAIR,    RESET,
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   AU_TOG,         MU_MOD,         MU_TOG,         _______, _______, _______,                                 _______, RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        _______, RESET,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,KC_MEDIA_STOP,  _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    _______, _______, _______, _______, _______, _______,                                                                                                 KC_ASRP, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    _______, _______, _______,                 KC_ASTG,        KC_ASDN,        KC_ASUP
  ),
  // windows
  [_WINDOWS] = LAYOUT_moonlander(KC_GRAVE,       _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,         TD(WIN_ADHOC_Q),   TD(WIN_ADHOC_W),   RGUI(KC_E),     TD(WIN_ADHOC_R),   RGUI(KC_T),     _______,                                 _______, TD(WIN_ADHOC_Y),   RGUI(KC_7),     RGUI(KC_8),     RGUI(KC_9),     RGUI(KC_0),     RGUI(KC_MINUS),
    RGUI(KC_ESCAPE),RGUI(KC_A),     select_slack,     show_desktop,RGUI(KC_F),     TD(WIN_ADHOC_G),   _______,                                                                 _______, RGUI(KC_H),     TD(WIN_ADHOC_J),   TD(WIN_ADHOC_K),   TD(WIN_ADHOC_L),   _______, _______,
                                 _______, RGUI(KC_Z),     RGUI(KC_X),     RGUI(KC_C),     RGUI(KC_V),     _______,                                 TD(WIN_ADHOC_N),   RGUI(KC_M),     TD(T_UP_MON_TH_MAXIMIZE),   _______, KC_GRAVE,       RGUI(RSFT(KC_J)),
    _______, _______, _______, MO(11),         MO(8),          _______,                                                                                                 _______, TD(T_LEFT_MON_TH_TILE_LEFT),   TD(T_DOWN_MON_TH_MINIMIZE),   TD(T_RIGHT_MON_TH_TILE_RIGHT),   KC_TAB,         close_x_window,
    MO(11),         _______, KC_LSHIFT,                      _______, ALT_TAB, KC_NO
  ),
  // macros
  [_MACROS] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, EMACS_YAS_DOC,     EMACS_YAS_TF,     EMACS_INSERT_GET_FEED, _______,                                                                 _______, _______, _______, _______, EMACS_YAS_TL,     _______, _______,
    _______, _______, _______, EMACS_YAS_C,     _______, _______,                                 _______, EMACS_YAS_MAP_ANON,     _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  // shiftlok
  [_SHIFTLOCK] = LAYOUT_moonlander(
                                   _______, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        SHIFTLOCK_LAYER_DEACTIVATE,
    TD(BASE_RETURN_TAP_DANCE),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     _______,                                 _______, RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(T_COMMA_H_LCPR),
    _______, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     _______,                                                                 _______, RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(T_COL_H_LCB),   TD(T_DQT_H_RCB),
                                   SHIFTLOCK_LAYER_DEACTIVATE,          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),                                     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        SHIFTLOCK_LAYER_DEACTIVATE,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  // winmove
  [_WINMOVE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(T_L6_H_L0),   _______, _______, _______, _______, _______, _______,                                 _______, LGUI(LSFT(KC_Y)),_______, _______, LGUI(LSFT(KC_O)),_______, _______,
    _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, _______,                                                                 _______, TD(T_TILE_LEFT_TH_MON_LEFT),   LGUI(LSFT(KC_J)),TD(T_WIN_MAX_TH_F11),   TD(T_TILE_RIGHT_TH_MON_RIGHT),   _______, _______,
    _______, _______, _______, _______, _______, _______,                                 LGUI(LSFT(KC_N)),_______, _______, LGUI(LSFT(KC_DOT)),_______, _______,
    _______, _______, _______, _______, TO(0),          _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [_META] = LAYOUT_moonlander(
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
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),

  // editing
  [_EDITING] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,    _______, _______,                                 _______, EMACS_COPY_FILE_PATH, LCTL(KC_7),     _______, EMACS_OTHER_WINDOW,  _______, _______,
    _______, _______, _______, _______, max_buffer, _______, _______,                                                                 _______, LALT(LSFT(KC_H)),LALT(LSFT(KC_J)),LALT(LSFT(KC_K)),LALT(LSFT(KC_L)),RCTL(KC_SCOLON),RCTL(KC_QUOTE),
    _______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______,                                 RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP, OSL(_SYMBOLS), _______, EMACS_WINDOW_CLOSE,    _______,
    _______, _______, _______, _______, OSL(_EMACS_SEL_BUFFER),_______,                                                                                                  _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
    [_SYMBOLS] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, KC_DLR,         KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,
    _______, _______, _______, _______, _______, _______,                                 _______, KC_EXLM,        KC_AT,          KC_HASH,        KC_LCBR,        KC_RCBR,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [_EMACS_SEL_BUFFER] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, EMACS_SEL_7,           EMACS_SEL_8,           EMACS_SEL_9,           EMACS_SEL_0,           _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, EMACS_SEL_4,           EMACS_SEL_5,           EMACS_SEL_6,           _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, EMACS_SEL_1,           EMACS_SEL_2,           EMACS_SEL_3,           _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
                               ),

};

#include "colors.c"

#include "../../../common/combos.c"
