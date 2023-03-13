// This is a direct copypasta of ../trevorlbrooks/keymap.c
// Previously this was done by adding to `SRC` in the rules.mk, but that
//   no longer seems to be working. The default_glow keymap doesn't work on my
//   machine either. In the future, make changes to the other copy and just copy it back over.

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3 // Gamepad config

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  UC_FLIP,  // (ಠ痊ಠ)┻━┻
  UC_TABL,  // ┬─┬ノ( º _ ºノ)
  UC_SHRG,  // ¯\_(ツ)_/¯
  UC_DISA   // ಠ_ಠ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  F5  |           | F12  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L3  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Grv |  '"  | Alt  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Alt  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_F5,
        KC_DEL,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        KC_GRV,         KC_QUOT,      KC_LALT,  KC_LEFT,KC_RGHT,
                                              KC_LALT,  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_F12,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(GAME),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_TRNS,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |   0  |   0  |   .  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Toggle|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |UC_   |UC_   |------|       |------|UC_   |UC_   |
 *                                 |FLIP  |TABL  |      |       |      |SHRG  |DISA  |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_ESC,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_NO,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               UC_FLIP,UC_TABL,KC_TRNS,
       // right hand
       KC_NO, KC_F6,   KC_F7, KC_F8, KC_F9,  KC_F10,  KC_F11,
       KC_NO, KC_UP,   KC_7,  KC_8,  KC_9,   KC_ASTR, KC_F12,
                KC_DOWN, KC_4,  KC_5,  KC_6,   KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,  KC_2,  KC_3,   KC_BSLS, KC_TRNS,
                         KC_0,  KC_0,  KC_DOT, KC_EQL,  KC_NO,
       RGB_TOG, KC_TRNS,
       KC_TRNS,
       KC_TRNS, UC_SHRG, UC_DISA
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Prev | Play | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Mute | VolDn| VolUp|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_NO, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_NO,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Gamepad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  F5  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |      | Prev | Play | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|      | Mute | VolDn| VolUp|      |  Play  |
 * |--------+------+------+------+------+------| Hyper|           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv   |  '"  |AltShf| Left | Right|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |      |        |      |
 *                                 | Space|Backsp|------|       |------|        |      |
 *                                 |      |ace   | End  |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[GAME] = LAYOUT_ergodox(  // layer 3 : gamepad
        // left hand
        KC_EQL,  KC_1,    KC_2,           KC_3,   KC_4,   KC_5,   KC_F5,
        KC_TAB,  KC_Q,    KC_W,           KC_E,   KC_R,   KC_T,   KC_NO,
        KC_LCTL, KC_A,    KC_S,           KC_D,   KC_F,   KC_G,
        KC_LSFT, KC_Z,    KC_X,           KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        KC_GRV,  KC_QUOT, LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                                    KC_TRNS,  KC_TRNS,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
#ifdef UNICODE_ENABLE
    case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
      if (record->event.pressed) {
        send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
      }
      break;
    case UC_TABL: // ┬─┬ノ( º _ ºノ)
      if (record->event.pressed) {
        send_unicode_string("┬─┬ノ( º _ ºノ)");
      }
      break;
    case UC_SHRG: // ¯\_(ツ)_/¯
      if (record->event.pressed) {
        send_unicode_string("¯\\_(ツ)_/¯");
      }
      break;
    case UC_DISA: // ಠ_ಠ
      if (record->event.pressed) {
        send_unicode_string("ಠ_ಠ");
      }
      break;
#endif
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  set_unicode_input_mode(UNICODE_MODE_WINDOWS);
  rgblight_mode(1);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case BASE:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case SYMB:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case MDIA:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case GAME:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      default:
        break;
    }

  return state;
};

#ifdef RGB_MATRIX_ENABLE

rgb_config_t rgb_matrix_config;

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

bool suspended = false;

void suspend_power_down_user(void)
{
    rgb_matrix_disable_noeeprom();
    suspended = true;
}

void suspend_wakeup_init_user(void)
{
    rgb_matrix_enable_noeeprom();
    suspended = false;
}

bool rgb_matrix_indicators_user(void) {
  if(rgb_matrix_config.enable == 0){
    rgb_matrix_set_color_all(0, 0, 0);
    return false;
  }

  switch (biton32(layer_state)) {
    case BASE:
      rgb_matrix_set_color_all(0xFF, 0x00, 0x00); break;
    case SYMB:
      rgb_matrix_set_color_all(0x00, 0x00, 0xFF); break;
    case MDIA:
      rgb_matrix_set_color_all(0x00, 0xFF, 0xFF); break;
    case GAME:
      rgb_matrix_set_color_all(0x3F, 0x00, 0x00);
      //Movement
      rgb_matrix_set_color(32, 0x7F, 0x7F, 0x7F); // W
      rgb_matrix_set_color(38, 0x7F, 0x7F, 0x7F); // A
      rgb_matrix_set_color(37, 0x7F, 0x7F, 0x7F); // S
      rgb_matrix_set_color(36, 0x7F, 0x7F, 0x7F); // D

      //Common game keys
      rgb_matrix_set_color(33, 0xFF, 0x00, 0x00); // Q
      rgb_matrix_set_color(31, 0xFF, 0x00, 0x00); // E
      rgb_matrix_set_color(30, 0xFF, 0x00, 0x00); // R
      rgb_matrix_set_color(35, 0xFF, 0x00, 0x00); // F
      rgb_matrix_set_color(28, 0x00, 0x00, 0x7F); // 1
      rgb_matrix_set_color(27, 0x00, 0x00, 0x7F); // 2
      rgb_matrix_set_color(26, 0x00, 0x00, 0x7F); // 3
      rgb_matrix_set_color(25, 0x00, 0x00, 0x7F); // 3

      break;
  }
  return false;
}
#endif
