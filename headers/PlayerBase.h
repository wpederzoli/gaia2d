#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "Image.h"
#include "Graphics.h"

class PlayerBase
{
    private:
        Image* image;
        int x;
        int y;

    public:
        PlayerBase();
        ~PlayerBase();

        virtual void create(Image* image);
        virtual void draw(Graphics* g);
};

#endif