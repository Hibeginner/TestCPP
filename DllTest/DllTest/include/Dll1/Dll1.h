#ifdef DLL1_API
#else
#define DLL1_API _declspec(dllimport)
#endif // DLL1_API

DLL1_API int add(int a, int b);

DLL1_API int substract(int a, int b);

class DLL1_API Point {
public:
	void output(int x, int y);
};