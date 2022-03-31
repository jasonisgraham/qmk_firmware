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

enum tap_dance_codes {
                      DANCE_0,
                      DANCE_1,
                      DANCE_2,
                      DANCE_3,
                      DANCE_4,
                      DANCE_5,
                      DANCE_6,
                      DANCE_7,
                      DANCE_8,
                      DANCE_9,
                      DANCE_10,
                      DANCE_11,
                      DANCE_12,
                      DANCE_13,
                      DANCE_14,
                      DANCE_15,
                      DANCE_16,
                      DANCE_17,
                      DANCE_18,
                      DANCE_19,
                      DANCE_20,
                      DANCE_21,
                      DANCE_22,
                      DANCE_23,
                      DANCE_24,
                      DANCE_25,
                      DANCE_26,
                      DANCE_27,
                      DANCE_28,
                      DANCE_29,
                      DANCE_30,
                      DANCE_31,
                      DANCE_32,
                      DANCE_33,
                      DANCE_34,
                      DANCE_35,
                      DANCE_36,
                      DANCE_37,
                      DANCE_38,
                      DANCE_39,
                      DANCE_40,
                      DANCE_41,
                      DANCE_42,
                      DANCE_43,
                      DANCE_44,
                      DANCE_45,
                      DANCE_46,
                      DANCE_47,
                      DANCE_48,
};


#define my_j TD(DANCE_6)
#define my_k TD(DANCE_7)
#define my_s KC_S
#define my_d KC_D
#define my_l TD(DANCE_8)
#define my_h KC_H
#define my_o TD(DANCE_3)
#define my_p TD(DANCE_4)
#define my_i TD(DANCE_2)
#define my_u TD(DANCE_1)
#define my_w KC_W
#define my_e KC_E
#define my_f KC_F
#define my_semicolon TD(DANCE_9)
#define my_left_shift KC_LSFT
#define my_right_shift KC_RSFT
#define my_single_quote TD(DANCE_10)
#define my_space KC_SPACE

#define my_right_of_lower KC_BSPACE
#define my_lower MO(1)
#define my_forward_slash TD(DANCE_14)
#define my_minus TD(DANCE_5)
#define my_comma TD(DANCE_12)
#define my_period TD(DANCE_13)
#define my_m TD(DANCE_11)
#define my_n KC_N


