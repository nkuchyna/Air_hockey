#ifndef IRENDER_H
#define IRENDER_H
#include "ErrorException.h"
#include "Aero_hockey.h"

enum    eFonts
{
    MENU_FONT = 0,
    GAME_FONT,
    INFO_FONT,
    WIN_FAIL_FONT,
    FONTS_NBR
};

enum eColors
{
    ORDINARY,
    HIGHLIGHT,
    COLORS_NBR
};

class IRender
{
public:
    virtual eKeys   keyBoardEvent() = 0;
    virtual void    drawTexture(eTextures type, int x, int y) = 0;
    virtual void    drawAnimation(eAnimation type, int x, int y) = 0;
    virtual void    clearWindow() = 0;
    virtual void    updateWindow() = 0;
    virtual void    renderText(std::string text, int x, int y, eFonts font, eColors color) = 0;
    virtual ~IRender() {};
};

#endif