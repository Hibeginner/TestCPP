#ifndef CLASS_REFLECTION_TEST_H_
#define CLASS_REFLECTION_TEST_H_

#include "ClassReflection.h"

class A : public Object
{
public:
	A() {};
	~A() {};

	ClassInfo *GetClassInfo() const{ 
		return &m_class_info_;
	};

	static Object *CreateObject()// �Զ�����������
	{
		return new A;
	};

protected:
	static ClassInfo m_class_info_;
};




#endif