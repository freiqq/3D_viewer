#include "s21_settings_bonus.h"

void open_settings(settings_t* settings) {
  FILE* fp = fopen(
      "/Users/glenpoin/Projects/C/C8_3DViewer_v1.0-0-master/src/"
      "3D_Viewer_interface/settings.txt",
      "r");
  if (fp) {
    fscanf(fp, "line_width = %f\n", &(settings->line_width));
    fscanf(fp, "point_size = %f\n", &(settings->point_size));
    fscanf(fp, "dotted_line = %d\n", &(settings->dotted_line));
    fscanf(fp, "type_of_point = %d\n", &(settings->type_of_point));
    fscanf(fp, "color_of_line_r = %d\n", &(settings->color_of_line_r));
    fscanf(fp, "color_of_line_g = %d\n", &(settings->color_of_line_g));
    fscanf(fp, "color_of_line_b = %d\n", &(settings->color_of_line_b));
    fscanf(fp, "color_of_back_r = %d\n", &(settings->color_of_back_r));
    fscanf(fp, "color_of_back_r = %d\n", &(settings->color_of_back_g));
    fscanf(fp, "color_of_back_g = %d\n", &(settings->color_of_back_b));
    fscanf(fp, "color_of_point_g = %d\n", &(settings->color_of_point_r));
    fscanf(fp, "color_of_point_b = %d\n", &(settings->color_of_point_g));
    fscanf(fp, "color_of_point_b = %d\n", &(settings->color_of_point_b));
    fscanf(fp, "projection = %d\n", &(settings->projection));
    fclose(fp);
  }
}

void record_settings(settings_t settings) {
  FILE* fp = fopen(
      "/Users/glenpoin/Projects/C/C8_3DViewer_v1.0-0-master/src/"
      "3D_Viewer_interface/settings.txt",
      "w");
  if (fp) {
    fprintf(fp, "line_width = %f\n", settings.line_width);
    fprintf(fp, "point_size = %f\n", settings.point_size);
    fprintf(fp, "dotted_line = %d\n", settings.dotted_line);
    fprintf(fp, "type_of_point = %d\n", settings.type_of_point);
    fprintf(fp, "color_of_line_r = %d\n", settings.color_of_line_r);
    fprintf(fp, "color_of_line_g = %d\n", settings.color_of_line_g);
    fprintf(fp, "color_of_line_b = %d\n", settings.color_of_line_b);
    fprintf(fp, "color_of_back_r = %d\n", settings.color_of_back_r);
    fprintf(fp, "color_of_back_r = %d\n", settings.color_of_back_g);
    fprintf(fp, "color_of_back_g = %d\n", settings.color_of_back_b);
    fprintf(fp, "color_of_point_g = %d\n", settings.color_of_point_r);
    fprintf(fp, "color_of_point_b = %d\n", settings.color_of_point_g);
    fprintf(fp, "color_of_point_b = %d\n", settings.color_of_point_b);
    fprintf(fp, "projection = %d\n", settings.projection);
    fclose(fp);
  }
}