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

enum layer_names {
    _QWERTY,
    _COLEMAK_DH,
    _DWN,
    _UP,
    _CONFIG,
};

#define _DFT 0
#define _LWR 1
#define _RSE 2
#define _ADJ 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DFT] = LAYOUT_split_3x6_3(
        KC_TAB     , KC_Q       , KC_W       , KC_E       , KC_R       , KC_T       ,
        KC_LCTRL   , KC_A       , KC_S       , KC_D       , KC_F       , KC_G       ,
        KC_LALT    , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B       ,
                                               KC_LGUI    , KC_LSHIFT  , FN_MO23    ,

        KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       , KC_BSPACE  ,
        KC_H       , KC_J       , KC_K       , KC_L       , KC_SCOLON  , KC_QUOTE   ,
        KC_N       , KC_M       , KC_COMMA   , KC_DOT     , KC_SLASH   , KC_ENTER   ,
        FN_MO13    , KC_SPACE   , KC_ESCAPE
    ),

    [_LWR] = LAYOUT_split_3x6_3(
        KC_TAB     , KC_Q       , KC_W       , KC_E       , KC_R       , KC_T       ,
        KC_LCTRL   , KC_A       , KC_S       , KC_D       , KC_F       , KC_G       ,
        KC_LALT    , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B       ,
                                               KC_LGUI    , KC_LSHIFT  , FN_MO23    ,

        KC_BSPACE  , KC_P       , KC_O       , KC_I       , KC_U       , KC_Y       ,
        KC_QUOTE   , KC_SCOLON  , KC_L       , KC_K       , KC_J       , KC_H       ,
        KC_ENTER   , KC_SLASH   , KC_DOT     , KC_COMMA   , KC_M       , KC_N       ,
        KC_ESCAPE  , KC_SPACE   , FN_MO13
    ),

    [_RSE] = LAYOUT_split_3x6_3(
        KC_TAB     , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      ,
        KC_TRNS    , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      ,
        KC_TRNS    , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      ,
                                               KC_TRNS    , KC_TRNS    , KC_TRNS    ,

        KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_TRNS    ,
        KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_TRNS    ,
        KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_NO      , KC_TRNS    ,
        KC_TRNS    , KC_TRNS    , KC_TRNS
    ),

    [_ADJ] = LAYOUT_split_3x6_3(
        RESET      , RGB_HUI    , RGB_SAI    , RGB_MOD    , RGB_VAI    , RGB_TOG    ,
        KC_TRNS    , RGB_HUD    , RGB_SAD    , RGB_RMOD   , RGB_VAD    , KC_NO      ,
        KC_TRNS    , KC_VOLD    , KC_VOLU    , KC_MUTE    , KC_BRID    , KC_BRIU    ,
                                               KC_TRNS    , KC_TRNS    , KC_TRNS    ,

        KC_BTN3    , KC_BTN1    , KC_BTN2    , KC_BTN4    , KC_NO      , KC_TRNS    ,
        KC_MS_L    , KC_MS_D    , KC_MS_U    , KC_MS_R    , KC_NO      , KC_TRNS    ,
        KC_WH_L    , KC_WH_D    , KC_WH_U    , KC_WH_R    , KC_NO      , KC_TRNS    ,
        KC_TRNS    , KC_TRNS    , KC_TRNS 
    )
};


#include "rgb.c"
#include "oled.c"
