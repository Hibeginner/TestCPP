#pragma once
#include <string>
#include <fstream>

class FileWriter
{
public:
	FileWriter() = delete;
	~FileWriter();
	FileWriter(const std::string &filePath);

	FileWriter(const FileWriter &FileWriter) = delete;
	FileWriter &operator=(const FileWriter &) = delete;

	FileWriter(FileWriter &&FileWriter) = delete;

	bool isFileOpen();
	void write(const char * startPos, int size);
	void close();
private:
	std::ofstream  _outputFileStream;
	std::string _filePath;

	bool _isOpenFile = false;
	bool init();
};