#include "../../../common/keymap.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
                              RCTL(KC_LBRACKET),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           MUSIC_LAYER_ACTIVATE,                                 _______, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    TD(DANCE_0),    KC_Q,           my_w,           my_e,           KC_R,           KC_T,           _______,                                 _______, KC_Y,           my_u,    my_i,    my_o,    my_p,    my_minus,
    MT(MOD_RCTL, KC_ESCAPE),KC_A,           my_s,           my_d,           my_f,           KC_G,           OSL(1),                                                                         KC_BSPACE,      my_h,           my_j,    my_k,    my_l,    my_semicolon,    my_single_quote,
    my_left_shift,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           my_n,           my_m,   my_comma,   my_period,   my_forward_slash,   my_right_shift,
                              MT(MOD_LCTL, KC_LBRACKET), SYSTEM_LAYER_ACTIVATE,          KC_LGUI,KC_LALT, MO(_RAISE),          KC_RCTRL,                                                                                                       KC_BSPACE,      my_lower,         my_right_of_lower,      TT(2),          TT(1),          KC_ENTER,
    KC_BSPACE,      LM(_SUPER,MOD_LGUI),KC_ENTER,                       LM(9,MOD_LALT), LM(_WINDOWS, MOD_LGUI), my_space
  ),
  // lower
  [_LOWER] = LAYOUT_moonlander(
    _______, RCTL(KC_1),     RCTL(KC_2),     RCTL(KC_3),     RCTL(KC_4),     RCTL(KC_5),     TG(3),                                          _______, _______, _______, _______, _______, _______, TD(DANCE_17),
    TD(DANCE_15),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     _______,                                 _______, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         _______, TD(DANCE_17),
    _______, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_SCROLLLOCK,  TO(0),                                                                          _______, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______,
    TD(DANCE_16),   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION,                                 TD(DANCE_18),   _______, TD(DANCE_19),   TD(DANCE_20),   KC_DELETE,    SHIFTLOK_LAYER_ACTIVATE,  // TO(_SHIFTLOK),
    _______, _______, KC_LGUI,        KC_LALT,        TT(3),          _______,                                                                                                 _______, _______, KC_NO,          _______, _______, TD(DANCE_21),
    _______, _______, _______,                 _______, _______, TT(3)
  ),
  // raise
  [_RAISE] = LAYOUT_moonlander(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    TD(DANCE_22),   _______, EMACS_OTHER_WINDOW,     KC_END,         EMACS_BUFFER_REVERT,     _______, _______,                                 _______, _______, KC_7,           KC_8,           KC_9,           KC_0,           _______,
    _______, DYN_REC_START1, DYN_MACRO_PLAY1,_______, RALT(KC_ENTER), OSL(6),         _______,                                                                 _______, KC_BSPACE,      KC_4,           KC_5,           KC_6,           KC_LBRACKET,    KC_RBRACKET,
    _______, DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   _______, FISH_ACCEPT_SEND,                                     KC_0,           KC_1,           KC_2,           KC_3,           KC_BSLASH,      _______,
    _______, _______, KC_LGUI,        KC_LALT,        _______, _______,                                                                                                 _______, KC_ENTER,       KC_0,           KC_DOT,         _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [_MOUSE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_23),   _______, _______, KC_MS_UP,       _______, _______, _______,                                 _______, TD(DANCE_24),   KC_PGUP,        KC_PGDOWN,      KC_END,         _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,                                                                 _______, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, KC_MS_BTN3,     RCTL(KC_PGUP),  RCTL(KC_PGDOWN),_______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  //system
  [_SYSTEM] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, RGB_SAD,        RGB_SAI,        WEBUSB_PAIR,    RESET,
    TD(DANCE_25),   AU_TOG,         MU_MOD,         MU_TOG,         _______, _______, _______,                                 _______, RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,KC_MEDIA_STOP,  _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    _______, _______, _______, _______, _______, _______,                                                                                                 KC_ASRP, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,
    _______, _______, _______,                 KC_ASTG,        KC_ASDN,        KC_ASUP
  ),
  // windows
  [_WINDOWS] = LAYOUT_moonlander(
    KC_GRAVE,       _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,         TD(DANCE_26),   TD(DANCE_27),   RGUI(KC_E),     TD(DANCE_28),   RGUI(KC_T),     _______,                                 _______, TD(DANCE_30),   RGUI(KC_7),     RGUI(KC_8),     RGUI(KC_9),     RGUI(KC_0),     RGUI(KC_MINUS),
    RGUI(KC_ESCAPE),RGUI(KC_A),     RGUI(KC_S),     LALT(LGUI(LCTL(KC_D))),RGUI(KC_F),     TD(DANCE_29),   _______,                                                                 _______, RGUI(KC_H),     TD(DANCE_31),   TD(DANCE_32),   TD(DANCE_33),   _______, _______,
    _______, RGUI(KC_Z),     RGUI(KC_X),     RGUI(KC_C),     RGUI(KC_V),     _______,                                 TD(DANCE_34),   RGUI(KC_M),     TD(DANCE_35),   _______, KC_GRAVE,       RGUI(RSFT(KC_J)),
    _______, _______, _______, MO(11),         MO(8),          _______,                                                                                                 _______, TD(DANCE_36),   TD(DANCE_37),   TD(DANCE_38),   KC_TAB,         TD(DANCE_39),
    MO(11),         _______, KC_LSHIFT,                      _______, _______, KC_NO
  ),
  // macros
  [_MACROS] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_40),   _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, EMACS_YAS_DOC,     EMACS_YAS_TF,     EMACS_INSERT_GET_FEED, _______,                                                                 _______, _______, _______, _______, EMACS_YAS_TL,     _______, _______,
    _______, _______, _______, EMACS_YAS_C,     _______, _______,                                 _______, EMACS_YAS_MAP_ANON,     _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  // shiftlok
  [_SHIFTLOK] = LAYOUT_moonlander(
    _______, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        _______,                                 _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    TD(DANCE_41),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     _______,                                 _______, RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_42),
    _______, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     _______,                                                                 _______, RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(DANCE_43),   TD(DANCE_44),
    TO(0),          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),                                     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        TO(0),
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  // winmove
  [_WINMOVE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TD(DANCE_45),   _______, _______, _______, _______, _______, _______,                                 _______, LGUI(LSFT(KC_Y)),_______, _______, LGUI(LSFT(KC_O)),_______, _______,
    _______, _______, _______, LALT(LGUI(LCTL(KC_D))),_______, _______, _______,                                                                 _______, TD(DANCE_46),   LGUI(LSFT(KC_J)),TD(DANCE_47),   TD(DANCE_48),   _______, _______,
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
    _______, _______, _______, EMACS_WINDOW_CLOSE,    _______, _______,                                 RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP, OSL(_SYMBOLS), _______, EMACS_WINDOW_CLOSEST_MACRO_12,    _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
    [_SYMBOLS] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR,         KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_LCBR,        KC_RCBR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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

int i = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MUSIC_LAYER_ACTIVATE:
    if (record->event.pressed) {
      switch (i++) {
        /* case 0: PLAY_SONG(lp_numb); break; */
        /* case 1: PLAY_SONG(ode_to_joy); break; */
      case 2: PLAY_SONG(rock_a_bye_baby); break;
        /* case 3: PLAY_SONG(close_encounters_5_note); break; */
        /* case 4: PLAY_SONG(doe_a_deer); break; */
        /* case 5: PLAY_SONG(in_like_flint); break; */
      case 6: PLAY_SONG(imperial_march); break;
        /* case 7: PLAY_SONG(clueboard_sound); break; */
        /* case 8: PLAY_SONG(basket_case); break; */
      case 9: PLAY_SONG(startup_sound); break;
        /* case 10: PLAY_SONG(goodbye_sound); break; */
        /* case 11: PLAY_SONG(planck_sound); break; */
        /* case 12: PLAY_SONG(preonic_sound); break; */
        /* case 13: PLAY_SONG(qwerty_sound); break; */
        /* case 14: PLAY_SONG(colemak_sound); break; */
        /* case 15: PLAY_SONG(dvorak_sound); break; */
        /* case 16: PLAY_SONG(plover_sound); break; */
        /* case 17: PLAY_SONG(plover_goodbye_sound); break; */
        /* case 18: PLAY_SONG(music_on_sound); break; */
        /* case 19: PLAY_SONG(audio_on_sound); break; */
        /* case 20: PLAY_SONG(audio_off_sound); break; */
        /* case 21: PLAY_SONG(music_off_sound); break; */
        /* case 22: PLAY_SONG(voice_change_sound); break; */
        /* case 23: PLAY_SONG(chromatic_sound); break; */
        /* case 24: PLAY_SONG(major_sound); break; */
        /* case 25: PLAY_SONG(minor_sound); break; */
        /* case 26: PLAY_SONG(guitar_sound); break; */
        /* case 27: PLAY_SONG(violin_sound); break; */
        /* case 28: PLAY_SONG(caps_lock_on_sound); break; */
        /* case 29: PLAY_SONG(caps_lock_off_sound); break; */
        /* case 30: PLAY_SONG(scroll_lock_on_sound); break; */
        /* case 31: PLAY_SONG(scroll_lock_off_sound); break; */
        /* case 32: PLAY_SONG(num_lock_on_sound); break; */
        /* case 33: PLAY_SONG(num_lock_off_sound); break; */
        /* case 34: PLAY_SONG(ag_norm_sound); break; */
        /* case 35: PLAY_SONG(ag_swap_sound); break; */
        /* case 36: PLAY_SONG(unicode_windows); break; */
        /* case 37: PLAY_SONG(unicode_linux); break; */
      case 38: PLAY_SONG(coin_sound); break;
      case 39: PLAY_SONG(one_up_sound); break;
        /* case 40: PLAY_SONG(sonic_ring); break; */
      case 41: PLAY_SONG(zelda_puzzle); break;
        /* case 42: PLAY_SONG(zelda_treasure); break; */
        /* case 43: PLAY_SONG(terminal_sound); break; */
        /* case 44: PLAY_SONG(overwatch_theme); break; */
        /* case 45: PLAY_SONG(mario_theme); break; */
      case 46: PLAY_SONG(mario_gameover); break;
      case 47: PLAY_SONG(mario_mushroom); break;
      case 48: PLAY_SONG(e1m1_doom); break;
      case 49: PLAY_SONG(disney_song); break;
      case 50: PLAY_SONG(number_one); break;
      case 51: PLAY_SONG(cabbage_song); break;
      case 52: PLAY_SONG(old_spice); break;
      case 53: PLAY_SONG(victory_fanfare_short); break;
      case 54: PLAY_SONG(all_star); break;
      case 55: PLAY_SONG(rick_roll); break;
      case 56: PLAY_SONG(ff_prelude); break;
      case 57: PLAY_SONG(to_boldly_go); break;
      default: i = 0;

      }


      /* layer_on(_MUSIC); */

      return false;

    }
    break;

  case SYSTEM_LAYER_ACTIVATE:
    PLAY_SONG(zelda_puzzle);
    layer_on(_SYSTEM);
    return false;

  case SHIFTLOK_LAYER_ACTIVATE:
    if (record->event.pressed) {
      /* PLAY_SONG(zelda_tune); */

      layer_on(_SHIFTLOK);

      return false;

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
      SEND_STRING(SS_TAP(X_D)  SS_TAP(X_O)  SS_TAP(X_C)  SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case EMACS_YAS_TF:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T)  SS_TAP(X_F)  SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case EMACS_YAS_C:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C)  SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case EMACS_YAS_TL:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T)  SS_TAP(X_L)  SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case EMACS_YAS_MAP_ANON:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_M)  SS_TAP(X_A)  SS_TAP(X_P)  SS_TAP(X_A)  SS_RALT(SS_TAP(X_SLASH)));

    }
    break;

  case EMACS_ACE_WINDOW_SWAP:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M)) SS_DELAY(10) SS_TAP(X_W) SS_DELAY(10) SS_RSFT(SS_TAP(X_M)));

    }
    break;

  case EMACS_WINDOW_CLOSE:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M))  SS_TAP(X_W)  SS_TAP(X_C));

    }
    break;
  case EMACS_INSERT_GET_FEED:
    if (record->event.pressed) {
      SEND_STRING("(def xs (get-feed))");
    }
    break;

  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
  }
  return true;
}

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


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_HOLD: register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_HOLD: register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_J)); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_HOLD: register_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_L)); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_HOLD: register_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
    }
    if(state->count > 3) {
        tap_code16(KC_SCOLON);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_SCOLON); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_DQUO); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_HOLD: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_LABK); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_HOLD: register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_RABK); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_HOLD: register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_QUES); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSPO);
        tap_code16(KC_LSPO);
        tap_code16(KC_LSPO);
    }
    if(state->count > 3) {
        tap_code16(KC_LSPO);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_LSPO); break;
        case DOUBLE_TAP: layer_move(7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSPO); register_code16(KC_LSPO);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_LSPO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSPO); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_LEFT));
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: register_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT));
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: unregister_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(KC_N); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_HOLD: register_code16(RSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGUP));
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGDOWN));
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
    }
    dance_state[20].step = 0;
}
void on_dance_21(qk_tap_dance_state_t *state, void *user_data);
void dance_21_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_21_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_21(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
    }
    if(state->count > 3) {
        tap_code16(KC_INSERT);
    }
}

