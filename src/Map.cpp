#include "Map.h"

Map::Map()
{
    this->tileWidth = -1;
    this->tileHeight = -1;
    this->width = -1;
    this->height = -1;
};

Map::~Map()
{};

bool Map::init(char const imagePath[], Graphics* g)
{
    this->tileWidth = 32;
    this->tileHeight = 32;
    this->width = 27;
    this->height = 20;

    if(!tiles.load(imagePath, g) )
        return false;

    return true;
};

void Map::draw(Graphics* g)
{
    //TODO: algorithm to draw the tiles on the map
};

void Map::free()
{
    //TODO: free resources.
}