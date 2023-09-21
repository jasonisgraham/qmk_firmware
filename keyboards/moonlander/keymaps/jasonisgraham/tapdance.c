enum tap_dance_codes {T_TAB_H_WINDOWS_DT_TIC_TH_TILDE,
                      T_U_TH_AMPR,
                      T_I_TH_ASTR,
                      T_O_TH_LPRN,
                      DANCE_9,
                      DANCE_62,
                      dance_h,
                      T_P_TH_RPRN,
                      T_MINUS_TH_PLUS,
                      T_J_TH_DLR,
                      T_K_TH_AMP,
                      T_L_TH_CIRC,
                      T_SEMI_H_COLON_DT_LSBR_TH_LCBR,
                      T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR,
                      T_M_TH_EXLAM,
                      T_COMMA_H_LTHAN_TH_AT,
                      T_PERIOD_H_GTHAN_TH_HASH,
                      T_FS_H_QU_DT_BS_TH_PIPE,
                      T_WWW_BACK_TH_WWW_FOR,
                      T_N_ALWAYS_LC,
                      T_PREV_TAB_TH_MOVE_TAB_LEFT,
                      T_NEXT_TAB_TH_MOVE_TAB_RIGHT,
                      T_EMACS_COMPLETE_H_BASE,
                      WIN_ADHOC_Q,
                      WIN_ADHOC_W,
                      WIN_ADHOC_R,
                      WIN_ADHOC_G,
                      WIN_ADHOC_Y,
                      WIN_ADHOC_J,
                      WIN_ADHOC_K,
                      WIN_ADHOC_L,
                      WIN_ADHOC_N,
                      T_LEFT_MON_TH_TILE_LEFT,
                      T_DOWN_MON_TH_MINIMIZE,
                      T_UP_MON_TH_MAXIMIZE,
                      T_RIGHT_MON_TH_TILE_RIGHT,
                      T_TAB_H_BASE_DT_TIC_TH_TILDE,
                      BASE_RETURN_TAP_DANCE,
                      T_COMMA_H_LCPR,
                      T_COL_H_LCB,
                      T_DQT_H_RCB,
                      T_L6_H_L0,
                      T_TILE_LEFT_TH_MON_LEFT,
                      T_WIN_MAX_TH_F11,
                      T_TILE_RIGHT_TH_MON_RIGHT,
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[70];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_t_tab_h_windows_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_windows_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_windows_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tab_h_windows_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_tab_h_windows_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_tab_h_windows_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_off(5); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}
void on_t_u_th_ampr(qk_tap_dance_state_t *state, void *user_data);
void t_u_th_ampr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_u_th_ampr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_u_th_ampr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void t_u_th_ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_HOLD: register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void t_u_th_ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_HOLD: unregister_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[1].step = 0;
}
void on_t_i_th_astr(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_i_th_astr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void t_i_th_astr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void t_i_th_astr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_HOLD: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[2].step = 0;
}
void on_t_o_th_lprn(qk_tap_dance_state_t *state, void *user_data);
void t_o_th_lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void t_o_th_lprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_o_th_lprn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void t_o_th_lprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_HOLD: register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void t_o_th_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_HOLD: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[3].step = 0;
}
void on_t_p_th_rprn(qk_tap_dance_state_t *state, void *user_data);
void t_p_th_rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void t_p_th_rprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_p_th_rprn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void t_p_th_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(KC_P); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void t_p_th_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(KC_P); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[4].step = 0;
}
void on_t_minus_th_plus(qk_tap_dance_state_t *state, void *user_data);
void t_minus_th_plus_finished(qk_tap_dance_state_t *state, void *user_data);
void t_minus_th_plus_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_minus_th_plus(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void t_minus_th_plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void t_minus_th_plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[5].step = 0;
}
void on_t_j_th_dlr(qk_tap_dance_state_t *state, void *user_data);
void t_j_th_dlr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_j_th_dlr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_j_th_dlr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void t_j_th_dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(KC_J); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_HOLD: register_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void t_j_th_dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(KC_J); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_HOLD: unregister_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[6].step = 0;
}
void on_t_k_th_amp(qk_tap_dance_state_t *state, void *user_data);
void t_k_th_amp_finished(qk_tap_dance_state_t *state, void *user_data);
void t_k_th_amp_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_k_th_amp(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void t_k_th_amp_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(KC_K); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void t_k_th_amp_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(KC_K); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_HOLD: unregister_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[7].step = 0;
}
void on_t_l_th_circ(qk_tap_dance_state_t *state, void *user_data);
void t_l_th_circ_finished(qk_tap_dance_state_t *state, void *user_data);
void t_l_th_circ_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_l_th_circ(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void t_l_th_circ_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(KC_L); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_HOLD: register_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void t_l_th_circ_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(KC_L); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_HOLD: unregister_code16(KC_CIRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state[8].step = 0;
}
void on_t_semi_h_colon_dt_lsbr_th_lcbr(qk_tap_dance_state_t *state, void *user_data);
void t_semi_h_colon_dt_lsbr_th_lcbr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_semi_h_colon_dt_lsbr_th_lcbr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_semi_h_colon_dt_lsbr_th_lcbr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
        tap_code16(KC_SCOLON);
    }
    if(state->count > 3) {
        tap_code16(KC_SCOLON);
    }
}

