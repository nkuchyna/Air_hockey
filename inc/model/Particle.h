#ifndef PARTICLE_H
#define PARTICLE_H
#include "Aero_hockey.h"
#define MAX_VELOCITY 100
extern const int     gWidth;
extern const int     gHeight;

class Particle
{
public:
    Particle(Vec2f pos = Vec2f(), eTextures type = PUCK, Vec2f dir = Vec2f(), int velocity = 0);
    ~Particle();

    int         getX() const;
    int         getY() const;
    eTextures   getType() const;

    Vec2f       getPos() const;
    Vec2f       getDir() const;
    int         getVelocity() const;
    Vec2f       getCenter() const;
    
    void        setX(int x);
    void        setY(int y);
    void        setType(eTextures type);
    void        setDir(Vec2f direction);
    void        setVelocity(int val);
    void        addVelocity(int dVelocity);
    void        subVelocity(int dVelocity);

    virtual void    move();
    virtual void    smothMove();

protected:
    Vec2f           pos;
    Vec2f           center;
    eTextures       type;
    Vec2f           direction;    
    float           velocity;
};

#endif
