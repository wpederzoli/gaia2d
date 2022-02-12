#ifndef PLAYERDEMO_H
#define PLAYERDEMO_H

#include "Game.h"
#include "Image.h"
#include "PlayerBase.h"
#include "Scene.h"
#include "Rectangle.h"
#include "Enitity.h"
#include "EntityBuilder.h"

class PlayerDemo : public Game
{
    private:
        Image playerImage;
        PlayerBase player;
        Rectangle camera;
        Scene* scene;
        Entity* entity; 

    public:
        PlayerDemo();
        ~PlayerDemo();

        bool init() override;
        // virtual void free();
        // virtual void update();
        void draw(Graphics* g) override;
};

#endif