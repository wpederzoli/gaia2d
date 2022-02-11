#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL_image.h>
#include "Graphics.h"

class Image
{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        int posX;
        int posY;

    public:
        Image();
        ~Image();
        
        bool load(char const filePath[], Graphics* g);
        bool load(char const filePath[], int frameWidth, int frameHeight, Graphics* g);

        void setFrame(int x, int y);
        void draw(int x, int y, const Graphics* g);
        void draw(int x, int y, int width, int height, const Graphics* g);

        void drawSprite(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, Graphics* g);
        void drawSprite(int sx, int sy, int sw, int sh, int scale, Graphics* g);
        void drawSprite(int x, int y, int frame, Graphics* g);
        void drawSprite(int sx, int sy, int sw, int sh,  int dx, int dy, int dw, int dh, bool flip, Graphics* g);

        int getFrameX(){ return this->posX; };
        int getFrameY(){ return this->posY; };
        int getWidth(){ return this->width; };
        int getHeight(){ return this->height; };

        void free();
};

#endif