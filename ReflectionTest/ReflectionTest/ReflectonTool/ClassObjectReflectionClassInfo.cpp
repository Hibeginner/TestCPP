#include "ClassObjectReflectionClassInfo.h"

ClassObjectReflectionClassInfo::ClassObjectReflectionClassInfo(const std::string className, ClassConstructFunc constructFunc):
	_className(className),
	_constructFunc(constructFunc)
{
	ClassObjectReflectionBaseObj::RegistClassInfo(this);
}

ClassObjectReflectionBaseObj *ClassObjectReflectionClassInfo::InstantObject() const
{
	if (_constructFunc)
	{
		return _constructFunc();
	}
	return nullptr;
}

std::string ClassObjectReflectionClassInfo::GetClassName()
{
	return _className;
}
