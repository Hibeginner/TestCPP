#pragma once
#include <string>
#include "ClassObjectReflectionBaseObj.h"


class ClassObjectReflectionBaseObj;//Ϊʲô�����и�ǰ�������������Ѿ�include�����ѵ��Ǳ���˳�����⣿
typedef ClassObjectReflectionBaseObj *(*ClassConstructFunc)();//���캯��ָ��

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

