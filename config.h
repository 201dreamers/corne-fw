/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

#define EE_HANDS

#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLED_NUM
#    define RGBLED_NUM 54
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif


#ifdef RGB_MATRIX_ENABLE
#   undef RGBLED_NUM
#   define RGBLED_NUM 54
#   undef RGBLED_SPLIT
#   define RGBLED_SPLIT { 27, 27 }
#   define RGB_MATRIX_SPLIT { 27, 27 }
#   define RGBLIGHT_LIMIT_VAL 120
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120

#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

#   define RGB_MATRIX_KEYPRESSES
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef  ENABLE_RGB_MATRIX_MULTISPLASH
#endif

#define SPLIT_LAYER_STATE_ENABLE
#define RGBLIGHT_LAYERS


// Reducing size of firmware
#define NO_MUSIC_MODE

#define LAYER_STATE_8BIT

#ifndef NO_DEBUG
    #define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif // !NO_PRINT

#ifndef LINK_TIME_OPTIMIZATION_ENABLE
#   define NO_ACTION_FUNCTION
#   define NO_ACTION_MACRO
#endif


// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_FONT_H "keyboards/crkbd/keymaps/vial/glcdfont.c"
