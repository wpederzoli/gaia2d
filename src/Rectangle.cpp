#include "Rectangle.h"

Rectangle::Rectangle()
{
    this->set(0, 0, 1, 1);
};

Rectangle::Rectangle(int x, int y, int width, int height)
{
    this->set(x, y, width, height);
};

Rectangle::~Rectangle()
{};

void Rectangle::set(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
};

void Rectangle::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
};

void Rectangle::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
};

void Rectangle::setX(int x)
{
    this->x = x;
};

void Rectangle::setY(int y)
{
    this->y = y;
};

void Rectangle::setWidth(int width)
{
    this->width = width;
};

void Rectangle::setHeight(int height)
{
    this->height = height;
};

void Rectangle::setX2(int x2)
{
    this->x = x2-this->width+1;
};

void Rectangle::setY2(int y2)
{
    this->y = y2-this->height+1;
};

void Rectangle::setCenterX(int x)
{
    this->x = x - this->width/2;
};

void Rectangle::setCenterY(int y)
{
    this->y = y - this->height/2;
};

int Rectangle::getX()
{
    return this->x;
};

int Rectangle::getY()
{
    return this->y;
};

int Rectangle::getWidth()
{
    return this->width;
};

int Rectangle::getHeight()
{
    return this->height;
};

int Rectangle::getX2()
{
    return this->x + this->width -1;
};

int Rectangle::getY2()
{
    return this->y + this->height -1;
};

int Rectangle::getCenterX()
{
    return this->x + this->width/2;
};

int Rectangle::getCenterY()
{
    return this->y + this->height/2;
};

bool Rectangle::overlaps(Rectangle rect)
{
    if(this->getX() > rect.getX2() )
        return false;
    if(this->getY() > rect.getY2() )
        return false;
    if(rect.getX2() > this->getX() )
        return false;
    if(rect.getY2() > this->getY() )
        return false;

    return true;
};

bool Rectangle::contains(int x, int y)
{
    if(x >= this->getX() && y >= this->getY() && x <= this->getX2() && y <= this->getY2() )
        return true;
    
    return false;
};