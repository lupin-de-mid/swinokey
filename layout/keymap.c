#include QMK_KEYBOARD_H

#include "arbitrary_keycode/include.h"
#define CUSTOM_SAFE_RANGE SAFE_RANGE
#include "lang_shift/include.h"
//#include "combo/include.h"
#include "custom_hotkeys.h"
#include "tt/include.h"
enum sofle_layers {
    L_EN = 0,
    L_EN_S,
    L_RU,
    L_RU_S,
    L_RED,
    L_GREEN
};

#define TG_RED TG(L_RED)
#define MO_RED MO(L_RED)
#define TT_RED (TT_000 + L_RED)

#define TG_GREEN TG(L_GREEN)
#define MO_GREEN MO(L_GREEN)
#define TT_GREEN (TT_001 + L_GREEN)

//remap order of buutons from left right to lines
#define MY_layout( \
    K00, K01, K02, K03, K04, K05,  \
    K10, K11, K12, K13, K14, K15,  \
    K20, K21, K22, K23, K24, K25,  \
    K30, K31, K32, K33, K34, K35, K36,    \
              K40, K41, K42, K43, K44,  \
    \
         K50, K51, K52, K53, K54, K55,  \
         K60, K61, K62, K63, K64, K65,  \
         K70, K71, K72, K73, K74, K75, \
    K80, K81, K82, K83, K84, K85, K86, \
    K90, K91, K92, K93, K94 \
) \
LAYOUT( \
    K00, K01, K02, K03, K04, K05,                       K50, K51, K52, K53, K54, K55, \
    K10, K11, K12, K13, K14, K15,                       K60, K61, K62, K63, K64, K65, \
    K20, K21, K22, K23, K24, K25,                       K70, K71, K72, K73, K74, K75, \
    K30, K31, K32, K33, K34, K35, K36,             K80, K81, K82, K83, K84, K85, K86, \
              K40, K41, K42, K43, K44,             K90, K91, K92, K93, K94 \
)

// Left number-row
#define CMB_PLS AG_PLUS
#define CMB_SCL AG_SCLN
#define CMB_GRV EN_GRV
#define CMB_EXL AG_EXCL
#define CMB_ASR AG_ASTR
#define CMB_LAN LA_CHNG

#define CMB_LB1 AG_LPRN
#define CMB_LB2 EN_LBRC
#define CMB_LB3 EN_LCBR
#define CMB_LB4 EN_LT

#define CMB_RB1 AG_RPRN
#define CMB_RB2 EN_RBRC
#define CMB_RB3 EN_RCBR
#define CMB_RB4 EN_GT

#define CMB_BSP KC_BACKSPACE
#define CMB_SFT SFT_N

#define CMB_ENT KC_ENT
#define CMB_EQL AG_EQL

#define CMB_SLS AG_SLSH
#define CMB_CTL CTRL_EN

#define CMB_DOT AG_DOT
#define CMB_QUE AG_QUES
#define CMB_CMM AG_CMSP
#define CMB_CLN AG_COLN
#define CMB_ALT ALT_EN
#define CMB_SPC KC_SPC
#define CMB_DQUE AG_COLN

#define CMB_TEST CMB_000
//Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)

#define CT_ENT LCTL(KC_ENT)
#define CT_BSPC LCTL(KC_BSPC)

