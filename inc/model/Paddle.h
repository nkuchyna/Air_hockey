#ifndef PADDLE_H
#define PADDLE_H
#include "Particle.h"

class Paddle : public Particle
{
public:
	Paddle(Vec2f pos = Vec2f(), eTextures texture = PADDLE_MY);
    ~Paddle();
    void	move() override;
};

#endif
