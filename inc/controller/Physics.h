#ifndef PHYSICS_H
#define PHYSICS_H
#include "Particle.h"
#include "Puck.h"
#include "Paddle.h"
#include <vector>

extern const int     gGates_MAX;
extern const int     gGates_MIN;

enum ePlayers
{
	ENEMY,
	PLAYER,
	NOBODY
};

struct Plane
{
	Vec2f	norm;
	Vec2f	pos;
	Plane(Vec2f	norm, Vec2f	pos) : norm(norm), pos(pos) {}
};

class Physics
{
public:
    Physics();
    ~Physics();

	bool		collision(const Particle *part1, Particle *part2);
	bool		staticCollision(const Particle *part1, const Particle *part2);
	bool		borderCollision(Particle *part1);
	ePlayers	checkGoal(const Vec2f &center);

private:
	Vec2f		calcDirAfterCollision(const Particle *paddle, const Particle *puck);
	void		switchDir(Particle *puck, const Vec2f &norm);
	bool		freeWorldCollision(Particle *part1, const Vec2f &shiftPos);
	bool		fixedWorldCollision(const Vec2f &shiftPos);

	std::vector<Plane>	worldBarier;
};

#endif
