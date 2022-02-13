#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H

#include "Entity.h"

class EntityBuilder
{
    private:
        int m_id;
        Image* m_image;
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:
        EntityBuilder();
        ~EntityBuilder();

        virtual EntityBuilder* id(int id);
        virtual EntityBuilder* image(Image* image);
        virtual Entity* build();
};

#endif