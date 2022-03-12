#define POINT_API _declspec(dllexport)
#include "Point.h"
#include <iostream>

int  add(int a, int b) {
	return a + b;
}

int  substract(int a, int b) {
	return a - b;
}

void Point::output(int x, int y) {
	std::cout << x << ", " << y << std::endl;
}