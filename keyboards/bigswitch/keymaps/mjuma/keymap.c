/*
Copyright 2018 QMK Contributors

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum TAP_DANCES {
    TAP = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(TD(TAP)),
};

void toggle_key(qk_tap_dance_state_t *state, uint16_t tap_code, uint16_t hold_code, bool unregister) {
    if (state->interrupted || !state->pressed) {
        register_code(tap_code);
        if (unregister) {
            unregister_code(tap_code);
        }
        return;
    } else {
        register_code(hold_code);
        if (unregister) {
            unregister_code(hold_code);
        }
        return;
    }
}

void tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            toggle_key(state, KC_Q, KC_W, true);
            return;
        case 2:
            toggle_key(state, KC_E, KC_R, true);
            return;
        case 3:
            toggle_key(state, KC_MPLY, KC_MUTE, false);
            return;
        case 4:
            toggle_key(state, KC_MNXT, KC_MPRV, false);
            return;
        default:
            return;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP] = ACTION_TAP_DANCE_FN(tap_dance)
};
