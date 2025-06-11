/**
 * Copyright 2025 Nicolas Odermatt-Lemay <nodermattlemay@gmail.com
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

#include "keycodes.h"
#include "keymap_canadian_french.h"
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          FR_Q,    FR_W,    FR_F,    FR_P,    FR_B,       FR_J,    FR_L,    FR_U,    FR_Y, FR_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        LGUI_A,  LALT_R,  LCTL_S, LSFT__T,    FR_G,       FR_M,  LSFT_N,  LCTL_E,  LALT_I,  LGUI_O,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          FR_Z,    FR_X,    FR_C,    FR_D,    FR_V,       FR_K,    FR_H, FR_COMM,  FR_DOT, FR_EACU,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  NAV_SPC,  ACCENT,    OSL_SYM, KC_BSPC
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_UNDO,  KC_CUT, KC_COPY, XXXXXXX, KC_PSTE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  KC_BTN1, KC_BTN2,    XXXXXXX, KC_BSPC
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [_ACCENT] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  U_GRV,  U_CIRC, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         A_GRV,  A_CIRC, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, E_CIRC,  I_CIRC,  O_CIRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,  C_CEDL, FR_DIAE, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  XXXXXXX, _______,    XXXXXXX, E_GRV
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       FR_LCBR, FR_AMPR, FR_ASTR, FR_LPRN, FR_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_COLN,  FR_DLR, FR_PERC, FR_DCIR, FR_PLUS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_TILD, FR_EXLM,   FR_AT, FR_HASH, FR_PIPE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  FR_RPRN, FR_UNDS,    TO_BASE, XXXXXXX
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       FR_LBRC,    KC_7,    KC_8,    KC_9, FR_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_SCLN,    KC_4,    KC_5,    KC_6,  FR_EQL,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_DGRV,    KC_1,    KC_2,    KC_3, FR_BSLS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                     KC_0, FR_MINS,    XXXXXXX, _______
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  switch (keycode) {
    /* Same as US layout: outputs ''' and '"' when shifted */
    case FR_QUOT:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT) {
	  del_mods(MOD_MASK_SHIFT);
	  tap_code16(FR_DQUO);
	  set_mods(mod_state);
	}
	else
	  tap_code16(FR_QUOT);
      }
      return false;
    /* Same as US layout: outputs ',' and ';' when shifted */
    case FR_COMM:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT) {
	  del_mods(MOD_MASK_SHIFT);
	  tap_code16(FR_SCLN);
	  set_mods(mod_state);
	}
	else
	  tap_code16(FR_COMM);
      }
      return false;
    /* Same as US layout: outputs '.' and ':' when shifted */
    case FR_DOT:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT) {
	  del_mods(MOD_MASK_SHIFT);
	  tap_code16(FR_COLN);
	  set_mods(mod_state);
	}
	else
	  tap_code16(FR_DOT);
      }
      return false;
    /* Same as US layout: outputs '/' and '?' when shifted */
    case FR_SLSH:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT) {
	  del_mods(MOD_MASK_SHIFT);
	  tap_code16(FR_QUES);
	  set_mods(mod_state);
	}
	else
	  tap_code16(FR_SLSH);
      }
      return false;
    case E_GRV:
      if (record->event.pressed) {
	tap_code16(FR_DGRV);
	tap_code16(FR_E);
      }
      return false;
    case A_GRV:
      if (record->event.pressed) {
	tap_code16(FR_DGRV);
	tap_code16(FR_A);
      }
      return false;
    case U_GRV:
      if (record->event.pressed) {
	tap_code16(FR_DGRV);
	tap_code16(FR_U);
      }
      return false;
    case E_CIRC:
      if (record->event.pressed) {
	tap_code16(FR_DCIR);
	tap_code16(FR_E);
      }
      return false;
    case A_CIRC:
      if (record->event.pressed) {
	tap_code16(FR_DCIR);
	tap_code16(FR_A);
      }
      return false;
    case I_CIRC:
      if (record->event.pressed) {
	tap_code16(FR_DCIR);
	tap_code16(FR_I);
      }
      return false;
    case O_CIRC:
      if (record->event.pressed) {
	tap_code16(FR_DCIR);
	tap_code16(FR_O);
      }
      return false;
    case U_CIRC:
      if (record->event.pressed) {
	tap_code16(FR_DCIR);
	tap_code16(FR_U);
      }
      return false;
    case C_CEDL:
      if (record->event.pressed) {
	tap_code16(FR_CEDL);
	tap_code16(FR_C);
      }
      return false;
    case E_DIAE:
      if (record->event.pressed) {
	tap_code16(FR_DIAE);
	tap_code16(FR_E);
      }
      return false;
    case I_DIAE:
      if (record->event.pressed) {
	tap_code16(FR_DIAE);
	tap_code16(FR_I);
      }
      return false;
    default:
      return true;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
}
