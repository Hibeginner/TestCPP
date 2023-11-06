#include "BasketBallPlayerPG.h"
#include "BasketBall.h"
#include <iostream>

void BasketBallPlayerPG::Visit(BasketBall* ballPtr)
{
	std::cout << "point guard have the ball. pass it."<< ballPtr->ID << std::endl;
}
