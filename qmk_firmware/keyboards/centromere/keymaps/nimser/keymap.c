#include QMK_KEYBOARD_H

/* transparent template for putting keys
 [???] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
*/

enum centromere_layers
{
	BASE, // Base layer
	SHFT, // Shifted letters
  NNUM, // Navigation and numbers
	SPEC, // Special characters
  FUN   // FN keys and function controls
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x6_3( \
  // FIXME Use composition for accents and special charecters,
  // see https://math.dartmouth.edu/~sarunas/Linux_Compose_Key_Sequences.html
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_B,    KC_W,    KC_P,     KC_O,  KC_DEL,                      KC_BSPC,    KC_V,    KC_D,    KC_L,    KC_J,  KC_Z,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_U,    KC_I,    KC_E, KC_COMMA,                         KC_C,    KC_T,    KC_S,    KC_R,    KC_N,   KC_M,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_APP,OSM(MOD_LSFT),KC_Y,   KC_X,MT(MOD_LALT,KC_DOT),KC_K,   MT(MOD_RCTL,KC_QUOT),    KC_Q,    KC_G,    KC_H,    KC_F, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(SPEC), KC_LCTL,  LT(FUN,KC_SPC),TT(NNUM), KC_RALT\
                                      //`--------------------------'  `--------------------------'
  ),


 [NNUM] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, _______,                      XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_0, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_7,    KC_8,    KC_9, _______, XXXXXXX,                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

 [SPEC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DLR, KC_PIPE,   KC_LT,   KC_GT, KC_AMPR, XXXXXXX,                      S(KC_6), KC_KP_PLUS, KC_MINS, KC_SLASH, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HASH, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_SCLN,                      KC_QUES, KC_EXLM, KC_UNDS,KC_PERC, KC_ASTR,  KC_EQL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_AT, KC_LBRC, KC_RBRC, KC_COLON,KC_TILDE,                       _______, KC_QUOT, KC_DQUO,  KC_GRV, KC_CIRC, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3( \
  // backspace, enter, arrows..D
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_F4,   KC_F5,   KC_F6,  KC_F12, XXXXXXX,                      KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F11, XXXXXXX,                      KC_BRID,  KC_ENT, KC_COPY,KC_PASTE,  KC_CUT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,                      XXXXXXX, KC_UNDO, XXXXXXX,KC_AGAIN, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

};

void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
    	case BASE:
    		set_led_off;
    		break;
        case FUN:
            set_led_blue;
            break;
        case NNUM:
            set_led_red;
            break;
        default:
            break;
    }
};
