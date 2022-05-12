#pragma once
#include "ClassObjectReflectionClassInfo.h"

class SelfReflectionTestClass :public ClassObjectReflectionBaseObj
{
public:
	typedef std::string(SelfReflectionTestClass:: *GetAStringFuncPtr)(const std::string&);
	SelfReflectionTestClass();

	int intValue;
	std::string strValue;

	static ClassObjectReflectionBaseObj *CreateObject();

	std::string GetAString(const std::string& prefix);

	int SelfReflectionTestClass:: *GetFieldPtr()
	{
		return &SelfReflectionTestClass::intValue;
	}

	GetAStringFuncPtr GetFunctionPtr()
	{
		return &SelfReflectionTestClass::GetAString;
	}
protected:
	static ClassObjectReflectionClassInfo classInfo;
};

