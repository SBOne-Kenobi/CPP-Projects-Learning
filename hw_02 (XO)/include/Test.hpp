#pragma once

#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__)

#include <stddef.h>
#include <iostream>

class Test {
protected:
	static int failedNum;
	static int totalNum;

	static void check(bool expr, const char *func, const char* filename, size_t lineNum);

public:
	static void showFinalResult();

	virtual void runAllTests() = 0;
};
