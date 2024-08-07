// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FUNCTION 3
#define _RAISE 2

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	FUNCTION,
	RAISE,
	TILDE_RAISE,
	SPACE_ENTER,
};
/* #include "tapdance.c" */
/* #include "autoshift.c" */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
			//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
			KC_ENTER,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
			//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
			RCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_A,    KC_A,    KC_A,    KC_A,    KC_A, KC_A,
			//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
			KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          KC_A,  KC_A,    KC_A,    KC_A, KC_A,  KC_A, KC_A,
			//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                     OSL(_RAISE), MO(_FUNCTION),  KC_SPACE ,                    KC_A,  KC_A,   KC_A
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // L, M, ENTER

  [_FUNCTION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRAVE, KC_6, KC_7,   KC_8, KC_9,  KC_0,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_K, KC_F1, KC_F2,   KC_F3, KC_F4,    KC_MINUS,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_L,  KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_EQUAL,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_M, KC_F9, KC_F10, KC_F11, KC_F12, KC_TILDE, QK_BOOT,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                    KC_LGUI,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,

  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                    KC_K,  KC_Q,    KC_W,    KC_UP,    KC_R,    KC_MINUS,                               KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,

                    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                    KC_L, KC_A,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_EQUAL,                               KC_A,    KC_A,    KC_A,    KC_A,    KC_A, KC_A,
                    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                    KC_DEL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          KC_A,  KC_A,    KC_A,    KC_A, KC_A,  KC_A, KC_A,
                    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                    LALT_T(KC_DEL), MO(_FUNCTION),   _______,                    KC_A,  KC_A,   KC_A
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
