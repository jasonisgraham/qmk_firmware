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

enum tap_dance_codes {T_TAB_H_WINDOWS_DT_TIC_TH_TILDE,
                      T_U_TH_AMPR,
                      T_I_TH_ASTR,
                      T_O_TH_LPRN,
                      T_P_TH_RPRN,
                      T_MINUS_TH_PLUS,
                      T_J_TH_DLR,
                      T_K_TH_AMP,
                      T_L_TH_CIRC,
                      T_SEMI_H_COLON_DT_LSBR_TH_LCBR,
                      T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR,
                      T_M_TH_EXLAM,
                      T_COMMA_H_LTHAN_TH_AT,
                      T_PERIOD_H_GTHAN_TH_HASH,
                      T_FS_H_QU_DT_BS_TH_PIPE,
                      T_WWW_BACK_TH_WWW_FOR,
                      T_N_ALWAYS_LC,
                      T_PREV_TAB_TH_MOVE_TAB_LEFT,
                      T_NEXT_TAB_TH_MOVE_TAB_RIGHT,
                      T_EMACS_COMPLETE_H_BASE,
                      T_TAB_H_BASE_DT_TIC_TH_TILDE,
                      WIN_ADHOC_Q,
                      WIN_ADHOC_W,
                      WIN_ADHOC_R,
                      WIN_ADHOC_G,
                      WIN_ADHOC_Y,
                      WIN_ADHOC_J,
                      WIN_ADHOC_K,
                      WIN_ADHOC_L,
                      WIN_ADHOC_N,
                      T_DOWN_MON_TH_MINIMIZE,
                      T_LEFT_MON_TH_TILE_LEFT,
                      T_DOWN_MON_TH_MINIMIZE,
                      T_RIGHT_MON_TH_TILE_RIGHT,
                      T_TAB_H_BASE_DT_TIC_TH_TILDE,
                      BASE_RETURN_TAP_DANCE,
                      T_COMMA_H_LCPR,
                      T_COL_H_LCB,
                      T_DQT_H_RCB,
                      T_L6_H_L0,
                      T_TILE_LEFT_TH_MON_LEFT,
                      T_WIN_MAX_TH_F11,
                      T_TILE_RIGHT_TH_MON_RIGHT,
};

#define close_x_window RSFT(RGUI(KC_Q))

#define my_comma TD(T_COMMA_H_LTHAN_TH_AT)
#define my_d KC_D
#define my_e KC_E
#define my_f KC_F
#define my_forward_slash TD(T_FS_H_QU_DT_BS_TH_PIPE)
#define my_h KC_H
#define my_i TD(T_I_TH_ASTR)
#define my_j TD(T_J_TH_DLR)
#define my_k TD(T_K_TH_AMP)
#define my_l TD(T_L_TH_CIRC)
#define my_left_shift KC_LSFT
#define my_lower MO(1)
#define my_m TD(T_M_TH_EXLAM)
#define my_minus TD(T_MINUS_TH_PLUS)
#define my_n KC_N
#define my_o TD(T_O_TH_LPRN)
#define my_p TD(T_P_TH_RPRN)
#define my_period TD(T_PERIOD_H_GTHAN_TH_HASH)
#define my_right_of_lower KC_BSPACE
#define my_right_shift KC_RSFT
#define my_s KC_S
#define my_semicolon TD(T_SEMI_H_COLON_DT_LSBR_TH_LCBR)
#define my_single_quote TD(T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR)
#define my_space KC_SPACE
#define my_u TD(T_U_TH_AMPR)
#define my_w KC_W


