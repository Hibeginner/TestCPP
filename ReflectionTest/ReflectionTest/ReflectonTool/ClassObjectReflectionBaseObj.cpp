#include "ClassObjectReflectionBaseObj.h"

static std::unordered_map<std::string, ClassObjectReflectionClassInfo *> *classInfoMap = nullptr; // 延迟到第一次注册

bool ClassObjectReflectionBaseObj::RegistClassInfo(ClassObjectReflectionClassInfo *classInfo)
{
	if (classInfoMap == nullptr)
	{
		classInfoMap = new std::unordered_map<std::string, ClassObjectReflectionClassInfo *>();
	}
	if (classInfo)
	{
		std::string className = classInfo->GetClassName();
		if (classInfoMap->find(className) == classInfoMap->end())
		{
			classInfoMap->emplace(className, classInfo);
		}
	}
	return false;
}

ClassObjectReflectionBaseObj *ClassObjectReflectionBaseObj::CreateObject(std::string className)
{
	if (classInfoMap->find(className) != classInfoMap->end())
		return (*classInfoMap)[className]->InstantObject();

	return nullptr;
}
