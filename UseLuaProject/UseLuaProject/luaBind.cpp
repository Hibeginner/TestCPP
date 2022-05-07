extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

const char *HandlesGetSet = "HandlesGetSet";

extern double a /*= 166*/;

int a_get(lua_State *L)
{
	lua_pushnumber(L, a);
	return 1;
}

int a_set(lua_State *L)
{
	if (lua_isnumber(L, 1))
	{
		a = lua_tonumber(L, 1);
	}

	return 0;
}

int index_event(lua_State *L)
{
	//从 registry  中获取变量的get set 方法
	luaL_getmetatable(L, HandlesGetSet);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);

	if (lua_isnil(L, -1))// 没有get set方法
	{
		lua_pop(L, 2);
		lua_rawget(L, -2);
	}
	else
	{
		lua_pushstring(L, "get");
		lua_rawget(L, -2);
		lua_pcall(L, 0, 1, 0);//调用get方法
	}
	return 1;
}

int newindex_event(lua_State *L)
{
	//从 registry  中获取变量的get set 方法
	luaL_getmetatable(L, HandlesGetSet);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);

	if (lua_isnil(L, -1))// 没有get set方法
	{
		lua_pop(L, 2);
		lua_rawset(L, -3);
	}
	else
	{
		lua_pushstring(L, "set");//调用set方法
		lua_rawget(L, -2);
		lua_pushvalue(L, 3);
		lua_pcall(L, 1, 0, 0);
	}
	return 0;
}

void BindLua(lua_State *L)
{

	//获取 _G表
#if defined (LUA_VERSION_NUM) && LUA_VERSION_NUM >= 502 /* after lua 5.2 */
	lua_pushvalue(L, LUA_REGISTRYINDEX); /* registry */
	lua_pushnumber(L, LUA_RIDX_GLOBALS); /* registry globalsindex */
	lua_rawget(L, -2);                  /* registry registry[globalsindex] */
	lua_remove(L, -2);                  /* registry */
#else
	lua_pushvalue(L, LUA_GLOBALSINDEX);
#endif

	//创建 _G表的元表
	lua_newtable(L);
	lua_pushstring(L, "__index");
	lua_pushcfunction(L, index_event);
	lua_rawset(L, -3);
	lua_pushstring(L, "__newindex");
	lua_pushcfunction(L, newindex_event);
	lua_rawset(L, -3);

	lua_setmetatable(L, -2);//设置 _G表的元表
	lua_pop(L, 1);

	//创建一张表存储在 registry  中
	luaL_newmetatable(L, HandlesGetSet);
	//注册 a 变量的get set方法
	lua_pushstring(L, "a");
	lua_newtable(L);
	lua_pushstring(L, "get");
	lua_pushcfunction(L, a_get);
	lua_rawset(L, -3);
	lua_pushstring(L, "set");
	lua_pushcfunction(L, a_set);
	lua_rawset(L, -3);
	lua_rawset(L, -3);
	lua_pop(L, 1);
}