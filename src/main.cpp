#include "Game.h"

int main(int argc, char const *argv[])
{
    Game game;
    
    if(!game.initSystem("Custom engine", 960, 480, false) ) 
    {
        game.kill();
        return 0;
    }

    game.run();

    return 0;
};
