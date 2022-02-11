#include "PlayerBase.h"

PlayerBase::PlayerBase()
{
    this->sprite = NULL;
};

PlayerBase::~PlayerBase(){};

void PlayerBase::create(Image* sprite)
{
    this->sprite = sprite;
};