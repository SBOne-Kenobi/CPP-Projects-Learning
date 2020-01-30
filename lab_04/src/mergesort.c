#include "mergesort.h"

void my_memcpy(void* dest, const void* source, size_t bytes) {
	for (size_t i = 0; i < bytes; ++i)
		((char*)dest)[i] = ((char*)source)[i]; 
}

int merge(void* array1, size_t elements1, void* array2, size_t elements2, void* dest, size_t element_size, comparator cmp) {
	elements1 *= element_size;
	elements2 *= element_size;
	void* ans = malloc(elements1 + elements2);
	if (ans == NULL)
		return -1;
	size_t j = 0;
	for (size_t i = 0; i < elements1; i += element_size) {
		while (j < elements2 && cmp(array2 + j, array1 + i) < 0) {
			my_memcpy(ans + i + j, array2 + j, element_size);
			j += element_size;
		}
		my_memcpy(ans + i + j, array1 + i, element_size);
	}
	my_memcpy(ans + elements1 + j, array2 + j, elements2 - j);
	my_memcpy(dest, ans, elements1 + elements2);
	free(ans);
	return 0;
}

int mergesort(void* array, size_t elements, size_t element_size, comparator cmp) {
	if (elements == 1)
		return 0;
	size_t m = elements >> 1;
	if (mergesort(array, m, element_size, cmp) == -1)
		return -1;
	if (mergesort(array + m * element_size, elements - m, element_size, cmp) == -1)
		return -1;
	if (merge(array, m, array + m * element_size, elements - m, array, element_size, cmp))
		return -1;
	return 0;
}
