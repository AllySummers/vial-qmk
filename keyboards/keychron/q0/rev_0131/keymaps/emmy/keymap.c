/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

// clang-format off

enum layers {
    BASE,
    FN_1,
    FN_2,
    FN_3,
    FN_4,
    FN_5,
    FN_6
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_numpad_6x5(
        TD(0),   TD(5),    MO(FN_1),KC_BSPC,  KC_TAB,
        TD(1),   KC_NUM,   KC_PSLS, KC_PAST,  KC_PMNS,
        TD(2),   KC_P7,    KC_P8,   KC_P9,    KC_PPLS,
        TD(3),   KC_P4,    KC_P5,   KC_P6,
        TD(4),   KC_P1,    KC_P2,   KC_P3,    KC_PENT,
        KC_LALT,KC_P0,             KC_PDOT
    ),

    [FN_1] = LAYOUT_numpad_6x5(
        TD(1),  QK_BOOT,  EE_CLR , DB_TOGG,  KC_VOLU,
        MC_1,   RGB_MOD,  RGB_VAI, RGB_HUI,  KC_DEL,
        MC_2,   RGB_RMOD, RGB_VAD, RGB_HUD,  KC_TRNS,
        MC_3,   RGB_SAI,  RGB_SPI, KC_MPRV,
        MC_4,   RGB_SAD,  RGB_SPD, KC_MPLY,  KC_TRNS,
        MC_5,   RGB_TOG,           KC_MNXT
    ),

    [FN_2] = LAYOUT_numpad_6x5(
        TD(2),   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,           KC_TRNS
    ),

    [FN_3] = LAYOUT_numpad_6x5(
        TD(3),     KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,           KC_TRNS
    ),

    [FN_4] = LAYOUT_numpad_6x5(
        TD(4),     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,           KC_TRNS
    ),

    [FN_5] = LAYOUT_numpad_6x5(
        TD(5),     KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,           KC_TRNS
    ),

    [FN_6] = LAYOUT_numpad_6x5(
        TD(6),     KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,           KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN_1] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [FN_2] = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
    [FN_3] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [FN_4] = {ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [FN_5] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN_6] = {ENCODER_CCW_CW(RGB_SPD, RGB_SPI)}
};
#endif // ENCODER_MAP_ENABLE

void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t tap_dance_0 = {
        KC_MPLY,
        MO(FN_1),
        KC_MUTE,
        KC_NO,
        200
    };

    vial_tap_dance_entry_t tap_dance_1 = {
        MC_1,
        MO(FN_2),
        KC_NO,
        KC_NO,
        200
    };

    vial_tap_dance_entry_t tap_dance_2 = {
        MC_2,
        MO(FN_3),
        KC_NO,
        KC_NO,
        200
    };

    vial_tap_dance_entry_t tap_dance_3 = {
        MC_3,
        MO(FN_4),
        KC_NO,
        KC_NO,
        200
    };

    vial_tap_dance_entry_t tap_dance_4 = {
        MC_4,
        MO(FN_5),
        KC_NO,
        KC_NO,
        200
    };

    vial_tap_dance_entry_t tap_dance_5 = {
        MC_4,
        MO(FN_6),
        KC_NO,
        KC_NO,
        200
    };

    dynamic_keymap_set_tap_dance(0, &tap_dance_0);
    dynamic_keymap_set_tap_dance(1, &tap_dance_1);
    dynamic_keymap_set_tap_dance(2, &tap_dance_2);
    dynamic_keymap_set_tap_dance(3, &tap_dance_3);
    dynamic_keymap_set_tap_dance(4, &tap_dance_4);
    dynamic_keymap_set_tap_dance(5, &tap_dance_5);
}

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}
