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