#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include "Image.h"
#include "Graphics.h"
#include "SceneNode.h"

class PlayerBase : public SceneNode
{
    private:
        Image* image;
        int id;

    public:
        PlayerBase();
        ~PlayerBase();
        
        virtual void create(Image* image);
        virtual void draw(Rectangle* view, Graphics* g) override;
};

#endif