#include "Paddle.h"

Paddle:: Paddle(Vec2f pos, eTextures texture) : Particle(pos, texture) {}

Paddle::~Paddle() {}

void    Paddle::move()
{
	if(velocity > 0)
	{
		Vec2f del(this->direction);
		del.multiply(LSHIFT);
		this->pos.add(del);
		--velocity;
	}
}