void t_semi_h_colon_dt_lsbr_th_lcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_SCOLON); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCOLON); register_code16(KC_SCOLON);
    }
}

void t_semi_h_colon_dt_lsbr_th_lcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_SCOLON); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCOLON); break;
    }
    dance_state[9].step = 0;
}
void on_t_squote_h_dquote_dt_rsbr_th_rcbr(qk_tap_dance_state_t *state, void *user_data);
void t_squote_h_dquote_dt_rsbr_th_rcbr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_squote_h_dquote_dt_rsbr_th_rcbr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_squote_h_dquote_dt_rsbr_th_rcbr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void t_squote_h_dquote_dt_rsbr_th_rcbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_DQUO); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void t_squote_h_dquote_dt_rsbr_th_rcbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(KC_DQUO); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[10].step = 0;
}
void on_t_m_th_exlam(qk_tap_dance_state_t *state, void *user_data);
void t_m_th_exlam_finished(qk_tap_dance_state_t *state, void *user_data);
void t_m_th_exlam_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_m_th_exlam(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void t_m_th_exlam_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_HOLD: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void t_m_th_exlam_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_M)); break;
        case DOUBLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_HOLD: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state[11].step = 0;
}
void on_t_comma_h_lthan_th_at(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lthan_th_at_finished(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lthan_th_at_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_comma_h_lthan_th_at(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void t_comma_h_lthan_th_at_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_LABK); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_HOLD: register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void t_comma_h_lthan_th_at_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_LABK); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_HOLD: unregister_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[12].step = 0;
}
void on_t_period_h_gthan_th_hash(qk_tap_dance_state_t *state, void *user_data);
void t_period_h_gthan_th_hash_finished(qk_tap_dance_state_t *state, void *user_data);
void t_period_h_gthan_th_hash_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_period_h_gthan_th_hash(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void t_period_h_gthan_th_hash_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_RABK); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_HOLD: register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void t_period_h_gthan_th_hash_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_RABK); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_HOLD: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[13].step = 0;
}
void on_t_fs_h_qu_dt_bs_th_pipe(qk_tap_dance_state_t *state, void *user_data);
void t_fs_h_qu_dt_bs_th_pipe_finished(qk_tap_dance_state_t *state, void *user_data);
void t_fs_h_qu_dt_bs_th_pipe_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_fs_h_qu_dt_bs_th_pipe(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void t_fs_h_qu_dt_bs_th_pipe_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_QUES); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void t_fs_h_qu_dt_bs_th_pipe_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_QUES); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[14].step = 0;
}

