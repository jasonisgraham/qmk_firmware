#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
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

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  GET_FEED_MACRO,
  SYSTEM_LAYER_ACTIVATE,
  RAISE_LAYER_HOLD,
  LOWER_LAYER_HOLD,
};

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
  DANCE_49,
  DANCE_50,
  DANCE_51,
  DANCE_52,
  DANCE_53,
  DANCE_54,
  DANCE_55,
  DANCE_56,
  DANCE_57,
  DANCE_58,
  DANCE_59,
  DANCE_60,
  DANCE_61,
  DANCE_62,
  DANCE_63,
  DANCE_64,
  DANCE_65,
  DANCE_66,
  DANCE_67,
  DANCE_68,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _SYSTEM,
  _WINDOWS,
  _MACROS,
  _SHIFTLOK,
  _WINMOVE,
  _ALT,
  _SUPER,
  _EDITING,
  _LAYER13,
  _VIM_CMDS,
  _LAYER15,
  _LAYER16,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


#define my_comma TD(DANCE_23)
#define my_b KC_B
#define my_d TD(DANCE_13)
#define my_e TD(DANCE_3)
#define my_h KC_H
#define my_f TD(DANCE_14)
#define my_g TD(DANCE_15)
#define my_i TD(DANCE_7)
#define my_j TD(DANCE_16)
#define my_k TD(DANCE_17)
#define my_l TD(DANCE_18)
#define my_left_shift KC_LSFT
#define my_m TD(DANCE_22)
#define my_minus TD(DANCE_10)
#define my_n TD(DANCE_21)
#define my_o TD(DANCE_8)
#define my_p TD(DANCE_9)
#define my_period TD(DANCE_24)
#define my_right_shift KC_RSFT
#define my_s TD(DANCE_12)
#define my_t TD(DANCE_5)
#define my_semicolon TD(DANCE_19)
#define my_single_quote TD(DANCE_20)
/* #define my_space LT(6,KC_SPACE) */
#define my_space KC_SPACE
#define my_u TD(DANCE_6)
#define my_w TD(DANCE_2)
#define my_q TD(DANCE_1)
#define my_y KC_Y
#define my_grave TD(DANCE_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    my_grave,    my_q,    my_w,    my_e,    TD(DANCE_4),    my_t,    my_y,           my_u,    my_i,    my_o,    my_p,    my_minus,
    MT(MOD_RCTL, KC_ESCAPE),TD(DANCE_11),   my_s,   my_d,   my_f,   my_g,   my_h,           my_j,   my_k,   my_l,   my_semicolon,   my_single_quote,
    my_left_shift,        KC_Z,           KC_X,           KC_C,           KC_V,           my_b,           my_n,   my_m,   my_comma,   my_period,   TD(DANCE_25),   my_right_shift,
    MT(MOD_LCTL, KC_LBRACKET), SYSTEM_LAYER_ACTIVATE,          KC_RGUI, KC_LALT, RAISE,          my_space, KC_NO,          LOWER,          KC_BSPACE,      RAISE_LAYER_HOLD,          LOWER_LAYER_HOLD,          KC_ENTER
  ),

  [_LOWER] = LAYOUT_planck_grid(
    TD(DANCE_26),   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCREEN,     KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         KC_TRANSPARENT, TD(DANCE_27),
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_SCROLLLOCK,  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    TD(DANCE_28),   KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_29),   TD(DANCE_30),   KC_DELETE,      TO(_SHIFTLOK),
    KC_TRANSPARENT, KC_NO, KC_LGUI,        KC_LALT,        MO(4),          TO(4),          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    TD(DANCE_32),   KC_NO,          ST_MACRO_0,     KC_END,         ST_MACRO_1,     KC_NO,          KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_0,           KC_UNDS,
    KC_TRANSPARENT, DYN_REC_START1, DYN_MACRO_PLAY1,KC_NO,          TD(DANCE_33),   OSL(7),         KC_BSPACE,      KC_4,           KC_5,           KC_6,           KC_LBRACKET,    KC_RBRACKET,
    KC_TRANSPARENT, DYN_REC_START2, DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_NO,          ST_MACRO_2,     KC_0,           KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO, KC_LGUI,        KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_ENTER,       KC_0,           KC_DOT,         KC_NO,          KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LSHIFT,      KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT,
    KC_TRANSPARENT, TG(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
  ),

  // 4
  [_MOUSE] = LAYOUT_planck_grid(
    TD(DANCE_34),   KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     TD(DANCE_35),   TD(DANCE_36),   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 5
  [_SYSTEM] = LAYOUT_planck_grid(
    TD(DANCE_37),   AU_TOG,         MU_MOD,         MU_TOG,         KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        KC_TRANSPARENT, WEBUSB_PAIR,    RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_MEDIA_STOP,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LED_LEVEL,      KC_TRANSPARENT, RGB_MOD,        TOGGLE_LAYER_COLOR,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE
  ),

  // 6
  [_WINDOWS] = LAYOUT_planck_grid(
   TO(_BASE), TD(DANCE_38),   TD(DANCE_39),   LGUI(KC_E),     TD(DANCE_40),   LGUI(KC_T),     TD(DANCE_41),   LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     LGUI(KC_MINUS),
    RGUI(KC_ESCAPE),LGUI(KC_A),     LGUI(KC_S),     LALT(LGUI(LCTL(KC_D))),LGUI(KC_F),     TD(DANCE_42),   LGUI(KC_H),     TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   KC_TRANSPARENT, KC_TRANSPARENT,
   KC_TRANSPARENT, LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     RGUI(KC_V),     KC_TRANSPARENT, TD(DANCE_46),   LGUI(KC_M),     TD(DANCE_47),   KC_TRANSPARENT, RSFT(LGUI(KC_K)), TO(_SHIFTLOK),
    KC_TRANSPARENT, KC_TRANSPARENT, TO(14),         TT(12),         TT(9),          LGUI(KC_SPACE), KC_NO,          TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),   RGUI(KC_ESCAPE),TD(DANCE_51)
  ),

  // 7
  [_MACROS] = LAYOUT_planck_grid(
    TD(DANCE_52),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_6,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_7,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 8
  [_SHIFTLOK] = LAYOUT_planck_grid(
    TD(DANCE_53),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     TD(DANCE_54),
    TO(0),          RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     TD(DANCE_55),   TD(DANCE_56),
    TO(0),          RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     KC_LABK,        KC_RABK,        KC_QUES,        TO(0),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 9
  [_WINMOVE] = LAYOUT_planck_grid(
    TD(DANCE_57),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGUI(RSFT(KC_Y)),KC_TRANSPARENT, KC_TRANSPARENT, RGUI(RSFT(KC_O)),KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(LCTL(KC_D))),KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_58),   RGUI(RSFT(KC_J)),TD(DANCE_59),   TD(DANCE_60),   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGUI(RSFT(KC_N)),KC_TRANSPARENT, KC_TRANSPARENT, RGUI(RSFT(KC_DOT)),KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 10
  [_ALT] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 11
  [_SUPER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // 12
  [_EDITING] = LAYOUT_planck_grid(
    TO(_BASE), KC_TRANSPARENT, ST_MACRO_8,     KC_TRANSPARENT, ST_MACRO_9,     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_7),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RALT(KC_ENTER), KC_TRANSPARENT, RALT(RSFT(KC_H)),RALT(RSFT(KC_J)),RALT(RSFT(KC_K)),RALT(RSFT(KC_L)),RCTL(KC_SCOLON),RCTL(KC_QUOTE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_10,    KC_TRANSPARENT, KC_TRANSPARENT, RALT(RSFT(KC_N)), ST_MACRO_11,    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_12,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          RALT(KC_ENTER), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  /* [_LAYER13] = LAYOUT_planck_grid( */
  /*   TD(DANCE_61),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, */
  /*   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, */
  /*   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, */
  /*   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT */
  /* ), */

  [_VIM_CMDS] = LAYOUT_planck_grid(
    TO(0), KC_TRANSPARENT, LALT(KC_F),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RCTL(KC_Y),     KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, RCTL(KC_V),     KC_TRANSPARENT,
    KC_TRANSPARENT,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(15),        TD(DANCE_62),   TD(DANCE_63),   TD(DANCE_64),   TD(DANCE_65),   KC_LCBR,        KC_RCBR,
    KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_66),   KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_B),     TD(DANCE_67),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER15] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_13,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_68),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER16] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_15,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {166,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {170,255,255}, {208,134,255}, {208,134,255}, {170,255,255}, {0,0,0}, {85,255,255}, {0,0,0}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,116}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {88,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {0,0,0}, {0,0,0}, {208,134,255}, {208,134,255}, {0,255,255}, {88,255,255}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {166,255,255}, {0,0,0}, {115,129,130}, {167,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,0,0}, {170,255,255}, {85,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,255,255}, {0,0,0}, {167,242,168}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {170,255,255}, {170,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {91,255,255}, {91,255,255}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {164,6,247}, {164,6,247}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {208,255,255}, {208,255,255}, {208,255,255} },

    [4] = { {169,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {218,255,255}, {218,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {91,255,255}, {91,255,255}, {0,0,0}, {91,255,255}, {43,255,255}, {43,255,255}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {208,255,255}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {172,255,255}, {208,255,255}, {208,255,255}, {208,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {234,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {219,255,255}, {219,255,255}, {219,255,255} },

    [6] = { {0,0,0}, {218,255,255}, {175,255,255}, {166,255,255}, {218,255,255}, {166,255,255}, {210,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {46,255,255}, {166,255,255}, {166,255,255}, {85,255,255}, {166,255,255}, {218,255,255}, {166,255,255}, {210,255,255}, {210,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {0,0,0}, {218,255,255}, {166,255,255}, {85,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {85,255,255}, {62,255,255}, {197,255,255}, {82,255,255}, {43,16,255}, {85,255,255}, {85,255,255}, {85,255,255}, {45,255,255}, {0,255,255} },

    [7] = { {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {167,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {46,255,255}, {175,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {46,255,255}, {46,255,255}, {167,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {88,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [10] = { {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {139,255,255}, {169,255,255}, {139,255,255}, {0,255,255}, {46,255,255}, {46,255,255}, {169,218,204} },

    [11] = { {175,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {220,168,159}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {220,168,159}, {175,255,255}, {220,168,159}, {220,168,159}, {220,168,159}, {0,255,255}, {40,255,255}, {0,255,255}, {129,255,255}, {220,168,159}, {220,168,159}, {40,255,255} },

    [_EDITING] = { {172,255,255}, {0,0,0}, {88,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {27,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [14] = { {0,0,0}, {0,0,0}, {0,207,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {175,255,255}, {0,0,0}, {129,255,255}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {62,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,207,255}, {0,207,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,207,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [15] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 12:
      set_layer_color(12);
      break;
    case 14:
      set_layer_color(14);
      break;
    case 15:
      set_layer_color(15);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

float zelda_puzzle[][2] =  SONG(ZELDA_PUZZLE);
float old_spice[][2] =  SONG(OLD_SPICE);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SYSTEM_LAYER_ACTIVATE:
    PLAY_SONG(zelda_puzzle);
    layer_on(_SYSTEM);
    return false;

  case RAISE_LAYER_HOLD:
    PLAY_SONG(old_spice);
    layer_on(_RAISE);
    return false;

  case LOWER_LAYER_HOLD:
    PLAY_SONG(old_spice);
    layer_on(_LOWER);
    return false;

  case ST_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_RCTL(SS_TAP(X_W)) SS_DELAY(100) SS_RCTL(SS_TAP(X_W)));

      }
    break;

  case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_DELAY(100) SS_TAP(X_R));

    }
    break;
  case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_L))) SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C) SS_DELAY(100) SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_M) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_P) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_RALT(SS_TAP(X_SLASH)));

    }
    break;
  case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_RCTL(SS_TAP(X_W)) SS_DELAY(100) SS_RCTL(SS_TAP(X_W)));

    }
    break;
  case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_C)) SS_DELAY(100) SS_TAP(X_R)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_C)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
  case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_M)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_RSFT(SS_TAP(X_M)));

    }
    break;
  case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_M)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_C));

    }
    break;
  case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_TAP(X_T));

    }
    break;
  case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME) SS_DELAY(100) SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_RCTL(SS_TAP(X_X)));

    }
    break;
  case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_END)) SS_DELAY(100) SS_RCTL(SS_TAP(X_X)));

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

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

