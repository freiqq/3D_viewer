#ifndef C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_PARSERS_H_
#define C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_PARSERS_H_

#include <stdio.h>

#include "s21_common.h"

void quantity_parser(data_t* data, FILE* fp);
void polygon_parser(data_t* data, FILE* f);
void vertex_parser(data_t* data, char* str, int increment);
void facet_parser(data_t* data, char* str, int* increment);

#endif  //  C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_PARSERS_H_