void on_t_www_back_th_www_for(qk_tap_dance_state_t *state, void *user_data);
void t_www_back_th_www_for_finished(qk_tap_dance_state_t *state, void *user_data);
void t_www_back_th_www_for_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_www_back_th_www_for(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
        tap_code16(RALT(KC_LEFT));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_LEFT));
    }
}

void t_www_back_th_www_for_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: register_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_LEFT)); register_code16(RALT(KC_LEFT));
    }
}

void t_www_back_th_www_for_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
        case DOUBLE_HOLD: unregister_code16(RALT(KC_RIGHT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_LEFT)); break;
    }
    dance_state[17].step = 0;
}
void on_t_n_always_lc(qk_tap_dance_state_t *state, void *user_data);
void t_n_always_lc_finished(qk_tap_dance_state_t *state, void *user_data);
void t_n_always_lc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_n_always_lc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void t_n_always_lc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(KC_N); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_HOLD: register_code16(RSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void t_n_always_lc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(KC_N); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_HOLD: unregister_code16(RSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[18].step = 0;
}
void on_t_prev_tab_th_move_tab_left(qk_tap_dance_state_t *state, void *user_data);
void t_prev_tab_th_move_tab_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_prev_tab_th_move_tab_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_prev_tab_th_move_tab_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
        tap_code16(RCTL(KC_PGUP));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGUP));
    }
}

void t_prev_tab_th_move_tab_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGUP)); register_code16(RCTL(KC_PGUP));
    }
}

void t_prev_tab_th_move_tab_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGUP))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGUP)); break;
    }
    dance_state[19].step = 0;
}
void on_t_next_tab_th_move_tab_right(qk_tap_dance_state_t *state, void *user_data);
void t_next_tab_th_move_tab_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_next_tab_th_move_tab_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_next_tab_th_move_tab_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
        tap_code16(RCTL(KC_PGDOWN));
    }
    if(state->count > 3) {
        tap_code16(RCTL(KC_PGDOWN));
    }
}

void t_next_tab_th_move_tab_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: register_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: register_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RCTL(KC_PGDOWN)); register_code16(RCTL(KC_PGDOWN));
    }
}

void t_next_tab_th_move_tab_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
        case DOUBLE_HOLD: unregister_code16(RCTL(RSFT(KC_PGDOWN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RCTL(KC_PGDOWN)); break;
    }
    dance_state[20].step = 0;
}

void on_t_emacs_complete_h_base(qk_tap_dance_state_t *state, void *user_data);
void t_emacs_complete_h_base_finished(qk_tap_dance_state_t *state, void *user_data);
void t_emacs_complete_h_base_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_emacs_complete_h_base(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
        tap_code16(RALT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_SLASH));
    }
}

void t_emacs_complete_h_base_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(RALT(KC_SLASH)); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_SLASH)); register_code16(RALT(KC_SLASH));
    }
}

void t_emacs_complete_h_base_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_SLASH)); break;
    }
    dance_state[22].step = 0;
}
void on_t_i_th_astr3(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr3_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_i_th_astr3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_i_th_astr3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_i_th_astr3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[23].step = 0;
}
void t_i_th_astr4_finished(qk_tap_dance_state_t *state, void *user_data);
void t_i_th_astr4_reset(qk_tap_dance_state_t *state, void *user_data);

void t_i_th_astr4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
    }
}

void t_i_th_astr4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
    }
    dance_state[24].step = 0;
}
void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tab_h_base_dt_tic_th_tilde(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void t_tab_h_base_dt_tic_th_tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[25].step = 0;
}
void on_win_adhoc_q(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_q_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_q(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
        tap_code16(RGUI(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Q));
    }
}

void win_adhoc_q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Q)); register_code16(RGUI(KC_Q));
    }
}

void win_adhoc_q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Q)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Q)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Q)); break;
    }
    dance_state[26].step = 0;
}
void on_win_adhoc_w(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_w_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_w_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_w(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
        tap_code16(RGUI(KC_W));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_W));
    }
}

