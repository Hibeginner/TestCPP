#pragma once
#include "Visitor.h"
class BasketBallPlayerSG :
    public Visitor
{
public:
    void Visit(BasketBall* ballPtr);
};

