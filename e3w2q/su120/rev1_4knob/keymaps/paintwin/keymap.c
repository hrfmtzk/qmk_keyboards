/* Copyright 2019 e3w2q
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
#include "keymap_jp.h"


enum encoder_number {
  _1ST_ENC = 0,
  _2ND_ENC,
};

enum layer_number {
  _L0 = 0,
  _L1,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_L0] = LAYOUT( /* Base */
    C(KC_Z),  KC_E,     KC_P,     XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_SLSH,  KC_H,     KC_R,     XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_LSFT,  KC_LALT,  KC_SPC,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    JP_COMM,  JP_DOT,   MO(_L1),  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  C(KC_S),   XXXXXXX,  XXXXXXX,

    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_L1] = LAYOUT(
    KC_4,     KC_5,     KC_6,     XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_R,     KC_T,     KC_Y,     XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F,     KC_G,     KC_H,     XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_V,     KC_B,     _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,

    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
    case _1ST_ENC:
        switch (biton32(layer_state)) {
        case _L0:
            if (clockwise) {
                tap_code(JP_RBRC);
            } else {
                tap_code(JP_LBRC);
            }
            break;
        case _L1:
            if (clockwise) {
                tap_code(JP_DOT);
            } else {
                tap_code(JP_COMM);
            }
            break;
        }
    }
}