void dance_21_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_INSERT); break;
        case DOUBLE_TAP: layer_move(7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_INSERT); register_code16(KC_INSERT);
    }
}

void dance_21_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_INSERT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_INSERT); break;
    }
    dance_state[21].step = 0;
}
void on_dance_22(qk_tap_dance_state_t *state, void *user_data);
void dance_22_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_22_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_22(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_SLASH));
    }
}

void dance_22_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(RALT(KC_SLASH)); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH));
    }
}

void dance_22_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
    }
    dance_state[22].step = 0;
}
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[23].step = 0;
}
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
    }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
    }
    dance_state[24].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[25].step = 0;
}
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Q));
    }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q));
    }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
    }
    dance_state[26].step = 0;
}
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_W));
    }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_W)); register_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_W)); register_code16(RGUI(KC_W));
    }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
    }
    dance_state[27].step = 0;
}
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_R));
    }
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_R)); register_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_R)); register_code16(RGUI(KC_R));
    }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
    }
    dance_state[28].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_G));
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_G)); register_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_G)); register_code16(RGUI(KC_G));
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
    }
    dance_state[29].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Y));
    }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y));
    }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
    }
    dance_state[30].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_J));
    }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: register_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
    }
    dance_state[31].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_K));
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_K)); register_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_K)); register_code16(RGUI(KC_K));
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
    }
    dance_state[32].step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_L));
    }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_L)); register_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_L)); register_code16(RGUI(KC_L));
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
    }
    dance_state[33].step = 0;
}
void on_dance_34(qk_tap_dance_state_t *state, void *user_data);
void dance_34_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_34_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_34(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_N));
    }
}

