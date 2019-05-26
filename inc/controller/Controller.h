#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h"
#include "Physics.h"

class Controller
{
public:
    Controller();
    ~Controller();

    void    launchGame();
    
private:
    Game       game; //model - contains all of game objects and logic of game loop
    View       *view; //render and all logic of game drawing + configuration of keys and window

    void    processGameInput();
    void    processMenuInput();
    bool    pressAnyKey();
    bool	pressESC();
};

#endif