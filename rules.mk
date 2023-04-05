BOOTLOADER             = qmk-dfu
OLED_DRIVER            = SSD1306

RGBLIGHT_ENABLE        = no     # Enable WS2812 RGB underlight.
LTO_ENABLE             = yes
AVR_USE_MINIMAL_PRINTF = yes
VIA_ENABLE             = yes     # Enable VIA
VIAL_ENABLE            = yes     # Enable VIAL
RGB_MATRIX_ENABLE      = yes
EXTRAKEY_ENABLE        = yes
OLED_ENABLE            = yes

MOUSEKEY_ENABLE        = no
WPM_ENABLE             = no
QMK_SETTINGS           = no
COMBO_ENABLE           = no
TAP_DANCE_ENABLE       = no
KEY_OVERRIDE_ENABLE    = no
MUSIC_ENABLE           = no
CONSOLE_ENABLE         = no
COMMAND_ENABLE         = no
GRAVE_ESC_ENABLE       = no
SPACE_CADET_ENABLE     = no
POINTING_DEVICE_ENABLE = no
MIDI_ENABLE            = no

CFLAGS                 += -flto
EXTRAFLAGS             += -flto
