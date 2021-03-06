#include "Animation.h"

Animation::Animation()
{
    this->image = NULL;
    this->id = 0;
    this->width = 0;
    this->height = 0;
    this->frameSizeX = 0;
    this->frameSizeY = 0;
    this->start = 0;
    this->end = 0;
    this->currentFrame = 0;
    this->posX = 0;
    this->posY = 0;
    this->flipHorizontal = false;
    this->loop = true;
    this->lastTick = SDL_GetTicks();
};

Animation::Animation(Image* source, int id, int frameSizeX, int frameSizeY, int start, int end)
{
    this->image = source;
    this->id = id;
    this->width = frameSizeX;
    this->height = frameSizeY;
    this->frameSizeX = frameSizeX;
    this->frameSizeY = frameSizeY;
    this->start = start;
    this->end = end;
    this->currentFrame = start;
    this->flipHorizontal = false;
    this->loop = true;
    this->lastTick = SDL_GetTicks();
};

Animation::~Animation()
{};

bool Animation::resetPosition()
{
    if(this->currentFrame > this->end)
        return true;
    if(this->currentFrame*this->frameSizeX + frameSizeX >= (*this->image).getWidth() )
        return true;
    
    return false;
};

void Animation::play(Graphics* g)
{
    Uint32 ticks = SDL_GetTicks();
    
    int framesPerRow = (*this->image).getWidth() / this->frameSizeX;

    SDL_Rect sourceRect;
    sourceRect.x = (this->currentFrame%framesPerRow) * this->frameSizeX;
    sourceRect.y = (this->currentFrame/framesPerRow) * this->frameSizeY;
    sourceRect.w = this->frameSizeX;
    sourceRect.h = this->frameSizeY;

    SDL_Rect destRect;
    destRect.x = this->posX;
    destRect.y = this->posY;
    destRect.w = this->width;
    destRect.h = this->height;

    if(this->flipHorizontal)
        (*this->image).drawSprite(sourceRect.x, sourceRect.y, sourceRect.w, sourceRect.h, destRect.x, destRect.y, destRect.w, destRect.h, true, g);
    else
        (*this->image).drawSprite(sourceRect.x, sourceRect.y, sourceRect.w, sourceRect.h, destRect.x, destRect.y, destRect.w, destRect.h, g);
    
    if( (ticks - this->lastTick) / 10 >= (Uint32) 100/this->speed )
    {
        this->lastTick = SDL_GetTicks();
        this->nextFrame();
    }
};

void Animation::setFrame(int frame){ this->currentFrame = frame; };

void Animation::setDimensions(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Animation::setPosition(int x, int y)
{
    this->posX = x;
    this->posY = y;
};

void Animation::nextFrame()
{
    if(this->currentFrame >= this->end - 1)
        this->currentFrame = this->loop ? this->currentFrame = this->start : this->end - 1;
    else
        this->currentFrame++;
};

void Animation::free()
{
    image->free();
    image = NULL;
};