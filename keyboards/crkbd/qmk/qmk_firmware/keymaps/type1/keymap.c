#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "naginata.h"

// 薙刀式のオン/オフに使うキーの定義
static uint16_t ng_on_keys[] = {KC_H, KC_J};  // HJで薙刀式オン
static uint16_t ng_off_keys[] = {KC_F, KC_G}; // FGで薙刀式オフ

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, LCTL(KC_C),    LCTL(KC_V),    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LNG2,       KC_LNG1,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(2),     KC_SPC,        KC_ENT,   MO(1), KC_DOWN
                                      //`-----------------------------'  `-----------------------------'

  ),

  [1] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB, KC_PMNS, JP_SCLN,    JP_7,    JP_8,    JP_9, LCTL(KC_C),    LCTL(KC_V), KC_HOME,   KC_UP, KC_PGUP, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PPLS, JP_COLN,    JP_4,    JP_5,    JP_6,    KC_LALT,       KC_RALT, KC_LEFT, KC_BTN1, KC_RGHT, KC_BTN2, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_PDOT,    JP_0,    JP_1,    JP_2,    JP_3,                             KC_END, KC_DOWN, KC_PGDN, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,     KC_SPC,        KC_ENT, _______, KC_DOWN
                                      //`-----------------------------'  `-----------------------------'
  ),

  [2] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB, S(JP_1), S(JP_2), S(JP_3), S(JP_4), S(JP_5), LCTL(KC_C),    LCTL(KC_V), S(JP_6), S(JP_7), S(JP_8),S(JP_9),S(JP_SLSH),KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, RGB_TOG,NGSW_LNX,NGSW_MAC,NGSW_WIN, NG_SHOS,    KC_LALT,       KC_RALT,S(JP_CIRC),JP_MINS,JP_LBRC, JP_RBRC, JP_BSLS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, NG_KOTI,  NG_MLV, NG_TAYO, XXXXXXX,                           JP_AT,S(JP_MINS),S(JP_LBRC),S(JP_RBRC),JP_YEN,JP_CIRC,
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,     KC_SPC,        KC_ENT, _______, KC_DOWN
                                      //`-----------------------------'  `-----------------------------'
  ),

  // 薙刀式レイヤー
  [3] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T, LCTL(KC_C),    LCTL(KC_V),    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G, LCTL(KC_Z),    LCTL(KC_R),    NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                               NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,    NG_SHFT,      NG_SHFT2, _______, KC_DOWN
                                      //`-----------------------------'  `-----------------------------'
  )
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif

void keyboard_post_init_user(void) {
    // 薙刀式の初期化
    set_naginata(3, ng_on_keys, ng_off_keys); // レイヤー3を薙刀式レイヤーとして使用
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // 薙刀式の処理
    if (!process_naginata(keycode, record)) {
        return false;
    }

  return true;
}
