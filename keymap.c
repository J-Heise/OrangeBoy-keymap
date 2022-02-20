/* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

// Written for Orange Boy Ergo

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
};

// Defines custom keycodes for using macros
enum custom_keycodes {
    DIA_A = SAFE_RANGE,
    DIA_U,
    DIA_O,
    DOUBLE_S,
    EURO_KC,
};

//Defines macros:
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    //Macro for diacritics ä and Ä.
    case DIA_A:
        if(record->event.pressed)
            {
                register_code(KC_RALT);
                register_code(KC_Q);
            }
        else
            {
                unregister_code(KC_RALT);
                unregister_code(KC_Q);
            }
    return false;

    //Macro for diacritics ü and Ü.
    case DIA_U:
        if(record->event.pressed)
            {
                register_code(KC_RALT);
                register_code(KC_Y);
            }
        else
            {
                unregister_code(KC_RALT);
                unregister_code(KC_Y);
            }
    return false;

    //Macro for ö and Ö.
    case DIA_O:
        if(record->event.pressed)
            {
                register_code(KC_RALT);
                register_code(KC_P);
            }
        else
            {
                unregister_code(KC_RALT);
                unregister_code(KC_P);
            }
    return false;

    //Macro for ß.
    case DOUBLE_S:
        if(record->event.pressed)
            {
                register_code(KC_RALT);
                register_code(KC_S);
            }
        else
            {
                unregister_code(KC_RALT);
                unregister_code(KC_S);
            }
    return false;

    //Macro for €.
    case EURO_KC:
        if(record->event.pressed)
            {
                register_code(KC_RALT);
                register_code(KC_5);
            }
        else
            {
                unregister_code(KC_RALT);
                unregister_code(KC_5);
            }
    return false;

    default:
    return true;
  }
};

//Defines different keyboard layers:
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//Base Layer:
[_BASE] = LAYOUT(
KC_MUTE, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_TRNS, KC_BSPC,
KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
KC_PGDN, MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
         KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,  MO(1),            KC_SPC,           KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT),

//Second Layer (Accessed through pressing MO(1)):
[_FN1] = LAYOUT(
KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EURO_KC, KC_TRNS, KC_TRNS, KC_TRNS, DIA_U,   KC_TRNS, DIA_O,   KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_CAPS, DIA_A,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT),
};
