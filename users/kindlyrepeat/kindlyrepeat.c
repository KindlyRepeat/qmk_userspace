#include "kindlyrepeat.h"

void custom_shift_key(uint8_t mod_state, uint16_t keycode, uint16_t shifted_keycode) {
    if (mod_state & MOD_MASK_SHIFT) {
        tap_code16(shifted_keycode);
    }
    else {
        tap_code16(keycode);
    }
}

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
