#pragma once

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// There are a number of variations depending on the layout of your bottom row.
// The arrow variant adds an additional key on the bottom-right, while the
// command variant adds an additional key on the bottom-left. arrow-command is a
// combination of both of those, having an additional key on both sides.
//
// Please note that the numbering of the macro arguments are based on the
// numbers of the keys on the PCB.

#define LAYOUT(K39, K40, K41, K42, K0, K1, K2, K3, K4, K5, K6, K7, K32, K33, K34, K35, K8, K9, K10, K11, K12, K13, K14, K15, K38, K45, K44, K36, K16, K17, K18, K19, K20, K21, K22, K23, K37, K43, K24, K25, K26, K27, K28, K29, K30, K31) { \
  { K0, K1, K2, K3, K4, K5, K6, K7 }, \
  { K8, K9, K10, K11, K12, K13, K14, K15 }, \
  { K16, K17, K18, K19, K20, K21, K22, K23 }, \
  { K24, K25, K26, K27, K28, K29, K30, K31 }, \
  { K32, K33, K34, K35, K36, K37, K38, KC_NO }, \
  { K39, K40, K41, K42, K43, K44, K45, KC_NO } \
}