void win_adhoc_w_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_W)); register_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_W)); register_code16(RGUI(KC_W));
    }
}

void win_adhoc_w_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_W)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_W)); break;
    }
    dance_state[27].step = 0;
}
void on_win_adhoc_r(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_r_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_r_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_r(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
        tap_code16(RGUI(KC_R));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_R));
    }
}

void win_adhoc_r_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_R)); register_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_R)); register_code16(RGUI(KC_R));
    }
}

void win_adhoc_r_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_R)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_R)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_R)); break;
    }
    dance_state[28].step = 0;
}
void on_win_adhoc_g(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_g_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_g_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_g(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
        tap_code16(RGUI(KC_G));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_G));
    }
}

void win_adhoc_g_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_G)); register_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_G)); register_code16(RGUI(KC_G));
    }
}

void win_adhoc_g_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_G)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_G)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_G)); break;
    }
    dance_state[29].step = 0;
}
void on_win_adhoc_y(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_y_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_y(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
        tap_code16(RGUI(KC_Y));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_Y));
    }
}

void win_adhoc_y_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_Y)); register_code16(RGUI(KC_Y));
    }
}

void win_adhoc_y_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_Y)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_Y)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_Y)); break;
    }
    dance_state[30].step = 0;
}
void on_win_adhoc_j(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_j_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_j_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_j(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
        tap_code16(RGUI(KC_J));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_J));
    }
}

void win_adhoc_j_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_J)); register_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: register_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_J)); register_code16(RGUI(KC_J));
    }
}

void win_adhoc_j_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_J)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(RALT(RGUI(KC_J)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_J)); break;
    }
    dance_state[31].step = 0;
}
void on_win_adhoc_k(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_k_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_k(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
        tap_code16(RGUI(KC_K));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_K));
    }
}

void win_adhoc_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_K)); register_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_K)); register_code16(RGUI(KC_K));
    }
}

void win_adhoc_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_K)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_K)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_K)); break;
    }
    dance_state[32].step = 0;
}
void on_win_adhoc_l(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_l_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_l_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_l(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
        tap_code16(RGUI(KC_L));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_L));
    }
}

void win_adhoc_l_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_L)); register_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_L)); register_code16(RGUI(KC_L));
    }
}

void win_adhoc_l_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_L)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_L)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_L)); break;
    }
    dance_state[33].step = 0;
}
void on_win_adhoc_n(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_n_finished(qk_tap_dance_state_t *state, void *user_data);
void win_adhoc_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_win_adhoc_n(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
        tap_code16(RGUI(KC_N));
    }
    if(state->count > 3) {
        tap_code16(RGUI(KC_N));
    }
}

void win_adhoc_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_N)); register_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(KC_N)); register_code16(RGUI(KC_N));
    }
}

void win_adhoc_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_N)); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LGUI(KC_N)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(KC_N)); break;
    }
    dance_state[34].step = 0;
}
void on_t_down_mon_th_minimiZe(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimiZe_finished(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimiZe_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_down_mon_th_minimiZe(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimiZe_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimiZe_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
    }
    dance_state[35].step = 0;
}
void on_t_left_mon_th_tile_left(qk_tap_dance_state_t *state, void *user_data);
void t_left_mon_th_tile_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_left_mon_th_tile_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_left_mon_th_tile_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void t_left_mon_th_tile_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_LEFT))); register_code16(RGUI(RSFT(KC_LEFT)));
    }
}

void t_left_mon_th_tile_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_LEFT))); break;
    }
    dance_state[36].step = 0;
}
void on_t_down_mon_th_minimize(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimize_finished(qk_tap_dance_state_t *state, void *user_data);
void t_down_mon_th_minimize_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_down_mon_th_minimize(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimize_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_DOWN))); register_code16(RGUI(RSFT(KC_DOWN)));
    }
}

