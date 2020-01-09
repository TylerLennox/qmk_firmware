#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _GAMING 1
#define _FUNC 2
#define _NUMPAD 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  FUNC,
  NUMPAD,
  LOWER,
  RAISE,
  ADJUST,
};

enum {
  TD_CAPS = 0,
  TD_BRC = 1,
  TD_MP = 2,
  TD_SLSH = 3,
  TD_ESTD = 4,
  TD_BSDL = 5
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_MP]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_SLSH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [TD_ESTD]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
  [TD_BSDL]  = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     /* QWERTY // Default layer - occasionally 'swaps' with Gaming layer
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | Esc `  | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | - +    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | []     |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | Shift  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ""     |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | Cntrl  | Z      | X      | C      | V      | B      | Mute   |    | Play   | N      | M      | ,      | .      | /      | NUM    |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | Enter  |    | Space  | BacSpc | Func   |
 *                                     '--------------------------'    '--------------------------'
 */

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  TD(TD_ESTD), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  TD(TD_MP),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  TD(TD_BRC),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  TD(TD_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,         KC_MPLY,   KC_N,    KC_M,  KC_COMM, KC_DOT, TD(TD_SLSH), TO(_NUMPAD),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT,  KC_ENT,                    KC_SPC,TD(TD_BSDL), TO(_FUNC)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

       /* Gaming // Default layer - occasionally 'swaps' with Gaming layer
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | Esc    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | Raise  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | Lower  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | Shift  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | Cntrl  | Z      | X      | C      | V      | B      | Mute   |    | Play   | N      | M      | ,      | .      | /      | NUM    |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | Space  | Enter  |    | Alt  | BacSpc | Func   |
 *                                     '--------------------------'    '--------------------------'
 */

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_LSFT,  KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  KC_LCTL,  KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,           KC_MPLY,  KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, TO(_NUMPAD),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_ENT,  KC_SPC,                    KC_RALT, KC_BSPC, TO(_FUNC)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

     /* FUNC // Function layer - functions and arrows
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | Til     | F1     | F2     | F3     | F4     | F5     |                      | F6     | F7     | F8     | F9     | F10    | Adjust  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | F11    | F12    |                      | Y      | U      | I      | O      | P      | Lower  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | Shift  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | Home   |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | Cntrl  | Z      | X      | C      | V      | B      | Mute   |    | Play   | N      | M      | ,      | .      | /      | End    |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | Enter  |    | Space  | BacSpc | Func   |
 *                                     '--------------------------'    '--------------------------'
 */

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,   KC_UP,   KC_F11,  KC_F12,                             KC_PGUP, _______,  KC_UP,  _______, KC_INS,  KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  TD(TD_CAPS), KC_A,   KC_S, KC_DOWN, KC_RIGHT, KC_G,                              KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,         KC_MPLY,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_BSLS,  KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT,  KC_ENT,                    KC_SPC, KC_BSPC, TO(_QWERTY)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

      /* NUMPAD // Number pad layer
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | Til    | F1     | F2     | F3     | F4     | F5     |                      | F6     | F7     | F8     | F9     | F10    | Raise  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | F11    | F12    |                      | Y      | U      | I      | O      | P      | Lower  |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | Shift  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | Home   |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | Cntrl  | Z      | X      | C      | V      | B      | Mute   |    | Play   | N      | M      | ,      | .      | /      | End    |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | Enter  |    | Space  | BacSpc | Func   |
 *                                     '--------------------------'    '--------------------------'
 */

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,  KC_PSLS, KC_PAST, KC_PMNS, TO(_ADJUST),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_UP,    KC_R,    KC_T,                               KC_Y,    KC_7,    KC_8,    KC_9,  KC_PPLS, TO(_GAMING),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  TD(TD_CAPS), KC_A,   KC_LEFT, KC_DOWN, KC_RIGHT,  KC_G,                              KC_RSFT,  KC_4,    KC_5,    KC_6,  KC_EQL,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,         KC_MPLY, KC_PDOT,   KC_1,    KC_2,    KC_3,  KC_PENT,  KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT,  KC_ENT,                    KC_SPC,  KC_0,   TO(_QWERTY)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, _______,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, TO(_QWERTY)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case QWERTY:
         if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
         }

         return false;
         break;
      case GAMING:
         if (record->event.pressed) {
            layer_on(_GAMING);
         } else {
            layer_off(_GAMING);
         }

         return false;
         break;
      case FUNC:
         if (record->event.pressed) {
            layer_on(_FUNC);
         } else {
            layer_off(_FUNC);
         }

         return false;
         break;
      case NUMPAD:
         if (record->event.pressed) {
            layer_on(_NUMPAD);
         } else {
            layer_off(_NUMPAD);
         }

         return false;
         break;
      case ADJUST:
         if (record->event.pressed) {
            layer_on(_ADJUST);
         } else {
            layer_off(_ADJUST);
         }
         return false;
         break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case _QWERTY:
        rgblight_setrgb(0xFF, 0x00, 0x2C);
      //   rgblight_setrgb_master(0xFF, 0x00, 0x2C);
      //   rgblight_setrgb_slave(0xFF, 0x00, 0x2C);
        break;
      case _GAMING:
        rgblight_setrgb(0xFF, 0x00, 0x00);
      //   rgblight_setrgb_master(0xFF, 0x00, 0x2C);
      //   rgblight_setrgb_slave(0xFF, 0x00, 0x2C);
        break;
      case _FUNC:
        rgblight_setrgb(0xFF, 0xFF, 0xFF);
        break;
      case _NUMPAD:
        rgblight_setrgb(0x00, 0x80, 0x80);
        break;
      case _ADJUST:
        rgblight_setrgb(0xFF, 0x00, 0xCC);
        break;
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
}