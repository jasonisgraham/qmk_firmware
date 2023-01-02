#include "../../../common/drop_keymap.c"
/* #include "../../../common/drop_colors.c" */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

[_BASE] = LAYOUT_wrapper(planck_base),

[_RAISE] = LAYOUT_wrapper(planck_raise),

[_SHIFTLOCK] = LAYOUT_wrapper(planck_shiftlock),


[_LOWER] = LAYOUT_wrapper(planck_lower),



[_ROFI] = LAYOUT_wrapper(planck_rofi                             ),

[_EMACS] = LAYOUT_wrapper(
planck_emacs
                                ),

[_SA] = LAYOUT_wrapper(
planck_sa
                            ),


[_MOUSE] = LAYOUT_wrapper(
planck_mouse),


// 11
[_SUPER] = LAYOUT_wrapper(
planck_super                              ),



// 12
[_EDITING] = LAYOUT_wrapper(
planck_editing
                                ),
// 9
[_WINMOVE] = LAYOUT_wrapper(
planck_winmove                                ),

// 4
[_ALL_MODS] = LAYOUT_wrapper(
planck_all_mods
                              ),


[_SYSTEM] = LAYOUT_wrapper(planck_system),

// 6
[_WINDOWS] = LAYOUT_wrapper(planck_windows
                                ),

// 7
[_MACROS] = LAYOUT_wrapper(
planck_macros                              ),

[_ADHOC_SET_HOTKEY] = LAYOUT_wrapper(
planck_adhoc_set_key                              ),

[_HYPER] = LAYOUT_wrapper(
planck_hyper                                         )
  };


/* extern bool g_suspend_state; */
/* extern rgb_config_t rgb_matrix_config; */


/* void keyboard_post_init_user(void) { */
/*   rgb_matrix_enable(); */
/* } */

/* const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = { */
/*     [1] = { {166,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {170,255,255}, {208,134,255}, {208,134,255}, {170,255,255}, {0,0,0}, {85,255,255}, {0,0,0}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,116}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,110,255}, {0,110,255}, {88,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {0,110,255}, {0,0,0}, {208,134,255}, {208,134,255}, {0,255,255}, {88,255,255}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} }, */

/*     [2] = { {166,255,255}, {0,0,0}, {115,129,130}, {167,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,0,0}, {170,255,255}, {85,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,255,255}, {0,0,0}, {167,242,168}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {170,255,255}, {170,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0} }, */
/* }; */

/* void set_layer_color(int layer) { */
/*   for (int i = 0; i < DRIVER_LED_TOTAL; i++) { */
/*     HSV hsv = { */
/*       .h = pgm_read_byte(&ledmap[layer][i][0]), */
/*       .s = pgm_read_byte(&ledmap[layer][i][1]), */
/*       .v = pgm_read_byte(&ledmap[layer][i][2]), */
/*     }; */
/*     if (!hsv.h && !hsv.s && !hsv.v) { */
/*         rgb_matrix_set_color( i, 0, 0, 0 ); */
/*     } else { */
/*         RGB rgb = hsv_to_rgb( hsv ); */
/*         float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX; */
/*         rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b ); */
/*     } */
/*   } */
/* } */

/* bool rgb_matrix_indicators_user(void) { */
/*   /\* if (g_suspend_state || keyboard_config.disable_layer_led) { return false; } *\/ */
/*   switch (biton32(layer_state)) { */
/*     case 1: */
/*       set_layer_color(1); */
/*       break; */
/*     case 2: */
/*       set_layer_color(2); */
/*       break; */
/*    default: */
/*     if (rgb_matrix_get_flags() == LED_FLAG_NONE) */
/*       rgb_matrix_set_color_all(0, 0, 0); */
/*     break; */
/*   } */
/*   return false; */
/* } */