void t_down_mon_th_minimize_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_J))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_DOWN))); break;
    }
    dance_state[37].step = 0;
}
void on_t_right_mon_th_tile_right(qk_tap_dance_state_t *state, void *user_data);
void t_right_mon_th_tile_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_right_mon_th_tile_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_right_mon_th_tile_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void t_right_mon_th_tile_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RGUI(RSFT(KC_RIGHT))); register_code16(RGUI(RSFT(KC_RIGHT)));
    }
}

void t_right_mon_th_tile_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_L))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RGUI(RSFT(KC_RIGHT))); break;
    }
    dance_state[38].step = 0;
}


void on_base_return_tap_dance(qk_tap_dance_state_t *state, void *user_data);
void base_return_tap_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void base_return_tap_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_base_return_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void base_return_tap_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: register_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void base_return_tap_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_HOLD: unregister_code16(KC_TILD); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[41].step = 0;
}
void on_t_comma_h_lcpr(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lcpr_finished(qk_tap_dance_state_t *state, void *user_data);
void t_comma_h_lcpr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_comma_h_lcpr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

void t_comma_h_lcpr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(KC_PLUS); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void t_comma_h_lcpr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(KC_PLUS); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state[42].step = 0;
}
void on_t_col_h_lcb(qk_tap_dance_state_t *state, void *user_data);
void t_col_h_lcb_finished(qk_tap_dance_state_t *state, void *user_data);
void t_col_h_lcb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_col_h_lcb(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void t_col_h_lcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void t_col_h_lcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[43].step = 0;
}
void on_t_dqt_h_rcb(qk_tap_dance_state_t *state, void *user_data);
void t_dqt_h_rcb_finished(qk_tap_dance_state_t *state, void *user_data);
void t_dqt_h_rcb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_dqt_h_rcb(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void t_dqt_h_rcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void t_dqt_h_rcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[44].step = 0;
}
void t_l6_h_l0_finished(qk_tap_dance_state_t *state, void *user_data);
void t_l6_h_l0_reset(qk_tap_dance_state_t *state, void *user_data);

void t_l6_h_l0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void t_l6_h_l0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
    }
    dance_state[45].step = 0;
}
void on_t_tile_left_th_mon_left(qk_tap_dance_state_t *state, void *user_data);
void t_tile_left_th_mon_left_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tile_left_th_mon_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tile_left_th_mon_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
        tap_code16(LGUI(LSFT(KC_H)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_H)));
    }
}

void t_tile_left_th_mon_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_H))); register_code16(LGUI(LSFT(KC_H)));
    }
}

void t_tile_left_th_mon_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_H))); break;
    }
    dance_state[46].step = 0;
}
void on_t_win_max_th_f11(qk_tap_dance_state_t *state, void *user_data);
void t_win_max_th_f11_finished(qk_tap_dance_state_t *state, void *user_data);
void t_win_max_th_f11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_win_max_th_f11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
        tap_code16(LGUI(LSFT(KC_K)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_K)));
    }
}

void t_win_max_th_f11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_K))); register_code16(LGUI(LSFT(KC_K)));
    }
}

void t_win_max_th_f11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
        case DOUBLE_HOLD: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_K))); break;
    }
    dance_state[47].step = 0;
}
void on_t_tile_right_th_mon_right(qk_tap_dance_state_t *state, void *user_data);
void t_tile_right_th_mon_right_finished(qk_tap_dance_state_t *state, void *user_data);
void t_tile_right_th_mon_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_tile_right_th_mon_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
        tap_code16(LGUI(LSFT(KC_L)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_L)));
    }
}

void t_tile_right_th_mon_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_L))); register_code16(LGUI(LSFT(KC_L)));
    }
}

void t_tile_right_th_mon_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[48].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_RIGHT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_L))); break;
    }
    dance_state[48].step = 0;
}

void on_t_up_mon_th_maximize(qk_tap_dance_state_t *state, void *user_data);
void t_up_mon_th_maximize_finished(qk_tap_dance_state_t *state, void *user_data);
void t_up_mon_th_maximize_reset(qk_tap_dance_state_t *state, void *user_data);

