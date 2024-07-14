#include "sketch.h"
#include "print.h"

#define L_ESC LT(_NAV, KC_ESC)
#define F_ENT LT(_FUNC, KC_ENT)

#define _______ KC_TRNS

enum layer_names {
  _QW
  ,_NAV
  ,_NUM
  ,_FUNC
};

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT(
    KC_TAB,   KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC, 
    L_ESC,    KC_A,       KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  MO(_NUM), 
    KC_LCTL,  MO(_NUM),   KC_LALT,  _______, KC_SPC,     KC_SPC,    KC_RGUI,  KC_RSFT,  KC_NO,    F_ENT),
  [_NAV] = LAYOUT(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,   KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_UNDS,   KC_F5,
    _______, KC_ESC,  _______, KC_PSCR, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,  KC_HOME, KC_END,   KC_INSERT, KC_RSFT,
    _______, _______, _______, _______,          _______, _______,         _______, _______, _______, _______),
  [_NUM] = LAYOUT(
    KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5 ,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,    KC_PIPE, _______, KC_UNDS, KC_PLUS, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
    _______,   _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______, _______,          _______, _______,         _______, _______, _______, _______),
  [_FUNC] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RESET,  _______, _______, _______, _______, _______, _______, _______,   _______,   _______,   _______,   KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______,  KC_MPLY,  KC_VOLD,
    CG_NORM, _______, CG_SWAP, _______,           _______,  _______,              _______, _______, _______, _______)
};



void process_indicator_update(layer_state_t state, uint8_t usb_led) {
  for (int i = 0; i < 10; i++) {
    setrgb(0, 0, 0, (LED_TYPE *)&led[i]);
  }
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  
  rgblight_set();
};

void keyboard_post_init_user(void) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_leds());
    return state;
};
// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(state)) {
//     case _NAV:
//         rgblight_sethsv (HSV_PURPLE);
//         rgblight_mode(RGBLIGHT_MODE_KNIGHT);
//         break;
//     case _NUM:
//         rgblight_sethsv (HSV_TEAL);
//         rgblight_mode(RGBLIGHT_MODE_KNIGHT);
//         break;
//     case _FUNC:
//         rgblight_sethsv (HSV_CORAL);
//         rgblight_mode(RGBLIGHT_MODE_SNAKE);
//         break;
//     default: 
//         process_indicator_update(state, host_keyboard_leds());
//         break;
//     }
//   return state;
// };