/* t[] number_to_str(uint32_t i) { */
/*   char t[100]; */
/*   itoa(state, t, 10); */
/*   return t; */
/* } */

/* static int uint32_t prev_state = -1; */

uint32_t layer_state_set_user(uint32_t state) {
  /* if (state == _SHIFTLOK) { */
  /*   SEND_STRING("state"); */
  /* } */
  /* prev_state = state; */

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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

static tap dance_state[69];

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
        case SINGLE_HOLD: layer_on(6); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_off(6); break;
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
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_Q)); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_HOLD: register_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_HOLD: unregister_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if(state->count > 3) {
        tap_code16(KC_W);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_HOLD: register_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_HOLD: unregister_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_E);
        tap_code16(KC_E);
        tap_code16(KC_E);
    }
    if(state->count > 3) {
        tap_code16(KC_E);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_E); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_E)); break;
        case DOUBLE_TAP: register_code16(KC_E); register_code16(KC_E); break;
        case DOUBLE_HOLD: register_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_E); register_code16(KC_E);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_E); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_E)); break;
        case DOUBLE_TAP: unregister_code16(KC_E); break;
        case DOUBLE_HOLD: unregister_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_E); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if(state->count > 3) {
        tap_code16(KC_R);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_R); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_R)); break;
        case DOUBLE_TAP: register_code16(KC_R); register_code16(KC_R); break;
        case DOUBLE_HOLD: register_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_R); register_code16(KC_R);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_R); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(KC_R); break;
        case DOUBLE_HOLD: unregister_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_R); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if(state->count > 3) {
        tap_code16(KC_T);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_T)); break;
        case DOUBLE_TAP: register_code16(KC_T); register_code16(KC_T); break;
        case DOUBLE_HOLD: register_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_T); register_code16(KC_T);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_T)); break;
        case DOUBLE_TAP: unregister_code16(KC_T); break;
        case DOUBLE_HOLD: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_T); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_HOLD: register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_HOLD: unregister_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_HOLD: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_HOLD: register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_HOLD: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_P)); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_A)); break;
        case DOUBLE_TAP: register_code16(KC_A); register_code16(KC_A); break;
        case DOUBLE_HOLD: register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_A)); break;
        case DOUBLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_HOLD: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if(state->count > 3) {
        tap_code16(KC_S);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_S)); break;
        case DOUBLE_TAP: register_code16(KC_S); register_code16(KC_S); break;
        case DOUBLE_HOLD: register_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_HOLD: unregister_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if(state->count > 3) {
        tap_code16(KC_D);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_D); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_D)); break;
        case DOUBLE_TAP: register_code16(KC_D); register_code16(KC_D); break;
        case DOUBLE_HOLD: register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_D); register_code16(KC_D);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_D); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_D)); break;
        case DOUBLE_TAP: unregister_code16(KC_D); break;
        case DOUBLE_HOLD: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_D); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if(state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_F)); break;
        case DOUBLE_TAP: register_code16(KC_F); register_code16(KC_F); break;
        case DOUBLE_HOLD: register_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F); register_code16(KC_F);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_HOLD: unregister_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_G);
        tap_code16(KC_G);
        tap_code16(KC_G);
    }
    if(state->count > 3) {
        tap_code16(KC_G);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_G); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_G)); break;
        case DOUBLE_TAP: register_code16(KC_G); register_code16(KC_G); break;
        case DOUBLE_HOLD: register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_G); register_code16(KC_G);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_G); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(KC_G); break;
        case DOUBLE_HOLD: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_G); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_J)); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_HOLD: register_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_HOLD: unregister_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_HOLD: unregister_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_L)); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_HOLD: register_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_HOLD: unregister_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state[18].step = 0;
}
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
    }
    if(state->count > 3) {
        tap_code16(KC_SCOLON);
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_SCOLON); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_SCOLON); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCOLON); break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_DQUO); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(KC_DQUO); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[20].step = 0;
}
void on_dance_21(qk_tap_dance_state_t *state, void *user_data);
void dance_21_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_21_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_21(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_21_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_N)); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_HOLD: register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void dance_21_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_HOLD: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[21].step = 0;
}
void on_dance_22(qk_tap_dance_state_t *state, void *user_data);
void dance_22_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_22_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_22(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void dance_22_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_HOLD: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void dance_22_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_HOLD: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state[22].step = 0;
}
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_LABK); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_HOLD: register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_LABK); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_HOLD: unregister_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[23].step = 0;
}
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_RABK); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_HOLD: register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_RABK); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_HOLD: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[24].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_QUES); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_QUES); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[25].step = 0;
}
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[26].step = 0;
}
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_LEFT));
        tap_code16(LALT(KC_LEFT));
        tap_code16(LALT(KC_LEFT));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_LEFT));
    }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_LEFT)); register_code16(LALT(KC_LEFT));
    }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_LEFT)); break;
    }
    dance_state[27].step = 0;
}
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSPO);
        tap_code16(KC_LSPO);
        tap_code16(KC_LSPO);
    }
    if(state->count > 3) {
        tap_code16(KC_LSPO);
    }
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(KC_LSPO); break;
        case DOUBLE_TAP: layer_move(8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSPO); register_code16(KC_LSPO);
    }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(KC_LSPO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSPO); break;
    }
    dance_state[28].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGUP));
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
    }
    dance_state[29].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGDOWN));
    }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
    }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
    }
    dance_state[30].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
    }
    if(state->count > 3) {
        tap_code16(KC_INSERT);
    }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(KC_INSERT); break;
        case DOUBLE_TAP: layer_move(8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_INSERT); register_code16(KC_INSERT);
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(KC_INSERT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_INSERT); break;
    }
    dance_state[31].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SLASH));
        tap_code16(LALT(KC_SLASH));
        tap_code16(LALT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SLASH));
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SLASH)); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(LALT(KC_SLASH)); register_code16(LALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SLASH)); register_code16(LALT(KC_SLASH));
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SLASH)); break;
    }
    dance_state[32].step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_ENTER));
        tap_code16(RALT(KC_ENTER));
        tap_code16(RALT(KC_ENTER));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_ENTER));
    }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(RALT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER)); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_ENTER)); register_code16(RALT(KC_ENTER));
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_ENTER)); break;
    }
    dance_state[33].step = 0;
}
void on_dance_34(qk_tap_dance_state_t *state, void *user_data);
void dance_34_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_34_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_34(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_34_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_34_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[34].step = 0;
}
void on_dance_35(qk_tap_dance_state_t *state, void *user_data);
void dance_35_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_35_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_35(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGUP));
    }
}

