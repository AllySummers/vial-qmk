#include QMK_KEYBOARD_H

/* === Keymap & Layers === */

enum layers {
  BASE,
  FN_1,
  FN_2,
  FN_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_F16,     KC_F17,     KC_F18,
    KC_F19,     KC_F20,     KC_F21,
    KC_F22,     KC_F23,     KC_F24
  ),

  [FN_1] = LAYOUT(
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),

  [FN_2] = LAYOUT(
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),

  [FN_3] = LAYOUT(
    KC_TRNS,    KC_TRNS,    EE_CLR,
    KC_TRNS,    KC_TRNS,    DB_TOGG,
    KC_TRNS,    KC_TRNS,    QK_BOOT
  ),
};

/* === Layer Lighting === */

/*
  LEDs {
    5, 0, 1,
    2, 3, 4,
    8, 6, 7
  }
*/

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case FN_1:
      rgblight_setrgb_at(RGB_RED, 5);
      break;
    case FN_2:
      rgblight_setrgb_at(RGB_RED, 2);
      break;
    case FN_3:
      rgblight_setrgb_at(RGB_RED, 8);
      break;
    case BASE:
    default:
      rgblight_setrgb(RGB_BLUE);
      break;
    }
  return state;
}
