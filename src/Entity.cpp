#include "Enitity.h"

Entity::Entity(int id) : SceneNode (id, 0, 0, 0, 0)
{
    this->image = NULL;
    this->id = id;
};

Entity::~Entity(){};

void Entity::setImage(Image* image){ this->image = image; };

void Entity::draw(Rectangle* view, Graphics* g)
{
    if(view->overlaps(*this) )
        this->image->drawSprite(0, 0, image->getWidth(), image->getHeight(), 
            this->getX(), this->getY(), this->getWidth(), this->getHeight(), g);
};