#include <stdio.h>
#include "Image.h"

Image::Image()
{
    this->texture = NULL;
    this->width = 0;
    this->height = 0;
    this->posX = 0;
    this->posY = 0;
};

Image::~Image()
{};

bool Image::load(char const filePath[], Graphics* g)
{
    bool success = true;

    SDL_Surface* surface = NULL;
    surface = IMG_Load(filePath);

    if(surface == NULL)
    {
        printf("Unable to load file from: %s\n", filePath);
        printf("Reason: %s\n", IMG_GetError() );
        success = false;
    }
    else
    {
        this->texture = SDL_CreateTextureFromSurface(g->getRenderer(), surface);

        if(this->texture == NULL)
        {
            printf("Unable to load image from surface: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            this->width = surface->w;
            this->height = surface->h;
        }
    }

    SDL_FreeSurface(surface);
    return success;
};

void Image::setFrame(int x, int y)
{
    this->posX = x;
    this->posY = y;
};

void Image::draw(int x, int y, const Graphics* g)
{
    if(this->texture == NULL)
    {
        printf("No texture found for this image\n");
        return;
    }

    SDL_Rect sourceRect = {this->posX, this->posY, this->width, this->height};
    SDL_Rect destRect = {x, y, this->width, this->height};

    SDL_RenderCopy(g->getRenderer(), this->texture, &sourceRect, &destRect);
};

void Image::draw(int x, int y, int width, int height, const Graphics* g)
{
    if(this->texture == NULL)
    {
        printf("No texture found for this image\n");
        return;
    }

    SDL_Rect sourceRect = {this->posX, this->posY, this->width, this->height};
    SDL_Rect destRect = {x, y, width, height};

    SDL_RenderCopy(g->getRenderer(), this->texture, &sourceRect, &destRect);
};

void Image::drawSprite(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, Graphics* g)
{
    if(this->texture == NULL)
    {
        printf("Unable to load texture from image\n");
        return;
    }
    
    SDL_Rect sourceRect = {sx, sy, sw, sh};
    SDL_Rect destRect = {dx, dy, dw, dh};

    SDL_RenderCopy(g->getRenderer(), this->texture, &sourceRect, &destRect);
};