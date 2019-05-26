#include "Menu.h"
#include <iostream>

Menu::Menu() {
    this->pos = 0;
    mainMenu.reserve(MAIN_MENU_ITEM_NBR);
    mainMenu.push_back({10, 10, Menu::PLAY, "PLAY"});
    mainMenu.push_back({10, 10, Menu::REFRESH_GAME, "NEW GAME"});
    mainMenu.push_back({10, 10, Menu::GAME_EXIT, "EXIT"});
    this->state =  Menu::MAIN;
}

Menu::~Menu() {}

 Menu::eMenuAction    Menu::handleKeyEvent(eKeys key)
 {
     switch(key)
     {
        case UP:
            if(this->pos > 0)
             {
                this->pos--;
                SPlayerSDL::shared.playSound(CLICK);
             }
            break;
        case DOWN:
            if(this->pos < MAIN_MENU_ITEM_NBR - 1)
            {
                this->pos++;
                SPlayerSDL::shared.playSound(CLICK);
            }
            break;
        case ENTER:
            return (static_cast<Menu::eMenuAction>(this->pos));
        case EXIT:
            return Menu::GAME_EXIT;
        default:
            return Menu::NBR_MENU_ACTION;
    }
    return  Menu::NBR_MENU_ACTION;
 }

 Menu::eMenuState     Menu::getState() const
 {
     return this->state;
 }

int         Menu::getPos() const
{
    return this->pos;
}

void        Menu::setPos(int pos)
{
    this->pos = pos;
}