// #include "../../../common/keymap.c"

  enum layers {_BASE,
               _LOWER,
               _RAISE,
               _MOUSE,
               _SYSTEM,
               _WINDOWS,
               _MACROS,
               _SHIFTLOK,
               _WINMOVE,
               _META,
               _SUPER,
               _EDITING,
               _SYMBOLS,
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
                              RCTL(KC_LBRACKET),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           MUSIC_LAYER_ACTIVATE,                                 _______, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    TD(T_TAB_H_WINDOWS_DT_TIC_TH_TILDE),    KC_Q,           my_w,           my_e,           KC_R,           KC_T,           _______,                                 _______, KC_Y,           my_u,    my_i,    my_o,    my_p,    my_minus,
    MT(MOD_RCTL, KC_ESCAPE),KC_A,           my_s,           my_d,           my_f,           KC_G,           OSL(1),                                                                         KC_BSPACE,      my_h,           my_j,    my_k,    my_l,    my_semicolon,    my_single_quote,
    my_left_shift,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           my_n,           my_m,   my_comma,   my_period,   my_forward_slash,   my_right_shift,
                              MT(MOD_LCTL, KC_LBRACKET), SYSTEM_LAYER_ACTIVATE,          KC_LGUI,KC_LALT, MO(_RAISE),          KC_RCTRL,                                                                                                       KC_BSPACE,      my_lower,         my_right_of_lower,      TT(2),          TT(1),          KC_ENTER,
    KC_BSPACE,      LM(_SUPER,MOD_LGUI),KC_ENTER,                       LM(9,MOD_LALT), LM(_WINDOWS, MOD_LGUI), my_space
  ),
  // lower
  [_LOWER] = LAYOUT_moonlander(
    _______, RCTL(KC_1),     RCTL(KC_2),     RCTL(KC_3),     RCTL(KC_4),     RCTL(KC_5),     TG(3),                                          _______, _______, _______, _______, _______, _______, TD(T_WWW_BACK_TH_WWW_FOR),
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     _______,                                 _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, TD(T_WWW_BACK_TH_WWW_FOR),
    _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_SCROLLLOCK,  TO(0),                                                                          _______, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______,
    _______,   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,                                 TD(T_N_ALWAYS_LC),   _______, TD(T_PREV_TAB_TH_MOVE_TAB_LEFT),   TD(T_NEXT_TAB_TH_MOVE_TAB_RIGHT),   KC_DELETE,    SHIFTLOK_LAYER_ACTIVATE,
    _______, _______, KC_LGUI,        KC_LALT,        TT(3),          _______,                                                                                                 _______, _______, KC_NO,          _______, _______, _______,
    _______, _______, _______,                 _______, _______, TT(3)
  ),
  // raise
  [_RAISE] = LAYOUT_moonlander(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    TD(T_EMACS_COMPLETE_H_BASE),   _______, EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     _______, _______,                                 _______, _______, KC_7,           KC_8,           KC_9,           KC_0,           _______,
    _______, DYN_REC_START1, DYN_MACRO_PLAY1,_______, RALT(KC_ENTER), OSL(6),         _______,                                                                 _______, KC_BSPACE,      KC_4,           KC_5,           KC_6,           KC_LBRACKET,    KC_RBRACKET,
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
    TD(T_TAB_H_BASE_DT_TIC_TH_TILDE),   AU_TOG,         MU_MOD,         MU_TOG,         _______, _______, _______,                                 _______, RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,KC_MEDIA_STOP,  _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    _______, _______, _______, _______, _______, _______,                                                                                                 KC_ASRP, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    _______, _______, _______,                 KC_ASTG,        KC_ASDN,        KC_ASUP
  ),
  // windows
  [_WINDOWS] = LAYOUT_moonlander(KC_GRAVE,       _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,         TD(WIN_ADHOC_Q),   TD(WIN_ADHOC_W),   RGUI(KC_E),     TD(WIN_ADHOC_R),   RGUI(KC_T),     _______,                                 _______, TD(WIN_ADHOC_Y),   RGUI(KC_7),     RGUI(KC_8),     RGUI(KC_9),     RGUI(KC_0),     RGUI(KC_MINUS),
    RGUI(KC_ESCAPE),RGUI(KC_A),     RGUI(KC_S),     LALT(LGUI(LCTL(KC_D))),RGUI(KC_F),     TD(WIN_ADHOC_G),   _______,                                                                 _______, RGUI(KC_H),     TD(WIN_ADHOC_J),   TD(WIN_ADHOC_K),   TD(WIN_ADHOC_L),   _______, _______,
    _______, RGUI(KC_Z),     RGUI(KC_X),     RGUI(KC_C),     RGUI(KC_V),     _______,                                 TD(WIN_ADHOC_N),   RGUI(KC_M),     TD(T_DOWN_MON_TH_MINIMIZE),   _______, KC_GRAVE,       RGUI(RSFT(KC_J)),
    _______, _______, _______, MO(11),         MO(8),          _______,                                                                                                 _______, TD(T_LEFT_MON_TH_TILE_LEFT),   TD(T_DOWN_MON_TH_MINIMIZE),   TD(T_RIGHT_MON_TH_TILE_RIGHT),   KC_TAB,         close_x_window,
    MO(11),         _______, KC_LSHIFT,                      _______, _______, KC_NO
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
  [_SHIFTLOK] = LAYOUT_moonlander(
    _______, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    TD(BASE_RETURN_TAP_DANCE),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     _______,                                 _______, RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(T_COMMA_H_LCPR),
    _______, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     _______,                                                                 _______, RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(T_COL_H_LCB),   TD(T_DQT_H_RCB),
    TO(0),          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),                                     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        TO(0),
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
    _______, _______, EMACS_OTHER_WINDOW,     _______, EMACS_BUFFER_REVERT,    _______, _______,                                 _______, _______, LCTL(KC_7),     _______, EMACS_OTHER_WINDOW,  _______, _______,
    _______, _______, _______, _______, max_buffer, _______, _______,                                                                 _______, LALT(LSFT(KC_H)),LALT(LSFT(KC_J)),LALT(LSFT(KC_K)),LALT(LSFT(KC_L)),RCTL(KC_SCOLON),RCTL(KC_QUOTE),
    _______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______,                                 RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP, OSL(_SYMBOLS), _______, EMACS_WINDOW_CLOSE,    _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
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

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = { {0,0,0}, {167,255,255}, {0,0,0}, {82,255,255}, {0,0,0},
                 {43,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0},
                 {43,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {42,255,255},
                 {43,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {42,255,255},
                 {43,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255},
                 {43,255,255}, {74,255,255}, {41,255,255}, {74,255,255},
                 {86,255,255}, {0,0,0}, {152,255,255},

                 {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {88,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {152,255,255}, {0,245,245}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {0,245,245}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_RAISE] = { {41,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {41,255,255}, {129,255,255}, {74,255,255}, {74,255,255}, {42,255,255}, {41,255,255}, {167,255,255}, {0,0,0}, {0,245,245}, {42,255,255}, {41,255,255}, {0,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {74,255,255}, {167,242,168}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {167,255,255}, {41,255,255}, {0,0,0}, {0,245,245}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MOUSE] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {74,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {218,255,255}, {41,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {218,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYSTEM] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,189,255}, {0,0,0}, {0,0,0}, {234,255,255}, {219,255,255}, {152,255,255}, {0,0,0}, {234,255,255}, {234,255,255}, {219,255,255}, {41,255,255}, {41,255,255}, {129,255,255}, {234,255,255}, {219,255,255}, {41,255,255}, {41,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0} },

    [_WINDOWS] = { {131,255,255}, {131,255,255}, {42,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {189,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {167,255,255}, {152,255,255}, {197,255,255}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {82,255,255}, {0,0,0}, {152,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {41,255,255}, {0,255,255}, {0,0,0}, {152,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {0,0,0}, {152,255,255}, {210,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {152,255,255}, {210,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {152,255,255}, {210,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {219,255,255}, {152,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MACROS] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SHIFTLOK] = { {0,0,0}, {167,255,255}, {0,0,0}, {167,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {42,255,255}, {42,255,255}, {170,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {42,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_WINMOVE] = { {0,0,0}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {27,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_META] = { {0,0,0}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {139,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {42,255,255}, {0,255,255}, {42,255,255}, {170,255,255}, {42,255,255}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {170,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {0,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {139,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255} },

    [_SUPER] = { {175,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {129,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {129,255,255} },

    [_EDITING] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {81,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {27,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {89,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {82,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYMBOLS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  /* if (g_suspend_state || keyboard_config.disable_layer_led) { return; } */
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
    case 10:
      set_layer_color(10);
      break;
    case 11:
      set_layer_color(11);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}


/* float zelda_tune[][2] = SONG(zelda); */
float lp_numb[][2] =  SONG(LP_NUMB);
float ode_to_joy[][2] =  SONG(ODE_TO_JOY);
float rock_a_bye_baby[][2] =  SONG(ROCK_A_BYE_BABY);
float close_encounters_5_note[][2] =  SONG(CLOSE_ENCOUNTERS_5_NOTE);
float doe_a_deer[][2] =  SONG(DOE_A_DEER);
float in_like_flint[][2] =  SONG(IN_LIKE_FLINT);
float imperial_march[][2] =  SONG(IMPERIAL_MARCH);
float clueboard_sound[][2] =  SONG(CLUEBOARD_SOUND);
float basket_case[][2] =  SONG(BASKET_CASE);
float startup_sound[][2] =  SONG(STARTUP_SOUND);
float goodbye_sound[][2] =  SONG(GOODBYE_SOUND);
float planck_sound[][2] =  SONG(PLANCK_SOUND);
float preonic_sound[][2] =  SONG(PREONIC_SOUND);
float qwerty_sound[][2] =  SONG(QWERTY_SOUND);
float colemak_sound[][2] =  SONG(COLEMAK_SOUND);
float dvorak_sound[][2] =  SONG(DVORAK_SOUND);
float plover_sound[][2] =  SONG(PLOVER_SOUND);
float plover_goodbye_sound[][2] =  SONG(PLOVER_GOODBYE_SOUND);
float music_on_sound[][2] =  SONG(MUSIC_ON_SOUND);
float audio_on_sound[][2] =  SONG(AUDIO_ON_SOUND);
float audio_off_sound[][2] =  SONG(AUDIO_OFF_SOUND);
float music_off_sound[][2] =  SONG(MUSIC_OFF_SOUND);
float voice_change_sound[][2] =  SONG(VOICE_CHANGE_SOUND);
float chromatic_sound[][2] =  SONG(CHROMATIC_SOUND);
float major_sound[][2] =  SONG(MAJOR_SOUND);
float minor_sound[][2] =  SONG(MINOR_SOUND);
float guitar_sound[][2] =  SONG(GUITAR_SOUND);
float violin_sound[][2] =  SONG(VIOLIN_SOUND);
float caps_lock_on_sound[][2] =  SONG(CAPS_LOCK_ON_SOUND);
float caps_lock_off_sound[][2] =  SONG(CAPS_LOCK_OFF_SOUND);
float scroll_lock_on_sound[][2] =  SONG(SCROLL_LOCK_ON_SOUND);
float scroll_lock_off_sound[][2] =  SONG(SCROLL_LOCK_OFF_SOUND);
float num_lock_on_sound[][2] =  SONG(NUM_LOCK_ON_SOUND);
float num_lock_off_sound[][2] =  SONG(NUM_LOCK_OFF_SOUND);
float ag_norm_sound[][2] =  SONG(AG_NORM_SOUND);
float ag_swap_sound[][2] =  SONG(AG_SWAP_SOUND);
float unicode_windows[][2] =  SONG(UNICODE_WINDOWS);
float unicode_linux[][2] =  SONG(UNICODE_LINUX);
float coin_sound[][2] =  SONG(COIN_SOUND);
float one_up_sound[][2] =  SONG(ONE_UP_SOUND);
float sonic_ring[][2] =  SONG(SONIC_RING);
float zelda_puzzle[][2] =  SONG(ZELDA_PUZZLE);
float zelda_treasure[][2] =  SONG(ZELDA_TREASURE);
float terminal_sound[][2] =  SONG(TERMINAL_SOUND);
float overwatch_theme[][2] =  SONG(OVERWATCH_THEME);
float mario_theme[][2] =  SONG(MARIO_THEME);
float mario_gameover[][2] =  SONG(MARIO_GAMEOVER);
float mario_mushroom[][2] =  SONG(MARIO_MUSHROOM);
float e1m1_doom[][2] =  SONG(E1M1_DOOM);
float disney_song[][2] =  SONG(DISNEY_SONG);
float number_one[][2] =  SONG(NUMBER_ONE);
float cabbage_song[][2] =  SONG(CABBAGE_SONG);
float old_spice[][2] =  SONG(OLD_SPICE);
float victory_fanfare_short[][2] =  SONG(VICTORY_FANFARE_SHORT);
float all_star[][2] =  SONG(ALL_STAR);
float rick_roll[][2] =  SONG(RICK_ROLL);
float ff_prelude[][2] =  SONG(FF_PRELUDE);
float to_boldly_go[][2] =  SONG(TO_BOLDLY_GO);

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[49];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_t_tab_h_windows_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_windows_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_windows_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tab_h_windows_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_tab_h_windows_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_tab_h_windows_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_off(5); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}
void on_t_u_th_ampr(qk_tap_dance_state_t *state, void *user_data);
void t_u_th_ampr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_u_th_ampr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_u_th_ampr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void t_u_th_ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_HOLD: register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void t_u_th_ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_HOLD: unregister_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[1].step = 0;
}
void on_t_i_th_astr(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_i_th_astr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void t_i_th_astr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void t_i_th_astr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_HOLD: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[2].step = 0;
}
void on_t_o_th_lprn(qk_tap_dance_state_t *state, void *user_data);
void t_o_th_lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void t_o_th_lprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_o_th_lprn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void t_o_th_lprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_HOLD: register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void t_o_th_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_HOLD: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[3].step = 0;
}
void on_t_p_th_rprn(qk_tap_dance_state_t *state, void *user_data);
void t_p_th_rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void t_p_th_rprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_p_th_rprn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void t_p_th_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void t_p_th_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_P)); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[4].step = 0;
}
void on_t_minus_th_plus(qk_tap_dance_state_t *state, void *user_data);
void t_minus_th_plus_finished(qk_tap_dance_state_t *state, void *user_data);
void t_minus_th_plus_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_minus_th_plus(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void t_minus_th_plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void t_minus_th_plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[5].step = 0;
}
void on_t_j_th_dlr(qk_tap_dance_state_t *state, void *user_data);
void t_j_th_dlr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_j_th_dlr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_j_th_dlr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void t_j_th_dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_J)); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_HOLD: register_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void t_j_th_dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_HOLD: unregister_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[6].step = 0;
}
void on_t_k_th_amp(qk_tap_dance_state_t *state, void *user_data);
void t_k_th_amp_finished(qk_tap_dance_state_t *state, void *user_data);
void t_k_th_amp_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_k_th_amp(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void t_k_th_amp_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void t_k_th_amp_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_HOLD: unregister_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[7].step = 0;
}
void on_t_l_th_circ(qk_tap_dance_state_t *state, void *user_data);
void t_l_th_circ_finished(qk_tap_dance_state_t *state, void *user_data);
void t_l_th_circ_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_l_th_circ(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void t_l_th_circ_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_L)); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_HOLD: register_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void t_l_th_circ_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_HOLD: unregister_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state[8].step = 0;
}
void on_t_semi_h_colon_dt_lsbr_th_lcbr(qk_tap_dance_state_t *state, void *user_data);
void t_semi_h_colon_dt_lsbr_th_lcbr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_semi_h_colon_dt_lsbr_th_lcbr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_semi_h_colon_dt_lsbr_th_lcbr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
    }
    if(state->count > 3) {
        tap_code16(KC_SCOLON);
    }
}

void t_semi_h_colon_dt_lsbr_th_lcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_SCOLON); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
    }
}

void t_semi_h_colon_dt_lsbr_th_lcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_SCOLON); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCOLON); break;
    }
    dance_state[9].step = 0;
}
void on_t_squote_h_dquote_dt_rsbr_th_rcbr(qk_tap_dance_state_t *state, void *user_data);
void t_squote_h_dquote_dt_rsbr_th_rcbr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_squote_h_dquote_dt_rsbr_th_rcbr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_squote_h_dquote_dt_rsbr_th_rcbr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void t_squote_h_dquote_dt_rsbr_th_rcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_DQUO); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void t_squote_h_dquote_dt_rsbr_th_rcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(KC_DQUO); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[10].step = 0;
}
void on_t_m_th_exlam(qk_tap_dance_state_t *state, void *user_data);
void t_m_th_exlam_finished(qk_tap_dance_state_t *state, void *user_data);
void t_m_th_exlam_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_m_th_exlam(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void t_m_th_exlam_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_HOLD: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void t_m_th_exlam_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_HOLD: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state[11].step = 0;
}
void on_t_comma_h_lthan_th_at(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lthan_th_at_finished(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lthan_th_at_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_comma_h_lthan_th_at(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void t_comma_h_lthan_th_at_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_LABK); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_HOLD: register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void t_comma_h_lthan_th_at_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_LABK); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_HOLD: unregister_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[12].step = 0;
}
void on_t_period_h_gthan_th_hash(qk_tap_dance_state_t *state, void *user_data);
void t_period_h_gthan_th_hash_finished(qk_tap_dance_state_t *state, void *user_data);
void t_period_h_gthan_th_hash_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_period_h_gthan_th_hash(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void t_period_h_gthan_th_hash_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_RABK); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_HOLD: register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void t_period_h_gthan_th_hash_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_RABK); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_HOLD: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[13].step = 0;
}
void on_t_fs_h_qu_dt_bs_th_pipe(qk_tap_dance_state_t *state, void *user_data);
void t_fs_h_qu_dt_bs_th_pipe_finished(qk_tap_dance_state_t *state, void *user_data);
void t_fs_h_qu_dt_bs_th_pipe_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_fs_h_qu_dt_bs_th_pipe(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void t_fs_h_qu_dt_bs_th_pipe_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_QUES); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void t_fs_h_qu_dt_bs_th_pipe_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_QUES); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[14].step = 0;
}

