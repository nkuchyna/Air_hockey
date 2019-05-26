#include "Game.h"

Game::Game()
{
    srand(time(NULL));
    this->screenState = COVER;
    this->running = true;
    std::srand(time(NULL));
    initGameElements();
}

Game::~Game() {}

void    Game::setScreenState(eScreenState state) { this->screenState = state; }

void    Game::initGameElements()
{
    this->gameBackground = partMngr.generate(Vec2f(), MENU_BACKGROUND);
    this->puck = partMngr.generate(Vec2f(::gWidth * 0.45, ::gHeight * 0.47), PUCK);
    this->myPaddle = partMngr.generate(Vec2f(::gWidth * 0.42, ::gHeight * 0.88), PADDLE_MY);
    this->enemyPaddle = partMngr.generate(Vec2f(::gWidth * 0.42, ::gHeight * 0.03), PADDLE_EN);
}

void    Game::executeGameLogic()
{
    this->puck->move();
    // this->enemyLogic();
    if(!physicsModel.borderCollision(this->myPaddle))
        this->myPaddle->smothMove();
    if(!physicsModel.borderCollision(this->enemyPaddle))
        this->enemyPaddle->smothMove();
    if(physicsModel.collision(this->myPaddle, this->enemyPaddle))
        this->enemyPaddle->addVelocity(1);
    if(physicsModel.collision(this->myPaddle, this->puck)
    || physicsModel.collision(this->enemyPaddle, this->puck))
        this->puck->addVelocity(1);
    if(physicsModel.borderCollision(this->puck))
        myPaddle->subVelocity(2);

    switch (physicsModel.checkGoal(this->puck->getCenter()))
    {
        case PLAYER:
            levelManager.playerGoal();
            refreshGame();
            break;
        case ENEMY:
            levelManager.enemyGoal();
            refreshGame();
            break;
        default:
            break;
    }
    //check game status
    eScreenState tmp = this->screenState;
    if((tmp = levelManager.updateScreenStatus()) != GAME_RUNNING)
        this->screenState = tmp;
}

void    Game::refreshGame()
{
    this->puck->setX(::gWidth * 0.45);
    this->puck->setY(::gHeight * 0.47);
    this->puck->setVelocity(0);
    this->enemyPaddle->setX(::gWidth * 0.42);
    this->enemyPaddle->setY(::gHeight * 0.03);
    this->enemyPaddle->setVelocity(0);
    this->myPaddle->setX(::gWidth * 0.42);
    this->myPaddle->setY(::gHeight * 0.88);
    this->myPaddle->setVelocity(0);
}

bool    Game::gameIsRunning()
{
    if(this->screenState == GAME_RUNNING)
        return true;
    return false;
}

bool    Game::menuIsRunning()
{
    if(this->screenState == MENU_RUNNING)
        return true;
    return false;
}

 bool    Game::coverIsRunning()
 {
      if(this->screenState == COVER)
        return true;
    return false;
 }

 bool    Game::nextLevel()
 {
      if(this->screenState == NEXT_LEVEL)
        return true;
    return false;
 }

bool    Game::gameIsFail()
{
    if(this->screenState == FAIL)
        return true;
    return false;
}

bool    Game::gameIsWin()
{
    if(this->screenState == WIN)
        return true;
    return false;
}

bool    Game::processRunning()
{
    if(this->running)
        return true;
    return false;
}

void    Game::updateMenuAction(eKeys key)
{
    Menu::eMenuAction   action = menu.handleKeyEvent(key);
    switch(action)
    {
        case  Menu::PLAY :
            this->screenState = GAME_RUNNING;
            std::cout << "GAME_RUNNING" << std::endl;
            break;
        case  Menu::REFRESH_GAME :
            refreshGame();
            levelManager.refreshGame();
            this->screenState = GAME_RUNNING;
            std::cout << "REFRESH GAME" << std::endl;
            break;
        case Menu::GAME_EXIT :
            this->running = false;
            std::cout << "GAME_EXIT" << std::endl;
            break;
        default :
            return;
    }
}

void    Game::enemyLogic()
{
    Vec2f   dir = puck->getCenter() - enemyPaddle->getCenter();
    float legth = puck->getCenter().distanceTo(enemyPaddle->getCenter());
    dir.normalize();
    enemyPaddle->setDir(dir);
    if(puck->getCenter().y < ::gHeight / 3 && !(rand() % 2))
    {
        enemyPaddle->setVelocity(1);
        if(physicsModel.collision(this->enemyPaddle, this->puck))
            this->puck->addVelocity(1);
    }
    else if(puck->getCenter().y < ::gHeight / 2 && legth > ::gHeight / 3 && !(rand() % 2) )
    {
        enemyPaddle->setVelocity(1);
        if(physicsModel.collision(this->enemyPaddle, this->puck))
            this->puck->addVelocity(1);
    }
    else if(enemyPaddle->getPos().y > ::gHeight * 0.05 && puck->getCenter().y > ::gHeight / 2 && !(rand() % 2))
    {
        Vec2f   dir = Vec2f(::gWidth * 0.42, ::gHeight * 0.03) - enemyPaddle->getPos();
        dir.normalize();
        enemyPaddle->setDir(dir);
        enemyPaddle->setVelocity(1);
    }
    enemyPaddle->smothMove();
}
