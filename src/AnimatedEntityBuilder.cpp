#include "AnimatedEntityBuilder.h"


AnimatedEntityBuilder::AnimatedEntityBuilder()
{
    m_entity = NULL;
};

AnimatedEntityBuilder::~AnimatedEntityBuilder(){};

AnimatedEntityBuilder* AnimatedEntityBuilder::id(int id)
{
    m_eb = (*m_eb.id(id) );
    return this;
};

AnimatedEntityBuilder* AnimatedEntityBuilder::image(Image* image)
{
    m_eb = (*m_eb.image(image) );
    return this;
};

AnimatedEntity* AnimatedEntityBuilder::build()
{
    m_entity = static_cast<AnimatedEntity*>(m_eb.build() );
    return m_entity;
};