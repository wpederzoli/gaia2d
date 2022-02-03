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
                isDone = false;
                break;
            }
        }

        //This is for testing
        graphics.clear();
        graphics.setColor(0, 0, 0, 1);
        graphics.present();

        SDL_Delay(2000);
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