#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Input.h"

class Game
{
    private:
        Graphics graphics;
        Input input;
        //Audio audio
        int fps;
        bool isDone;
    
    public:
        Game();
        ~Game();

        bool initSystem(char const title[], int width, int height, bool fullscreen);
        void run();
        void end();
        void kill();
};

#endif