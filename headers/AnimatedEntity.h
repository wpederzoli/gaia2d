#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H

#include "Entity.h"
#include "Animator.h"

class AnimatedEntity : public Entity
{
    private:
        Animator animator;
    
    public:
        AnimatedEntity(int id);
        ~AnimatedEntity();
        
        void addAnimation(int id, int frameWidth, int frameHeight, int frameStart, int frameEnd);
        void play(Graphics* g);
};

#endif