#include "ClassReflection.h"

static unordered_map<std::string, ClassInfo *> *class_map = nullptr; // �ӳٵ���һ��ע��

bool Object::Register(ClassInfo *ci)
{
	if (!class_map)
	{
		class_map = new unordered_map<std::string, ClassInfo *>();
	}

	if (ci)
	{
		std::string c_name = ci->GetClassName();
		if (class_map->find(c_name) == class_map->end())// ���û��ע���
		{
			(*class_map)[c_name] = ci;
		}
		return true;
	}

	return false;
}

Object *Object::CreateObject(std::string name)
{
	// ���ע�����ֱ�ӵ���classinfo��createobject
	if (class_map->find(name) != class_map->end())
		return (*class_map)[name]->CreateObject();

	return nullptr;
}