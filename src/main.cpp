#include "Controller.h"
#include "Aero_hockey.h"
#include "ErrorException.h"

const int     gWidth = 520;
const int     gHeight = 770;
const int     gGates_MAX = 370;
const int     gGates_MIN = 150;

int     main(int argc, char **argv)
{
    Controller      controller;
    try
    {
         controller.launchGame();
    }
    catch(std::exception &ex)
    {
        std::cout << "Error!" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    return 0;
}