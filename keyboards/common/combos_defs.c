/* #include "muse.h" */


#include QMK_KEYBOARD_H


const uint16_t PROGMEM combo_mouse1_mouse2[] = {KC_MS_BTN1, KC_MS_BTN2, COMBO_END};
const uint16_t PROGMEM combo_super_r_super_g[] = {super_r, super_g, COMBO_END};

const uint16_t PROGMEM combo_macro_r_macro_g[] = {macros_r, macros_g, COMBO_END};

const uint16_t PROGMEM combo_editing_equal[] = {editing_comma, editing_period, COMBO_END};
const uint16_t PROGMEM combo_a_s_k[] = {my_a, my_s, my_k, COMBO_END};
const uint16_t PROGMEM combo_r_o[] = {my_r, my_o, COMBO_END};

const uint16_t PROGMEM combo_LOWER_SHIFTP[] = {LOWER, my_cap_p, COMBO_END};
const uint16_t PROGMEM combo_k42_k43[] = {alt_keyboard, level3, COMBO_END};
const uint16_t PROGMEM combo_top_left_hyper[] = {top_left, hyper, COMBO_END};
const uint16_t PROGMEM combo_top_left_my_q[] = {top_left, my_q, COMBO_END};
const uint16_t PROGMEM combo_period_slash[] = {my_period, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_super_t[] = {super, my_t, COMBO_END};


const uint16_t PROGMEM combo_mod_r1_mod_r4[] = {mod_r1, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_super_k47[] = {super, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_k47_space[] = {mod_r4, my_space, COMBO_END};
const uint16_t PROGMEM combo_super_space_k47[] = {mod_r4, super, my_space, COMBO_END};
const uint16_t PROGMEM combo_super_space[] = {super, my_space, COMBO_END};
const uint16_t PROGMEM combo_n_k47[] = {my_n, mod_r4, COMBO_END};

const uint16_t PROGMEM combo_mod_r2_b[] = {mod_r2, my_b, COMBO_END};
const uint16_t PROGMEM combo_mod_r3_super[] = {mod_r3, super, COMBO_END};



const uint16_t PROGMEM combo_space_m[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_space_u[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_space_i[] = {my_space, my_i, COMBO_END};
const uint16_t PROGMEM combo_space_o[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_space_period[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_space_j_k[] = {my_space, my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_space_j[] = {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_space_k[] = {my_space, my_k, COMBO_END};

const uint16_t PROGMEM combo_space_h[] = {my_space, my_h, COMBO_END};

const uint16_t PROGMEM combo_x_c[] = {my_x, my_c, COMBO_END};
const uint16_t PROGMEM combo_raise_f[] = {RAISE, my_f, COMBO_END};
const uint16_t PROGMEM combo_raise_r[] = {RAISE, my_r, COMBO_END};
const uint16_t PROGMEM combo_bottom_top_mid_column[] = {top_alpha_mid_column, mod_r4, COMBO_END};
const uint16_t PROGMEM combo_s_a[] = {my_a, my_s, COMBO_END};
/* const uint16_t PROGMEM combo_lower_bottom_right_2[] = {lower_key_4_11, lower_key_4_12, COMBO_END}; */
/* const uint16_t PROGMEM combo_raise_lower_i[] = {raise_key_4_9, my_raise_i, COMBO_END}; */

const uint16_t PROGMEM combo_q_w[] = {my_q, my_w, COMBO_END};


const uint16_t PROGMEM combo_lower_l_semi[] = {my_lower_l,       my_lower_semi, COMBO_END};
const uint16_t PROGMEM combo_period_semicolon[] = {my_period, my_semicolon, COMBO_END};

const uint16_t PROGMEM combo_backspace_g[] = {my_g, backspace, COMBO_END};
const uint16_t PROGMEM combo_backspace_h[] = {my_h, backspace, COMBO_END};

/* const uint16_t PROGMEM combo_lower_slash[] = {LOWER, my_forward_slash, COMBO_END}; */
/* const uint16_t PROGMEM combo_raise_slash[] = {RAISE, my_forward_slash, COMBO_END}; */
const uint16_t PROGMEM combo_raise_d_f[] = {RAISE, my_d , my_f, COMBO_END};
const uint16_t PROGMEM combo__lower_d_f[] = {my_lower_d , my_lower_f, COMBO_END};

/* const uint16_t PROGMEM combo_space_n[] = {my_space, my_n, COMBO_END}; */
const uint16_t PROGMEM combo_3_7__2_8[] = {mod_r3, my_h, COMBO_END};

/* const uint16_t PROGMEM combo_space_lprn[] = {my_space, my_o, COMBO_END}; */
/* const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END}; */
/* const uint16_t PROGMEM combo_exlm[] = {my_space, my_m, COMBO_END}; */
/* const uint16_t PROGMEM combo_at[] =   {my_space, my_comma, COMBO_END}; */
/* const uint16_t PROGMEM combo_hash[] = {my_space, my_period, COMBO_END}; */
/* const uint16_t PROGMEM combo_dlr[] =  {my_space, my_j, COMBO_END}; */
/* const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END}; */
/* const uint16_t PROGMEM combo_circ[] = {my_space, my_l, COMBO_END}; */
/* const uint16_t PROGMEM combo_ampr[] = {my_space, my_u, COMBO_END}; */
/* const uint16_t PROGMEM combo_astr[] = {my_space,  my_i, COMBO_END}; */
/* const uint16_t PROGMEM combo_osl_extended[] = {my_j, my_l, COMBO_END}; */
/* const uint16_t PROGMEM combo_rofi_run_modal[] = {my_s,  my_d, my_f, COMBO_END}; */

const uint16_t PROGMEM combo_shiftlock_lower_lprn[] = {LOWER, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_rprn[] = {LOWER, my_cap_p, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_exlm[] = {LOWER, my_cap_m, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_at[] =   {LOWER, my_cap_comma, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_hash[] = {LOWER, my_cap_period, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_dlr[] =  {LOWER, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_perc[] = {LOWER, my_cap_k, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_circ[] = {LOWER, my_cap_l, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_ampr[] = {LOWER, my_cap_u, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_lower_astr[] = {LOWER,  my_cap_i, COMBO_END};

const uint16_t PROGMEM combo_z_x[] = {my_z, my_x, COMBO_END};

const uint16_t PROGMEM combo_lower_lprn[] = {LOWER, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower_rprn[] = {LOWER, my_p, COMBO_END};
const uint16_t PROGMEM combo_lower_exlm[] = {LOWER, my_m, COMBO_END};
const uint16_t PROGMEM combo_lower_at[] =   {LOWER, my_comma, COMBO_END};
const uint16_t PROGMEM combo_lower_hash[] = {LOWER, my_period, COMBO_END};
const uint16_t PROGMEM combo_lower_dlr[] =  {LOWER, my_j, COMBO_END};
const uint16_t PROGMEM combo_lower_perc[] = {LOWER, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_circ[] = {LOWER, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower_ampr[] = {LOWER, my_u, COMBO_END};
const uint16_t PROGMEM combo_lower_astr[] = {LOWER,  my_i, COMBO_END};
const uint16_t PROGMEM raise_comma_raise_period[] = {my_raise_comma,  my_raise_period, COMBO_END};
const uint16_t PROGMEM editing_comma_editing_period[] = {editing_comma, editing_period, COMBO_END};


/* const uint16_t PROGMEM combo_raise_h_raise_u[] = {my_raise_h,  my_raise_u, COMBO_END}; */
const uint16_t PROGMEM combo_h_u[] = {my_h,  my_u, COMBO_END};


const uint16_t PROGMEM combo_cap_j_cap_i[] = {my_cap_j, my_cap_i, COMBO_END};
const uint16_t PROGMEM combo_cap_k_cap_o[] = {my_cap_k, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_cap_m_cap_k[] = {my_cap_m, my_cap_k, COMBO_END};

const uint16_t PROGMEM combo_winmove_up_right[] = {winmove_U, winmove_R, COMBO_END};
/* const uint16_t PROGMEM combo_spc_q[] = {my_q, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_w[] = {my_w, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_e[] = {my_e, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_t[] = {my_t, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_a[] = {my_a, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_s[] = {my_s, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_z[] = {my_z, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_x[] = {my_x, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_c[] = {my_c, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_n[] = {my_n, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_p[] = {my_p, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_u[] = {my_u, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_i[] = {my_i, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_o[] = {my_o, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_spc_grave[] = {my_grave, my_space, COMBO_END}; */

/* const uint16_t PROGMEM combo_y_u[] = {my_y, my_u, COMBO_END}; */

/* const uint16_t PROGMEM combo_spc_topright[] = {topright, my_space, COMBO_END}; */


/* const uint16_t PROGMEM combo_u_k[] = {my_k, my_u, COMBO_END}; */
/* const uint16_t PROGMEM combo_i_l[] = {my_i, my_l, COMBO_END}; */
/* const uint16_t PROGMEM combo_j_comma[] = {my_j, my_comma, COMBO_END}; */

/* const uint16_t PROGMEM combo_c_v[] = {my_c, my_v, COMBO_END}; */


const uint16_t PROGMEM combo_s_c[] = {my_s, my_c, COMBO_END};
const uint16_t PROGMEM combo_shiftlock_d_shiftlock_f[] = {my_cap_d, my_cap_f, COMBO_END};
const uint16_t PROGMEM combo_e_f[] = {my_e, my_f, COMBO_END};

const uint16_t PROGMEM combo_j_k[] = {my_j, my_k, COMBO_END};

const uint16_t PROGMEM combo_super__f_b[] = {super_f, super_b, COMBO_END};
const uint16_t PROGMEM combo_super__g_r3[] = {super_g, super_mod_r3, COMBO_END};
const uint16_t PROGMEM combo_f_b[] = {my_f, my_b, COMBO_END};
const uint16_t PROGMEM combo_g_r3[] = {my_g, mod_r3, COMBO_END};
const uint16_t PROGMEM combo_s_d[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_s_d_f[] = {my_s, my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_s_f[] = {my_s, my_f, COMBO_END};

/* const uint16_t PROGMEM combo_f_d[] = {my_f, my_d, COMBO_END}; */
const uint16_t PROGMEM combo_f_g[] = {my_f, my_g, COMBO_END};
const uint16_t PROGMEM combo_editing_k_editing_l[] = {editing_k, editing_l, COMBO_END};

const uint16_t PROGMEM combo_k49_k410[] =  {LOWER, my_right_of_lower, COMBO_END};
const uint16_t PROGMEM combo_k49_k410_k11[] =  {LOWER, my_right_of_lower, key_4_11, COMBO_END};


const uint16_t PROGMEM combo_k_o[] = {my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_k_o_semicolon[] = {my_k, my_o, my_semicolon, COMBO_END};
/* const uint16_t PROGMEM combo_j_i_l[] = {my_j, my_i, my_l, COMBO_END}; */

const uint16_t PROGMEM combo_k_l[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_K_L[] = {my_cap_k, my_cap_l, COMBO_END};
const uint16_t PROGMEM combo_M_cap_semi[] = {my_cap_m, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_windows_k_l[] = {windows_k, windows_l, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_l[] = {my_raise_k, my_raise_l, COMBO_END};


const uint16_t PROGMEM combo_h_j[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_H_J[] = {my_cap_h, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_K[] = {my_cap_k, my_cap_j, COMBO_END};
/* const uint16_t PROGMEM combo_spc_h[] = {my_h, my_space, COMBO_END}; */
/* const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END}; */
const uint16_t PROGMEM combo_j_i[] = {my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_j_i_o[] = {my_j, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_cap_j_cap_i_cap_o[] = {my_cap_j, my_cap_i, my_cap_o, COMBO_END};


const uint16_t PROGMEM combo_i_o[] = { my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_raise_i_raise_o[] = { my_raise_i, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_my_raise_g[] = { RAISE, my_g, COMBO_END};
/* const uint16_t PROGMEM combo_k_m[] = {my_k, my_m, COMBO_END}; */

const uint16_t PROGMEM combo_j_n[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_n[] = {my_raise_j, my_raise_n, COMBO_END};

/* const uint16_t PROGMEM combo_w_l[] = {my_w, my_l, COMBO_END}; */
/* const uint16_t PROGMEM combo_w_h[] = {my_w, my_h, COMBO_END}; */
const uint16_t PROGMEM combo_w_e_r[] = {my_w, my_e, my_r, COMBO_END};
const uint16_t PROGMEM combo_q_w_e[] = {my_q, my_w, my_e,  COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {my_w, my_e, COMBO_END};

const uint16_t PROGMEM combo_1_7_y[] = {mod_r1, my_y, COMBO_END};
const uint16_t PROGMEM combo_1_7_y_u[] = {mod_r1, my_y, my_u, COMBO_END};


/* const uint16_t PROGMEM combo_hyper_clear[] = {my_k,my_semicolon, my_l, COMBO_END}; */
const uint16_t PROGMEM combo_left_shift_forward_slash[] = {my_left_shift, my_forward_slash, COMBO_END};

/* const uint16_t PROGMEM combo_opening_square[] = {my_l, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_closing_square[] = {my_singlequote, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_opening_curly[] = {my_o, my_p, COMBO_END}; */

const uint16_t PROGMEM combo_l_semicolon[] = {my_l, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_l_k_semicolon[] = {my_l, my_k, my_semicolon, COMBO_END}; // [

const uint16_t PROGMEM combo_l_p[] = {my_l, my_p, COMBO_END}; // [
/* const uint16_t PROGMEM combo_comma_m[] = {my_m, my_comma, COMBO_END}; // [ */
/* const uint16_t PROGMEM combo_l_semicolon_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // { */
/* const uint16_t PROGMEM combo_period_comma_m[] = {my_period, my_m, my_comma, COMBO_END}; // { */

/* const uint16_t PROGMEM combo_j_singlequote[] = {my_j, my_singlequote, COMBO_END}; */

const uint16_t PROGMEM combo_comma_l[] = {my_l, my_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_comma_raise_l[] = {my_raise_l, my_raise_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_comma[] = {my_raise_m, my_raise_comma, COMBO_END};

/* const uint16_t PROGMEM combo_lower_comma_lower_l[] = {my_lower_l, my_lower_comma, COMBO_END}; */

/* const uint16_t PROGMEM combo_comma_semicolon[] = {my_semicolon, my_comma, COMBO_END}; */

/* const uint16_t PROGMEM combo_semicolon_singlequote[] = {my_semicolon, my_singlequote, COMBO_END}; // ] */
/* const uint16_t PROGMEM combo_l_singlequote_semicolon[] = {my_l, my_singlequote, my_semicolon, COMBO_END}; // } */
/* const uint16_t PROGMEM combo_comma_period_forward_slash[] = {my_forward_slash, my_comma, my_period, COMBO_END}; // ] */

/* const uint16_t PROGMEM combo_space_forward_slash[] = {my_forward_slash, my_space, COMBO_END}; // ] */
/* const uint16_t PROGMEM combo_period_forward_slash[] = {my_forward_slash, my_period, COMBO_END}; */

/* const uint16_t PROGMEM combo_p_topright[] = {my_p, topright, COMBO_END}; // underscore */
/* const uint16_t PROGMEM combo_p_topright_o[] = {my_p, my_o, topright, COMBO_END}; // equal */

/* const uint16_t PROGMEM combo_lower_right_of_lower[] = {LOWER, right_of_lower, COMBO_END}; */

const uint16_t PROGMEM combo_j_l[] = { my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_l[] = { my_raise_l, my_raise_j, COMBO_END};
const uint16_t PROGMEM combo_raise_u_raise_i[] = { my_raise_u, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_raise_u_raise_o[] = { my_raise_u, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_editing_u_editing_i[] = { editing_u, editing_i, COMBO_END};
const uint16_t PROGMEM combo_editing_u_editing_o[] = { editing_u, editing_o, COMBO_END};
const uint16_t PROGMEM combo_m_k[] = { my_m, my_k, COMBO_END};
/* const uint16_t PROGMEM combo_m_k_l[] = { my_m, my_k, my_l, COMBO_END}; */
const uint16_t PROGMEM combo_m_l[] = { my_m, my_l, COMBO_END};
const uint16_t PROGMEM combo_j_k_l[] = {my_k, my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_j_k_l_semi[] = {my_k, my_l, my_j, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_J_K_L[] = {my_cap_k, my_cap_l, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_K_L_SEMI[] = {my_cap_k, my_cap_l, my_cap_j, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_k_l_semi[] = {my_k, my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_K_L_SEMI[] = {my_cap_k, my_cap_l, my_cap_semi, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {my_u, my_i, COMBO_END};

const uint16_t PROGMEM combo_4_11_4_12[] = {key_4_11, key_4_12, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_12[] = {my_right_of_lower, key_4_12, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_11[] = {my_right_of_lower, key_4_11, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_11_4_12[] = {my_right_of_lower, key_4_11, key_4_12, COMBO_END};


const uint16_t PROGMEM combo_left_to_down[] = {my_right_of_lower, key_left, COMBO_END};
const uint16_t PROGMEM combo_right_to_up[] = {key_left, key_right, COMBO_END};


const uint16_t PROGMEM combo_u_o[] = {my_u, my_o, COMBO_END};
/* const uint16_t PROGMEM combo_u_i_o[] = {my_u, my_i, my_o, COMBO_END}; */
const uint16_t PROGMEM combo_m_period[] = {my_m, my_period, COMBO_END};
/* const uint16_t PROGMEM combo_raise_m_raise_period[] = {my_raise_m, my_raise_period, COMBO_END}; */

const uint16_t PROGMEM combo_j_o[] = {my_j,  my_o, COMBO_END};
const uint16_t PROGMEM combo_cap_j_cap_o[] = {my_cap_j,  my_cap_o, COMBO_END};
/* const uint16_t PROGMEM combo_j_k_o[] = {my_j, my_k, my_o, COMBO_END}; */
/* const uint16_t PROGMEM combo_k_p[] = {my_k, my_p, COMBO_END}; */
/* const uint16_t PROGMEM combo_w_r[] = {my_w, my_r, COMBO_END}; */
/* const uint16_t PROGMEM combo_x_v[] = {my_x, my_v, COMBO_END}; */
/* const uint16_t PROGMEM combo_q_e[] = {my_q, my_e, COMBO_END}; */
/* const uint16_t PROGMEM combo_w_f[] = {my_w, my_f, COMBO_END}; */
/* const uint16_t PROGMEM combo_s_e[] = {my_s, my_e, COMBO_END}; */


const uint16_t PROGMEM combo_grave_q[] = {my_grave, my_q, COMBO_END};
const uint16_t PROGMEM combo_e_t[] = {my_e, my_t, COMBO_END};
/* const uint16_t PROGMEM combo_grave_topright[] = {my_grave, topright, COMBO_END}; */
/* const uint16_t PROGMEM combo_grave_p[] = {my_grave, my_p, COMBO_END}; */
const uint16_t PROGMEM combo_k_semicolon[] = {my_k, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_K_cap_semicolon[] = {my_cap_k, my_cap_semi, COMBO_END};
/* const uint16_t PROGMEM combo_space_semicolon[] = {my_space, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_space_singlequote[] = {my_space, my_singlequote, COMBO_END}; */
/* const uint16_t PROGMEM combo_l_singlequote[] = {my_l, my_singlequote, COMBO_END}; */


/* const uint16_t PROGMEM combo_singlequote_semicolon[] = {my_semicolon, my_singlequote, COMBO_END}; */

/* const uint16_t PROGMEM combo_h_i[] = {my_h, my_i, COMBO_END}; */

const uint16_t PROGMEM combo_o_p[] = {my_o, my_p, COMBO_END};
/* const uint16_t PROGMEM combo_raise_o_raise_p[] = {my_raise_o, my_raise_p, COMBO_END}; */

const uint16_t PROGMEM combo_comma_period[] = {my_comma, my_period, COMBO_END};
const uint16_t PROGMEM combo_m_comma_period[] = {my_m, my_comma, my_period, COMBO_END};


/* const uint16_t PROGMEM combo_m_comma_period[] = {my_m, my_period, my_comma, COMBO_END}; */
const uint16_t PROGMEM combo_m_comma[] = {my_m, my_comma, COMBO_END};

/* const uint16_t PROGMEM i_love_bootz[] = {my_i, my_l, COMBO_END}; */

const uint16_t PROGMEM combo_v_d[] = {my_v, my_d, COMBO_END};
const uint16_t PROGMEM combo_v_c[] = {my_v, my_c, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_raise_d_raise_f[] = {my_raise_d, my_raise_f, COMBO_END};



/* const uint16_t PROGMEM combo_topright_l[] = {topright, my_l, COMBO_END}; */
/* const uint16_t PROGMEM combo_topright_p_l[] = {topright, my_l, my_p, COMBO_END}; */

/* const uint16_t PROGMEM combo_forward_slash_right_shift[] = {my_forward_slash, my_right_shift, COMBO_END}; */

const uint16_t PROGMEM combo_slack_show_desktop[] = {show_desktop, select_slack, COMBO_END};

// + : lower+;
const uint16_t PROGMEM combo_lower_semicolon[] = {LOWER, my_semicolon, COMBO_END};

/* #ifdef PREONIC_BUILD */
const uint16_t PROGMEM combo_up_left[] = {preonic_9, preonic_7, COMBO_END};
const uint16_t PROGMEM combo_up_right[] = {preonic_9, preonic_10, COMBO_END};
const uint16_t PROGMEM combo_down_left[] = {preonic_8, preonic_7, COMBO_END};
const uint16_t PROGMEM combo_down_right[] = {preonic_8, preonic_10, COMBO_END};
const uint16_t PROGMEM combo_six_left[] = {preonic_6, preonic_7, COMBO_END};
const uint16_t PROGMEM combo_right_zero[] = {preonic_10, preonic_11, COMBO_END};
const uint16_t PROGMEM combo_up_down[] = {preonic_8, preonic_9, COMBO_END};
const uint16_t PROGMEM combo_left_right[] = {preonic_7, preonic_10, COMBO_END};

/* #endif */


const uint16_t PROGMEM combo_w_d[] = {my_w, my_d, COMBO_END};
const uint16_t PROGMEM combo_r_g[] = {my_r, my_g, COMBO_END};
const uint16_t PROGMEM combo_e_r[] = {my_e, my_r, COMBO_END};

const uint16_t PROGMEM combo_y_i[] = {my_y, my_i, COMBO_END};
const uint16_t PROGMEM combo_d_i[] = {my_d, my_i, COMBO_END};
const uint16_t PROGMEM combo_y_t[] = {my_y, my_t, COMBO_END};
const uint16_t PROGMEM combo_d_t[] = {my_d, my_t, COMBO_END};


const uint16_t PROGMEM combo_right__lower_j_i[] = {raise_key_4_9, my_raise_j, my_raise_i, COMBO_END};

const uint16_t PROGMEM combo_raise_j_raise_i[] = {my_raise_j, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_i_raise_o[] = {my_raise_j, my_raise_i, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_lower__j_i[] = {LOWER, my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_lower__j_l[] = {LOWER, my_j, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower_j_i[] = { my_lower_j, my_lower_i, COMBO_END};
const uint16_t PROGMEM combo_lower_u_i[] = { my_lower_u, my_lower_i, COMBO_END};
/* const uint16_t PROGMEM combo_lower__k_o[] = {LOWER, my_k, my_o, COMBO_END}; */
/* const uint16_t PROGMEM combo_lower_k_o[] = {my_lower_k, my_lower_o, COMBO_END}; */
const uint16_t PROGMEM combo_lower_o_p[] = {my_lower_p, my_lower_o, COMBO_END};
/* const uint16_t PROGMEM combo_lower__m_k[] = {LOWER, my_m, my_k, COMBO_END}; */
/* const uint16_t PROGMEM combo_lower_m_k[] = {my_lower_m, my_lower_k, COMBO_END}; */
const uint16_t PROGMEM combo_lower__i_o[] = {LOWER, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower__k_l[] = {LOWER, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__comma_period[] = {LOWER, my_comma, my_period, COMBO_END};
/* const uint16_t PROGMEM combo_lower_i_o[] = {my_lower_i, my_lower_o, COMBO_END}; */
const uint16_t PROGMEM combo_lower_k_lower_l[] = {my_lower_k, my_lower_l, COMBO_END};

const uint16_t PROGMEM combo_lower_comma_l[] = {my_lower_comma, my_lower_l, COMBO_END};
const uint16_t PROGMEM combo_lower_m_lower_comma[] = {my_lower_comma, my_lower_m, COMBO_END};
const uint16_t PROGMEM combo_lower_comma_lower_period[] = {my_lower_comma, my_lower_period, COMBO_END};
const uint16_t PROGMEM combo_lower__comma_l[] = {LOWER, my_comma, my_l, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_o[] = {my_raise_k, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_k[] = {my_raise_m, my_raise_k, COMBO_END};

/* const uint16_t PROGMEM combo_lower_k_lower_o[] = {my_lower_k, my_lower_o, COMBO_END}; */
/* const uint16_t PROGMEM combo_lower_m_lower_k[] = {my_lower_m, my_lower_k, COMBO_END}; */
/* const uint16_t PROGMEM combo_lower_k_lower_l[] = {my_lower_k, my_lower_l, COMBO_END}; */

const uint16_t PROGMEM combo_lower_d_lower_f[] = {my_lower_d, my_lower_f, COMBO_END};

/* const uint16_t PROGMEM combo_raise_esc_ctrl[] = {esc_ctrl, RAISE, COMBO_END}; */

/* const uint16_t PROGMEM combo_q_o[] = {my_o, my_q, COMBO_END}; */

const uint16_t PROGMEM combo_raise_h_raise_j[] = {my_raise_h, my_raise_j, COMBO_END};


const uint16_t PROGMEM combo_LOWER_o_p[] = {LOWER, my_o, my_p, COMBO_END};
/* const uint16_t PROGMEM combo_LOWER_m_comma[] = {LOWER, my_m, my_comma, COMBO_END}; */

/* const uint16_t PROGMEM combo_LOWER_l_semi[] = {LOWER, my_l, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_LOWER_period_slash[] = {LOWER, my_forward_slash, my_period, COMBO_END}; */
const uint16_t PROGMEM combo_r_t[] = {my_r, my_t, COMBO_END};
const uint16_t PROGMEM combo_LOWER_lower_lower_period_lower_slash[] = {lower_LOWER, my_lower_period, my_lower_slash, COMBO_END};


const uint16_t PROGMEM combo_super_tab_backtab[] = {super_tab, super_backtab, COMBO_END};

/* const uint16_t PROGMEM combo_shift_alt[] = {LOWER, my_left_shift, KC_LALT, COMBO_END}; */
/* const uint16_t PROGMEM combo_hyper_slash[] = {LOWER, right_of_lower, my_forward_slash, COMBO_END}; */
const uint16_t PROGMEM combo_lower_j_k_l[] = {LOWER, my_j, my_k, my_l, COMBO_END};

const uint16_t PROGMEM combo_editing_j_editing_k[] = {editing_j, editing_k, COMBO_END};

const uint16_t PROGMEM combo_backspace_y[] = {backspace, my_y, COMBO_END};

const uint16_t PROGMEM combo_lower_j_k[] = {LOWER, my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_m_k[] = {LOWER, my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_space_m_k[] = {my_space, my_m, my_k, COMBO_END};

const uint16_t PROGMEM combo_raise_j_raise_k[] = {my_raise_j, my_raise_k, COMBO_END};
