#ifndef VIEWER_H
#define VIEWER_H
#define GL_SILENCE_DEPRECAION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QMouseEvent>
#include <QWidget>
#include <QtOpenGLWidgets/QOpenGLWidget>

#ifdef __cplusplus
extern "C" {
#endif
#include "../3D_Viewer_backend/s21_affine_transformations.h"
#include "../3D_Viewer_backend/s21_common.h"
#include "../3D_Viewer_backend/s21_settings_bonus.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class viewer;
}

class viewer : public QOpenGLWidget {
  Q_OBJECT
  ~viewer();

 private:
  int init = 0;

  int x = 0;
  int y = 0;
  int z = 0;
  float max_x;
  float max_y;
  float max_z;
  float min_x;
  float min_y;
  float min_z;
  float p_x;
  float p_y;
  float p_z;

  float frontier;
  float distance;
  float near;
  float far;

  double angle_x = 0;
  double angle_y = 0;
  double angle_z = 0;
  double scale_of_object = 1;
  char file_name_str[1024];
  int count_of_vertex = 0;
  int count_of_facets = 0;
  int size_of_facets = 0;
  float* vertexes = NULL;
  float* source_vertexes = NULL;
  int* facets = NULL;
  int* source_facets = NULL;
  // bonus
  int perspective = 0;

  float line_width = 1;
  float point_size = 5;
  int dotted_line = 0;
  int type_of_point = 0;

  int color_of_line_r = 255;
  int color_of_line_g = 255;
  int color_of_line_b = 255;

  int color_of_back_r = 42;
  int color_of_back_g = 43;
  int color_of_back_b = 42;

  int color_of_point_r = 0;
  int color_of_point_g = 255;
  int color_of_point_b = 255;

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void draw_model();
  void draw_points();
  void find_limit_values();

 public:
  explicit viewer(QWidget* parent = nullptr);

  // core
  void set_data(data_t data);
  void set_angle_x(double angle_x);
  void set_angle_y(int angle_y);
  void set_angle_z(int angle_z);
  void set_coordinate_x(int coordinate_x);
  void set_coordinate_y(int coordinate_y);
  void set_coordinate_z(int coordinate_z);
  void set_scale(double scale);

  // bonus
  void set_projection_type(int projection_type);

  void set_type_of_line(int type_of_line);
  void set_type_of_point(int point_type);
  void set_line_width(double width);
  void set_point_size(double size);

  void set_color_line_r(int r);
  void set_color_line_g(int g);
  void set_color_line_b(int b);

  void set_color_back_r(int r);
  void set_color_back_g(int g);
  void set_color_back_b(int b);

  void set_color_point_r(int r);
  void set_color_point_g(int g);
  void set_color_point_b(int b);

 private:
  Ui::viewer* ui;
};
#endif  // VIEWER_H
