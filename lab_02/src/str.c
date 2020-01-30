#include "str.h"

char* my_strcpy(char* str1, const char* str2) {
	char* p = str1;
	while (*str2) {
		*(p++) = *(str2++);
	}
	*p = *str2;
	return str1;
}

size_t my_strlen(const char* str) {
	const char* p = str;
	while (*(p++));
	return (size_t)(p - str - 1);
}

char* my_strcat(char* str1, const char* str2) {
	char* p = str1 + my_strlen(str1);
	my_strcpy(p, str2);
	return str1;
}

int my_strcmp(const char* str1, const char* str2) {
	while (*str1 || *str2) {
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		str1++;
		str2++;
	}
	return 0;
}