void dance_34_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_N)); register_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_N)); register_code16(RGUI(KC_N));
    }
}

void dance_34_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
    }
    dance_state[34].step = 0;
}
void on_dance_35(qk_tap_dance_state_t *state, void *user_data);
void dance_35_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_35_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_35(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_UP)));
        tap_code16(RGUI(RSFT(KC_UP)));
        tap_code16(RGUI(RSFT(KC_UP)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_UP)));
    }
}

void dance_35_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_UP))); register_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_UP))); register_code16(RGUI(RSFT(KC_UP)));
    }
}

void dance_35_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_UP))); break;
    }
    dance_state[35].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
    }
    dance_state[36].step = 0;
}
void on_dance_37(qk_tap_dance_state_t *state, void *user_data);
void dance_37_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_37_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_37(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void dance_37_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void dance_37_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
    }
    dance_state[37].step = 0;
}
void on_dance_38(qk_tap_dance_state_t *state, void *user_data);
void dance_38_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_38_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_38(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void dance_38_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void dance_38_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
    }
    dance_state[38].step = 0;
}
void dance_39_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_39_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_39_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[39].step = dance_step(state);
    switch (dance_state[39].step) {
        case DOUBLE_HOLD: register_code16(RCTL(RGUI(KC_Q))); break;
    }
}