void on_t_www_back_th_www_for(qk_tap_dance_state_t *state, void *user_data);
void t_www_back_th_www_for_finished(qk_tap_dance_state_t *state, void *user_data);
void t_www_back_th_www_for_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_www_back_th_www_for(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_LEFT));
    }
}

void t_www_back_th_www_for_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: register_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT));
    }
}

void t_www_back_th_www_for_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: unregister_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
    }
    dance_state[17].step = 0;
}
void on_t_n_always_lc(qk_tap_dance_state_t *state, void *user_data);
void t_n_always_lc_finished(qk_tap_dance_state_t *state, void *user_data);
void t_n_always_lc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_n_always_lc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void t_n_always_lc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(KC_N); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_HOLD: register_code16(RSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void t_n_always_lc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(KC_N); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_HOLD: unregister_code16(RSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[18].step = 0;
}
void on_t_prev_tab_th_move_tab_left(qk_tap_dance_state_t *state, void *user_data);
void t_prev_tab_th_move_tab_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_prev_tab_th_move_tab_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_prev_tab_th_move_tab_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGUP));
    }
}

void t_prev_tab_th_move_tab_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
    }
}

void t_prev_tab_th_move_tab_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
    }
    dance_state[19].step = 0;
}
void on_t_next_tab_th_move_tab_right(qk_tap_dance_state_t *state, void *user_data);
void t_next_tab_th_move_tab_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_next_tab_th_move_tab_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_next_tab_th_move_tab_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGDOWN));
    }
}