void dance_35_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
    }
}

void dance_35_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
    }
    dance_state[35].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGDOWN));
    }
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
    }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
    }
    dance_state[36].step = 0;
}
void on_dance_37(qk_tap_dance_state_t *state, void *user_data);
void dance_37_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_37_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_37(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_37_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_37_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[37].step = 0;
}
void on_dance_38(qk_tap_dance_state_t *state, void *user_data);
void dance_38_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_38_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_38(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_Q));
        tap_code16(LGUI(KC_Q));
        tap_code16(LGUI(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_Q));
    }
}

void dance_38_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_Q)); register_code16(LGUI(KC_Q));
    }
}

void dance_38_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_Q)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_Q)); break;
    }
    dance_state[38].step = 0;
}
void on_dance_39(qk_tap_dance_state_t *state, void *user_data);
void dance_39_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_39_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_39(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_W));
        tap_code16(LGUI(KC_W));
        tap_code16(LGUI(KC_W));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_W));
    }
}

void dance_39_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[39].step = dance_step(state);
    switch (dance_state[39].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_W)); register_code16(LGUI(KC_W)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_W)); register_code16(LGUI(KC_W));
    }
}

void dance_39_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[39].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_W)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_W)); break;
    }
    dance_state[39].step = 0;
}
void on_dance_40(qk_tap_dance_state_t *state, void *user_data);
void dance_40_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_40_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_40(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_R));
        tap_code16(LGUI(KC_R));
        tap_code16(LGUI(KC_R));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_R));
    }
}

