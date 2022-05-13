#pragma once
#include <string>
#include <unordered_map>
#include <memory>

template<typename ClassType>
class ClassFieldContainerBase //有base的原因是，下面的map需要相同类型的成员。还需要做成指针，方便多态
{
public:
	void SetFieldValue(ClassType *instance) {};
	virtual const char *GetFieldType() = 0;
};


template<typename ClassType, typename FieldType>
class ClassFieldContainer : public ClassFieldContainerBase<ClassType>//这里要写public共有继承，不然构造函数无法调用到
{
public:
	ClassFieldContainer(const std::string fieldName, FieldType ClassType:: *fieldPtr);
	void SetFieldValue(ClassType *instance, FieldType value);
	const char *GetFieldType() override;

	FieldType ClassType:: *GetFieldPtr()
	{
		return _fieldPtr;
	};
private:
	std::string _fieldName;
	FieldType ClassType:: *_fieldPtr;
};

template<typename ClassType, typename FieldType>
inline ClassFieldContainer<ClassType, FieldType>::ClassFieldContainer(const std::string fieldName, FieldType ClassType:: *fieldPtr):
	_fieldName(fieldName),
	_fieldPtr(fieldPtr)
{
}

template<typename ClassType, typename FieldType>
inline void ClassFieldContainer<ClassType, FieldType>::SetFieldValue(ClassType *instance, FieldType value)
{
	instance->*_fieldPtr = value;
}

template<typename ClassType, typename FieldType>
inline const char *ClassFieldContainer<ClassType, FieldType>::GetFieldType()
{
	const char *typeInfo = typeid(_fieldPtr).name();
	return typeInfo;
}





template<typename ClassType>
class ClassFieldReflectionInfo
{
public:

	template<typename FieldType>
	void RegistField(const std::string fieldName, FieldType ClassType:: *fieldPtr);
	
	template<typename FieldType>
	void SetFieldValue(ClassType* instance, const std::string fieldName, FieldType value);

	template<typename ReturnType>
	ReturnType GetFieldValue(ClassType *instance, const std::string fieldName);

	const char * GetFieldTypeByName(const std::string fieldName);
private:
	std::unordered_map<std::string, std::unique_ptr<ClassFieldContainerBase<ClassType>>> _filedMap;//std::unique_ptr方便多
};

template<typename ClassType>
template<typename FieldType>
inline void ClassFieldReflectionInfo<ClassType>::RegistField(const std::string fieldName, FieldType ClassType:: *fieldPtr)
{
	_filedMap.emplace(fieldName, std::make_unique<ClassFieldContainer<ClassType, FieldType>>(fieldName, fieldPtr));
}

template<typename ClassType>
template<typename FieldType>
inline void ClassFieldReflectionInfo<ClassType>::SetFieldValue(ClassType *instance, const std::string fieldName, FieldType value)
{
	if (_filedMap.find(fieldName) != _filedMap.end())
	{
		std::unique_ptr<ClassFieldContainerBase<ClassType>> &ptr = _filedMap[fieldName];
		ClassFieldContainerBase<ClassType> *originPtr = ptr.get();
		ClassFieldContainer<ClassType, FieldType>* containerPtr = reinterpret_cast<ClassFieldContainer<ClassType, FieldType>*>(originPtr);
		containerPtr->SetFieldValue(instance, value);
	}
}

template<typename ClassType>
template<typename FieldType>
inline FieldType ClassFieldReflectionInfo<ClassType>::GetFieldValue(ClassType *instance, const std::string fieldName)
{
	if (_filedMap.find(fieldName) != _filedMap.end())
	{
		std::unique_ptr<ClassFieldContainerBase<ClassType>> &ptr = _filedMap[fieldName];
		ClassFieldContainerBase<ClassType> *originPtr = ptr.get();
		ClassFieldContainer<ClassType, FieldType> *containerPtr = reinterpret_cast<ClassFieldContainer<ClassType, FieldType>*>(originPtr);
		FieldType ClassType:: *fieldPtr = containerPtr->GetFieldPtr();

		return instance->*fieldPtr;
	}
	return FieldType();
}

template<typename ClassType>
inline const char * ClassFieldReflectionInfo<ClassType>::GetFieldTypeByName(const std::string fieldName)
{
	if (_filedMap.find(fieldName) != _filedMap.end())
	{
		std::unique_ptr<ClassFieldContainerBase<ClassType>> &ptr = _filedMap[fieldName];
		return ptr->GetFieldType();
	}
}
