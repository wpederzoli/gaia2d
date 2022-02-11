#include "PlayerBase.h"

PlayerBase::PlayerBase()
{
    this->image = NULL;
    this->x = 0;
    this->y = 0;
};

PlayerBase::~PlayerBase(){};

void PlayerBase::create(Image* image)
{
    this->image = image;
};

void PlayerBase::draw(Graphics* g)
{
    this->image->draw(this->x, this->y, g);
};