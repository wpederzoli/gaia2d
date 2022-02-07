#include "Map.h"

Map::Map()
{
    this->tileWidth = -1;
    this->tileHeight = -1;
    this->width = -1;
    this->height = -1;
    this->layer1 = this->layer2 = this->layer3 = this->solidLayer = NULL;
};

Map::~Map()
{};

bool Map::load(char const mapFile[], char const imageFile[], Graphics* g)
{
    this->layer1 = this->layer2 = this->layer3 = this->solidLayer = NULL;

    std::ifstream in(mapFile);

    if(!in.good())
        return false;

    loadDimensions(&in);
    loadSolidTiles(&in);

    this->layer1 = new int[this->width*this->height];
    this->layer2 = new int[this->width*this->height];
    this->layer3 = new int[this->width*this->height];
    this->solidLayer = new int[this->width*this->height];

    loadLayer(layer1, &in);
    loadLayer(layer2, &in);
    loadLayer(layer3, &in);
    generateSolidLayer();

    in.close();
    
    if(!tiles.load(imageFile, g) )
        return false;

    return true;
};

void Map::loadDimensions(std::ifstream *in)
{
    std::string buffer;

    //Get 'width'
    std::getline(*in, buffer, ' ');
    //get width value
    std::getline(*in, buffer, '\n');
    this->width = std::atoi(buffer.c_str() );

    //Get 'height'
    std::getline(*in, buffer, ' ');
    //get height value
    std::getline(*in, buffer, '\n');
    this->height = std::atoi(buffer.c_str());

    //Get 'tile_width'
    std::getline(*in, buffer, ' ');
    //Get tile_width value
    std::getline(*in, buffer, '\n');
    this->tileWidth = std::atoi(buffer.c_str());

    //Get 'tile_height'
    std::getline(*in, buffer, ' ');
    //Get tile_height value
    std::getline(*in, buffer, '\n');
    this->tileHeight = std::atoi(buffer.c_str());
};

void Map::loadSolidTiles(std::ifstream* in)
{
    std::string buffer;

    //Get 'solid_tiles'
    std::getline(*in, buffer, '\n');
    //Get solid_tiles values
    std::getline(*in, buffer, '\n');

    char* string = new char[buffer.size() + 1];
    std::strcpy(string, buffer.c_str());

    char* token = strtok(string, " ,");

    while(token != NULL)
    {
        solidTiles.push_back(std::atoi(token));
        strtok(NULL, " ,");
    }

    delete[] string;
};

void Map::loadLayer(int* layer, std::ifstream *in)
{
    std::string buffer;

    //Get 'layerX'
    std::getline(*in, buffer, '\n');
    
    //Get layerX lines
    int i = 0;

    for(int y = 0; y < this->height; y++)
    {
        for(int x = 0; x < this->width; x++)
        {
            char delim = ',';
            if(x == width-1)
                delim = '\n';
            
            std::getline(*in, buffer, delim);
            layer[i] = std::atoi(buffer.c_str());
            i++;
        }
    }
};

void Map::generateSolidLayer()
{
    for(int i = 0; i < this->width*this->height; i++)
    {
        if(this->isTileSolid(this->layer1[i]) || this->isTileSolid(this->layer2[i]) ||
            this->isTileSolid(this->layer3[i]) )
                this->solidLayer[i] = 1;
        else
            this->solidLayer[i] = 0;
    }
};