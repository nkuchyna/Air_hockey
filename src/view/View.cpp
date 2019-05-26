#include "View.h"
#define WIDTH(a) (rTextSizes[a].second)
#define HEIGHT(a) (rTextSizes[a].second)

View::View(Game &game) : game(game) {
    this->render = new SDLRender();
}
View::~View() {
    if(this->render)
        delete this->render;
}

eKeys   View::updateEvent()
{
    return this->render->keyBoardEvent();
}

void    View::drawCover()
{
    this->render->clearWindow();
    this->render->drawTexture(MENU_BACKGROUND, 0, 0);
    this->render->drawAnimation(NEXT_LEVEL_ANIMATION, ::gWidth * 0.06, ::gHeight * 0.37);
    this->render->renderText("AIR HOCKEY", ::gWidth * 0.38, ::gHeight * 0.45, WIN_FAIL_FONT, HIGHLIGHT);
    this->render->renderText("Tap any key to load menu...", 30, ::gHeight - 60, MENU_FONT, ORDINARY);
    this->render->updateWindow();
}

void    View::drawGame() {

    this->render->clearWindow();
    this->render->drawTexture(GAME_BACKGROUND, 0, 0);
    this->render->drawTexture(game.puck->getType(), game.puck->getX(), game.puck->getY());
    this->render->drawTexture(game.enemyPaddle->getType(), game.enemyPaddle->getX(), game.enemyPaddle->getY());
    this->render->drawTexture(game.myPaddle->getType(), game.myPaddle->getX(), game.myPaddle->getY());
    this->render->renderText("Level: " + game.levelManager.getCurrentLevelStr(), ::gWidth * 0.04, ::gHeight * 0.01, MENU_FONT, ORDINARY);
    this->render->renderText("get " + game.levelManager.getLevelPointsStr() + "points", ::gWidth * 0.04, ::gHeight * 0.07, INFO_FONT, ORDINARY);
    this->render->renderText(game.levelManager.getEnemyPointsStr(), ::gWidth * 0.9, ::gHeight * 0.42, MENU_FONT, ORDINARY);
    this->render->renderText(game.levelManager.getPlayerPointsStr(), ::gWidth * 0.9, ::gHeight * 0.52, MENU_FONT, ORDINARY);
    this->render->updateWindow();
}

void    View::drawMenu() {
    this->render->clearWindow();
    int x = ::gWidth * 0.4;
    int y = ::gHeight * 0.35;
    int counter = 0;
    this->render->drawTexture(MENU_BACKGROUND, 0, 0);
    if(game.menu.getState() == Menu::MAIN)
    {
        for(auto &it : game.menu.mainMenu)
        {
            if(counter == game.menu.getPos())
                this->render->renderText(it.title, x, y, MENU_FONT, HIGHLIGHT);
            else
                this->render->renderText(it.title, x, y, MENU_FONT, ORDINARY);
            counter++;
            y += ::gHeight * 0.08;
        }
    }
    this->render->updateWindow();
}

void    View::drawWin() {
    this->render->clearWindow();
    this->render->drawTexture(MENU_BACKGROUND, 0, 0);
    this->render->drawAnimation(NEXT_LEVEL_ANIMATION, ::gWidth * 0.06, ::gHeight * 0.37);
    this->render->renderText("YOU WIN!", ::gWidth * 0.43, ::gHeight * 0.45, WIN_FAIL_FONT, HIGHLIGHT);
    this->render->renderText("Tap any key to load menu...", 30, ::gHeight - 60, MENU_FONT, ORDINARY);
    this->render->updateWindow();
}

void    View::drawFail() {

    this->render->clearWindow();
    this->render->drawTexture(MENU_BACKGROUND, 0, 0);
    this->render->drawAnimation(NEXT_LEVEL_ANIMATION, ::gWidth * 0.06, ::gHeight * 0.37);
    this->render->renderText("FAIL!", ::gWidth * 0.5, ::gHeight * 0.45, WIN_FAIL_FONT, HIGHLIGHT);
    this->render->renderText("Tap ESC key to load menu...", 30, ::gHeight - 60, MENU_FONT, ORDINARY);
    this->render->updateWindow();
}

void    View::drawNextLevel() {

    this->render->clearWindow();
    this->render->drawTexture(MENU_BACKGROUND, 0, 0);
    this->render->drawAnimation(NEXT_LEVEL_ANIMATION, ::gWidth * 0.06, ::gHeight * 0.37);
    this->render->renderText("NEXT LEVEL", ::gWidth * 0.4, ::gHeight * 0.45, WIN_FAIL_FONT, HIGHLIGHT);
    this->render->renderText("Tap any key to load menu...", 30, ::gHeight - 60, MENU_FONT, ORDINARY);
    this->render->updateWindow();
}
