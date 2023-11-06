/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keyrecords/combos.h"
#include "keyrecords/keycodes.h" 
#include "hexa.h"

#ifdef OLED_ENABLE
    #include "oled/oled.h"
#endif
#ifdef OCEAN_DREAM_ENABLE
    #include "oled/ocean_dream.h"
#endif
#ifdef LUNA_ENABLE
    #include "oled/luna.h"
#endif

/* TEMPLATE
     * ,-----------------------------------------------.                     ,------------------------------------------------.
     * |      |      |        |        |        |      |                    |      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * |      |      |        |        |        |      |                    |      |    ü   |        |    ö    |      |      |
     * |------+------+--------+--------+--------+------|                    |------+--------+--------+---------+------+------|
     * |      |   ä  |        |        |        |      |-------.    ,-------|      |        |        |         |      |      |
     * |------+------+--------+--------+--------+------|       |    |       |------+--------+--------+---------+------+------|
     * |      |      |        |        |        |      |-------|    |-------|      |        |        |         |      |      |
     *  -----------------------------------------------/       /             -----------------------------------------------'
     *                          |      |      |      | /      /       \      \  |      |      |      |
     *                          |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                          `----------------------------'           '------''--------------------'
     *
    [_TEMPLATE] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____, ____, ____, ____, ____, ____,                                                                                 ____, ____, ____, ____, ____, ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____, ____, ____, ____, ____, ____,                                                                                 ____, ____, ____, ____, ____, ____,   
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____, ____, ____, ____, ____, ____,                                                                                 ____, ____, ____, ____, ____, ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____, ____, ____, ____, ____, ____, ____,                                                                     ____, ____, ____, ____, ____, ____, ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                    ____, ____, ____, ____,                                                                                     ____, ____, ____, ____
*/

