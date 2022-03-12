#include "TestClass.h"

void TestClass::notOverrideFunc()
{
	int a = 2;
}

void TestClass::saySomething()
{
	int a = 2;
}

void ChildTestClass::saySomething()
{
	int a = 3;
}

void ChildTestClass::notOverrideFunc()
{
	int a = 3;
}
