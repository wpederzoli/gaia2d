#ifndef ENTITY_H
#define ENTITY_H

#include "SceneNode.h"
#include "Image.h"

class Entity : public SceneNode
{
    private:
        Image* image;
        int id;
    
    public:
        Entity(int id);
        ~Entity();

        void setImage(Image* image);
};

#endif