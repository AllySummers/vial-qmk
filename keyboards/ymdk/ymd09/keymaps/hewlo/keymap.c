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
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
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
  LAYER_UP,
  LAYER_DOWN,
};

const uint16_t PROGMEM layer_base_combo[]   = { KC_F20, KC_F16, COMBO_END};
const uint16_t PROGMEM layer_fn2_combo[]    = { KC_F20, KC_F18, COMBO_END};
const uint16_t PROGMEM layer_fn1_combo[]    = { KC_F20, KC_F22, COMBO_END};
const uint16_t PROGMEM layer_fn3_combo[]    = { KC_F20, KC_F24, COMBO_END};
const uint16_t PROGMEM layer_up_combo[]     = { KC_F20, KC_F17, COMBO_END};
const uint16_t PROGMEM layer_down_combo[]   = { KC_F20, KC_F23, COMBO_END};

combo_t key_combos[] = {
  [GOTO_BASE]     = COMBO_ACTION(layer_base_combo),
  [GOTO_FN_1]     = COMBO_ACTION(layer_fn2_combo),
  [GOTO_FN_2]     = COMBO_ACTION(layer_fn1_combo),
  [GOTO_FN_3]     = COMBO_ACTION(layer_fn3_combo),
  [LAYER_UP]      = COMBO_ACTION(layer_up_combo),
  [LAYER_DOWN]    = COMBO_ACTION(layer_down_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    layer_clear();

    switch(combo_index) {
      case LAYER_UP:
        if (layer_state_is(BASE)) {
          layer_on(FN_1);
        } else if (layer_state_is(FN_1)) {
          layer_on(FN_2);
        } else if (layer_state_is(FN_2)) {
          layer_on(FN_3);
        } else if (layer_state_is(FN_3)) {
          layer_on(BASE);
        }
        break;
      case LAYER_DOWN:
        if (layer_state_is(BASE)) {
          layer_on(FN_3);
        } else if (layer_state_is(FN_1)) {
          layer_on(BASE);
        } else if (layer_state_is(FN_2)) {
          layer_on(FN_1);
        } else if (layer_state_is(FN_3)) {
          layer_on(FN_2);
        }
        break;
      case GOTO_BASE:
        layer_on(GOTO_BASE);
        break;
      case GOTO_FN_1:
        layer_on(GOTO_FN_1);
        break;
      case GOTO_FN_2:
        layer_on(GOTO_FN_2);
        break;
      case GOTO_FN_3:
        layer_on(GOTO_FN_3);
        break;
    }
  }
}

/* === Layer Lighting === */
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case FN_1:
      rgblight_setrgb_at(RGB_RED, 1);
      break;
    case FN_2:
      rgblight_setrgb_at(RGB_RED, 2);
      break;
    case FN_3:
      rgblight_setrgb_at(RGB_RED, 3);
      break;
    case BASE:
    default:
      rgblight_setrgb(RGB_BLUE);
      break;
    }
  return state;
}
