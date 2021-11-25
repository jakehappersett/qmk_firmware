/* Copyright 2020 melonbred
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

#define L_ESC LT(_NAV, KC_ESC)
#define Q_NUM LT(_NUM, KC_QUOT)
#define F_ENT LT(_FUNC, KC_ENT)
// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QW
  ,_NAV
  ,_NUM
  ,_FUNC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_2u1u_space(
        KC_TAB,        KC_Q,    KC_W,    KC_E,                KC_R, KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        L_ESC,         KC_A,    KC_S,    KC_D,                KC_F, KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,                KC_V, KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    MO(_NUM),
        KC_LCTL,       MO(_NUM), KC_LALT, LCTL_T(KC_ENT),       KC_MPLY, KC_SPC,                   KC_RGUI, KC_DOWN, F_ENT
    ),

    [_NAV] = LAYOUT_2u1u_space(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,   KC_DEL,
        _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_UNDS,   KC_F5,
        _______, KC_ESC,  _______, KC_PSCR, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,  KC_HOME, KC_END,   KC_INSERT, KC_RSFT,
        _______, _______, _______, _______,          _______, _______,                 _______, _______, _______ 
    ),
    
    [_NUM] = LAYOUT_2u1u_space(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5 ,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_ESC,  KC_PIPE, _______, KC_UNDS, KC_PLUS, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______,          _______, _______,                 _______, _______, _______ 
    ),

    [_FUNC] = LAYOUT_2u1u_space(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
        CG_NORM, XXXXXXX, CG_SWAP, XXXXXXX,          XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// Rotary Encoder Functions
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
