#include "ParticleManager.h"

ParticleManager::ParticleManager() {}

ParticleManager::~ParticleManager() {}

 Particle*      ParticleManager::generate(Vec2f pos, eTextures type)
 {
    switch(type)
    {
        case MENU_BACKGROUND:
            return new Particle(pos, MENU_BACKGROUND);
        case GAME_BACKGROUND:
            return new Particle(pos, GAME_BACKGROUND);
        case PUCK:
            return new Puck(pos, PUCK);
        case PADDLE_EN:
            return new Paddle(pos, PADDLE_EN);
        case PADDLE_MY:
            return new Paddle(pos, PADDLE_MY);
        default:
            return nullptr;
    }
 }
