#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>

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
        int* layer1, *layer2, *layer3, *solidLayer;
        std::vector<int> solidTiles;

        void loadDimensions(std::ifstream *in);
        void loadSolidTiles(std::ifstream *in);
        void loadLayer(int* layer, std::ifstream *in);
        void generateSolidLayer();

    public:
        Map();
        ~Map();

        bool load(char const mapFile[], char const imageFile[], Graphics* g);
        void draw(int layer, int xOffset, int yOffset, Graphics* g);
        void free();

        bool isTileSolid(int tile);
        bool checkSolid(int x, int y);
};

#endif