#ifndef PUCK_H
#define PUCK_H
#include "Particle.h"

class Puck : public Particle
{
public:
    Puck(Vec2f pos = Vec2f(), eTextures texture = PADDLE_EN);
    ~Puck();

    void	move() override;
};

#endif
