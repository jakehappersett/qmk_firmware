/* Copyright 2018 Holten Campbell
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

#define _QW 0
#define _NAV 1
#define _NUM 2
#define _FUNC 3

#define _______ KC_TRNS
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)
#define L_ESC LT(_NAV, KC_ESC)
#define R_ENT LT(_NAV, KC_QUOTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT(
		KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    KC_DEL, KC_BSPC,
		L_ESC ,   KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J,     KC_K, KC_L,    KC_SCLN, KC_QUOTE,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          _______,KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, MO(_NUM),
		KC_LCTL,  MO(_NUM),                    KC_LALT,KC_ENT,	      KC_SPC, MO(_NUM),                         KC_RGUI, TG(_FUNC)
    ),

    [_NAV] = LAYOUT(
		KC_GRV,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,          KC_CIRC,   KC_AMPR,    KC_ASTR,     KC_LPRN,   KC_RPRN,   KC_VOLD,   KC_VOLU,
		KC_ESC,    KC_BSLS,   KC_QUOT,   KC_MINS,   KC_EQL,    _______,          KC_LEFT,   KC_DOWN,    KC_UP,       KC_RIGHT,  _______,   KC_F5,
		_______,   _______,   _______,   _______,   L_CURBR,   R_CURBR,          _______,   KC_LBRC,    KC_RBRC,     KC_HOME,   KC_END,  KC_INSERT,   _______,
		BL_TOGG,   BL_STEP,                         _______,   _______,	         _______,   _______,                                       _______,   _______
    ),

    [_NUM] =  LAYOUT(
		KC_TILD,  KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,    KC_8,   KC_9,   KC_0,      _______,  _______,
		KC_ESC,  KC_PIPE,   KC_DQUO,   KC_UNDS,   KC_PLUS,     _______,          _______,   KC_4,    KC_5,   KC_6,   _______,   _______,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   KC_0,    KC_1,   KC_2,   KC_3,   _______,  _______,
		_______,  _______,                         _______,    _______,	         _______,   _______,                               _______,  _______
    ),

    [_FUNC] = LAYOUT(
		_______,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_F10,    KC_F11,   KC_F12,
		_______,  _______,   _______,   _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,
		_______,  _______,   RESET,     _______,   _______,    _______,          _______,   _______,  _______, _______, _______,   _______,  _______,
		_______,  _______,                         _______,    _______,	         _______,   _______,                               _______,  _______
    )
};

void matrix_init_user(void) {
  // set Base LED to output turn it on by default
  setPinOutput(B1);
  writePinHigh(B1);
  // set NAV layer LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set NUM layer LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

//function for layer indicator LEDs
layer_state_t layer_state_set_user(layer_state_t state)
{
  switch (get_highest_layer(state)) {
      case _NAV:
          writePinHigh(B2);
          break;
      case _NUM:
          writePinHigh(B3);
          break;
      case _FUNC:
          writePinHigh(B1);
          writePinHigh(B2);
          writePinHigh(B3);
          break;
      default: 
          // Default to first light on 
          writePinHigh(B1);
          writePinLow(B2);
          writePinLow(B3);
          break;
  }
  return state;
}

