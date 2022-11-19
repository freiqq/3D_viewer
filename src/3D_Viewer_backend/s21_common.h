#ifndef C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_COMMON_H_
#define C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_COMMON_H_

typedef struct data {
  int count_of_vertexes;
  int count_of_facets;
  int size_of_facets;
  int* facets;
  float* vertexes;
} data_t;

#endif  //  C8_3D_VIEWER_3D_VIEWER_BACKEND_S_21_COMMON_H_