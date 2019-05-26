#include "Physics.h"
#include <cmath>

Physics::Physics()
{
    worldBarier.push_back(Plane(Vec2f(-1, 0), Vec2f(::gWidth, 0)));
    worldBarier.push_back(Plane(Vec2f(1, 0), Vec2f(0, 0)));
    worldBarier.push_back(Plane(Vec2f(0, -1), Vec2f(0, ::gHeight)));
    worldBarier.push_back(Plane(Vec2f(0, 1), Vec2f(0, 0)));
}

Physics::~Physics() {}

bool    Physics::collision(const Particle *part1, Particle *part2)
{  
    float dist = part1->getPos().distanceTo(part2->getPos());
    if(dist < (PADDLE_SIZE - SHIFT))
    {
        part2->setDir(calcDirAfterCollision(part1, part2));
        part2->addVelocity(VELOCITY);
        return true;
    }
    return false;
}

bool    Physics::staticCollision(const Particle *part1, const Particle *part2)
{  
    float dist = part1->getPos().distanceTo(part2->getPos());
    if(dist < (PADDLE_SIZE - SHIFT))
        return true;
    return false;
}

bool    Physics::borderCollision(Particle *part1)
{
    Vec2f shiftPos = part1->getCenter() + part1->getDir() * PADDLE_SIZE / 2;
    if((dynamic_cast<Puck*>(part1) != nullptr && freeWorldCollision(part1, shiftPos))
    || (dynamic_cast<Paddle*>(part1) != nullptr && fixedWorldCollision(shiftPos)))
        return true;
    return false;
}

Vec2f    Physics::calcDirAfterCollision(const Particle *paddle, const Particle *puck)
{
    Vec2f   dir = puck->getCenter()- paddle->getCenter();
    dir.normalize();
    return dir;
}

void    Physics::switchDir(Particle *puck, const Vec2f &norm)
{
    Vec2f dir = puck->getDir();
    dir = dir - norm * 2 * norm.dot(dir);
    puck->setDir(dir);
}

bool        Physics::freeWorldCollision(Particle *part1, const Vec2f &shiftPos)
{
    //gates
    if(!(shiftPos.x > ::gGates_MAX ||  shiftPos.x < ::gGates_MIN)
        && (shiftPos.y <= SHIFT || shiftPos.y >= ::gHeight - SHIFT))
        return false;
    //general
    if(shiftPos.x <= SHIFT)
        switchDir(part1, worldBarier[1].norm);
    else if(shiftPos.x >= ::gWidth - SHIFT)
        switchDir(part1, worldBarier[0].norm);
    else if(shiftPos.y <= SHIFT)
        switchDir(part1, worldBarier[3].norm);
    else if(shiftPos.y >= ::gHeight - SHIFT)
        switchDir(part1, worldBarier[2].norm);
    else
        return false;
    return true;
}

bool        Physics::fixedWorldCollision(const Vec2f &shiftPos)
{
    if(!(shiftPos.x > ::gGates_MAX ||  shiftPos.x < ::gGates_MIN)
        && (shiftPos.y <= SHIFT || shiftPos.y >= ::gHeight - SHIFT))
        return false;
    if(shiftPos.x <= SHIFT || shiftPos.x >= ::gWidth - SHIFT
    || shiftPos.y <= SHIFT || shiftPos.y >= ::gHeight - SHIFT)
        return true;
    return false;
}

ePlayers    Physics::checkGoal(const Vec2f &center)
{
    if(center.y <= 0)
        return PLAYER;
    else if(center.y >= ::gHeight)
        return ENEMY;
    return NOBODY;
}
