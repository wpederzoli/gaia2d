#include "AnimatedDemo.h"

int main(int argc, char* argv[])
{
    AnimatedDemo game;
    if(!game.init() )
    {
        game.free();
        return 0;
    }

    game.run();

    return 0;
}