void dance_40_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[40].step = dance_step(state);
    switch (dance_state[40].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_R)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_R)); register_code16(LGUI(KC_R)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_R)); register_code16(LGUI(KC_R));
    }
}

void dance_40_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[40].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_R)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_R)); break;
    }
    dance_state[40].step = 0;
}
void on_dance_41(qk_tap_dance_state_t *state, void *user_data);
void dance_41_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_41_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_41(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Y));
    }
}

void dance_41_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: register_code16(LCTL(RALT(RGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y));
    }
}

void dance_41_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(RALT(RGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
    }
    dance_state[41].step = 0;
}
void on_dance_42(qk_tap_dance_state_t *state, void *user_data);
void dance_42_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_42_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_42(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_G));
        tap_code16(LGUI(KC_G));
        tap_code16(LGUI(KC_G));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_G));
    }
}

void dance_42_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_G)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_G)); register_code16(LGUI(KC_G)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_G)); register_code16(LGUI(KC_G));
    }
}

void dance_42_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_G)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_G)); break;
    }
    dance_state[42].step = 0;
}
void on_dance_43(qk_tap_dance_state_t *state, void *user_data);
void dance_43_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_43_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_43(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_J));
    }
}

void dance_43_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
    }
}

void dance_43_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
    }
    dance_state[43].step = 0;
}
void on_dance_44(qk_tap_dance_state_t *state, void *user_data);
void dance_44_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_44_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_44(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_K));
        tap_code16(LGUI(KC_K));
        tap_code16(LGUI(KC_K));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_K));
    }
}

