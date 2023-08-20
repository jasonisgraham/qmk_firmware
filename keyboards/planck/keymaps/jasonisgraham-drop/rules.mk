SRC += muse.c

AUDIO_ENABLE = yes
AUTOCORRECT_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
COMMAND_ENABLE = yes        # Commands for debug and configuration
CONSOLE_ENABLE = yes        # Console for debug
CUSTOM_MATRIX = lite
DIP_SWITCH_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
KEY_OVERRIDE_ENABLE = yes
LAYOUTS_HAS_RGB = no
LEADER_ENABLE = yes
MIDI_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
NKRO_ENABLE = yes           # Enable N-Key Rollover
REPEAT_KEY_ENABLE = yes
RGBLIGHT_ANIMATIONS = yes
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
RGB_ANIMATIONS = yes
UNICODEMAP_ENABLE = yes

RGB_MATRIX_ENABLE = no
SRC += matrix.c
TAP_DANCE_ENABLE = yes
WEBUSB_ENABLE = yes
