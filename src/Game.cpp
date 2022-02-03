#include "Game.h"

Game::Game() 
{
    this->isDone = false;
};

Game::~Game()
{};

bool Game::initSystem(char const title[], int width, int height, bool fullscreen)
{
    if(!graphics.init(title, width, height, fullscreen) )
        return false;

    return true;
};

void Game::run()
{
    while(!this->isDone)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event) )
        {
            if(event.type == SDL_QUIT)
            {
                isDone = true;
                break;
            }
        }

        //This is for testing
        graphics.setColor(255, 255, 255, 255);                
        graphics.clear();
        graphics.present();

    }
};

void Game::end()
{
    this->isDone = false;
};

void Game::kill()
{
    SDL_Quit();
}