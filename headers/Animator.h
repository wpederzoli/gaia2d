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

        void addAnimation(Image* sprite, int id, int sizeX, int sizeY, int frameStart,  int frameEnd, bool active = false);
        void setAnimation(int id);
        void setAnimation(int id, bool flip);
        void setAnimation(int id, bool flip, bool playOnce);
        
        void play(Graphics* g);
        void play(int x, int y, Graphics* g);
        
        void setGlobalSpeed(int s);
        void setAnimationSpeed(int s);
        Animation* getActiveAnimation(){ return this->active; };
};

#endif