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
//                 |               |               |              |               ||               |                 |             |                |              |               |              |
    [_DFT] = LAYOUT_split_3x6_3(
        KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,        KC_BSPC,
       KC_LCTL,           KC_A,           KC_S,           KC_D,           KC_F,           KC_G,            KC_H,           KC_J,           KC_K,           KC_L,        KC_SCLN,       KC_QUOTE,
       KC_LALT,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,            KC_N,           KC_M,       KC_COMMA,         KC_DOT,       KC_SLASH,      KC_ESCAPE,
                                                       KC_LGUI,        KC_LSFT,          MO(1),           MO(2),       KC_SPACE,       KC_ENTER
    ),

//                 |               |               |              |               ||               |                 |             |                |              |               |              |
    [_LWR] = LAYOUT_split_3x6_3(
       KC_TRNS,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,        KC_HOME,        KC_PGUP,          KC_NO,          KC_NO,        KC_TRNS,
       KC_TRNS,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,         KC_LEFT,        KC_DOWN,          KC_UP,       KC_RIGHT,          KC_NO,        KC_PSCR,
       KC_TRNS,       KC_SPACE,          KC_NO,          KC_NO,          KC_NO,      KC_DELETE,           KC_NO,         KC_END,        KC_PGDN,          KC_NO,      KC_DELETE,        KC_TRNS,
                                                       KC_TRNS,        KC_TRNS,        KC_TRNS,           MO(3),        KC_TRNS,        KC_TRNS
    ),

//                 |               |               |              |               ||               |                 |             |                |              |               |              |
    [_RSE] = LAYOUT_split_3x6_3(
       KC_TRNS,     LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_TRNS,
       KC_TRNS,     LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),       KC_MINUS,       KC_EQUAL,         KC_LBRC,     LSFT(KC_9),  LSFT(KC_LBRC),          KC_NO,  LSFT(KC_BSLS),        KC_CAPS,
       KC_TRNS,       KC_GRAVE, LSFT(KC_GRAVE),          KC_NO, LSFT(KC_MINUS), LSFT(KC_EQUAL),         KC_RBRC,     LSFT(KC_0),  LSFT(KC_RBRC),          KC_NO,        KC_BSLS,        KC_TRNS,
                                                       KC_TRNS,        KC_TRNS,          MO(3),         KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

//                 |               |               |              |               ||               |                 |             |                |              |               |              |
    [_ADJ] = LAYOUT_split_3x6_3(
       KC_TRNS,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,         RGB_TOG,        RGB_MOD,        RGB_VAI,        RGB_SAI,        RGB_HUI,        KC_TRNS,
       KC_TRNS,          KC_F6,          KC_F7,          KC_F8,          KC_F9,         KC_F10,           KC_NO,          KC_NO,          KC_NO,        KC_BRID,        KC_BRIU,         QK_RBT,
       KC_TRNS,         KC_F11,         KC_F12,        KC_VOLD,        KC_VOLU,        KC_MUTE,         KC_MNXT,       RGB_RMOD,        RGB_VAD,        RGB_SAD,        RGB_HUD,        KC_TRNS,
                                                       KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS
    )
};


#include "rgb.c"
#include "oled.c"
