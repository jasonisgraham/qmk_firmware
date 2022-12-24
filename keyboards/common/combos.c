#include "combos_defs.c"

combo_t key_combos[COMBO_COUNT] = {
                                   COMBO(combo_s_a, SA_LAYER_ACTIVATE),
                                   COMBO(combo_backspace_y, KC_DELETE),
                                   COMBO(combo_apl_mutl, APL_MULT),
                                   COMBO(combo_apl_division, APL_DIVISION),
                                   COMBO(combo_y_i,EMACS_INSIDE_YANK),
                                   COMBO(combo_d_i,EMACS_INSIDE_DELETE),
                                   COMBO(combo_y_t,EMACS_TO_YANK),
                                   COMBO(combo_d_t,EMACS_TO_DELETE),

                                   COMBO(combo_lower__j_i, LALT(KC_7)),
                                   COMBO(combo_lower__j_l, THREAD_LAST),
                                   COMBO(combo_lower_j_i, THREAD_LAST),
                                   COMBO(combo_lower_u_i, THREAD_FIRST),

                                   COMBO(combo_3_7__2_8, RCTL(KC_Z)),
                                   COMBO(combo_4_10_4_12, KC_RIGHT),
                                   COMBO(combo_4_11_4_12, KC_RIGHT),
                                   COMBO(combo_4_10_4_11, KC_LEFT),
                                   COMBO(combo_4_10_4_11_4_12, RCTL(KC_C)),
                                   COMBO(combo_l_semicolon, RCTL(KC_C)),
                                   COMBO(combo_l_p, CLEAR_THAT_REPL),


                                   COMBO(combo_left_to_down, KC_DOWN),
                                         COMBO(combo_right_to_up, KC_UP),
                                   /* COMBO(combo_w_d, TO(_GAUTH)), */
                                   COMBO(combo_r_t, KC_AGIN),
                                   COMBO(combo_lower_semicolon, RCTL(KC_C)),

                                   COMBO(combo_backspace_g, KC_DELETE),
                                   COMBO(combo_backspace_h, TD(WWW_BACK_FORWARD)),
                                   COMBO(combo_m_period, KC_COLN),

                                   /* COMBO(combo_shift_alt, AUDIO_LAYER_HOLD), */
                                   COMBO(combo_LOWER_o_p, AUTOSHIFT_TOGGLE),
                                   /* COMBO(combo_LOWER_m_comma, LAYER_MOUSE_HOLD), */
                                   /* COMBO(combo_LOWER_l_semi, LAYER_RAISE_HOLD), */
                                   COMBO(combo_lower_j_k_l, LAYER_LOWER_HOLD),
                                   COMBO(combo_LOWER_lower_lower_period_lower_slash, TO(_BASE)),


                                   COMBO(combo_h_u, TD(DANCE_SAVE_LOAD_NS_SWITCH)),
                                   // COMBO(combo_j_n, KC_GRV),
                                   COMBO(combo_esc_semicolon, RSFT(KC_LSFT)),

                                   COMBO(combo_j_n, RSFT(KC_LSFT)),
                                   COMBO(combo_raise_h_raise_j, KC_DELETE),
                                   /* COMBO(combo_lower_semicolon, RCTL(KC_SCOLON)), */
                                   /* COMBO(combo_my_raise_g, OSL(_MACROS)), */

                                   // layers
                                   COMBO(combo_r_g, TD(DANCE_F5)),
                                   COMBO(combo_grave_q, QK_CAPS_WORD_TOGGLE),
                                   COMBO(combo_f_g, OSL(_MACROS)),
                                   COMBO(combo_s_d, TD(DANCE_SUPER)),
                                   COMBO(combo_w_e, OSL(_WINMOVE)),

                                   COMBO(combo_windows_k_l, LGUI(KC_MINUS)),
                                   COMBO(combo_slack_show_desktop, ALT_TAB), // only active in WINDOWS layer. bad name.  alt-tab tho

                                   COMBO(combo_e_f, my_grave),
                                   COMBO(combo_s_c, LALT(KC_SCOLON)),

                                   // emacs paste
                                   /* COMBO(combo_y_u, RCTL(KC_Y)), */
                                   // macros n'at
                                   COMBO(combo_v_d, KC_PASTE), // shell paste
                                   COMBO(combo_v_c, LALT(KC_LCBR)), // shell copy mode

                                   COMBO(combo_LOWER_SHIFTP, KC_BSPACE),

                                   //
                                   /* COMBO(combo_e_f, KC_TAB), */
                                   COMBO(combo_shiftlock_d_shiftlock_f, KC_TAB),
                                   COMBO(combo_d_f, KC_TAB),
                                   COMBO(combo_raise_d_raise_f, LSFT(KC_TAB)),
                                   /* COMBO(combo_topright_p_l, CTRL_P), */

                                   COMBO(combo_raise_u_raise_i, KC_DQUO),
                                   COMBO(combo_raise_m_raise_comma, KC_QUOT),
                                   COMBO(combo_m_comma, KC_DQUO),
                                   /* COMBO(combo_grave_topright, SYSTEM_LAYER_ACTIVATE), */
                                   /* COMBO(combo_grave_p, SYSTEM_LAYER_ACTIVATE), */

                                   // braces
                                   COMBO(combo_cap_j_cap_i, KC_LPRN),
                                   /* COMBO(combo_j_i, KC_LPRN), */
                                   COMBO(combo_j_i, BRACKET_PAREN),
                                   COMBO(combo_raise_j_raise_i, KC_RPRN),
                                   COMBO(combo_m_k, KC_LBRACKET),
                                   COMBO(combo_j_l, EMACS_WRAP_IN_THREAD_LAST),

                                   COMBO(combo_cap_m_cap_k, KC_LBRACKET),
                                   COMBO(combo_raise_m_raise_k, KC_RBRACKET),
                                   COMBO(combo_j_o, KC_LBRACKET),


                                   COMBO(combo_e_r, MO(_ROFI)),

                                   /* COMBO(combo_lower__j_i, KC_F), */
                                   // COMBO(combo_lower__j_i, EMACS_EVIL_FIND),
                                   COMBO(combo_lower_comma_l, KC_TILD),
                                   /* COMBO(combo_lower_comma_l, KC_TILD), */
                                   COMBO(combo_lower__comma_l, TERM_HOME),
                                   COMBO(combo_lower_k_raise_l, KC_UNDS),


                                   COMBO(combo_lower__i_o, CLJ_ANON_FN),
                                   COMBO(combo_lower__k_l, CLJ_REGEX),
                                   COMBO(combo_lower__comma_period, CLJ_SET),

                                   COMBO(combo_lower_d_lower_f, TO(_BASE)), // ??

                                   COMBO(combo_i_o, KC_BSLASH),
                                   COMBO(combo_raise_i_raise_o, KC_PIPE),

                                   COMBO(combo_k_l, KC_MINUS),
                                   COMBO(combo_K_L, KC_MINUS),
                                   COMBO(combo_raise_k_raise_l, KC_UNDS),
                                   COMBO(combo_j_k_l, KC_UNDS),
                                   /* COMBO(combo_lower_j_k_l, KC_UNDS), */
                                   COMBO(combo_cap_j_cap_k_cap_l, KC_UNDS),

                                   COMBO(combo_u_i, KC_QUOT),
                                   COMBO(combo_comma_l, KC_GRV),
                                   COMBO(combo_raise_comma_raise_l, KC_TILD),

                                   COMBO(combo_comma_period, KC_EQL),
                                   /* COMBO(combo_m_comma_period, KC_PLUS), */
                                   COMBO(raise_comma_raise_period, KC_PLUS),

                                   /* COMBO(combo_m_k_l, KC_COLN), */
                                   COMBO(combo_m_l, KC_COLN),

                                   COMBO(combo_h_j, KC_BSPC),
                                   COMBO(combo_H_J, KC_BSPC),

                                   /* COMBO(combo_lower_slash, TERM_CD_UP_DIR), */

                                   COMBO(combo_raise_j_raise_k, FISH_ACCEPT_SEND),

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
                                   COMBO(combo_j_i_o, KC_LCBR),
                                   COMBO(combo_cap_k_cap_o, KC_LCBR),
                                   COMBO(combo_raise_k_raise_o, KC_RCBR),

                                   COMBO(combo_lower_o_p, CTRL_N),
                                   COMBO(combo_o_p, CTRL_P),
                                   COMBO(combo_shiftlok, SHIFTLOCK_LAYER_ACTIVATE),


                                   COMBO(combo_raise_d_f, ALT_TAB),

                                   COMBO(combo_j_k, KC_ENTER),
                                   COMBO(combo_editing_j_editing_k, CIDER_RUN_PREV_COMMAND),
                                   COMBO(combo_editing_k_editing_l, THREAD_LAST),
                                   COMBO(combo_J_K, KC_ENTER),

                                   COMBO(combo_period_semicolon, EMACS_COMMENT_READER),
                                   COMBO(combo_lower_l_semi, EMACS_PRIVATE_READER),
                                   /* COMBO(combo_bottom_top_mid_column, LLOCK), */
                                   COMBO(combo_top_left_hyper, MO(_SYSTEM)),
                                   /* COMBO(combo_top_left_hyper, adhoc_set_hotkey), */
                                   COMBO(combo_k42_k43, adhoc_set_hotkey),
                                   COMBO(combo_raise_f, SA_LAYER_ACTIVATE),
                                   COMBO(combo_raise_r, MO(_MOUSE)),
                                   COMBO(combo_winmove_up_right, WINDOW_TOGGLE_HORIZONTAL_MAX),



};
