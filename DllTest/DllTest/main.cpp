
#include "include/Dll1/Dll1.h"
//extern int add(int a, int b);
//extern int substract(int a, int b);

//__declspec(dllimport) int add(int a, int b);
//__declspec(dllimport) int substract(int a, int b);

void main() {
	int resAdd = add(1, 2);
	int resSub = substract(1, 2);

	Point p;
	p.output(2, 3);
}