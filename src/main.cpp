#include "AnimatedDemo.h"

int main(int argc, char* argv[])
{
    AnimatedDemo game;
    if(!game.init() )
    {
        game.kill();
        return 0;
    }

    game.run();

    return 0;
}