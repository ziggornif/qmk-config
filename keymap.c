#include QMK_KEYBOARD_H

// ── Custom keycodes ───────────────────────────────────────────────────────────

enum custom_keycodes {
    FULLSCR = SAFE_RANGE,
    LEFTHALF,
    RIGHTHALF,
    LEFTSCR,
    RIGHTSCR,
    ERASEW,
    // French accents (assumes US-International layout dead keys)
    AGRV, EGRV, UGRV,
    EACU,
    ACIR, ECIR, ICIR, OCIR, UCIR,
    EUML, IUML, UUML,
    CCED,
};

static void tap_with_mods(uint8_t mods, uint16_t kc) {
    register_mods(mods);
    tap_code(kc);
    unregister_mods(mods);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case FULLSCR:
            tap_with_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT), KC_F);
            return false;
        case LEFTHALF:
            tap_with_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT), KC_LEFT);
            return false;
        case RIGHTHALF:
            tap_with_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT), KC_RIGHT);
            return false;
        case LEFTSCR:
            tap_with_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL), KC_LEFT);
            return false;
        case RIGHTSCR:
            tap_with_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL), KC_RIGHT);
            return false;
        case ERASEW:
            tap_with_mods(MOD_BIT(KC_LCTL), KC_BSPC);
            return false;

        // dead grave (`) + vowel
        case AGRV: tap_code(KC_GRV);  tap_code(KC_A); return false;
        case EGRV: tap_code(KC_GRV);  tap_code(KC_E); return false;
        case UGRV: tap_code(KC_GRV);  tap_code(KC_U); return false;

        // dead acute (') + e
        case EACU: tap_code(KC_QUOT); tap_code(KC_E); return false;

        // dead circumflex (Shift+6) + vowel
        case ACIR: tap_with_mods(MOD_BIT(KC_LSFT), KC_6); tap_code(KC_A); return false;
        case ECIR: tap_with_mods(MOD_BIT(KC_LSFT), KC_6); tap_code(KC_E); return false;
        case ICIR: tap_with_mods(MOD_BIT(KC_LSFT), KC_6); tap_code(KC_I); return false;
        case OCIR: tap_with_mods(MOD_BIT(KC_LSFT), KC_6); tap_code(KC_O); return false;
        case UCIR: tap_with_mods(MOD_BIT(KC_LSFT), KC_6); tap_code(KC_U); return false;

        // dead diaeresis (Shift+') + vowel
        case EUML: tap_with_mods(MOD_BIT(KC_LSFT), KC_QUOT); tap_code(KC_E); return false;
        case IUML: tap_with_mods(MOD_BIT(KC_LSFT), KC_QUOT); tap_code(KC_I); return false;
        case UUML: tap_with_mods(MOD_BIT(KC_LSFT), KC_QUOT); tap_code(KC_U); return false;

        // ç = ' + c
        case CCED: tap_code(KC_QUOT); tap_code(KC_C); return false;
    }
    return true;
}

#define LT2_SPC LT(2, KC_SPC)
#define LT3_SPC LT(3, KC_SPC)
#define LT4_BSPC LT(4, KC_BSPC)

// ── Combos ────────────────────────────────────────────────────────────────────

// const uint16_t PROGMEM combo_layer3[] = {MO(1), LT2_TAB, COMBO_END};

combo_t key_combos[] = {
    // COMBO(combo_layer3, MO(3)),
};

// ── Keymaps ───────────────────────────────────────────────────────────────────

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                                KC_LALT, KC_LGUI, MO(1),   LT2_SPC,  LT3_SPC, KC_BSPC, KC_RALT, KC_DEL
  ),

  [1] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_TRNS,  KC_TRNS,  KC_TRNS,   LALT(KC_PSCR),    S(KC_PSCR), KC_PSCR,
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                       KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_BSPC,
    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,                      LEFTHALF, LEFTSCR,  RIGHTSCR,  RIGHTHALF,  KC_TRNS,    KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_MINS,  KC_PLUS,   KC_LCBR,    KC_RCBR,    KC_PIPE,
                                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [2] = LAYOUT(
    KC_TRNS,  KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY,  KC_MNXT,                     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD,  KC_VOLU,                     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS, ERASEW,
    KC_LSFT,  KC_TRNS, KC_TRNS, KC_TRNS, FULLSCR,  KC_TRNS,                     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC, KC_BSLS,
                                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, EACU,    KC_TRNS, KC_TRNS,                     KC_TRNS, UGRV,    ICIR,    OCIR,    KC_TRNS, KC_TRNS,
    KC_TRNS, AGRV,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, UUML,    IUML,    EUML,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, CCED,    ACIR,    ECIR,    KC_TRNS, KC_TRNS,   UCIR,    EGRV,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

// ── OLED ──────────────────────────────────────────────────────────────────────

#ifdef OLED_ENABLE

#include "bongo.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_0;
}

static void render_status(void) {
    // Layer
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("BASE "), false); break;
        case 1: oled_write_P(PSTR("LOWER"), false); break;
        case 2: oled_write_P(PSTR("RAISE"), false); break;
        case 3: oled_write_P(PSTR("ACCNT"), false); break;
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
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }
    if (is_keyboard_master()) {
        render_status();
    } else {
        draw_bongo(false);
    }
    return false;
}

#endif
