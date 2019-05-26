#include "Level.h"

Level::Level() {
    this->levelMap[FIRST] = 2;
    this->levelMap[SECOND] = 3;
    this->levelMap[THIRD] = 4;

    this->currentLevel = FIRST;
    this->playerPoints = 0;
    this->enemyPoints = 0;
}

Level::~Level() {}

eScreenState    Level::updateScreenStatus()
{
    if(this->playerPoints >= this->levelMap[currentLevel]
    && (static_cast<eLevels>(this->currentLevel + 1)) < LEVEL_NBR)
    {
        this->currentLevel = static_cast<eLevels>(this->currentLevel + 1);
        SPlayerSDL::shared.playSound(MOVE);
        return NEXT_LEVEL;
    }
    else if(this->playerPoints >= this->levelMap[currentLevel]
    && static_cast<eLevels>(this->currentLevel + 1) >= LEVEL_NBR)
    {
        SPlayerSDL::shared.playSound(WIN_SOUND);
        return WIN;
    }
    else if(this->enemyPoints >= this->levelMap[currentLevel])
    {
        SPlayerSDL::shared.playSound(FAIL_SOUND);
        return FAIL;
    }
    return GAME_RUNNING;
}

void        Level::enemyGoal()
{
    SPlayerSDL::shared.playSound(MOVE);
    ++this->enemyPoints;
}

void        Level::playerGoal()
{
    SPlayerSDL::shared.playSound(MOVE);
    ++this->playerPoints;
}

void        Level::refreshLevel()
{
    this->playerPoints = 0;
    this->enemyPoints = 0;
}

void        Level::refreshGame()
{
    this->currentLevel = FIRST;
    this->playerPoints = 0;
    this->enemyPoints = 0;
}

std::string     Level::getEnemyPointsStr()
{
    return std::to_string(this->enemyPoints);
}

std::string     Level::getPlayerPointsStr()
{
    return std::to_string(this->playerPoints);
}

std::string     Level::getCurrentLevelStr()
{
    return std::to_string(this->currentLevel);
}

std::string     Level::getLevelPointsStr()
{
    return std::to_string(this->levelMap[currentLevel]);
}
