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
	int a = 3;
	feildA = 3;
	SaySomething();
}

TestClassB::~TestClassB()
{
	int a = 3;
	SaySomething();
}

void TestClassB::SaySomething()
{
	int a = 3;
}

ChildTestClassB::ChildTestClassB(int a)
{
	int b = 3;
	feildB = 3;
	SaySomething();
}

ChildTestClassB::~ChildTestClassB()
{
	int a = 3;
	SaySomething();
}

void ChildTestClassB::SaySomething()
{
	TestClassB::SaySomething();//这里父类的SaySomething会被执行2次，一次在子类的析构时，一次在父类的析构时(因为父类的析构也调用了)。
	feildA = 3;
	int a = 3;
}
