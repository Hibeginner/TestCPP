#pragma once
#include "Visitor.h"
class BasketBallPlayerPG ://Point Guard 控球后卫 Shoot Guard 得分后卫
    public Visitor
{
public:
    void Visit(BasketBall* ballPtr);
};

