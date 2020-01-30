#include "mergesort.h"
#include <string.h>
#include <stdio.h>

int cmp_int(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}

int cmp_char(const void* a, const void* b) {
	return *(const char*)a - *(const char*)b;
}

int cmp_str(const void* a, const void* b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char **argv) {
	if (argc - 2 > 0) {
		if (strcmp(argv[1], "int") == 0) {
			int* array = malloc(sizeof(int) * (argc - 2));
			if (array == NULL) {
				printf("Error: memory allocation failed.\n");
				return 1;
			}
			for (int i = 0; i < argc - 2; i++)
				sscanf(argv[i + 2], "%d", array + i);
			if (mergesort(array, argc - 2, sizeof(int), cmp_int) == -1) {
				printf("Error: memory allocation failed.\n");
				free(array);
				return 1;
			}
			for (int i = 0; i < argc - 2; i++)
				printf("%d ", array[i]);
			free(array);
		} else if (strcmp(argv[1], "char") == 0) {
			char* array = malloc(sizeof(char) * (argc - 2));
			if (array == NULL) {
				printf("Error: memory allocation failed.\n");
				return 1;
			}
			for (int i = 0; i < argc - 2; i++)
				sscanf(argv[i + 2], "%c", array + i);
			if (mergesort(array, argc - 2, sizeof(char), cmp_char) == -1) {
				printf("Error: memory allocation failed.\n");
				free(array);
				return 1;
			}
			for (int i = 0; i < argc - 2; i++)
				printf("%c ", array[i]);
			free(array);
		} else if (strcmp(argv[1], "str") == 0) {
			char** array = malloc(sizeof(char*) * (argc - 2));
			if (array == NULL) {
				printf("Error: memory allocation failed.\n");\
				return 1;
			}
			for (int i = 0; i < argc - 2; i++) {
				array[i] = malloc(sizeof(char*) * strlen(argv[i + 2]));
				if (array[i] == NULL) {
					printf("Error: memory allocation failed.\n");
					for (int j = 0; j <= i; j++)
						free(array[j]);
					free(array);
					return 1;
				}
				strcpy(array[i], argv[i + 2]);
			}
			if (mergesort(array, argc - 2, sizeof(char*), cmp_str) == -1) {
				printf("Error: memory allocation failed.\n");
				for (int i = 0; i < argc - 2; i++)
					free(array[i]);
				free(array);
				return 1;
			}
			for (int i = 0; i < argc - 2; i++) {
				printf("%s ", array[i]);
				free(array[i]);
			}
			free(array);
		}
	}
	printf("\n");
	return 0;
}
