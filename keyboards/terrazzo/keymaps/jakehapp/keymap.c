#include <print.h>
#include "terrazzo.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
  ANI_UP = SAFE_RANGE,
  ANI_DN,
  MODE,
  ENC_BTN,
  SPD
};

enum layers {
	_QWERTY,
	_NAV,
	_NUM,
	_FN
};
const uint16_t PROGMEM semi_combo[] = {KC_L, KC_QUOT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(semi_combo, KC_SCLN)};


#define MODSLSH LT(_NUM, KC_SLSH)
#define L_ESC LT(_NAV, KC_ESC)
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
		  KC_MUTE,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
	    ANI_UP,   L_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,            KC_QUOT,
	    KC_MNXT,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          MODSLSH, 
	    KC_MPLY,           MO(_NUM), KC_RALT,          LCTL_T(KC_ENT),    KC_SPC,           KC_RGUI, MO(_FN)
  ),
  
  [_NUM] = LAYOUT(
      _______, KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	    _______, KC_PIPE, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX,  XXXXXXX,    KC_4,    KC_5,    KC_6,             KC_SCLN,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_0,       KC_1,    KC_2,    KC_3,    _______, 
	    _______,          _______, _______,          _______,          _______,              _______, _______
  ),

  [_NAV] = LAYOUT(
      _______, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_DEL,
	    _______, _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,           KC_F5,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, L_CURBR, R_CURBR, KC_LBRC, KC_RBRC, KC_HOME, KC_END,             KC_INSERT, 
	    _______,          _______, _______,          _______,          _______,          _______, _______
  ),

  [_FN] = LAYOUT(
		  _______,  RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
		  KC_F9,    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_F11,  KC_F12,          _______, 
		  KC_F10,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         CG_TOGG, 
		  KC_F11,            CG_NORM, CG_SWAP,          _______,          _______,          _______, _______
  )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch(keycode) {
            case ANI_UP:
                terrazzo_step_mode();
                return true;
            case ANI_DN:
                terrazzo_step_mode_reverse();
                return true;
            case MODE:
                dprint("LED MODE\n");
                return true;
        }
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(biton32(layer_state)) {
      case _NAV:
        clockwise ? tap_code(KC_PGUP) : tap_code(KC_PGDN);
        break;
      default:
        clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
        break;
    }   
}

void keyboard_post_init_user(void) {
  // debug_enable=true;
}