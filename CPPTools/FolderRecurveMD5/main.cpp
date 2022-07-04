#include "FolderRecurver.h"
#include <iostream>

void ExecuteRecurve(int argc, const char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Give a folder path follow by .exe" << std::endl;
		return;
	}
	const char *processChar = nullptr;
	for (int i = 0; i < argc; i++)
	{
		const char *tempArg = argv[i];
		if (i == 1)
		{
			processChar = tempArg;
			std::cout << tempArg << std::endl;
		}
	}

	/*std::cout << "Drag a folder here:" << std::endl;
	char request[1024];
	std::cin.getline(request, 1024);

	std::string filePath(request);*/

	std::string filePath(processChar);

	FolderRecurver executor(filePath);
	executor.ExecuteMD5();
}

int main(int argc, const char *argv[])
{
	ExecuteRecurve(argc, argv);
	return 0;
}