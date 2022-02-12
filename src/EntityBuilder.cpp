#include "EntityBuilder.h"

EntityBuilder::EntityBuilder(int entityId)
{
    this->entity = new Entity(entityId);
};

EntityBuilder::~EntityBuilder(){};

EntityBuilder EntityBuilder::setSingleImage(Image* image)
{
    this->entity->setImage(image);
    return *this;
};

EntityBuilder EntityBuilder::setPosition(int x, int y)
{
    this->entity->setX(x);
    this->entity->setY(y);

    return *this;
};

EntityBuilder EntityBuilder::setDimensions(int width, int height)
{
    this->entity->setWidth(width);
    this->entity->setHeight(height);

    return *this;
};

Entity* EntityBuilder::build()
{
    return this->entity;
};

