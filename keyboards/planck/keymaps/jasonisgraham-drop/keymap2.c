#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _CTRL,
    _MOUSE,
    _SYSTEM,
    _WINDOWS,
    _MACROS,
    _SHIFTLOCK,
    _WINMOVE,
    _ALT,
    _SUPER,
    _EDITING,
    _LAYER13,
    _VIM_CMDS,
    _LAYER15,
    _COLORS,
    _LAYER17,
    _LAYER18,
    _LAYER19,
    _EMACS_SEL_WINDOW,
    _GAUTH,
    _AUDIO,
    _VOLUME,
    _BRIGHTNESS,
    _ADHOC_SET_HOTKEY,
};

#include "../../../common/keycodes.c"
#include "../../../common/drop_tapdance.c"

#define test KC_ASTR
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TD_D TD(DANCE_13)
#define alt_tab ALT_TAB
#define backspace KC_BSPACE
#define below_b KC_RALT
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define below_n KC_RALT
#define below_v MT(MOD_RCTL, KC_ESCAPE)
#define emacs_a _______
#define emacs_f EMACS_YAS_FILTER_ANON
#define emacs_m EMACS_YAS_MAP_ANON
#define emacs_r EMACS_YAS_REMOVE_ANON
#define esc_ctrl MT(MOD_RCTL, KC_ESCAPE)
#define hyper KC_LCTL // OSL(_WINDOWS)
#define key_0_0 KC_LCTL
#define key_0_1 RCTL(RALT(KC_RSFT))
#define key_4_11 KC_BSPACE // CYCLE_DROP_COLORS // LAYER_LOWER_HOLD
#define key_4_12 KC_ENTER
#define macro_alt_slash SS_RALT(SS_TAP(X_SLASH))
#define my_cap_h RSFT(KC_H)
#define my_cap_i RSFT(KC_I)
#define my_cap_j RSFT(KC_J)
#define my_cap_k RSFT(KC_K)
#define my_cap_l RSFT(KC_L)
#define my_cap_m RSFT(KC_M)
#define my_cap_o RSFT(KC_O)
#define my_comma KC_COMMA // TD(DANCE_23)
#define my_forward_slash TD(DANCE_25)
#define my_left_shift KC_LSFT //  LM(_SHIFTLOCK, MOD_LSFT)

#define my_lctl MT(MOD_RCTL, KC_ESCAPE)
#define my_lower MO(_LOWER)
#define my_lower MO(_LOWER)
#define my_lower_comma TD(DANCE_29)
#define my_lower_d KC_F7
#define my_lower_f KC_F8
#define my_lower_i KC_PGDOWN
#define my_lower_j KC_DOWN
#define my_lower_k KC_UP
#define my_lower_l KC_RIGHT
#define my_lower_m TD(DANCE_29)
#define my_lower_n TD(DANCE_69)
#define my_lower_o KC_END
#define my_lower_p TD(DANCE_27)
#define my_lower_period TD(DANCE_30)
#define my_lower_semi esc_ctrl
#define my_lower_slash SHIFTLOCK_LAYER_ACTIVATE
#define lower_LOWER TO(_BASE)
#define lower_right_of_lower _______
#define lower_key_4_11 _______
#define lower_key_4_12 _______
#define my_raise RAISE
#define my_raise_comma KC_2
#define my_raise_h KC_BSPACE
#define my_raise_i KC_8
#define my_raise_j KC_4
#define my_raise_k KC_5
#define my_raise_l KC_6
#define my_raise_m KC_1
#define my_raise_n KC_0
#define my_raise_o KC_9
#define my_raise_p KC_0
#define my_raise_period KC_3
#define my_raise_u KC_7
#define my_right_shift LM(_ALT, MOD_LSFT) // KC_RSFT
#define raise_semi KC_MINUS

#define my_semicolon TD(DANCE_19)
#define my_singlequote TD(DANCE_20)
#define my_space KC_SPACE

#define my_period KC_DOT
#define my_minus _______
#define my_grave TD(DANCE_0)

#define WINDOWS_Q TD(DANCE_38)

