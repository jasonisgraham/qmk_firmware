
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {166,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {170,255,255}, {208,134,255}, {208,134,255}, {170,255,255}, {0,0,0}, {85,255,255}, {0,0,0}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,116}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,110,255}, {0,110,255}, {88,255,255}, {0,110,255}, {0,110,255}, {0,110,255}, {0,110,255}, {86,255,255}, {0,110,255}, {0,0,0}, {208,134,255}, {208,134,255}, {0,255,255}, {88,255,255}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {166,255,255}, {0,0,0}, {115,129,130}, {167,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,0,0}, {170,255,255}, {85,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,206,255}, {85,255,255}, {0,255,255}, {0,0,0}, {167,242,168}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {208,255,255}, {170,255,255}, {170,255,255}, {129,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {91,255,255}, {91,255,255}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {164,6,247}, {164,6,247}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {208,255,255}, {208,255,255}, {208,255,255} },

    [4] = { {169,255,255}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {218,255,255}, {218,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {91,255,255}, {91,255,255}, {0,0,0}, {91,255,255}, {43,255,255}, {43,255,255}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {208,255,255}, {208,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {172,255,255}, {208,255,255}, {208,255,255}, {208,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {170,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {234,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {41,255,255}, {41,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {219,255,255}, {219,255,255}, {219,255,255} },

    [6] = { {0,0,0}, {218,255,255}, {175,255,255}, {166,255,255}, {218,255,255}, {166,255,255}, {210,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {46,255,255}, {166,255,255}, {46,255,255}, {46,255,255}, {166,255,255}, {218,255,255}, {166,255,255}, {210,255,255}, {210,255,255}, {210,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {166,255,255}, {166,255,255}, {166,255,255}, {166,255,255}, {0,0,0}, {218,255,255}, {166,255,255}, {85,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {62,255,255}, {197,255,255}, {82,255,255}, {43,16,255}, {85,255,255}, {85,255,255}, {85,255,255}, {45,255,255}, {0,255,255} },

    [7] = { {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {218,255,255}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {88,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [10] = { {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {46,255,255}, {139,255,255}, {169,255,255}, {139,255,255}, {0,255,255}, {46,255,255}, {46,255,255}, {169,218,204} },

    [11] = { {175,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {220,168,159}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {175,255,255}, {175,255,255}, {175,255,255}, {220,168,159}, {175,255,255}, {220,168,159}, {220,168,159}, {220,168,159}, {0,255,255}, {40,255,255}, {0,255,255}, {129,255,255}, {220,168,159}, {220,168,159}, {40,255,255} },

    [12] = { {173,255,255}, {0,0,0}, {88,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {167,255,255}, {0,0,0}, {88,255,255}, {0,0,0}, {62,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {46,255,255}, {27,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [13] = { {175,255,255}, {0,0,0}, {0,207,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {175,255,255}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {62,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,207,255}, {0,207,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,207,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [14] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
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
    set_layer_color(7);
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
  case 12:
    set_layer_color(12);
    break;
  case 13:
    set_layer_color(13);
    break;
  case 14:
    set_layer_color(14);
    break;
  default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
