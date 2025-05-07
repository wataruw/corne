#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "naginata.h"
#include "quantum.h"

// 薙刀式のオン/オフに使うキーの定義
static uint16_t ng_on_keys[] = {KC_H, KC_J};  // HJで薙刀式オン
static uint16_t ng_off_keys[] = {KC_F, KC_G}; // FGで薙刀式オフ

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, LCTL(KC_C),    LCTL(KC_V),    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LALT,       KC_RALT,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,   MO(2),
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   MO(1),
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,     KC_SPC,        KC_ENT, KC_BSPC,  KC_DEL
                                      //`-----------------------------'  `-----------------------------'

  ),

  [1] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,------------------------------------------------------------------------------------------.
       KC_TAB, JP_CIRC,  JP_YEN,    JP_7,    JP_8,    JP_9,    RGB_TOG,       RGB_TOG, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT,  KC_PGUP,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------------+--------------+------------+---------------+---------+---------|
      KC_LCTL, JP_COLN,   JP_AT,    JP_4,    JP_5,    JP_6,       JP_0,       KC_HOME,       KC_LEFT,       KC_DOWN,       KC_UP,        KC_RGHT,   KC_END,    MO(2),
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------------+--------------+------------+---------------+---------+---------|
      KC_LSFT, JP_SCLN, JP_BSLS,    JP_1,    JP_2,    JP_3,                               KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,  KC_PGDN,    MO(1),
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------------+--------------+------------+---------------+---------+---------|
                                          KC_LGUI, KC_LALT,    KC_BTN2,       KC_BTN1,       KC_BSPC,        KC_DEL
                                      //`-----------------------------'  `-----------------------------------------'
  ),

  [2] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,--------------------------------------------------------------------------------------------------.
       KC_TAB, KC_PSCR,  KC_F12,   KC_F7,   KC_F8,   KC_F9,    RGB_TOG,         RGB_TOG,      NGSW_WIN,   KC_MS_WH_UP,    KC_MS_UP,        KC_LNG2,        KC_LNG1,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-------------+--------------+--------------+------------+---------------+---------------+---------|
      KC_LCTL, JP_LBRC,  KC_F11,   KC_F4,   KC_F5,   KC_F6,    KC_LALT,         KC_RALT,      NGSW_MAC,    KC_MS_LEFT,     KC_BTN1,    KC_MS_RIGHT,        XXXXXXX,    MO(2),
  //|--------+--------+--------+--------+--------+--------+-----------'  `-------------+--------------+--------------+------------+---------------+---------------+---------|
      KC_LSFT, JP_RBRC,  KC_F10, XXXXXXX,   KC_F2,   KC_F3,                                    NG_TAYO, KC_MS_WH_DOWN,  KC_MS_DOWN,        XXXXXXX,        NG_SHOS,    MO(1),
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-------------+--------------+--------------+------------+---------------+---------------+---------|
                                          KC_LGUI, KC_LALT,     KC_SPC,          KC_ENT,       KC_BSPC,        KC_DEL
                                      //`-----------------------------'  `-------------------------------------------'
  ),

  // 薙刀式レイヤー
  [3] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,-----------------------------------------------------------------.
       KC_TAB,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    NG_SHOS,       NG_TAYO,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,   NGSW_MAC,      NGSW_WIN,    NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN,   MO(0),
  //|--------+--------+--------+--------+--------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                               NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH,   MO(1),
  //|--------+--------+--------+--------+--------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT,    NG_SHFT,      NG_SHFT2, KC_BSPC,  KC_DEL
                                      //`-----------------------------'  `-----------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(KC_MS_RIGHT, KC_MS_LEFT), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
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
