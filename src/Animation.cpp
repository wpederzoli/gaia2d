#include "Animation.h"

Animation::Animation()
{
    this->image = NULL;
    this->id = 0;
    this->frameSizeX = 0;
    this->frameSizeY = 0;
    this->start = 0;
    this->end = 0;
    this->currentFrame = 0;
    this->lastTick = SDL_GetTicks();
};

Animation::Animation(Image* source, int id, int frameSizeX, int frameSizeY, int start, int end)
{
    this->image = source;
    this->id = id;
    this->frameSizeX = frameSizeX;
    this->frameSizeY = frameSizeY;
    this->start = start;
    this->end = end;
    this->currentFrame = 0;
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

    // if(this->resetPosition() )
    //     this->setFrame(0);
    
    int framesPerRow = (*this->image).getWidth() / this->frameSizeX;

    SDL_Rect sourceRect;
    sourceRect.x = (this->currentFrame%framesPerRow) * this->frameSizeX;
    sourceRect.y = (this->currentFrame/framesPerRow) * this->frameSizeY;
    sourceRect.w = this->frameSizeX;
    sourceRect.h = this->frameSizeY;

    SDL_Rect destRect;
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = this->frameSizeX;
    destRect.h = this->frameSizeY;

    (*this->image).drawSprite(sourceRect.x, sourceRect.y, sourceRect.w, sourceRect.h, destRect.x, destRect.y, destRect.w, destRect.h, g);
    
    if( (ticks - this->lastTick) / 10 >= 100/this->speed )
    {
        this->lastTick = SDL_GetTicks();
        this->nextFrame();
    }
};

void Animation::setFrame(int frame){ this->currentFrame = frame; };

void Animation::nextFrame()
{
    printf("this is current frame: %i\n", this->currentFrame);
    if(this->currentFrame >= this->end - 1)
        this->currentFrame = 0;   
    else
        this->currentFrame++;
}