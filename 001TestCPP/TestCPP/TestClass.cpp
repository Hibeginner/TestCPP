#include "TestClass.h"

void TestClass::notOverrideFunc()
{
	int a = 2;
}

void TestClass::saySomething()
{
	int a = 2;
}

void *TestClass::operator new(size_t size)
{
	return malloc(size);
}

void *TestClass::operator new(size_t size, std::nothrow_t &noThrow)
{
	return malloc(size);
}

void ChildTestClass::saySomething()
{
	int a = 3;
}

void ChildTestClass::notOverrideFunc()
{
	int a = 3;
}

//void *ChildTestClass::operator new(size_t size)
//{
//	return malloc(size);
//}
//
//void *ChildTestClass::operator new(size_t size, std::nothrow_t &noThrow)
//{
//	return malloc(size);
//}

TestClassB::TestClassB()
{
}

TestClassB::~TestClassB()
{
}

ChildTestClassB::ChildTestClassB(int a)
{
}
