#include "combos_defs.c"

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_editing_equal, emacs_indent_buffer),

    COMBO(combo_period_slash, LALT(KC_DOT)),

    COMBO(combo_q_w, KC_GRAVE),
    COMBO(combo_a_s, KC_ESCAPE),

    COMBO(combo_w_e, KC_TAB),
    COMBO(combo_s_d, OSM(MOD_RCTL)),
    COMBO(combo_d_f, OSL(_LOWER)),
    COMBO(combo_e_r, OSL(_WINMOVE)),

    COMBO(combo_raise_w_raise_e, LSFT(KC_TAB)),
    /* COMBO(combo_topright_p_l, CTRL_P), */

    /* COMBO(combo_raise_u_raise_i, KC_DQUO), */
    COMBO(combo_raise_m_raise_comma, KC_QUOT),
    COMBO(combo_m_comma, KC_DQUO),
    /* COMBO(combo_grave_topright, SYSTEM_LAYER_ACTIVATE), */
    /* COMBO(combo_grave_p, SYSTEM_LAYER_ACTIVATE), */

    // braces
    COMBO(combo_cap_j_cap_i, BRACKET_PAREN),
    /* COMBO(combo_j_i, KC_LPRN), */
    COMBO(combo_j_i, BRACKET_PAREN),
    COMBO(combo_raise_j_raise_i, KC_RPRN),
    COMBO(combo_m_k, KC_LBRACKET),
    COMBO(combo_raise_i_raise_o, EMACS_WRAP_IN_THREAD_LAST),
    COMBO(combo_raise_u_raise_i, EMACS_WRAP_IN_THREAD_FIRST),
    COMBO(combo_raise_u_raise_o, EMACS_WRAP_IN_THREAD_LAST),
    COMBO(combo_editing_u_editing_i, HOME_THEN_EMACS_WRAP_IN_THREAD_FIRST),
    COMBO(combo_editing_u_editing_o, HOME_THEN_EMACS_WRAP_IN_THREAD_LAST),
    COMBO(combo_cap_m_cap_k, KC_LBRACKET),
    COMBO(combo_raise_m_raise_k, KC_RBRACKET),
    COMBO(combo_j_o, KC_LBRACKET),
    COMBO(combo_cap_j_cap_o, KC_LBRACKET),



    /* COMBO(combo_lower_j_i, KC_F), */
    // COMBO(combo_lower_j_i, EMACS_EVIL_FIND),
    COMBO(combo_lower_comma_l, TERM_HOME),
    /* COMBO(combo_lower_comma_l, KC_TILD), */
    COMBO(combo_lower__comma_l, TERM_HOME),


    COMBO(combo_lower__i_o, CLJ_ANON_FN),
    COMBO(combo_lower__k_l, CLJ_REGEX),
    COMBO(combo_lower__comma_period, CLJ_SET),

    COMBO(combo_lower_d_lower_f, TO(_BASE)), // ??

    COMBO(combo_i_o, KC_BSLASH),
    /* COMBO(combo_raise_i_raise_o, KC_PIPE), */

    COMBO(combo_comma_l, KC_GRV),
    COMBO(combo_raise_comma_raise_l, KC_TILD),

    COMBO(combo_comma_period, EQUAL_THEN_SPACE),
    /* COMBO(combo_m_comma_period, KC_PLUS), */
    COMBO(raise_comma_raise_period, THREAD_LAST_EQUAL),
    COMBO(editing_comma_editing_period, FN_THEN_THREAD_LAST_EQUAL),

    /* COMBO(combo_m_k_l, KC_COLN), */

    COMBO(combo_u_i, THREAD_FIRST),
    COMBO(combo_u_o, THREAD_LAST),

    /* COMBO(combo_lower_slash, TERM_CD_UP_DIR), */

    COMBO(combo_lower_lprn, KC_LPRN),
    COMBO(combo_lower_rprn, KC_RPRN),
    COMBO(combo_lower_exlm, KC_EXLM),
    COMBO(combo_lower_at, KC_AT),
    COMBO(combo_lower_hash, KC_HASH),
    COMBO(combo_lower_dlr, KC_DLR),
    COMBO(combo_lower_perc, KC_PERC),
    COMBO(combo_lower_circ, KC_CIRC),
    COMBO(combo_lower_ampr, KC_AMPR),
    COMBO(combo_lower_astr, KC_ASTR),


    COMBO(combo_editor_select_lprn, EMACS_SEL_LPRN),
    COMBO(combo_editor_select_rprn, EMACS_SEL_RPRN),
    COMBO(combo_editor_select_exlm, EMACS_SEL_EXLM),
    COMBO(combo_editor_select_at,   EMACS_SEL_AT),
    COMBO(combo_editor_select_hash, EMACS_SEL_HASH),
    COMBO(combo_editor_select_dlr,  EMACS_SEL_DLR),
    COMBO(combo_editor_select_perc, EMACS_SEL_PERC),
    COMBO(combo_editor_select_circ, EMACS_SEL_CIRC),
    COMBO(combo_editor_select_ampr, EMACS_SEL_AMPR),
    COMBO(combo_editor_select_astr, EMACS_SEL_ASTR),


    COMBO(combo_shiftlock_lower_lprn, KC_LPRN),
    COMBO(combo_shiftlock_lower_rprn, KC_RPRN),
    COMBO(combo_shiftlock_lower_exlm, KC_EXLM),
    COMBO(combo_shiftlock_lower_at, KC_AT),
    COMBO(combo_shiftlock_lower_hash, KC_HASH),
    COMBO(combo_shiftlock_lower_dlr, KC_DLR),
    COMBO(combo_shiftlock_lower_perc, KC_PERC),
    COMBO(combo_shiftlock_lower_circ, KC_CIRC),
    COMBO(combo_shiftlock_lower_ampr, KC_AMPR),
    COMBO(combo_shiftlock_lower_astr, KC_ASTR),



    COMBO(combo_k_o, KC_LCBR),
    /* COMBO(combo_k_o_semicolon, LALT(KC_X)), */
    COMBO(combo_j_i_o, KC_LCBR),
    COMBO(combo_cap_j_cap_i_cap_o, KC_LCBR),
    COMBO(combo_cap_k_cap_o, KC_LCBR),
    COMBO(combo_raise_k_raise_o, KC_RCBR),
    COMBO(combo_raise_j_raise_i_raise_o, KC_RCBR),

    COMBO(combo_lower_o_p, CTRL_N),
    COMBO(combo_left_shift_forward_slash, KC_ENTER),

    COMBO(combo_space_m_k, OSM(MOD_MASK_ALL_MODS)),
    COMBO(combo_lower_m_k, OSM(MOD_MASK_ALL_MODS)),
    COMBO(combo_lower_j_k, RCTL(KC_ENTER)),
    COMBO(combo_raise_j_raise_k, LCTL(KC_ENTER)),
    COMBO(combo_j_k, KC_ENTER),
    COMBO(combo_editing_j_editing_k, FISH_ACCEPT_SEND),
    COMBO(combo_editing_k_editing_l, TERM_CD_PREVIOUS),
    COMBO(combo_J_K, KC_ENTER),

    COMBO(combo_z_x_c, META_X),
    COMBO(combo_period_semicolon, EMACS_COMMENT_READER),
    COMBO(combo_lower_l_semi, EMACS_PRIVATE_READER),
    /* COMBO(combo_bottom_top_mid_column, LLOCK), */
    COMBO(combo_q_w_e, adhoc_set_hotkey),
    COMBO(combo_w_d, EMACS_WRAP_HYDRA),
    COMBO(combo_1_7_y, TD(DANCE_MICROPHONE)),
    COMBO(combo_1_7_y_u, OSL(_LAYER_LOCK)),
    COMBO(combo_mod_r1_mod_r4, LLOCK),
    COMBO(combo_raise_r, LAYER_MOUSE_HOLD),
    COMBO(combo_winmove_up_right, WINDOW_TOGGLE_HORIZONTAL_MAX),
    COMBO (combo_lower_semicolon, CLJ_ARROW),
    COMBO(combo_lower_comma_lower_period, BROWSER_SEARCH_OPEN_TABS),
    /* #ifdef PREONIC_BUILD */
    /* #endif */



    COMBO(combo_f_b, KC_MS_BTN1),
    COMBO(combo_g_r3, KC_MS_BTN2),
    COMBO(combo_super__f_b, KC_MS_BTN1),
    COMBO(combo_super__g_r3, KC_MS_BTN2),
    COMBO(combo_mouse1_mouse2, KC_MS_BTN3),
    COMBO(combo_mod_r3_super, KC_LEFT),
    COMBO(combo_mod_r2_b, KC_RIGHT),
    COMBO(combo_select_grave, EMACS_SEL_GRAVE),

};
