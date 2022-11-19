#include "viewer.h"

void viewer::set_data(data_t data) {
  count_of_vertex = data.count_of_vertexes;
  count_of_facets = data.count_of_facets;
  size_of_facets = data.size_of_facets;
  source_vertexes = data.vertexes;
  facets = data.facets;
  vertexes = (float*)calloc(count_of_vertex * 4 + 1, sizeof(float));
  init = 1;
  find_limit_values();
  update();
}

void viewer::set_angle_x(double arg1) {
  angle_x = arg1;
  update();
}

void viewer::set_angle_y(int arg1) {
  angle_y = arg1;
  update();
}

void viewer::set_angle_z(int arg1) {
  angle_z = arg1;
  update();
}

void viewer::set_coordinate_x(int coordinate_x) {
  x = coordinate_x;
  update();
}

void viewer::set_coordinate_y(int coordinate_y) {
  y = coordinate_y;
  update();
}

void viewer::set_coordinate_z(int coordinate_z) {
  z = coordinate_z;
  update();
}

void viewer::set_scale(double scale) {
  scale_of_object = scale;
  update();
}

void viewer::set_type_of_line(int type_of_line) {
  dotted_line = type_of_line;
  update();
}

void viewer::set_type_of_point(int point_type) {
  type_of_point = point_type;
  update();
}

void viewer::set_projection_type(int projection_type) {
  perspective = projection_type;
  update();
}

void viewer::set_line_width(double width) {
  line_width = (GLfloat)width;
  update();
}

void viewer::set_point_size(double size) {
  point_size = (GLfloat)size * 3;
  update();
}

void viewer::set_color_line_r(int r) {
  color_of_line_r = r;
  update();
}

void viewer::set_color_line_g(int g) {
  color_of_line_g = g;
  update();
}

void viewer::set_color_line_b(int b) {
  color_of_line_b = b;
  update();
}

void viewer::set_color_back_r(int r) {
  color_of_back_r = r;
  update();
}

void viewer::set_color_back_g(int g) {
  color_of_back_g = g;
  update();
}

void viewer::set_color_back_b(int b) {
  color_of_back_b = b;
  update();
}

void viewer::set_color_point_r(int r) {
  color_of_point_r = r;
  update();
}

void viewer::set_color_point_g(int g) {
  color_of_point_g = g;
  update();
}

void viewer::set_color_point_b(int b) {
  color_of_point_b = b;
  update();
}