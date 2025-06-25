#include QMK_KEYBOARD_H

enum custom_keycodes {
  C_QUOT = SAFE_RANGE,
  C_SLSH,
  C_GRV,
  C_CIRC
};

enum combo_events {
  E_ACUTE,
  E_GRAVE,
  A_GRAVE,
  U_GRAVE,
  E_CIRC,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
  C_CEDIL,
  E_TREMA,
  I_TREMA,
  ESCAPE,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM e_acute_combo[] = {LSFT_T(KC_N), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM e_grave_combo[] = {LALT_T(KC_R), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM a_grave_combo[] = {LALT_T(KC_R), LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM u_grave_combo[] = {LALT_T(KC_R), KC_U,         COMBO_END};
const uint16_t PROGMEM e_circ_combo[] =  {ALGR_T(KC_X), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM a_circ_combo[] =  {ALGR_T(KC_X), LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM i_circ_combo[] =  {ALGR_T(KC_X), LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM o_circ_combo[] =  {ALGR_T(KC_X), LGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM u_circ_combo[] =  {ALGR_T(KC_X), KC_U,         COMBO_END};
const uint16_t PROGMEM c_cedil_combo[] = {KC_C,         KC_D,         COMBO_END};
const uint16_t PROGMEM e_trema_combo[] = {KC_D,         LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM i_trema_combo[] = {KC_D,         LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM escape_combo[] =  {LCTL_T(KC_E), LALT_T(KC_I), COMBO_END};

combo_t key_combos[] = {
  [E_ACUTE] = COMBO_ACTION(e_acute_combo),
  [E_GRAVE] = COMBO_ACTION(e_grave_combo),
  [A_GRAVE] = COMBO_ACTION(a_grave_combo),
  [U_GRAVE] = COMBO_ACTION(u_grave_combo),
  [E_CIRC] = COMBO_ACTION(e_circ_combo),
  [A_CIRC] = COMBO_ACTION(a_circ_combo),
  [I_CIRC] = COMBO_ACTION(i_circ_combo),
  [O_CIRC] = COMBO_ACTION(o_circ_combo),
  [U_CIRC] = COMBO_ACTION(u_circ_combo),
  [C_CEDIL] = COMBO_ACTION(c_cedil_combo),
  [E_TREMA] = COMBO_ACTION(e_trema_combo),
  [I_TREMA] = COMBO_ACTION(i_trema_combo),
  [ESCAPE] = COMBO_ACTION(escape_combo)
};

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
    case C_QUOT:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  tap_code16(LSFT(KC_2));
	else
	  tap_code16(LSFT(KC_COMM));
      }
      return false;
    case C_SLSH:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  tap_code16(LSFT(KC_6));
	else
	  tap_code16(LSFT(KC_3));
      }
      return false;
    case C_GRV:
      if (record->event.pressed) {
	tap_code16(KC_QUOT);
	tap_code16(KC_SPC);
      }
      return false;
    case C_CIRC:
      if (record->event.pressed) {
	tap_code16(KC_LCBR);
	tap_code16(KC_SPC);
      }
      return false;
    case KC_DOT:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  tap_code16(LSFT(KC_BSLS));
	else
	  tap_code16(KC_DOT);
      }
      return false;
    case KC_COMM:
      if (record->event.pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	  del_mods(MOD_MASK_SHIFT);
	  tap_code16(KC_BSLS);
	  set_mods(mod_state);
	  }
	else
	  tap_code16(KC_COMM);
      }
      return false;
  default:
    return true;
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  mod_state = get_mods();
  switch(combo_index) {
    case E_ACUTE:
      if (pressed) {
	tap_code16(KC_SLSH);
      }
      break;
      case E_GRAVE:
	if (pressed) {
	  if (mod_state & MOD_MASK_SHIFT)
	    {
	      del_mods(MOD_MASK_SHIFT);
	      tap_code16(KC_QUOT);
	      set_mods(mod_state);
	      tap_code16(KC_E);
	    }
	  else
	    {
	      tap_code16(KC_QUOT);
	      tap_code16(KC_E);
	    }
	}
	break;
      case A_GRAVE:
	if (pressed) {
	  if (mod_state & MOD_MASK_SHIFT)
	    {
	      del_mods(MOD_MASK_SHIFT);
	      tap_code16(KC_QUOT);
	      set_mods(mod_state);
	      tap_code16(KC_A);
	    }
	  else
	    {
	      tap_code16(KC_QUOT);
	      tap_code16(KC_A);
	    }
	}
	break;
      case U_GRAVE:
	if (pressed) {
	  if (mod_state & MOD_MASK_SHIFT)
	    {
	      del_mods(MOD_MASK_SHIFT);
	      tap_code16(KC_QUOT);
	      set_mods(mod_state);
	      tap_code16(KC_U);
	    }
	  else
	    {
	      tap_code16(KC_QUOT);
	      tap_code16(KC_U);
	    }
	}
      break;
    case E_CIRC:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_LCBR);
	    set_mods(mod_state);
	    tap_code16(KC_E);
	  }
	else
	  {
	    tap_code16(KC_LCBR);
	    tap_code16(KC_E);
	  }
      }
      break;
    case A_CIRC:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_LCBR);
	    set_mods(mod_state);
	    tap_code16(KC_A);
	  }
	else
	  {
	    tap_code16(KC_LCBR);
	    tap_code16(KC_A);
	  }
      }
      break;
    case I_CIRC:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_LCBR);
	    set_mods(mod_state);
	    tap_code16(KC_I);
	  }
	else
	  {
	    tap_code16(KC_LCBR);
	    tap_code16(KC_I);
	  }
      }
      break;
    case O_CIRC:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_LCBR);
	    set_mods(mod_state);
	    tap_code16(KC_O);
	  }
	else
	  {
	    tap_code16(KC_LCBR);
	    tap_code16(KC_O);
	  }
      }
      break;
    case U_CIRC:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_LCBR);
	    set_mods(mod_state);
	    tap_code16(KC_U);
	  }
	else
	  {
	    tap_code16(KC_LCBR);
	    tap_code16(KC_U);
	  }
      }
      break;
    case C_CEDIL:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_RBRC);
	    set_mods(mod_state);
	    tap_code16(KC_C);
	  }
	else
	  {
	    tap_code16(KC_RBRC);
	    tap_code16(KC_C);
	  }
      }
      break;
    case E_TREMA:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    tap_code16(KC_RCBR);
	    tap_code16(KC_E);
	  }
	else
	  {
	    add_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_RCBR);
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_E);
	  }
      }
      break;
    case I_TREMA:
      if (pressed) {
	if (mod_state & MOD_MASK_SHIFT)
	  {
	    tap_code16(KC_RCBR);
	    tap_code16(KC_I);
	  }
	else
	  {
	    add_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_RCBR);
	    del_mods(MOD_MASK_SHIFT);
	    tap_code16(KC_I);
	  }
      }
      break;
  case ESCAPE:
    tap_code16(KC_ESC);
    break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
