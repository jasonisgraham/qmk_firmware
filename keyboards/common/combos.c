#include "combos_defs.c"

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_editing_equal, emacs_indent_buffer),
    COMBO(combo_s_a, SA_LAYER_ACTIVATE),
    COMBO(combo_period_slash, LALT(KC_DOT)),

    COMBO(combo_z_x, EASYMOTION_LEADER),

    COMBO(combo_super_r_super_g, RESET_INPUT_PREFS),

    COMBO(combo_e_t, CIDER_RUN_TEST),

    /* COMBO(combo_macro_r_macro_g, IMPORTER_RELOAD), */

    COMBO(combo_super_tab_backtab, LGUI(KC_GRAVE)),
    /* COMBO(combo_backspace_y, KC_DELETE), */
    /* COMBO(combo_y_i,EMACS_INSIDE_YANK), */
    /* COMBO(combo_d_i,EMACS_INSIDE_DELETE), */
    COMBO(combo_y_t,EMACS_TO_YANK),
    COMBO(combo_d_t,EMACS_TO_DELETE),

    /* COMBO(, OSL(_EMACS_SELECT)), */
    COMBO(combo_right__lower_j_i, OSL(_FILES)),
    COMBO(combo_lower__j_i, ROFI_LOCATE),
    COMBO(combo_lower__j_l, THREAD_LAST),
    COMBO(combo_m_comma_period, LPRN_EQUAL),
    COMBO(combo_lower_j_i, THREAD_LAST),
    COMBO(combo_lower_u_i, THREAD_FIRST),

    COMBO(combo_3_7__2_8, RCTL(KC_Z)),
    COMBO(combo_4_10_4_12, KC_RIGHT),
    COMBO(combo_4_11_4_12, KC_RIGHT),
    COMBO(combo_space_m, LALT(KC_M)),
    COMBO(combo_space_j, LALT(KC_M)),
    COMBO(combo_space_h, LALT(KC_M)),
    COMBO(combo_k47_space, KC_RIGHT),
    COMBO(combo_super_space, KC_DOWN),
    COMBO(combo_super_space_k47, KC_DOWN),
    COMBO(combo_super_k47, KC_LEFT),
    COMBO(combo_super_k47, KC_LEFT),
    COMBO(combo_4_10_4_11, KC_LEFT),
    COMBO(combo_n_k47, KC_LEFT),
    COMBO(combo_4_10_4_11_4_12, RCTL(KC_C)),
    COMBO(combo_o_p, KC_UP),


    COMBO(combo_l_p, CLEAR_THAT_REPL),

    COMBO(combo_k_semicolon, OSM(MOD_LALT)),
    COMBO(combo_K_cap_semicolon, OSM(MOD_LALT)),
    COMBO(combo_m_l, OSM(MOD_LCTL)),

    COMBO(combo_j_k_l, OSL_RCTL_LALT),
    COMBO(combo_J_K_L, OSL_RCTL_LALT),
    COMBO(combo_k_l_semi, OSM( MOD_LALT | MOD_RCTL | MOD_LCTL | MOD_LGUI)), // j+k+l+: l -> C-⎕
    COMBO(combo_K_L_SEMI, OSM( MOD_LALT | MOD_RCTL | MOD_LCTL | MOD_LGUI)), // j+k+l+: l -> C-⎕

    /* COMBO(, OSM(MOD_RCTL | MOD_LCTL)), */
    COMBO(combo_k_l, OSM(MOD_RCTL)),
    COMBO(combo_K_L, OSM(MOD_RCTL)),

    COMBO(combo_h_j, ALL_MODS_OSM),
    COMBO(combo_H_J, ALL_MODS_OSM),
    /* COMBO(combo_H_J, OSM(MOD_LSFT|MOD_RSFT|MOD_RCTL|MOD_LALT|MOD_RALT)), */

    /* COMBO(combo_raise_k_raise_l, OSM(MOD_LCTL)), */
    COMBO(combo_l_semicolon, OSM(MOD_LCTL)),
    COMBO(combo_j_l, OSM(MOD_LALT)),

    /* COMBO(combo_l_k_semicolon, OSM(MOD_LCTL)), */
    /* COMBO(combo_l_p, OSM(MOD_LCTL)), */
    /* COMBO(combo_M_cap_semi, OSM(MOD_LCTL)), */
    /* COMBO(combo_lower_k_lower_l, KC_UNDS), */




    COMBO(combo_left_to_down, KC_DOWN),
    COMBO(combo_right_to_up, KC_UP),
    /* COMBO(combo_w_d, TO(_GAUTH)), */
    COMBO(combo_r_t, KC_AGIN),

    COMBO(combo_backspace_g, OSL(_EMACS_SELECT)),
    COMBO(combo_k49_k410, OSL(_EMACS_SELECT)),
    COMBO(combo_k49_k410_k11, KC_INSERT),

    COMBO(combo_backspace_h, TD(WWW_BACK_FORWARD)),
    /* COMBO(combo_m_period, SEND_STRING("#()")), */

    /* COMBO(combo_shift_alt, AUDIO_LAYER_HOLD), */
    COMBO(combo_LOWER_o_p, AS_TOGG),
    /* COMBO(combo_LOWER_m_comma, LAYER_MOUSE_HOLD), */
    /* COMBO(combo_LOWER_l_semi, LAYER_RAISE_HOLD), */
    COMBO(combo_lower_j_k_l, LAYER_LOWER_HOLD),
    COMBO(combo_LOWER_lower_lower_period_lower_slash, TO(_BASE)),

    COMBO(combo_h_u, KC_LBRACKET),
    COMBO(combo_j_n, KC_LEFT_ANGLE_BRACKET),

    /* COMBO(combo_raise_h_raise_j, KC_DELETE), */
    /* COMBO(combo_my_raise_g, TD(DANCE_MACROS)), */

    /* COMBO(combo_space_period, ROFI_DRUN), */
    COMBO(combo_space_j_k, ROFI_DRUN),
    /* COMBO(combo_space_u, ROFI_LOCATE), */
    /* COMBO(combo_space_i, LAUNCHER_WINDOWS), */
    /* COMBO(combo_space_o, LAUNCHER_CLIPBOARD), */
    // layers
    COMBO(combo_r_g, TD(DANCE_F5)),
    COMBO(combo_grave_q, QK_REPEAT_KEY),
    COMBO(combo_f_g, TD(DANCE_MACROS)),
    COMBO(combo_w_e, OSL(_WINMOVE)),

    COMBO(combo_windows_k_l, LGUI(KC_MINUS)),
    COMBO(combo_slack_show_desktop, ALT_TAB), // only active in WINDOWS layer. bad name.  alt-tab tho

    COMBO(combo_e_f, TD(DANCE_SAVE_LOAD_NS_SWITCH)),
    /* COMBO(combo_s_c, LALT(KC_SCOLON)), */

    // emacs paste
    /* COMBO(combo_y_u, RCTL(KC_Y)), */
    // macros n'at
    /* COMBO(combo_v_d, KC_PASTE), // shell paste */
    COMBO(combo_v_d, TERM_PASTE), // shell paste
    COMBO(combo_v_c, LALT(KC_LCBR)), // shell copy mode

    COMBO(combo_LOWER_SHIFTP, KC_BSPACE),

    //
    /* COMBO(combo_e_f, KC_TAB), */
    COMBO(combo_shiftlock_d_shiftlock_f, TD(DANCE_TAB)),
    COMBO(combo_s_d, OSL(_LOWER)),
    COMBO(combo_d_f, KC_TAB),
    COMBO(combo_x_c, CTRL_X_ALL_MODS_OSM),
    COMBO(combo_raise_d_raise_f, LSFT(KC_TAB)),
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


    COMBO(combo_e_r, TD(DANCE_ROFI)),

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


    COMBO(combo__lower_d_f, backtab),
    COMBO(combo_raise_d_f, ALT_TAB),

    COMBO(combo_space_m_k, OSM(MOD_MASK_ALL_MODS)),
    COMBO(combo_lower_m_k, OSM(MOD_MASK_ALL_MODS)),
    COMBO(combo_lower_j_k, RCTL(KC_ENTER)),
    COMBO(combo_raise_j_raise_k, LCTL(KC_ENTER)),
    COMBO(combo_j_k, KC_ENTER),
    COMBO(combo_editing_j_editing_k, FISH_ACCEPT_SEND),
    COMBO(combo_editing_k_editing_l, TERM_CD_PREVIOUS),
    COMBO(combo_J_K, KC_ENTER),

    COMBO(combo_period_semicolon, EMACS_COMMENT_READER),
    COMBO(combo_lower_l_semi, EMACS_PRIVATE_READER),
    /* COMBO(combo_bottom_top_mid_column, LLOCK), */
    COMBO(combo_top_left_hyper, MO(_SYSTEM)),
    COMBO(combo_top_left_my_q, OSL(_CODE)),
    COMBO(combo_a_s_k, adhoc_set_hotkey),
    COMBO(combo_q_w_e, adhoc_set_hotkey),
    COMBO(combo_q_w, EMACS_WRAP_HYDRA),
    COMBO(combo_w_d, EMACS_WRAP_HYDRA),
    COMBO(combo_1_7_y, TD(DANCE_MICROPHONE)),
    COMBO(combo_1_7_y_u, OSL(_LAYER_LOCK)),
    COMBO(combo_k42_k43, LLOCK),
    COMBO(combo_raise_f, TD(DANCE_MACROS)),
    COMBO(combo_raise_r, LAYER_MOUSE_HOLD),
    COMBO(combo_winmove_up_right, WINDOW_TOGGLE_HORIZONTAL_MAX),
    COMBO (combo_lower_semicolon, CLJ_ARROW),
    COMBO(combo_lower_comma_lower_period, BROWSER_SEARCH_OPEN_TABS),
    /* #ifdef PREONIC_BUILD */
    COMBO(combo_up_left, winmove_UL),
    COMBO(combo_up_right, winmove_UR),
    COMBO(combo_right_zero, winmove_R),
    COMBO(combo_six_left, winmove_L),
    COMBO(combo_down_left, winmove_DL),
    COMBO(combo_down_right, winmove_DR),
    COMBO(combo_left_right, WINDOW_TOGGLE_HORIZONTAL_MAX),
    COMBO(combo_up_down, winmove_U),
    /* #endif */



    COMBO(combo_mod_r3_super, KC_RIGHT),
    COMBO(combo_mod_r2_b, KC_LEFT),

};