void dance_44_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_K)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_K)); register_code16(LGUI(KC_K)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_K)); register_code16(LGUI(KC_K));
    }
}

void dance_44_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_K)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_K)); break;
    }
    dance_state[44].step = 0;
}
void on_dance_45(qk_tap_dance_state_t *state, void *user_data);
void dance_45_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_45_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_45(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_L));
        tap_code16(LGUI(KC_L));
        tap_code16(LGUI(KC_L));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_L));
    }
}

void dance_45_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_L)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_L)); register_code16(LGUI(KC_L)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_L)); register_code16(LGUI(KC_L));
    }
}

void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_L)); break;
    }
    dance_state[45].step = 0;
}
void on_dance_46(qk_tap_dance_state_t *state, void *user_data);
void dance_46_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_46_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_46(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_N));
        tap_code16(LGUI(KC_N));
        tap_code16(LGUI(KC_N));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_N));
    }
}

void dance_46_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_N)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_N)); register_code16(LGUI(KC_N)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_N)); register_code16(LGUI(KC_N));
    }
}

void dance_46_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_N)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_N)); break;
    }
    dance_state[46].step = 0;
}
void on_dance_47(qk_tap_dance_state_t *state, void *user_data);
void dance_47_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_47_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_47(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_UP)));
        tap_code16(LGUI(LSFT(KC_UP)));
        tap_code16(LGUI(LSFT(KC_UP)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_UP)));
    }
}

void dance_47_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_UP))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP)));
    }
}

void dance_47_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
    }
    dance_state[47].step = 0;
}
void on_dance_48(qk_tap_dance_state_t *state, void *user_data);
void dance_48_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_48_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_48(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_LEFT)));
        tap_code16(LGUI(LSFT(KC_LEFT)));
        tap_code16(LGUI(LSFT(KC_LEFT)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_LEFT)));
    }
}

