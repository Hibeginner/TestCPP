#include "ShowExeDependentDLL.h"
#include<TCHAR.h>

bool ShowExeDependentDLL::AdjustProcessTokenPrivilege()
{
	LUID luidTmp;
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		//OutputDebugString("AdjustProcessTokenPrivilege OpenProcessToken Failed ! \n");
		std::cout << "AdjustProcessTokenPrivilege OpenProcessToken Failed !" << std::endl;
	}

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luidTmp))
	{
		//OutputDebugString("AdjustProcessTokenPrivilege LookupPrivilegeValue Failed !");
		std::cout << "AdjustProcessTokenPrivilege LookupPrivilegeValue Failed !" << std::endl;
		CloseHandle(hToken);
		return FALSE;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = luidTmp;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL))
	{
		//OutputDebugString("AdjustProcessTokenPrivilege AdjustTokenPrivileges Failed ! \n");
		std::cout << "AdjustProcessTokenPrivilege AdjustTokenPrivileges Failed !" << std::endl;
		CloseHandle(hToken);
		return FALSE;
	}
	CloseHandle(hToken);
	return true;
}

void ShowExeDependentDLL::show(DWORD processID)
{
	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	unsigned int i;

	// Print the process identifier.

	printf("\nProcess ID: %u\n", processID);

	// Get a list of all the modules in this process.

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
	{
		std::cout << "Error :" << GetLastError() << std::endl;
		return;
	}
		

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		int hModuleSize = sizeof(HMODULE);
		int maxNum = (cbNeeded / hModuleSize);
		for (i = 0; i < maxNum; i++)
		{
			TCHAR szModName[MAX_PATH];

			if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{// Get the full path to the module's file.
				// Print the module name and handle value.

				_tprintf(TEXT("\t%s (0x%08X)\n"), szModName, hMods[i]);
				int a = 3;
			}
		}
	}

	CloseHandle(hProcess);
}
