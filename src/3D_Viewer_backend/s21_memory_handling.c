#include "s21_memory_handling.h"

int allocate_memory(data_t* data) {
  int status = 1;
  if (data->size_of_facets > 0 && data->count_of_vertexes > 0) {
    data->facets = (int*)calloc(data->size_of_facets * 2, sizeof(int));
    data->vertexes =
        (float*)calloc((data->count_of_vertexes * 4) + 1, sizeof(float));
    if (!(data->facets) || !(data->vertexes)) {
      status = 0;
    }
  } else {
    status = 0;
  }
  return status;
}

int free_memory(data_t* data) {
  int status = 0;
  if (data->facets && data->vertexes) {
    free(data->facets);
    free(data->vertexes);
    status = 1;
  }
  return status;
}
