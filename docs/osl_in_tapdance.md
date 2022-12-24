## use-case: one-shot layers while tapdancing 
the super key behaves this way:
- single tap activates what looks like OSL for the _WINDOWS layer
- single hold acts as holding down the super key
- double tap activates what looks like OSL for _ROFI layer

## Determine which layers you only want to be treated as OSL.  
for me, i only need a single press after activating my "window selection" or "rofi" layer.
```
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  // i cant think of any use case where id want to keep these layers active after 1st key.
  // these layers are only used as OSLs
  if (layer_state_is(_WINDOWS) || layer_state_is(_ROFI)) {
    layer_move(_BASE);
  }
}
```
we're ensuring that after a keycode is processed, the active layer is resolved to base layer.

## how to achieve
### tapdance fns: lets assign these _WINDOWS and _ROFI layer events here
```
void on_dance_super(qk_tap_dance_state_t *state, void *user_data) {}

void dance_super_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[85].step = dance_step(state);
  switch (dance_state[85].step) {
  case TAP:
    layer_on(_WINDOWS);
    break;

  case TAP2:
  case HOLD2:
    layer_on(_ROFI);
    break;

  case HOLD:
  default:
    // hold down SUPER cuz i dont wanna explicitly apply SUPER to every key
    register_code16(KC_LGUI);
    layer_on(_SUPER);
    break;
  }
}

void dance_super_reset(qk_tap_dance_state_t *state, void *user_data) {
  // layer_off(_ROFI) and layer_off(_ROFI) are handled by post_process_record_user
  switch (dance_state[85].step) {
  case TAP:
  case TAP2:
  case HOLD2:
    break;

  case HOLD:
  default:
    unregister_code16(KC_LGUI);
    layer_off(_SUPER);
    break;
  }
  dance_state[85].step = 0;
}
```
and add this to `qk_tap_dance_action_t tap_dance_actions[] = {...}` where `...` includes an element like
```
[DANCE_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_super, dance_super_finished, dance_super_reset),

```

### assign this tapdance to the super key 
#define my_super TD(DANCE_SUPER)


## results
- tap super does a OSL for a layer (_WINDOWS in this case) 
- holding super acts as a default super key
- double tapping does a OSL for another layer (_ROFI in this case)
