#include "Test.hpp"

int Test::totalNum = 0;
int Test::failedNum = 0;

using std::cout;

void Test::check(bool expr, const char *func, const char* filename, size_t lineNum) {
	++totalNum;
	if (!expr) {
		++failedNum;
		cout << "Crashed test #" << totalNum << "\n";
		cout << "Func: " << func << "\n";
		cout << "File: " << filename << "\n";
		cout << "Line: " << lineNum << "\n";
		cout << "\n";
	}
}

void Test::showFinalResult() {
	cout << "Total: " << totalNum << "\n" << "Failed: " << failedNum << "\n";
	totalNum = 0;
	failedNum = 0;
}
