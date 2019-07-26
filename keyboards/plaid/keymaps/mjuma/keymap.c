/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

extern keymap_config_t keymap_config;

enum plaid_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _GAMING,
  _ADJUST,
  _FN,
  _SPACE_FN
};

enum plaid_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  GAMING,
  EXT_PLV,
  LED_1,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_0
};

#define _______ KC_TRNS
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define SPACE_FN LT(_SPACE_FN, KC_SPC)

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
    KC_LCTL,
    KC_RCTL,
    KC_LALT,
    KC_RALT,
    KC_LSFT,
    KC_RSFT,
    KC_LGUI,
    KC_RGUI,
    LOWER,
    RAISE
};

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | FN   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, FN,       KC_LALT, KC_LGUI, LOWER,   SPACE_FN,  SPACE_FN,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_plaid_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   /  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   _  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    _______, _______, _______, KC_SLSH,    KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR, KC_BSLS, KC_MINS, KC_EQL,  KC_PIPE,
    _______, _______, _______, _______,    _______,  _______,  _______,  _______, _______, KC_UNDS, KC_PLUS, KC_ENT,
    _______, _______, _______, _______,    _______,  KC_SPC,   KC_SPC,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |   .  |   =  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC,
    _______, _______, _______, _______, _______, _______, KC_PAST,  KC_4,     KC_5,    KC_6,     KC_PMNS,  KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_PSLS,  KC_1,     KC_2,    KC_3,     KC_PPLS,  KC_ENT,
    _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,   _______,  KC_0,    KC_PDOT,  KC_PEQL,  _______
),

/* fn
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |      |INSERT| Home | PgUp |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | ROLL |SHRUG |      |      |      |DELETE| End  | PgDn |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_plaid_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,   KC_F15,   _______,  KC_INS,  KC_HOME, KC_PGUP, _______, _______,
    _______, _______, _______, _______,   _______,  _______,  _______,  KC_DEL,  KC_END,  KC_PGDN, _______, KC_ENT,
    _______, _______, _______, _______, _______,  KC_SPC,   KC_SPC,   _______, _______, _______, _______, _______
),

/* Space fn
 * ,------------------------------------------------------------------------------------.
 * |PRNT SC|      |  UP  |      |      |      |      |      |      |      |      |      |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |       | LEFT | DOWN | RIGHT|      |      | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * |       |ALT+1 |ALT+2 |ALT+3 |ALT+4 |ALT+5 |ALT+6 |ALT+7 |ALT+8 |ALT+9 |ALT+10|      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |VOLDWN|             |VOL UP| PREV | MUTE |PLY/PS| NEXT |
 * `------------------------------------------------------------------------------------'
 */
[_SPACE_FN] = LAYOUT_plaid_grid(
    KC_PSCR, _______,    KC_UP,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______, KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,
    _______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), _______,
    _______, _______,    _______,    _______,    KC_VOLD,    _______,    _______,    KC_VOLU,    KC_MPRV,    KC_MUTE,    KC_MPLY,    KC_MNXT
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_plaid_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),


/* Gaming Layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | FN   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_plaid_grid(
    KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_GESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, FN,       KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,    RAISE,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    RESET,LED_1, LED_2, LED_3, LED_4, LED_5,LED_6, LED_7, LED_8, LED_9, LED_0,KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

//Setup config struct for LED
typedef union {
  uint32_t raw;
  struct {
    uint8_t  red_mode :8;
    uint8_t  green_mode :8;
  };
} led_config_t;
led_config_t led_config;

//Set leds to saved state during powerup
void keyboard_post_init_user(void) {
  // Call the post init code.
  led_config.raw = eeconfig_read_user();

  if(led_config.red_mode == LEDMODE_ON) {
      writePinHigh(LED_RED);
  }

  if(led_config.green_mode == LEDMODE_ON) {
      writePinHigh(LED_GREEN);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset! 
  led_config.raw = 0;
  led_config.red_mode = LEDMODE_ON;
  led_config.green_mode = LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
  eeconfig_update_user(led_config.raw);
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
    switch (led_mode) {
      case LEDMODE_MODS:
        for (int i=0;i<sizeof(modifiers) / sizeof(modifiers[0]);i++) {
          if(keycode==modifiers[i]) {
            if (record->event.pressed) {
              writePinHigh(led);
            }
            else {
              writePinLow(led);
            }
          }
        }
        break;
      case LEDMODE_BLINKIN:
        if (record->event.pressed) {
          if(rand() % 2 == 1) {
            if(rand() % 2 == 0) {
              writePinLow(led);
            }
            else {
              writePinHigh(led);
            }
          }
        }
        break;
      case LEDMODE_KEY:
        if (record->event.pressed) {
          writePinHigh(led);
          return;
        }
        else {
          writePinLow(led);
          return;
        }
        break;
      case LEDMODE_ENTER:
        if (keycode==KC_ENT) {
          writePinHigh(led);
        }
        else {
          writePinLow(led);
        }
        break;

    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* If the either led mode is keypressed based, call the led updater
     then let it fall through the keypress handlers. Just to keep 
     the logic out of this procedure */
  if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_RED, led_config.red_mode, keycode, record);
  }
  if (led_config.green_mode >= LEDMODE_MODS && led_config.green_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_GREEN, led_config.green_mode, keycode, record);
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
    case LED_1:
      if (record->event.pressed) {
        if (led_config.red_mode==LEDMODE_ON) {
            led_config.red_mode=LEDMODE_OFF;
            writePinLow(LED_RED);
        }
        else {
            led_config.red_mode=LEDMODE_ON;
            writePinHigh(LED_RED);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_2:
      if (record->event.pressed) {
        if (led_config.green_mode==LEDMODE_ON) {
            led_config.green_mode=LEDMODE_OFF;
            writePinLow(LED_GREEN);
        }
        else {
            led_config.green_mode=LEDMODE_ON;
            writePinHigh(LED_GREEN);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_3:
      led_config.red_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_4:
      led_config.green_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_5:
      led_config.red_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_6:
      led_config.green_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_7:
      led_config.red_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_8:
      led_config.green_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_9:
      led_config.red_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_0:
      led_config.green_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
  }
  return true;
}