void dance_39_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[39].step) {
        case DOUBLE_HOLD: unregister_code16(RCTL(RGUI(KC_Q))); break;
    }
    dance_state[39].step = 0;
}
void on_dance_40(qk_tap_dance_state_t *state, void *user_data);
void dance_40_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_40_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_40(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_40_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[40].step = dance_step(state);
    switch (dance_state[40].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_40_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[40].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[40].step = 0;
}
void on_dance_41(qk_tap_dance_state_t *state, void *user_data);
void dance_41_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_41_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_41(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_41_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_41_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[41].step = 0;
}
void on_dance_42(qk_tap_dance_state_t *state, void *user_data);
void dance_42_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_42_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_42(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

void dance_42_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void dance_42_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state[42].step = 0;
}
void on_dance_43(qk_tap_dance_state_t *state, void *user_data);
void dance_43_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_43_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_43(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_43_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_43_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[43].step = 0;
}
void on_dance_44(qk_tap_dance_state_t *state, void *user_data);
void dance_44_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_44_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_44(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void dance_44_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void dance_44_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[44].step = 0;
}
void dance_45_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_45_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_45_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
    }
    dance_state[45].step = 0;
}
void on_dance_46(qk_tap_dance_state_t *state, void *user_data);
void dance_46_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_46_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_46(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_H)));
    }
}

void dance_46_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H)));
    }
}

void dance_46_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
    }
    dance_state[46].step = 0;
}
void on_dance_47(qk_tap_dance_state_t *state, void *user_data);
void dance_47_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_47_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_47(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_K)));
    }
}

void dance_47_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K)));
    }
}

void dance_47_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
    }
    dance_state[47].step = 0;
}
void on_dance_48(qk_tap_dance_state_t *state, void *user_data);
void dance_48_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_48_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_48(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_L)));
    }
}

void dance_48_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L)));
    }
}

void dance_48_reset(qk_tap_dance_state_t *state, void *user_data) {
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
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
        [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
        [DANCE_21] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
        [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_24_finished, dance_24_reset),
        [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
        [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
        [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
        [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
        [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
        [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
        [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
        [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_39_finished, dance_39_reset),
        [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_41, dance_41_finished, dance_41_reset),
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_45_finished, dance_45_reset),
        [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
        [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
        [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
};
