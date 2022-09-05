/* #include "muse.h" */


#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_lower_bottom_right_2[] = {lower_key_4_11, lower_key_4_12, COMBO_END};
const uint16_t PROGMEM combo_raise_lower_i[] = {raise_key_4_9, my_raise_i, COMBO_END};

const uint16_t PROGMEM combo_period_semicolon[] = {my_period, my_semicolon, COMBO_END};

const uint16_t PROGMEM combo_lower_slash[] = {LOWER, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_raise_slash[] = {RAISE, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_raise_d_f[] = {RAISE, my_d , my_f, COMBO_END};

const uint16_t PROGMEM combo_space_n[] = {my_space, my_n, COMBO_END};

const uint16_t PROGMEM combo_space_lprn[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_at[] =   {my_space, my_comma, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_dlr[] =  {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_circ[] = {my_space, my_l, COMBO_END};
const uint16_t PROGMEM combo_ampr[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_astr[] = {my_space,  my_i, COMBO_END};
const uint16_t PROGMEM combo_osl_extended[] = {my_j, my_l, COMBO_END};
const uint16_t PROGMEM combo_rofi_run_modal[] = {my_s,  my_d, my_f, COMBO_END};

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

const uint16_t PROGMEM combo_raise_f[] = {RAISE,  my_f, COMBO_END};
const uint16_t PROGMEM combo_raise_h_raise_u[] = {my_raise_h,  my_raise_u, COMBO_END};
const uint16_t PROGMEM combo_h_u[] = {my_h,  my_u, COMBO_END};


const uint16_t PROGMEM combo_cap_j_cap_i[] = {my_cap_j, my_cap_i, COMBO_END};
const uint16_t PROGMEM combo_cap_k_cap_o[] = {my_cap_k, my_cap_o, COMBO_END};
const uint16_t PROGMEM combo_cap_m_cap_k[] = {my_cap_m, my_cap_k, COMBO_END};

const uint16_t PROGMEM combo_spc_q[] = {my_q, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_w[] = {my_w, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_e[] = {my_e, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_t[] = {my_t, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_a[] = {my_a, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_s[] = {my_s, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_z[] = {my_z, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_x[] = {my_x, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_c[] = {my_c, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_n[] = {my_n, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_p[] = {my_p, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_u[] = {my_u, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_i[] = {my_i, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_o[] = {my_o, my_space, COMBO_END};
const uint16_t PROGMEM combo_spc_grave[] = {my_grave, my_space, COMBO_END};

const uint16_t PROGMEM combo_y_u[] = {my_y, my_u, COMBO_END};

const uint16_t PROGMEM combo_spc_topright[] = {topright, my_space, COMBO_END};


const uint16_t PROGMEM combo_u_k[] = {my_k, my_u, COMBO_END};
const uint16_t PROGMEM combo_i_l[] = {my_i, my_l, COMBO_END};
const uint16_t PROGMEM combo_j_comma[] = {my_j, my_comma, COMBO_END};

const uint16_t PROGMEM combo_c_v[] = {my_c, my_v, COMBO_END};


const uint16_t PROGMEM combo_windows_tab_q[] = {ALT_TAB, WINDOWS_Q, COMBO_END};


const uint16_t PROGMEM combo_e_f[] = {my_e, my_f, COMBO_END};
const uint16_t PROGMEM combo_j_k[] = {my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_k[] = {my_raise_j, my_raise_k, COMBO_END};

const uint16_t PROGMEM combo_s_d[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_f_d[] = {my_f, my_d, COMBO_END};
const uint16_t PROGMEM combo_f_g[] = {my_f, my_g, COMBO_END};
const uint16_t PROGMEM combo_editing_k_editing_l[] = {editing_k, editing_l, COMBO_END};


const uint16_t PROGMEM combo_k_o[] = {my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_j_i_l[] = {my_j, my_i, my_l, COMBO_END};

const uint16_t PROGMEM combo_k_l[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_K_L[] = {my_cap_k, my_cap_l, COMBO_END};
const uint16_t PROGMEM combo_windows_k_l[] = {windows_k, windows_l, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_l[] = {my_raise_k, my_raise_l, COMBO_END};
const uint16_t PROGMEM combo_cap_j_cap_k_cap_l[] = {my_cap_j, my_cap_k, my_cap_l, COMBO_END};


const uint16_t PROGMEM combo_h_j[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_H_J[] = {my_cap_h, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_J_K[] = {my_cap_k, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_spc_h[] = {my_h, my_space, COMBO_END};
const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END};
const uint16_t PROGMEM combo_j_i[] = {my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_j_i_o[] = {my_j, my_i, my_o, COMBO_END};

const uint16_t PROGMEM combo_i_o[] = { my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_raise_i_raise_o[] = { my_raise_i, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_my_raise_g[] = { RAISE, my_g, COMBO_END};
const uint16_t PROGMEM combo_k_m[] = {my_k, my_m, COMBO_END};

const uint16_t PROGMEM combo_j_n[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_raise_j_raise_n[] = {my_raise_j, my_raise_n, COMBO_END};

const uint16_t PROGMEM combo_w_l[] = {my_w, my_l, COMBO_END};
const uint16_t PROGMEM combo_w_h[] = {my_w, my_h, COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {my_w, my_e, COMBO_END};


/* const uint16_t PROGMEM combo_hyper_clear[] = {my_k,my_semicolon, my_l, COMBO_END}; */
const uint16_t PROGMEM combo_shiftlok[] = {my_left_shift, my_forward_slash, COMBO_END};

/* const uint16_t PROGMEM combo_opening_square[] = {my_l, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_closing_square[] = {my_singlequote, my_semicolon, COMBO_END}; */
/* const uint16_t PROGMEM combo_opening_curly[] = {my_o, my_p, COMBO_END}; */

const uint16_t PROGMEM combo_l_semicolon[] = {my_l, my_semicolon, COMBO_END}; // [

const uint16_t PROGMEM combo_l_p[] = {my_l, my_p, COMBO_END}; // [
const uint16_t PROGMEM combo_comma_m[] = {my_m, my_comma, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semicolon_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // {
const uint16_t PROGMEM combo_period_comma_m[] = {my_period, my_m, my_comma, COMBO_END}; // {

const uint16_t PROGMEM combo_j_singlequote[] = {my_j, my_singlequote, COMBO_END};

const uint16_t PROGMEM combo_comma_l[] = {my_l, my_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_comma_raise_l[] = {my_raise_l, my_raise_comma, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_comma[] = {my_raise_m, my_raise_comma, COMBO_END};

const uint16_t PROGMEM combo_lower_comma_lower_l[] = {my_lower_l, my_lower_comma, COMBO_END};

const uint16_t PROGMEM combo_comma_semicolon[] = {my_semicolon, my_comma, COMBO_END};

const uint16_t PROGMEM combo_semicolon_singlequote[] = {my_semicolon, my_singlequote, COMBO_END}; // ]
const uint16_t PROGMEM combo_l_singlequote_semicolon[] = {my_l, my_singlequote, my_semicolon, COMBO_END}; // }
const uint16_t PROGMEM combo_comma_period_forward_slash[] = {my_forward_slash, my_comma, my_period, COMBO_END}; // ]

const uint16_t PROGMEM combo_space_forward_slash[] = {my_forward_slash, my_space, COMBO_END}; // ]
const uint16_t PROGMEM combo_period_forward_slash[] = {my_forward_slash, my_period, COMBO_END};

const uint16_t PROGMEM combo_p_topright[] = {my_p, topright, COMBO_END}; // underscore
const uint16_t PROGMEM combo_p_topright_o[] = {my_p, my_o, topright, COMBO_END}; // equal

const uint16_t PROGMEM combo_lower_right_of_lower[] = {LOWER, right_of_lower, COMBO_END};

const uint16_t PROGMEM combo_j_l[] = { my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_m_k[] = { my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_m_k_l[] = { my_m, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_m_l[] = { my_m, my_l, COMBO_END};
const uint16_t PROGMEM combo_j_k_l[] = {my_k, my_l, my_j, COMBO_END};
const uint16_t PROGMEM combo_J_K_L[] = {my_cap_k, my_cap_l, my_cap_j, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {my_u, my_i, COMBO_END};
const uint16_t PROGMEM combo_raise_u_raise_i[] = {my_raise_i, my_raise_u, COMBO_END};

const uint16_t PROGMEM combo_4_11_4_12[] = {key_4_11, key_4_12, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_12[] = {my_right_of_lower, key_4_12, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_11[] = {my_right_of_lower, key_4_11, COMBO_END};
const uint16_t PROGMEM combo_4_10_4_11_4_12[] = {my_right_of_lower, key_4_11, key_4_12, COMBO_END};


const uint16_t PROGMEM combo_left_to_down[] = {my_right_of_lower, key_left, COMBO_END};
const uint16_t PROGMEM combo_right_to_up[] = {key_left, key_right, COMBO_END};


const uint16_t PROGMEM combo_u_o[] = {my_u, my_o, COMBO_END};
const uint16_t PROGMEM combo_u_i_o[] = {my_u, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_m_period[] = {my_m, my_period, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_period[] = {my_raise_m, my_raise_period, COMBO_END};

const uint16_t PROGMEM combo_j_o[] = {my_j,  my_o, COMBO_END};
const uint16_t PROGMEM combo_j_k_o[] = {my_j, my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_k_p[] = {my_k, my_p, COMBO_END};
const uint16_t PROGMEM combo_w_r[] = {my_w, my_r, COMBO_END};
/* const uint16_t PROGMEM combo_x_v[] = {my_x, my_v, COMBO_END}; */
const uint16_t PROGMEM combo_q_e[] = {my_q, my_e, COMBO_END};
const uint16_t PROGMEM combo_s_f[] = {my_s, my_f, COMBO_END};
const uint16_t PROGMEM combo_w_f[] = {my_w, my_f, COMBO_END};
const uint16_t PROGMEM combo_q_w[] = {my_q, my_w, COMBO_END};
const uint16_t PROGMEM combo_s_e[] = {my_s, my_e, COMBO_END};


const uint16_t PROGMEM combo_grave_q[] = {my_grave, my_q, COMBO_END};
const uint16_t PROGMEM combo_grave_topright[] = {my_grave, topright, COMBO_END};
const uint16_t PROGMEM combo_grave_p[] = {my_grave, my_p, COMBO_END};
const uint16_t PROGMEM combo_k_semicolon[] = {my_k, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_space_semicolon[] = {my_space, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_space_singlequote[] = {my_space, my_singlequote, COMBO_END};
const uint16_t PROGMEM combo_l_singlequote[] = {my_l, my_singlequote, COMBO_END};


const uint16_t PROGMEM combo_singlequote_semicolon[] = {my_semicolon, my_singlequote, COMBO_END};

const uint16_t PROGMEM combo_h_i[] = {my_h, my_i, COMBO_END};

const uint16_t PROGMEM combo_o_p[] = {my_o, my_p, COMBO_END};
const uint16_t PROGMEM combo_raise_o_raise_p[] = {my_raise_o, my_raise_p, COMBO_END};

const uint16_t PROGMEM combo_comma_period[] = {my_comma, my_period, COMBO_END};


const uint16_t PROGMEM combo_m_comma_period[] = {my_m, my_period, my_comma, COMBO_END};
const uint16_t PROGMEM combo_m_comma[] = {my_m, my_comma, COMBO_END};

/* const uint16_t PROGMEM i_love_bootz[] = {my_i, my_l, COMBO_END}; */

const uint16_t PROGMEM combo_v_d[] = {my_v, my_d, COMBO_END};
const uint16_t PROGMEM combo_v_c[] = {my_v, my_c, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {my_d, my_f, COMBO_END};
const uint16_t PROGMEM combo_raise_d_raise_f[] = {my_raise_d, my_raise_f, COMBO_END};



const uint16_t PROGMEM combo_topright_l[] = {topright, my_l, COMBO_END};
const uint16_t PROGMEM combo_topright_p_l[] = {topright, my_l, my_p, COMBO_END};

/* const uint16_t PROGMEM combo_forward_slash_right_shift[] = {my_forward_slash, my_right_shift, COMBO_END}; */

const uint16_t PROGMEM combo_slack_show_desktop[] = {show_desktop, select_slack, COMBO_END};


const uint16_t PROGMEM combo_w_d[] = {my_w, my_d, COMBO_END};
const uint16_t PROGMEM combo_r_g[] = {my_r, my_g, COMBO_END};
const uint16_t PROGMEM combo_e_r[] = {my_e, my_r, COMBO_END};

const uint16_t PROGMEM combo_y_i[] = {my_y, my_i, COMBO_END};
const uint16_t PROGMEM combo_d_i[] = {my_d, my_i, COMBO_END};
const uint16_t PROGMEM combo_y_t[] = {my_y, my_t, COMBO_END};
const uint16_t PROGMEM combo_d_t[] = {my_d, my_t, COMBO_END};


const uint16_t PROGMEM combo_raise_j_raise_i[] = {my_raise_j, my_raise_i, COMBO_END};
const uint16_t PROGMEM combo_lower__j_i[] = {LOWER, my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_lower__k_o[] = {LOWER, my_k, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower_k_o[] = {my_lower_k, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_o_p[] = {my_lower_p, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower__m_k[] = {LOWER, my_m, my_k, COMBO_END};
const uint16_t PROGMEM combo_lower_m_k[] = {my_lower_m, my_lower_k, COMBO_END};
const uint16_t PROGMEM combo_lower__i_o[] = {LOWER, my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_lower__k_l[] = {LOWER, my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_lower__comma_period[] = {LOWER, my_comma, my_period, COMBO_END};
const uint16_t PROGMEM combo_lower_i_o[] = {my_lower_i, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_k_raise_l[] = {my_lower_k, my_lower_l, COMBO_END};

const uint16_t PROGMEM combo_lower_comma_l[] = {my_lower_comma, my_lower_l, COMBO_END};
const uint16_t PROGMEM combo_lower__comma_l[] = {LOWER, my_comma, my_l, COMBO_END};
const uint16_t PROGMEM combo_raise_k_raise_o[] = {my_raise_k, my_raise_o, COMBO_END};
const uint16_t PROGMEM combo_raise_m_raise_k[] = {my_raise_m, my_raise_k, COMBO_END};

const uint16_t PROGMEM combo_lower_j_i[] = {LOWER, my_j, my_i, COMBO_END};
const uint16_t PROGMEM combo_lower_k_lower_o[] = {my_lower_k, my_lower_o, COMBO_END};
const uint16_t PROGMEM combo_lower_m_lower_k[] = {my_lower_m, my_lower_k, COMBO_END};
const uint16_t PROGMEM combo_lower_k_lower_l[] = {my_lower_k, my_lower_l, COMBO_END};

const uint16_t PROGMEM combo_lower_d_lower_f[] = {my_lower_d, my_lower_f, COMBO_END};

const uint16_t PROGMEM combo_raise_esc_ctrl[] = {esc_ctrl, RAISE, COMBO_END};

const uint16_t PROGMEM combo_q_o[] = {my_o, my_q, COMBO_END};

const uint16_t PROGMEM combo_lower_semicolon[] = {my_semicolon, LOWER, COMBO_END};

const uint16_t PROGMEM combo_raise_h_raise_j[] = {my_raise_h, my_raise_j, COMBO_END};


const uint16_t PROGMEM combo_LOWER_o_p[] = {LOWER, my_o, my_p, COMBO_END};
const uint16_t PROGMEM combo_LOWER_m_comma[] = {LOWER, my_m, my_comma, COMBO_END};

const uint16_t PROGMEM combo_LOWER_l_semi[] = {LOWER, my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_LOWER_period_slash[] = {LOWER, my_forward_slash, my_period, COMBO_END};
const uint16_t PROGMEM combo_r_t[] = {my_r, my_t, COMBO_END};
const uint16_t PROGMEM combo_LOWER_lower_lower_period_lower_slash[] = {lower_LOWER, my_lower_period, my_lower_slash, COMBO_END};


const uint16_t PROGMEM combo_shift_alt[] = {LOWER, my_left_shift, KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_hyper_slash[] = {LOWER, right_of_lower, my_forward_slash, COMBO_END};
const uint16_t PROGMEM combo_lower_j_k_l[] = {LOWER, my_j, my_k, my_l, COMBO_END};


const uint16_t PROGMEM combo_editing_j_editing_k[] = {editing_j, editing_k, COMBO_END};

/* const combo_t  = COMBO(combo_topright_p_l, LCTL(KC_L)); */

combo_t key_combos[COMBO_COUNT] = {
                                   COMBO(combo_lower_bottom_right_2, KC_DELETE),
                                   COMBO(combo_y_i,EMACS_INSIDE_YANK),
                                   COMBO(combo_d_i,EMACS_INSIDE_DELETE),
                                   COMBO(combo_y_t,EMACS_TO_YANK),
                                   COMBO(combo_d_t,EMACS_TO_DELETE),

                                   COMBO(combo_lower__j_i, EMACS_FASD),

                                   COMBO(combo_4_10_4_12, KC_RIGHT),
                                   COMBO(combo_4_11_4_12, KC_RIGHT),
                                   COMBO(combo_4_10_4_11, KC_LEFT),
                                   COMBO(combo_4_10_4_11_4_12, RCTL(KC_C)),
                                   COMBO(combo_l_semicolon, RCTL(KC_C)),
                                   COMBO(combo_l_p, CLEAR_THAT_REPL),


                                   COMBO(combo_left_to_down, KC_DOWN),
                                         COMBO(combo_right_to_up, KC_UP),
                                   COMBO(combo_w_d, TO(_GAUTH)),
                                   COMBO(combo_r_t, KC_AGIN),
                                   COMBO(combo_lower_semicolon, RCTL(KC_C)),

                                   /* COMBO(combo_m_period, KC_COLN), */

                                   /* COMBO(combo_shift_alt, AUDIO_LAYER_HOLD), */
                                   COMBO(combo_LOWER_o_p, AUTOSHIFT_TOGGLE),
                                   /* COMBO(combo_LOWER_m_comma, LAYER_MOUSE_HOLD), */
                                   /* COMBO(combo_LOWER_l_semi, LAYER_RAISE_HOLD), */
                                   COMBO(combo_lower_j_k_l, LAYER_LOWER_HOLD),
                                   COMBO(combo_LOWER_lower_lower_period_lower_slash, TO(_BASE)),


                                   COMBO(combo_h_u, TD(DANCE_SAVE_LOAD_NS_SWITCH)),
                                   // COMBO(combo_j_n, KC_GRV),
                                   COMBO(combo_j_n, KC_GRV),
                                   COMBO(combo_raise_h_raise_j, KC_DELETE),
                                   /* COMBO(combo_lower_semicolon, RCTL(KC_SCOLON)), */
                                   COMBO(combo_my_raise_g, OSL(_MACROS)),

                                   // layers
                                   COMBO(combo_r_g, TD(DANCE_F5)),
                                   /* COMBO(combo_grave_q, TO(_AUDIO)), */
                                   COMBO(combo_f_g, OSL(_MACROS)),
                                   COMBO(combo_s_d, OSL(_WINDOWS)),
                                   COMBO(combo_w_e, OSL(_WINMOVE)),

                                   COMBO(combo_windows_k_l, RGUI(KC_MINUS)),
                                   COMBO(combo_slack_show_desktop, ALT_TAB), // only active in WINDOWS layer. bad name.  alt-tab tho

                                   COMBO(combo_e_f, my_grave),

                                   // emacs paste
                                   /* COMBO(combo_y_u, RCTL(KC_Y)), */
                                   // macros n'at
                                   COMBO(combo_v_d, KC_PASTE), // shell paste
                                   COMBO(combo_v_c, LALT(RSFT(KC_LBRACKET))), // shell copy mode

                                   //
                                   /* COMBO(combo_e_f, KC_TAB), */
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
                                   COMBO(combo_j_l, KC_LBRACKET),

                                   COMBO(combo_cap_m_cap_k, KC_LBRACKET),
                                   COMBO(combo_raise_m_raise_k, KC_RBRACKET),
                                   COMBO(combo_j_o, KC_LBRACKET),


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
                                   COMBO(combo_m_comma_period, KC_PLUS),
                                   COMBO(raise_comma_raise_period, KC_PLUS),

                                   /* COMBO(combo_m_k_l, KC_COLN), */
                                   COMBO(combo_m_l, KC_COLN),

                                   COMBO(combo_h_j, KC_BSPC),
                                   COMBO(combo_H_J, KC_BSPC),

                                   COMBO(combo_lower_slash, TERM_CD_UP_DIR),

                                   COMBO(combo_raise_j_raise_k, FISH_ACCEPT_SEND),

                                   COMBO(combo_lower_lprn, KC_LPRN),
                                   /* COMBO(combo_lower_rprn, ALT_TAB), */
                                   COMBO(combo_lower_exlm, KC_EXLM),
                                   COMBO(combo_lower_at, KC_AT),
                                   COMBO(combo_lower_hash, KC_HASH),
                                   COMBO(combo_lower_dlr, KC_DLR),
                                   COMBO(combo_lower_perc, KC_PERC),
                                   COMBO(combo_lower_circ, KC_CIRC),
                                   COMBO(combo_lower_ampr, KC_AMPR),
                                   COMBO(combo_lower_astr, KC_ASTR),

                                   COMBO(combo_k_o, KC_LCBR),
                                   COMBO(combo_j_i_o, KC_LCBR),
                                   COMBO(combo_cap_k_cap_o, KC_LCBR),
                                   COMBO(combo_raise_k_raise_o, KC_RCBR),

                                   // curly braces
                                   COMBO(combo_k_p, KC_RCBR),

                                   COMBO(combo_lower_comma_lower_l, KC_TILD),

                                   COMBO(combo_lower_o_p, CTRL_N),
                                   COMBO(combo_o_p, CTRL_P),
                                   COMBO(combo_shiftlok, CAPS_WORD),


                                   COMBO(combo_raise_d_f, ALT_TAB),

                                   COMBO(combo_j_k, KC_ENTER),
                                   COMBO(combo_editing_j_editing_k, CIDER_RUN_PREV_COMMAND),
                                   COMBO(combo_editing_k_editing_l, THREAD_LAST),
                                   COMBO(combo_J_K, KC_ENTER),

                                   COMBO(combo_period_semicolon, EMACS_COMMENT_READER),
                                   COMBO(combo_e_r, MO(_ROFI)),

                                   /* COMBO(combo_windows_tab_q, RGUI(KC_ESCAPE)) */
                                   /* , */


                                                                      /* COMBO(combo_spc_x, RGUI(KC_X)), */
                                                                      /* COMBO(combo_spc_h, RGUI(KC_H)), */
                                                                      /* COMBO(combo_spc_w, RGUI(KC_W)), */
                                                                      /* COMBO(combo_spc_q, RGUI(KC_Q)), */
                                                                      /* COMBO(combo_spc_n, RGUI(KC_N)), */
                                                                      /* COMBO(combo_spc_e, RGUI(KC_E)), */
                                                                      /* COMBO(combo_spc_a, RGUI(KC_A)), */
                                                                      /* COMBO(combo_spc_s, RGUI(KC_S)), */
                                                                      /* COMBO(combo_spc_t, RGUI(KC_T)), */
                                                                      /* COMBO(combo_spc_p, RGUI(KC_0)), */
                                                                      /* COMBO(combo_spc_u, RGUI(KC_7)), */
                                                                      /* COMBO(combo_spc_i, RGUI(KC_8)), */
                                                                      /* COMBO(combo_spc_o, RGUI(KC_9)) */
};
