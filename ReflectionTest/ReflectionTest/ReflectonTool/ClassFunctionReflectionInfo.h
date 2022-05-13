//��һ��ʵ�֣���ע���ˡ�������map��װ�İ�
//#pragma once
//#include <string>
//
//template<typename ClassType>
//class ClassFunctionReflectionInfo
//{
//public:
//	template<typename ReturnType, typename... ParamTypes>
//	ClassFunctionReflectionInfo(std::string funcName, ReturnType(ClassType:: *tempclassFunctionPtr) (ParamTypes...));
//
//	template<typename ReturnType, typename... ParamTypes>
//	ReturnType Invoke(ClassType *instance, ParamTypes &&... paramTypes);
//private:
//	void (ClassType:: *classFunctionPtr)();//ͨ�ú���ָ�룬����ͨ��reinterpretת����������ָ��
//	std::string _funcName;
//};
//
//template<typename ClassType>
//template<typename ReturnType, typename ...ParamTypes>
//inline ClassFunctionReflectionInfo<ClassType>::ClassFunctionReflectionInfo(std::string funcName, ReturnType(ClassType:: *tempclassFunctionPtr)(ParamTypes...)) :
//	_funcName(funcName),
//	classFunctionPtr(reinterpret_cast<void(ClassType:: *)()>(tempclassFunctionPtr))
//{
//
//}
//
//template<typename ClassType>
//template<typename ReturnType, typename ...ParamTypes>
//inline ReturnType ClassFunctionReflectionInfo<ClassType>::Invoke(ClassType *instance, ParamTypes &&... paramTypes)
//{
//	size_t paramSize = sizeof...(paramTypes);
//	ReturnType(ClassType:: * funcPtr)(ParamTypes...) = reinterpret_cast<ReturnType(ClassType:: *)(ParamTypes...)>(classFunctionPtr);
//	return (instance->*funcPtr)(std::forward<ParamTypes>(paramTypes)...); //return��ȥӦ����һ��copy��ֵ��(paramTypes)...��˵��һ��һ��������ת��
//}
//
//


#pragma once
#include <string>
#include <unordered_map>
#include <memory>

template<typename ClassType>
class ClassFunctionReflectionContainerBase
{
public:
	ClassFunctionReflectionContainerBase(std::string funcName):
		_funcName(funcName)
	{

	};
	std::string _funcName;
};

template<typename ClassType, typename ReturnType>
class ClassFunctionReflectionContainer: public ClassFunctionReflectionContainerBase<ClassType>
{
public:
	template<typename... ParamTypes>
	ClassFunctionReflectionContainer(std::string funcName, ReturnType(ClassType:: *tempclassFunctionPtr) (ParamTypes...)):
		ClassFunctionReflectionContainerBase<ClassType>(funcName),
		classFunctionPtr(reinterpret_cast<void(ClassType:: *)()>(tempclassFunctionPtr))
	{

	};

	template<typename... ParamTypes>
	ReturnType Invoke(ClassType *instance, ParamTypes&&... params);
private:
	void (ClassType:: *classFunctionPtr)();//ͨ�ú���ָ�룬����ͨ��reinterpretת����������ָ��
};

template<typename ClassType, typename ReturnType>
template<typename ...ParamTypes>
inline ReturnType ClassFunctionReflectionContainer<ClassType, ReturnType>::Invoke(ClassType *instance, ParamTypes && ...params)
{
	ReturnType(ClassType:: * funcPtr)(ParamTypes...) = reinterpret_cast<ReturnType(ClassType:: *)(ParamTypes...)>(classFunctionPtr);
	return (instance->*funcPtr)(std::forward<ParamTypes>(params)...);
}



template<typename ClassType>
class ClassFunctionReflectionInfo
{
public:
	template<typename ReturnType, typename ... ParamTypes>
	void RegistFunction(std::string funcName, ReturnType(ClassType:: *classFunctionPtr)(ParamTypes...));

	template<typename ReturnType, typename ... ParamTypes>
	ReturnType Invoke(ClassType *instance, std::string funcName, ParamTypes&&... params);
private:
	std::unordered_map < std::string, std::unique_ptr<ClassFunctionReflectionContainerBase<ClassType>>> _funcMap;
};

template<typename ClassType>
template<typename ReturnType, typename ...ParamTypes>
inline void ClassFunctionReflectionInfo<ClassType>::RegistFunction(std::string funcName, ReturnType(ClassType:: *classFunctionPtr)(ParamTypes...))
{
	_funcMap.emplace(funcName, std::make_unique<ClassFunctionReflectionContainer<ClassType, ReturnType>>(funcName, classFunctionPtr));
}

template<typename ClassType>
template<typename ReturnType, typename ...ParamTypes>
inline ReturnType ClassFunctionReflectionInfo<ClassType>::Invoke(ClassType *instance, std::string funcName, ParamTypes && ...params)
{
	if (_funcMap.find(funcName) != _funcMap.end())
	{
		std::unique_ptr<ClassFunctionReflectionContainerBase<ClassType>> &baseUniquePtr = _funcMap[funcName];
		ClassFunctionReflectionContainerBase<ClassType> *basePtr = baseUniquePtr.get();
		ClassFunctionReflectionContainer<ClassType, ReturnType> *containerPtr = reinterpret_cast<ClassFunctionReflectionContainer<ClassType, ReturnType>*>(basePtr);
		return containerPtr->Invoke(instance, std::forward<ParamTypes>(params)...);
	}
	return ReturnType();
}


