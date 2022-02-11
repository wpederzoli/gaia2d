#ifndef ANIMATION_H
#define ANIMATION_H

#include "Image.h"

class Animation
{
    private:
        Image* image;
        int id;
        int width;
        int height;
        int frameSizeX;
        int frameSizeY;
        int start;
        int end;
        int currentFrame = 0;
        int speed = 10;
        bool flipHorizontal;
        bool loop;

        int posX;
        int posY;
    
        Uint32 lastTick;

        bool resetPosition();
        void nextFrame();

    public:
        Animation();
        Animation(Image* source, int id, int x, int y, int start, int end);
        ~Animation();

        void play(Graphics* g);

        void setFrame(int frame);
        void setDimensions(int width, int height);
        void setPosition(int x, int y);
        void setSpeed(int s){ this->speed = s; };
        void setLoop(bool loop){ this->loop = loop; }; 
        void flip(bool flip){ this->flipHorizontal = flip; };

        int getId(){ return this->id; };
        bool isFlipped(){ return this->flipHorizontal; };
};

#endif