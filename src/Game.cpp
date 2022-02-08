#include "Game.h"

Game::Game() 
{
    this->isDone = false;
    this->fps = 60;
};

Game::~Game()
{};

bool Game::initSystem(char const title[], int width, int height, bool fullscreen)
{
    if(!graphics.init(title, width, height, fullscreen) )
        return false;
    
    if(!audio.init())
        return false;

    input.init();

    return true;
};

Graphics* Game::getGraphics()
{
    return &this->graphics;
}

Input* Game::getInput()
{
    return &this->input;
};

void Game::run()
{
    while(!this->isDone)
    {
        unsigned int frameStart = SDL_GetTicks();
        
        SDL_Event event;
        while(SDL_PollEvent(&event) )
        {
            if(event.type == SDL_QUIT)
            {
                isDone = true;
                break;
            }
        }
        
        this->input.update();
        update();
        draw(getGraphics());

        int frameTime = SDL_GetTicks() - frameStart;
        int delay = (1000/this->fps) - frameTime;

        SDL_Delay(delay);
    }
};

void Game::end()
{
    this->isDone = false;
};

void Game::kill()
{
    SDL_Quit();
};

bool Game::init()
{
    return initSystem("Game", 800, 600, false);
};

void Game::free()
{};

void Game::update()
{};

void Game::draw(Graphics* g)
{
    g->clear();
};