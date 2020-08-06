#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _NAV 1
#define _NUM 2
#define _FUNC 3

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define L_ESC LT(_NAV, KC_ESC)
#define R_ENT LT(_NAV, KC_QUOTE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*!doc: Default */
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    L_ESC,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, R_ENT,
    KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_NUM),
    KC_LCTL, MO(_NUM), KC_LALT,           LCTL_T(KC_ENT),  KC_SPC,                    KC_RGUI, KC_ESC,  TG(_FUNC)
  ),
/*!end*/
//added sensible vim controls
/*!doc: Navigation*/
  [_NAV] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,   KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_UNDS,   KC_F5,
    _______, KC_ESC,  _______, KC_PSCR, L_CURBR, R_CURBR, KC_LBRC, KC_RBRC,  KC_HOME, KC_END,   KC_INSERT, KC_RSFT,
    KC_LCTL, KC_LGUI, _______,                   _______, _______,                    _______, _______, _______
  ),
/*!end*/
/*!doc: Numbers*/
  [_NUM] = LAYOUT( /* LAYER 2 */
    KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5 ,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,    KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    _______, KC_ENT,
    _______,   _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
    _______,   _______, _______,                   _______, _______,                   KC_VOLU, KC_VOLD, _______
  ),
/*!end*/
/*!doc: Functions*/
  [_FUNC] = LAYOUT( /* LAYER 3 */
    RESET,   _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,                      _______, _______, _______
  )
/*!end*/
};


void process_indicator_update(uint32_t state, uint8_t usb_led) {
  for (int i = 0; i < 3; i++) {
    setrgb(0, 0, 0, (LED_TYPE *)&led[i]);
  }
  setrgb(218, 23, 180, (LED_TYPE *)&led[0]);
  if (state & (1<<1)) {
    setrgb(32, 104, 255, (LED_TYPE *)&led[1]);
  }
  if (state & (1<<2)) {
    setrgb(10, 255, 125, (LED_TYPE *)&led[2]);
  }
  if (state & (1<<3)) {
    setrgb(247, 169, 42, (LED_TYPE *)&led[0]);
    setrgb(247, 169, 42, (LED_TYPE *)&led[1]);
    setrgb(247, 169, 42, (LED_TYPE *)&led[2]);

  }
  rgblight_set();
};

void keyboard_post_init_user(void) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

uint32_t layer_state_set_user(uint32_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};