#ifndef C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_AFFINE_TRANSFORMATIONS_H_
#define C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_AFFINE_TRANSFORMATIONS_H_

#include <math.h>
#include <stdio.h>

#include "s21_common.h"

void rotation_on_axis_x(float* vertexes, int count_of_vertexes, double angle,
                        int increment);
void rotation_on_axis_y(float* vertexes, int count_of_vertexes, double angle,
                        int increment);
void rotation_on_axis_z(float* vertexes, int count_of_vertexes, double angle,
                        int increment);

void affine_transformation(float* source_vertexes, float* vertexes,
                           int count_of_vertexes, int x, int y, int z,
                           double angle_x, double angle_y, double angle_z,
                           double scale, double max_z);

#endif  //  C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_AFFINE_TRANSFORMATIONS_H_