void t_next_tab_th_move_tab_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
    }
}

void t_next_tab_th_move_tab_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
    }
    dance_state[20].step = 0;
}

void on_t_emacs_complete_h_base(qk_tap_dance_state_t *state, void *user_data);
void t_emacs_complete_h_base_finished(qk_tap_dance_state_t *state, void *user_data);
void t_emacs_complete_h_base_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_emacs_complete_h_base(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_SLASH));
    }
}

void t_emacs_complete_h_base_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(RALT(KC_SLASH)); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH));
    }
}

void t_emacs_complete_h_base_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
    }
    dance_state[22].step = 0;
}
void on_t_i_th_astr3(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr3_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_i_th_astr3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_i_th_astr3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_i_th_astr3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[23].step = 0;
}
void t_i_th_astr4_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr4_reset(qk_tap_dance_state_t *state, void *user_data);

void t_i_th_astr4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
    }
}

void t_i_th_astr4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
    }
    dance_state[24].step = 0;
}
void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[25].step = 0;
}
void on_win_adhoc_q(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_q_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_q(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Q));
    }
}

void win_adhoc_q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q));
    }
}

void win_adhoc_q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
    }
    dance_state[26].step = 0;
}
void on_win_adhoc_w(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_w_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_w_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_w(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_W));
    }
}

