#pragma once

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