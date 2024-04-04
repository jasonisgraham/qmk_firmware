#include QMK_KEYBOARD_H

const uint16_t PROGMEM cmbo_lower_dot_slash[] = {LOWER, my_forward_slash, my_period, COMBO_END};
const uint16_t PROGMEM combo_mod_r1[] = {LOWER, my_forward_slash, my_period, COMBO_END};
const uint16_t PROGMEM combo_A_S[] = {my_cap_a, my_cap_s, COMBO_END};
const uint16_t PROGMEM combo_H_J[] = {my_cap_h, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_I[] = {my_cap_j, my_cap_i, COMBO_END};
const uint16_t PROGMEM combo_J_I_O[] = {my_cap_j, my_cap_i, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_J_K[] = {my_cap_k, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_K_L[] = {my_cap_k, my_cap_l, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_K_L_SEMI[] = {my_cap_k, my_cap_l, my_cap_j, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_J_O[] = {my_cap_j,  my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_K_L[] = {my_cap_k, my_cap_l, COMBO_END};
const uint16_t PROGMEM combo_K_L_SEMI[] = {my_cap_k, my_cap_l, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_K_O[] = {my_cap_k, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_K_cap_semi[] = {my_cap_k, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_M_K[] = {my_cap_m, my_cap_k, COMBO_END};
const uint16_t PROGMEM combo_M_cap_semi[] = {my_cap_m, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_a_s[] = {my_a, my_s, COMBO_END};
const uint16_t PROGMEM combo_a_s_k[] = {my_a, my_s, my_k, COMBO_END};
const uint16_t PROGMEM combo_b_r3[] = {my_b, mod_r3, COMBO_END};
const uint16_t PROGMEM combo_c_v[] = {my_c, my_v, COMBO_END};
const uint16_t PROGMEM combo_comma_dot[] = {my_comma, my_period, COMBO_END};
const uint16_t PROGMEM combo_comma_dot_slash[] = {my_forward_slash, my_comma, my_period, COMBO_END}; // ]
const uint16_t PROGMEM combo_comma_semi[] = {my_semicolon, my_comma, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_d_i[] = {my_d, my_i, COMBO_END};
const uint16_t PROGMEM combo_d_t[] = {my_d, my_t, COMBO_END};
const uint16_t PROGMEM combo_d_v[] = {my_v, my_d, COMBO_END};
const uint16_t PROGMEM combo_e_f[] = {my_e, my_f, COMBO_END};
const uint16_t PROGMEM combo_e_r[] = {my_e, my_r, COMBO_END};
const uint16_t PROGMEM combo_e_t[] = {my_e, my_t, COMBO_END};
const uint16_t PROGMEM combo_editing_comma__editing_period[] = {editing_comma, editing_period, COMBO_END};
const uint16_t PROGMEM combo_editing_j__editing_k[] = {editing_j, editing_k, COMBO_END};
const uint16_t PROGMEM combo_editing_k__editing_l[] = {editing_k, editing_l, COMBO_END};
const uint16_t PROGMEM combo_editing_u__editing_i[] = { editing_u, editing_i, COMBO_END};
const uint16_t PROGMEM combo_editing_u__editing_o[] = { editing_u, editing_o, COMBO_END};
const uint16_t PROGMEM combo_editor_select_ampr[] = {EMACS_SEL_LOWER, EMACS_SEL_U, COMBO_END};
const uint16_t PROGMEM combo_editor_select_astr[] = {EMACS_SEL_LOWER, EMACS_SEL_I, COMBO_END};
const uint16_t PROGMEM combo_editor_select_at[] = {EMACS_SEL_LOWER, EMACS_SEL_COMMA, COMBO_END};
const uint16_t PROGMEM combo_editor_select_circ[] = {EMACS_SEL_LOWER, EMACS_SEL_L, COMBO_END};
const uint16_t PROGMEM combo_editor_select_dlr[] = {EMACS_SEL_LOWER, EMACS_SEL_J, COMBO_END};
const uint16_t PROGMEM combo_editor_select_exlm[] = {EMACS_SEL_LOWER, EMACS_SEL_M, COMBO_END};
const uint16_t PROGMEM combo_editor_select_hash[] = {EMACS_SEL_LOWER, EMACS_SEL_DOT, COMBO_END};
const uint16_t PROGMEM combo_editor_select_lprn[] = {EMACS_SEL_LOWER, EMACS_SEL_O, COMBO_END};
const uint16_t PROGMEM combo_editor_select_perc[] = {EMACS_SEL_LOWER, EMACS_SEL_K, COMBO_END};
const uint16_t PROGMEM combo_editor_select_rprn[] = {EMACS_SEL_LOWER, EMACS_SEL_P, COMBO_END};
const uint16_t PROGMEM combo_f_b[] = {my_f, my_b, COMBO_END};
const uint16_t PROGMEM combo_f_d[] = {my_f, my_d, COMBO_END};
const uint16_t PROGMEM combo_f_g[] = {my_f, my_g, COMBO_END};
const uint16_t PROGMEM combo_g_backspace[] = {my_g, backspace, COMBO_END};
const uint16_t PROGMEM combo_g_r2[] = {my_g, mod_r2, COMBO_END};
const uint16_t PROGMEM combo_g_r3[] = {my_g, mod_r3, COMBO_END};
/* const uint16_t PROGMEM combo_h_backspace[] = {my_h, backspace, COMBO_END}; */
const uint16_t PROGMEM combo_h_i[] = {my_h, my_i, COMBO_END};
const uint16_t PROGMEM combo_h_j[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_h_u[] = {my_h,  my_u, COMBO_END};
const uint16_t PROGMEM combo_i_l[] = {my_i, my_l, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = { my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_j_comma[] = {my_j, my_comma, COMBO_END};
const uint16_t PROGMEM combo_j_i[] = {my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_j_i_l[] = {my_j, my_i, my_l, COMBO_END};
const uint16_t PROGMEM combo_j_i_o[] = {my_j, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_j_k[] = {my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_j_k_l[] = {my_k, my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_j_k_l_semi[] = {my_k, my_l, my_j, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_j_k_o[] = {my_j, my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_j_l[] = { my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_j_n[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_j_o[] = {my_j,  my_o, COMBO_END};
const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END};
const uint16_t PROGMEM combo_k_l[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_k_l_semi[] = {my_k,my_semicolon, my_l, COMBO_END};
const uint16_t PROGMEM combo_k_m[] = {my_k, my_m, COMBO_END};
const uint16_t PROGMEM combo_k_o[] = {my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_k_o_semi[] = {my_k, my_o, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_k_p[] = {my_k, my_p, COMBO_END};
const uint16_t PROGMEM combo_k_semi[] = {my_k, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_l_comma[] = {my_l, my_comma, COMBO_END};
const uint16_t PROGMEM combo_l_k_semi[] = {my_l, my_k, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_l_p[] = {my_l, my_p, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semi[] = {my_l, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semi_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // {
const uint16_t PROGMEM combo_l_singlequote[] = {my_l, my_singlequote, COMBO_END};
const uint16_t PROGMEM combo_l_singlequote_semi[] = {my_l, my_singlequote, my_semicolon, COMBO_END}; // }
const uint16_t PROGMEM combo_left_right[] = {preonic_7, preonic_10, COMBO_END};
const uint16_t PROGMEM combo_left_shift_forward_slash[] = {my_left_shift, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_left_to_down[] = {my_right_of_lower, key_left, COMBO_END};
const uint16_t PROGMEM combo_lower__P[] = {LOWER, my_cap_p, COMBO_END};
const uint16_t PROGMEM combo_lower__comma[] =   {LOWER, my_comma, COMBO_END};
const uint16_t PROGMEM combo_lower__comma__l[] = {LOWER, my_comma, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__comma__period[] = {LOWER, my_comma, my_period, COMBO_END};
const uint16_t PROGMEM combo_lower__i[] = {LOWER,  my_i, COMBO_END};
const uint16_t PROGMEM combo_lower__i__o[] = {LOWER, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower__j__i[] = {LOWER, my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_lower__j__l[] = {LOWER, my_j, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__k__l[] = {LOWER, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__k__o[] = {LOWER, my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower__l[] = {LOWER, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__m__k[] = {LOWER, my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower__u[] = {LOWER, my_u, COMBO_END};
const uint16_t PROGMEM combo_lower_backspace[] =  {LOWER, my_right_of_lower, COMBO_END};
const uint16_t PROGMEM combo_lower_backspace_left[] =  {LOWER, my_right_of_lower, key_4_11, COMBO_END};
const uint16_t PROGMEM combo_lower_comma__lower_l[] = {my_lower_comma, my_lower_l, COMBO_END};
const uint16_t PROGMEM combo_lower_comma__lower_period[] = {my_lower_comma, my_lower_period, COMBO_END};
const uint16_t PROGMEM combo_lower_d__lower_f[] = {my_lower_d, my_lower_f, COMBO_END};
const uint16_t PROGMEM combo_lower_d_lower__f[] = {my_lower_d , my_lower_f, COMBO_END};
const uint16_t PROGMEM combo_lower_dot[] = {LOWER, my_period, COMBO_END};
const uint16_t PROGMEM combo_lower_i__lower_o[] = {my_lower_i, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_j[] =  {LOWER, my_j, COMBO_END};
const uint16_t PROGMEM combo_lower_j__lower_i[] = { my_lower_j, my_lower_i, COMBO_END};
const uint16_t PROGMEM combo_lower_j_k[] = {LOWER, my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_j_k_l[] = {LOWER, my_j, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower_k__lower_l[] = {my_lower_k, my_lower_l, COMBO_END};
const uint16_t PROGMEM combo_lower_k__lower_o[] = {my_lower_k, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_l__lower_semi[] = {my_lower_l,       my_lower_semi, COMBO_END};
const uint16_t PROGMEM combo_lower_l_semi[] = {LOWER, my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_lower_m[] = {LOWER, my_m, COMBO_END};
const uint16_t PROGMEM combo_lower_m__lower_comma[] = {my_lower_comma, my_lower_m, COMBO_END};
const uint16_t PROGMEM combo_lower_m__lower_k[] = {my_lower_m, my_lower_k, COMBO_END};
const uint16_t PROGMEM combo_lower_m_comma[] = {LOWER, my_m, my_comma, COMBO_END};
const uint16_t PROGMEM combo_lower_m_k[] = {LOWER, my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_m_lower_k[] = {my_lower_m, my_lower_k, COMBO_END};
const uint16_t PROGMEM combo_lower_o[] = {LOWER, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower_o_p[] = {LOWER, my_o, my_p, COMBO_END};
const uint16_t PROGMEM combo_lower_p__lower_p[] = {my_lower_p, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_perc[] = {LOWER, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_rprn[] = {LOWER, my_p, COMBO_END};
const uint16_t PROGMEM combo_lower_semi[] = {LOWER, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_lower_slash[] = {LOWER, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_lower_u_i[] = { my_lower_u, my_lower_i, COMBO_END};
const uint16_t PROGMEM combo_m_comma[] = {my_m, my_comma, COMBO_END};
const uint16_t PROGMEM combo_m_comma_period[] = {my_m, my_comma, my_period, COMBO_END};
const uint16_t PROGMEM combo_m_k[] = { my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_m_k_l[] = { my_m, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_m_l[] = { my_m, my_l, COMBO_END};
const uint16_t PROGMEM combo_m_period[] = {my_m, my_period, COMBO_END};
const uint16_t PROGMEM combo_macro_r_macro_g[] = {macros_r, macros_g, COMBO_END};
const uint16_t PROGMEM combo_mod1_y[] = {mod_r1, my_y, COMBO_END};
const uint16_t PROGMEM combo_mod1_g[] = {mod_r1, my_g, COMBO_END};
const uint16_t PROGMEM combo_mod1_y_u[] = {mod_r1, my_y, my_u, COMBO_END};
const uint16_t PROGMEM combo_mod3_h[] = {mod_r3, my_h, COMBO_END};
const uint16_t PROGMEM combo_mod_r1_mod_r4[] = {mod_r1, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_mod_r2_b[] = {mod_r2, my_b, COMBO_END};
const uint16_t PROGMEM combo_mod_r3_super[] = {mod_r3, super, COMBO_END};
const uint16_t PROGMEM combo_mouse1_mouse2[] = {KC_MS_BTN1, KC_MS_BTN2, COMBO_END};
const uint16_t PROGMEM combo_my_raise_g[] = { RAISE, my_g, COMBO_END};
const uint16_t PROGMEM combo_n_k47[] = {my_n, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_n_m[] = {my_n, my_m, COMBO_END};
const uint16_t PROGMEM combo_n_r3[] = {my_n, mod_r3, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {my_o, my_p, COMBO_END};
const uint16_t PROGMEM combo_opening_curly[] = {my_o, my_p, COMBO_END};
const uint16_t PROGMEM combo_opening_square[] = {my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_osl_extended[] = {my_j, my_l, COMBO_END};
const uint16_t PROGMEM combo_p_topright[] = {my_p, topright, COMBO_END}; // underscore
const uint16_t PROGMEM combo_p_topright_o[] = {my_p, my_o, topright, COMBO_END}; // equal
const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_period_comma_m[] = {my_period, my_m, my_comma, COMBO_END}; // {
const uint16_t PROGMEM combo_period_forward_slash[] = {my_forward_slash, my_period, COMBO_END};
const uint16_t PROGMEM combo_period_semi[] = {my_period, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_period_slash[] = {my_period, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_q_e[] = {my_q, my_e, COMBO_END};
const uint16_t PROGMEM combo_q_o[] = {my_o, my_q, COMBO_END};
const uint16_t PROGMEM combo_q_w[] = {my_q, my_w, COMBO_END};
const uint16_t PROGMEM combo_emacs_sel_q_w[] = {EMACS_SEL_1,  EMACS_SEL_2, COMBO_END};
const uint16_t PROGMEM combo_emacs_sel_d_f[] = {EMACS_SEL_D,  EMACS_SEL_F, COMBO_END};
const uint16_t PROGMEM combo_q_w_e[] = {my_q, my_w, my_e,  COMBO_END};
const uint16_t PROGMEM combo_r2_h[] = {mod_r2, my_h, COMBO_END};
const uint16_t PROGMEM combo_r4_space[] = {mod_r4, my_space, COMBO_END};
const uint16_t PROGMEM combo_r_g[] = {my_r, my_g, COMBO_END};
const uint16_t PROGMEM combo_r_o[] = {my_r, my_o, COMBO_END};
const uint16_t PROGMEM combo_r_t[] = {my_r, my_t, COMBO_END};
const uint16_t PROGMEM combo_raise_comma_raise_l[] = {my_raise_l, my_raise_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_d_f[] = {RAISE, my_d , my_f, COMBO_END};
const uint16_t PROGMEM combo_raise_d_raise_f[] = {my_raise_d, my_raise_f, COMBO_END};
const uint16_t PROGMEM combo_raise_esc_ctrl[] = {esc_ctrl, RAISE, COMBO_END};
const uint16_t PROGMEM combo_raise_f[] = {RAISE, my_f, COMBO_END};
const uint16_t PROGMEM combo_lower_q_lower_w[] = {my_lower_q, my_lower_w, COMBO_END};
const uint16_t PROGMEM combo_raise_q_raise_w[] = {my_raise_q, my_raise_w, COMBO_END};
const uint16_t PROGMEM combo_raise_h_raise_j[] = {my_raise_h, my_raise_j, COMBO_END};
const uint16_t PROGMEM combo_raise_h_raise_u[] = {my_raise_h,  my_raise_u, COMBO_END};
const uint16_t PROGMEM combo_raise_i_raise_o[] = { my_raise_i, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_i[] = {my_raise_j, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_i_raise_o[] = {my_raise_j, my_raise_i, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_k[] = {my_raise_j, my_raise_k, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_l[] = { my_raise_l, my_raise_j, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_n[] = {my_raise_j, my_raise_n, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_l[] = {my_raise_k, my_raise_l, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_o[] = {my_raise_k, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_lower_i[] = {raise_key_4_9, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_comma[] = {my_raise_m, my_raise_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_k[] = {my_raise_m, my_raise_k, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_period[] = {my_raise_m, my_raise_period, COMBO_END};
const uint16_t PROGMEM combo_raise_o_raise_p[] = {my_raise_o, my_raise_p, COMBO_END};
const uint16_t PROGMEM combo_raise_r[] = {RAISE, my_r, COMBO_END};
const uint16_t PROGMEM combo_raise_slash[] = {RAISE, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_raise_u_raise_i[] = { my_raise_u, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_raise_u_raise_o[] = { my_raise_u, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_w_raise_e[] = {my_raise_w, my_raise_e, COMBO_END};
const uint16_t PROGMEM combo_right__lower_j_i[] = {raise_key_4_9, my_raise_j, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_right_to_up[] = {key_left, key_right, COMBO_END};
const uint16_t PROGMEM combo_right_zero[] = {preonic_10, preonic_11, COMBO_END};
const uint16_t PROGMEM combo_rofi_run_modal[] = {my_s,  my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END};
const uint16_t PROGMEM combo_s_c[] = {my_s, my_c, COMBO_END};
const uint16_t PROGMEM combo_s_d[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_s_d_f[] = {my_s, my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_s_e[] = {my_s, my_e, COMBO_END};
const uint16_t PROGMEM combo_s_f[] = {my_s, my_f, COMBO_END};

const uint16_t PROGMEM combo_select_grave[] = {EMACS_SEL_COMMA, EMACS_SEL_L, COMBO_END};
const uint16_t PROGMEM combo_semi_singlequote[] = {my_semicolon, my_singlequote, COMBO_END}; // ]
const uint16_t PROGMEM combo_shift_alt[] = {LOWER, my_left_shift, KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_d_shiftlock_f[] = {my_cap_d, my_cap_f, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_ampr[] = {LOWER, my_cap_u, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_astr[] = {LOWER,  my_cap_i, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_at[] =   {LOWER, my_cap_comma, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_circ[] = {LOWER, my_cap_l, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_dlr[] =  {LOWER, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_exlm[] = {LOWER, my_cap_m, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_hash[] = {LOWER, my_cap_period, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_lprn[] = {LOWER, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_perc[] = {LOWER, my_cap_k, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_rprn[] = {LOWER, my_cap_p, COMBO_END};
const uint16_t PROGMEM combo_singlequote_semi[] = {my_semicolon, my_singlequote, COMBO_END};
const uint16_t PROGMEM combo_six_left[] = {preonic_6, preonic_7, COMBO_END};
const uint16_t PROGMEM combo_slack_show_desktop[] = {show_desktop, select_slack, COMBO_END};
const uint16_t PROGMEM combo_space_comma[] =   {my_space, my_comma, COMBO_END};
const uint16_t PROGMEM combo_space_dot[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_space_forward_slash[] = {my_forward_slash, my_space, COMBO_END}; // ]
const uint16_t PROGMEM combo_space_h[] = {my_space, my_h, COMBO_END};
const uint16_t PROGMEM combo_space_i[] = {my_space,  my_i, COMBO_END};
const uint16_t PROGMEM combo_space_j[] = {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_space_j_k[] = {my_space, my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_space_k[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_space_l[] = {my_space, my_l, COMBO_END};
const uint16_t PROGMEM combo_space_lprn[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_space_m[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_space_m_k[] = {my_space, my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_space_n[] = {my_space, my_n, COMBO_END};
const uint16_t PROGMEM combo_space_o[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_space_period[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_space_r2[] = {my_space, mod_r2, COMBO_END};
const uint16_t PROGMEM combo_space_semi[] = {my_space, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_space_u[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_super_f__super_b[] = {super_f, super_b, COMBO_END};
const uint16_t PROGMEM combo_super_g__super_r3[] = {super_g, super_mod_r3, COMBO_END};
const uint16_t PROGMEM combo_super_r4[] = {super, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_super_r__super_g[] = {super_r, super_g, COMBO_END};
const uint16_t PROGMEM combo_super_space[] = {super, my_space, COMBO_END};
const uint16_t PROGMEM combo_super_space_r4[] = {mod_r4, super, my_space, COMBO_END};
const uint16_t PROGMEM combo_super_t[] = {super, my_t, COMBO_END};
const uint16_t PROGMEM combo_t_r3[] = {my_t, mod_r3, COMBO_END};
const uint16_t PROGMEM combo_t_y[] = {my_y, my_t, COMBO_END};
const uint16_t PROGMEM combo_tab_q[] = {top_left, my_q, COMBO_END};
const uint16_t PROGMEM combo_tab_a[] = {top_left, my_a, COMBO_END};
const uint16_t PROGMEM combo_tab_esc[] = {top_left, esc_ctrl, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {my_u, my_i, COMBO_END};
const uint16_t PROGMEM combo_u_i_o[] = {my_u, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_u_k[] = {my_k, my_u, COMBO_END};
const uint16_t PROGMEM combo_u_o[] = {my_u, my_o, COMBO_END};
const uint16_t PROGMEM combo_w_d[] = {my_w, my_d, COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {my_w, my_e, COMBO_END};
const uint16_t PROGMEM combo_w_e_r[] = {my_w, my_e, my_r, COMBO_END};
const uint16_t PROGMEM combo_w_f[] = {my_w, my_f, COMBO_END};
const uint16_t PROGMEM combo_w_r[] = {my_w, my_r, COMBO_END};
const uint16_t PROGMEM combo_x_c[] = {my_x, my_c, COMBO_END};
const uint16_t PROGMEM combo_x_v[] = {my_x, my_v, COMBO_END};
const uint16_t PROGMEM combo_y_backspace[] = {backspace, my_y, COMBO_END};
const uint16_t PROGMEM combo_y_u[] = {my_y, my_u, COMBO_END};
const uint16_t PROGMEM combo_z_x[] = {my_z, my_x, COMBO_END};
const uint16_t PROGMEM combo_z_x_c[] = {my_z, my_x, my_c, COMBO_END};
const uint16_t PROGMEM cycle_animations[] = {level3,   alt_keyboard,  COMBO_END};
const uint16_t PROGMEM editing_comma__editing_dot[] = {editing_comma, editing_period, COMBO_END};
const uint16_t PROGMEM morph_ation[] = {my_t, my_n,  COMBO_END};
const uint16_t PROGMEM morph_less[] = {my_s,  my_l,  COMBO_END};
const uint16_t PROGMEM morph_ment[] = {my_m,  my_t,  COMBO_END};
const uint16_t PROGMEM morph_ness[] = {my_s,  my_n,  COMBO_END};
const uint16_t PROGMEM preonic_a_c[] = {preonic_lalt,  preonic_rctl,  COMBO_END};
const uint16_t PROGMEM preonic_h_a[] = {preonic_lctl,  preonic_lalt,  COMBO_END};
const uint16_t PROGMEM preonic_h_a_c[] = {preonic_lctl,  preonic_lalt, preonic_rctl,  COMBO_END};
const uint16_t PROGMEM preonic_h_c[] = {preonic_lctl,  preonic_rctl,  COMBO_END};
const uint16_t PROGMEM raise_comma__raise_dot[] = {my_raise_comma,  my_raise_period, COMBO_END};
const uint16_t PROGMEM super_e[] = {super,   my_e,  COMBO_END};
const uint16_t PROGMEM super_t[] = {super,   my_t,  COMBO_END};
const uint16_t PROGMEM word_because[] = {my_b, my_c,  COMBO_END};