void dance_48_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_LEFT))); register_code16(LGUI(LSFT(KC_LEFT)));
    }
}

void dance_48_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[48].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
    }
    dance_state[48].step = 0;
}
void on_dance_49(qk_tap_dance_state_t *state, void *user_data);
void dance_49_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_49_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_49(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_DOWN)));
        tap_code16(LGUI(LSFT(KC_DOWN)));
        tap_code16(LGUI(LSFT(KC_DOWN)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_DOWN)));
    }
}

void dance_49_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[49].step = dance_step(state);
    switch (dance_state[49].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_DOWN))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_DOWN))); register_code16(LGUI(LSFT(KC_DOWN)));
    }
}

void dance_49_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[49].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_DOWN))); break;
    }
    dance_state[49].step = 0;
}
void on_dance_50(qk_tap_dance_state_t *state, void *user_data);
void dance_50_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_50_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_50(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_RIGHT)));
        tap_code16(LGUI(LSFT(KC_RIGHT)));
        tap_code16(LGUI(LSFT(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_RIGHT)));
    }
}

void dance_50_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[50].step = dance_step(state);
    switch (dance_state[50].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_RIGHT))); register_code16(LGUI(LSFT(KC_RIGHT)));
    }
}

void dance_50_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[50].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
    }
    dance_state[50].step = 0;
}
void dance_51_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_51_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_51_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[51].step = dance_step(state);
    switch (dance_state[51].step) {
        case DOUBLE_HOLD: register_code16(RCTL(RGUI(KC_Q))); break;
    }
}

void dance_51_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[51].step) {
        case DOUBLE_HOLD: unregister_code16(RCTL(RGUI(KC_Q))); break;
    }
    dance_state[51].step = 0;
}
void on_dance_52(qk_tap_dance_state_t *state, void *user_data);
void dance_52_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_52_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_52(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_52_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[52].step = dance_step(state);
    switch (dance_state[52].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_52_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[52].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[52].step = 0;
}
void on_dance_53(qk_tap_dance_state_t *state, void *user_data);
void dance_53_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_53_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_53(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TILD);
        tap_code16(KC_TILD);
        tap_code16(KC_TILD);
    }
    if(state->count > 3) {
        tap_code16(KC_TILD);
    }
}

void dance_53_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[53].step = dance_step(state);
    switch (dance_state[53].step) {
        case SINGLE_TAP: register_code16(KC_TILD); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_TILD); register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TILD); register_code16(KC_TILD);
    }
}

void dance_53_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[53].step) {
        case SINGLE_TAP: unregister_code16(KC_TILD); break;
        case DOUBLE_TAP: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TILD); break;
    }
    dance_state[53].step = 0;
}
void on_dance_54(qk_tap_dance_state_t *state, void *user_data);
void dance_54_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_54_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_54(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

void dance_54_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[54].step = dance_step(state);
    switch (dance_state[54].step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void dance_54_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[54].step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state[54].step = 0;
}
void on_dance_55(qk_tap_dance_state_t *state, void *user_data);
void dance_55_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_55_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_55(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_55_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[55].step = dance_step(state);
    switch (dance_state[55].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_55_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[55].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[55].step = 0;
}
void on_dance_56(qk_tap_dance_state_t *state, void *user_data);
void dance_56_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_56_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_56(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void dance_56_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[56].step = dance_step(state);
    switch (dance_state[56].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void dance_56_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[56].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[56].step = 0;
}
void dance_57_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_57_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_57_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[57].step = dance_step(state);
    switch (dance_state[57].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void dance_57_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[57].step) {
    }
    dance_state[57].step = 0;
}
void on_dance_58(qk_tap_dance_state_t *state, void *user_data);
void dance_58_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_58_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_58(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_H)));
        tap_code16(RGUI(RSFT(KC_H)));
        tap_code16(RGUI(RSFT(KC_H)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_H)));
    }
}

void dance_58_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[58].step = dance_step(state);
    switch (dance_state[58].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_H))); register_code16(RGUI(RSFT(KC_H)));
    }
}

void dance_58_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[58].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_H))); break;
    }
    dance_state[58].step = 0;
}
void on_dance_59(qk_tap_dance_state_t *state, void *user_data);
void dance_59_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_59_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_59(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_K)));
        tap_code16(RGUI(RSFT(KC_K)));
        tap_code16(RGUI(RSFT(KC_K)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_K)));
    }
}

void dance_59_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[59].step = dance_step(state);
    switch (dance_state[59].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_HOLD: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_K))); register_code16(RGUI(RSFT(KC_K)));
    }
}

