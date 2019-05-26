#ifndef VIEW_H
#define VIEW_H
#include "Game.h"
#include "SDLRender.h"
#include "Animation.h"

class View
{
public:
    View(Game &game);
    ~View();

    eKeys   updateEvent();
    void    drawCover();
    void    drawGame();
    void    drawMenu();
    void    drawWin();
    void    drawFail();
    void    drawNextLevel();

    //void  configureSounds();
    //void  configureButtons();
    //void  configureScreen();

private:
    IRender     *render;
    Game        &game; //model
};

#endif