void win_adhoc_w_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_W)); register_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_W)); register_code16(RGUI(KC_W));
    }
}

void win_adhoc_w_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
    }
    dance_state[27].step = 0;
}
void on_win_adhoc_r(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_r_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_r_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_r(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_R));
    }
}

void win_adhoc_r_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_R)); register_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_R)); register_code16(RGUI(KC_R));
    }
}

void win_adhoc_r_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
    }
    dance_state[28].step = 0;
}
void on_win_adhoc_g(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_g_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_g_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_g(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_G));
    }
}

void win_adhoc_g_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_G)); register_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_G)); register_code16(RGUI(KC_G));
    }
}

void win_adhoc_g_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
    }
    dance_state[29].step = 0;
}
void on_win_adhoc_y(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_y_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_y(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Y));
    }
}

void win_adhoc_y_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y));
    }
}

void win_adhoc_y_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
    }
    dance_state[30].step = 0;
}
void on_win_adhoc_j(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_j_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_j_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_j(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_J));
    }
}

void win_adhoc_j_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: register_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
    }
}

void win_adhoc_j_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
    }
    dance_state[31].step = 0;
}
void on_win_adhoc_k(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_k_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_k(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_K));
    }
}

void win_adhoc_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_K)); register_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_K)); register_code16(RGUI(KC_K));
    }
}

void win_adhoc_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
    }
    dance_state[32].step = 0;
}
void on_win_adhoc_l(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_l_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_l_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_l(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_L));
    }
}

void win_adhoc_l_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_L)); register_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_L)); register_code16(RGUI(KC_L));
    }
}

void win_adhoc_l_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
    }
    dance_state[33].step = 0;
}
void on_win_adhoc_n(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_n_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_n(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_N));
    }
}

