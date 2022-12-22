#include "FileReader.h"

FileReader::~FileReader()
{
	Close();
}

FileReader::FileReader(const std::string& filePath) :
	_filePath(filePath),
	_fileSize(0)
{
	Init();
}

std::string FileReader::GetLine()
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

bool FileReader::IsFileOpen()
{
	return _isOpenFile;
}

bool FileReader::IsEndOfFile()
{
	if (_isOpenFile)
	{
		return _inputFileStream.eof();
	}
	return true;
}

void FileReader::Close()
{
	if (_isOpenFile)
	{
		_inputFileStream.close();
	}
	_isOpenFile = false;
}

int FileReader::GetFileSize()
{
	if (_isOpenFile) {
		return _fileSize;
	}
	return 0;
}

void FileReader::ReadBuff(char* buff, int size)
{
	if (_isOpenFile) {
		if (nullptr != buff && size != 0) {
			_inputFileStream.read(buff, size);
			if (_inputFileStream)
				std::cout << "all characters read successfully.";
			else
				std::cout << "error: only " << _inputFileStream.gcount() << " could be read";
		}
	}
}

bool FileReader::Init()
{
	if (!_filePath.empty())
	{
		_inputFileStream.open(_filePath, std::ios::binary);
		if (_inputFileStream.is_open())
		{
			_isOpenFile = true;
			InitFileSize();
			return true;
		}
	}
	return false;
}

void FileReader::InitFileSize()
{
	if (_isOpenFile) {
		_inputFileStream.seekg(0, _inputFileStream.end);
		_fileSize = _inputFileStream.tellg();
		_inputFileStream.seekg(0, _inputFileStream.beg);
	}
}
