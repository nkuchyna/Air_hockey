#ifndef LEVEL_H
#define LEVEL_H
#include <unordered_map>
#include "Aero_hockey.h"

class Level
{
public:
    Level();
    ~Level();

enum    eLevels
{
    FIRST,
    SECOND,
    THIRD,
    LEVEL_NBR
};

eScreenState    updateScreenStatus();
void            refreshLevel();
void            refreshGame();
void            enemyGoal();
void            playerGoal();
std::string     getEnemyPointsStr();
std::string     getPlayerPointsStr();
std::string     getCurrentLevelStr();
std::string     getLevelPointsStr();

private:
    std::unordered_map<eLevels, int>  levelMap; //1 - level, 2 - win points, 3 - max time
    int         playerPoints;
    int         enemyPoints;
    eLevels     currentLevel;
    // int         currentTime;
};

#endif