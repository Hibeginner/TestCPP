#define DLL1_API extern "C" _declspec(dllexport)
#include "Dll1.h"
#include <iostream>

int _stdcall add(int a, int b) {
	return a + b;
}

int _stdcall substract(int a, int b) {
	return a - b;
}

//void Point::output(int x, int y) {
//	std::cout << x << ", " << y << std::endl;
//}