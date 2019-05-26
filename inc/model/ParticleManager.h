#ifndef PARTICLE_MANAGER
#define PARTICLE_MANAGER
#include <unordered_map>
#include "Aero_hockey.h"
#include "Particle.h"
#include "Puck.h"
#include "Paddle.h"


class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();

    Particle*   generate(Vec2f pos, eTextures type);
};

#endif