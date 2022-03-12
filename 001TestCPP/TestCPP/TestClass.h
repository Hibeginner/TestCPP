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
};


class ChildTestClass : public TestClass {
public:
	void saySomething() override;
	void notOverrideFunc();
};