void dance_59_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[59].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_HOLD: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_K))); break;
    }
    dance_state[59].step = 0;
}
void on_dance_60(qk_tap_dance_state_t *state, void *user_data);
void dance_60_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_60_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_60(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_L)));
        tap_code16(RGUI(RSFT(KC_L)));
        tap_code16(RGUI(RSFT(KC_L)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_L)));
    }
}

void dance_60_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[60].step = dance_step(state);
    switch (dance_state[60].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_L))); register_code16(RGUI(RSFT(KC_L)));
    }
}

void dance_60_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[60].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_L))); break;
    }
    dance_state[60].step = 0;
}
void on_dance_61(qk_tap_dance_state_t *state, void *user_data);
void dance_61_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_61_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_61(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if(state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

void dance_61_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[61].step = dance_step(state);
    switch (dance_state[61].step) {
        case SINGLE_TAP: register_code16(KC_GRAVE); break;
        case SINGLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
    }
}

void dance_61_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[61].step) {
        case SINGLE_TAP: unregister_code16(KC_GRAVE); break;
        case SINGLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break;
    }
    dance_state[61].step = 0;
}
void on_dance_62(qk_tap_dance_state_t *state, void *user_data);
void dance_62_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_62_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_62(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_62_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[62].step = dance_step(state);
    switch (dance_state[62].step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(KC_H); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_62_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[62].step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(KC_H); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state[62].step = 0;
}
void on_dance_63(qk_tap_dance_state_t *state, void *user_data);
void dance_63_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_63_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_63(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_63_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[63].step = dance_step(state);
    switch (dance_state[63].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(KC_J); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_63_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[63].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(KC_J); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[63].step = 0;
}
void on_dance_64(qk_tap_dance_state_t *state, void *user_data);
void dance_64_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_64_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_64(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_64_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[64].step = dance_step(state);
    switch (dance_state[64].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(KC_K); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_64_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[64].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(KC_K); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[64].step = 0;
}
void on_dance_65(qk_tap_dance_state_t *state, void *user_data);
void dance_65_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_65_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_65(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void dance_65_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[65].step = dance_step(state);
    switch (dance_state[65].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(KC_L); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void dance_65_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[65].step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(KC_L); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state[65].step = 0;
}
void on_dance_66(qk_tap_dance_state_t *state, void *user_data);
void dance_66_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_66_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_66(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_66_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[66].step = dance_step(state);
    switch (dance_state[66].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(KC_DELETE); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_66_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[66].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[66].step = 0;
}
void on_dance_67(qk_tap_dance_state_t *state, void *user_data);
void dance_67_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_67_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_67(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_67_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[67].step = dance_step(state);
    switch (dance_state[67].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(KC_N); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void dance_67_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[67].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(KC_N); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[67].step = 0;
}
void on_dance_68(qk_tap_dance_state_t *state, void *user_data);
void dance_68_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_68_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_68(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_HOME));
        tap_code16(RCTL(KC_HOME));
        tap_code16(RCTL(KC_HOME));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_HOME));
    }
}

void dance_68_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[68].step = dance_step(state);
    switch (dance_state[68].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_HOME)); break;
        case SINGLE_HOLD: register_code16(RCTL(KC_END)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_HOME)); register_code16(RCTL(KC_HOME));
    }
}

void dance_68_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[68].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
        case SINGLE_HOLD: unregister_code16(RCTL(KC_END)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_HOME)); break;
    }
    dance_state[68].step = 0;
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
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
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
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
        [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_41, dance_41_finished, dance_41_reset),
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
        [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
        [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
        [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
        [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
        [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
        [DANCE_51] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_51_finished, dance_51_reset),
        [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_52, dance_52_finished, dance_52_reset),
        [DANCE_53] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_53, dance_53_finished, dance_53_reset),
        [DANCE_54] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_54, dance_54_finished, dance_54_reset),
        [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
        [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
        [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_57_finished, dance_57_reset),
        [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
        [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset),
        [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset),
        [DANCE_61] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_61, dance_61_finished, dance_61_reset),
        [DANCE_62] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_62, dance_62_finished, dance_62_reset),
        [DANCE_63] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_63, dance_63_finished, dance_63_reset),
        [DANCE_64] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_64, dance_64_finished, dance_64_reset),
        [DANCE_65] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_65, dance_65_finished, dance_65_reset),
        [DANCE_66] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_66, dance_66_finished, dance_66_reset),
        [DANCE_67] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_67, dance_67_finished, dance_67_reset),
        [DANCE_68] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_68, dance_68_finished, dance_68_reset),
};


const uint16_t PROGMEM combo_grave_q[] = {my_grave, my_q, COMBO_END};

