#include "PlayerDemo.h"

PlayerDemo::PlayerDemo()
{
    this->scene = NULL;
    this->entity = NULL;
};

PlayerDemo::~PlayerDemo(){};

bool PlayerDemo::init()
{
    if(!this->initSystem("Player demo", 800, 600, false))
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-sprite.png", Game::getGraphics() ) )
        return false;

    EntityBuilder eb(0);
    this->camera.set(0, 0, 100, 200);
    // this->player.create(0, &this->playerImage, 100, 200);
    this->entity = eb.setSingleImage(&playerImage).setPosition(100, 200).setDimensions(100, 100).build();
    this->scene = new Scene();
    // this->scene->addNode(&player);
    // this->scene->addNode(entity);
    this->scene->addNode(this->entity);

    return true;
};

void PlayerDemo::draw(Graphics* g)
{
    this->scene->draw(&this->camera, g);
};