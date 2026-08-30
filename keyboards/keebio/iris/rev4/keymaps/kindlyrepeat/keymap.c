/*
 * The `LAYOUT_iris_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "sendstring_canadian_french.h" // TODO: Remove me probably. WOuld be included in users/kindlyrepeat.c
#include "g/keymap_combo.h"

#include "kindlyrepeat.h"

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_iris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                   K31, K32, K33, K34                 \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______, \
    KC_TAB,   K01,    K02,     K03,      K04,     K05,                          K06,     K07,     K08,     K09,     K0A,   _______, \
   KC_CAPS,   K11,    K12,     K13,      K14,     K15,                          K16,     K17,     K18,     K19,     K1A,   _______, \
   KC_LSFT,   K21,    K22,     K23,      K24,     K25,   UG_TOGG,   UG_NEXT,    K26,     K27,     K28,     K29,     K2A,   _______, \
                                          K31,   K32,  _______,      _______, K33,  K34                                             \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_iris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_base_wrapper(
	______________COLEMAK_MOD_DH_L1____________,         ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________,         ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________,         ______________COLEMAK_MOD_DH_R3____________,
	                         NAV_SPC, SFT_TAB,             SYM_ENT, LAY_NUM
    ),

    [LAYER_NAV] = LAYOUT_base_wrapper(
       __________________NAV_L1___________________,          __________________NAV_R1___________________,
       __________________NAV_L2___________________,          __________________NAV_R2___________________,
       __________________NAV_L3___________________,          __________________NAV_R3___________________,
       	                         KC_ENT, KC_BSPC,              _______, _______
    ),

    [LAYER_SYM] = LAYOUT_base_wrapper(
       __________________SYM_L1___________________,          __________________SYM_R1___________________,
       __________________SYM_L2___________________,          __________________SYM_R2___________________,
       __________________SYM_L3___________________,          __________________SYM_R3___________________,
              	                KC_RPRN, KC_UNDS,              _______, _______
    ),

    [LAYER_NUM] = LAYOUT_base_wrapper(
       __________________NUM_L1___________________,          __________________NUM_R1___________________,
       __________________NUM_L2___________________,          __________________NUM_R2___________________,
       __________________NUM_L3___________________,          __________________NUM_R3___________________,
              	                 KC_0,  KC_MINS,               _______, _______
    ),
};
