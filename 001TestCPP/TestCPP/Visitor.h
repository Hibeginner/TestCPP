#pragma once
#ifndef __VISITOR_H_
#define __VISITOR_H_

//#include "BasketBall.h"//����������ѭ����������
class BasketBall;
class Visitor
{
public:
	virtual void Visit(BasketBall* ballPtr) = 0;
};


#endif // !__VISITOR_H_