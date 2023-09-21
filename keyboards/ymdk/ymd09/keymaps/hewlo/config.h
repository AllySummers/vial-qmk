/* Vial configuration */

#pragma once

#define VIAL_KEYBOARD_UID {0x44, 0x71, 0x9C, 0x1D, 0x1A, 0xCF, 0x55, 0xDA}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }

#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 300

/* === RGB === */

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT // Sets the default mode, if none has been set
#define RGBLIGHT_DEFAULT_HUE 170 // Sets the default hue value, if none has been set
#define RGBLIGHT_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#define RGBLIGHT_DEFAULT_VAL 255 // Sets the default brightness value, if none has been set
#define RGBLIGHT_DEFAULT_SPD 0 // Sets the default animation speed, if none has been set
#define RGBLIGHT_SLEEP // If defined, synchronization functionality for split keyboards is added

#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

#undef RGBLIGHT_ANIMATIONS