KC_Q,         KC_W,         KC_F,         KC_P,         KC_B, KC_J, KC_L,         KC_U,         KC_Y,         C_QUOT,\
LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),\
KC_Z,         ALGR_T(KC_X), KC_C,         KC_D,         KC_V, KC_K, KC_H,         KC_COMM,      KC_DOT,       C_SLSH,\
LT(2,KC_SPC), LT(1,KC_TAB), LT(3,KC_ENT), LT(4,KC_BSPC)),
	
	[1] = LAYOUT_split_3x5_2(
QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,\
KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,\
KC_NO, KC_NO, KC_BTN2, KC_BTN1),
	
	[2] = LAYOUT_split_3x5_2(
QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE,\
KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG,\
KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,\
KC_NO, KC_NO, KC_ENT, KC_BSPC),
	
	[3] = LAYOUT_split_3x5_2(
RALT(KC_QUOT), KC_AMPR, KC_ASTR, KC_LPRN, RALT(KC_BSLS), KC_NO, KC_NO, KC_NO, KC_NO, \
QK_BOOT, KC_COLN, KC_DLR, KC_PERC, C_CIRC, KC_PLUS, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
RALT(KC_SCLN), KC_EXLM, RALT(KC_2), KC_GRV, LSFT(KC_GRV), KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, \
KC_RPRN, KC_UNDS, KC_NO, KC_NO),
	
	[4] = LAYOUT_split_3x5_2(
RALT(KC_LBRC), KC_7, KC_8, KC_9, RALT(KC_RBRC), KC_NO, KC_NO, KC_NO, KC_NO, \
QK_BOOT, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
C_GRV, KC_1, KC_2, KC_3, RALT(KC_GRV), KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, \
KC_0, KC_MINS, KC_NO, KC_NO)
};
