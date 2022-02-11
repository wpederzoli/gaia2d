#include "PlayerDemo.h"

PlayerDemo::PlayerDemo(){};

PlayerDemo::~PlayerDemo(){};

bool PlayerDemo::init()
{
    if(!this->initSystem("Player demo", 800, 600, false))
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-sprite.png", Game::getGraphics() ) )
        return false;

    this->player.create(&this->playerImage);

    return true;
};

void PlayerDemo::draw(Graphics* g)
{
    this->player.draw(g);
}