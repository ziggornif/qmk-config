#include QMK_KEYBOARD_H

// ── Macros ────────────────────────────────────────────────────────────────────

enum custom_keycodes {
    FULLSCR = SAFE_RANGE,
    LEFTHALF,
    RIGHTHALF,
    LEFTSCR,
    RIGHTSCR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case FULLSCR:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            tap_code(KC_F);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            return false;
        case LEFTHALF:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            tap_code(KC_LEFT);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            return false;
        case RIGHTHALF:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            tap_code(KC_RIGHT);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT));
            return false;
        case LEFTSCR:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
            tap_code(KC_LEFT);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
            return false;
        case RIGHTSCR:
            register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
            tap_code(KC_RIGHT);
            unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
            return false;
    }
    return true;
}

// ── Combos ────────────────────────────────────────────────────────────────────

const uint16_t PROGMEM combo_layer3[] = {MO(1), MO(2), COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_layer3, MO(3)),
};

// ── Keymaps ───────────────────────────────────────────────────────────────────

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                                KC_LALT, KC_LGUI, MO(1),  MO(2),    KC_ENT,  KC_SPC,  KC_BSPC, KC_DEL
  ),

  [1] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_PSCR), KC_PSCR,
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                       KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,
    KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, FULLSCR,  KC_PERC,                     LEFTHALF, LEFTSCR,  RIGHTSCR, RIGHTHALF,KC_RPRN,    KC_TILD,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_MINS,  KC_PLUS,  KC_LCBR,  KC_RCBR,    KC_PIPE,
                                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [2] = LAYOUT(
    KC_TRNS,  KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY,  KC_MNXT,                     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD,  KC_VOLU,                     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS, KC_TRNS,
    KC_LSFT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC, KC_BSLS,
                                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

// ── OLED ──────────────────────────────────────────────────────────────────────

#ifdef OLED_ENABLE

#include "bongo.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) return OLED_ROTATION_0;
    return OLED_ROTATION_270;
}

static void render_master(void) {
    // Layer
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("BASE "), false); break;
        case 1: oled_write_P(PSTR("LOWER"), false); break;
        case 2: oled_write_P(PSTR("RAISE"), false); break;
        case 3: oled_write_P(PSTR("FUNC "), false); break;
        default: oled_write_P(PSTR("?????"), false);
    }

    oled_write_P(PSTR("     "), false);

    // Modificateurs
    oled_write_P(PSTR("MODS "), false);
    oled_write_P(PSTR("-----"), false);
    uint8_t mods = get_mods();
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT  ") : PSTR("     "), false);
    oled_write_P(mods & MOD_MASK_CTRL  ? PSTR("CTL  ") : PSTR("     "), false);
    oled_write_P(mods & MOD_MASK_ALT   ? PSTR("ALT  ") : PSTR("     "), false);
    oled_write_P(mods & MOD_MASK_GUI   ? PSTR("GUI  ") : PSTR("     "), false);

    oled_write_P(PSTR("     "), false);

    // WPM
    oled_write_P(PSTR("WPM  "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        draw_bongo(false);
    } else {
        render_master();
    }
    return false;
}

#endif
