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
#define SW_ENT LCTL_T(KC_ENT)
#define L_ESC LT(_NAV, KC_ESC)
#define MODSLSH LT(_NUM, KC_SLSH)
#define _____ KC_TRNS

enum layers { _QWERTY, _NAV, _NUM, _FN };

enum combos { LQ_SEMI, ZX_NUM };

const uint16_t PROGMEM semi_combo[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM num_combo[]  = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {[LQ_SEMI] = COMBO(semi_combo, KC_SCLN), [ZX_NUM] = COMBO(num_combo, MO(_NUM))};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY] = LAYOUT_wkl(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, L_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MODSLSH, MO(_NUM), KC_RALT, SW_ENT, KC_SPC, KC_RGUI, MO(_FN)),
                                                              [_NUM]    = LAYOUT_wkl(KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_PIPE, KC_NO, KC_UNDS, KC_PLUS, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, _____, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO, _____, KC_VOLU, _____, _____, KC_NO, KC_NO),
                                                              [_NAV]    = LAYOUT_wkl(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_NO, KC_BSLS, KC_NO, KC_MINS, KC_EQL, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_F5, _____, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_HOME, KC_END, KC_INSERT, _____, KC_NO, _____, _____, KC_NO, KC_NO),
                                                              [_FN]     = LAYOUT_wkl(RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, _____, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, CG_NORM, CG_SWAP, KC_NO, KC_NO, KC_NO, KC_NO)};
