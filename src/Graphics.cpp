#include "Graphics.h"

Graphics::Graphics() 
{
    this->window = NULL;
    this->renderer = NULL;
    this->width = 0;
    this->height = 0;
};

Graphics::~Graphics()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    this->window = NULL;
    this->renderer = NULL;
};

bool Graphics::init(char const title[], int width, int height, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) 
    {
        printf("Unable to start SDL subsystems: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        Uint32 flags = 0;
        if(fullscreen)
            flags |= SDL_WINDOW_FULLSCREEN;

        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(this->window == NULL)
        {
            printf("Unable to initialize window: %s\n", SDL_GetError() );
            return false;
        }

        // -1 initializes the first supported rendering driver
        //TODO: Abstract magic numbers for flags
        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if(this->renderer == NULL)
        {
            printf("Unable to initialize rendering driver: %s\n", SDL_GetError() );
            return false;
        }
    }

    //Set width and height
    this->width = width;
    this->height = height;

    return true;
};

void Graphics::clear()
{
    SDL_RenderClear(this->getRenderer() );
};

void Graphics::setColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(this->getRenderer(), r, g, b, a);
};

SDL_Renderer* Graphics::getRenderer() const
{
    return this->renderer;
};

int Graphics::getHeight()
{
    return this->height;
};

int Graphics::getWidth()
{
    return this->width;
};

void Graphics::present()
{
    SDL_RenderPresent(this->getRenderer() );
};

void Graphics::drawRect(int x, int y, int w, int h, int r, int g, int b)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderDrawRect(this->getRenderer(), &rect);
    this->setColor(r, g, b, 255);
};

void Graphics::fillRect(int x, int y, int w, int h, int r, int g, int b)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderFillRect(this->getRenderer(), &rect);
    this->setColor(r, g, b, 255);
};