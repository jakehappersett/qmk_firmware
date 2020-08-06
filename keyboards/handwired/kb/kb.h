#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, \
	K10  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   KC_NO, KC_NO }  \
}

#endif