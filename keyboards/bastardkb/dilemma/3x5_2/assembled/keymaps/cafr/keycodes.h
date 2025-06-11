#pragma once

#include QMK_KEYBOARD_H

#include "quantum/quantum_keycodes.h"

enum layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    _ACCENT,
    LAYER_SYM,
    LAYER_NUM,
};

enum custom_keycodes {
  SYM = QK_USER,
  E_GRV,
  A_GRV,
  U_GRV,
  E_CIRC,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
  C_CEDL,
  E_DIAE,
  I_DIAE,
};

/* Left hand Mod-Tap */
#define LGUI_A     LGUI_T(FR_A)
#define LALT_R     LALT_T(FR_R)
#define LCTL_S     LCTL_T(FR_S)
#define LSFT__T    LSFT_T(FR_T)
/* Right hand Mod-Tap */
#define LSFT_N     LSFT_T(FR_N)
#define LCTL_E     LCTL_T(FR_E)
#define LALT_I     LALT_T(KC_I)
#define LGUI_O     LGUI_T(KC_O)

/* Layer-Tap */
#define NAV_SPC  LT(LAYER_NAV,  KC_SPC)
#define FOO_TAB  LT(LAYER_TODO, KC_TAB)
#define SYM_ENT  LT(LAYER_SYM,  KC_ENT)
#define NUM_E    LT(LAYER_NUM,  KC_E)

/*One Shot Keys*/
#define OSL_BAS  OSL(LAYER_BASE)
#define OSL_SYM  OSL(LAYER_SYM)
#define OSL_NUM  OSL(LAYER_NUM)
#define ACCENT   OSL(_ACCENT)

/* Toggle layer */
#define TO_BASE  TO(LAYER_BASE)
#define TO_SYM   TO(LAYER_SYM)
