#include "BasketBall.h"

BasketBall::BasketBall()
{
	ID = 1;
}

void BasketBall::Accept(Visitor* visitorPtr)
{
	visitorPtr->Visit(this);
}