#define my_a TD(DANCE_A)
#define my_b TD(DANCE_B)
#define my_c TD(DANCE_C)
#define my_d TD(DANCE_D)
#define my_e TD(DANCE_E)
#define my_f TD(DANCE_F)
#define my_g TD(DANCE_G)
#define my_h TD(DANCE_H)
#define my_i TD(DANCE_I)
#define my_j TD(DANCE_J)
#define my_k TD(DANCE_K)
#define my_l TD(DANCE_L)
#define my_m TD(DANCE_M)
#define my_n TD(DANCE_N)
#define my_o TD(DANCE_O)
#define my_p TD(DANCE_P)
#define my_q TD(DANCE_Q)
#define my_r TD(DANCE_R)
#define my_s TD(DANCE_S)
#define my_t TD(DANCE_T)
#define my_u TD(DANCE_U)
#define my_v TD(DANCE_V)
#define my_w TD(DANCE_W)
#define my_x TD(DANCE_X)
#define my_y TD(DANCE_Y)
#define my_z TD(Z_OR_SHIFT)

#define right_of_lower esc_ctrl // my_left_shift ///hyper // / MT(MOD_RCTL, KC_ESCAPE)
#define select_slack LGUI(KC_S)
#define show_desktop LALT(LGUI(LCTL(KC_D)))
#define below_m MT(MOD_RCTL, KC_ESCAPE)
#define super LM(_SUPER, MOD_LGUI) // TD(SUPER_WINDOWS)
/* #define super KC_LGUI */
#define alt LM(_ALT, MOD_LALT)
/* #define super TD(SUPER_WINDOWS) */
#define topright _______
#include "user_song_list.h"
/* #define hyper KC_LCTL */
/* #define key_4_12 KC_LCTL */
/* #define my_left_shift KC_LSPO */
/* #define my_right_shift KC_ENTER */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_planck_grid(my_grave, my_q, my_w, my_e, my_r, my_t, CAPS_WORD, my_y, my_u, my_i, my_o, my_p, my_lctl, my_a, my_s, my_d, my_f, my_g, _______, my_h, my_j, my_k, my_l, my_semicolon, my_left_shift, my_z, my_x, my_c, my_v, my_b, _______, my_n, my_m, my_comma, my_period, my_forward_slash, hyper, hyper, LGUI(LCTL(KC_LALT)), alt, RAISE, super, my_left_shift, my_space, LOWER, right_of_lower, key_4_11, key_4_12),

    [_LOWER] = LAYOUT_planck_grid(TD(DANCE_26), KC_F1, KC_F2, KC_F3, KC_F4, TD(DANCE_73), _______, KC_HOME, KC_PGUP, my_lower_i, my_lower_o, my_lower_p, _______, KC_F5, KC_F6, KC_F7, KC_F8, _______, _______, KC_LEFT, my_lower_j, my_lower_k, my_lower_l, my_lower_semi, _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_APPLICATION, _______, my_lower_n, my_lower_m, my_lower_comma, my_lower_period, my_lower_slash, _______, _______, _______, _______, MO(_MOUSE), _______, _______, TO(4), lower_LOWER, lower_right_of_lower, lower_key_4_11, lower_key_4_12

                                  ),

    [_RAISE] = LAYOUT_planck_grid(TD(DANCE_32), OSL(_EDITING), EMACS_OTHER_WINDOW, KC_END, EMACS_BUFFER_REVERT, _______, _______, _______, my_raise_u, my_raise_i, my_raise_o, my_raise_p, _______, DYN_REC_START1, DYN_MACRO_PLAY1, KC_NO, TD(DANCE_33), OSL(7), _______, my_raise_h, my_raise_j, my_raise_k, my_raise_l, raise_semi, _______, DYN_REC_START2, DYN_MACRO_PLAY2, DYN_REC_STOP, KC_NO, FISH_ACCEPT_SEND, _______, KC_0, my_raise_m, my_raise_comma, KC_3, KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENTER, KC_0, _______, _______),

    [_CTRL] = LAYOUT_planck_grid(my_grave, my_q, my_w, my_e, my_r, my_t, CAPS_WORD, my_y, my_u, my_i, my_o, my_p, my_lctl, my_a, my_s, my_d, my_f, my_g, _______, my_h, my_j, my_k, my_l, my_semicolon, my_left_shift, my_z, my_x, my_c, my_v, my_b, _______, my_n, my_m, my_comma, my_period, my_forward_slash, hyper, hyper, LGUI(LCTL(KC_LALT)), alt, RAISE, super, my_left_shift, my_space, LOWER, right_of_lower, key_4_11, key_4_12),

    /* _______, _______, _______, KC_MS_UP,       _______, _______, _______, _______, KC_ASRP,        KC_ASDN,        KC_ASUP,        KC_ASTG, */
    /* _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    GAUTH_LAYER_ACTIVATE, KC_MS_BTN1,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN2,     _______, _______, */
    /* KC_LSHIFT,      _______, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     _______, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_RSHIFT, */
    /* _______, TG(4),          _______, _______, _______, KC_MS_BTN1,     KC_NO,          _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */

    // 4
    [_MOUSE] = LAYOUT_planck_grid(TD(DANCE_34), _______, _______, KC_MS_UP, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDOWN, KC_END, _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, OSL(_GAUTH), _______, KC_MS_BTN1, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_BTN2, _______, SHIFTLOCK_LAYER_ACTIVATE, _______, _______, _______, _______, _______, _______, LALT(LGUI(KC_N)), KC_MS_BTN3, TD(DANCE_35), TD(DANCE_36), _______, _______, KC_NO, _______, _______, _______, TO(_BASE), _______, _______, _______, _______, _______, _______),

    // 5
    [_SYSTEM] = LAYOUT_planck_grid(SYSTEM_LAYER_DEACTIVATE, _______, _______, _______, _______, _______, _______, KC_PSTE, KC_AGIN, DEBUG, RESET_ANIMATION, RESET, _______, MO(_AUDIO), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ASTG, _______, _______, _______, _______, MO(_BRIGHTNESS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

                                   /* SYSTEM_LAYER_DEACTIVATE,   AU_TOG,         MU_MOD,         MU_TOG,         _______, RGB_SPD,        RGB_SPI,        RGB_SAD,        RGB_SAI,        _______, WEBUSB_PAIR,    RESET, */
                                   /* RGB_MODE_PLAIN, RGB_MODE_SNAKE,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, _______, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        _______, KC_MEDIA_STOP,  _______, */
                                   /* KC_ASTG, KC_ASON, KC_ASOFF, RGBLIGHT_HUE_STEP, _______, _______,      _______, RGB_MOD,        _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK, */
                                   /* CYCLE_FAVE_ANIMATIONS, TO(_LAYER13), TOGGLE_BREATHING, _______, _______, _______, KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE */
                                   ),

    // 6
    [_WINDOWS] = LAYOUT_planck_grid(TO(_BASE), WINDOWS_Q, TD(DANCE_39), LGUI(KC_E), TD(DANCE_40), LGUI(KC_T), LGUI(KC_MINUS), LGUI(KC_Y), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), RGUI(KC_ESCAPE), LGUI(KC_A), select_slack, show_desktop, LGUI(KC_F), TD(DANCE_42), _______, LGUI(KC_H), TD(DANCE_43), TD(DANCE_44), TD(DANCE_45), _______, TO(_BASE), LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), RGUI(KC_V), _______, _______, TD(DANCE_46), LGUI(KC_M), _______, RSFT(LGUI(KC_K)), RCTL(RGUI(KC_Q)), _______, _______, _______, LALT(KC_6), _______, ALT_TAB, _______, LALT(KC_8), _______, OSL(_ADHOC_SET_HOTKEY), _______, _______),

    // 7
    [_MACROS] = LAYOUT_planck_grid(TD(DANCE_52), EMACS_RE_FIND, _______, _______, emacs_r, _______, EMACS_GOTO_PARSE_ITEM, _______, EMACS_BACKWARD_UP, _______, EMACS_ANON_FN, _______, _______, emacs_a, CD_CSV, EMACS_YAS_DOC, emacs_f, EMACS_INSERT_GET_FEED, EMACS_GOTO_GET_FEED, _______, _______, EMACS_YAS_KEYS_DESCRUCTURE, EMACS_YAS_TL, EMACS_COMMENT_READER, _______, _______, _______, EMACS_YAS_C, _______, _______, EMACS_GOTO_SYNC_FEED, _______, emacs_m, _______, _______, TERM_CD_UP_DIR, _______, _______, _______, _______, _______, _______, KC_NO, _______, _______, _______, _______, _______),

    // 8
    [_SHIFTLOCK] = LAYOUT_planck_grid(TO(_BASE), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), _______, RSFT(KC_Y), RSFT(KC_U), my_cap_i, my_cap_o, RSFT(KC_P), ESC_THEN_BASE_LAYER, RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), _______, my_cap_h, my_cap_j, my_cap_k, my_cap_l, TD(DANCE_55), SHIFTLOCK_LAYER_DEACTIVATE, RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), _______, RSFT(KC_N), my_cap_m, KC_LABK, KC_RABK, KC_QUES, _______, _______, _______, _______, _______, _______, KC_NO, _______, LOWER, _______, _______, _______),

    // 9
    [_WINMOVE] = LAYOUT_planck_grid(TO(_BASE), _______, _______, _______, _______, _______, _______, RGUI(RSFT(KC_Y)), _______, _______, RGUI(RSFT(KC_O)), _______, _______, _______, _______, LALT(LGUI(LCTL(KC_D))), _______, _______, _______, TD(DANCE_58), RGUI(RSFT(KC_J)), TD(DANCE_59), TD(DANCE_60), _______, _______, _______, _______, KC_F11, _______, _______, _______, RGUI(RSFT(KC_N)), TD(DANCE_47), _______, RGUI(RSFT(KC_DOT)), _______, _______, _______, _______, _______, TO(0), _______, KC_NO, TD(DANCE_48), TD(DANCE_49), TD(DANCE_50), _______, _______),

    // 10
    [_ALT] = LAYOUT_planck_grid(my_grave, my_q, my_w, my_e, my_r, my_t, CAPS_WORD, my_y, my_u, my_i, my_o, my_p, my_lctl, my_a, my_s, my_d, my_f, my_g, _______, my_h, my_j, my_k, my_l, my_semicolon, my_left_shift, my_z, my_x, my_c, my_v, my_b, _______, my_n, my_m, my_comma, my_period, my_forward_slash, hyper, hyper, LGUI(LCTL(KC_LALT)), KC_LALT, RAISE, KC_LGUI, my_left_shift, my_space, LOWER, right_of_lower, key_4_11, key_4_12),

    // 11
    [_SUPER] = LAYOUT_planck_grid(my_grave, my_q, my_w, my_e, my_r, my_t, CAPS_WORD, my_y, my_u, my_i, my_o, my_p, my_lctl, my_a, my_s, my_d, my_f, my_g, _______, my_h, my_j, my_k, my_l, my_semicolon, my_left_shift, my_z, my_x, my_c, my_v, my_b, _______, my_n, my_m, my_comma, my_period, my_forward_slash, hyper, hyper, LGUI(LCTL(KC_LALT)), KC_LALT, RAISE, KC_LGUI, my_left_shift, my_space, LOWER, right_of_lower, key_4_11, key_4_12),

    // 12
    [_EDITING] = LAYOUT_planck_grid(TO(_BASE), _______, EMACS_OTHER_WINDOW, _______, EMACS_BUFFER_REVERT, _______, _______, EMACS_COPY_FILE_PATH, LCTL(KC_7), _______, EMACS_OTHER_WINDOW, _______, _______, _______, _______, _______, RALT(KC_ENTER), _______, RCTL(KC_QUOTE), RALT(RSFT(KC_H)), RALT(RSFT(KC_J)), RALT(RSFT(KC_K)), RALT(RSFT(KC_L)), RCTL(KC_SCOLON), _______, _______, _______, EMACS_WINDOW_CLOSE, _______, _______, _______, RALT(RSFT(KC_N)), EMACS_ACE_WINDOW_SWAP, _______, _______, TERM_CD_UP_DIR, _______, _______, _______, _______, OSL(18), _______, _______, KC_NO, RALT(KC_ENTER), _______, _______, _______

                                    ),

    [_LAYER13] = LAYOUT_planck_grid(TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MODE_PLAIN, _______, RGB_MODE_FORWARD, RGB_MODE_REVERSE, _______, _______, _______, _______, _______, _______, _______, _______, RGBLIGHT_HUE_STEP, RGBLIGHT_MODE_STATIC_LIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_VIM_CMDS] = LAYOUT_planck_grid(TO(0), _______, LALT(KC_F), _______, _______, _______, _______, RCTL(KC_Y), _______, TO(0), _______, RCTL(KC_V), _______, _______, _______, _______, _______, OSL(15), TD(DANCE_H), _______, TD(DANCE_J), TD(DANCE_64), TD(DANCE_65), KC_LCBR, _______, _______, TD(DANCE_66), _______, _______, LALT(KC_B), _______, TD(DANCE_67), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_LAYER15] = LAYOUT_planck_grid(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_COLORS] = LAYOUT_planck_grid(TO(_BASE), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), RSFT(KC_Y), RSFT(KC_U), RSFT(KC_I), RSFT(KC_O), RSFT(KC_P), TD(DANCE_54), ESC_THEN_BASE_LAYER, RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), my_cap_h, my_cap_j, my_cap_k, my_cap_l, TD(DANCE_55), TD(DANCE_56), SHIFTLOCK_LAYER_DEACTIVATE, RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), RSFT(KC_N), RSFT(KC_M), KC_LABK, KC_RABK, KC_QUES, SHIFTLOCK_LAYER_DEACTIVATE, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_TWINKLE, _______, RGBLIGHT_MODE_STATIC_LIGHT, _______, _______, _______

                                   ),

    [_LAYER17] = LAYOUT_planck_grid(TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DLR, KC_PERC, KC_CIRC, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RPRN, KC_EXLM, KC_AT, KC_HASH, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [_LAYER18] = LAYOUT_planck_grid(TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_7, EMACS_SEL_8, EMACS_SEL_9, EMACS_SEL_0, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_4, EMACS_SEL_5, EMACS_SEL_6, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EMACS_SEL_0, EMACS_SEL_1, EMACS_SEL_2, EMACS_SEL_3, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [_GAUTH]   = LAYOUT_planck_grid(TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, gauth_plex, _______, _______, _______, _______, gauth_fb, gauth_gh, _______, gauth_hb, _______, _______, gauth_lp, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_AUDIO]      = LAYOUT_planck_grid(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, _______, _______),
    [_BRIGHTNESS] = LAYOUT_planck_grid(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_ADHOC_SET_HOTKEY] = LAYOUT_planck_grid(TO(_BASE), LCTL(RALT(RGUI(KC_Y))), LCTL(RALT(RGUI(KC_W))), _______, LCTL(RALT(RGUI(KC_R))), _______, _______, LCTL(RALT(RGUI(KC_Y))), _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(RALT(RGUI(KC_G))), _______, _______, LCTL(RALT(RGUI(KC_J))), LCTL(RALT(RGUI(KC_K))), LCTL(RALT(RGUI(KC_L))), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(RALT(RGUI(KC_N))), _______, _______, _______, _______),

};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
    return true;
}

