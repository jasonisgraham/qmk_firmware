SRC += muse.c

SRC += ../../../common/layer_lock.c
SRC += ../../../common/caps_word.c

AUTO_SHIFT_MODIFIERS = yes

UNICODE_ENABLE = yes
# UCIS_ENABLE = yes
# UNICODEMAP_ENABLE = yes

AUDIO_ENABLE = yes
CAPS_WORD_ENABLE = NO

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
# ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
# BACKLIGHT_ENABLE = yes
# RGBLIGHT_ENABLE = yes
MIDI_ENABLE = yes


NKRO_ENABLE = yes

EXTRAKEY_ENABLE = yes

# ENCODER_ENABLE = yes

ENCODER_MAP_ENABLE = yes



RGB_ANIMATIONS = yes

# BACKLIGHT_ENABLE = yes

RGBLIGHT_ENABLE = yes
RGBLIGHT_ANIMATIONS = yes
