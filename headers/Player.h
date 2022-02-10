#ifndef PLAYER_H
#define PLAYER_H

#include "MapNode.h"
#include "Animator.h"
#include "Image.h"

class Player : public MapNode
{
    private:
        Animator animator;
        Image* sprite;
        
        bool collision;
        int moveSpeed;
    
    public:
        Player(int id, int x, int y, int width, int height, bool collision, Map* map);
        ~Player();

        void draw(Rectangle* view, Graphics* g);

        void addAnimation(Image* sprite, int id, int frameWidth, int frameHeight, int frameStart, int frameEnd);
        void playAnimation(int animationId);

        int getSpeed(){ return this->moveSpeed; };
};

#endif