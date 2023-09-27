#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2] = SONG(RICK_ROLL);
#endif

void leader_start_user(void) {
#ifdef AUDIO_ENABLE
  PLAY_SONG(leader_start_song);
#endif
}

void leader_end_user(void) {
  bool did_leader_succeed = false;

  if (leader_sequence_one_key(KC_E)) {
    SEND_STRING(SS_LCTL(SS_LSFT("t")));
    did_leader_succeed = true;
  } else if (leader_sequence_two_keys(KC_E, KC_D)) {
    SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
    did_leader_succeed = true;
  }

#ifdef AUDIO_ENABLE
  if (did_leader_succeed) {
    PLAY_SONG(leader_succeed_song);
  } else {
    PLAY_SONG(leader_fail_song);
  }
#endif
}
