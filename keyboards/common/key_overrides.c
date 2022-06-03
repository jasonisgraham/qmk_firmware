const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t return_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_J, KC_ENTER);
const key_override_t bspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_H, KC_BSPC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
&return_key_override,
                                                                  &bspace_key_override,
                                                                  &delete_key_override,
                                                                  NULL // Null terminate the array of overrides!
};