void win_adhoc_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_N)); register_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_N)); register_code16(RGUI(KC_N));
    }
}

void win_adhoc_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
    }
    dance_state[34].step = 0;
}
void on_t_down_mon_th_minimiZe(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimiZe_finished(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimiZe_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_down_mon_th_minimiZe(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_UP)));
        tap_code16(RGUI(RSFT(KC_UP)));
        tap_code16(RGUI(RSFT(KC_UP)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_UP)));
    }
}

void t_down_mon_th_minimiZe_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_UP))); register_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_UP))); register_code16(RGUI(RSFT(KC_UP)));
    }
}

void t_down_mon_th_minimiZe_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
    }
    dance_state[35].step = 0;
}
void on_t_left_mon_th_tile_left(qk_tap_dance_state_t *state, void *user_data);
void t_left_mon_th_tile_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_left_mon_th_tile_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_left_mon_th_tile_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void t_left_mon_th_tile_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void t_left_mon_th_tile_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
    }
    dance_state[36].step = 0;
}
void on_t_down_mon_th_minimize(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimize_finished(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimize_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_down_mon_th_minimize(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimize_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimize_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
    }
    dance_state[37].step = 0;
}
void on_t_right_mon_th_tile_right(qk_tap_dance_state_t *state, void *user_data);
void t_right_mon_th_tile_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_right_mon_th_tile_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_right_mon_th_tile_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void t_right_mon_th_tile_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void t_right_mon_th_tile_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
    }
    dance_state[38].step = 0;
}

void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[40].step = dance_step(state);
    switch (dance_state[40].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[40].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[40].step = 0;
}
void on_base_return_tap_dance(qk_tap_dance_state_t *state, void *user_data);
void base_return_tap_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void base_return_tap_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_base_return_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void base_return_tap_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void base_return_tap_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[41].step = 0;
}
void on_t_comma_h_lcpr(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lcpr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lcpr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_comma_h_lcpr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

void t_comma_h_lcpr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void t_comma_h_lcpr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state[42].step = 0;
}
void on_t_col_h_lcb(qk_tap_dance_state_t *state, void *user_data);
void t_col_h_lcb_finished(qk_tap_dance_state_t *state, void *user_data);
void t_col_h_lcb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_col_h_lcb(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void t_col_h_lcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void t_col_h_lcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[43].step = 0;
}
void on_t_dqt_h_rcb(qk_tap_dance_state_t *state, void *user_data);
void t_dqt_h_rcb_finished(qk_tap_dance_state_t *state, void *user_data);
void t_dqt_h_rcb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_dqt_h_rcb(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void t_dqt_h_rcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void t_dqt_h_rcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[44].step = 0;
}
void t_l6_h_l0_finished(qk_tap_dance_state_t *state, void *user_data);
void t_l6_h_l0_reset(qk_tap_dance_state_t *state, void *user_data);

void t_l6_h_l0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void t_l6_h_l0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
    }
    dance_state[45].step = 0;
}
void on_t_tile_left_th_mon_left(qk_tap_dance_state_t *state, void *user_data);
void t_tile_left_th_mon_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tile_left_th_mon_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tile_left_th_mon_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_H)));
    }
}

void t_tile_left_th_mon_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H)));
    }
}

void t_tile_left_th_mon_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
    }
    dance_state[46].step = 0;
}
void on_t_win_max_th_f11(qk_tap_dance_state_t *state, void *user_data);
void t_win_max_th_f11_finished(qk_tap_dance_state_t *state, void *user_data);
void t_win_max_th_f11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_win_max_th_f11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_K)));
    }
}

void t_win_max_th_f11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K)));
    }
}

void t_win_max_th_f11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
    }
    dance_state[47].step = 0;
}
void on_t_tile_right_th_mon_right(qk_tap_dance_state_t *state, void *user_data);
void t_tile_right_th_mon_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tile_right_th_mon_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tile_right_th_mon_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_L)));
    }
}

void t_tile_right_th_mon_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L)));
    }
}

