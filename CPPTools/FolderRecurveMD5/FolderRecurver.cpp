#include "FolderRecurver.h"
#include <windows.h>
#include <locale.h>  
#include <locale>
#include <io.h>
#include <fstream>
#include <sstream>
#include <iostream>

std::string relativePathToABSPath(std::string path)
{
#ifdef _WIN32
#define max_path 4096
	char resolved_path[max_path] = { 0 };
	_fullpath(resolved_path, path.c_str(), max_path);
#else
	//linux release有个坑，需要大点的空间
#define max_path 40960
	char resolved_path[max_path] = { 0 };
	realpath(path.c_str(), resolved_path);
#endif
	return std::string(resolved_path);
}

bool replace(std::string &str, const std::string &from, const std::string &to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
	{
		return false;
	}
	str.replace(start_pos, from.length(), to);
	return true;
}

void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
	if (from.empty())
	{
		return;
	}
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}

FolderRecurver::FolderRecurver(std::string &folderPath):
	_folderPath(relativePathToABSPath(folderPath))
{
	
}

void FolderRecurver::ExecuteMD5()
{
	this->ExecuteMD5WithFolder(_folderPath);

	this->WriteResultToFile();
}

void FolderRecurver::ExecuteMD5WithFolder(std::string &folderPath)
{
	//file handle
	intptr_t fHandle = 0;
	//file info struct
	struct _finddata_t fInfo;
	std::string pathString;

	std::vector<std::string> filePaths;
	std::vector<std::string> directoryPaths;

	if ((fHandle = _findfirst(pathString.assign(folderPath).append("\\*").c_str(), &fInfo)) != -1)
	{
		do
		{
			const char *fName = fInfo.name;
			if ((fInfo.attrib & _A_SUBDIR))
			{  //is directory
				if (strcmp(fName, ".") != 0 && strcmp(fName, "..") != 0)
				{
					pathString.assign(folderPath).append("/").append(fName);
					this->ExecuteMD5WithFolder(pathString);
				}
			}
			else
			{ //is file
				pathString.assign(folderPath).append("/").append(fName);
				this->ExecuteMD5WidthFile(pathString);
			}

		} while (_findnext(fHandle, &fInfo) == 0);  //find next, if success return 0 or fail return -1
		_findclose(fHandle);
	}
}

void FolderRecurver::ExecuteMD5WidthFile(std::string &filePath)
{
	std::ifstream openFileStream;
	openFileStream.open(filePath, std::ifstream::binary);
	if (!openFileStream.is_open())
	{
		return;
	}
	openFileStream.seekg(0, openFileStream.end);
	int fileLength = openFileStream.tellg();
	openFileStream.seekg(0, openFileStream.beg);

	char *readBuff = new char[fileLength];
	openFileStream.read(readBuff, fileLength);

	if (openFileStream)
	{
		//std::cout << "all characters read successfully.";
	}
	else
	{
		//std::cout << "error: only " << openFileStream.gcount() << " could be read";
	}
	openFileStream.close();

	

	MD5_CTX _md5Context;
	MD5_Init(&_md5Context);
	MD5_Update(&_md5Context, readBuff, fileLength);
	unsigned char md5[17] = { 0 };
	MD5_Final(md5, &_md5Context);
	
	std::string md5String;
	for (int i = 0; i < 16; i++)
	{
		std::string hexStr = this->charToHex(md5[i]);
		md5String.append(hexStr);
	}
	std::cout << md5String.c_str() << ":" << filePath.c_str() << std::endl;
	this->SaveToMap(md5String, filePath);

	delete[] readBuff;
}

std::string FolderRecurver::charToHex(unsigned char ch)
{
	const std::string hex = "0123456789ABCDEF";

	std::stringstream ss;
	ss << hex[ch >> 4] << hex[ch & 0xf];

	return ss.str();
}

void FolderRecurver::SaveToMap(std::string &md5Str, std::string &filePath)
{
	auto keyValueIter = _md5FileMap.find(md5Str);
	std::vector<std::string> *vectorPtr = nullptr;
	if (keyValueIter != _md5FileMap.end())
	{
		std::vector<std::string> &filePathVectorRef = _md5FileMap[md5Str];
		vectorPtr = &filePathVectorRef;
	}
	else
	{
		std::vector<std::string> filePathVector;
		_md5FileMap[md5Str] = filePathVector;
		std::vector<std::string> &filePathVectorRef = _md5FileMap[md5Str];
		vectorPtr = &filePathVectorRef;
	}
	if (vectorPtr != nullptr)
	{
		std::string saveFilePath = filePath;
		replaceAll(saveFilePath, "\\", "/");

		vectorPtr->push_back(saveFilePath);
	}
}

void FolderRecurver::WriteResultToFile()
{
	std::string outputString;
	for (auto mapIter = _md5FileMap.begin(); mapIter != _md5FileMap.end(); mapIter++)
	{
		auto mapValueVector = mapIter->second;
		int vectorSize = mapValueVector.size();
		if (vectorSize > 1)
		{
			outputString.append(mapIter->first);
			outputString.append("\n");

			for (auto vectorIter = mapValueVector.begin(); vectorIter != mapValueVector.end(); vectorIter++)
			{
				outputString.append(",");
				outputString.append((*vectorIter));
				outputString.append("\n");
			}
			outputString.append("\n");
		}
	}

	std::ofstream outputStream;
	std::string saveFileName = _folderPath;
	replaceAll(saveFileName, ":\\", "_");
	replaceAll(saveFileName, "\\", "_");
	saveFileName.append(".csv");
	outputStream.open(saveFileName, std::ofstream::binary);
	outputStream.write(outputString.c_str(), outputString.size());
	outputStream.close();
}
