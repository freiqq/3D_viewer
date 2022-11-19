#include "viewer.h"

#include "ui_viewer.h"

viewer::viewer(QWidget* parent) : QOpenGLWidget(parent) {
  setGeometry(0, 0, 700, 700);
}

void viewer::initializeGL() { glEnable(GL_DEPTH_TEST); }

void viewer::resizeGL(int w, int h) {
  if (count_of_facets > 0) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  }
}

void viewer::find_limit_values() {
  max_x = source_vertexes[0];
  max_y = source_vertexes[1];
  max_z = source_vertexes[2];
  min_x = source_vertexes[0];
  min_y = source_vertexes[1];
  min_z = source_vertexes[2];
  for (int i = 0; i < count_of_vertex * 3; i += 3) {
    if (source_vertexes[i] > max_x) max_x = source_vertexes[i];
    if (source_vertexes[i + 1] > max_y) max_y = source_vertexes[i + 1];
    if (source_vertexes[i + 2] > max_z) max_z = source_vertexes[i + 2];
    if (source_vertexes[i] < min_x) min_x = source_vertexes[i];
    if (source_vertexes[i + 1] < min_y) min_y = source_vertexes[i + 1];
    if (source_vertexes[i + 2] < min_y) min_y = source_vertexes[i + 2];
  }

  p_x = (min_x + max_x) / 2.0;
  p_y = (min_y + max_y) / 2.0;
  p_z = (min_z + max_z) / 2.0;
  frontier =
      sqrt((max_x - p_x) * (max_x - p_x) + (max_y - p_y) * (max_y - p_y) +
           (max_z - p_z) * (max_z - p_z));
  distance = frontier / 0.57735;
  near = distance - frontier;
  far = distance + frontier;
}

void viewer::paintGL() {
  glClearColor((double)color_of_back_r / 255.0, (double)color_of_back_g / 255.0,
               (double)color_of_back_b / 255.0, 0);
  if (count_of_facets > 0) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspective) {
      glFrustum(-frontier, frontier, -frontier, frontier, max_z * 0.8,
                max_z * 50);
    } else {
      glOrtho(-frontier, frontier, -frontier, frontier, max_z * 0.8,
              max_z * 10);
    }
    glTranslatef(-p_x, -p_y, -(max_z * 3));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    draw_model();
  }
}

void viewer::draw_model() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLineWidth(line_width);
  if (dotted_line == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  }

  affine_transformation(source_vertexes, vertexes, count_of_vertex, x, y, z,
                        angle_x, angle_y, angle_z, scale_of_object, max_z);
  glVertexPointer(3, GL_FLOAT, 0, vertexes);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColor3d((double)color_of_line_r / 255, (double)color_of_line_g / 255,
            (double)color_of_line_b / 255);
  glDrawElements(GL_LINES, size_of_facets * 2, GL_UNSIGNED_INT, facets);
  draw_points();
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_DEPTH_BUFFER_BIT | GL_LINE_STIPPLE);
}

void viewer::draw_points() {
  glPointSize(point_size);
  glColor3f((double)color_of_point_r / 255, (double)color_of_point_g / 255,
            (double)color_of_point_b / 255);
  if (type_of_point == 1) {
    glEnable(GL_QUADS);
    glDrawArrays(GL_POINTS, 0, count_of_vertex - 1);
    glDisable(GL_QUADS);
  } else if (type_of_point == 2) {
    glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, count_of_vertex - 1);
    glDisable(GL_POINT_SMOOTH);
  }
}

viewer::~viewer() { free(vertexes); }