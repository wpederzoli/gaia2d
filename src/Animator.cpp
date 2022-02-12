#include "Animator.h"

Animator::Animator()
{
    this->sprite = NULL;
    this->active = NULL;
};

Animator::~Animator()
{};

void Animator::setActive(Animation* a)
{
    this->active = a;
};

void Animator::play(Graphics* g)
{
    (*this->active).play(g);
};

void Animator::play(int x, int y, Graphics* g)
{
    (*this->active).setPosition(x, y);
    (*this->active).play(g);
};

void Animator::addAnimation(Image* sprite, int id, int sizeX, int sizeY, int frameStart, int frameEnd, bool active)
{
    Animation* animation = new Animation(sprite, id, sizeX, sizeY, frameStart, frameEnd);
    this->animations.push_back(animation);
    
    if(active)
        this->active = animation;
};

void Animator::setAnimation(int id)
{
    std::list<Animation*>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
    {
        if((*it)->getId() == id)
        {
            this->setActive(*it);
            (*it)->flip(false);
            (*it)->setLoop(true);
            break;
        }
    }
};

void Animator::setAnimation(int id, bool flip)
{
    this->setAnimation(id);
    (*this->active).flip(flip);
};

void Animator::setAnimation(int id, bool flip, bool playOnce)
{
    this->setAnimation(id, flip);
    (*this->active).setLoop(!playOnce);

};

void Animator::setGlobalSpeed(int s)
{
    std::list<Animation*>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
    {
        (*it)->setSpeed(s);
    }
};

void Animator::setAnimationSpeed(int s)
{
    (*this->active).setSpeed(s);
};



