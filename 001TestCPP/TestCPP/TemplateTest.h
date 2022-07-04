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

template<typename FirstType, typename... OtherType> //typename...���������OtherType��ģ�������
void printList(const FirstType &firstParam, const OtherType&... otherParam) //OtherType&...���������otherParam�Ǻ���������
{
	std::cout << firstParam << std::endl;
	printList(otherParam...);//��չ��
}

