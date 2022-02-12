#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H

#include <stdio.h>
#include "Entity.h"

class EntityBuilder
{
    private:
        Entity* m_entity;
        int m_id;
        Image* m_image;
        int m_x;
        int m_y;
        int m_width;
        int m_heigth;
    
    public:
        EntityBuilder();
        ~EntityBuilder();

        EntityBuilder* id(int id);
        EntityBuilder* image(Image* image);
        EntityBuilder* position(int x, int y);
        EntityBuilder* dimensions(int width, int height);

        virtual Entity* build();
};

#endif