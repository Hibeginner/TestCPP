#include "FolderViewGenerator.h"


// std::wstring版本
std::vector<std::wstring> ws_split(const std::wstring &in, const std::wstring &delim)
{
	std::wregex re{ delim };
	return std::vector<std::wstring> {
		std::wsregex_token_iterator(in.begin(), in.end(), re, -1),
			std::wsregex_token_iterator()
	};
}
// c string版本
std::vector<std::string> c_split(const char *in, const char *delim)
{
	std::regex re{ delim };
	return std::vector<std::string> {
		std::cregex_token_iterator(in, in + strlen(in), re, -1),
			std::cregex_token_iterator()
	};
}
// 支持wchar_t宽字符集的版本
std::vector<std::wstring> wc_split(const wchar_t *in, const wchar_t *delim)
{
	std::wregex re{ delim };
	return std::vector<std::wstring> {
		std::wcregex_token_iterator(in, in + wcslen(in), re, -1),
			std::wcregex_token_iterator()
	};
}
// 上面的s_split和ws_split可以统一用模板来实现
template<typename E,
	typename TR = std::char_traits<E>,
	typename AL = std::allocator<E>,
	typename _str_type = std::basic_string<E, TR, AL>>
	std::vector<_str_type> bs_split(const std::basic_string<E, TR, AL> &in, const std::basic_string<E, TR, AL> &delim)
{
	std::basic_regex<E> re{ delim };
	return std::vector<_str_type> {
		std::regex_token_iterator<typename _str_type::const_iterator>(in.begin(), in.end(), re, -1),
			std::regex_token_iterator<typename _str_type::const_iterator>()
	};
}


FolderViewGenerator::~FolderViewGenerator()
{
}

FolderViewGenerator::FolderViewGenerator(int argc, const char **(&argv))
{
	init(argc, argv);
}

void FolderViewGenerator::doGenerate()
{
	FileReader fileReader(_inputFilePath);
	if (!fileReader.isFileOpen())
	{
		std::cout << "read fail." << std::endl;
		return;
	}

	std::unordered_map<int, TabData> tabDataMap;
	int index = 1;
	std::string lineStrBuff;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	while (!fileReader.isEndOfFile())
	{
		lineStrBuff = fileReader.getLine();
		std::wstring lineWStr = conv.from_bytes(lineStrBuff);
		size_t spliterPos = lineWStr.find(L"\t");
		std::wstring newTabPath = lineWStr.substr(0, spliterPos);
		std::wstring oldTabPath = lineWStr.substr(spliterPos + 1, lineWStr.size());

		std::vector<std::wstring> splitVector = ws_split(newTabPath, L"/");
		TabData tabData;
		tabData.mappingName = oldTabPath;
		int folderDeepIndex = 0;
 		int totalLength = splitVector.size();
		for (auto vectorIter = splitVector.begin(); vectorIter != splitVector.end(); vectorIter++)
		{
			std::wstring tempWStr = *vectorIter;
			if (folderDeepIndex == totalLength - 1)
			{
				tabData.selfName = tempWStr;
			}
			else
			{
				tabData.dirVector.push_back(tempWStr);
			}
			folderDeepIndex++;
		}
		tabDataMap.emplace(index, tabData);
		index++;
	}

	TabDataTree tabDataTree;
	tabDataTree.root.treeName = L"根";
	//std::unordered_map<std::wstring, TabData>
	for (auto mapIter = tabDataMap.begin(); mapIter != tabDataMap.end(); mapIter++)
	{
		tabDataTree.addToTree(mapIter->second);
	}

	tabDataTree.logTree();

	size_t buffSize = tabDataTree.logStr.size();
	if (buffSize > 0)
	{
		FileWriter fileWriter(_outputFilePath);

		if (fileWriter.isFileOpen())
		{
			std::string tempStr = conv.to_bytes(tabDataTree.logStr);
			fileWriter.write(tempStr.c_str(), tempStr.size());
		}

		fileWriter.close();
	}
}

void FolderViewGenerator::init(int argc, const char **(&argv))
{
	for (int i = 0; i < argc; i++)
	{
		const char *tempArg = argv[i];
		std::cout << tempArg << std::endl;
		if (i == 1)
		{
			_inputFilePath = tempArg;
		}
		if (i == 2)
		{
			_outputFilePath = tempArg;
		}
	}
	if (_outputFilePath.empty())
	{
		_outputFilePath = "new2.txt";
	}
}
