/* Copyright 2015-2018 Jack Humbert
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

#pragma once

#ifndef __ASSEMBLER__
#    include "pin_defs.h"
#endif

/* diode directions */
#define COL2ROW 0
#define ROW2COL 1

#include "song_list.h"

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define COMBO_TERM 30  // default is 50.  50ms produces false positives when typing kinda fast

#define echo false
#define COMBO_COUNT 100
/* #define RGBLIGHT_LAYER_BLINK 1 */
/* #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF */

#define FORCE_NKRO


#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 6

#undef TAPPING_TERM
#define TAPPING_TERM 195

#define PERMISSIVE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"yBwNd/qD05Z"
#define RGB_MATRIX_STARTUP_SPD 60


#define BUTTMAN 69

#ifndef WEBUSB_ENABLE
#    define WEBUSB_PAIR KC_NO
#endif

#define LEADER_TIMEOUT 300
