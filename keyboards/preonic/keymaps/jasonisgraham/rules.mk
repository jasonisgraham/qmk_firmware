SRC += muse.c

AUDIO_ENABLE = yes
CAPS_WORD_ENABLE = yes

SRC += ../../../common/autocorrection.c

UNICODE_ENABLE = yes

LTO_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes


LEADER_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

AUTO_SHIFT_ENABLE = yes
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
# BACKLIGHT_ENABLE = yes
# RGBLIGHT_ENABLE = yes
MIDI_ENABLE = yes


NKRO_ENABLE = yes

RGB_ANIMATIONS = yes

# SRC += encoder_update_user.c

EXTRAKEY_ENABLE = yes

# ENCODER_ENABLE = yes

ENCODER_MAP_ENABLE = yes

# SEQUENCER_ENABLE = yes
# BACKLIGHT_ENABLE = yes

RGBLIGHT_ENABLE = yes
RGBLIGHT_ANIMATIONS = yes
