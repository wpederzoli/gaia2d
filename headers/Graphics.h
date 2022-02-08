#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Graphics
{
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
        int width;
        int height;

    public:
        Graphics();
        ~Graphics();

        bool init(char const title[], int width, int height, bool fullscreen);
        void clear();
        void setColor(int r, int g, int b, int a);
        SDL_Renderer* getRenderer() const;
        int getHeight();
        int getWidth();
        void present();
        void drawRect(int x, int y, int w, int h, int r, int b, int g);
};

#endif