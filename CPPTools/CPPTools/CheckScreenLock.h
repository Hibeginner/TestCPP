#pragma once
#include <Windows.h>
#include <WtsApi32.h>

class CheckScreenLock
{
public:
	CheckScreenLock() = default;
	bool IsSessionLocked();
};

