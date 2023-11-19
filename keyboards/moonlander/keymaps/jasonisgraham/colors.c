extern rgb_config_t rgb_matrix_config;

#define HYPER_LEDMAP                  \
    {{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE},{HSV_WHITE}}

#define SHIFTLOCK_LAYER_LEDMAP                  \
  {{HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE},                     \
   {HSV_RED}, {HSV_WHITE}}

#define WINDOWS { \
    {HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},         \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE},             \
{HSV_RED}, {HSV_YELLOW}, {HSV_PURPLE}}


void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255} },

    [2] = { {169,255,255}, {169,255,255}, {218,218,204}, {48,255,255}, {169,255,255}, {169,255,255}, {218,218,204}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {48,255,255}, {218,218,204}, {169,255,255}, {169,255,255}, {169,255,255}, {128,255,255}, {218,218,204}, {169,255,255}, {169,255,255}, {0,255,255}, {218,218,204}, {218,218,204}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,255}, {128,255,255}, {128,255,255}, {169,255,255}, {169,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {169,255,255}, {169,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {169,255,255}, {169,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {169,255,255}, {169,255,255}, {128,255,255}, {168,218,204}, {128,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255} },

    [3] = SHIFTLOCK_LAYER_LEDMAP,

    [4] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {168,218,204}, {168,218,204}, {0,255,255}, {0,255,255}, {218,180,255}, {218,218,204}, {48,255,255}, {0,255,255}, {0,255,255}, {48,255,255}, {218,218,204}, {48,255,255}, {0,255,255}, {0,255,255}, {48,255,255}, {218,218,204}, {86,255,255}, {0,255,255}, {0,255,255}, {218,180,255}, {218,218,204}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

    [5] = { {250,218,204}, {86,255,255}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {197,255,255}, {86,255,255}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {197,255,255}, {197,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255} },

    [7] = { {53,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,255}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {53,255,255}, {0,0,255}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {53,255,255}, {53,255,255}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {53,255,255}, {0,0,0}, {0,0,0}, {53,255,255}, {0,0,0}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {53,255,255}, {53,255,255}, {0,0,0}, {0,0,0}, {53,255,255}, {0,0,0}, {53,255,255}, {53,255,255}, {0,0,0}, {0,0,255}, {53,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {139,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {0,0,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,0}, {139,255,255}, {0,0,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {139,255,255}, {139,255,255}, {0,0,0}, {139,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {139,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,255}, {139,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {250,218,204}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {197,255,255}, {0,0,0}, {250,218,204}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [10] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {168,218,204}, {95,218,204}, {0,0,0}, {0,0,0}, {218,180,255}, {95,218,204}, {95,218,204}, {0,0,0}, {0,0,0}, {86,255,255}, {168,218,204}, {95,218,204}, {197,255,255}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {218,180,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {0,0,0}, {0,0,0}, {86,255,255}, {218,255,255}, {168,218,204}, {0,255,255}, {0,0,0}, {218,180,255}, {218,255,255}, {95,218,204}, {0,255,255}, {0,0,0}, {86,255,255}, {218,255,255}, {95,218,204}, {0,0,0}, {0,0,0}, {218,180,255}, {218,255,255}, {168,218,204}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {86,255,255}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [11] = { {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {53,255,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {53,255,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {86,255,255}, {218,103,255}, {218,103,255}, {53,255,255}, {53,255,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255}, {218,103,255} },

    [12] = { {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255} },

    [13] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {0,0,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {139,255,255}, {128,255,255}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,255}, {48,255,255}, {218,103,255}, {48,255,255}, {86,255,255}, {139,255,255}, {0,0,0}, {197,255,255}, {86,255,255}, {86,255,255}, {0,0,255}, {128,255,255}, {128,255,255}, {128,255,255}, {86,255,255}, {139,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {139,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [14] = { {0,255,255}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {218,255,255}, {218,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {95,218,204}, {95,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {46,218,204}, {46,218,204}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [15] = WINDOWS,

    [16] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {86,255,255}, {218,180,255}, {0,0,0}, {0,0,0}, {218,180,255}, {218,180,255}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,180,255}, {218,180,255}, {218,180,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [17] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {250,218,204}, {250,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {250,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {172,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {250,218,204}, {250,218,204}, {250,218,204}, {0,0,0}, {0,255,255}, {250,218,204}, {250,218,204}, {250,218,204}, {0,0,0}, {172,255,255}, {250,218,204}, {250,218,204}, {250,218,204}, {0,0,0}, {0,255,255}, {250,218,204}, {250,218,204}, {250,218,204}, {0,0,0}, {172,255,255}, {250,218,204}, {0,0,0}, {250,218,204}, {0,0,0}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [18] = HYPER_LEDMAP,

    [19] = { {0,0,0}, {0,0,0}, {48,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {46,156,130}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [20] = { {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,129,255}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [21] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {0,0,0}, {168,218,204}, {0,0,0}, {0,0,0}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [22] = { {172,218,255}, {216,255,255}, {86,255,255}, {216,255,255}, {216,255,255}, {86,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {0,0,255}, {86,255,255}, {216,255,255}, {216,255,255}, {0,0,255}, {0,0,255}, {86,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {0,0,255}, {216,255,255}, {216,255,255}, {216,255,255}, {86,255,255}, {139,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255}, {216,255,255} },

    [24] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {218,218,204}, {218,218,204}, {218,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {250,218,204}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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


bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) { return false; }

    /* dprintf("biton32(layer_state): %u\n", biton32(layer_state)); */
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
    case 8:
      set_layer_color(8);
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
    case 15:
      set_layer_color(15);
      break;
    case 16:
      set_layer_color(16);
      break;
    case 17:
      set_layer_color(17);
      break;
    case 18:
      set_layer_color(18);
      break;
    case 19:
      set_layer_color(19);
      break;
    case 20:
      set_layer_color(20);
      break;
    case 21:
      set_layer_color(21);
      break;
    case 22:
      set_layer_color(22);
      break;
    case 24:
      set_layer_color(24);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}
