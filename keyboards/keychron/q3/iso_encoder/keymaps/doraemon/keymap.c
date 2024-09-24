/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_french.h"

/* #region [LAYERS] */

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,  KC_NO,    KC_NO,    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     FR_RPRN,  FR_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   FR_A,     FR_Z,     FR_E,     FR_R,     FR_T,     FR_Y,     FR_U,     FR_I,     FR_O,     FR_P,     FR_CIRC,  FR_DLR,     KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  FR_Q,     FR_S,     FR_D,     FR_F,     FR_G,     FR_H,     FR_J,     FR_K,     FR_L,     FR_M,     FR_UGRV,  FR_ASTR,    KC_ENT,
        KC_LSFT,  KC_NUBS,  FR_W,     FR_X,     FR_C,     FR_V,     FR_B,     FR_N,     FR_COMM,  FR_SCLN,  FR_COLN,  FR_EXLM,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_iso(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  M_LOREM,  _______,  _______,  _______,    M_PW,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  KC_PSCR,  KC_NO,    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     FR_RPRN,  FR_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   FR_A,     FR_Z,     FR_E,     FR_R,     FR_T,     FR_Y,     FR_U,     FR_I,     FR_O,     FR_P,     FR_CIRC,  FR_DLR,               KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  FR_Q,     FR_S,     FR_D,     FR_F,     FR_G,     FR_H,     FR_J,     FR_K,     FR_L,     FR_M,     FR_UGRV,  FR_ASTR,    KC_ENT,
        KC_LSFT,  KC_NUBS,  FR_W,     FR_X,     FR_C,     FR_V,     FR_B,     FR_N,     FR_COMM,  FR_SCLN,  FR_COLN,  FR_EXLM,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_iso(
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  M_LOREM,  _______,  _______,  _______,    M_PW,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

/* #endregion */

/* #region [CUSTOM KEYCODES] */

enum custom_keycodes {
    M_LOREM = SAFE_RANGE,
    M_PW,
};

/* #endregion */

/* #region [CONSTANTS] */

const char *const PW = "pure0sssn13\n";
const char *const LOREMS[] = {
    "Suspendisse magna ut fermentum tristique nec libero. ",
    "Quisque vel tristique arcu. Suspendisse nec potenti. ",
    "Integer luctus justo ac magna dignissim, id egestas. ",
    "Lorem ipsum dolor sit amet, ligula nec justo tempor. ",
    "Integer luctus justo ac magna dignissim, id egestas. "
};
#define LOREMS_LENGTH (sizeof(LOREMS) / sizeof(LOREMS[0])) // Compute array length

/* #endregion */

/* #region [KEYPRESS] */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_LOREM:
            if (record->event.pressed) {
                int randomIndex = rand() % LOREMS_LENGTH; // Get a random index
                send_string(LOREMS[randomIndex]); // Send the string
            }
            return false;
        case M_PW:
            if (record->event.pressed) {
                send_string(PW);
            }
            return false;
    }

    return true;
}

/* #endregion */
