#include "PlayerDemo.h"

int main(int argc, char* argv[])
{
    PlayerDemo game;
    if(!game.init() )
    {
        game.free();
        return 0;
    }

    game.run();
    return 0;
}