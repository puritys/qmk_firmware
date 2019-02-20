#include QMK_KEYBOARD_H

void handleChromeKey(keyrecord_t *record, uint8_t id, uint8_t opt);

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
    // layout 0 for MAC
	LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, F(0), KC_RALT, MO(2), KC_NO, MO(1), KC_RCTL),

    // layout 1 for win
	LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, F(0), KC_RALT, MO(2), KC_NO, MO(1), KC_RCTL),

    // layout 3 for FN0
	LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, F(12), KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, F(14), F(13), F(15) , KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // layout 4 for pcb light and layout
	LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(6),
    [1] = ACTION_BACKLIGHT_DECREASE(),
    [2] = ACTION_BACKLIGHT_TOGGLE(),
    [3] = ACTION_BACKLIGHT_INCREASE(),
    [4] = ACTION_LAYER_MODS(7, MOD_LALT),
    //[5] = ACTION_LAYER_MOMENTARY(4),
    [6] = ACTION_FUNCTION_OPT(MY_CHROME_PREV, 1),
    [7] = ACTION_FUNCTION_OPT(MY_CHROME_NEXT, 1),
    [8] = ACTION_FUNCTION(TRICKY_ESC),
    [9] = ACTION_FUNCTION(MY_BACKSPACE),
    [10] = ACTION_LAYER_MODS(5, MOD_LGUI),
    [11] = ACTION_FUNCTION(MY_UNIX_INSERT),
    [12] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 1),
    [13] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 2),
    [14] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 3),
    [15] = ACTION_FUNCTION_OPT(MY_PG_CONTROL, 4),

    [16] = ACTION_LAYER_SET(0, ON_PRESS), 
    [17] = ACTION_LAYER_SET(1, ON_PRESS),
    [18] = ACTION_LAYER_SET(2, ON_PRESS),
    [24] = ACTION_LAYER_MOMENTARY(3),

    [19] = ACTION_FUNCTION_OPT(MY_CHROME_PREV, 2),//MAC
    [20] = ACTION_FUNCTION_OPT(MY_CHROME_NEXT, 2), //MAC

};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}
uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif 

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{/*{{{*/
    switch (id) {
        case MY_PASTE:
            return (record->event.pressed ?
                MACRO(T(PSTE), END ) :
                MACRO_NONE);
        case MY_TYPE_SINGLE_QUOTE:
            return (record->event.pressed ?
                MACRO( T(QUOT), T(QUOT), T(LEFT), END ) :
                MACRO_NONE);
        case MY_TYPE_DOUBLE_QUOTE:
            return (record->event.pressed ?
                MACRO(D(LSFT), T(QUOT), T(QUOT), U(LSFT), T(LEFT), END ) :
                MACRO_NONE);

        case KEYPAD_00:
            return (record->event.pressed ?
                    MACRO( T(P0), T(P0), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}/*}}}*/


#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK   (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{/*{{{*/
    static uint8_t tricky_esc_registered;
    static uint8_t mod = 0;
    static uint8_t key;
    //dprintf("zzz %d\n", record->tap.count);
    switch (id) {
        case TRICKY_ESC:
            if (record->event.pressed) {
                if (get_mods() & MODS_SHIFT_MASK) {
                    tricky_esc_registered = KC_GRV;
                }
                else {
                    tricky_esc_registered = KC_ESC;
                }
                register_code(tricky_esc_registered);
                send_keyboard_report();
            }
            else {
                unregister_code(tricky_esc_registered);
                send_keyboard_report();
            }
            break;
        case MY_BACKSPACE:
            mod = get_mods();
            if (record->event.pressed) {
                if (mod & MODS_CTRL_MASK) {
                    key = KC_DELETE;
                }
                else {
                    key = KC_BSPC;
                }
                del_mods(mod);
                add_key(key);
                send_keyboard_report();
                add_mods(mod);   // return Ctrl but not sent
            } else {
                del_key(key);
                send_keyboard_report();
            }
            break;
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
        case MY_UNIX_INSERT:
            mod = get_mods();
            if (record->event.pressed) {
                del_mods(mod);
                add_mods(MOD_BIT(KC_LSHIFT));
                add_key(KC_INS);
                send_keyboard_report();
                add_mods(mod);   // return mods but don't send
            } else {
                del_mods(MOD_BIT(KC_LSHIFT));
                del_key(KC_INS);
                send_keyboard_report();
            }
            break;
        case MY_CHROME_PREV:
        case MY_CHROME_NEXT:
            handleChromeKey(record, id, opt);
            break;
        case MY_BACKLIGHT_ENABLE:
            backlight_enable();
            break;
    }
}/*}}}*/

void handleChromeKey(keyrecord_t *record, uint8_t id, uint8_t opt) {
    uint8_t mod = 0;
    uint8_t newMod = 0, newModNext = 0;
    mod = get_mods();
    if (opt == 1) {
        newMod = MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LSHIFT);
        newModNext = MOD_BIT(KC_LCTRL);
    } else if (opt == 2) {//Mac
        newMod = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSHIFT);
        newModNext = MOD_BIT(KC_LGUI);
    }
    if (record->event.pressed) {
        switch (id) {
            case MY_CHROME_PREV:
                del_mods(mod);
                add_mods(newMod);
                add_key(KC_TAB);
                send_keyboard_report();

                del_mods(newMod);
                add_mods(mod);   // return alt but don't send
                break;
            case MY_CHROME_NEXT:
                del_mods(mod);
                add_mods(newModNext);
                add_key(KC_TAB);
                send_keyboard_report();
                del_mods(newModNext);
                add_mods(mod);   // return alt but don't send
                break;
        }
    } else {
        del_key(KC_TAB);
        del_mods(newMod);
        send_keyboard_report();
    }


}


