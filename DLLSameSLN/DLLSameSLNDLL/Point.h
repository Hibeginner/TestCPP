#ifdef POINT_API
#else
#define POINT_API  _declspec(dllimport)
#endif // DLL1_API

POINT_API int  add(int a, int b);

POINT_API int  substract(int a, int b);

class POINT_API Point {
public:
	void output(int x, int y);
};