void t_tile_right_th_mon_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[48].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
    }
    dance_state[48].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [T_TAB_H_WINDOWS_DT_TIC_TH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tab_h_windows_dt_tic_th_tilde, t_tab_h_windows_dt_tic_th_tilde_finished, t_tab_h_windows_dt_tic_th_tilde_reset),
        [T_U_TH_AMPR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_u_th_ampr, t_u_th_ampr_finished, t_u_th_ampr_reset),
        [T_I_TH_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_i_th_astr, t_i_th_astr_finished, t_i_th_astr_reset),
        [T_O_TH_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_o_th_lprn, t_o_th_lprn_finished, t_o_th_lprn_reset),
        [T_P_TH_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_p_th_rprn, t_p_th_rprn_finished, t_p_th_rprn_reset),
        [T_MINUS_TH_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_minus_th_plus, t_minus_th_plus_finished, t_minus_th_plus_reset),
        [T_J_TH_DLR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_j_th_dlr, t_j_th_dlr_finished, t_j_th_dlr_reset),
        [T_K_TH_AMP] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_k_th_amp, t_k_th_amp_finished, t_k_th_amp_reset),
        [T_L_TH_CIRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_l_th_circ, t_l_th_circ_finished, t_l_th_circ_reset),
        [T_SEMI_H_COLON_DT_LSBR_TH_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_semi_h_colon_dt_lsbr_th_lcbr, t_semi_h_colon_dt_lsbr_th_lcbr_finished, t_semi_h_colon_dt_lsbr_th_lcbr_reset),
        [T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_squote_h_dquote_dt_rsbr_th_rcbr, t_squote_h_dquote_dt_rsbr_th_rcbr_finished, t_squote_h_dquote_dt_rsbr_th_rcbr_reset),
        [T_M_TH_EXLAM] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_m_th_exlam, t_m_th_exlam_finished, t_m_th_exlam_reset),
        [T_COMMA_H_LTHAN_TH_AT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_comma_h_lthan_th_at, t_comma_h_lthan_th_at_finished, t_comma_h_lthan_th_at_reset),
        [T_PERIOD_H_GTHAN_TH_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_period_h_gthan_th_hash, t_period_h_gthan_th_hash_finished, t_period_h_gthan_th_hash_reset),
        [T_FS_H_QU_DT_BS_TH_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_fs_h_qu_dt_bs_th_pipe, t_fs_h_qu_dt_bs_th_pipe_finished, t_fs_h_qu_dt_bs_th_pipe_reset),
        [T_WWW_BACK_TH_WWW_FOR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_www_back_th_www_for, t_www_back_th_www_for_finished, t_www_back_th_www_for_reset),
        [T_N_ALWAYS_LC] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_n_always_lc, t_n_always_lc_finished, t_n_always_lc_reset),
        [T_PREV_TAB_TH_MOVE_TAB_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_prev_tab_th_move_tab_left, t_prev_tab_th_move_tab_left_finished, t_prev_tab_th_move_tab_left_reset),
        [T_NEXT_TAB_TH_MOVE_TAB_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_next_tab_th_move_tab_right, t_next_tab_th_move_tab_right_finished, t_next_tab_th_move_tab_right_reset),
        [T_EMACS_COMPLETE_H_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_emacs_complete_h_base, t_emacs_complete_h_base_finished, t_emacs_complete_h_base_reset),
        [T_TAB_H_BASE_DT_TIC_TH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tab_h_base_dt_tic_th_tilde, t_tab_h_base_dt_tic_th_tilde_finished, t_tab_h_base_dt_tic_th_tilde_reset),
        [WIN_ADHOC_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_q, win_adhoc_q_finished, win_adhoc_q_reset),
        [WIN_ADHOC_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_w, win_adhoc_w_finished, win_adhoc_w_reset),
        [WIN_ADHOC_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_r, win_adhoc_r_finished, win_adhoc_r_reset),
        [WIN_ADHOC_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_g, win_adhoc_g_finished, win_adhoc_g_reset),
        [WIN_ADHOC_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_y, win_adhoc_y_finished, win_adhoc_y_reset),
        [WIN_ADHOC_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_j, win_adhoc_j_finished, win_adhoc_j_reset),
        [WIN_ADHOC_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_k, win_adhoc_k_finished, win_adhoc_k_reset),
        [WIN_ADHOC_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_l, win_adhoc_l_finished, win_adhoc_l_reset),
        [WIN_ADHOC_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_n, win_adhoc_n_finished, win_adhoc_n_reset),
        [T_LEFT_MON_TH_TILE_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_left_mon_th_tile_left, t_left_mon_th_tile_left_finished, t_left_mon_th_tile_left_reset),
        [T_DOWN_MON_TH_MINIMIZE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_down_mon_th_minimize, t_down_mon_th_minimize_finished, t_down_mon_th_minimize_reset),
        [T_RIGHT_MON_TH_TILE_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_right_mon_th_tile_right, t_right_mon_th_tile_right_finished, t_right_mon_th_tile_right_reset),
        [T_TAB_H_BASE_DT_TIC_TH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tab_h_base_dt_tic_th_tilde, t_tab_h_base_dt_tic_th_tilde_finished, t_tab_h_base_dt_tic_th_tilde_reset),
        [BASE_RETURN_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_base_return_tap_dance, base_return_tap_dance_finished, base_return_tap_dance_reset),
        [T_COMMA_H_LCPR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_comma_h_lcpr, t_comma_h_lcpr_finished, t_comma_h_lcpr_reset),
        [T_COL_H_LCB] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_col_h_lcb, t_col_h_lcb_finished, t_col_h_lcb_reset),
        [T_DQT_H_RCB] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_dqt_h_rcb, t_dqt_h_rcb_finished, t_dqt_h_rcb_reset),
        [T_L6_H_L0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_l6_h_l0_finished, t_l6_h_l0_reset),
        [T_TILE_LEFT_TH_MON_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tile_left_th_mon_left, t_tile_left_th_mon_left_finished, t_tile_left_th_mon_left_reset),
        [T_WIN_MAX_TH_F11] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_win_max_th_f11, t_win_max_th_f11_finished, t_win_max_th_f11_reset),
        [T_TILE_RIGHT_TH_MON_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tile_right_th_mon_right, t_tile_right_th_mon_right_finished, t_tile_right_th_mon_right_reset),
};

