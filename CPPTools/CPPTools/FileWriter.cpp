#include "FileWriter.h"

FileWriter::~FileWriter()
{
	close();
}

FileWriter::FileWriter(const std::string &filePath):
	_filePath(filePath)
{
	init();
}

bool FileWriter::isFileOpen()
{
	return _isOpenFile;
}

void FileWriter::write(const char *startPos, int size)
{
	if (_isOpenFile)
	{
		_outputFileStream.write(startPos, size);
	}
}

void FileWriter::close()
{
	if (_isOpenFile)
	{
		_outputFileStream.close();
	}
	_isOpenFile = false;
}

bool FileWriter::init()
{
	if (!_filePath.empty())
	{
		_outputFileStream.open(_filePath, std::ios::binary);
		if (_outputFileStream.is_open())
		{
			_isOpenFile = true;
			return true;
		}
	}
	return false;
}
