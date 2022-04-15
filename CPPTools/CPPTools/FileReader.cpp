#include "FileReader.h"

FileReader::~FileReader()
{
	close();
}

FileReader::FileReader(const std::string &filePath):
	_filePath(filePath)
{
	init();
}

std::string FileReader::getLine()
{
	std::string lineStrBuff;
	if (_isOpenFile)
	{
		/*std::wstring tempBuff;
		std::getline(_inputFileStream, tempBuff);
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		lineStrBuff = converter.to_bytes(tempBuff);*/
		std::getline(_inputFileStream, lineStrBuff);
	}
	return lineStrBuff;
}

bool FileReader::isFileOpen()
{
	return _isOpenFile;
}

bool FileReader::isEndOfFile()
{
	if (_isOpenFile)
	{
		return _inputFileStream.eof();
	}
	return true;
}

void FileReader::close()
{
	if (_isOpenFile)
	{
		_inputFileStream.close();
	}
	_isOpenFile = false;
}

bool FileReader::init()
{
	if (!_filePath.empty())
	{
		_inputFileStream.open(_filePath, std::ios::in);
		if (_inputFileStream.is_open())
		{
			_isOpenFile = true;
			return true;
		}
	}
	return false;
}
