#include "EntityBuilder.h"

EntityBuilder::EntityBuilder()
{
    m_entity = NULL;
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

EntityBuilder* EntityBuilder::position(int x, int y)
{
    m_x = x;
    m_y = y;
    return this;
};

EntityBuilder* EntityBuilder::dimensions(int w, int h)
{
    m_width = w;
    m_heigth = h;
};

Entity* EntityBuilder::build()
{
    m_entity = new Entity(m_id);
    m_entity->setPosition(m_x, m_y);
    m_entity->setSize(m_width, m_heigth);
    m_entity->setImage(m_image);

    return m_entity;
};



