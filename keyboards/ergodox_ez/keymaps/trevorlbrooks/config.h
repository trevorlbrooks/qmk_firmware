#pragma once

#ifndef KEYMAP_CONFIG_H
#define KEYMAP_CONFIG_H

#ifdef LED_BRIGHTNESS_DEFAULT
    #undef LED_BRIGHTNESS_DEFAULT
#endif

#define LED_BRIGHTNESS_DEFAULT  (LED_BRIGHTNESS_HI * .85)

#ifdef RGBLIGHT_ENABLE
#ifndef RGB_MATRIX_ENABLE
#define RGBLIGHT_COLOR_LAYER_0 0x7F, 0x7F, 0x7F
#define RGBLIGHT_COLOR_LAYER_1 0xFF, 0x00, 0x00
#define RGBLIGHT_COLOR_LAYER_2 0x00, 0xFF, 0xFF
#define RGBLIGHT_COLOR_LAYER_3 0x7F, 0x00, 0x00
#endif
#endif

#ifdef DEBOUNCE
    #undef DEBOUNCE
#endif

#define DEBOUNCE 15
#define UNICODE_SELECTED_MODES UC_OSX, UC_WIN
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#endif

// Disable some features
#ifndef NO_DEBUG
    #define NO_DEBUG
#endif
#ifndef NO_PRINT
    #define NO_PRINT
#endif
#ifndef NO_ACTION_MACRO
    #define NO_ACTION_MACRO
#endif
#ifndef NO_ACTION_FUNCTION
    #define NO_ACTION_FUNCTION
#endif
