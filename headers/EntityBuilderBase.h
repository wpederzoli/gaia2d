#ifndef ENTITYBUILDERBASE_H
#define ENTITYBUILDERBASE_H

#include <stdio.h>
#include "Builder.h"
#include "Entity.h"

template<class BuilderType, class EntityType>
class EntityBuilderBase : public Builder<EntityType>
{
    // private:
    //     EntityType* m_entity;
    //     int m_id;
    //     Image* m_image;
    //     int m_x;
    //     int m_y;
    //     int m_width;
    //     int m_heigth;
    
    // public:
    //     EntityBuilderBase(){ m_builderType = this; };
    //     ~EntityBuilderBase(){};

    //     virtual BuilderType<BuilderType, EntityType>* id(int id){ m_id = id; return m_builderType; };
    //     // EntityType* image(Image* image){ m_image = image; return *this; };
    //     // EntityType* position(int x, int y){ m_x = x; m_y = y; return *this; };
    //     // EntityType* dimensions(int width, int height){ m_width = width; m_heigth = height; return *this; };
    //     virtual EntityType* build()
    //     {
    //         m_entity = new EntityType(m_id);
    //         return m_entity;
    //     };
};

#endif