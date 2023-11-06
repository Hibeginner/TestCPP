#pragma once
#ifndef __BALL_H_
#define __BALL_H_

#include "Visitor.h"

class Ball
{
public:
	virtual void Accept(Visitor* visitorPtr) = 0;
};

#endif // !__BALL_H_
