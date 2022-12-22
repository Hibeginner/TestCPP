#pragma once


#include <fstream>
#include <iostream>
#include <string>

class FileReader
{
public:
	FileReader() = delete;
	~FileReader();
	FileReader(const std::string& filePath);

	FileReader(const FileReader& fileReader) = delete;
	FileReader& operator=(const FileReader&) = delete;

	FileReader(FileReader&& fileReader) = delete;

	std::string GetLine();
	bool IsFileOpen();
	bool IsEndOfFile();
	void Close();
	int GetFileSize();

	void ReadBuff(char* buff, int size);
private:
	std::ifstream _inputFileStream;
	std::string _filePath;

	bool _isOpenFile = false;
	bool Init();

	void InitFileSize();

	int _fileSize;
};

