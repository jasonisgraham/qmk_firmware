const uint16_t PROGMEM combo_lprn_n[] = {my_space, my_n, COMBO_END};
const uint16_t PROGMEM combo_lprn[] = {my_space, my_o, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {my_space, my_p, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {my_space, my_m, COMBO_END};
const uint16_t PROGMEM combo_at[] =   {my_space, my_comma, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {my_space, my_period, COMBO_END};
const uint16_t PROGMEM combo_dlr[] =  {my_space, my_j, COMBO_END};
const uint16_t PROGMEM combo_perc[] = {my_space, my_k, COMBO_END};
const uint16_t PROGMEM combo_circ[] = {my_space, my_l, COMBO_END};
const uint16_t PROGMEM combo_ampr[] = {my_space, my_u, COMBO_END};
const uint16_t PROGMEM combo_astr[] = {my_space,  my_i, COMBO_END};
const uint16_t PROGMEM combo_osl_symbols[] = {my_j, my_l, COMBO_END};

const uint16_t PROGMEM combo_newline[] = {my_j, my_k, COMBO_END};
const uint16_t PROGMEM combo_osl_windows[] = {my_s, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_windows_2[] = {my_f, my_d, COMBO_END};
const uint16_t PROGMEM combo_osl_editor[] = {my_k, my_l, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {my_h, my_j, COMBO_END};
const uint16_t PROGMEM combo_spc_h[] = {my_h, my_space, COMBO_END};
const uint16_t PROGMEM combo_jo[] = {my_o, my_j, COMBO_END};
const uint16_t PROGMEM combo_jp[] = {my_p, my_j, COMBO_END};
const uint16_t PROGMEM combo_opening_paren[] = {my_u,  my_i, COMBO_END};
const uint16_t PROGMEM combo_closing_paren[] = { my_i, my_o, COMBO_END};
const uint16_t PROGMEM combo_max[] = {my_k, my_m, COMBO_END};
const uint16_t PROGMEM combo_min[] = {my_j, my_n, COMBO_END};
const uint16_t PROGMEM combo_win_right[] = {my_w, my_l, COMBO_END};
const uint16_t PROGMEM combo_win_left[] = {my_w, my_h, COMBO_END};
const uint16_t PROGMEM combo_osl_win_move[] = {my_w, my_e, COMBO_END};
const uint16_t PROGMEM combo_hyper_clear[] = {my_k,my_semicolon, my_l, COMBO_END};
const uint16_t PROGMEM combo_shiftlok[] = {my_left_shift, my_right_shift, COMBO_END};
const uint16_t PROGMEM combo_opening_square[] = {my_l, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_closing_square[] = {my_single_quote, my_semicolon, COMBO_END};
const uint16_t PROGMEM combo_opening_curly[] = {my_o, my_p, COMBO_END};

const uint16_t PROGMEM combo_l_semicolon[] = {my_l, my_semicolon, COMBO_END}; // [
const uint16_t PROGMEM combo_comma_m[] = {my_m, my_comma, COMBO_END}; // [
const uint16_t PROGMEM combo_l_semicolon_k[] = {my_k, my_l, my_semicolon, COMBO_END}; // {
const uint16_t PROGMEM combo_period_comma_m[] = {my_period, my_m, my_comma, COMBO_END}; // {

const uint16_t PROGMEM combo_semicolon_singlequote[] = {my_semicolon, my_single_quote, COMBO_END}; // ]
const uint16_t PROGMEM combo_comma_period[] = {my_comma, my_period, COMBO_END}; // ]
const uint16_t PROGMEM combo_l_singlequote_semicolon[] = {my_l, my_single_quote, my_semicolon, COMBO_END}; // }
const uint16_t PROGMEM combo_comma_period_forward_slash[] = {my_forward_slash, my_comma, my_period, COMBO_END}; // ]

const uint16_t PROGMEM combo_p_minus[] = {my_p, my_minus, COMBO_END}; // underscore
const uint16_t PROGMEM combo_p_minus_o[] = {my_p, my_o, my_minus, COMBO_END}; // equal

const uint16_t PROGMEM combo_lower_right_of_lower[] = {my_lower, my_right_of_lower, COMBO_END}; // equal

const uint16_t PROGMEM combo_j_l[] = {my_j, my_l, COMBO_END}; // osl(symbols)


combo_t key_combos[COMBO_COUNT] = {COMBO(combo_osl_windows, OSL(_WINDOWS)),
                                   COMBO(combo_osl_windows_2, OSL(_WINDOWS)),
                                   COMBO(combo_osl_win_move, OSL(_WINMOVE)),
                                   COMBO(combo_j_l, OSL(_SYMBOLS)),

                                   COMBO(combo_backspace, KC_BSPC),
                                   COMBO(combo_spc_h, KC_BSPC),

                                   COMBO(combo_lprn_n, KC_LPRN),
                                   COMBO(combo_lprn, KC_LPRN),
                                   COMBO(combo_rprn, KC_RPRN),
                                   COMBO(combo_exlm, KC_EXLM),
                                   COMBO(combo_at, KC_AT),
                                   COMBO(combo_hash, KC_HASH),
                                   COMBO(combo_dlr, KC_DLR),
                                   COMBO(combo_perc, KC_PERC),
                                   COMBO(combo_circ, KC_CIRC),
                                   COMBO(combo_ampr, KC_AMPR),
                                   COMBO(combo_astr, KC_ASTR),

                                   COMBO(combo_jo, KC_LSPO),
                                   COMBO(combo_jp, KC_RPRN),
                                   COMBO(combo_osl_symbols, RCTL(KC_SCLN)),
                                   COMBO(combo_osl_editor, OSL(_EDITING)),
                                   COMBO(combo_max, RGUI(RSFT(KC_K))),
                                   COMBO(combo_min, RGUI(RSFT(KC_J))),
                                   COMBO(combo_shiftlok, TO(_SHIFTLOK)),
                                   COMBO(combo_opening_paren, KC_LPRN),
                                   COMBO(combo_closing_paren, KC_RPRN),
                                   COMBO(combo_comma_m, KC_LBRACKET),
                                   COMBO(combo_l_semicolon, KC_LBRACKET),

                                   COMBO(combo_period_comma_m, KC_LCBR),
                                   COMBO(combo_l_semicolon_k, KC_LCBR),

                                   COMBO(combo_comma_period, KC_RBRACKET),
                                   COMBO(combo_semicolon_singlequote, KC_RBRACKET),
                                   COMBO(combo_l_singlequote_semicolon, KC_RCBR),
                                   COMBO(combo_comma_period_forward_slash, KC_RCBR),

                                   COMBO(combo_lower_right_of_lower, TO(_LOWER)),
                                   COMBO(combo_p_minus, KC_UNDS),
                                   COMBO(combo_p_minus_o, KC_EQL),
                                   COMBO(combo_newline, KC_ENTER)};
