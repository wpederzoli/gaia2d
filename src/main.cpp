#include "AnimatedDemo.h"

int main(int argc, char const *argv[])
{
    AnimatedDemo game;
    if(!game.init() )
    {
        game.free();
        return 0;
    }

    game.run();

    return 0;
};
