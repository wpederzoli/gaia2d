#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL_ttf.h>
#include "Graphics.h"

class Font
{
    private:
        SDL_Texture* m_texture;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_heigth;

    public:
        Font();
        ~Font();

        void setPosition(int x, int y);

        bool load(char const fontPath[], const char text[], int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Graphics* graphics);
        void draw(Graphics* g);
        void free();
};

#endif