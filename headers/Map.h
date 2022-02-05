#ifndef MAP_H
#define MAP_H

#include "Graphics.h"
#include "Image.h"

class Map
{
    private:
        Image tiles;
        int tileWidth;
        int tileHeight;
        int width;
        int height;

    public:
        Map();
        ~Map();

        bool init(char const imagePath[], Graphics* g);
        void draw(Graphics* g);
        void free();
};

#endif