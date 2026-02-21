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
#include "sendstring_canadian_french.h"
#include "g/keymap_combo.h"

#define ___X___ XXXXXXX

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          FR_Q,    FR_W,    FR_F,    FR_P,    FR_B,       FR_J,    FR_L,    FR_U,    FR_Y, FR_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          FR_A,    FR_R,    FR_S,    FR_T,    FR_G,       FR_M,    FR_N,    FR_E,    FR_I,    FR_O,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          FR_Z,    FR_X,    FR_C,    FR_D,    FR_V,       FR_K,    FR_H, FR_COMM,  FR_DOT, FR_EACU,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
	                          NAV_SPC, SFT_TAB,    SYM_ENT, MO(LAYER_NUM)
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_BTN1, KC_BTN2,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, CW_TOGG,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO, KC_RALT,   KC_NO,   KC_NO,   KC_NO,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                   KC_ENT, KC_BSPC,      KC_NO,   KC_NO
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       FR_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, FR_RCBR,      KC_NO, FR_LDAQ, FR_LABK, FR_RABK, FR_RDAQ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_COLN,  KC_DLR, KC_PERC, FR_QUES, KC_PLUS,      KC_NO,   KC_NO, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_TILD, KC_EXLM,   FR_AT, FR_HASH, FR_PIPE,      KC_NO,   KC_NO,   KC_NO,  FR_DOT, FR_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  KC_RPRN, KC_UNDS,      KC_NO,   KC_NO
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       FR_LBRC,    KC_7,    KC_8,    KC_9, FR_RBRC,      KC_NO, FR_LDAQ, FR_RDAQ, KC_BSPC,  KC_DEL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,     QK_REP, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       FR_DGRV,    KC_1,    KC_2,    KC_3, FR_BSLS,      KC_NO, FR_LABK, FR_RABK,  FR_DOT, FR_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                     KC_0, KC_MINS,      KC_NO,   KC_NO
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
};

// This is the default callack except what I don't shift '-' to '_'.
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void custom_shift_key(uint8_t mod_state, uint16_t keycode, uint16_t shifted_keycode) {
    if (mod_state & MOD_MASK_SHIFT) {
        tap_code16(shifted_keycode);
    }
    else {
        tap_code16(keycode);
    }
}

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    switch (keycode) {
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
    case U_GRV:
        if (record->event.pressed) {
            tap_code16(FR_DGRV);
            tap_code16(FR_U);
        }
        return false;
    case U_CIRC:
        if (record->event.pressed) {
            tap_code16(FR_DCIR);
            tap_code16(FR_U);
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
    case M_PAREN:
        if (record->event.pressed) {
            SEND_STRING("()" SS_TAP(X_LEFT));
        }
	return false;
    case M_BRC:
        if (record->event.pressed) {
            SEND_STRING("[]" SS_TAP(X_LEFT));
        }
	return false;
    case M_CBR:
        if (record->event.pressed) {
            SEND_STRING("{}" SS_TAP(X_LEFT));
        }
        return false;
    default:
        return true;
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LGUI_A:
    case LALT_R:
    case LCTL_S:
    case LSFT__T:
    case LSFT_N:
    case LCTL_E:
    case LALT_I:
    case LGUI_O:
    case E_GRV:
    case A_GRV:
    case E_CIRC:
    case A_CIRC:
    case I_CIRC:
    case O_CIRC:
    case C_CEDL:
    case FR_QUOT:
    case FR_COMM:
    case FR_DOT:
      return true;
    default:
      return false;
    }
}

// code extended from the example on the QMK docs https://docs.qmk.fm/#/feature_auto_shift?id=custom-shifted-values
// Autoshift combos to get capitalized accented letter.
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
    case FR_QUOT:
        register_code16((!shifted) ? FR_QUOT : FR_DQUO);
        break;
    case FR_COMM:
        register_code16((!shifted) ? FR_COMM : FR_SCLN);
        break;
    case FR_DOT:
        register_code16((!shifted) ? FR_DOT : FR_COLN);
        break;
    case E_GRV:
        if (shifted) {
            tap_code16(FR_DGRV);
            tap_code16(S(FR_E));
        }
        else {
            tap_code16(FR_DGRV);
            tap_code16(FR_E);
        }
        break;
    case A_GRV:
        if (shifted) {
            tap_code16(FR_DGRV);
            tap_code16(S(FR_A));
        }
        else {
            tap_code16(FR_DGRV);
            tap_code16(FR_A);
        }
        break;
    case E_CIRC:
        if (shifted) {
            tap_code16(FR_DCIR);
            tap_code16(S(FR_E));
        }
        else {
            tap_code16(FR_DCIR);
            tap_code16(FR_E);
        }
        break;
    case A_CIRC:
        if (shifted) {
            tap_code16(FR_DCIR);
            tap_code16(S(FR_A));
        }
        else {
            tap_code16(FR_DCIR);
            tap_code16(FR_A);
        }
        break;
    case I_CIRC:
        if (shifted) {
            tap_code16(FR_DCIR);
            tap_code16(S(FR_I));
        }
        else {
            tap_code16(FR_DCIR);
            tap_code16(FR_I);
        }
        break;
    case O_CIRC:
        if (shifted) {
            tap_code16(FR_DCIR);
            tap_code16(S(FR_O));
        }
        else {
            tap_code16(FR_DCIR);
            tap_code16(FR_O);
        }
        break;
    case C_CEDL:
        if (shifted) {
            tap_code16(FR_CEDL);
            tap_code16(S(FR_C));
        }
        else {
            tap_code16(FR_CEDL);
            tap_code16(FR_C);
        }
        break;
    default:
        if (shifted) {
            add_weak_mods(MOD_BIT(KC_LSFT));
        }
        // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
        register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
    case FR_QUOT:
      unregister_code16((!shifted) ? FR_QUOT : FR_DQUO);
      break;
    case FR_COMM:
      unregister_code16((!shifted) ? FR_COMM : FR_SCLN);
      break;
    case FR_DOT:
      unregister_code16((!shifted) ? FR_DOT : FR_COLN);
      break;
    default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
    unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
