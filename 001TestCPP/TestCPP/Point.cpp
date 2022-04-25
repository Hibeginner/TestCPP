#include "Point.h"

#ifndef TEST_MULTI_INCLUDE
#define TEST_MULTI_INCLUDE 101
#endif // !TEST_MULTI_INCLUDE


int globalInt = 24;

int testGlobalFunc(int a, int b) {
	return a + b;
}

int Point::staticInt = 33;
std::vector<std::string> Point::staticVector = std::vector<std::string>();


Point::Point()
{
	this->x = 0;
	this->y = 0;

	Point::staticVector.push_back("33");
}

Point::Point(int a, int b)
{
	this->x = a;
	this->y = b;
}

Point::Point(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
}

Point::Point(Point &&tempP) noexcept
{
	this->x = tempP.x;
	this->y = tempP.y;
}

Point::~Point() {
	this->x = 0;
	this->y = 0;
}

void *Point::operator new(size_t size)
{
	return malloc(size);
}

void *Point::operator new(size_t size, std::nothrow_t & noThrow)
{
	return malloc(size);
}
