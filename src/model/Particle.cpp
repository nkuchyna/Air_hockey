#include "Particle.h"

Particle::Particle(Vec2f pos, eTextures type, Vec2f direction, int velocity) :pos(pos),
																type(type),
																direction(direction),
																velocity(velocity) {}

Particle::~Particle() {}

eTextures   Particle::getType() const { return this->type; }
int     	Particle::getX() const { return this->pos.x; }
int     	Particle::getY() const { return this->pos.y; }
Vec2f   	Particle::getPos() const { return this->pos; }
Vec2f   	Particle::getDir() const { return this->direction; }
int			Particle::getVelocity() const { return this->velocity; }
Vec2f   	Particle::getCenter() const { return Vec2f(pos.x + PADDLE_SIZE / 2, pos.y + PADDLE_SIZE / 2); }

void    	Particle::setX(int x) { this->pos.x = x; }
void    	Particle::setY(int y) { this->pos.y = y; }
void    	Particle::setType(eTextures type) { this->type = type; }
void		Particle::setDir(Vec2f direction) { this->direction.set(direction); }
void    	Particle::setVelocity(int val) { this->velocity = val; }

void		Particle::addVelocity(int velocity)
{
	if((this->velocity += velocity) > MAX_VELOCITY)
		this->velocity = MAX_VELOCITY;
}

void	Particle::subVelocity(int dVelocity)
{
	if((this->velocity -= dVelocity) < 0)
		this->velocity = 0;
}

void	Particle::move()
{
	if(velocity > 0)
	{
		Vec2f del(this->direction);
		del.multiply(LSHIFT);
		this->pos.add(del);
		--velocity;
	}
}

void	Particle::smothMove()
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
