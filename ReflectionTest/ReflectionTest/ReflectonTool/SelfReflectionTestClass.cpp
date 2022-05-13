#include "SelfReflectionTestClass.h"

SelfReflectionTestClass::SelfReflectionTestClass():
	intValue(0),
	strValue("")
{
}

ClassObjectReflectionBaseObj *SelfReflectionTestClass::CreateObject()
{
	return new SelfReflectionTestClass();
}

std::string SelfReflectionTestClass::GetAString(const std::string& prefix)
{
	std::string tempStr = prefix + std::string("cde");
	return tempStr;
}

ClassObjectReflectionClassInfo SelfReflectionTestClass::classInfo("SelfReflectionTestClass", SelfReflectionTestClass::CreateObject);