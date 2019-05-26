#include "Controller.h"

Controller::Controller() { this->view  = new View(this->game); }

Controller::~Controller() {}

void    Controller::launchGame()
{
    const int	FPS = 60;
	const int	frame_delay = 1000 / FPS;
	unsigned	frame_start;

    while(this->game.processRunning())
    {
        //cover_loop
        while(this->game.coverIsRunning())
        {
            SPlayerSDL::shared.stopMusic();
            this->view->drawCover();
            if(pressAnyKey())
                this->game.setScreenState(MENU_RUNNING);
        }
        //menu_loop
        SPlayerSDL::shared.playMusic(MENU_MUSIC);
        while(this->game.menuIsRunning() && this->game.processRunning())
        {
            this->game.updateMenuAction(this->view->updateEvent());
            this->view->drawMenu();
        }
        //game loop
        SPlayerSDL::shared.playMusic(GAME_MUSIC);
        while(this->game.gameIsRunning())
        {
            this->view->drawGame();
            frame_start = SDL_GetTicks();
            processGameInput();
            this->game.executeGameLogic();
            while(SDL_GetTicks() - frame_start < 1000/FPS);
        }
        //fail loop
        while(this->game.gameIsFail())
        {
            SPlayerSDL::shared.stopMusic();
            frame_start = SDL_GetTicks();
            this->view->drawFail();
            while(SDL_GetTicks() - frame_start < 1000/FPS);
            if(pressESC())
            {
                this->game.setScreenState(MENU_RUNNING);
                this->game.levelManager.refreshGame();
                this->game.refreshGame();
            }
        }
        //win loop
        while(this->game.gameIsWin())
        {
            frame_start = SDL_GetTicks();
            this->view->drawWin();
            while(SDL_GetTicks() - frame_start < 1000/FPS);
            if(pressAnyKey())
            {
                this->game.setScreenState(MENU_RUNNING);
                this->game.levelManager.refreshLevel();
                this->game.refreshGame();
            }
        }
        //next_level loop
        while(this->game.nextLevel())
        {
            frame_start = SDL_GetTicks();
            this->view->drawCover();
            while(SDL_GetTicks() - frame_start < 1000/FPS);
            if(pressAnyKey())
            {
                this->game.setScreenState(GAME_RUNNING);
                this->game.levelManager.refreshLevel();
            }
        }
        this->game.menu.setPos(0);
    }
}

void    Controller::processGameInput()
{
    switch(this->view->updateEvent())
    {
        case EXIT :
            std::cout << "You are in the menu" << std::endl;
            this->game.setScreenState(MENU_RUNNING);
            break;
        case UP :
            if(this->game.gameIsRunning())
            {
                this->game.myPaddle->setDir(Vec2f(0, -1));
                this->game.myPaddle->addVelocity(1);
            }
            break;
        case RIGHT :
            if(this->game.gameIsRunning())
            {
                this->game.myPaddle->setDir(Vec2f(1, 0));
                this->game.myPaddle->addVelocity(1);
            }
            break;
        case LEFT :
            if(this->game.gameIsRunning())
            {
                this->game.myPaddle->setDir(Vec2f(-1, 0));
                this->game.myPaddle->addVelocity(1);
            }
            break;
        case DOWN :
            if(this->game.gameIsRunning())
            {
                this->game.myPaddle->setDir(Vec2f(0, 1));
                this->game.myPaddle->addVelocity(1);
            }
            break;
        default:
            return;
    }
}

bool    Controller::pressAnyKey()
{
    if(this->view->updateEvent() != NONE)
        return true;
    return false;
}

bool    Controller::pressESC()
{
    if(this->view->updateEvent() == EXIT)
        return true;
    return false;
}

void    Controller::processMenuInput() { game.updateMenuAction(this->view->updateEvent()); }
