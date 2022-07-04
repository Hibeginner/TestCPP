#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <openssl/md5.h>

class FolderRecurver
{
public:
	FolderRecurver(std::string &folderPath);
	void ExecuteMD5();
private:
	std::string _folderPath;
	std::unordered_map<std::string, std::vector<std::string>> _md5FileMap;
	


	void ExecuteMD5WithFolder(std::string & folderPath);
	void ExecuteMD5WidthFile(std::string &filePath);

	std::string charToHex(unsigned char ch);
	void SaveToMap(std::string &md5Str, std::string &filePath);
	void WriteResultToFile();
};

