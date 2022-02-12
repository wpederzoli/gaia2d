#include "PlayerBase.h"

PlayerBase::PlayerBase() : SceneNode(0, 0, 0, 0, 0)
{
    this->image = NULL;
};

PlayerBase::~PlayerBase(){};

void PlayerBase::create(Image* image)
{
    this->image = image;
};

void PlayerBase::draw(Rectangle* view, Graphics* g)
{
    if(view->overlaps(*this) )
    {
        this->image->drawSprite(this->image->getFrameX(), this->image->getFrameY(), this->image->getWidth(), this->image->getHeight(),
                this->getX(), this->getY(), this->getWidth(), this->getHeight(), g);
    }

};