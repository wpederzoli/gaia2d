#include "PlayerDemo.h"

PlayerDemo::PlayerDemo(){};

PlayerDemo::~PlayerDemo(){};

bool PlayerDemo::init()
{
    if(!this->initSystem("Player demo", 800, 600, false))
        return false;
    
    this->player.create(&this->playerImage);

    return true;
};