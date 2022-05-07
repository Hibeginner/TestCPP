#include<iostream>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

using namespace std;
double a = 166;

void BindLua(lua_State *L);

int main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	BindLua(L);
	a = 99;
	if (0 != luaL_dofile(L, "a.lua"))
	{
		printf("%s\n", lua_tostring(L, -1));
	}
	printf("a = %f\n\n\n", a);
	a = a + 1000;
	if (0 != luaL_dofile(L, "a.lua"))
	{
		printf("%s\n", lua_tostring(L, -1));
	}
	printf("a = %f\n", a);
	lua_close(L);

	return 0;
}
