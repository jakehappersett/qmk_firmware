#ifndef CONFIG_H
#define CONFIG_H
#include "config_common.h"

#define VENDOR_ID 0xFEAE
#define PRODUCT_ID 0x8947
#define DEVICE_VER 0x0001
#define MANUFACTURER trash man
#define PRODUCT Ketch
#define DESCRIPTION Ketch 40%

#define MATRIX_ROWS 6
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS {F5, F1, F0, F7, B6, F6}
#define MATRIX_COL_PINS {D0, D1, D2, D3, D4, D5, D6, D7}




#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_PIN B0

#define DEBOUNCE 5
#define TAPPING_TERM 175

#define USB_MAX_POWER_CONSUMPTION 100
#define PERMISSIVE_HOLD
#define PORTSCAN D0
#define PORTSCAN_PINS 255
#define RGB_DI_PIN F4
#define RGBLED_NUM 10
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define IS_COMMAND () (keyboard_report-> mods == (MOD_BIT (KC_LSHIFT) | MOD_BIT (KC_RSHIFT)))
#endif