#include "AnimatedDemo.h"

bool AnimatedDemo::init()
{
    if(!this->initSystem("Animation test", 800, 600, false) )
        return false;
    if(!this->map.load("feature-examples/graphics/map.map", "feature-examples/graphics/tiles.png", Game::getGraphics()) )
        return false;
    if(!this->playerImage.load("feature-examples/graphics/girl-idle-sprite.png", Game::getGraphics()) )
        return false;

    this->animator.addAnimation(&playerImage, 0, 128, 140, 1, 16);
    this->animator.setAnimation(0);

    this->camera.set(0, 0, 800, 600);
    this->player = new SceneNode(0, 10, 10, 50, 50);
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
    printf("update state\n");
};


void AnimatedDemo::draw(Graphics* g)
{
    g->clear();
    
    this->map.draw(1, 0, 0, g);
    this->map.draw(2, 0, 0, g);
    this->map.draw(3, 0, 0, g);
    this->map.draw(0, 0, 0, g);
    animator.play(g);
    this->scene.draw(&this->camera, g);
    
    g->present();
};