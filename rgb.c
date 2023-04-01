#pragma once

#undef INDICATE_LAYER_WITH_LIGHT
#if defined(RGBLIGH_ENABLE) && defined(INDICATE_LAYER_WITH_LIGHT)

#include "quantum/rgblight/rgblight.h"


const rgblight_segment_t PROGMEM layer_lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, HSV_PURPLE},
    {34, 3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM layer_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, HSV_ORANGE},
    {34, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM layer_adjust[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, HSV_SPRINGGREEN},
    {34, 3, HSV_SPRINGGREEN}
);

const rgblight_segment_t* const PROGMEM local_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_lower,
    layer_raise,
    layer_adjust
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = local_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
}

#endif


#if defined(RGB_MATRIX_ENABLE) && defined(INDICATE_LAYER_WITH_LIGHT)

static void set_color_for_keys_with_keylight(HSV color, uint8_t led_min, uint8_t led_max) {
    if (color.v > rgb_matrix_get_val()) {
        color.v = rgb_matrix_get_val();
    }

    RGB color_rgb = hsv_to_rgb(color);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, color_rgb.r, color_rgb.g, color_rgb.b);
        }
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (layer_state) {
        case L_BASE:
            return;
        case L_LOWER:
            set_color_for_keys_with_keylight((HSV){HSV_ORANGE}, led_min, led_max);
            break;
        case L_RAISE:
            set_color_for_keys_with_keylight((HSV){HSV_PURPLE}, led_min, led_max);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            set_color_for_keys_with_keylight((HSV){HSV_GREEN}, led_min, led_max);
            break;
    }
}

#endif
