#include "Enitity.h"

Entity::Entity(int id) : SceneNode (id, 0, 0, 0, 0)
{
    this->image = NULL;
    this->id = id;
};

void Entity::setImage(Image* image){ this->image = image; };

Entity::~Entity(){};