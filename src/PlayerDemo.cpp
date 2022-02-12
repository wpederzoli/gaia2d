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

    EntityBuilder eb;
    // AnimatedEntityBuilder eb(0);
    this->camera.set(0, 0, 100, 200);
    // this->player.create(0, &this->playerImage, 100, 200);
    this->entity = eb.id(0)->image(&playerImage)->position(10, 20)->dimensions(100, 200)->build();
    // this->animatedEntity = eb.setSprite(&playerImage).addAnimation(0, 65, 71, 1, 16).build();
    // this->animatedEntity->play(Game::getGraphics() );
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