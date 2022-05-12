#pragma once
#include <string>
#include "Point.h"
class TestClass
{
public:
	int value1;
	std::string value2;
	Point p;
	void notOverrideFunc();
	virtual void saySomething();

	void *operator new (size_t size);
	void *operator new (size_t size, std::nothrow_t & noThrow);
};


class ChildTestClass : public TestClass {
public:
	void saySomething() override;
	void notOverrideFunc();

	/*void *operator new (size_t size);
	void *operator new (size_t size, std::nothrow_t &noThrow);*/
};

class TestClassB
{
public:
	TestClassB();
	~TestClassB();

private:

};

class ChildTestClassB : public TestClassB //此处的public共有继承是为了能调用到父类的构造函数，不然无法new出父类了
{
public:
	ChildTestClassB(int a);
};