#pragma once

#ifdef OLED_ENABLE

#include <stdio.h>


#define L_BASE   0
#define L_LOWER  2
#define L_RAISE  4
#define L_ADJUST 8

#define ANIM_FRAME_DURATION 333  // how long each frame lasts in ms
#define KAPI
#define LUNA


static uint32_t animation_timer = 0;
static uint8_t curr_frame = 0;


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}


static void oled_render_separator(void) {
    oled_write_ln_P(PSTR("_____"), false);
}


static void oled_render_space(void) {
    oled_write_ln_P(PSTR("     "), false);
}


static void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_LOWER:
            oled_write_ln_P(PSTR("L W R"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("R S E"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("A D J"), false);
            break;
        case L_BASE:
        default:
            oled_write_ln_P(PSTR("D F T"), false);
            break;
    }
}


#ifdef RGBLIGHT_ENABLE
static void oled_render_hsv(void) {
    oled_write_P(PSTR("h:"), false);
    oled_write(get_u8_str(rgblight_get_hue(), ' '), false);
    oled_write_P(PSTR("s:"), false);
    oled_write(get_u8_str(rgblight_get_sat(), ' '), false);
    oled_write_P(PSTR("v:"), false);
    oled_write_ln(get_u8_str(rgblight_get_val(), ' '), false);
}
#endif


#ifdef RGB_MATRIX_ENABLE
static void oled_render_hsv(void) {
    oled_write_P(PSTR("m:"), false);
    oled_write(get_u8_str(rgb_matrix_get_mode(), ' '), false);
    oled_write_P(PSTR("h:"), false);
    oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
    oled_write_P(PSTR("s:"), false);
    oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
    oled_write_P(PSTR("v:"), false);
    oled_write_ln(get_u8_str(rgb_matrix_get_val(), ' '), false);
}
#endif


static void oled_render_keymods(uint8_t led_usb_state) {
    bool is_caps_on = false;
    if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
        is_caps_on = true;
    }
    oled_write_ln_P(PSTR("<cap>"), is_caps_on);
}


#ifdef KAPI
static void oled_render_kapi_animation(void) {
    static const char PROGMEM kapi_frames[2][16] = {
        {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0},
        {0x85, 0x86, 0x87, 0x88, 0x89, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0}
    };
    if (timer_elapsed32(animation_timer) > ANIM_FRAME_DURATION) {
        animation_timer = timer_read32();
        curr_frame = (curr_frame + 1) % 2;
        oled_write_ln_P(kapi_frames[curr_frame], false);
    }
};
#endif  // KAPI


#ifdef LUNA
static void oled_render_luna_animation(void) {
    static const char PROGMEM luna_frames[2][96] = {
        /* frame 'sit1', 32x22px */
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
         0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
         0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

        /* frame 'sit2', 32x22px */
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
         0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
         0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    if (timer_elapsed32(animation_timer) > ANIM_FRAME_DURATION) {
        animation_timer = timer_read32();
        curr_frame = (curr_frame + 1) % 2;
        oled_write_raw_P(luna_frames[curr_frame], sizeof(luna_frames[curr_frame]));
    }
}
#endif  // LUNA


static void oled_render_master_screen(void) {
    oled_render_layer_state();
    oled_render_separator();
    oled_render_space();

    oled_render_keymods(host_keyboard_leds());
    oled_render_space();
    oled_render_space();

#   ifdef KAPI
    oled_render_kapi_animation();
#   endif  // KAPI
}


static void oled_render_slave_screen(void) {
    oled_write_ln_P(PSTR("crkbd"), false);
    oled_render_separator();
    oled_render_space();

#   if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    oled_render_hsv();
#   endif  // RGBLIGHT_ENABLE || RGB_MATRIX_ENABLE

#   ifdef LUNA
    oled_render_space();
    oled_render_luna_animation();
#   endif  // LUNA
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_master_screen();
    } else {
        oled_render_slave_screen();
    }

    return false;
}
#endif // OLED_ENABLE