// Этот макрос нужен, чтобы задавать одинаковые слои (в том числе и шифтовый слой) для английского и русского языка. В итоге их отличия будут только в буквах.
/// Позволяет задавать только изенившеяся клавиши языковые, проставляя все остальное автоматом
#define LANG_TWO_LAYERS(\
  L_DEFAULT, L_SHIFT,\
  /* Left hand */ \
       LU1, LU2, LU3, LU4, LU5, \
       LH1, LH2, LH3, LH4, LH5, \
       LD1, LD2, LD3, LD4, LD5, \
 /* Right hand */ \
       RU1, RU2, RU3, RU4, RU5, \
       RH1, RH2, RH3, RH4, RH5, RH6, \
       RD1, RD2, RD3, RD4, RD5, RD6, \
  /* ---------------------------- Shift layer ---------------------------- */ \
    /* Left hand */ \
       SLU1, SLU2, SLU3, SLU4, SLU5, \
       SLH1, SLH2, SLH3, SLH4, SLH5, \
       SLD1, SLD2, SLD3, SLD4, SLD5, \
 /* Right hand */ \
       SRU1, SRU2, SRU3, SRU4, SRU5, \
       SRH1, SRH2, SRH3, SRH4, SRH5, SRH6, \
       SRD1, SRD2, SRD3, SRD4, SRD5, SRD6 \
) \
/*-------------------------------------------------------------------------*/ \
      [L_DEFAULT] = MY_layout(  \
/* LEFT HALF */ \
        KC_ESC,  CMB_PLS, CMB_SCL,  CMB_GRV, CMB_CLN, CMB_EQL, \
        AG_UNDS,     LU1,     LU2,      LU3,     LU4,     LU5,    \
        CMB_DQUE,    LH1,     LH2,      LH3,     LH4,     LH5,   \
        EN_QUOT,     LD1,     LD2,      LD3,     LD4,     LD5,   _______,      \
                 CMB_CTL,  CMB_LAN, CMB_BSP, CMB_SFT, CMB_ENT, \
        /* RIGHT HALF */ \
         CMB_ASR, CMB_EXL,CMB_QUE, EN_HASH, AG_SLSH, CT_Z, \
             RU1,     RU2,     RU3,       RU4,     RU5,     AG_MINS, \
             RH1,     RH2,     RH3,       RH4,     RH5,         RH6,                    \
_______,     RD1,     RD2,     RD3,       RD4,     RD5,         RD6,                    \
TT_RED,  CMB_SPC, CMB_DOT, CMB_ALT, TT_GREEN \
      ), \
      \
      /*-----------------------------------------------------------------*/ \
      [L_SHIFT] = MY_layout(/* LEFT HALF */ \
        _______, AG_7, AG_5, AG_3, AG_1, AG_9, \
        _______, SLU1,    SLU2,    SLU3,    SLU4,    SLU5,     \
        _______, SLH1,    SLH2,    SLH3,    SLH4,    SLH5,     \
        _______,    SLD1,    SLD2,    SLD3,    SLD4,    SLD5, _______,\
                       _______, _______, _______, _______, _______,\
        \
        /* RIGHT HALF */ \
         AG_0,    AG_2,    AG_4,    AG_6,    AG_8,    CT_Y, \
         SRU1,    SRU2,    SRU3,    SRU4,    SRU5,    EN_TILD, \
         SRH1,    SRH2,    SRH3,    SRH4,    SRH5,    SRH6, \
 _______, SRD1,    SRD2,    SRD3,    SRD4,    SRD5,    SRD6, \
 _______, _______, AG_COMM, _______, _______\
      ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LANG_TWO_LAYERS(
        L_EN, L_EN_S,

        /* Left hand */
        EN_Q,  EN_W,    EN_E,    EN_R,    EN_T,
        EN_A,  EN_S,    EN_D,    EN_F,    EN_G,
        EN_Z,  EN_X,    EN_C,    EN_V,    EN_B,

        /* Right hand */
        EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,
        EN_H,    EN_J,    EN_K,    EN_L, _______,    _______,
        EN_N,    EN_M,   _______,_______,_______,_______,

        /* ---------------------------- Shift layer ---------------------------- */
       /* Left hand */
        EN_S_Q,  EN_S_W,    EN_S_E,    EN_S_R,    EN_S_T,
        EN_S_A,  EN_S_S,    EN_S_D,    EN_S_F,    EN_S_G,
        EN_S_Z,  EN_S_X,    EN_S_C,    EN_S_V,    EN_S_B,
        
        /* Right hand */
        EN_S_Y,    EN_S_U,    EN_S_I,    EN_S_O,  EN_S_P,
        EN_S_H,    EN_S_J,    EN_S_K,    EN_S_L, _______, _______,
        EN_S_N,    EN_S_M,   _______,   _______, _______, _______
        )

    LANG_TWO_LAYERS(
        L_RU, L_RU_S,

        /* Left hand */
        RU_J,  RU_TS,    RU_U,    RU_K,    RU_JE,
        RU_F,  RU_Y,    RU_V,    RU_A,    RU_P,
        RU_JA,  RU_CH,    RU_S,    RU_M,    RU_I,

        /* Right hand */
        RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,
        RU_R,    RU_O,    RU_L,    RU_D,    RU_ZH,    RU_E,
        RU_T,    RU_SF,   RU_B,    RU_JU,    _______,   _______,

       /* ---------------------------- Shift layer ---------------------------- */
       /* Left hand */
        RU_S_J,  RU_S_TS,    RU_S_U,    RU_S_K,    RU_S_JE,
        RU_S_F,  RU_S_Y,     RU_S_V,    RU_S_A,    RU_S_P,
        RU_S_JA, RU_S_CH,    RU_S_S,    RU_S_M,    RU_S_I,

        /* Right hand */
        RU_S_N,    RU_S_G,    RU_S_SH,    RU_S_SC,    RU_S_Z,
        RU_S_R,    RU_S_O,    RU_S_L,     RU_S_D,     RU_S_ZH,    RU_S_E,
        RU_S_T,    RU_S_SF,    RU_S_B,     RU_S_JU,    _______,   _______
        )


    [L_RED] = MY_layout(
        // LEFT HALF
         TG_RED,      KC_F7,   KC_F5,   KC_F1,   KC_F1,   KC_F9,
        _______,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
        _______,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
        _______,    CT_LEFT, CT_DOWN,   CT_UP, CT_RGHT, _______, _______,
                             _______, _______, _______, _______, _______,

        // RIGHT HALF
                  KC_F10,   KC_F2,   KC_F4,   KC_F6,   KC_F8, _______,
                 CMB_RB2, CMB_RB1, CMB_LB1, CMB_LB2, _______, _______,
                 CMB_LB4, CMB_LB3, CMB_RB3, CMB_RB4, _______, _______,
        _______,  KC_TAB, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
        ),

    [L_GREEN] = MY_layout(
        // LEFT HALF
         TG_RED,   KC_F7,   KC_F5,   KC_F1,   KC_F1,   KC_F9,
        _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
        _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
        _______, CT_LEFT, CT_DOWN,   CT_UP, CT_RGHT, _______, _______,
                          _______, _______, _______, _______, _______,

        // RIGHT HALF
                  KC_F10,   KC_F2,   KC_F4,   KC_F6,   KC_F8, _______,
                 CMB_RB2, CMB_RB1, CMB_LB1, CMB_LB2, _______, _______,
                 CMB_LB4, CMB_LB3, CMB_RB3, CMB_RB4, _______, _______,
        _______,  KC_TAB, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
        ),

};

