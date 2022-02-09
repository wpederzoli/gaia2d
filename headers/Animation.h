#ifndef ANIMATION_H
#define ANIMATION_H

#include "Image.h"

class Animation
{
    private:
        Image* image;
        int id;
        int frameSizeX;
        int frameSizeY;
        int start;
        int end;
        int currentFrame = 0;
        int speed = 27;
    
        Uint32 lastTick;

        bool resetPosition();
        void nextFrame();

    public:
        Animation();
        Animation(Image* source, int id, int x, int y, int start, int end);
        ~Animation();

        void play(Graphics* g);
        void setFrame(int frame);
        int getId(){ return this->id; };
};

#endif