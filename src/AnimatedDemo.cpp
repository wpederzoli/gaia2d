#include "AnimatedDemo.h"

bool AnimatedDemo::init()
{
    if(!this->initSystem("Animation test", 800, 600, false) )
        return false;
    if(!this->map.load("feature-examples/graphics/map.map", "feature-examples/graphics/tiles.png", Game::getGraphics()) )
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-sprite.png", Game::getGraphics()) )
        return false;

    this->player = new Player(0, 100, 200, 50, 50, true, &this->map);
    this->player->addAnimation(&playerImage, 0, 65, 71, 1, 16);
    this->player->addAnimation(&playerImage, 1, 65, 71, 17, 36);
    this->player->playAnimation(0);
    this->player->setAnimationGlobalSpeed(27);

    this->camera.set(0, 0, 800, 600);
    this->scene.addNode(this->player);

    return true;
};

void AnimatedDemo::free()
{
    printf("free resources\n");
};

void AnimatedDemo::update()
{
    Input *in = Game::getInput();
    if(in->keyDown(SDL_SCANCODE_RIGHT) )
    {
        this->player->move(this->player->getSpeed(), 0);
        this->player->playAnimation(1);
    }
    else
    {
        this->player->playAnimation(0);
    }
    if(in->keyDown(SDL_SCANCODE_LEFT))
        this->player->move(-this->player->getSpeed(), 0);
    if(in->keyDown(SDL_SCANCODE_UP) )
        this->player->move(0, -this->player->getSpeed() );
    if(in->keyDown(SDL_SCANCODE_DOWN) )
        this->player->move(0, this->player->getSpeed() );
};


void AnimatedDemo::draw(Graphics* g)
{
    this->map.draw(1, 0, 0, g);
    this->map.draw(2, 0, 0, g);
    this->map.draw(3, 0, 0, g);
    this->map.draw(0, 0, 0, g);
    this->scene.draw(&this->camera, g);
};