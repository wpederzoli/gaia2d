#include "EntityBuilder.h"

EntityBuilder::EntityBuilder()
{
    m_image = NULL;
    m_id = -1;
    m_x = 0;
    m_y = 0;
    m_width = 0;
    m_height = 0;
};

EntityBuilder::~EntityBuilder(){};

EntityBuilder* EntityBuilder::id(int id)
{
    m_id = id;
    return this;
};

EntityBuilder* EntityBuilder::image(Image* image)
{
    m_image = image;
    return this;
};

Entity* EntityBuilder::build()
{
    if(m_id == -1 || m_image == NULL)
        return NULL;
    
    Entity* entity = new Entity(m_id);
    entity->setX(m_x);
    entity->setY(m_y);
    entity->setWidth(m_width);
    entity->setHeight(m_height);
    entity->setImage(m_image);

    return entity;
};


