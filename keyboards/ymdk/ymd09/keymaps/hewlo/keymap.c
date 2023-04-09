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

/* === Combos === */

enum combo_events {
  /* START - do not move index */
  GOTO_BASE,
  GOTO_FN_1,
  GOTO_FN_2,
  GOTO_FN_3,
  /* END - do not move index */
};

const uint16_t PROGMEM layer_base_combo[]   = { KC_F20, KC_F21, COMBO_END};
const uint16_t PROGMEM layer_fn1_combo[]    = { KC_F20, KC_F16, COMBO_END};
const uint16_t PROGMEM layer_fn2_combo[]    = { KC_F20, KC_F19, COMBO_END};
const uint16_t PROGMEM layer_fn3_combo[]    = { KC_F20, KC_F22, COMBO_END};

combo_t key_combos[VIAL_COMBO_ENTRIES] = {
  [GOTO_BASE]     = COMBO_ACTION(layer_base_combo),
  [GOTO_FN_1]     = COMBO_ACTION(layer_fn2_combo),
  [GOTO_FN_2]     = COMBO_ACTION(layer_fn1_combo),
  [GOTO_FN_3]     = COMBO_ACTION(layer_fn3_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    layer_clear();
    layer_off(BASE);
    layer_off(FN_1);
    layer_off(FN_2);
    layer_off(FN_3);

    switch(combo_index) {
      case GOTO_BASE:
        layer_on(BASE);
        break;
      case GOTO_FN_1:
        layer_on(FN_1);
        break;
      case GOTO_FN_2:
        layer_on(FN_2);
        break;
      case GOTO_FN_3:
        layer_on(FN_3);
        break;
    }
  }
}

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
