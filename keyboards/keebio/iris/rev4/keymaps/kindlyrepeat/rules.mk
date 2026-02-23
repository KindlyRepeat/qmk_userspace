LTO_ENABLE = yes

AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE  = yes
COMBO_ENABLE      = yes
REPEAT_KEY_ENABLE = yes

# Disabling those 4 features save about 600 bytes.
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no

# Disabling those 3 features save an additionnal 850 bytes.
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# Enable macros for creation of combos. See https://docs.qmk.fm/features/combo#dictionary-management
VPATH += keyboards/gboards
