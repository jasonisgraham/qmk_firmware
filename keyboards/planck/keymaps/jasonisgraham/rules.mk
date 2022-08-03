SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
SRC += ../../../common/layer_lock.c

KEY_OVERRIDE_ENABLE = yes

AUTO_SHIFT_MODIFIERS = yes
AUTO_SHIFT_ENABLE = yes
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes

LEADER_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
RGB_ANIMATIONS = yes

# SEQUENCER_ENABLE = yes
BACKLIGHT_ENABLE = yes

RGBLIGHT_ENABLE = yes
RGBLIGHT_ANIMATIONS = yes

# ENCODER_MAP_ENABLE = yes

# TERMINAL_ENABLE = yes
# PROGRAMMABLE_BUTTON_ENABLE = yes
# VPATH += keyboards/gboards/			#
