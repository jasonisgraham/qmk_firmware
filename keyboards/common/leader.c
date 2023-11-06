float leader_start_song[][2] = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2] = SONG(RICK_ROLL);

void leader_start_user(void) {
    printf("leader start\n");
}

void leader_end_user(void) {
    bool did_leader_succeed = false;
    printf("leader end\n");

    if (leader_sequence_one_key(my_t)) {
        printf("leader one-key\n");
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(my_a)) {
        printf("leader one-key A\n");
        tap_code16(RGUI(KC_A));
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(my_l, LOWER)) {
        layer_on(_LOWER);
        printf("leader lowerA\n");
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(my_l, RAISE)) {
        layer_on(_RAISE);
        printf("leader raise\n");
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(my_l, my_left_shift)) {
        printf("leader shiftlock\n");
        layer_on(_SHIFTLOCK);
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(my_l, my_m)) {
        printf("leader mouse\n");
        layer_on(_MOUSE);
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(my_e, my_d)) {
        printf("leader two-key\n");
        SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
        did_leader_succeed = true;
    }

    if (did_leader_succeed) {
        printf("success");
    } else {
        printf("failure!");
    }
}
