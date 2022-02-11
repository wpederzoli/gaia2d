#include "Player.h"

Player::Player(int id, int x, int y, int width, int height, bool collision, Map* map) :
MapNode(id, x, y, width, height, collision, map)
{
    this->collision = collision;
    this->moveSpeed = 1;
};

Player::~Player()
{};

void Player::draw(Rectangle* view, Graphics* g)
{
    this->animator.play(this->getX(), this->getY(), g);
};

void Player::addAnimation(Image* sprite, int id, int frameWidth, int frameHeight, int frameStart, int frameEnd)
{
    this->animator.addAnimation(sprite, id, frameWidth, frameHeight, frameStart, frameEnd);
};

void Player::setAnimationGlobalSpeed(int s)
{
    this->animator.setGlobalSpeed(s);
};

void Player::setAnimationSpeed(int s)
{
    this->animator.setAnimationSpeed(s);
};

void Player::playAnimation(int animationId)
{
    this->animator.setAnimation(animationId);
};

void Player::playAnimation(int animationId, bool flip)
{
    this->animator.setAnimation(animationId, flip);
};

void Player::playAnimationOnce(int animationId)
{
    this->animator.setAnimation(animationId, false, true);
};

bool Player::isAnimationFlipped(){ return (*this->animator.getActiveAnimation()).isFlipped(); };

int Player::getAnimationId()
{
    return (*this->animator.getActiveAnimation()).getId();
};