const uint16_t PROGMEM combo_esc[] = {my_m, my_comma, COMBO_END};
const uint16_t PROGMEM combo_newline[] = {my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_osl_windows_2[] = {my_f, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_windows[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_windows_3[] = {my_f, my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_editor[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_spc_h[] = {my_h, my_space, COMBO_END};
const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END};
const uint16_t PROGMEM combo_jp[] = {my_p, my_j, COMBO_END};
const uint16_t PROGMEM combo_opening_paren[] = {my_u, my_i, COMBO_END};
const uint16_t PROGMEM combo_closing_paren[] = {my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_max[] = {my_k, my_m, COMBO_END};
const uint16_t PROGMEM combo_min[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_osl_win_move[] = {my_w, my_e, COMBO_END};

const uint16_t PROGMEM combo_hyper_clear[] = {my_k,my_semicolon, my_l, COMBO_END};
const uint16_t PROGMEM combo_shiftlok[] = {my_left_shift, my_right_shift, COMBO_END};

const uint16_t PROGMEM combo_l_semicolon[] = {my_l, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semicolon_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // {

const uint16_t PROGMEM combo_semicolon_singlequote[] = {my_semicolon, my_single_quote, COMBO_END}; // ]
const uint16_t PROGMEM combo_l_singlequote_semicolon[] = {my_l, my_single_quote, my_semicolon, COMBO_END}; // }

const uint16_t PROGMEM combo_p_minus[] = {my_p, my_minus, COMBO_END}; // underscore
const uint16_t PROGMEM combo_p_minus_o[] = {my_p, my_o, my_minus, COMBO_END}; // equal

const uint16_t PROGMEM combo_osl_symbols[] = {my_j, my_l, COMBO_END};

const uint16_t PROGMEM combo_lprn[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_lprn_n[] = {my_space, my_n, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_at[] =   {my_space, my_comma, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_dlr[] =  {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_circ[] = {my_space, my_l, COMBO_END};
const uint16_t PROGMEM combo_ampr[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_astr[] = {my_space, my_i, COMBO_END};


const uint16_t PROGMEM combo_bm[] = {my_b, my_m, COMBO_END};
const uint16_t PROGMEM combo_comman[] = {my_comma, my_n, COMBO_END};
const uint16_t PROGMEM combo_periodm[] = {my_period, my_m, COMBO_END};
const uint16_t PROGMEM combo_jg[] =  {my_g, my_j, COMBO_END};
const uint16_t PROGMEM combo_kh[] = {my_h, my_k, COMBO_END};
const uint16_t PROGMEM combo_lj[] = {my_j, my_l, COMBO_END};
const uint16_t PROGMEM combo_ut[] = {my_t, my_u, COMBO_END};
const uint16_t PROGMEM combo_iy[] = {my_y, my_i, COMBO_END};
const uint16_t PROGMEM combo_ou[] = {my_o, my_u, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {COMBO(combo_esc, KC_ESC),
                                   COMBO(combo_osl_windows, OSL(_WINDOWS)),
                                   COMBO(combo_osl_windows_2, OSL(_WINDOWS)),
                                   COMBO(combo_osl_windows_3, OSL(_WINDOWS)),
                                   COMBO(combo_osl_win_move, OSL(_WINMOVE)),
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

                                   COMBO(combo_grave_q, KC_ASTG),

                                   COMBO(combo_jo, KC_LSPO),
                                   COMBO(combo_jp, KC_RPRN),
                                   COMBO(combo_osl_symbols, RCTL(KC_SCLN)),
                                   COMBO(combo_osl_editor, OSL(_EDITING)),
                                   COMBO(combo_max, RGUI(RSFT(KC_K))),
                                   COMBO(combo_min, RGUI(RSFT(KC_J))),
                                   COMBO(combo_shiftlok, TO(_SHIFTLOK)),
                                   COMBO(combo_opening_paren, KC_LPRN),
                                   COMBO(combo_closing_paren, KC_RPRN),
                                   COMBO(combo_l_semicolon, KC_LBRACKET),
                                   COMBO(combo_l_semicolon_k, KC_LCBR),


                                   /* COMBO(combo_ou, KC_LPRN), */
                                   COMBO(combo_bm, KC_EXLM),
                                   COMBO(combo_comman, KC_AT),
                                   COMBO(combo_periodm, KC_HASH),
                                   COMBO(combo_jg, KC_DLR),
                                   COMBO(combo_kh, KC_PERC),
                                   COMBO(combo_lj, KC_CIRC),
                                   COMBO(combo_ut, KC_AMPR),
                                   COMBO(combo_iy, KC_ASTR),


                                   COMBO(combo_semicolon_singlequote, KC_RBRACKET),
                                   COMBO(combo_l_singlequote_semicolon, KC_RCBR),

                                   COMBO(combo_p_minus, KC_UNDS),
                                   COMBO(combo_p_minus_o, KC_EQL),
                                   /* COMBO(combo_win_left, RGUI(RSFT(KC_H))), */
                                   /* COMBO(combo_win_right, RGUI(RSFT(KC_L))), */
                                   COMBO(combo_newline, KC_ENTER)};
