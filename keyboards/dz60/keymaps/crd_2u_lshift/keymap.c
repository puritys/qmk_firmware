#include QMK_KEYBOARD_H

enum function_id {
    TRICKY_ESC = 0,
    MY_PG_CONTROL,
    MY_CHROME_NEXT,
    MY_CHROME_PREV,
    MY_BACKSPACE, 
    KEYPAD_00,
    MY_PASTE,
    MY_UNIX_INSERT,
    MY_BACKLIGHT_ENABLE,
    MY_TYPE_SINGLE_QUOTE,
    MY_TYPE_DOUBLE_QUOTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl/Esc|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |shift |  U  | End |
   * |-----------------------------------------------------------------------------------------+
   * | FN1  |  Alt  |  Cmd  |              Space                | Cmd  | FN2 |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */
  // layout0 mac
  LAYOUT_directional(
      KC_GESC,        KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,
      KC_TAB,        KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,       KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
      KC_LCTL,         KC_LGUI, KC_LALT, KC_SPC, KC_SPC, F(0), KC_RALT, F(0), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  /* windows Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl/Esc|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |shift |  U  | End |
   * |-----------------------------------------------------------------------------------------+
   * | FN1  |  Alt  |  Cmd  |              Space                | Cmd  | FN2 |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */
  // layout1 windows
  LAYOUT_directional(
      KC_GESC,        KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,
      KC_TAB,        KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,       KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
      KC_LCTL,         KC_LALT, KC_LGUI, KC_SPC, KC_SPC, F(0), KC_RALT, F(0), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  /* FN1 Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     Del   |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     | Home | PgUp |      |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |  L  |  D  |  U  |  R  | End | PgDn|             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |PgUp |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |Home |PgDn | End |
   * `-----------------------------------------------------------------------------------------'
   */

  // layout2 for FN   
  LAYOUT_directional(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,    KC_F12,  _______, KC_DEL,
      _______, _______, _______, KC_ENT, _______, _______, _______, _______, KC_UP, _______,   _______, KC_HOME,   KC_PGUP, _______,
      _______, _______, _______, KC_DEL, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_RIGHT,  _______,  _______, _______,
      _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______,   _______, _______,   KC_PGUP, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_END
      ),

  /* FN2 Layer (Media)
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |Mute | Vol- | Vol+ |      |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |Bri- |Bri+ |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |Pl/Ps|Vol+ |Mute |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |Prev |Vol- |Next |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,  _______, _______, RESET,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_MUTE,       KC_VOLD,  KC_VOLU, _______,
      _______, _______, _______, DEBUG,   _______, _______, _______, _______, _______, _______, KC_SCROLLLOCK, KC_PAUSE, _______, 
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       KC_MPLY,  KC_VOLU, KC_MUTE,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
      ),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(2),
    [1] = ACTION_LAYER_MOMENTARY(3),

    [2] = ACTION_LAYER_SET(0, ON_PRESS), 
    [3] = ACTION_LAYER_SET(1, ON_PRESS),

    [12] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 1),
    [13] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 2),
    [14] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 3),
    [15] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 4),



};


#define MODS_CTRL_MASK   (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{/*{{{*/
    static uint8_t mod = 0;
    static uint8_t key;
    //dprintf("zzz %d\n", record->tap.count);
    switch (id) {
       case MY_PG_CONTROL:
            //dprintf("in MY_PG_CONTROL opt = %d\n", opt);
            mod = get_mods();
            if (record->event.pressed) {
                switch (opt) {
                    case 1:
                        key = (mod & MODS_CTRL_MASK) ? KC_PGUP : KC_UP;
                        break; 
                    case 2:
                        key = (mod & MODS_CTRL_MASK) ? KC_PGDN : KC_DOWN;
                        break; 
                    case 3:
                        key = (mod & MODS_CTRL_MASK) ? KC_HOME : KC_LEFT;
                        break;
                    case 4:
                        key = (mod & MODS_CTRL_MASK) ? KC_END : KC_RIGHT;
                        break; 
                }
                if (mod & MODS_CTRL_MASK)  {
                    del_mods(mod);
                    add_key(key);
                    send_keyboard_report();
                    add_mods(mod);   // return Ctrl but not sent
                }  else {
                    add_key(key);
                    send_keyboard_report();
                }
            } else {
                del_key(key);
                send_keyboard_report();
            }
            break;
    }
}/*}}}*/


