#pragma once
#include <string>

template<typename ClassType>
class ClassFunctionReflectionInfo
{
public:
	template<typename ReturnType, typename... ParamTypes>
	ClassFunctionReflectionInfo(std::string funcName, ReturnType (ClassType::*tempclassFunctionPtr) (ParamTypes...));

	template<typename ReturnType, typename... ParamTypes>
	ReturnType Invoke(ClassType * instance, ParamTypes &&... paramTypes);
private:
	void (ClassType:: *classFunctionPtr)();//通用函数指针，可以通过reinterpret转成其他类型指针
	std::string _funcName;
};

template<typename ClassType>
template<typename ReturnType, typename ...ParamTypes>
inline ClassFunctionReflectionInfo<ClassType>::ClassFunctionReflectionInfo(std::string funcName, ReturnType(ClassType:: *tempclassFunctionPtr)(ParamTypes...)):
	_funcName(funcName),
	classFunctionPtr(reinterpret_cast<void(ClassType:: *)()>(tempclassFunctionPtr))
{

}

template<typename ClassType>
template<typename ReturnType, typename ...ParamTypes>
inline ReturnType ClassFunctionReflectionInfo<ClassType>::Invoke(ClassType *instance, ParamTypes &&... paramTypes)
{
	size_t paramSize = sizeof...(paramTypes);
	ReturnType(ClassType:: * funcPtr)(ParamTypes...) = reinterpret_cast<ReturnType(ClassType:: *)(ParamTypes...)>(classFunctionPtr);
	return (instance->*funcPtr)(std::forward<ParamTypes>(paramTypes)...); //return出去应该是一次copy赋值。(paramTypes)...是说，一个一个参数地转发
}


