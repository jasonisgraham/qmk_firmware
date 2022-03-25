SRC += ../../../common/layer_lock.c
SRC += ../../../common/caps_word.c


# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

KEY_OVERRIDE_ENABLE = yes

AUDIO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes
MIDI_ENABLE = yes
NKRO_ENABLE = yes
ORYX_ENABLE = yes
RGB_ANIMATIONS = yes
SRC = matrix.c
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = yes
WEBUSB_ENABLE = yes
# BACKLIGHT_ENABLE = yes

# RGBLIGHT_ENABLE = yes
# RGBLIGHT_ANIMATIONS = yes


CAPS_WORD_ENABLE = yes
SRC = matrix.c
