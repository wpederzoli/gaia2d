#ifndef PLAYERDEMO_H
#define PLAYERDEMO_H

#include "Game.h"
#include "Image.h"
#include "PlayerBase.h"

class PlayerDemo : public Game
{
    private:
        Image playerImage;
        PlayerBase player;
    
    public:
        PlayerDemo();
        ~PlayerDemo();

        virtual bool init();
        // virtual void free();
        // virtual void update();
        // virtual void draw(Graphics* g);
};

#endif