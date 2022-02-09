#ifndef ANIMATEDDEMO_H
#define ANIMATEDDEMO_H

#include "Game.h"
#include "Map.h"
#include "Graphics.h"
#include "Rectangle.h"
#include "Image.h"
#include "Scene.h"
#include "SceneNode.h"

#include "Animator.h"

class AnimatedDemo : public Game
{
    private:
        Map map;
        Image playerImage;
        Scene scene;
        SceneNode* player;
        Rectangle camera;
        Animator animator;
    
    public:
        virtual bool init();
        virtual void free();
        virtual void update();
        virtual void draw(Graphics* g);
};

#endif