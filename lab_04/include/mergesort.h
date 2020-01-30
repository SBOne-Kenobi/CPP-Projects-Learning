#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#include <stddef.h>
#include <stdlib.h>

typedef int (*comparator)(const void*, const void*);

int mergesort(void* array, size_t elements, size_t element_size, comparator cmp);

#endif
