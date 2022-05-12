#pragma once
#include "MemberFuncReflection.h"

#include <iostream>
#include <vector>
#include <string>

struct MemberFuncTestClassA
{
	double func(int a)
	{
		std::cout << "func(" << a << ") ";
		return 3.41;
	}
	int fun2(char b)
	{
		std::cout << "fun2('" << b << "') ";
		return 50;
	}

	/*std::string fun3(const std::string& prefix)
	{
		std::string tempStr = prefix + std::string("cde");
		return tempStr;
	}*/
};