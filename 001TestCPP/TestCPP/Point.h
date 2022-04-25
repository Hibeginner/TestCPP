#pragma once

#ifndef POINT_H
#define POINT_H

#pragma message("���ڱ���Point.h  ...")//���Ա�ͬһ���ļ�includeʱ���᲻��ִ�ж��

#define TEST_MULTI_INCLUDE 100 //���Ի᲻���ظ�����

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




