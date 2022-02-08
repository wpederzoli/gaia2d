#include "SceneDemo.h"

int main(int argc, char const *argv[])
{
    SceneDemo game;
    if(!game.init() )
    {
        game.free();
        return 0;
    }

    game.run();

    return 0;
};
