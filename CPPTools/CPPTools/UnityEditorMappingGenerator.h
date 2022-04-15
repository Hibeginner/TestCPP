#pragma once
#include "FileReader.h"
#include "FileWriter.h"
#include <unordered_map>
#include <codecvt>
#include <exception>

class UnityEditorMappingGenerator
{
public:
	UnityEditorMappingGenerator() = delete;
	~UnityEditorMappingGenerator();

	UnityEditorMappingGenerator(int argc, const char **(&argv));

	UnityEditorMappingGenerator(const UnityEditorMappingGenerator &UnityEditorMappingGenerator) = delete;
	UnityEditorMappingGenerator &operator=(const UnityEditorMappingGenerator &) = delete;

	UnityEditorMappingGenerator(UnityEditorMappingGenerator &&UnityEditorMappingGenerator) = delete;
	void doGenerate();
private:
	std::string _inputFilePath;
	std::string _outputFilePath;

	void init(int argc, const char **(&argv));
};

