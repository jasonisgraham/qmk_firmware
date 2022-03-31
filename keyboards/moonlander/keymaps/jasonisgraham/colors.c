extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,0,0}, {43,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {42,255,255}, {43,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {42,255,255}, {43,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {74,255,255}, {43,255,255}, {74,255,255}, {41,255,255}, {74,255,255}, {86,255,255}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {88,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {139,126,248}, {0,0,0}, {152,255,255}, {0,245,245}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {0,245,245}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,245,245}, {0,110,255}, {0,0,0}, {0,0,0}, {0,0,0}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {41,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {41,255,255}, {129,255,255}, {74,255,255}, {74,255,255}, {42,255,255}, {41,255,255}, {167,255,255}, {0,0,0}, {0,245,245}, {42,255,255}, {41,255,255}, {0,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {74,255,255}, {167,242,168}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {167,255,255}, {41,255,255}, {0,0,0}, {0,245,245}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {74,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {218,255,255}, {41,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {218,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,189,255}, {0,0,0}, {0,0,0}, {234,255,255}, {219,255,255}, {152,255,255}, {0,0,0}, {234,255,255}, {234,255,255}, {219,255,255}, {41,255,255}, {41,255,255}, {129,255,255}, {234,255,255}, {219,255,255}, {41,255,255}, {41,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {46,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {189,255,255}, {46,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {46,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {210,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {152,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {167,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {167,255,255}, {0,0,0}, {167,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {42,255,255}, {42,255,255}, {170,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {42,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {42,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {42,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,0,0}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {27,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {218,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {218,255,255}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {0,0,0}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {139,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {42,255,255}, {0,255,255}, {42,255,255}, {170,255,255}, {42,255,255}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {170,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {42,255,255}, {42,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {42,255,255}, {0,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {139,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255} },

    [10] = { {175,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {175,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {175,255,255}, {129,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {37,255,255}, {0,0,0}, {0,0,0}, {129,255,255} },

    [11] = { {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {81,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {197,255,255}, {0,0,0}, {175,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {27,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {89,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {82,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [12] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [13] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}
int p = 0;
#include "../../../../quantum/hacks.c"
void rgb_matrix_indicators_user(void) {
  /* if (g_suspend_state || keyboard_config.disable_layer_led) { return; } */
  if (p != use_only_base_layer_combos) {
    char s[3];
    itoa(use_only_base_layer_combos, s, 10);
    SEND_STRING(s);
    p = use_only_base_layer_combos;
  }

  switch (biton32(layer_state)) {
  case 0:
#undef use_only_base_layer_combos
#define use_only_base_layer_combos 0


    break;

    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      /* rgblight_mode(RGB_MATRIX_DIGITAL_RAIN); */
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
    case 10:
      set_layer_color(10);
      break;
    case 11:
      set_layer_color(11);
      break;
  case 13:
    set_layer_color(13);
    break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
