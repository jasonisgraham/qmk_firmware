#include QMK_KEYBOARD_H
/* #include "muse.h" */

enum preonic_layers {
  _BASE,
  _SYSTEM
};

enum preonic_keycodes {
  BASE = SAFE_RANGE
};

#define dpad_left KC_LEFT
#define dpad_right KC_RIGHT
#define dpad_up KC_UP
#define dpad_down KC_DOWN
#define front_punch KC_X // x
#define key_x front_punch
#define back_punch KC_Y // y
#define key_y back_punch
#define front_kick KC_A // a
#define key_a front_kick
#define back_kick KC_B // b
#define key_b back_kick
#define throw KC_SPACE // l1
#define key_l1 throw
#define block KC_V // r2
#define kameo KC_P // r1
#define key_r1 kameo
#define key_l2 KC_L // l2
#define key_l3 KC_Z
#define key_r3 KC_SLASH
#define key_r2 KC_SEMICOLON

#define preonic_1  KC_1
#define preonic_2  KC_2
#define preonic_3  KC_3
#define preonic_4  KC_4
#define preonic_5  KC_5
#define preonic_6  LSFT(KC_RCTL)
#define preonic_7  KC_6
#define preonic_8  KC_7
#define preonic_9  KC_8
#define preonic_10 KC_9
#define preonic_11 KC_0



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_preonic_grid(MO(_SYSTEM), preonic_1, preonic_2, preonic_3,   preonic_4, preonic_5, preonic_6, KC_BSPC	, key_l2, preonic_9, preonic_10, key_r2, \
                                  key_l1,    dpad_left,    dpad_up,    KC_W,    KC_R,   KC_T, KC_ESC,    KC_Y,          key_l1,    key_y,    key_b,     key_r1, \
                                  KC_ESC, dpad_left,  dpad_down,   dpad_right,   KC_F,   KC_G, KC_ENTER,  key_l2,         key_x,   KC_K,   KC_L,   key_r2, \
                                  key_l3, KC_Z,           KC_X,           KC_C,  KC_V       ,           _______,  key_l1,     KC_N,   KC_M,   KC_COMMA,   KC_DOT,   key_r3, \
                                  MO(_SYSTEM), _______,   _______,         _______, dpad_down,  _______, key_l1,           key_a, key_r1,_______,_______,_______),

    [_SYSTEM] = LAYOUT_preonic_grid(_______, _______,_______,_______,_______,_______, QK_BOOTLOADER,_______,_______,_______,_______,_______, \
                                    _______, _______, _______, _______, _______,    _______, _______, _______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, QK_CLEAR_EEPROM, KC_MEDIA_PLAY_PAUSE, \
                                    _______, _______, _______, DB_TOGG, _______, _______, DM_REC1, DM_PLY1, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______, DB_TOGG, \
                                    QK_AUTO_SHIFT_TOGGLE, _______ , _______, _______, _______, _______,   DM_REC2, DM_PLY2,  KC_AUDIO_MUTE, _______, _______, QK_BOOTLOADER, \
                                    TO(_BASE), _______, _______, _______, _______,     _______, DM_RSTP, _______, _______, _______, _______, _______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = { */
/*     [_BASE] =   { ENCODER_CCW_CW( KC_VOLU, KC_VOLD) }, */
/*     [_SYSTEM]= { ENCODER_CCW_CW( KC_VOLU, KC_VOLD) }, */
/* }; */