/* Define layer names */
enum layers {
    _QWERTZ = 0,
    _TRACKMANIA,
    _GAMING,
    _NAVIGATION,
    _SYMBOLS,
    _NUMPAD,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_QWERTZ] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        QK_GESC,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(_QWERTZ),
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_TAB,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                   DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_HASH,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_LSFT,    LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                                   KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(DE_SS),  KC_RSFT,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_LCTL,    DE_Y,           KC_X,           KC_C,           KC_V,           KC_B, TO(_GAMING),  TO(_TRACKMANIA),    KC_N,           KC_M,           DE_COMM,        DE_DOT,         DE_MINS,        KC_RCTL,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
                LT(_MEDIA,KC_RCMD), LT(_NUMPAD,K_ESC), BSPLT(_NAVIGATION),    KC_TAB,                                 KC_APP,    SPLT(_SYMBOLS),   KC_ENTER,       KC_DEL
    ),

    [_NAVIGATION] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,           ____,           ____,           ____,           KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           KC_PGUP,        KC_UP,          KC_PGDN,        ____,           ____,   
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       ____,           ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,       ____,          ____,        ____,           KC_PSCR,        KC_HOME,        KC_END,         ____,           ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                        ____,           ____,           ____,           ____,                                                       ____,       ____,           ____,           ____
    ),

    [_SYMBOLS] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,           ____,           ____,           ____,           KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       DE_LPRN,        DE_RPRN,        DE_LABK,        DE_RABK,        DE_EQL,                                 ____,           KC_F1,          KC_F2,          KC_F3,          KC_F4,          ____, 
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       DE_LCBR,        DE_RCBR,        DE_AMPR,        DE_PIPE,        DE_ACUT,                                ____,           KC_F5,          KC_F6,          KC_F7,          KC_F8,          ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       K_BRTO,         K_BRTC,         DE_MINS,        DE_PLUS,        DE_CIRC ,    ____,           ____,      ____,            KC_F9,          KC_F10,         KC_F11,         KC_F12,         ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                        ____,           ____,           ____,           ____,                                                       ____,       ____,           ____,           ____

    ), 
    
    [_NUMPAD] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,           ____,           ____,           KC_PSLS,        KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   KC_NUM,         KC_P7,          KC_P8,          KC_P9,          KC_PAST,        ____,   
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   DE_COMM,        KC_P4,          KC_P5,          KC_P6,          KC_PMNS,        ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,       ____,           ____,       DE_DOT,         KC_P1,          KC_P2,          KC_P3,          KC_PPLS,        ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                ____,       ____,       ____,       ____,                                                                   ____,           KC_P0,          ____,        ____
    ), 

    [_MEDIA] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,           ____,           ____,           ____,           KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       KC_MUTE,        ____,           ____,           ____,           ____,                                   ____,           ____,           ____,           ____,           ____,           ____, 
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       KC_VOLU,        KC_MPRV,        KC_MPLY,        KC_MNXT,        ____,                                   ____,           ____,           ____,           ____,           ____,           ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       KC_VOLD,        KC_CALC,        KC_COPY,        KC_PASTE,       ____,       ____,           ____,       ____,           ____,           ____,           ____,           ____,           ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
            ____,       ____,       ____,       ____,                                                                   ____,       ____,       ____,       ____

    ), 


    /*  
    ---------------------------------------------------------------------------------------------
            GAME Relevant 
    ---------------------------------------------------------------------------------------------
    */ 
    [_TRACKMANIA] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,          ____,           ____,           ____,           KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           ____,          KC_UP,          ____,           ____,           ____,   
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,                                   ____,           KC_LEFT,       KC_DOWN,        KC_RIGHT,       ____,           ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        ____,       ____,           ____,           ____,           ____,           ____,       ____,           ____,       ____,           ____,           ____,           ____,          ____,           ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                        ____,           ____,           KC_SPACE,       ____,                                                   ____,           ____,           ____,           ____
    ),

    [_GAMING] = LAYOUT(
    // ,-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        QK_GESC,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_TAB,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                   DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           ____,   
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_LSFT,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                   KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        ____,
    // |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        KC_LCTL,    DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,       DE_PLUS ,       ____,       KC_N,           KC_M,           DE_COMM,        DE_DOT,         DE_MINS,        ____,
    // \-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/
                        DE_ODIA,        DE_ADIA,            KC_SPACE,       DE_UDIA,                                                   ____,           ____,           ____,           ____
    ),

};

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _NAVIGATION:
        rgb_matrix_sethsv(HSV_GREEN); 
        rgb_matrix_mode_noeeprom(RGB_MATRIX_GRADIENT_UP_DOWN);
        break;
    case _SYMBOLS:
        rgb_matrix_sethsv(HSV_BLUE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE); 
        break;
    case _NUMPAD:
        rgb_matrix_sethsv(HSV_ORANGE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH); 
        break;
    case _MEDIA:
        rgb_matrix_sethsv(HSV_GOLDENROD);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR); 
        break;
    case _TRACKMANIA:
        rgb_matrix_sethsv(HSV_CHARTREUSE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_PENDULUM); 
        break;
    case _GAMING:
        rgb_matrix_sethsv(HSV_RED);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_BREATHING); 
        break;
    default: //  for any other layers, or the default layer
    case _QWERTZ:
        rgblight_sethsv (HSV_WHITE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        break;
    }
  return state;
}

#endif


#ifdef OLED_ENABLE

bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall

    if(!oled_timeout_housekeeping()) {
        return false;
    }
    
    if (is_keyboard_master()){
        enum layers current_active = IS_LAYER_ON(_NAVIGATION) ? _NAVIGATION : _QWERTZ;
        current_active = IS_LAYER_ON(_SYMBOLS) ? _SYMBOLS : current_active;
        current_active = IS_LAYER_ON(_NUMPAD) ? _NUMPAD : current_active;
        current_active = IS_LAYER_ON(_MEDIA) ? _MEDIA : current_active;
        current_active = IS_LAYER_ON(_TRACKMANIA) ? _TRACKMANIA : current_active;
        current_active = IS_LAYER_ON(_GAMING) ? _GAMING : current_active;

        switch (current_active) {
            case _NAVIGATION:
                render_navigation();
                break;  
            case _SYMBOLS:
                render_arrow();
                break;     
            case _NUMPAD:
                render_code();
                break;     
            case _MEDIA:
                render_media();
                break;
            case _TRACKMANIA:
                render_car();
                break;
            case _GAMING:
                render_arcade();
                break;
            default:
            case _QWERTZ:
                render_home();
        }

        render_empty_line();
        // Host Keyboard Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("    "), false);
        
        #ifdef LUNA_ENABLE
        render_luna(0,13);
        #endif

    } else {

        #ifdef OCEAN_DREAM_ENABLE
        render_stars();
        #endif

    }

    return false;
}

#endif
