#ifndef MENU_H
#define MENU_H
#define MAIN_MENU_ITEM_NBR      3
#include "IRender.h"
#include <vector>

extern const int     gWidth;
extern const int     gHeight;

class Menu
{
    public:
        Menu();
        ~Menu();

    enum eMenuState
    {
        MAIN,
        STRATEGY,
        MENU_NBR
    };

    enum eMenuAction
    {
        PLAY,
        REFRESH_GAME,
        GAME_EXIT,
        NBR_MENU_ACTION
    };

    struct MenuItem
    {
        int                 width;
        int                 height;
        Menu::eMenuAction   action;
        std::string         title;
    };

    Menu::eMenuAction   handleKeyEvent(eKeys key);
    Menu::eMenuState    getState() const;
    int                 getPos() const;
    void                setPos(int pos);
    std::vector<MenuItem>   mainMenu;
    // eMenuAction    handleClick(int x, int y);

private:
    eMenuState              state;
    int                     pos;
};

#endif
