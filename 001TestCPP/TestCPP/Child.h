#pragma once
#include "Parent.h"
class Child : Parent
{
public:
	Child();
	Child(int a);

	virtual void SaySomething() override;
};