#define HSV_CYAN_D        188, 255, 255
#define HSV_CYAN_L        108, 255, 255

const rgblight_segment_t PROGMEM en_layer_d[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_CYAN_D}
);

const rgblight_segment_t PROGMEM en_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_CYAN_L}
);

const rgblight_segment_t PROGMEM ru_layer_d[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GOLD}
);

const rgblight_segment_t PROGMEM ru_layer_l[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM red_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);

const rgblight_segment_t PROGMEM green_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    en_layer,
    en_layer,
    ru_layer,
    ru_layer,
    red_layer,
    green_layer
);

//const ComboWithKeycode combos[] PROGMEM = {
//    // Left Index
//    CHORD(TG_GREEN,    /* <- */ CMB_TEST)
//};

//const uint8_t combos_size = sizeof(combos)/sizeof(ComboWithKeycode);
const uint16_t tt_keys[][3] = {
//   { TT_CTJ, CT_J,  CT_BSLS }, // Убийство программы, если нажать три раза, то выдаёт Ctrl+\, что убивает безоговорочно.
    { TT_RED,  MO_RED,  TG_RED },
    { TT_GREEN,  MO_GREEN,  TG_GREEN },
//    { TT_GREN, MO_GREN, TG_GREN },
//    { TT_VIOL, MO_VIOL, TG_VIOL },
//    { TT_GRAY, MO_GRAY, TG_GRAY },
//    { TT_CYAN, MO_CYAN, TG_CYAN },
//    { TT_YELW, MO_YELW, TG_YELW },
//    { TT_GAME, MO_GAME, TG_GAME },
//    { TT_NUCL, MO_NUCL, TG_NUCL },
};
const uint8_t tt_size = sizeof(tt_keys)/(sizeof(uint16_t) * 3);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_EN));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_EN_S));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_RU));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_RU_S));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_RED));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_GREEN));
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_EN));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode

    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case L_EN:
            oled_write_ln_P(PSTR("En"), false);
            break;
        case L_EN_S:
            oled_write_ln_P(PSTR("En_S"), false);
            break;
        case L_RU:
            oled_write_ln_P(PSTR("Ru"), false);
            break;
        case L_RU_S:
            oled_write_ln_P(PSTR("Ru_S"), false);
            break;
        case L_RED:
            oled_write_ln_P(PSTR("RED"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case L_EN:
            oled_write_P(PSTR("En\n"), false);
            break;
        case L_EN_S:
            oled_write_P(PSTR("En_S\n"), false);
            break;
        case L_RU:
            oled_write_P(PSTR("RU"), false);
            break;
        case L_RU_S:
            oled_write_P(PSTR("RU_S"), false);
            break;
        case L_RED:
            oled_write_P(PSTR("RED"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    if (!combo_process_record(keycode, record))
//        return false;
    if (!tt_process_record(keycode, record))
        return false;
    if (!lang_shift_process_record(keycode, record))
        return false;
    if (!process_my_hotkeys(keycode, record))
        return false;
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PAGE_DOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}


#endif
void user_timer(void) {
//    combo_user_timer();
    lang_shift_user_timer();
}

void matrix_scan_user(void) {
    user_timer();
}
