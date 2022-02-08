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
    
    if(!tiles.load(imageFile, this->tileWidth, this->tileHeight, g) )
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
        token = strtok(NULL, " ,");
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

void Map::draw(int layer, int xOffset, int yOffset, Graphics* g)
{
    int* drawLayer = NULL;

    if(layer == 0)
        drawLayer = solidLayer;
    else if(layer == 1)
        drawLayer = layer1;
    else if(layer == 2)
        drawLayer = layer2;
    else if(layer == 3)
        drawLayer = layer3;
    else
        return;

    int startY = yOffset/this->tileHeight;
    int startX = xOffset/this->tileWidth;

    int rows = (g->getHeight()/this->tileHeight) + 2;
    int cols = (g->getWidth()/this->tileWidth) + 2;

    for(int y = startY; y < startY+rows; y++)
    {
        for(int x = startX; x < startX+cols; x++)
        {
            int frame = -1;

            if(x >= 0 && y >= 0 && x < this->width && y < this->height)
                frame = drawLayer[y*this->width + x]-1;

            if(frame >= 0)
            {
                if(layer == 0)
                    g->drawRect(x*tileWidth - xOffset, y*tileHeight - yOffset, tileWidth, tileHeight, 255, 0, 0);
                else    
                    tiles.drawSprite(x*tileWidth - xOffset, y*tileHeight - yOffset, frame, g);
            }
        }
    }
};

void Map::free()
{
    if(this->layer1 != NULL)
    {
        delete[] this->layer1;
        this->layer1 = NULL;
    }
    if(this->layer2 != NULL)
    {
        delete[] this->layer2;
        this->layer2 = NULL;
    }
    if(this->layer3 != NULL)
    {
        delete[] this->layer3;
        this->layer3 = NULL;
    }
    if(this->solidLayer != NULL)
    {
        delete[] this->solidLayer;
        this->solidLayer = NULL;
    }

    this->solidTiles.clear();
    //this->tiles.free();
};

bool Map::isTileSolid(int tile)
{
    for(unsigned int i = 0; i < this->solidTiles.size(); i++)
    {
        if(this->solidTiles[i] == tile)
            return true;
    }

    return false;
};

bool Map::checkSolid(int x, int y)
{
    if(x < 0 || x > this->width || y < 0 || y > this->height)
        return false;
    
    return this->solidLayer[y*this->width + x];
};