const uint16_t PROGMEM combo_lprn_n[] = {my_space, my_n, COMBO_END};
const uint16_t PROGMEM combo_lprn[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_at[] =   {my_space, my_comma, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_dlr[] =  {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_circ[] = {my_space, my_l, COMBO_END};
const uint16_t PROGMEM combo_ampr[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_astr[] = {my_space,  my_i, COMBO_END};
const uint16_t PROGMEM combo_osl_symbols[] = {my_j, my_l, COMBO_END};

const uint16_t PROGMEM combo_newline[] = {my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_osl_windows[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_windows_2[] = {my_f, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_editor[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_spc_h[] = {my_h, my_space, COMBO_END};
const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END};
const uint16_t PROGMEM combo_jp[] = {my_p, my_j, COMBO_END};
const uint16_t PROGMEM combo_opening_paren[] = {my_u,  my_i, COMBO_END};
const uint16_t PROGMEM combo_closing_paren[] = { my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_max[] = {my_k, my_m, COMBO_END};
const uint16_t PROGMEM combo_min[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_win_right[] = {my_w, my_l, COMBO_END};
const uint16_t PROGMEM combo_win_left[] = {my_w, my_h, COMBO_END};
const uint16_t PROGMEM combo_osl_win_move[] = {my_w, my_e, COMBO_END};
const uint16_t PROGMEM combo_hyper_clear[] = {my_k,my_semicolon, my_l, COMBO_END};
const uint16_t PROGMEM combo_shiftlok[] = {my_left_shift, my_right_shift, COMBO_END};
const uint16_t PROGMEM combo_opening_square[] = {my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_closing_square[] = {my_single_quote, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_opening_curly[] = {my_o, my_p, COMBO_END};

const uint16_t PROGMEM combo_l_semicolon[] = {my_l, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_comma_m[] = {my_m, my_comma, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semicolon_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // {
const uint16_t PROGMEM combo_period_comma_m[] = {my_period, my_m, my_comma, COMBO_END}; // {

const uint16_t PROGMEM combo_semicolon_singlequote[] = {my_semicolon, my_single_quote, COMBO_END}; // ]
const uint16_t PROGMEM combo_comma_period[] = {my_comma, my_period, COMBO_END}; // ]
const uint16_t PROGMEM combo_l_singlequote_semicolon[] = {my_l, my_single_quote, my_semicolon, COMBO_END}; // }
const uint16_t PROGMEM combo_comma_period_forward_slash[] = {my_forward_slash, my_comma, my_period, COMBO_END}; // ]

const uint16_t PROGMEM combo_p_minus[] = {my_p, my_minus, COMBO_END}; // underscore
const uint16_t PROGMEM combo_p_minus_o[] = {my_p, my_o, my_minus, COMBO_END}; // equal

const uint16_t PROGMEM combo_lower_right_of_lower[] = {my_lower, my_right_of_lower, COMBO_END}; // equal

const uint16_t PROGMEM combo_j_l[] = {my_j, my_l, COMBO_END}; // osl(symbols)


combo_t key_combos[COMBO_COUNT] = {COMBO(combo_osl_windows, OSL(_WINDOWS)),
                                   COMBO(combo_osl_windows_2, OSL(_WINDOWS)),
                                   COMBO(combo_osl_win_move, OSL(_WINMOVE)),
                                   COMBO(combo_j_l, OSL(_SYMBOLS)),

                                   COMBO(combo_backspace, KC_BSPC),
                                   COMBO(combo_spc_h, KC_BSPC),

                                   COMBO(combo_lprn_n, KC_LPRN),
                                   COMBO(combo_lprn, KC_LPRN),
                                   COMBO(combo_rprn, KC_RPRN),
                                   COMBO(combo_exlm, KC_EXLM),
                                   COMBO(combo_at, KC_AT),
                                   COMBO(combo_hash, KC_HASH),
                                   COMBO(combo_dlr, KC_DLR),
                                   COMBO(combo_perc, KC_PERC),
                                   COMBO(combo_circ, KC_CIRC),
                                   COMBO(combo_ampr, KC_AMPR),
                                   COMBO(combo_astr, KC_ASTR),

                                   COMBO(combo_jo, KC_LSPO),
                                   COMBO(combo_jp, KC_RPRN),
                                   COMBO(combo_osl_symbols, RCTL(KC_SCLN)),
                                   COMBO(combo_osl_editor, OSL(_EDITING)),
                                   COMBO(combo_max, RGUI(RSFT(KC_K))),
                                   COMBO(combo_min, RGUI(RSFT(KC_J))),
                                   COMBO(combo_shiftlok, TO(_SHIFTLOK)),
                                   COMBO(combo_opening_paren, KC_LPRN),
                                   COMBO(combo_closing_paren, KC_RPRN),
                                   COMBO(combo_comma_m, KC_LBRACKET),
                                   COMBO(combo_l_semicolon, KC_LBRACKET),

                                   COMBO(combo_period_comma_m, KC_LCBR),
                                   COMBO(combo_l_semicolon_k, KC_LCBR),

                                   COMBO(combo_comma_period, KC_RBRACKET),
                                   COMBO(combo_semicolon_singlequote, KC_RBRACKET),
                                   COMBO(combo_l_singlequote_semicolon, KC_RCBR),
                                   COMBO(combo_comma_period_forward_slash, KC_RCBR),

                                   COMBO(combo_lower_right_of_lower, TO(_LOWER)),
                                   COMBO(combo_p_minus, KC_UNDS),
                                   COMBO(combo_p_minus_o, KC_EQL),
                                   COMBO(combo_newline, KC_ENTER)};
