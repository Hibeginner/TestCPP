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

	FileReader(const FileReader &fileReader) = delete;
	FileReader &operator=(const FileReader &) = delete;

	FileReader(FileReader &&fileReader) = delete;

	std::string getLine();
	bool isFileOpen();
	bool isEndOfFile();
	void close();
private:
	std::ifstream _inputFileStream;
	std::string _filePath;

	bool _isOpenFile = false;
	bool init();
};

