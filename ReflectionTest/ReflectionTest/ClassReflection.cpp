#include "ClassReflection.h"

static unordered_map<std::string, ClassInfo *> *class_map = nullptr; // 延迟到第一次注册

bool Object::Register(ClassInfo *ci)
{
	if (!class_map)
	{
		class_map = new unordered_map<std::string, ClassInfo *>();
	}

	if (ci)
	{
		std::string c_name = ci->GetClassName();
		if (class_map->find(c_name) == class_map->end())// 如果没有注册过
		{
			(*class_map)[c_name] = ci;
		}
		return true;
	}

	return false;
}

Object *Object::CreateObject(std::string name)
{
	// 如果注册过就直接调用classinfo的createobject
	if (class_map->find(name) != class_map->end())
		return (*class_map)[name]->CreateObject();

	return nullptr;
}