#include "PlayerDemo.h"

PlayerDemo::PlayerDemo()
{
    this->scene = NULL;
    this->entity = NULL;
    this->animatedEntity = NULL;
};

PlayerDemo::~PlayerDemo(){};

bool PlayerDemo::init()
{
    if(!this->initSystem("Player demo", 800, 600, false))
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-sprite.png", Game::getGraphics() ) )
        return false;

    AnimatedEntityBuilder eb;
    // AnimatedEntityBuilder eb(0);
    this->camera.set(0, 0, 100, 200);
    // this->player.create(0, &this->playerImage, 100, 200);
    // this->entity = eb.id(0)->build();
    this->animatedEntity = eb.id(0)->image(&playerImage)->build();
    // this->animatedEntity->play(Game::getGraphics() );
    this->scene = new Scene();
    // this->scene->addNode(&player);
    // this->scene->addNode(entity);
    this->scene->addNode(this->animatedEntity);

    return true;
};

void PlayerDemo::draw(Graphics* g)
{
    this->scene->draw(&this->camera, g);
};