#include "leader.h"

/* float leader_start_song[][2] = SONG(ONE_UP_SOUND); */
/* float leader_succeed_song[][2] = SONG(ALL_STAR); */
/* float leader_fail_song[][2] = SONG(RICK_ROLL); */

void leader_start_user(void) {
        /* alt_colors(HSV_WHITE, HSV_FUSCIA); */
        /* PLAY_SONG(caps_lock_off_sound); */
        /* SEND_STRING("LEADER START"); */
}
void leader_end_user(void) {
    bool did_leader_succeed = false;
    rgblight_disable();
    printf("leader end\n");


    if (leader_sequence_one_key(my_t)) {
        printf("leader one-key\n");
        SEND_STRING("leader one-key KC_T");
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(my_a)) {
        SEND_STRING("leader one-key A");
        did_leader_succeed = true;
   }
    /* else if (leader_sequence_two_keys(my_l, LOWER)) { */
    /*     layer_on(_LOWER); */
    /*     printf("leader lowerA\n"); */
    /*     did_leader_succeed = true; */
    /* } else if (leader_sequence_two_keys(my_l, RAISE)) { */
    /*     layer_on(_RAISE); */
    /*     printf("leader raise\n"); */
    /*     did_leader_succeed = true; */
    /* } else if (leader_sequence_two_keys(my_l, my_left_shift)) { */
    /*     printf("leader shiftlock\n"); */
    /*     layer_on(_SHIFTLOCK); */
    /*     did_leader_succeed = true; */
    /* } else if (leader_sequence_two_keys(my_l, my_m)) { */
    /*     printf("leader mouse\n"); */
    /*     layer_on(_MOUSE); */
    /*     did_leader_succeed = true; */
    /* } else if (leader_sequence_two_keys(my_e, my_d)) { */
    /*     printf("leader two-key\n"); */
    /*     /\* SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c")); *\/ */
    /*     did_leader_succeed = true; */
    /* } else if (leader_sequence_two_keys(my_s, my_a)) { */
    /*     tap_code16(KC_BACKSPACE); */
    /*     tap_code16(KC_BACKSPACE); */
    /*     /\* save_all_then_goto_base(); *\/ */

    /* } */

    if (did_leader_succeed) {
    } else {
#ifdef AUDIO_ENABLE
        /* SEND_STRING("leader fail"); */
        /* PLAY_SONG(caps_lock_off_sound); */
#endif
    }
}
