#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "psapi.h"

#pragma comment(lib, "Psapi.lib")

class ShowExeDependentDLL
{
public:
	bool AdjustProcessTokenPrivilege();
	void show(DWORD processID);
};

