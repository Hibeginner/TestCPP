#pragma once

#ifndef POINT_H
#define POINT_H

#pragma message("正在编译Point.h  ...")//测试被同一个文件include时，会不会执行多次

#define TEST_MULTI_INCLUDE 100 //测试会不会重复定义

#include <vector>
#include <string>

class Point
{
public:
	Point();

	Point(int a, int b);

	Point(const Point & p);
	Point(Point && tempP) noexcept;
	~Point();

	void *operator new(size_t size);
	void *operator new(size_t size, std::nothrow_t &);

	int x;
	int y;

	static int staticInt;
	static std::vector<std::string> staticVector;
};

#endif // !POINT_H




