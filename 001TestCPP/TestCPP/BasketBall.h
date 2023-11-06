#pragma once
#ifndef __BASKETBALL_H_
#define __BASKETBALL_H_
#include "Ball.h"

class BasketBall :
    public Ball
{
public:
    BasketBall();
    void Accept(Visitor* visitorPtr);
    int ID;
};
#endif // !__BASKETBALL_H_
