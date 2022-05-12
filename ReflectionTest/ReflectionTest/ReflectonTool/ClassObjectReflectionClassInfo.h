#pragma once
#include <string>
#include "ClassObjectReflectionBaseObj.h"


class ClassObjectReflectionBaseObj;//为什么必须有个前置声明？不是已经include了吗？难道是编译顺序问题？
typedef ClassObjectReflectionBaseObj *(*ClassConstructFunc)();//构造函数指针

class ClassObjectReflectionClassInfo
{
public:
	ClassObjectReflectionClassInfo() = delete;

	ClassObjectReflectionClassInfo(const std::string className, ClassConstructFunc constructFunc);

	ClassObjectReflectionBaseObj *InstantObject() const;

	std::string GetClassName();
private:
	std::string _className;
	ClassConstructFunc _constructFunc;
};

