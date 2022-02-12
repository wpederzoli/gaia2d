#ifndef PLAYERDEMO_H
#define PLAYERDEMO_H

#include "Game.h"
#include "Image.h"
#include "PlayerBase.h"
#include "Scene.h"
#include "Rectangle.h"
#include "Entity.h"
#include "EntityBuilder.h"
#include "AnimatedEntity.h"
#include "AnimatedEntityBuilder.h"

class PlayerDemo : public Game
{
    private:
        Image playerImage;
        PlayerBase player;
        Rectangle camera;
        Scene* scene;
        Entity* entity;
        AnimatedEntity* animatedEntity; 

    public:
        PlayerDemo();
        ~PlayerDemo();

        bool init() override;
        // virtual void free();
        // virtual void update();
        void draw(Graphics* g) override;
};

#endif