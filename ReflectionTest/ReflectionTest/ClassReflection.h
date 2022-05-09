#ifndef CLASS_REFLECTION_H_
#define CLASS_REFLECTION_H_

#include <string>
#include <unordered_map>

using namespace std;

class ClassInfo;

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	static bool Register(ClassInfo *ci); // 注册函数
	static Object *CreateObject(string name);
};

using ObjectConstructorFn = Object * (*)(void); // 构造函数指针

class ClassInfo
{
public:
	ClassInfo(const string classname, ObjectConstructorFn ctor)
		:class_name_(classname),
		m_object_constructor_(ctor)
	{
		Object::Register(this); // 注入到Object中
	}

	virtual ~ClassInfo() {};
	Object *CreateObject() const
	{
		if (m_object_constructor_)
		{
			return m_object_constructor_();
		}
		else
		{
			return 0;
		}
		//return m_object_constructor_ ? (*m_object_constructor_) : 0;// 返回当前类型的构造函数
	}

	const string GetClassName() const
	{
		return class_name_;
	}
	ObjectConstructorFn GetConstructor()
	{
		return m_object_constructor_;
	}

private:
	string class_name_;
	ObjectConstructorFn m_object_constructor_; // 维护对象信息
};

#endif