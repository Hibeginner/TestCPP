#pragma once
#include <string>
#include <unordered_map>
#include "ClassObjectReflectionClassInfo.h"

class ClassObjectReflectionClassInfo;

class ClassObjectReflectionBaseObj
{
public:
	ClassObjectReflectionBaseObj() {};
	virtual ~ClassObjectReflectionBaseObj() {};

	static bool RegistClassInfo(ClassObjectReflectionClassInfo *classInfo);

	static ClassObjectReflectionBaseObj *CreateObject(std::string className);
};

