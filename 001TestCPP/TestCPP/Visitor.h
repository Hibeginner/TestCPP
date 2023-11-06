#pragma once
#ifndef __VISITOR_H_
#define __VISITOR_H_

//#include "BasketBall.h"//这里会有类的循环引用问题
class BasketBall;
class Visitor
{
public:
	virtual void Visit(BasketBall* ballPtr) = 0;
};


#endif // !__VISITOR_H_