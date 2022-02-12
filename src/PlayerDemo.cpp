#include "PlayerDemo.h"

PlayerDemo::PlayerDemo()
{
    this->scene = NULL;
};

PlayerDemo::~PlayerDemo(){};

bool PlayerDemo::init()
{
    if(!this->initSystem("Player demo", 800, 600, false))
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-sprite.png", Game::getGraphics() ) )
        return false;

    this->camera.set(0, 0, 100, 200);
    this->player.create(&this->playerImage);
    this->scene = new Scene();
    this->scene->addNode(&player);

    return true;
};

void PlayerDemo::draw(Graphics* g)
{
    this->scene->draw(&this->camera, g);
};