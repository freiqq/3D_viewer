#include "s21_affine_transformations.h"

void rotation_on_axis_x(float* vertexes, int count_of_vertexes, double angle,
                        int increment) {
  angle = 6.28 * angle / 360;
  float y = vertexes[increment + 1];
  float z = vertexes[increment + 2];
  vertexes[increment + 1] = y * cos(angle) + z * sin(angle);
  vertexes[increment + 2] = -y * sin(angle) + z * cos(angle);
}

void rotation_on_axis_y(float* vertexes, int count_of_vertexes, double angle,
                        int increment) {
  angle = 6.28 * angle / 360;
  float x = vertexes[increment];
  float z = vertexes[increment + 2];
  vertexes[increment] = x * cos(angle) + z * sin(angle);
  vertexes[increment + 2] = -x * sin(angle) + z * cos(angle);
}

void rotation_on_axis_z(float* vertexes, int count_of_vertexes, double angle,
                        int increment) {
  angle = 3.14 * angle / 180;
  float x = vertexes[increment];
  float y = vertexes[increment + 1];
  vertexes[increment] = x * cos(angle) + y * sin(angle);
  vertexes[increment + 1] = -x * sin(angle) + y * cos(angle);
}

void affine_transformation(float* source_vertexes, float* vertexes,
                           int count_of_vertexes, int x, int y, int z,
                           double angle_x, double angle_y, double angle_z,
                           double scale, double max_z) {
  for (int i = 0; i < count_of_vertexes * 3; i += 3) {
    vertexes[i] = source_vertexes[i];
    vertexes[i + 1] = source_vertexes[i + 1];
    vertexes[i + 2] = source_vertexes[i + 2];
    rotation_on_axis_x(vertexes, count_of_vertexes, angle_x, i);
    rotation_on_axis_y(vertexes, count_of_vertexes, angle_y, i);
    rotation_on_axis_z(vertexes, count_of_vertexes, angle_z, i);
    vertexes[i] = (vertexes[i] + (float)x / 25 * max_z) * scale;
    vertexes[i + 1] = (vertexes[i + 1] + (float)y / 25 * max_z) * scale;
    vertexes[i + 2] = (vertexes[i + 2] + (float)z / 25 * max_z) * scale;
  }
}