void on_t_up_mon_th_maximize(qk_tap_dance_state_t *state, void *user_data) {

  if(state->count == 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
    tap_code16(LGUI(LSFT(KC_UP)));
  }
  if(state->count > 3) {
    tap_code16(LGUI(LSFT(KC_UP)));
  }
}

void t_up_mon_th_maximize_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[49].step = dance_step(state);
    switch (dance_state[49].step) {
    case SINGLE_TAP: register_code16(LGUI(LSFT(KC_UP))); break;
    case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP))); break;
    case DOUBLE_HOLD: register_code16(RGUI(RSFT(KC_K))); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_UP))); register_code16(LGUI(LSFT(KC_UP)));
    }
}

void t_up_mon_th_maximize_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[49].step) {
    case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
    case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;
    case DOUBLE_HOLD: unregister_code16(RGUI(RSFT(KC_K))); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_UP))); break;

    }
    dance_state[49].step = 0;
}

void on_dance_62(qk_tap_dance_state_t *state, void *user_data);
void dance_62_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_62_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_62(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_62_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[62].step = dance_step(state);
    switch (dance_state[62].step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(KC_H); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_62_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[62].step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(KC_H); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state[62].step = 0;
}

void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(KC_P); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(KC_P); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[9].step = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
        [T_TAB_H_WINDOWS_DT_TIC_TH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tab_h_windows_dt_tic_th_tilde, t_tab_h_windows_dt_tic_th_tilde_finished, t_tab_h_windows_dt_tic_th_tilde_reset),
        [T_U_TH_AMPR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_u_th_ampr, t_u_th_ampr_finished, t_u_th_ampr_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_62] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_62, dance_62_finished, dance_62_reset),
        [T_I_TH_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_i_th_astr, t_i_th_astr_finished, t_i_th_astr_reset),
        [T_O_TH_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_o_th_lprn, t_o_th_lprn_finished, t_o_th_lprn_reset),
        [T_P_TH_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_p_th_rprn, t_p_th_rprn_finished, t_p_th_rprn_reset),
        [T_MINUS_TH_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_minus_th_plus, t_minus_th_plus_finished, t_minus_th_plus_reset),
        [T_J_TH_DLR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_j_th_dlr, t_j_th_dlr_finished, t_j_th_dlr_reset),
        [T_K_TH_AMP] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_k_th_amp, t_k_th_amp_finished, t_k_th_amp_reset),
        [T_L_TH_CIRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_l_th_circ, t_l_th_circ_finished, t_l_th_circ_reset),
        [T_SEMI_H_COLON_DT_LSBR_TH_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_semi_h_colon_dt_lsbr_th_lcbr, t_semi_h_colon_dt_lsbr_th_lcbr_finished, t_semi_h_colon_dt_lsbr_th_lcbr_reset),
        [T_SQUOTE_H_DQUOTE_DT_RSBR_TH_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_squote_h_dquote_dt_rsbr_th_rcbr, t_squote_h_dquote_dt_rsbr_th_rcbr_finished, t_squote_h_dquote_dt_rsbr_th_rcbr_reset),
        [T_M_TH_EXLAM] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_m_th_exlam, t_m_th_exlam_finished, t_m_th_exlam_reset),
        [T_COMMA_H_LTHAN_TH_AT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_comma_h_lthan_th_at, t_comma_h_lthan_th_at_finished, t_comma_h_lthan_th_at_reset),
        [T_PERIOD_H_GTHAN_TH_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_period_h_gthan_th_hash, t_period_h_gthan_th_hash_finished, t_period_h_gthan_th_hash_reset),
        [T_FS_H_QU_DT_BS_TH_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_fs_h_qu_dt_bs_th_pipe, t_fs_h_qu_dt_bs_th_pipe_finished, t_fs_h_qu_dt_bs_th_pipe_reset),
        [T_WWW_BACK_TH_WWW_FOR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_www_back_th_www_for, t_www_back_th_www_for_finished, t_www_back_th_www_for_reset),
        [T_N_ALWAYS_LC] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_n_always_lc, t_n_always_lc_finished, t_n_always_lc_reset),
        [T_PREV_TAB_TH_MOVE_TAB_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_prev_tab_th_move_tab_left, t_prev_tab_th_move_tab_left_finished, t_prev_tab_th_move_tab_left_reset),
        [T_NEXT_TAB_TH_MOVE_TAB_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_next_tab_th_move_tab_right, t_next_tab_th_move_tab_right_finished, t_next_tab_th_move_tab_right_reset),
        [T_EMACS_COMPLETE_H_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_emacs_complete_h_base, t_emacs_complete_h_base_finished, t_emacs_complete_h_base_reset),
        [T_TAB_H_BASE_DT_TIC_TH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tab_h_base_dt_tic_th_tilde, t_tab_h_base_dt_tic_th_tilde_finished, t_tab_h_base_dt_tic_th_tilde_reset),
        [WIN_ADHOC_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_q, win_adhoc_q_finished, win_adhoc_q_reset),
        [WIN_ADHOC_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_w, win_adhoc_w_finished, win_adhoc_w_reset),
        [WIN_ADHOC_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_r, win_adhoc_r_finished, win_adhoc_r_reset),
        [WIN_ADHOC_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_g, win_adhoc_g_finished, win_adhoc_g_reset),
        [WIN_ADHOC_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_y, win_adhoc_y_finished, win_adhoc_y_reset),
        [WIN_ADHOC_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_j, win_adhoc_j_finished, win_adhoc_j_reset),
        [WIN_ADHOC_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_k, win_adhoc_k_finished, win_adhoc_k_reset),
        [WIN_ADHOC_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_l, win_adhoc_l_finished, win_adhoc_l_reset),
        [WIN_ADHOC_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_win_adhoc_n, win_adhoc_n_finished, win_adhoc_n_reset),
        [T_LEFT_MON_TH_TILE_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_left_mon_th_tile_left, t_left_mon_th_tile_left_finished, t_left_mon_th_tile_left_reset),
        [T_DOWN_MON_TH_MINIMIZE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_down_mon_th_minimize, t_down_mon_th_minimize_finished, t_down_mon_th_minimize_reset),
        [T_UP_MON_TH_MAXIMIZE] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_up_mon_th_maximize, t_up_mon_th_maximize_finished, t_up_mon_th_maximize_reset),
        [T_RIGHT_MON_TH_TILE_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_right_mon_th_tile_right, t_right_mon_th_tile_right_finished, t_right_mon_th_tile_right_reset),
        [BASE_RETURN_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_base_return_tap_dance, base_return_tap_dance_finished, base_return_tap_dance_reset),
        [T_COMMA_H_LCPR] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_comma_h_lcpr, t_comma_h_lcpr_finished, t_comma_h_lcpr_reset),
        [T_COL_H_LCB] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_col_h_lcb, t_col_h_lcb_finished, t_col_h_lcb_reset),
        [T_DQT_H_RCB] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_dqt_h_rcb, t_dqt_h_rcb_finished, t_dqt_h_rcb_reset),
        [T_L6_H_L0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_l6_h_l0_finished, t_l6_h_l0_reset),
        [dance_h] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_62_finished, dance_62_reset),
        [T_TILE_LEFT_TH_MON_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tile_left_th_mon_left, t_tile_left_th_mon_left_finished, t_tile_left_th_mon_left_reset),
        [T_WIN_MAX_TH_F11] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_win_max_th_f11, t_win_max_th_f11_finished, t_win_max_th_f11_reset),
        [T_TILE_RIGHT_TH_MON_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_t_tile_right_th_mon_right, t_tile_right_th_mon_right_finished, t_tile_right_th_mon_right_reset),
};
