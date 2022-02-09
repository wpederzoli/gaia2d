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

void Animator::addAnimation(Image* sprite, int id, int sizeX, int sizeY, int frameStart, int frameEnd)
{
    Animation* animation = new Animation(sprite, id, sizeX, sizeY, frameStart, frameEnd);
    this->animations.push_back(animation);
};

void Animator::setAnimation(int id)
{
    std::list<Animation*>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
    {
        if((*it)->getId() == id)
        {
            this->setActive(*it);
            break;
        }
    }
};