/* bool dip_switch_update_user(uint8_t index, bool active) { */
/*     switch (index) { */
/*         case 0: */
/*             if (active) { */
/*                 layer_on(_ADJUST); */
/*             } else { */
/*                 layer_off(_ADJUST); */
/*             } */
/*             break; */
/*         case 1: */
/*             if (active) { */
/*                 muse_mode = true; */
/*             } else { */
/*                 muse_mode = false; */
/*             } */
/*     } */
/*     return true; */
/* } */

#include "colors.c"

LEADER_EXTERNS();

void leader_matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) {
            // Anything you can do in my_a macro.
            SEND_STRING("QMK is awesome.");
        }
        SEQ_TWO_KEYS(TD_D, TD_D) {
            SEND_STRING(SS_LCTL("k") SS_LCTL("c"));
        }
        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }
        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
    }
}

#include "../../../common/combos.c"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
            return true;
        case KC_LCBR:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;

        case KC_LCBR:
            register_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;

        case KC_LBRACKET:
            register_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
            break;

        case KC_TAB:
            register_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
            break;

        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
            unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;
        case KC_LCBR:
            unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;

        case KC_LBRACKET:
            unregister_code16((!shifted) ? KC_LBRACKET : KC_RBRACKET);
            break;

        case KC_TAB:
            unregister_code16((!shifted) ? KC_TAB : RALT(KC_SLASH));
            break;

        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}