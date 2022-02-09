#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <list>

#include "Image.h"
#include "Animation.h"
#include "Graphics.h"

class Animation;

class Animator
{
    private:
        std::list<Animation*> animations;
        Image* sprite;
        Animation* active; 
        void setActive(Animation* animation);
   
    public:
        Animator();
        ~Animator();

        void addAnimation(Image* sprite, int id, int sizeX, int sizeY, int frameStart,  int frameEnd);
        void setAnimation(int id);
        void play(Graphics* g);
};

#endif