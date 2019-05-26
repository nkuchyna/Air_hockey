#include "Puck.h"

Puck:: Puck(Vec2f pos, eTextures texture) : Particle(pos, texture) {}

Puck::~Puck() {}

void    Puck::move()
{
	if(velocity > 0)
	{
		Vec2f del(this->direction);
		if(velocity > 1)
			del.multiply(SHIFT + velocity * 0.01);
		else
			del.multiply(SHIFT);
		this->pos.add(del);
		--velocity;
	}
	else
		direction = Vec2f(0, 0);
}
