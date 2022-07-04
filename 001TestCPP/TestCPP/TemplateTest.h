#pragma once
#include <iostream>

template <typename T>
T compare(const T &a, const T &b)
{
	if (a < b)
	{
		return -1;
	}
	if (a > b)
	{
		return 1;
	}
	return 0;
}

template <typename T>
class TemplateTest
{
public:
	void setValue(T value);
	T &getValue();
private:
	T value;
};


template<typename T>
void TemplateTest<T>::setValue(T value)
{
	this->value = value;
}

template<typename T>
T &TemplateTest<T>::getValue()
{
	return value;
}

template <typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y)->decltype(x *y)
{
	return x * y;
}


template<typename FirstType>
void printList(const FirstType &firstParam)
{
	std::cout << firstParam << std::endl;
}

template<typename FirstType, typename... OtherType> //typename...三个点代表，OtherType是模板参数包
void printList(const FirstType &firstParam, const OtherType&... otherParam) //OtherType&...三个点代表，otherParam是函数参数包
{
	std::cout << firstParam << std::endl;
	printList(otherParam...);//包展开
}

