#ifndef C8_3D_VIEWER_3D_VIEWER_BACKEND_MEMORY_HANDLING_H_
#define C8_3D_VIEWER_3D_VIEWER_BACKEND_MEMORY_HANDLING_H_

#include <stdlib.h>

#include "s21_common.h"

int allocate_memory(data_t* data);
int free_memory(data_t* data);

#endif  //  C8_3D_VIEWER_3D_VIEWER_BACKEND_MEMORY_HANDLING_H_