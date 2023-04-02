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

#include QMK_KEYBOARD_H


#define _DFT 0
#define _LWR 1
#define _RSE 2
#define _ADJ 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DFT] = LAYOUT_split_3x6_3(
         KC_TAB,        KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,         KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,   KC_BSPACE,
       KC_LCTRL,        KC_A,        KC_S,        KC_D,        KC_F,        KC_G,         KC_H,        KC_J,        KC_K,        KC_L,   KC_SCOLON,    KC_QUOTE,
        KC_LALT,        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,         KC_N,        KC_M,    KC_COMMA,      KC_DOT,    KC_SLASH,    KC_ENTER,
                                               KC_LGUI,     FN_MO23,   KC_LSHIFT,     KC_SPACE,     FN_MO13,   KC_ESCAPE
    ),

    [_LWR] = LAYOUT_split_3x6_3(
       KC_GRAVE,        KC_1,        KC_2,        KC_3,        KC_4,    KC_EQUAL,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,     KC_TRNS,
        KC_TRNS,        KC_5,        KC_6,        KC_7,        KC_8,    KC_MINUS,      KC_LEFT,     KC_DOWN,       KC_UP,    KC_RIGHT,  KC_PSCREEN, KC_CAPSLOCK,
        KC_TRNS,        KC_9,        KC_0, KC_LBRACKET, KC_RBRACKET,   KC_BSLASH,      KC_HOME,      KC_END,     KC_PGUP,   KC_PGDOWN,   KC_DELETE,     KC_TRNS,
                                               KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS
    ),

    [_RSE] = LAYOUT_split_3x6_3(
          KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,        KC_F7,       KC_F8,       KC_F9,      KC_F10,      KC_F11,      KC_F12,
        KC_TRNS,     KC_BRID,     KC_BRIU,     KC_VOLD,     KC_VOLU,     KC_MUTE,      RGB_MOD,     RGB_VAI,     RGB_SAI,     RGB_HUI,     RGB_TOG,     KC_TRNS,
        KC_TRNS,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,     RGB_RMOD,     RGB_VAD,     RGB_SAD,     RGB_HUD,       RESET,     KC_TRNS,
                                               KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS
    ),

    [_ADJ] = LAYOUT_split_3x6_3(
          KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
          KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
          KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
                                                 KC_NO,       KC_NO,     KC_TRNS,      KC_TRNS,       KC_NO,       KC_NO
    )
};


#include "rgb.c"
#include "oled.c"
