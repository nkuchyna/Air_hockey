#ifndef GAME_H
#define GAME_H
#include "Aero_hockey.h"
#include "Menu.h"
#include "ParticleManager.h"
#include "Physics.h"
#include "Level.h"
#include <ctime>
#include <cstdlib>
#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void    setScreenState(eScreenState state);

    void    initGameElements();
    void    executeGameLogic(); //game loop
    void    refreshGame();
    bool    processRunning();
    bool    gameIsRunning();
    bool    menuIsRunning();
    bool    gameIsFail();
    bool    gameIsWin();
    bool    coverIsRunning();
    bool    nextLevel();
    void    updateMenuAction(eKeys key);
    void    enemyLogic();

    Menu                    menu;
    Level                   levelManager;
    ParticleManager         partMngr;
    Physics                 physicsModel;

    Particle*              gameBackground;
    Particle*              puck;
    Particle*              enemyPaddle;
    Particle*              myPaddle;

private:
    eScreenState    screenState;
    bool            running;
};

#endif
