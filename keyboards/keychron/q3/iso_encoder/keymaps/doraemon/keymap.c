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
/* TODO
 - macro recorder
 - touches exposé etc sur fn
 - fn + arrows pour la souris
 - fn + ctrl droite pour clic gauche
 - macro mouse jiggling
*/

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"

/* #region [CUSTOM KEYCODES] */

enum custom_keycodes {
    M_LOREM = SAFE_RANGE,
    M_PW,
    M_BOOT,
    M_SYMFO,
};

/* #endregion */

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
        M_BOOT,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  M_SYMFO,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,  M_LOREM,  _______,  _______,  _______,    M_PW,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                AC_TOGG,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  KC_PSCR,  KC_NO,    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     FR_RPRN,  FR_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   FR_A,     FR_Z,     FR_E,     FR_R,     FR_T,     FR_Y,     FR_U,     FR_I,     FR_O,     FR_P,     FR_CIRC,  FR_DLR,               KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  FR_Q,     FR_S,     FR_D,     FR_F,     FR_G,     FR_H,     FR_J,     FR_K,     FR_L,     FR_M,     FR_UGRV,  FR_ASTR,    KC_ENT,
        KC_LSFT,  KC_NUBS,  FR_W,     FR_X,     FR_C,     FR_V,     FR_B,     FR_N,     FR_COMM,  FR_SCLN,  FR_COLN,  FR_EXLM,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_iso(
        M_BOOT,   KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  M_SYMFO,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,  M_LOREM,  _______,  _______,  _______,    M_PW,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                AC_TOGG,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
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

/* #region [CONSTANTS] */

const char *const PW = "pure0sssn13\n";
const char *const LOREMS[] = {
    "Lorem ipsum dolor sit amet, ligula nec justo tempor. ",
    "Suspendisse magna ut fermentum tristique nec libero. ",
    "Quisque vel tristique arcu. Suspendisse nec potenti. ",
    "Integer luctus justo ac magna dignissim, id egestas. "
};
#define LOREMS_LENGTH (sizeof(LOREMS) / sizeof(LOREMS[0])) // Compute array length
#define TAP_DELAY 100

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
        case M_BOOT:
            if (record->event.pressed) {
                reset_keyboard();  // Enter bootloader mode
            }
            return false;
        case M_SYMFO:
            if (record->event.pressed) {
                tap_code16_delay(LALT(KC_UP), TAP_DELAY); // ATL+UP (move one function up)
                tap_code16_delay(LALT(KC_UP), TAP_DELAY); // ATL+UP (move one function up)
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select getter name
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select getter name fully
                tap_code16_delay(LCTL(FR_C), TAP_DELAY); // Copy getter name
                tap_code_delay(KC_HOME, TAP_DELAY); // Move to line start
                tap_code_delay(KC_DOWN, TAP_DELAY); // Move one line down
                tap_code_delay(KC_DOWN, TAP_DELAY); // Move one line down
                tap_code16_delay(LCTL(KC_RIGHT), TAP_DELAY); // Move one word right
                tap_code16_delay(LCTL(KC_RIGHT), TAP_DELAY); // Move one word right
                tap_code16_delay(LCTL(KC_RIGHT), TAP_DELAY); // Move one word right
                send_string("translate()->");
                tap_code16_delay(LCTL(FR_W), TAP_DELAY * 3); // Select property
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select property fully
                tap_code16_delay(LCTL(FR_V), TAP_DELAY); // Paste getter name
                tap_code_delay(FR_LPRN, TAP_DELAY);  // (
                tap_code_delay(FR_RPRN, TAP_DELAY);  // )
                tap_code16_delay(LALT(KC_DOWN), TAP_DELAY); // ATL+DOWN (move one function down)
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select setter name
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select setter name fully
                tap_code16_delay(LCTL(FR_C), TAP_DELAY); // Copy setter name
                tap_code_delay(KC_HOME, TAP_DELAY); // Move to line start
                tap_code_delay(KC_DOWN, TAP_DELAY); // Move one line down
                tap_code_delay(KC_DOWN, TAP_DELAY); // Move one line down
                tap_code16_delay(LCTL(KC_RIGHT), TAP_DELAY); // Move one word right
                tap_code16_delay(LCTL(KC_RIGHT), TAP_DELAY); // Move one word right
                send_string("translate()->");
                tap_code16_delay(LCTL(FR_W), TAP_DELAY * 3); // Select property fully
                tap_code16_delay(LCTL(FR_W), TAP_DELAY); // Select property fully
                tap_code16_delay(LCTL(FR_V), TAP_DELAY);
                tap_code_delay(FR_LPRN, TAP_DELAY); // (
                tap_code_delay(KC_DEL, TAP_DELAY); // Delete
                tap_code_delay(KC_DEL, TAP_DELAY); // Delete
                tap_code_delay(KC_DEL, TAP_DELAY); // Delete
                tap_code_delay(KC_DEL, TAP_DELAY); // Delete
                tap_code16_delay(KC_END, TAP_DELAY); // Move at the end of the line
                tap_code16_delay(KC_LEFT, TAP_DELAY); // Move one char back
                tap_code_delay(FR_RPRN, TAP_DELAY); // )
                tap_code_delay(KC_DOWN, TAP_DELAY); // Get back in position
                tap_code_delay(KC_DOWN, TAP_DELAY);
            }
            return false;
    }

    return true;
}

/* #endregion */
