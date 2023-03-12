// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layers_block.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       T_TAB   , ___________________COLEMAK_DH_L1_______________ ,        ___________________COLEMAK_DH_R1_______________ , KC_MINS ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       KC_LCTL , ___________________COLEMAK_DH_L2_______________ ,        ___________________COLEMAK_DH_R2_______________ , CTL_QUOT,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       KC_LSFT , ___________________COLEMAK_DH_L3_______________ ,        ___________________COLEMAK_DH_R3_______________ , ADJ_EQL ,
  // +---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------+
                                     _________MOD_LEFT__________ ,        _________MOD_RIGHT_________
                                 // \----------------------------/      \-----------------------------/
  ),

  [_QWERTY] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       T_TAB   , ___________________QWERTY_L1___________________ ,        ___________________QWERTY_R1___________________ , KC_MINS ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       KC_LCTL , ___________________QWERTY_L2___________________ ,        ___________________QWERTY_R2___________________ , CTL_QUOT,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       KC_LSFT , ___________________QWERTY_L3___________________ ,        ___________________QWERTY_R3___________________ , ADJ_EQL ,
  // +---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------+
                                     _________MOD_LEFT__________ ,        _________MOD_RIGHT_________
                                 // \----------------------------/      \-----------------------------/
  ),

  [_FUNCTION] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       KC_ESC  , ___________________FUNC_LEFT___________________ ,        ___________________FUNC_RIGHT__________________ , KC_F11  ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       K_CSCN  , ____________________MEDIA_1____________________ ,        KC_DEL  , _______________NAV_1_________________ , KC_F12  ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       _______ , ____________________MEDIA_2____________________ ,        KC_INS  , _______________NAV_2_________________ , K_LOCK  ,
  // +---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------+
                                     _______MOD_TRNS_LEFT_______ ,        _______MOD_TRNS_RIGHT______
                                 // \----------------------------/      \-----------------------------/
  ),

  [_CODE] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       T_GRV   , ___________________NUM_LEFT____________________ ,        ___________________NUM_RIGHT___________________ , KC_BSLS ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________SYMBOL_L1________________________ ,        ________________________SYMBOL_R1________________________ ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________SYMBOL_L2________________________ ,        ________________________SYMBOL_R2________________________ ,
  // +---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------+
                                     _______MOD_TRNS_LEFT_______ ,        _______MOD_TRNS_RIGHT______
                                 // \----------------------------/      \-----------------------------/
  ),

  [_ADJUST] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       ________________________ADJUST_L1________________________ ,        ________________________ADJUST_R1________________________ ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________ADJUST_L2________________________ ,        ________________________ADJUST_R2________________________ ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________ADJUST_L3________________________ ,        ________________________ADJUST_R3________________________ ,
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
                                     _______ , _______ , _______ ,        _______ , _______ , _______
                                 // \----------------------------/      \-----------------------------/
  ),

  [_SECRET] = LAYOUT_wrapper(
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
       ________________________SECRET_L1________________________ ,        ________________________SECRET_R1________________________ ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________SECRET_L2________________________ ,        ________________________SECRET_R2________________________ ,
  // |---------+---------+---------+---------+---------+---------|      |---------+---------+---------+---------+---------+---------|
       ________________________SECRET_L3________________________ ,        ________________________SECRET_R3________________________ ,
  // +---------+---------+---------+---------+---------+---------+      +---------+---------+---------+---------+---------+---------+
                                     XXXXXXX , XXXXXXX , XXXXXXX ,        XXXXXXX , XXXXXXX , XXXXXXX
                                 // \----------------------------/      \-----------------------------/
  )
};
// clang-format off

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FUNCTION, _ADJUST, _SECRET);
}
