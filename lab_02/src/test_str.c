#include "str.h"
#include "test_str.h"
#include <assert.h>
#include <string.h>

#define NUMBER_OF_TESTS 10
#define MAX_LEN 100

int seed = 0;

void next_rand(void) {
	seed = (seed * 53 + 7) % MAX_LEN;
}

void gen_str(char* str) {
	next_rand();
	int size = seed % 10 + 1;
	for (int i = 0; i < size - 1; i++) {
		next_rand();
		str[i] = (char)(seed) % 24 + 'a';
	}
	str[size - 1] = 0;
}

void test_strcpy(void) {
	char str[MAX_LEN];
	char buf1[MAX_LEN];
	char buf2[MAX_LEN];
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		gen_str(str);
		assert(strcmp(strcpy(buf1, str), my_strcpy(buf2, str)) == 0);
	}
}

void test_strcat(void) {
	char str[MAX_LEN];
	char buf1[MAX_LEN];
	char buf2[MAX_LEN];
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		gen_str(str);
		gen_str(buf1);
		strcpy(buf2, buf1);
		assert(strcmp(strcat(buf1, str), my_strcat(buf2, str)) == 0);
	}
}

void test_strcmp(void) {
	char str[MAX_LEN];
	char buf1[MAX_LEN];
	char buf2[MAX_LEN];
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		gen_str(str);
		gen_str(buf1);
		strcpy(buf2, str);
		int a = strcmp(str, buf1);
		int b = my_strcmp(str, buf1);
		assert((a == 0 && b == 0) || (a * b > 0));
		a = strcmp(str, buf2);
		b = my_strcmp(str, buf2);
		assert((a == 0 && b == 0) || (a * b > 0));
	}
}

void test_strlen(void) {
	char str[MAX_LEN];
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		gen_str(str);
		assert(strlen(str) == my_strlen(str));
	}
}

