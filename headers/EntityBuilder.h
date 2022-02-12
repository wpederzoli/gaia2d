#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H

#include <stdio.h>
#include "Enitity.h"

class EntityBuilder
{
    private:
        Entity* entity;
    
    public:
        EntityBuilder(int entityId);
        ~EntityBuilder();

        EntityBuilder setSingleImage(Image* image);
        EntityBuilder setPosition(int x, int y);
        EntityBuilder setDimensions(int width, int height);

        Entity* build();
};

#endif