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
	virtual ~TestClassB();//有虚函数的类，析构函数一定要做成virtual的，不然TestClassB *parentPtr = new ChildTestClassB(1); delete parentPtr;这样不会走子类的析构

	virtual void SaySomething();
	int feildA;
private:

};

class ChildTestClassB : public TestClassB //此处的public共有继承是为了能调用到父类的构造函数，不然多态的方式(TestClassB *parentPtr = new ChildTestClassB(1);)无法new出父类了(不允许对不可访问的基类进行转换，因为子类里无法访问父类，虽然可以构造)
{
public:
	ChildTestClassB(int a);
	~ChildTestClassB();

	void SaySomething() override;
	int feildB;
};