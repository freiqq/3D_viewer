#include "s21_parsers.h"

void quantity_parser(data_t* data, FILE* fp) {
  char str[1024];
  data->count_of_vertexes = 1;
  data->count_of_facets = 1;
  data->size_of_facets = 0;
  while (fgets(str, 1024, fp) != NULL) {
    if (str[0] == 'v' && str[1] == ' ') {
      data->count_of_vertexes += 1;
    } else if (str[0] == 'f' && str[1] == ' ') {
      data->count_of_facets += 1;
      for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] == ' ') {
          data->size_of_facets += 1;
        }
      }
    }
  }
}

void polygon_parser(data_t* data, FILE* f) {
  int i = 0;
  int j = 0;
  fseek(f, 0, SEEK_SET);
  char str[1024];
  while (fgets(str, 1024, f) != NULL) {
    if (str[0] == 'v' && str[1] == ' ') {
      vertex_parser(data, str, i);
      i += 3;
    } else if (str[0] == 'f' && str[1] == ' ') {
      facet_parser(data, str, &j);
    }
  }
}

void vertex_parser(data_t* data, char* str, int increment) {
  double x, y, z;
  sscanf(str, "v %lf %lf %lf", &x, &y, &z);
  data->vertexes[increment] = x;
  data->vertexes[increment + 1] = y;
  data->vertexes[increment + 2] = z;
}

void facet_parser(data_t* data, char* str, int* increment) {
  int facet;
  int temp_facet_begin;
  int n = 0;
  for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      sscanf(&(str[i]), "%d", &facet);
      data->facets[*increment] = facet - 1;
      (*increment)++;
      if (n == 0) {
        temp_facet_begin = facet;
      } else if (n == 2) {
        data->facets[*increment] = facet - 1;
        (*increment)++;
        data->facets[*increment] = temp_facet_begin - 1;
        (*increment)++;
        n = 0;
      } else {
        data->facets[*increment] = facet - 1;
        (*increment)++;
      }
      n++;
    }
  }
}
