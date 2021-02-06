/* Copyright 2020 LAZYDESIGNERS
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
#define R_ENT LT(_NAV, KC_QUOTE)
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

void set_bolt_colors(void);

enum custom_keycodes {
  _QW = 0,
  _NAV,
  _NUM,
  _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT(
               KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
               L_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
               KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_NUM),
               KC_LCTL,  MO(_NUM),           KC_LALT, LCTL_T(KC_ENT),     KC_SPC,  KC_RGUI,                   KC_RCTL, KC_ESC,  TG(_FUNC)
             ),
    [_NAV] = LAYOUT(
                KC_GRV,   KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,   KC_DEL,
                KC_NO,    KC_BSLS, KC_QUOT,  KC_MINS, KC_EQL,  KC_NO,                KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_UNDS,   KC_F5,
                KC_TRNS,    KC_ESC,  KC_NO,    KC_PSCR, L_CURBR, R_CURBR,      KC_NO,  KC_LBRC, KC_RBRC,  KC_HOME, KC_END,   KC_INSERT, KC_TRNS,
                KC_TRNS,  KC_TRNS,                    KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,                      KC_TRNS,   KC_TRNS,   KC_TRNS
             ),
    [_NUM] = LAYOUT(
                KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5 ,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
                KC_ESC,     KC_PIPE, KC_NO,   KC_UNDS, KC_PLUS, KC_NO,                KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_ENT,
                KC_TRNS,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_0,    KC_1,    KC_2,    KC_3,    KC_NO,   KC_TRNS,
                KC_TRNS,      KC_TRNS,                     KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,                     KC_TRNS,   KC_TRNS,   KC_TRNS
             ),
    [_FUNC] = LAYOUT(
                RESET,    KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO,                    KC_NO, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,
                RGB_TOG,   KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO,                    KC_NO, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,
                KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO,            KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                CG_NORM,  KC_NO,                  CG_SWAP,  KC_NO,          KC_NO,  KC_NO,                   KC_NO,   KC_NO,   KC_TRNS
             )
};

// RGB code 
void set_bolt_colors(){
        rgblight_sethsv_at(191, 255, 128, 9);
        rgblight_sethsv_range(213, 255, 128, 10, 11);
        rgblight_sethsv_at(HSV_TEAL, 12);
}
// layer RGB Toggle 
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QW:
        rgblight_sethsv (HSV_MAGENTA);
        set_bolt_colors();
        break;
    case _NAV:
        rgblight_sethsv (HSV_PURPLE);
        set_bolt_colors();
        break;
    case _NUM:
        rgblight_sethsv (HSV_TEAL);
        set_bolt_colors();
        break;
    case _FUNC:
        rgblight_sethsv (HSV_CORAL);
        set_bolt_colors();
        break;
    default: 
        rgblight_sethsv (HSV_MAGENTA);
        set_bolt_colors();
        break;
    }
  return state;
}