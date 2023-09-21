/* Copyright 2021 Joe Maples <joe@maples.dev>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes { FIRST = SAFE_RANGE,
                       TOGGLE_KC_SPC};

bool spacebar_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TOGGLE_KC_SPC:
    if (record->event.pressed) {
      if (spacebar_active) {
        unregister_code16(KC_SPC);
        rgblight_disable();
        spacebar_active = false;
      } else {
        register_code16(KC_SPC);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_WHITE);
        spacebar_active = true;
      }
    }
    break;

  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

                                                              [0] = LAYOUT(TOGGLE_KC_SPC, RCTL(KC_C), RCTL(KC_V)),

};
