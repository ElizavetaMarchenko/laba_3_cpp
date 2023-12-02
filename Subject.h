#pragma once

class Subject {
public:
	int func1(int a) { return 2 * a; };
	int func2(int a, int b) { return 5 * a + 6 * b; };
	int func3(int a, int b, int c) { return 3 * a + 7 * b - 6 * c; };
};