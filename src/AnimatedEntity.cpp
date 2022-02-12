#include "AnimatedEntity.h"

AnimatedEntity::AnimatedEntity(int id) : Entity(id)
{};

AnimatedEntity::~AnimatedEntity(){};

void AnimatedEntity::addAnimation(int id, int frameWidth, int frameHeight, int frameStart, int frameEnd)
{
    this->animator.addAnimation(this->getImage(), id, frameWidth, frameHeight, frameStart, frameEnd, true);
};

void AnimatedEntity::play(Graphics* g){ this->animator.play(g); };
