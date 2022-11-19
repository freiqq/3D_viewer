#ifndef C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_SETTINGS_BONUS_H_
#define C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_SETTINGS_BONUS_H_

#include <stdio.h>

typedef struct s21_settings_bonus {
  float line_width;
  float point_size;
  int dotted_line;
  int type_of_point;
  int color_of_line_r;
  int color_of_line_g;
  int color_of_line_b;
  int color_of_back_r;
  int color_of_back_g;
  int color_of_back_b;
  int color_of_point_r;
  int color_of_point_g;
  int color_of_point_b;
  int projection;
} settings_t;

void open_settings(settings_t* settings);

void record_settings(settings_t settings);

#endif  //  C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_SETTINGS_BONUS_H_