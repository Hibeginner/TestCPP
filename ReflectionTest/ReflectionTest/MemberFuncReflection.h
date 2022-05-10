#pragma once

#include <string>

class Primitive
{
private:
	std::string name;
public:
	Primitive(std::string name) : name(name) {}
};

template<typename T>
class ClassMethod : Primitive
{
private:
	void (T:: *methodAddress)(); // used as a "generic" function pointer
	T &targetClass;
public:
	template<typename R, typename ...Args> // no need for casting to void*
	// and also check type - `methodAddress` is a member function specifically on `T`, not any abstract pointer...
	ClassMethod(std::string name, T &instance, R(T:: *methodAddress)(Args...)) :
		Primitive(name),
		// take a reference, unless you accept `nullptr`... I do not believe you do...
		targetClass(instance),
		// I do not believe this is very valid, but "will work".
		methodAddress(reinterpret_cast<void(T:: *)()>(methodAddress))
	{
		// all those out of class template deifinitions are confusing
		// let's move them inside!
	}

	template<typename ReturnType, typename ...Args>
	ReturnType Invoke(Args... args)
	{
		ReturnType(T:: * funcionPointer)(Args...) = reinterpret_cast<ReturnType(T:: *)(Args...)>(methodAddress);
		// forward arguments
		return (targetClass.*funcionPointer)(std::forward<Args...>(args)...);
		// when targetClass is a pointer, then
		// `*targetClass.*funcionPointer` is equal to `*(targetClass.*funcionPointer)` !!
		// you want `((*targetClass).*functionPointer)` or just `targetClass->*funcionPointer
	}
};