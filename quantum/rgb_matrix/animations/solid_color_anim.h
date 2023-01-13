#define RGB_MATRIX_EFFECT_SOLID_COLOR
RGB_MATRIX_EFFECT(SOLID_COLOR)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV SOLID_COLOR_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h += abs8(g_led_config.point[i].y - k_rgb_matrix_center.y) + (g_led_config.point[i].x - time);
    return hsv;
}

bool SOLID_COLOR(effect_params_t* params) {
    return effect_runner_i(params, &SOLID_COLOR_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
