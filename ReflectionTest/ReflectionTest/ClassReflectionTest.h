#ifndef CLASS_REFLECTION_TEST_H_
#define CLASS_REFLECTION_TEST_H_

#include "ClassReflection.h"

class CustomClassA : public Object
{
public:
	CustomClassA() {};
	~CustomClassA() {};

	int x;
	int y;

	ClassInfo *GetClassInfo() const{ 
		return &m_class_info_;
	};

	static Object *CreateObject()// 自定义生产函数
	{
		return new CustomClassA;
	};

	int *GetIntPtr(int a)
	{
		return nullptr;
	}

protected:
	static ClassInfo m_class_info_;
};




#endif