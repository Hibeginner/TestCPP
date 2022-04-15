#include "UnityEditorMappingGenerator.h"

void strimStr(std::string &str)
{
	size_t n = str.find_last_not_of(" \r\n\t");
	/*if (n != std::string::npos)
	{
		lineStrBuff.erase(n, lineStrBuff.size() - n);
	}*/
	n = str.find_first_not_of(" \r\n\t");
	if (n != std::string::npos)
	{
		str.erase(0, n);
	}
}

std::string getTabName(std::string &str)
{
	std::size_t startIndex = str.find_first_of("\"");
	std::size_t endIndex = str.find_last_of("\"");
	std::string nameOfTab = str.substr(startIndex + 1, endIndex - startIndex - 1);
	return nameOfTab;
}

UnityEditorMappingGenerator::~UnityEditorMappingGenerator()
{
}

UnityEditorMappingGenerator::UnityEditorMappingGenerator(int argc, const char **(&argv))
{
	init(argc, argv);
}

void UnityEditorMappingGenerator::doGenerate()
{

	FileReader fileReader(_inputFilePath);
	if (!fileReader.isFileOpen())
	{
		std::cout << "read fail." << std::endl;
		return;
	}

	std::unordered_map<std::wstring, std::wstring> splitMap = {
	 {L"#region UI����", L"RO���߼�/UI����/"},
	 {L"#region ������Ч����", L"RO���߼�/������Ч����/"},
	 {L"#region ��ͼ_Shader_����_ģ�͹���", L"RO���߼�/��ͼ_Shader_����_ģ�͹���/"},
	 {L"#region ��Ч����", L"RO���߼�/��Ч����/"},
	 {L"#region �߻�����", L"RO���߼�/�߻�����/"},
	 {L"#region �������������", L"RO���߼�/�������������/"},
	 {L"#region AssetBundle����", L"RO���߼�/AssetBundle����/"},
	 {L"#region Lua", L"Lua/"},
	 {L"#region ���ػ�����", L"RO���߼�/���ػ�����/"},
	 {L"#region ս���༭��", L"ս���༭����/"},
	 {L"#region ��������", L"ս���༭����/��������/"},
	 {L"#region ��������", L"RO���߼�/��������/"},
	};

	std::string matchStr("[MenuItem(");
	std::wstring subtractionStr = L"";
	std::string lineStrBuff;
	bool recordNextLine = false;
	std::wstring tabPrefix = L"";
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	while (!fileReader.isEndOfFile())
	{
		lineStrBuff = fileReader.getLine();
		
		strimStr(lineStrBuff);
		std::cout << lineStrBuff << std::endl;

		size_t matchResultTest = lineStrBuff.find(matchStr);
		if (matchResultTest == 0)
		{
			int i = 0;
		}

		for (auto it = splitMap.begin(); it != splitMap.end(); ++it)
		{
			std::string keyStr = conv.to_bytes(it->first);
			size_t splitIndex = lineStrBuff.find(keyStr);
			if (splitIndex != std::string::npos)
			{
				tabPrefix = it->second;
				break;
			}
		}

		if (recordNextLine)
		{
			std::string nameOfTab = getTabName(lineStrBuff);
			subtractionStr += conv.from_bytes(nameOfTab) + conv.from_bytes("\n");

			recordNextLine = false;
		}

		size_t matchResult = lineStrBuff.find(matchStr);
		if (matchResult == 0)
		{
			std::string nameOfTab = getTabName(lineStrBuff);
			
			std::wstring tabWStr = tabPrefix;
			std::wstring nameOfTabWStr = conv.from_bytes(nameOfTab);
			subtractionStr += tabWStr;
			subtractionStr += nameOfTabWStr;
			subtractionStr += L"\t";

			recordNextLine = true;
		}
	}

	size_t buffSize = subtractionStr.size();
	if (buffSize > 0)
	{
		FileWriter fileWriter(_outputFilePath);

		if (fileWriter.isFileOpen())
		{
			std::string tempStr = conv.to_bytes(subtractionStr);
			fileWriter.write(tempStr.c_str(), tempStr.size());
		}

		fileWriter.close();
	}


}

void UnityEditorMappingGenerator::init(int argc, const char **(&argv))
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
		_outputFilePath = "new1.txt";
	}
}
