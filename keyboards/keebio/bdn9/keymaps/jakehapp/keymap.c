/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

#define NORM   TO(_NORM)
#define PAGE   TO(_PAGE)

enum layers {
    _NORM = 0,
    _PAGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                   |      | Knob 2: Page Dn/Up |
        | Play media        | Home | Press: Play/Pause  |
        | Toggle to Page    | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [_NORM] = LAYOUT(
	    KC_MPLY, KC_HOME, KC_MUTE,
        PAGE   , KC_UP  , RGB_MOD,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        |                |      | Knob 2: Page Dn/Up |
        | RESET          | N/A  | Media Stop         |
        | Toggle to Norm | Home | RGB Mode           |
        | Media Previous | End  | Media Next         |
     */
    [_PAGE] = LAYOUT(
        RESET  , BL_STEP, KC_PGDN,
        NORM   , KC_HOME, RGB_MOD,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _PAGE:
            //set the rgb 
            rgblight_setrgb (0x00,  0x80, 0x75);
            break;
        default: 
            //set the rgb 
            rgblight_setrgb (0x73,  0x00, 0xFF);
            break;
    }
  return state;
}


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        switch(get_highest_layer(layer_state)) {
            case _PAGE:
                if (clockwise) {
                    tap_code(KC_WH_U);
                    break;
                } else {
                    tap_code(KC_WH_D);
                    break;
                }
            default: 
                if (clockwise) {
                    tap_code(KC_VOLD);
                    break;
                } else {
                    tap_code(KC_VOLU);
                    break;
                }
            
        }
    }
}
