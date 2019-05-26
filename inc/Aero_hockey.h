#ifndef AERO_HOCKEY
#define AERO_HOCKEY
#include "Vector.h"
#include "ISPlayer.h"
#include "SPlayerSDL.h"
#include <iostream>
#include <string>

#define SHIFT 10
#define LSHIFT  20
#define VELOCITY  60

#define PADDLE_SIZE  80
// #define PUCK_SIZE 60

enum    eKeys
{
    NONE = -1,
    DEFAULT = 0,
    UP,
    RIGHT,
    DOWN,
    LEFT,
    EXIT,
    MENU,
    ENTER,
    NBR_KEYS
};

enum    eDir
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NBR_DIR
};

enum    eTextures
{
    MENU_BACKGROUND,
    GAME_BACKGROUND,
    PUCK,
    PADDLE_EN,
    PADDLE_MY,
    TEXTURES_NBR
};

enum eAnimation
{
    TRY_AGAIN,
    NEXT_LEVEL_ANIMATION,
    YOU_WIN,
    ANIMATIONS_NBR
};

enum eScreenState
{
    COVER,
    MENU_RUNNING,
    GAME_RUNNING,
    NEXT_LEVEL,
    TIME_IS_OUT,
    WIN,
    FAIL,
    STRATEGY,
    NBR_SCREEN_STATE
};

#endif
