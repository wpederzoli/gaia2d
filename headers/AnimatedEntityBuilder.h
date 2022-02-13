#ifndef ANIMATEDENTITYBUILDER_H
#define ANIMATEDENTITYBUILDER_H

#include "EntityBuilder.h"
#include "AnimatedEntity.h"

class AnimatedEntityBuilder : EntityBuilder
{
    private:
        AnimatedEntity* m_entity;
        EntityBuilder m_eb;
    
    public:
        AnimatedEntityBuilder();
        ~AnimatedEntityBuilder();

        virtual AnimatedEntityBuilder* id(int id) override;
        virtual AnimatedEntityBuilder* image(Image* image);
        virtual AnimatedEntity* build() override;
};

#endif