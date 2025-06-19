// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

/*************************************************************************************************************
*
* Layer 1: /S = shift, /C = ctrl, /A = opt, /G = cmd
*                                                                                       F14    F15     F16
* ,---------------------------------------------------------------------------------------------------------.
* | Caps   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   |  F11 |  F12 | Lock | Grab | DspUp| DspDn| MicMute|
* |--------+------+------+------+------+------+-----------------+------+------+------+------+------+--------|
* |  `~    |  1!  |  2@  |  3#  |  4$  |  5%  |                 |  6^  |  7&  |  8*  |  9(  |  0)  |  -_    |
* |--------+------+------+------+------+------|                 +------+------+------+------+------+--------|
* |  Tab   |   Q  |   W  |   E  |   R  |   T  |                 |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                 |------+------+------+------+------+--------|
* |  ESC   | A/C  | S/A  | D/G  | F/S  |   G  |                 |   H  | J/S  | K/G  | L/A  | ;:/C | '"     |
* |--------+------+------+------+------+------|                 |------+------+------+------+------+--------|
* |  C-;   |   Z  |   X  |   C  |   V  |   B  |                 |   N  |   M  |  ,.  |  .>  |  /?  | C-y    |
* `--------+------+------+------+------+-------                 `------+------+------+------+------+--------'
*          | Undo |ViMove| Copy | Paste|                               |  [{  |  ]}  |  =+  | Redo |
*          `---------------------------'                               `---------------------------'
*                                      ,------+------.   ,------+------.
*                                      | Left | Right|   | Up   | Down |
*                               ,------|------|------|   |------+------+------.
*                               |      |      | Home |   | pgUp |      |      |
*                               | BkSp | Esc  |------|   |------|Return| Space|
*                               |      |      | End  |   | pgDn |      |      |
*                               `--------------------'   `--------------------'
*
*/
/*************************************************************************************************************
* Layer 2: Vim Move
*
* ,---------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |      |   |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+-----------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                 |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                 +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                 |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                 |------+------+------+------+------+--------|
* |        |      |      |      |      |C-left|                 | left | down |  up  | rght |C-rght|        |
* |--------+------+------+------+------+------|                 |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                 |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                 `------+------+------+------+------+--------'
*          |      |      |      |      |                               |      |      |      |      |
*          `---------------------------'                               `---------------------------'
*                                      ,------+------.   ,------+------.
*                                      |      |      |   |      |      |
*                               ,------|------|------|   |------+------+------.
*                               |      |      |      |   |      |      |      |
*                               |      |      |------|   |------|      |      |
*                               |      |      |      |   |      |      |      |
*                               `--------------------'   `--------------------'
*
*/

#define QWERTY 0 // Base qwerty
#define VIMOVE 1 // Vim Movement

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
    KC_CAPS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12,     LCTL(LGUI(KC_Q)), LCTL(LGUI(LSFT(KC_4))),  KC_F14,  KC_F15,         KC_F16,
    KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                               KC_6,       KC_7,           KC_8,           KC_9,           KC_0,               KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                               KC_Y,       KC_U,           KC_I,           KC_O,           KC_P,               KC_BSLS,
    KC_ESC,         LCTL_T(KC_A),   LALT_T(KC_S),   LGUI_T(KC_D),   LSFT_T(KC_F),   KC_G,                                               KC_H,       RSFT_T(KC_J),   RGUI_T(KC_K),   RALT_T(KC_L),   RCTL_T(KC_SCLN),    KC_QUOT,
    LCTL(KC_SCLN),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                               KC_N,       KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,            LCTL(KC_Y),
                    LGUI(KC_Z),     MO(VIMOVE),     LGUI(KC_C),     LGUI(KC_V),                                                                     KC_LBRC,        KC_RBRC,        KC_EQL,         LSG(KC_Z),
                                                                                    KC_LEFT,    KC_RIGHT,                   KC_UP,      KC_DOWN,
                                                                                                KC_HOME,                    KC_PGUP,
                                                                    KC_BSPC,        KC_ESC,     KC_END,                     KC_PGDN,    KC_ENTER,   KC_SPC
  ),

  [VIMOVE] = LAYOUT(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    LCTL(KC_LEFT),                                                      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   LCTL(KC_RIGHT), KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,
                                                                            KC_TRNS,                                    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,    KC_TRNS
  )
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LSFT_T(KC_F):
        return true;
    case RSFT_T(KC_J):
        return true;
    default:
        return false;
    }
}
