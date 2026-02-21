#pragma once

/* Auto Shift */
#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_NUMERIC
/* Auto Shift for tap-hold keys */
//#define RETRO_SHIFT

/* Try to mitigate the Remote Desktop Protocol issue on Windows */
/* @ is not registered properly. TODO: Does this fix ? */
// #define TAP_CODE_DELAY 30
#define TAPPING_TERM 200

/* Automatic Mouse Layer */
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER LAYER_NAV

/* Cirque Trackpad */
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_HIRES_SCROLL_ENABLE

/* Combos are defined using keys from layer 0 but will work on all layers */
#define COMBO_ONLY_FROM_LAYER 0
