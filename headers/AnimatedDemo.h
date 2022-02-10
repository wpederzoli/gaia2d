#ifndef ANIMATEDDEMO_H
#define ANIMATEDDEMO_H

#include "Game.h"
#include "Map.h"
#include "Rectangle.h"
#include "Image.h"
#include "Scene.h"

#include "Player.h"

class AnimatedDemo : public Game
{
    private:
        Map map;
        Image playerImage;
        Scene scene;
        Player* player;
        Rectangle camera;
    
    public:
        virtual bool init();
        virtual void free();
        virtual void update();
        virtual void draw(Graphics* g);
};

#endif