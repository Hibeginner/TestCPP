#pragma once
#ifndef FolderViewGenerator_H
#define FolderViewGenerator_H

#include "FileReader.h"
#include "FileWriter.h"
#include <unordered_map>
#include <codecvt>
#include <exception>
#include "TabData.h"
#include <vector>
#include <regex>

class FolderViewGenerator
{
public:
	FolderViewGenerator() = delete;
	~FolderViewGenerator();

	FolderViewGenerator(int argc, const char **(&argv));

	FolderViewGenerator(const FolderViewGenerator &UnityEditorMappingGenerator) = delete;
	FolderViewGenerator &operator=(const FolderViewGenerator &) = delete;

	FolderViewGenerator(FolderViewGenerator &&FolderViewGenerator) = delete;
	void doGenerate();
private:
	std::string _inputFilePath;
	std::string _outputFilePath;

	void init(int argc, const char **(&argv));
};

#endif