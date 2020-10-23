#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define SW_CTCL MAGIC_SWAP_CONTROL_CAPSLOCK
#define US_CTCL MAGIC_UNSWAP_CONTROL_CAPSLOCK
#define WIN_LCK LGUI(KC_L)

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN,
  //+--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------+
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,
  //+--------+--------+--------+--------+--------+--------+        +        +        +--------+--------+--------+--------+--------+--------+
                                       KC_LALT, LOWER,   KC_SPC,               KC_ENT,  RAISE,   KC_LALT
                                // +--------+--------+--------+                 +--------+--------+--------+
  ),

  [_LOWER] = LAYOUT(
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, JP_CIRC, JP_TILD, KC_BSPC,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_TAB,  _______, G(KC_C), KC_END,  _______, _______,                            G(KC_V), _______, KC_TAB,  _______, KC_UP,   JP_PIPE,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_LCMD, KC_HOME, G(KC_F), KC_DEL,  KC_RGHT, _______,                            KC_BSPC, _______, _______, JP_LBRC, JP_RBRC, JP_YEN,
  //+--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------+
     KC_LSFT, G(KC_Z), G(KC_X), _______, _______, KC_LEFT, _______,          _______, KC_DOWN, KC_ENT,  _______, JP_LCBR, JP_RCBR, JP_BSLS,
  //+--------+--------+--------+--------+--------+--------+        +        +        +--------+--------+--------+--------+--------+--------+
                                       KC_LGUI, _______, _______,              _______,  _______, _______
                                // +--------+--------+--------+                 +--------+--------+--------+
  ),

  [_RAISE] = LAYOUT(
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_TAB,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_INS,  KC_PGUP,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     KC_LCTL, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_UP,   KC_PGDN,
  //+--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------+
     KC_LSFT, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,
  //+--------+--------+--------+--------+--------+--------+        +        +        +--------+--------+--------+--------+--------+--------+
                                       KC_LALT, _______, _______,              _______, _______, KC_RCTL
                                // +--------+--------+--------+                 +--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT(
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,                            RGB_TOG, RGB_MOD, RGB_RMOD, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------+                          +--------+--------+--------+--------+--------+--------+
     SW_CTCL, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------+
     US_CTCL, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------+        +        +        +--------+--------+--------+--------+--------+--------+
                                       WIN_LCK, _______, _______,              _______, _______, KC_SLEP
                                // +--------+--------+--------+                 +--------+--------+--------+
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
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
