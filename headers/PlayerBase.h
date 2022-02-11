#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "Image.h"

class PlayerBase
{
    private:
        Image* sprite;
    
    public:
        PlayerBase();
        ~PlayerBase();

        virtual void create(Image* sprite);
};

#endif