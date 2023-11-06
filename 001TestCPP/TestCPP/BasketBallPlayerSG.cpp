#include "BasketBallPlayerSG.h"
#include "BasketBall.h"
#include <iostream>

void BasketBallPlayerSG::Visit(BasketBall* ballPtr)
{
	std::cout << "shoot guard have the ball. shoot." << ballPtr->ID << std::endl;
}
