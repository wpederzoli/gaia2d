#include "PlayerBase.h"

PlayerBase::PlayerBase() : SceneNode(0, 0, 0, 0, 0)
{
    this->image = NULL;
};

PlayerBase::~PlayerBase(){};

void PlayerBase::create(int id, Image* image)
{
    this->setId(id);
    this->image = image;
};

void PlayerBase::create(int id, Image* image, int width, int height)
{
    this->setId(id);
    this->image = image;
    this->setWidth(width);
    this->setHeight(height);
};

void PlayerBase::draw(Rectangle* view, Graphics* g)
{
    if(view->overlaps(*this) )
    {
        this->image->drawSprite(this->image->getFrameX(), this->image->getFrameY(), this->image->getWidth(), this->image->getHeight(),
                this->getX(), this->getY(), this->getWidth(), this->getHeight(), g);
    }

};