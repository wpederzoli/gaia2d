#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Input.h"
#include "Audio.h"

class Game
{
    private:
        Graphics graphics;
        Input input;
        Audio audio;
        int fps;
        bool isDone;
    
    public:
        Game();
        ~Game();

        Graphics* getGraphics();
        Input* getInput();
        Audio* getAudio();

        bool initSystem(char const title[], int width, int height, bool fullscreen);
        void run();
        void end();
        void kill();

        virtual bool init();
        virtual void free();
        virtual void update();
        virtual void draw(Graphics* g);
};

#endif