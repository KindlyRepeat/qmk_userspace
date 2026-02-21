#pragma once

#include QMK_KEYBOARD_H

#include "quantum/quantum_keycodes.h"

enum layers {
    LAYER_BASE = 0,
    LAYER_NAV,
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
  M_PAREN,
  M_BRC,
  M_CBR,
  COMBO_TEST
};

#define C_W     C(FR_W)
#define C_S_TAB C(S(KC_TAB))
#define C_TAB   C(KC_TAB)

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

/* Thumb Mod-Tap */
#define SFT_TAB MT(MOD_LSFT, KC_TAB)

/* Layer-Tap */
#define NAV_SPC  LT(LAYER_NAV,  KC_SPC)
#define FOO_TAB  LT(LAYER_TODO, KC_TAB)
#define SYM_ENT  LT(LAYER_SYM,  KC_ENT)
#define NUM_E    LT(LAYER_NUM,  KC_E)
#define NUM_BSP  LT(LAYER_NUM,   KC_BSPC)

/* One Shot Keys */
#define OS_BAS  OSL(LAYER_BASE)
#define OS_SYM  OSL(LAYER_SYM)
#define OS_NUM  OSL(LAYER_NUM)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

/* Toggle layer */
#define TO_BASE  TO(LAYER_BASE)
#define TO_SYM   TO(LAYER_SYM)

/* Test */
#define FRC_U_GRAVE SEND_STRING("`u")

/* Macros */
// #define M_PAREN SEND_STRING("()" SS_TAP(X_LEFT))
